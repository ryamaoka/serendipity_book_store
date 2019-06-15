//File name: invmenu.cpp
//Project name: serendipity
//----------------------------------------------------------------
//creator's name and email: Ryota Yamaoka ryamaoka0@saddleback.edu
//course-section:cs 1b ticket#23650
//creation date:1/21/19
//date of last modification:5/20/19
//----------------------------------------------------------------
//purpose:create a inventory database menu
//----------------------------------------------------------------
//Algorithm:
// step 1: create a menu with the options to
//        lookUpBook, editBook, addBook, deleteBook, and to return to main menu
// step 2: read in user choice
// step 3: create a switch (choice) to go into each Function that is chosen
// step 4: create a lookUpBook FUNCTION
//         1. have user input search target
//         2. convert search target into all lowercase
//         3. convert existing bookTitle into lowercase
//         4. use find() function to look for book title or isbn number
// step 5: create addBook Function to add a book unless bookCount is > 125
// step 6: create editBook Function which calls lookUpBook so user can edit
//          each individual member variable that is chosen
// step 7: create a deleteBook Function that calls lookUpBook so user can select
//          and delete a book from the database.
//----------------------------------------------------------------
//data dictionary
//
//constants
//name      data type    initial Value
//  DBSIZE  int          125
//----------------------------------------------------------------
//variables
//
//name             data type     initial Value
// title           string        --Empty
// isbn            string        --Empty
// author          string        --Empty
// publisher       string        --Empty
// dateAdded       string        --Empty
// newTitle        string        ""
// newISBN         string        ""
// newAuthor       string        ""
// newPublisher    string        ""
// newDateAdded    string        ""
// newQuantity     string        ""
// newWholesale    string        ""
// newRetail       string        ""
// searchBook      string        not initialized
// existingTitle   string        not initialized
// existingISBN    string        not initialized
// view            char          n
// keepLooking     char          n
// saveBook        char          n
// editBook        char          n
// deleteBook      char          n
// searchSuccessfulchar          n
// choice          int           0
// bookkCount      int           0
// position        int           0
// searchIndex     int           0
// quantity        int           0
//lookUpIndex      int           -1
// wholesale       double        0.00
// retail          double        0.00
// found           bool          false
// newBook         booKType      default constructor value
// *p              bookType ptr  nullptr
// *t              bookType ptr  nullptr
// it              linkedListIterator<Type>



#include <iostream>
#include <iomanip>
#include <cctype>
#include "bookType.h"
#include "invmenu.h"
#include "bookinfo.h"
#include "linkedList.h"
#include "orderedLinkedList.h"
#include <string>

using namespace std;

const int DBSIZE = 125;



void inventoryModule(orderedLinkedList<bookType> &list0, orderedLinkedList<bookType> &list1, orderedLinkedList<bookType> &list2, orderedLinkedList<bookType> &list3)
{
  int choice = 0;
  int lookUpIndex = -1;
  bookType  *ptr = nullptr;

  do
  {
    system("clear");

    cout << "Serendipity Booksellers" << endl << endl;

    cout << "         Inventory Menu          " << endl;
    cout << "*********************************" << endl;
    cout << "* 1. Look Up a Book             *" << endl;
    cout << "* 2. Add a Book                 *" << endl;
    cout << "* 3. Edit a Book's Record       *" << endl;
    cout << "* 4. Delete a Book's Record     *" << endl;
    cout << "* 5. Return to Main Menu        *" << endl;
    cout << "*********************************" << endl;
    cout << endl;

    cout << "Enter Your Choice: ";
    cin >> choice;

    while (choice < 1 || choice > 5 || cin.fail())
    {;
      cin.clear();
      cin.ignore(1000, '\n');

      cout << "Please Enter Valid Choice: ";
      cin >> choice;
    }

    cout << endl << endl;
    cin.ignore(1000, '\n');
    cout << "Choice " << choice << " Was Selected" << endl;
    cout << "Please Press Enter To Continue.." << endl;
    cin.get();

    switch (choice)
    {
      case 1:
        ptr = lookUpBook(list0, list1, list2, list3);
        delete ptr;


        break;

      case 2:
        if (bookType::getBookCount() > DBSIZE)
        {
          cin.ignore(1000, '\n');
          cout << "Database Is Full.  Please Delete A Book Before Adding" << endl;
          cout << "Please Press Enter To Continue.." << endl;
          cin.get();
          break;
        }
        addBook(list0, list1, list2, list3);
        break;

      case 3:
        editBook(list0, list1, list2, list3);

        break;

      case 4:
        deleteBook(list0, list1, list2, list3);

        break;

      case 5:
        break;

      default:
        cout << "<something went wrong>" << endl;
        break;
    }


  } while (choice != 5);



  cin.ignore(1000, '\n');
  cout << "Return To Main Menu" << endl;
  cout << "Please Press Enter To Continue.." << endl;
  cin.get();
}


