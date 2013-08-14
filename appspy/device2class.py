#coding=UTF-8

#!/usr/bin/env python

#created by beitang.xz@08/15/2012
import sys

catMap = {
    
}

def main():
    try:
        for line in sys.stdin:
            ss = line.split() #user_id, appdata, model
            if devMap.has_key(ss[2].strip()):
                print '%s\t%s\t%s'%(ss[0], ss[1], devMap[ss[2].strip()])
            else:
                print '%s\t%s\t%d'%(ss[0], ss[1], 0)
    except:
        print 0
        return

if __name__ == "__main__":
    main()
