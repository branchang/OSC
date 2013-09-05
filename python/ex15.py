#!/usr/bin/python
from sys import argv

script, filename = argv

txt = open(filename)

print txt.read()

filename = raw_input(">")

txt_again = open(filename)

print txt_again.read()
