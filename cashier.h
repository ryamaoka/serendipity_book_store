#ifndef CASHIER_H
#define CASHIER_H

#include "bookType.h"
#include "linkedList.h"
#include "orderedLinkedList.h"

//Function name: casheirModule
//Purpose: casheir POS
// Receives:4 orderedLinkedList of bookType dataType  
// Returns: nothing
void cashierModule(orderedLinkedList<bookType> &list0, orderedLinkedList<bookType> &list1, orderedLinkedList<bookType> &list2, orderedLinkedList<bookType> &list3);


#endif
