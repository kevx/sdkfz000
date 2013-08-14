#!/usr/bin/env python

import sys

def main():
    for line in sys.stdin:
        try:
            s = line.strip()
            s = line.replace('[', '')
            s = s.replace(']', '')
            s = s.replace('"', '')
            print s
        except:
            print >> sys.stderr, "myrepl_failed"
            continue

if __name__ == "__main__":
    main()
