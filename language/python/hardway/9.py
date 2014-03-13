#!/usr/bin/python
days= "Mon Tue Wed Thu Fri Sat Sun"
months = "Jan\nFeb\nMar\nApr\nMay\nJun\nJul\nAug"

print "Here are the days: ", days
print "Here are the months: ", months

print """
There's something going on here.
With the three double-quotes.
We'll be able to type as much as we like.
Even 4 lines if we want, or 5, or 6.
"""



tabby_cat = "\tI'm tabbed in."
persian_cat = "I'm split\non a line."
backslash_cat = "I'm \\ a \\ cat."

fat_cat = """
I'll do a list:
\t* Cat food
\t* Fishies
\t* Catnip\n\t* Grass
"""

print tabby_cat
print persian_cat
print backslash_cat
print fat_cat

from os.path import *
from sys import getsizeof

file_path = "/home/Bran/dic.txt"
if exists(file_path):
    fobj = open(file_path, 'r+')
    #str = fobj.read(10)
    str = fobj.readline()
    while str:
        print "%r" % str,
        str = fobj.readline()
else:
    print "no exists"

#fobj.write("Bran write")
len = getsizeof(fobj)
fobj.close()
print "done!"
print len



