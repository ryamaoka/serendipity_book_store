//File name: bookType.cpp
//Project name: serendipity
//----------------------------------------------------------------
//creator's name and email: Ryota Yamaoka ryamaoka0@saddleback.edu
//course-section:cs 1b ticket#23650
//creation date:1/21/19
//date of last modification:5/20/19
//----------------------------------------------------------------
//purpose: to define the functions for bookType class
//----------------------------------------------------------------
//Algorithm:
// step 1: create constructors, default, and with parameters
// step 2: initialize static variable bookCount and getter and increment function
// step 3: create setters
// step 4: create getters
// step 5: create print and equals function
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
// bookCount        int           0
// found            bool          false
// title1           string        this->getBookTitle()
// title2           string        otherBook.getBookTitle()
// qty1             int           this->getQtyOnHand()
// qty2             int           otherBook.getQtyOnHand()
// price1           double        this->getWholesale()
// price2           doouble       otherBook.getWholesale()
// date1            string        this->getDateAdded()
// date2            string        otherBook.getDateAdded()
// date1AsInt       int           0
// date2AsInt       int           0



#include <iostream>
#include <string>
#include <stdlib.h>
#include "bookType.h"
#include "bookinfo.h"

using namespace std;

//*********************************************** static ****************************************************************************

int bookType::bookCount = 0;


//Function Name: getBookCount
//Purpose: get the value of static variable bookCount
//Input: nothing
//Output: int bookCount
int bookType::getBookCount()
{
  return bookType::bookCount;
}

//Function Name: incrementBookCount
//Purpose: increment the value of bookCount by 1
//Input: nothing
//Output: nothing
void bookType::incrementBookCount()
{
  bookType::bookCount++;
}

//Function Name: decrementBookCount
//Purpose: decrement the value of bookCount by 1
//Input: nothing
//Output: nothing
void bookType::decrementBookCount()
{
  bookType::bookCount--;
}

//*********************************************** constructors **********************************************************************

//Function name: bookType()
//Purpose: constructor to create and set initial value for object of class bookType
// Receives: nothing
// Returns: nothing
bookType::bookType()
{
  setAll("Not Set", "Not Set", "Not Set", "Not Set", "Not Set", 0, 0, 0);
  setSortCode(0);
  setTransactionQty(0);
  setTransactionTotal(0);
}

//Function name: bookType(string t, string i, string a, string p, string d, int q, double w, double r)
//Purpose: constructor with parameters
// Receives: book title, isbn, author, publisher, date added, qty on hand, wholesale, and retail
// Returns: nothing
bookType::bookType(string t, string i, string a, string p, string d, int q, double w, double r)
{
  setAll(t, i, a, p, d, q, w, r);
  setSortCode(0);
  setTransactionQty(0);
  setTransactionTotal(0);
}

//Function name: bookType(const bookType& otherBook)
//Purpose: copy constructor
// Receives: bookTitle, isbn, author, publisher, dateAdded, qtyOnHand, wholesale, retail
// Returns: nothing

bookType::bookType(const bookType& otherBook)
{
  setAll(otherBook.getBookTitle(), otherBook.getISBN(), otherBook.getAuthor(), otherBook.getPublisher(), otherBook.getDateAdded(), otherBook.getQtyOnHand(), otherBook.getWholesale(), otherBook.getRetail());
  setSortCode(0);
  setTransactionQty(otherBook.getTransactionQty());
  setTransactionTotal(otherBook.getTransactionTotal());
}


//*********************************************** destructors ***********************************************************************

//Function name: ~bookType()
//Purpose: destructor for object of class bookType
// Receives: nothing
// Returns: nothing
bookType::~bookType()
{

  //cout << "Object Going Out Of Scope" << endl;


}

//********************************************** setters *****************************************************************************
//Function name: setBookTitle
//Purpose: set the value of bookTitle member variable of class bookType
// Receives: string
// Returns: nothing
void bookType::setBookTitle(string newTitle)
{
  bookTitle = newTitle;
}

