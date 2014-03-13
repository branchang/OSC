#!/usr/bin/python
def FOO(op, n1, n2):
    return eval("%d %s %d" %  (n1, op, n2))

print FOO('*', 1, 2)

