#!/usr/bin/python
def func_doc(x,y):
    ''' Prints the maximum of two numbers.

    The two values must be int.'''
    if x > y:
        print x
    else:
        print y

func_doc(4,5)
#print func_doc.__doc__
help(func_doc)
