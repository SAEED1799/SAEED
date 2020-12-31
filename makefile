CC=gcc
AR=ar
OBJECT_TXT_FIND=txtfind.o 
OBJECT_INSERTION_SORT=isort.o
FLAGS = -Wall -g

all: main

main: txtfindmain isortmain

txtfindmain: $(OBJECT_TXT_FIND) txtfind
	     $(CC) $(FLAGS) -o txtfind $(OBJECT_TXT_FIND) libtxtfind.a 

isortmain: $(OBJECT_INSERTION_SORT) isort
	     $(CC) $(FLAGS) -o isort $(OBJECT_INSERTION_SORT) libisort.a 


txtfind: libtxtfind.a
libtxtfind.a: $(OBJECT_TXT_FIND)
	 $(AR) -rcs libtxtfind.a $(OBJECT_TXT_FIND) 


isort: libisort.a
libisort.a: $(OBJECT_INSERTION_SORT)
	 $(AR) -rcs libisort.a $(OBJECT_INSERTION_SORT) 


txtfind.o: txtfind.c
	 $(CC) $(FLAGS) -c -fPIC txtfind.c

isort.o: isort.c
	 $(CC) $(FLAGS) -c -fPIC isort.c

.PHONY: 
	all clean txtfind main isort
clean: 
	 rm -rf *.o *.a main 
