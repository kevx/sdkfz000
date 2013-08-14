#coding=UTF-8
"""
kiev-query
"""
import sys
import sqlite3

def main():
	conn = sqlite3.connect('kiev0.db')
	c = conn.cursor()
	fn = u'夏震'.encode('utf-8')
	rows = c.execute("select * from kiev where fullname='%s' limit 100"%fn)
	for row in rows:
		print(row[1])
	conn.close()
	
if __name__ == '__main__':
	main()