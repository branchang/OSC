#!/usr/bin/python

class SchoolMember:
    def __init__(self, name, age):
        self.name = name
        self.age = age
    def tell(self):
        print 'Name is "%s", Age: "%s"' %  (self.name,self.age) 

class Teacher(SchoolMember):
    def __init__(self, name, age, salary):
        SchoolMember.__init__(self,name, age)
        self.salary = salary
        print '(initialized Teacher:"%s")' % self.name

    def tell(self):
        SchoolMember.tell(self)
        print 'Salary:"%d"' % self.salary

class Student(SchoolMember):
    def __init__(self, name, age, marks):
        SchoolMember.__init__(self, name, age)
        self.marks = marks
        print '(initialized Student "%s")' % self.name
    def tell(self):
        SchoolMember.tell(self)
        print 'Marks: "%d"' % self.marks

t  = Teacher("Mrs.Shrividya", 40, 30000)
s = Student("Bran", 22, 77)

members = [t,s]
for member in members:
    member.tell()