//Function name: setISBN
//Purpose: set the value of isbn member variable of class bookType
// Receives: string
// Returns: nothing
void bookType::setISBN(string newISBN)
{
  isbn = newISBN;
}

//Function name: setAuthor
//Purpose: set the value of author memebr variable of class bookType
// Receives: string
// Returns: nothing
void bookType::setAuthor(string newAuthor)
{
  author = newAuthor;
}

//Function name: setPublisher
//Purpose: set the value of publisher member variable of class bookType
// Receives: string
// Returns: nothing
void bookType::setPublisher(string newPublisher)
{
  publisher = newPublisher;
}

//Function name: setDateAdded
//Purpose: set the value of dateAdded member variable of class bookType
// Receives: string
// Returns: nothing
void bookType::setDateAdded(string newDateAdded)
{
  dateAdded = newDateAdded;
}

//Function name: setQtyOnHand
//Purpose: set the value of qtyOnHand memeber variable of class bookType
// Receives: int
// Returns: nothing
void bookType::setQtyOnHand(int newQuantity)
{
  qtyOnHand = newQuantity;
}

//Function name: setWholesale
//Purpose: set the value of wholesale member variable of class bookType
// Receives: double
// Returns: nothing
void bookType::setWholesale(double newWholesale)
{
  wholesale = newWholesale;
}

//Function name: setRetail
//Purpose: set the value of retail member variable of class bookType
// Receives: double
// Returns: nothing
void bookType::setRetail(double newRetail)
{
  retail = newRetail;
}

//Function name: setAll
//Purpose: sets all of the value of the member variable of class bookType
// Receives: string, string, string, string, string, int, double, double
// Returns: nothing
void bookType::setAll(string newTitle, string newISBN, string newAuthor, string newPublisher, string newDateAdded, int newQuantity, double newWholesale, double newRetail)
{
  bookTitle = newTitle;
  isbn = newISBN;
  author = newAuthor;
  publisher = newPublisher;
  dateAdded = newDateAdded;
  qtyOnHand = newQuantity;
  wholesale = newWholesale;
  retail = newRetail;
  sortCode = 0;
  transactionQty = 0;
}

//Function: setSortCode
//Purpose: set the value of sort code - value to determine what to sort by
//Receives: int
// Returns: nothing
void bookType::setSortCode(int sortNum)
{
  sortCode = sortNum;
}

//Function: setTransactionQty
//Purpose: sets the value of transactionQty- number of the book to be purchased
//Receives: int number of books
// Returns: nothing

void bookType::setTransactionQty(int num)
{
  transactionQty = num;
}

//Function: setTransactionTotal
//Purpose: sets the value of price * quantity to be purchased
//Receives: double
// Returns: nothing

void bookType::setTransactionTotal(double total)
{
  transactionTotal = total;
}
//******************************************************** getters ******************************************************************

//Function name: getBookTitle
//Purpose: return the value of bookTitle of class bookType
// Receives:nothing
// Returns: string
string bookType::getBookTitle() const
{
  return bookTitle;
}

//Function name: getISBN
//Purpose: return the value of isbn of class bookType
// Receives:nothing
// Returns: string
string bookType::getISBN() const
{
  return isbn;
}

//Function name: getAuthor
//Purpose: return the value of author of class bookType
// Receives: nothing
// Returns: string
string bookType::getAuthor() const
{
  return author;
}

//Function name: getPublisher
//Purpose: return the value of publisher of class bookType
// Receives: nothing
// Returns: string
string bookType::getPublisher() const
{
  return publisher;
}

//Function name: getDateAdded
//Purpose: return the value of dateAdded of class bookType
// Receives: nothing
// Returns: string
string bookType::getDateAdded() const
{
  return dateAdded;
}

//Function name: getQtyOnHand
//Purpose: return the value of qtyOnHand of class bookType
// Receives: nothing
// Returns: int
int bookType::getQtyOnHand() const
{
  return qtyOnHand;
}

//Function name: getWholesale
//Purpose: return the value of wholesale of class bookType
// Receives: nothing
// Returns: double
double bookType::getWholesale() const
{
  return wholesale;
}

