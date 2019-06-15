#ifndef INVMENU_H
#define INVMENU_H

#include <string>
#include "bookType.h"
#include "linkedList.h"
#include "orderedLinkedList.h"

//Function name: inventoryModule
//Purpose: create a menu for inventory menu
// Receives: 4 orderedLinkedList of bookType dataType
// Returns: nothing
void inventoryModule(orderedLinkedList<bookType> &list0, orderedLinkedList<bookType> &list1, orderedLinkedList<bookType> &list2, orderedLinkedList<bookType> &list3);

//Function name: lookUpBook
//Purpose: search function for a book in the database
// Receives: 4 orderedLinkedList of bookType dataType
// Returns: pointer to the book if found in the list.  Returns nullptr if book is not found 
bookType* lookUpBook(orderedLinkedList<bookType> &list0, orderedLinkedList<bookType> &list1, orderedLinkedList<bookType> &list2, orderedLinkedList<bookType> &list3);

//Function name: addBook
//Purpose: add a new book into the database
// Receives: 4 orderedLinkedList of bookType dataType
// Returns: nothing
void addBook(orderedLinkedList<bookType> &list0, orderedLinkedList<bookType> &list1, orderedLinkedList<bookType> &list2, orderedLinkedList<bookType> &list3);

//Function name: editBook
//Purpose: edit each memebr vairables of the object
// Receives: 4 orderedLinkedList of bookType dataType
// Returns: nothing
void editBook(orderedLinkedList<bookType> &list0, orderedLinkedList<bookType> &list1, orderedLinkedList<bookType> &list2, orderedLinkedList<bookType> &list3);

//Function name: deleteBook
//Purpose: delete a book from the database
// Receives: 4 orderedLinkedList of bookType dataType
// Returns: nothing
void deleteBook(orderedLinkedList<bookType> &list0, orderedLinkedList<bookType> &list1, orderedLinkedList<bookType> &list2, orderedLinkedList<bookType> &list3);

#endif