bookType* lookUpBook(orderedLinkedList<bookType> &list0, orderedLinkedList<bookType> &list1, orderedLinkedList<bookType> &list2, orderedLinkedList<bookType> &list3)
{

  bookType *t = nullptr;
  bookType *p = nullptr;
  /*
  t = new bookType;
  t->setBookTitle("C++");
  p = list0.lookUpBook(*t);
  if (p != nullptr)
    cout << *p << endl;
  else
    cout << "book not found" << endl;
*/


    string searchBook = "";
    string existingTitle = "";
    string existingISBN = "";
    bool found = false;
    size_t position = 0;
    int searchIndex = 0;
    int lookUpIndex = -1;
    char view = 'n';
    char searchSuccessful = 'n';
    linkedListIterator<bookType> it;



    system("clear");
    cout << "Look Up Book" << endl;
    cout << "Database Size: " << DBSIZE << endl;
    cout << "Book Count: " << bookType::getBookCount() << endl;
    cout << endl << endl;

    //cin.ignore(1000, '\n');

    cout << "Enter Search: ";
    getline(cin,searchBook, '\n');

  //cout << "converting searchBook string to lowerCase" << endl;
  //convert string - searchBook to lowercase
    for (int i = 0; i < searchBook.length(); i++)
    {
      if (static_cast<int>(searchBook[i]) >= 65 && static_cast<int>(searchBook[i] <= 122) && static_cast<int>(searchBook[0]) >= 65)
      {
        searchBook[i] = static_cast<char>(tolower(searchBook[i]));
      }
    }

  //cout << "Search Algorithm for linked list" << endl;
  //search algorithm for linked list
  int iteration = 0;

    for (it = list0.begin(); it != list0.end(); ++it)
    {
      //cout << "Iteration number: " << iteration << " **********************" << endl;
      //iteration++;
      (*it).setSortCode(0);
      // convert existing bookTitle to lowercase
       existingTitle = (*it).getBookTitle();
       //cout << "existing title before conversion: " << existingTitle << endl;
       for (int i = 0; i < existingTitle.length(); i++)
       {
         if (static_cast<int>(existingTitle[i] >= 65 && static_cast<int>(existingTitle[i] <= 122)))
         {
           existingTitle[i] = static_cast<char>(tolower(existingTitle[i]));
         }
       }
       //cout << "existing title after conversion: " << existingTitle << endl;
       //cout << "Retrieve isbn" << endl;
       // retrieve isbn number
       existingISBN = (*it).getISBN();
       //cout << "set existing isbn" << endl;
       //using .find function  position == string::npos if not found

       position = 0;
       position = existingTitle.find(searchBook);
       //cout << "Position: " << position << endl;
       //cout << "string::npos: " << string::npos << endl;
       //cout << "set position" << endl;

       if (position != string::npos || existingISBN == searchBook)
       {
         cout << endl;
         //cout << "inside if statement" << endl;
         cout << "Book Found: " << (*it).getBookTitle() << endl;
         cout << "View This In Book Record? (y/n): ";
         cin >> view;

         if(view == 'y' || view == 'Y')
         {
           cout << endl;
           cout << (*it) << endl << endl;
           //cout << "transactionqty: " << (*it).getTransactionQty() << endl;
         }

         cout << "Was This The Book You Were Looking For? (y/n): ";
         cin >> searchSuccessful;

         if(searchSuccessful == 'y' || searchSuccessful == 'Y')
         {
           t = new bookType;
           t->setBookTitle((*it).getBookTitle());
           t->setSortCode(0);

          // cout << "*t" << endl;
           //cout << *t << endl;
           p = list0.lookUpBook(*t);
           //cout << "*it transactionqty: " << (*it).getTransactionQty() << endl;
           p->setTransactionQty((*it).getTransactionQty());
           list0.deleteNode(*it);
           list0.insert(*p);
           //cout << "*p" << endl;
          // cout << *p << endl;
           //cout << "TransactionQty: " << p->getTransactionQty() << endl;
           delete t;
           t = nullptr;
           if (p != nullptr)
           {
            //cout << *p << endl;
            return p;
           }
           else
           {
             cout << "Null pointer was returned" << endl;
           }

           break;
         }

       }

    }

    if (searchSuccessful == 'n' || searchSuccessful == 'N')
    {
      cout << endl;
      cout << "Book was not found" << endl;
    }


    //delete p;




  cin.ignore(1000, '\n');
  cout << "Please Press Enter To Continue.." << endl;
  cin.get();

  return p;

}


