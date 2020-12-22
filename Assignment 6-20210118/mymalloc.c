#include <stdio.h>
#include <stddef.h>
#include "mymalloc.h"

void initialize () {
	freeList->size = 25000 - sizeof(struct block);
	freeList->isFree = 1;
	freeList->next = NULL;
}

void split (struct block* fittingSlot, size_t size) {
	struct block* new = (void*) ((void*)fittingSlot + size + sizeof(struct block));
	new->size = (fittingSlot->size) - size - sizeof(struct block);
	new->isFree = 1;
	new->next = fittingSlot->next;
	fittingSlot->size = size;
	fittingSlot->isFree = 0;
	fittingSlot->next = new;
}

void* myMalloc (size_t size) {
	if (!(freeList->size)) {
		initialize();
	}
	struct block *current;
	current = freeList;
	while (1) {
		if (!current) {
			break;
		}
		if (current->size > size && current->isFree) {
			break;
		}
		current = current->next;
	}
	if (!current) {
		return NULL;
	}
	if (current->size == size) {
		current->isFree = 0;
		current++;
		return (void*) current;
	}
	split(current, size);
	current++;
	return (void*) current;
}

void merge () {
	struct block *current = freeList;
	while (current->next) {
		if (current->isFree && current->next->isFree) {
			current->size += current->next->size + sizeof(struct block);
			current->next = current->next->next;
		} else {
			current = current->next;
		}
	}
}

void myFree (void *ptr) {
	struct block *current = --ptr;
	current->isFree = 1;
	merge();
}

