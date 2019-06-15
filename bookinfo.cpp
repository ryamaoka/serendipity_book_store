//File name: bookinfo.cpp
//Project name: serendipity
//----------------------------------------------------------------
//creator's name and email: Ryota Yamaoka ryamaoka0@saddleback.edu
//course-section:cs 1b ticket#23650
//creation date:1/21/19
//date of last modification:5/20/19
//----------------------------------------------------------------
//purpose:to display the title, author, isbn, publisher, date added,
//          quantity available, wholesale cost, and retail price of a
//          given book.
//----------------------------------------------------------------
//Algorithm:
// step 1: pass in the bookType object into this function as a parameter
// step 2: display the information of the book by using the getters
//         created for each member variable.
//----------------------------------------------------------------
//data dictionary
//
//constants
//name               data type    initial Value
//
//----------------------------------------------------------------
//variables
//
//name               data type     initial Value
// bookInfo          bookType

#include <iostream>
#include <iomanip>
#include "bookinfo.h"
using namespace std;

void bookinformation(const bookType bookInfo)
{
  system("clear");

  cout << "Serendipity Booksellers" << endl;
  cout << "Book Information" << endl << endl;
  cout << endl << endl;

  cout << left;
  cout << setw(20) << "ISBN: " << bookInfo.getISBN() << endl;
  cout << setw(20) << "Title: " << bookInfo.getBookTitle() << endl;
  cout << setw(20) << "Author: " << bookInfo.getAuthor() << endl;
  cout << setw(20) << "Publisher: " << bookInfo.getPublisher() << endl;
  cout << setw(20) << "Date Added: " << bookInfo.getDateAdded() << endl;
  cout << setw(20) << "Quantity On Hand: " << bookInfo.getQtyOnHand() << endl;
  cout << setw(20) << "Wholesale Cost: " << bookInfo.getWholesale() << endl;
  cout << setw(20) << "Retail Price: " << bookInfo.getRetail() << endl;
  cout << endl;

  cout << "Please Press Enter To Continue.." << endl;
  cin.get();
}