void addBook(orderedLinkedList<bookType> &list0, orderedLinkedList<bookType> &list1, orderedLinkedList<bookType> &list2, orderedLinkedList<bookType> &list3)
{
  char saveBook = 'n';
  int choice = -1;
  int quantity = 0;
  double wholesale = 0.00;
  double retail = 0.00;
  string title = "--Empty";
  string isbn = "--Empty";
  string author = "--Empty";
  string publisher = "--Empty";
  string dateAdded = "--Empty";
  bookType newBook;
  bookType *temp = nullptr;  // for linked list
  do
  {
    system("clear");
    cout << "Add Book" << endl;
    cout << "Database Size: " << DBSIZE << endl;
    cout << "Book Count: " << bookType::getBookCount() << endl;

    if (bookType::getBookCount() >= DBSIZE)
    {
      cin.ignore(1000, '\n');
      cout << "Database Is Full. Please Delete A Book To Continue" << endl;
      cout << "Please Press Enter To Continue.." << endl;
      cin.get();

      return;
    }

    cout << endl << endl;
    cout << setw(50) << "Pending values" << endl;

    cout << left;
    cout << setw(35) << " 1. Enter Book Title" << "> " << title << endl;
    cout << setw(35) << " 2. Enter ISBN" << "> " << isbn << endl;
    cout << setw(35) << " 3. Enter Author" << "> " << author << endl;
    cout << setw(35) << " 4. Enter Publisher" << "> " << publisher << endl;
    cout << setw(35) << " 5. Enter Date Added (mm/dd/yyyy)" << "> " << dateAdded << endl;
    cout << setw(35) << " 6. Enter Quantity On Hand" << "> " << quantity << endl;
    cout << setw(35) << " 7. Enter Wholesale Cost" << "> " << fixed << showpoint << setprecision(2) << wholesale << endl;
    cout << setw(35) << " 8. Enter Retail Price" << "> " << fixed << showpoint << setprecision(2) << retail << endl;
    cout << setw(35) << " 9. Save Book To Database" << endl;
    cout << setw(35) << " 0. Return To Inventory Menu" << endl;
    cout << right << noshowpoint << endl;

    cout << "Enter Choice (1-9) OR (0) To Exit: ";
    cin >> choice;

    while (choice < 0 || choice > 9 || cin.fail())
    {
      cin.clear();
      cin.ignore(1000, '\n');
      cout << "Please Enter Valid Input: ";
      cin >> choice;
    }

    switch (choice)
    {
      case 1:
        cin.ignore(1000, '\n');
        cout << "Book Title: ";
        getline(cin, title, '\n');
        break;

      case 2:
        cin.ignore(1000, '\n');
        cout << "ISBN: ";
        getline(cin, isbn, '\n');
        break;

      case 3:
        cin.ignore(1000, '\n');
        cout << "Author: ";
        getline(cin, author, '\n');
        break;

      case 4:
        cin.ignore(1000, '\n');
        cout << "Publisher: ";
        getline(cin, publisher, '\n');
        break;

      case 5:
        cin.ignore(1000, '\n');
        cout << "Date Added (mm/dd/yyyy): ";
        getline(cin, dateAdded, '\n');
        break;

      case 6:
        cin.ignore(1000, '\n');
        cout << "Quantity On Hand: ";
        cin >> quantity;

        while (quantity < 0 || cin.fail())
        {
          cin.clear();
          cin.ignore(1000, '\n');
          cout << "Please Enter Valid Value: ";
          cin >> quantity;
        }
        break;

      case 7:
        cin.ignore(1000, '\n');
        cout << "Wholesale Cost: ";
        cin >> wholesale;

        while (wholesale < 0 || cin.fail())
        {
          cin.clear();
          cin.ignore(1000, '\n');
          cout << "Please Enter Valid Value: ";
          cin >> wholesale;
        }
        break;

      case 8:
        cin.ignore(1000, '\n');
        cout << "Retail Price: ";
        cin >> retail;

        while (retail < 0 || cin.fail())
        {
          cin.clear();
          cin.ignore(1000, '\n');
          cout << "Please Enter Valid Value: ";
          cin >> retail;
        }
        break;

      case 9:
        bookType::incrementBookCount();

        temp = new bookType(title, isbn, author, publisher, dateAdded, quantity, wholesale, retail);
        temp->setSortCode(0);
        list0.insert(*temp);

        temp->setSortCode(1);
        list1.insert(*temp);

        temp->setSortCode(2);
        list2.insert(*temp);

        temp->setSortCode(3);
        list3.insert(*temp);


        title = "--Empty";
        isbn = "--Empty";
        author = "--Empty";
        publisher = "--Empty";
        dateAdded = "--Empty";
        quantity = 0;
        wholesale = 0.00;
        retail = 0.00;
        break;

      case 0:
        break;

      default:
        cout << "<something went wrong>" << endl;
        break;
    }




  } while (choice != 0);
  delete temp;

/*
  cin.ignore(1000, '\n');
  cout << "Please Press Enter To Continue.." << endl;
  cin.get();
*/
}


