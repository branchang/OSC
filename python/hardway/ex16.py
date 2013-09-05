#!/usr/bin/python

from sys import argv
scriptname, filename = argv

print "you will open file name:%s", filename
print "If you don't want do that, hit CTRL-C."
print "If you want do that , hit RETURN."

raw_input('?')

print "Open the file ...."

fp = open(filename, 'w')
#fp.truncate()

line1 = raw_input("line1:")
line2 = raw_input("line2:")
line3 = raw_input("line3:")

fp.write(line1)
fp.write("\n")
fp.write(line2)
fp.write('\n')
fp.write(line3)
fp.write("\n")

print "done!!\n"
fp.close()
