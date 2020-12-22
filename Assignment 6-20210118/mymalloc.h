#ifndef MYMALLOC_H
#define MYMALLOC_H

#include <stdio.h>
#include <stddef.h>

char memory[25000];

struct block {
	size_t size;
	int isFree;
	struct block *next;
};

struct block *freeList = (void*) memory;

void initilize ();
void split (struct block*, size_t);
void* myMalloc (size_t);
void merge ();
void myFree (void*);

#endif

