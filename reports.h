#ifndef REPORTS_H
#define REPORTS_H

#include "linkedList.h"
#include "orderedLinkedList.h"

// Function name: reportsModule
// Purpose: create a menu for reports module
// Receives: 4 orderedLinkedList of bookType dataType
// Returns: nothing
void reportsModule(orderedLinkedList<bookType> &list0, orderedLinkedList<bookType> &list1, orderedLinkedList<bookType> &list2, orderedLinkedList<bookType> &list3);

// Function name: repListing
// Purpose: display all the member variables/info for all the books in database
// Receives: bookType pointer to pointer bookArray
// Returns: nothing
void repListing(orderedLinkedList<bookType> &list0, orderedLinkedList<bookType> &list1, orderedLinkedList<bookType> &list2, orderedLinkedList<bookType> &list3);

// Function name: repWholesale
// Purpose: displays the wholesale cost of every book and reports the total
//         wholesale value in the database
// Receives: 4 orderedLinkedList of bookType dataType
// Returns: nothing
void repWholesale(orderedLinkedList<bookType> &list0, orderedLinkedList<bookType> &list1, orderedLinkedList<bookType> &list2, orderedLinkedList<bookType> &list3);

// Function name: repRetail
// Purpose: displays retail value of all the books and reports the total
//         retail value in the database
// Receives: 4 orderedLinkedList of bookType dataType
// Returns: nothing
void repRetail(orderedLinkedList<bookType> &list0, orderedLinkedList<bookType> &list1, orderedLinkedList<bookType> &list2, orderedLinkedList<bookType> &list3);

// Function name: repQty
// Purpose: displays qty in hand in order greatest to least
// Receives:  4 orderedLinkedList of bookType dataType
// Returns: nothing
void repQty(orderedLinkedList<bookType> &list0, orderedLinkedList<bookType> &list1, orderedLinkedList<bookType> &list2, orderedLinkedList<bookType> &list3);

// Function name: repCost
// Purpose: displays wholesale cost in order from most expensive to least expensive
// Receives:  4 orderedLinkedList of bookType dataType
// Returns: nothing
void repCost(orderedLinkedList<bookType> &list0, orderedLinkedList<bookType> &list1, orderedLinkedList<bookType> &list2, orderedLinkedList<bookType> &list3);

// Function name: repAge
// Purpose: displays by date added to database from oldest to most recent 
// Receives:  4 orderedLinkedList of bookType dataType
// Returns: nothing
void repAge(orderedLinkedList<bookType> &list0, orderedLinkedList<bookType> &list1, orderedLinkedList<bookType> &list2, orderedLinkedList<bookType> &list3);


#endif
