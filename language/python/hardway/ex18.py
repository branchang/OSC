#!/usr/bin/python

def print_argv(*argv):
    arg1, arg2 = argv
    print "first is %r,seconed is %r" % (arg1, arg2)

def print_one(argc):
    arg1 = argc
    print "only one argc is %r \n" % arg1

def print_two(argc1, argc2):
    print "argc1 %s, argc2 %s \n" % (argc1, argc2)

print_argv("Bran", "Is")
print_one("a")
print_two("pro", "boy")
