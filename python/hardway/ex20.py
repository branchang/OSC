#!/usr/python
from sys import argv

scritpy, filename = argv

def print_all(f):
    print f.read()

def rewind(f):
    f.seek(0)

def print_a_line(line_count, f):
    print line_count, f.readline()

current_line = open(filename)

print_all(current_line)

rewind(current_line)

currentline = 1

print_a_line(currentline, current_line)

currentline = currentline + 1

print_a_line(currentline, current_line)


currentline = currentline + 1

print_a_line(currentline, current_line)
