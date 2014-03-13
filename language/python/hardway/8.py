#!/usr/bin/python
formatter = "%r %r %r %r"

print formatter % (1, 2, 3, 4)
print formatter % ("a", "b", "c", "d")
print formatter % (True, False, True, False)
print formatter % (formatter, formatter, formatter, formatter)
print formatter % ("I had this thing", "that you could type up down", 
        "buf I don't know", "so I said goodnight")

print '\n\n'
from os import *

str = getcwd()
print str
print getcwdu()

print getpid()
print getlogin()

abort()
system("echo Bran!!")

