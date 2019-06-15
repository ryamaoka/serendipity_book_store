#ifndef LINKEDLIST_H
#define LINKEDLIST_H

//#define NDEBUG
#include <iostream>
#include <cassert>
using namespace std;

//******************************* nodeType *******************************
template <class Type>
struct nodeType
{
  Type info;
  nodeType<Type> *link;
};

//******************************* class linkedList Iterator  *******************************
template <class Type>
class linkedListIterator
{
private:
  nodeType<Type> *current;
    //pointer to point to the current node in the linked list

public:
  linkedListIterator();
    // default constructor
    // postCondition: current = nullptr;

  linkedListIterator(nodeType<Type> *ptr);
    // constructor with parameter
    // postCondition: current = ptr;

  Type operator*();
    // function to overload the dereferencing operator
    // postCondition: returns the info contained in the node

  linkedListIterator<Type> operator++();
    // overload the pre increment operator
    // postCondition the iterator is advanced to the next node

  bool operator==(const linkedListIterator<Type>& right) const;
    // overload the equality operator
    // postCondition: returns true if this iterator is equal to the iterator specified by right, otherwise it returns false

  bool operator!=(const linkedListIterator<Type>& right) const;
    // overload the not equal to operator
    // postCondition: returns true if this iterator is not equal to the iterator specified by right, otherwise it returns false


};



template <class Type>
linkedListIterator<Type>::linkedListIterator()
{
  current = nullptr;
}


template <class Type>
linkedListIterator<Type>::linkedListIterator(nodeType<Type> *ptr)
{
  current = ptr;
}

template <class Type>
Type linkedListIterator<Type>::operator*()
{
  return current->info;
}

template <class Type>
linkedListIterator<Type> linkedListIterator<Type>::operator++()
{
  current = current->link;

  return *this;
}

template <class Type>
bool linkedListIterator<Type>::operator==(const linkedListIterator<Type>& right) const
{
  return (current == right.current);
}

template <class Type>
bool linkedListIterator<Type>::operator!=(const linkedListIterator<Type>& right) const
{
  return (current != right.current);
}



//******************************* class linkedListType *******************************
template <class Type>
class linkedListType
{
private:
  void copyList(const linkedListType<Type>& otherList);
    // function to make a copy of otherList
    // postCondition: a copy of otherList is created and assigned to this list

protected:
  int count;
    // variable to store the number of elements in the list

  nodeType<Type> *first;
    // pointer to the first node of the list

  nodeType<Type> *last;
    // pointer to the last node of the list

public:
  const linkedListType<Type>& operator= (const linkedListType<Type>& );
    // overloads the assignment operator

  void initializeList();
    // initialize the list to an empty state.
    // postCondition: first = nullptr, last = nullptr, count = 0

  bool isEmpty() const;
    // function to determine whether the list is empty
    // postCondition: returns true if the list is empty, otherwise it returns false

  void print() const;
    // function to output the data contained in each node
    // postCondition: none

  int length() const;
    // function to return the number of nodes in the list
    // postCondition: the value of count is returned

  void destroyList();
    // function to delete all the nodes from the list
    // postCondition: first = nullptr, last = nullptr, count = 0.

  Type front() const;
    // function to return the first element of the list
    // preCondition: the list must exist and must not be empty
    // postCondition: if the list is empty, the program terminates; otherwise, the first element of the list is returned

  Type back() const;
    // function to return the last element of the list.
    // preCondition: the list must exist and must not be empty
    // postCondition: if the list is empty, the program terminates; otherwise, the last element of the list is returned

  virtual bool search(const Type& searchItem) const = 0;
    // function to determine whether searchItem is in the list
    // postCondition:returns true if searchItem is in the list, otherwise the value false is returned

  virtual void insertFirst(const Type& newItem) = 0;
    // function to insert newItem at the beginning of the list.
    // postCondition: first points to the new list, newItem is inserted at the  beginning of the list, last points to the last node in the list, and count is incremented by 1

  virtual void insertLast(const Type& newItem) = 0;
    // function to insert newItem at the end of the list
    // postCondition: first points to the new list, newItem is inserted at the end of the list, last points to the last node in the list, and count is incremented by 1

