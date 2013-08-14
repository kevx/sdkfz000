#coding=UTF-8
"""
kiev-init
"""
import sys
import sqlite3
	
def main():
	conn = sqlite3.connect('kiev0.db')
	c = conn.cursor()
	c.execute('create index indx_fullname on kiev (fullname)')

	conn.commit()
	conn.close()
	
if __name__ == '__main__':
	main()