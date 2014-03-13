#!/usr/bin/python
zoo = ('wolf', 'elephant', 'penguin')
print 'Number of animals in the zoo is ', len(zoo)

new_zoo = ('momkey', 'dolphin', zoo)

print 'Number of animals in the new zoo is ', len(new_zoo)

print 'all animals in new zoo are', new_zoo
print "old zoo ", new_zoo[2], zoo
print new_zoo[2][2]
