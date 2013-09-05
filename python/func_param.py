#!/usr/bin/python
def func_param(a,b):
    if a > b:
        print a,">" ,b
    elif a < b:
        print a,"<", b
    else:
        print a, "==", b

while True:
    a = int(raw_input("input a = "))
    b = int(raw_input("input b = "))
    func_param(a,b)
else:
    print "done"
    