void editBook(orderedLinkedList<bookType> &list0, orderedLinkedList<bookType> &list1, orderedLinkedList<bookType> &list2, orderedLinkedList<bookType> &list3)
{
  int choice = 0;
  int lookUpIndex = -1;
  char editBook = 'n';

  string newTitle = "";
  string newISBN = "";
  string newAuthor = "";
  string newPublisher = "";
  string newDateAdded = "";
  int newQuantity = 0;
  double newWholesale = 0;
  double newRetail = 0;
  bookType *p = nullptr;
  bookType *newBook = nullptr;
  linkedListIterator<bookType> it;

  system("clear");
  cout << "Edit A Book's Record" << endl;
  cout << "Database Size: " << DBSIZE << endl;
  cout << "Book Count: " << bookType::getBookCount() << endl;
  cout << endl << endl;

  p = lookUpBook(list0, list1, list2, list3);
  if (p == nullptr)
  {
    cout << "p is a null ptr" << endl;
    return;
  }




  cout << "Edit This Book? (y/n): ";
  cin >> editBook;

  if (editBook == 'y' || editBook == 'Y')
  {
    newBook = new bookType(*p);

    //cout << "delete for list 0" << endl;
    (*p).setSortCode(0);
    list0.deleteNode(*p);

    //cout << "delete for list 1" << endl;
    (*p).setSortCode(1);
    list1.deleteNode(*p);

    //cout << "delete for list 2" << endl;
    (*p).setSortCode(2);
    list2.deleteNode(*p);

    //cout << "delete for list 3" << endl;
    (*p).setSortCode(3);
    list3.deleteNode(*p);

    do
    {
      system("clear");

      cout << setw(45) << "Current Values" << endl;
      cout << left;
      cout << setw(35) << " 1. Edit Book Title" << "> " << newBook->getBookTitle() << endl;
      cout << setw(35) << " 2. Edit ISBN" << "> " << newBook->getISBN() << endl;
      cout << setw(35) << " 3. Edit Author" << "> " << newBook->getAuthor() << endl;
      cout << setw(35) << " 4. Edit Publisher" << "> " << newBook->getPublisher() << endl;
      cout << setw(35) << " 5. Edit Date Added" << "> " << newBook->getDateAdded() << endl;
      cout << setw(35) << " 6. Edit Quantity On Hand" << "> " << newBook->getQtyOnHand() << endl;
      cout << setw(35) << " 7. Edit Wholesale Cost" << "> " << fixed << showpoint << setprecision(2) << newBook->getWholesale() << endl;
      cout << setw(35) << " 8. Edit Retail Price" << "> " << fixed << showpoint << setprecision(2) << newBook->getRetail() << endl;
      cout << setw(35) << " 9. Return To Inventoy Menu" << endl;
      cout << right << noshowpoint << endl;
      cout << "Enter Your Choice (1-9): ";
      cin >> choice;

      while (choice < 0 || choice > 9 || cin.fail())
      {
        cin.clear();
        cin.ignore(1000, '\n');
        cout << "Please Enter Valid Value: ";
        cin >> choice;
      }

      switch (choice)
      {
        case 1:
          cin.ignore(1000, '\n');
          cout << "Book Title: ";
          getline(cin, newTitle, '\n');
          newBook->setBookTitle(newTitle);
          break;

        case 2:
          cin.ignore(1000, '\n');
          cout << "ISBN: ";
          getline(cin, newISBN, '\n');
          newBook->setISBN(newISBN);
          break;

        case 3:
          cin.ignore(1000, '\n');
          cout << "Author: ";
          getline(cin, newAuthor, '\n');
          newBook->setAuthor(newAuthor);
          break;

        case 4:
          cin.ignore(1000, '\n');
          cout << "Publisher: ";
          getline(cin, newPublisher, '\n');
          newBook->setPublisher(newPublisher);
          break;

        case 5:
          cin.ignore(1000, '\n');
          cout << "Date Added: ";
          getline(cin, newDateAdded, '\n');
          newBook->setDateAdded(newDateAdded);
          break;

        case 6:
          cin.ignore(1000, '\n');
          cout << "Quantity On Hand: ";
          cin >> newQuantity;

          while (newQuantity < 0 || cin.fail())
          {
            cin.clear();
            cin.ignore(1000, '\n');
            cout << "Please Enter Valid Value: ";
            cin >> newQuantity;
          }
          newBook->setQtyOnHand(newQuantity);
          break;

        case 7:
          cin.ignore(1000, '\n');
          cout << "Wholesale Cost: ";
          cin >> newWholesale;

          while (newWholesale < 0 || cin.fail())
          {
            cin.clear();
            cin.ignore(1000, '\n');
            cout << "Please Enter Vavlid Value: ";
            cin >> newWholesale;
          }
          newBook->setWholesale(newWholesale);
          break;

        case 8:
          cin.ignore(1000, '\n');
          cout << "Retail Price: ";
          cin >> newRetail;

          while (newRetail < 0 || cin.fail())
          {
            cin.clear();
            cin.ignore(1000, '\n');
            cout << "Please Enter Valid Value: ";
            cin >> newRetail;
          }
          newBook->setRetail(newRetail);
          break;

        case 9:

          cout << *newBook << endl;



          newBook->setSortCode(0);
          list0.insert(*newBook);

          newBook->setSortCode(1);
          list1.insert(*newBook);

          newBook->setSortCode(2);
          list2.insert(*newBook);

          newBook->setSortCode(3);
          list3.insert(*newBook);
          break;

        default:
          cout << "<something went wrong> " << endl;
          break;
      }






    } while (choice != 9);
  }

  delete newBook;
  newBook = nullptr;
  delete p;
  p = nullptr;
/*
  cin.ignore(1000, '\n');
  cout << "Please Press Enter To Continue.." << endl;
  cin.get();
*/
}


