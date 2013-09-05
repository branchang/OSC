#!/usr/bin/python

#'ab' is short for 'a'ddress'b'ook

ab = {
        'Swaroop':'Swaroop@sunniwell.com',
        'Orange':'Orangezhr@sunniwel.com',
        'Bran':'Bran.Zhang@google.com'
        }

print "Orange address is %s" % ab['Orange']

ab['Bran'] = "Brans.Zhang@gmail.com"

del ab['Orange']

for name,address in ab.items():
    print 'Contact %s at %s' % (name, address)

if 'Bran' in ab:        #or ab.has_kety('Bran')
    print "\n Bran sddress is %s" % ab['Bran']
