#ifndef BOOKTYPE_H
#define BOOKTYPE_H

#include <string>
#include "linkedList.h"
#include "orderedLinkedList.h"
using namespace std;

class bookType
{
private:
  static int bookCount;
  string bookTitle;
  string isbn;
  string author;
  string publisher;
  string dateAdded;
  int qtyOnHand;
  double wholesale;
  double retail;
  int sortCode;              // sort code: 0 = sort by title, 1 = sort by qty on hand, 2 = wholesale, 3 = date added
  int transactionQty;       // stores quantity to purchase for cashier module
  double transactionTotal;  // stores the price for cashier transaction of quantity to be purchased * retail price

  friend ostream& operator<< (ostream& osObject, const bookType& book);
public:
//******************** overload operators ********************
  bool operator== (const bookType& otherBook) const;
  bool operator!= (const bookType& otherBook) const;
  bool operator>= (const bookType& otherBook) const;


//******************** setters ********************
  void setBookTitle(string newTitle);
  void setISBN(string newISBN);
  void setAuthor(string newAuthor);
  void setPublisher(string newPublisher);
  void setDateAdded(string newDateAdded);
  void setQtyOnHand(int newQuantity);
  void setWholesale(double newWholesale);
  void setRetail(double newRetail);
  void setAll(string newTitle, string newISBN, string newAuthor, string newPublisher, string newDateAdded, int newQuantity, double newWholesale, double newRetail);
  void setSortCode(int sortNum);
  void setTransactionQty(int num);
  void setTransactionTotal(double total);
//******************** getters ********************
  string getBookTitle() const;
  string getISBN() const;
  string getAuthor() const;
  string getPublisher() const;
  string getDateAdded() const;
  int getQtyOnHand() const;
  double getWholesale() const;
  double getRetail() const;
  int getSortCode() const;
  int getTransactionQty() const;
  double getTransactionTotal() const;


  static int getBookCount();
  static void incrementBookCount();
  static void decrementBookCount();

  void print() const;
  bool equals(bookType other) const;

  bookType();
  bookType(string t, string i, string a, string p, string d, int q, double w, double r);
  bookType(const bookType& otherBook);
  ~bookType();

};


#endif
