#include <stdio.h>
#include "stack.h"

int main()
{
	stack s1;
	stack s2;
	s1.push(1);
	s1.push(2);
	s1.push(3);
	s1.push(4);
	s1.push(5);
	s1.push(6);
	s1.push(7);
	s1.push(8);
	s1.push(9);
	s1.push(10);
	s1.push(11);
	s1.push(1);
	s1.push(2);
	s1.push(3);
	s1.push(4);
	s1.push(5);
	s1.push(6);
	s1.push(7);
	s1.push(8);
	s1.push(30);
	s1.push(31);
	s1.push(32);
	s1.clear();
	s1.push(2);
	s1.push(4);
	printf("%d %d\n",s1.pop(),s1.pop());
	s1.clear();
	s1.push(1);
	s1.push(2);
	s1.push(3);
	s1.push(4);
	s1.push(5);
	s1.push(6);
	s1.push(7);
	s1.push(8);
	s1.push(9);
	s1.push(10);
	s1.push(11);
	s1.push(1);
	s1.push(2);
	s1.push(3);
	s1.push(4);
	s1.push(5);
	s1.push(6);
	s1.push(7);
	s1.push(8);
	s1.push(30);
	s1.push(31);
	s1.push(32);
	printf("%d %d\n",s1.pop(),s1.pop());
	return 0;
}
