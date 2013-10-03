#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include <string.h>
#include <unistd.h>
#include <fcntl.h>
#include <errno.h>
#include <stdint.h>
#include <sys/io.h>
#include <sys/types.h>

static unsigned int _ATAIO_BASE = 0x1F0;
static unsigned int _ATA_RST = 0x3F6;

static inline void cli() {__asm__ __volatile__("cli");}
static inline void sti() {__asm__ __volatile__("sti");}
static inline void udelay() {__asm__ __volatile__("outb %%al,%0" : : "dN" (0x80));}

struct dt {
    uint16_t size;
    uint32_t la;
} __attribute__((packed)) idtr;

int is_ready(unsigned char s) {
	if(((s & 0x80) == 0) && ((s & 0x8) > 0)) {
		return 1;
	}
	
	if (((s & 0x1) > 0) || ((s & 0x20) > 0)) return 1;
	return 0;
}

void ata()
{
    unsigned char exists = 0;
    unsigned char stat = 0;
    //reset first
    outb(_ATA_RST, (unsigned char)0x04);
    udelay();
    
    outb(_ATA_RST, (unsigned char)0);
    outb(_ATAIO_BASE + 6, 0xA0);
    outb(_ATAIO_BASE + 2, (unsigned char)0);
	outb(_ATAIO_BASE + 3, (unsigned char)0);
	outb(_ATAIO_BASE + 4, (unsigned char)0);
	outb(_ATAIO_BASE + 5, (unsigned char)0);
    outb(_ATAIO_BASE + 7, (unsigned char)0xEC);
    udelay();
    exists = inb(_ATAIO_BASE + 7);
    
    if (!exists) {
        printf("!!!not exists");
        return;
    }    
    
    unsigned char cl = 0;
    unsigned char ch = 0;
    
    while((stat & 0x80) != 0) {
        stat = inb(_ATAIO_BASE + 7);
    }
    
    cl = inb(_ATAIO_BASE + 4);
    ch = inb(_ATAIO_BASE + 5);
    printf("%#3x, %#3x\n", cl, ch);
    for(int i = 0; i < 256; i++) {
		printf("%-5x", inw(_ATAIO_BASE + 0));
    }
    printf("\n\n");
}

void cmos()
{
    unsigned char buff[128];
    memset(buff, 0, 128);
    
    outb(0x70, 0x9);
    buff[0] = inb(0x71);
        
    for (char ii = 0; ii < 1; ii++) {
        printf("%-3x", buff[ii]);
    }
}

void read_idtr()
{
    memset(&idtr, 0, sizeof(struct dt));
    __asm__ __volatile__(
    "sidt %0":"=m"(idtr)
    );
    
    unsigned char* base = (unsigned char*)idtr.la;
    
    printf("idtr=%#x,%#x\n", idtr.size, idtr.la);
}

void read_idt()
{
    int kmem = open("/dev/kmem", O_RDONLY );
    if (kmem < 0) {
        printf("!!!open kmem failed");
        exit(1);
    }
    
    uint8_t buf[0x7FF];
    memset(buf, 0, 0x7FF*sizeof(uint8_t));
    
    lseek(kmem, idtr.la, SEEK_SET);
    int realsize = read(kmem, buf, idtr.size);
    
    for (int i = 0; i < realsize; i++) {
        printf("%-3x", buf[i]);
    }
    close(kmem);
}
 
int main(void) 
{
    /*adjust privilege*/
    if (iopl (3) == -1) {
        fprintf(stderr, "!!!failed to adjust privilege");
        return -1;
    }
    read_idtr();
    read_idt();
    return 0;
}
