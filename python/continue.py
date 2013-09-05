#!/usr/bin/python
while True:
    s = raw_input("Bran, input sth..\n")
    if s == "quit":
        break
    if len(s) < 4:
        continue
    print "you input is ",s, ",Bran."
print "doen while"
