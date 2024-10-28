#include "freeList.h"
#include <stdlib.h>
#include <iostream>
#include <stdio.h>
using namespace std;

long int* RAM; // basically simulating RAM at the start of this
	       // program as a dynamically allocated array of unsigned
	       // chars, which are byte sized long its because the OS
	       // this program is running on is 64bit system. 64 bits
	       // means each spot takes up 8 bytes.

int main() {
  RAM = new long int[8192];

  freeList me(RAM,8192);
  cout << "Start" << endl;
  me.print();

  long int* addr1 = me.reserve_space(100);
  cout << "Allocation 1" << endl;
  me.print();
  long int* addr2 = me.reserve_space(200);
  cout << "Allocation 2" << endl;
  me.print();

  me.free_space( addr1 );
  cout << "Free 1" << endl;
  me.print();
  me.coalesce_forward();
  cout << "Coalesce 1" << endl;
  me.print();

  me.free_space( addr2 );
  cout << "Free 2" << endl;
  me.print();

  me.coalesce_forward();
  cout << "Coalesce 2" << endl;
  me.print();
  
  
  delete RAM;
  return 0;
}