void deleteBook(orderedLinkedList<bookType> &list0, orderedLinkedList<bookType> &list1, orderedLinkedList<bookType> &list2, orderedLinkedList<bookType> &list3)
{
  int lookUpIndex = -1;
  char deleteBook = 'n';
  bookType bookToDelete;
  bookType *p = nullptr;
  linkedListIterator<bookType> it;

  system("clear");
  cout << "Delete A Book's Record" << endl;
  cout << "Database Size: " << DBSIZE << endl;
  cout << "Book Count: " << bookType::getBookCount() << endl;
  cout << endl << endl;

  p = lookUpBook(list0, list1, list2, list3);
  if (p == nullptr)
  {
    return;
  }

  cout << *p << endl;
  cout << "Delete This Book? (y/n): ";
  cin >> deleteBook;



  if (deleteBook == 'y' || deleteBook == 'Y')
  {
    //cout << "*****************delete for list 0***************************" << endl;
    //cout << "******************* print list 0 ******************************************" << endl;
    //for (it = list0.begin(); it != list0.end(); ++it)
    //{
      //cout << *it << endl;
    //}
    //cout << "*********************************************************************************************************" << endl;
    (*p).setSortCode(0);
    //cout << "sort code: " << p->getSortCode() << endl;
    list0.deleteNode(*p);

    //cout << "*****************delete for list 1***************************" << endl;
    (*p).setSortCode(1);
    //cout << "sort code: " << p->getSortCode() << endl;
    list1.deleteNode(*p);

    //cout << "*****************delete for list 2***************************" << endl;
    (*p).setSortCode(2);
    //cout << "sort code: " << p->getSortCode() << endl;
    list2.deleteNode(*p);

    //cout << "*****************delete for list 3***************************" << endl;
    (*p).setSortCode(3);
    //cout << "sort code: " << p->getSortCode() << endl;
    list3.deleteNode(*p);

    //cout << "delete p" << endl;
    delete p;
    p = nullptr;




    cout << "Book Deleted" << endl;



    bookType::decrementBookCount();
  }



  cin.ignore(1000, '\n');
  cout << "Please Press Enter To Continue.." << endl;
  cin.get();

}