//Function name: getRetail
//Purpose: return the value of retail of class bookType
// Receives: nothing
// Returns: double
double bookType::getRetail() const
{
  return retail;
}

//Function: getSortCode
//Purpose: returns the value of sort code
//Receives: nothing
// Returns: int sortCode
int bookType::getSortCode() const
{
  return sortCode;
}

//Function: getTransactionQty
//Purpose: returns the value of quantity to be purchased
//Receives: nothing
// Returns: int sortCode
int bookType::getTransactionQty() const
{
  return transactionQty;
}

//Function: getTransactionTotal
//Purpose: returns the value of total of price * quantity
//Receives: nothing
// Returns: int sortCode
double bookType::getTransactionTotal() const
{
  return transactionTotal;
}
//******************************************************* print and equals *********************************************************

//Function name:print
//Purpose: display all the values of the member variables of class bookType
// Receives: nothing
// Returns: nothing
void bookType::print() const
{

  cout << endl;
  cout << "Book Title: " << bookTitle << endl;
  cout << "ISBN: " << isbn << endl;
  cout << "Author: " << author << endl;
  cout << "Publisher: " << publisher << endl;
  cout << "Date Added: " << dateAdded << endl;
  cout << "Quantity On Hand: " << qtyOnHand << endl;
  cout << "Wholesale Cost: " << wholesale << endl;
  cout << "Retail Price: " << retail << endl;
  cout << endl;

}

//Function name: equals
//Purpose: checks if the objects are the same
// Receives: nothing
// Returns: boolean
bool bookType::equals(bookType other) const
{
  if (other.bookTitle == bookTitle && other.isbn == isbn && other.author == author &&
      other.publisher == publisher && other.dateAdded == dateAdded &&
      other.qtyOnHand == qtyOnHand && other.wholesale == wholesale && other.retail == retail)
  {
    return true;
  }

  else
  {
    return false;
  }
}

//************************************************** overload operators **************************************************
bool bookType::operator== (const bookType& otherBook) const
{


  bool found = false;
  string title1 = this->getBookTitle();
  string title2 = otherBook.getBookTitle();
  int qty1 = this->getQtyOnHand();
  int qty2 = otherBook.getQtyOnHand();
  double price1 = this->getWholesale();
  double price2 = otherBook.getWholesale();
  string date1 = this->getDateAdded();
  string date2 = otherBook.getDateAdded();
  int date1AsInt = 0;
  int date2AsInt = 0;

  //if (this != &otherBook)   //avoid self evaluation
//  {
    switch (otherBook.sortCode)
    {
      case 0:         // check equality by title
        //cout << "title1: " << title1 << endl;
        //cout << "title2: " << title2 << endl;
        if ((title1.compare(title2) == 0))
        {
          //cout << "****************************Book Found****************************" << endl;
          found = true;
        }
        break;

      case 1:         // check equality by Qty on Hand
        //cout << "title1: " << title1 << endl;
        //cout << "title2: " << title2 << endl;
        if ((qty1 == qty2) && (title1.compare(title2)== 0))
        {
          //cout << "****************************Book Found****************************" << endl;
          found = true;
        }
        break;

      case 2:         // check equality by Wholesale price
        //cout << "title1: " << title1 << endl;
        //cout << "title2: " << title2 << endl;
        if ((price1 == price2) && (title1.compare(title2) == 0))
        {
          //cout << "****************************Book Found****************************" << endl;
          found = true;
        }
        break;

      case 3:         // check equality by Date Added
        //cout << "title1: " << title1 << endl;
        //cout << "title2: " << title2 << endl;
        if ((date1 == date2) && (title1.compare(title2) == 0))
        {
            //cout << "****************************Book Found****************************" << endl;
          found = true;
        }
        break;

      default:
        cout << "Something went wrong" << endl;
        break;
    }
  //}

  return found;
}

