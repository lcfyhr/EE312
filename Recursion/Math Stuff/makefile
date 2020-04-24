# target: dependencies
# <tab> rule

# make (without arguments) executes first rule in file
# Ideally, one target for every object file and a target for final binary.

math_stuff: mathstuff.o
	c99 -o math_stuff mathstuff.o

mathstuff.o: mathstuff.c
	c99 -c mathstuff.c