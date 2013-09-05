#!/usr/bin/python
shoplist = ['apple', 'orange', 'mango', 'carror', 'banana']
print 'I have ', len(shoplist), ' item to purchase.'

print 'There item are'
for item in shoplist:
    print item,

print 'I will sort items'
shoplist.sort()

for item in shoplist:
    print item,

shoplist.append("Bran")

print 'I shoping list is now', shoplist

olditem = shoplist[0]

del shoplist[0] 
print 'now I bought the', olditem

shoplist.sort()
print 'My shopping list is now', shoplist
