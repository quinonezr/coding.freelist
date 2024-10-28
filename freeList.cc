#include "freeList.h"

freeList::freeList( long int*inRAM, int size ) {

  
  head = &inRAM[0];
  *head = size - long(2);
  *(head+1) = NULL;

}

long int*
freeList::reserve_space( int size ) {
  long int* loc = NULL;

*(head + size + 2) = *head - size - 2;
*(head + size + 3) = *(head + 2); 
*head = size; 
loc = head + 2;
head = head + size + 2;



  return loc;
}

void
freeList::free_space( long int* location ) {
*(location - 1) = reinterpret_cast<long int>(head);
head = (location - 2);



  
}

void
freeList::coalesce_forward() {
  long int* next;
  long int* current = head;
  next = reinterpret_cast<long int*>(*(head +1));
  while (next != NULL){
  
  if ((current + *current + 2) == next) {
      *current = *next + *current + 2;
    *(current + 1) = reinterpret_cast<long int>(*(next +1));
    current = next;
      next = reinterpret_cast<long int*>(*(current + 1));
  }
    else {
      current = next;
      next = reinterpret_cast<long int*>(*(current + 1));
      }
    
  }
}

// print() is given to you. It traverses the free list and prints out what is there.
void freeList::print() {
  long int * printHead = head;
  
  while( printHead != NULL ) {
    cout << "at " << printHead << "("<< dec <<printHead[0] << " : 0x" << hex << printHead[1] <<  ")\n";
    printHead = (long int *)printHead[1];
  }
}
