# target: dependencies
# <tab> rule

# make (without arguments) executes first rule in file
# Ideally, one target for every object file and a target for final binary.

floodfill: driver.o stack312_ll.o
	c99 -o floodfill driver.o stack312_ll.o

driver.o: driver.c
	c99 -c driver.c

stack312_ll.o: stack312_ll.c stack312_ll.h
	c99 -c stack312_ll.c