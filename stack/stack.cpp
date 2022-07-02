#include "stack.h"
#include <assert.h>
#include <stdio.h>
#include <stdlib.h>

stack::stack() {
	this->top = 0;
	this->dane = (int*)malloc(this->fsize * (sizeof(int)));
}

stack::~stack() { free(this->dane); }

void stack::clear() {
	this->top = 0;
	this->fsize = 10;
	this->dane = (int*)realloc(this->dane,this->fsize * (sizeof(int)));
}

void stack::push(int a) {
	if ((top % 10 == 0)) {
		this->fsize = (this->top + 10);
		this->dane = (int*)realloc(this->dane, this->fsize * sizeof(int));
	}
	assert(this->top < this->fsize);
	this->dane[this->top++] = a;
}

int stack::pop() {
	assert(this->top > 0);
	return this->dane[--this->top];
}
