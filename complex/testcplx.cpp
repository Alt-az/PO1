#include <iostream>
using namespace std;
#include "complex.h"


int main()
{
  Complex a(3,15),b(0,13),c;
  b=3-a;
  cout<<b<<endl;
  c = 10;
  cout << c <<endl;
  c = -a;
  cout << c <<endl;  
  c = a + b;
  c = c - Complex(10);
  cout << c <<endl;  
  c = 10 - a;
  (c -=b) -=10;
  cout << c <<endl;
  cout<< b.abs()<<endl;
  cout<< b.phase()<<endl;
  b.conj();
  cout <<b<<endl;
  c=Complex(10,10);
  c/=Complex(5,5);
  cout<<c<<endl;
  c=a/2;
  cout<<c<<endl;
  c=2/a;
  cout<<c<<endl;
}
