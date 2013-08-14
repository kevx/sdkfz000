#coding=UTF-8
"""
kiev-init
"""
import sys
import sqlite3
import time

def is_cn_char(i): 
    return 0x4e00<=ord(i)<0x9fa6
	
def ignore(name, idnum):
	npfx = name[0:1]
	if is_cn_char(npfx): return False
	return True
	
def main():
	conn = sqlite3.connect('kiev0.db')
	c = conn.cursor()
	sz = 0
	batch = 0
	t1 = long(time.time())
	for line in sys.stdin:
		try:
			if sz == 1000:
				print('batch #%d ... completed'%batch) 
				sz = 0
				batch = batch + 1
				conn.commit()
			line = line.decode('utf-8')
			ss = line.split('\001')
			if len(ss) != 2: continue
			fullname = ss[0].strip()
			idnum = ss[1].strip()
			if ignore(fullname, idnum) == True: continue

			c.execute('insert into kiev values(?,?)', (fullname,idnum))
			sz = sz + 1
		except Exception,e:
			print >> sys.stderr, e
			continue
	
	t2 = long(time.time())
	print('import done! time:%d ms'%(t2-t1))
	if sz > 0:
		conn.commit()
	conn.close()
	
if __name__ == '__main__':
	main()