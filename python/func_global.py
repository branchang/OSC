#!/usr/bin/python

def func():
    global x
    print "x is", x
    x = 7 
    print " x is ", x

x = 50
func()
print "x is", x
