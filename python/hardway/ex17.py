#!/usr/bin/python

from sys import argv

script, from_file, to_file = argv

fp = open(from_file, "r")

context = fp.read()

fpp = open(to_file, "w")

fpp.write(context)