  virtual void deleteNode(const Type& deleteItem) = 0;
    // function to delete deleteItem from the list
    // postCondition: if found, the node containing deleteItem is deleted from the list. first points to the first node, last points to the last node of the updated list, and count is decremented by 1

  linkedListIterator<Type> begin();
    // function to return an iterator at the beginning of the linked list
    // postCondition: returns an iterator such that current is set to first

  linkedListIterator<Type> end();
    // function to return an iterator one element past the last element of the linked list
    // postCondition: returns an iterator such that current is set to nullptr.

  linkedListType();
    // default constructor
    // postCondition: first = nullptr, last = nullptr, count = 0;

  linkedListType(const linkedListType<Type>& otherList);
    // copy constructor

  ~linkedListType();
    // destructor
    // deletes all the nodes from the list
    // postCondition: the list object is destroyed
};




template <class Type>
void linkedListType<Type>::initializeList()
{
  destroyList();
}


template <class Type>
bool linkedListType<Type>::isEmpty() const
{
  return (first == nullptr);
}


template <class Type>
linkedListType<Type>::linkedListType()
{
  first = nullptr;
  last = nullptr;
  count = 0;
}


template <class Type>
void linkedListType<Type>::destroyList()
{
  nodeType<Type> *temp;
    // pointer to deallocate the memory occupied by the node

  while (first != nullptr)
  {
    temp = first;
    first = first->link;
    delete temp;
  }
    // while there are nodes in the list, set temp to the current node, advance first to the next node, deallocate the memory occupied by temp

  last = nullptr;
    //initialize last to nullptr, first has already been set the nullptr by the while loop

  count = 0;
}


template <class Type>
void linkedListType<Type>::print() const
{
  nodeType<Type> *current;
    // pointer to traverse the list

  current = first;
    // set current so that it points to the first node

  while (current != nullptr)
  {
    cout << current->info << " ";
    current = current->link;
  }
}


template <class Type>
int linkedListType<Type>::length() const
{
  return count;
}


template <class Type>
Type linkedListType<Type>::front() const
{
  assert(first != nullptr);

  return first->info;
    // returns the info of the first node
}


template <class Type>
Type linkedListType<Type>::back() const
{
  assert(last != nullptr);

  return last->info;
    // returns the info of the last node
}


template <class Type>
linkedListIterator<Type> linkedListType<Type>::begin()
{
  linkedListIterator<Type> temp(first);

  return temp;
}


template <class Type>
linkedListIterator<Type> linkedListType<Type>::end()
{
  linkedListIterator<Type> temp(nullptr);

  return temp;
}


template <class Type>
void linkedListType<Type>::copyList(const linkedListType<Type>& otherList)
{
  nodeType<Type> *newNode;  // pointer to create a node
  nodeType<Type> *current;  // pointer to traverse the list

  if (first != nullptr)  // if the list is not empty, make it empty
  {
    destroyList();
  }

  if (otherList.first == nullptr) // otherList is empty
  {
    first = nullptr;
    last = nullptr;
    count = 0;
  }
  else
  {
    current = otherList.first;    // current points to the list ot be copied
    count = otherList.count;

      // copy the first node
    first = new nodeType<Type>;    // create the node

    first->info = current->info;  // copy the info
    first->link = nullptr;        // set the link field of the node to nullptr
    last = first;                 // make last point to the first node

    current = current->link;      // make current point to the next node

      // copy the remaining list
    while (current != nullptr)
    {
      newNode = new nodeType<Type>;     // create a node
      newNode->info = current->info;    // copy the info
      newNode->link = nullptr;          // set the link of newNode to nullptr
      last->link = newNode;             // attach newNode after last
      last = newNode;                   // make last point to the actual last node
      current = current->link;          // make current point to the next node
    }
  }
}


template <class Type>
linkedListType<Type>::linkedListType(const linkedListType<Type>& otherList)
{
  first = nullptr;
  copyList(otherList);
}


template <class Type>
const linkedListType<Type>& linkedListType<Type>::operator=(const linkedListType<Type>& otherList)
{
  if (this != &otherList) // avoid self coopy
  {
    copyList(otherList);
  }

  return *this;
}

template <class Type>
linkedListType<Type>::~linkedListType()
{
  destroyList();
}


#endif
