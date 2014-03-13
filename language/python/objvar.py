#!/usr/bin/python

class Person():
    population = 0
    def __init__(self, name,age):
        self.name = name
        self.age = age
        print '(initializing %s, %d)' % (self.name,self.age)
        Person.population += 1

    def __del__(self):
        Person.population -= 1
        print '%s sys bye.' % self.name

        if Person.population == 0:
            print 'i ma the last one.'
        else:
            print 'there are still %d people left' % Person.population
            
    def sayHi(self):
        print 'hi i am %s->%d' % (self.name,self.age)
    
    def howMany(self):
        if Person.population == 1:
            print 'i am the only person here' 
        else:
            print 'we have %d person is here' % Person.population


swaroop = Person('Swaroop', 23)
swaroop.sayHi()
swaroop.howMany()
kalam = Person('Abdul Kalam', 25)
kalam.sayHi()
kalam.howMany()
swaroop.sayHi()
swaroop.howMany()

        
