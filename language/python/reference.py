#!/usr/bin/python
print 'Simple A ssignment'
shoplist = ['apple', 'mango', 'carrot', 'banana']
mylist = shoplist

del shoplist[0]

print 'shoplist', shoplist
print 'mylist', mylist

print 'Copy by making a full slice'
mylist = shoplist[:]
del mylist[0]

print 'shoplist', shoplist
print 'mylist', mylist
print "svn test2 "
