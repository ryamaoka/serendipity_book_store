#ifndef ORDEREDLINKEDLIST_H
#define ORDEREDLINKEDLIST_H


#define NDEBUG
#include <cassert>
#include <iostream>
#include "linkedList.h"
using namespace std;


template <class Type>
class orderedLinkedList: public linkedListType<Type>
{
  using linkedListType<Type>::first;
  using linkedListType<Type>::last;
  using linkedListType<Type>::count;

public:

  bool search(const Type& searchItem) const;
    // function to determine whether searchItem is in the list
    // postCondition: returns true if searchItem is in the list, otherwise it returns false

  void insert(const Type& newItem);
    // function to insert newItem in the list
    // postCondition: first points to the new list, newItem is inserted at the proper place in the list, and count is incremented by 1

  Type* lookUpBook(const Type& searchItem) const;
    // function to return a item in the list if Found
    // postCondition: returns the item if the searchItem is in the list, otherwise returns a nullptr 

  void insertFirst(const Type& newItem);
    // function to insert newItem in the list.
    // becuase the resulting list must be sorted, newItem is inserted at the proper place in the list.
    // this function uses the function insert to insert newItem
    // postCondition: first points to the new list, newItem is inserted at the propoer place in the list, and count is incremented by 1

  void insertLast(const Type& newItem);
    // function to insert newItem in the list
    // Because the resulting list must be sorted, newItem is inserted at the proper place in the list
    // This function uses the function insert to insert newItem
    // postCondition: first points to the new list, newItem is inserted at the proper place in the list, and count is incremented by 1.

  void deleteNode(const Type& deleteItem);
    // function to delete deleteItem from the list.
    // postCondition: if found, the node containing deleteItem is deleted from the list; first points to the first node of the new list, and count is decremented by 1.
    // if deleteItem is not in the list, an appropriate message is printed
};


template <class Type>
bool orderedLinkedList<Type>::search(const Type& searchItem) const
{
  bool found = false;
  nodeType<Type> *current;      // pointer to traverse the list

  current = first;              // start the search at the first node

  while (current != nullptr &&  !found)
  {
    if (current->info >= searchItem)
    {
      found = true;
    }
    else
    {
      current = current->link;
    }
  }

  if (found)
  {
    found = (current->info == searchItem);  // test for equality
  }

  return found;
}


template <class Type>
void orderedLinkedList<Type>::insert(const Type& newItem)
{
  nodeType<Type> *current;                    // pointer to traverse the list
  nodeType<Type> *trailCurrent = nullptr;     // pointer just before current
  nodeType<Type> *newNode;                    // pointer to create a node
  bool found;

  newNode = new nodeType<Type>;
  newNode->info = newItem;
  newNode->link = nullptr;

  if (first == nullptr)
  {
    first = newNode;
    last = newNode;
    count++;
  }
  else
  {
    current = first;
    found = false;

    while (current != nullptr && !found)      // search the list
    {
      if (current->info >= newItem)
      {
        found = true;
      }
      else
      {
        trailCurrent = current;
        current = current->link;
      }
    }

    if (current == first)
    {
      newNode->link = first;
      first = newNode;
      count++;
    }
    else
    {
      trailCurrent->link = newNode;
      newNode->link = current;

      if (current == nullptr)
      {
        last = newNode;
      }

      count++;
    }
  }
}

template <class Type>
Type* orderedLinkedList<Type>::lookUpBook(const Type& searchItem) const
{
  bool found = false;
  nodeType<Type> *current = nullptr;    // pointer to traverse the list

  current = first;          // start the search at the first node

  while (current != nullptr && !found)
  {
    if (current->info == searchItem)
    {

      return &current->info;
    }


    current = current->link;

  }
  return nullptr;
}


template <class Type>
void orderedLinkedList<Type>::insertFirst(const Type& newItem)
{
  insert(newItem);
}


template <class Type>
void orderedLinkedList<Type>::insertLast(const Type& newItem)
{
  insert(newItem);
}


template <class Type>
void orderedLinkedList<Type>::deleteNode(const Type& deleteItem)
{
  nodeType<Type> *current;       // pointer to traverse the list
  nodeType<Type> *trailCurrent = nullptr;       // pointer just before current
  bool found;

  if (first == nullptr)
  {
    cout << "Cannot delete from an empty list" << endl;
  }
  else
  {
    current = first;
    found = false;

    while (current != nullptr && !found)
    {
      //cout << "Current info" << endl;
      //cout << current->info << endl;


      if (current->info == deleteItem)  //edit >= to ==
      {
        //cout << "*************************************** book found ****************************************" << endl;
        found = true;
      }
      else
      {
        trailCurrent = current;
        current = current->link;
      }
    }
    if (current == nullptr)
    {
      cout << "The item to be deleted is not in the list" << endl;
    }
    else
    {
      //cout << "Current info" << endl;
      //cout << current->info << endl;
      //cout << "deleteItem" << endl;
      //cout << deleteItem << endl;
      if (current->info == deleteItem)
      {
        if (first == current)
        {
          first = first->link;
          if (first == nullptr)
          {
            last = nullptr;
          }
          delete current;
        }
        else
        {
          trailCurrent->link = current->link;
          if (current == last)
          {
            last = trailCurrent;
          }
        }
        count--;
      }
      else
      {
        cout << "The item to be deleted is not in the list" << endl;
      }
    }
  }







/*
  if (first == nullptr)
  {
    cout << "Cannot delete from an empty list" << endl;
  }
  else
  {

    current = first;
    found = false;

    while(current != nullptr && !found)   // search the list
    {
      if (current->info >= deleteItem)
      {
        found = true;
      }
      else
      {
        trailCurrent = current;
        current = current->link;
      }
    }

    if (current == nullptr)
    {
      cout << "The item to be deleted is not in the list 1" << endl;
    }
    else
    {
      //edit
      cout << "current info" << endl;
      cout << current->info << endl;
      cout << "deleteItem" << endl;
      cout << deleteItem << endl;
      if (current->info == deleteItem)
      {
        if (first == current)
        {
          first = first->link;

          if (first == nullptr)
          {
            last = nullptr;
          }
          delete current;
        }
        else
        {
          trailCurrent->link = current->link;

          if (current == last)
          {
            last = trailCurrent;
          }

          delete current;
        }

        count--;
      }
      else
      {
        cout << "The item to be deleted is not in the list 2" << endl;
      }
    }
  }
}
*/
}
#endif