bool bookType::operator!= (const bookType& otherBook) const
{
  bool notFound = false;
  string title1 = this->getBookTitle();
  string title2 = otherBook.getBookTitle();
  int qty1 = this->getQtyOnHand();
  int qty2 = otherBook.getQtyOnHand();
  double price1 = this->getWholesale();
  double price2 = otherBook.getWholesale();
  string date1 = this->getDateAdded();
  string date2 = otherBook.getDateAdded();
  int date1AsInt = 0;
  int date2AsInt = 0;


    switch (otherBook.sortCode)
    {
      case 0:         // check equality by title
        if ((title1.compare(title2) != 0))
        {
          notFound = true;
        }
        break;

      case 1:         // check equality by Qty on Hand
        if ((qty1 != qty2) && (title1.compare(title2)!= 0))
        {
          notFound = true;
        }
        break;

      case 2:         // check equality by Wholesale price
        if ((price1 != price2) && (title1.compare(title2) != 0))
        {
          notFound = true;
        }
        break;

      case 3:         // check equality by Date Added
        if ((date1 != date2) && (title1.compare(title2) != 0))
        {
          notFound = true;
        }
        break;

      default:
        cout << "Something went wrong" << endl;
        break;
    }

  return notFound;
}

bool bookType::operator>= (const bookType& otherBook) const
{
  bool greaterThan = false;
  string title1 = this->getBookTitle();
  string title2 = otherBook.getBookTitle();
  int qty1 = this->getQtyOnHand();
  int qty2 = otherBook.getQtyOnHand();
  double price1 = this->getWholesale();
  double price2 = otherBook.getWholesale();
  string date1 = this->getDateAdded();
  string date2 = otherBook.getDateAdded();
  int date1AsInt = 0;
  int date2AsInt = 0;


    switch (otherBook.sortCode)
    {
      case 0:         // sort by title
        if (title1.compare(title2) >= 0)
        {
          greaterThan = true;
        }
        break;

      case 1:         // sort by Qty on Hand in descending order- greatest quality listed first
        if (qty1 <= qty2)
        {
          greaterThan = true;
        }
        break;

      case 2:         // sort by Wholesale price in descending order - greatest unit cost listed first
        if (price1 <= price2)
        {
          greaterThan = true;
        }
        break;

      case 3:         // sort by Date Added in descending order - books in inventory the longest listed first

        date1 = this->getDateAdded().substr(6, 4);    //retrieve substring of date
        date1AsInt = atoi(date1.c_str());               // atoi converts cstring to integer.ascii to int

        date2 = otherBook.getDateAdded().substr(6,4);
        date2AsInt = atoi(date2.c_str());

        if (date1AsInt > date2AsInt)      // checks by year
        {
          greaterThan = true;
        }
        else
        {
          if (date1AsInt == date2AsInt)
          {
            date1 = this->getDateAdded().substr(0, 2);
            date1AsInt = atoi(date1.c_str());

            date2 = otherBook.getDateAdded().substr(0, 2);
            date2AsInt = atoi(date2.c_str());

            if (date1AsInt > date2AsInt)    // checks by month
            {
              greaterThan = true;
            }
            else
            {
              if (date1AsInt == date2AsInt)
              {
                date1 = this->getDateAdded().substr(3, 2);
                date1AsInt = atoi(date1.c_str());

                date2 = otherBook.getDateAdded().substr(3, 2);
                date2AsInt = atoi(date2.c_str());

                if (date1AsInt > date2AsInt)        // checks by day
                {
                  greaterThan = true;
                }
              }
            }
          }
        }
        break;

      default:
        cout << "Something went wrong" << endl;
        break;
    }

  return greaterThan;
}


ostream& operator<< (ostream& osObject, const bookType& book)
{
  osObject << "Book Title: " << book.bookTitle << endl;
  osObject << "ISBN: " << book.isbn << endl;
  osObject << "Author: " << book.author << endl;
  osObject << "Publisher: " << book.publisher << endl;
  osObject << "Date Added: " << book.dateAdded << endl;
  osObject << "Quantity On Hand: " << book.qtyOnHand << endl;
  osObject << "Wholesale Cost: " << book.wholesale << endl;
  osObject << "Retail Price: " << book.retail << endl;

  return osObject;
}
