/*
 * stub is a replacement for jni.
 * stub loads shared objects in its own memory space
 * so that even if these objects crash, the main
 * java process will survive and may start a new 
 * stub instance to continue its work.
 * 
 * stdin & stdout are used to communicate with each other.
 * Tasks should be proccessed one by one. Multi-task can
 * be achieved by running multi stub instances.
 */
 

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

#define MAX_CMD_LEN 1024

typedef enum {
    invalid = -1,
    normal = 0,
    destroy = 1
} opcode;

opcode parse_op(char* cmd, char** out)
{
    char buf[5];
    memset(buf, 0, 5);
    char* pop = strchr(cmd, ',');
    if (pop == NULL) return invalid;
    
    *out = pop;
    strncpy(buf, cmd, (pop - cmd));
    return atoi(buf);
}

int main(void) 
{
    char cmdBuf[MAX_CMD_LEN];
    char* pcmd = NULL;
    int willEnd = 0;
    
    while (!willEnd) {
        memset(cmdBuf, 0, MAX_CMD_LEN);
        fscanf(stdin, "%s", cmdBuf);
        
        opcode opc = parse_op(cmdBuf, &pcmd);
        fprintf(stdout, "%d\n", opc);
        switch(opc) {
        case normal:
            break;
        case destroy:
            willEnd = 1;break;
        default:break;
        }
    }
    
    return 0;
}
