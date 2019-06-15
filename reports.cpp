//File name: reports.cpp
//Project name: serendipity
//----------------------------------------------------------------
//creator's name and email: Ryota Yamaoka ryamaoka0@saddleback.edu
//course-section:cs 1b ticket#23650
//creation date:1/21/19
//date of last modification:5/20/19
//----------------------------------------------------------------
//purpose:create a menu for reports module functions
//----------------------------------------------------------------
//Algorithm:
// step 1: create a menu for inventory listing, inventory wholesale value,
//          inventory retail value, listing by quantity, listing by cost,
//          listing by age,
// step 2: read in user choice selection
// step 3: create a switch (choice) for each choice and functions
// step 4: create report listing function to show all the data of a book
// step 5: create wholesale function to show the wholesale cost and total wholesale in current inventory
// step 6: create retial function to show the retail cost and total retail value in current inventory
// step 7: create repQty to sort the books by quantity in hand by greatest to least
// step 8: create repCost to sort the books by wholesale cost by most expensive to least
// step 9: create repAge to sort the books by the date added to inventory by oldest to new
//----------------------------------------------------------------
//data dictionary
//
//constants
//name     data type    initial Value
// DBSIZE  int          125
//----------------------------------------------------------------
//variables
//
//name         data type     initial Value
// choice       int           0
// pageNumber   int           0
// it           linkedListIterator<bookType>
// totalWholeSaleValue double 0
// totalRetailValue    double 0


#include <iostream>
#include <iomanip>
#include <string>
#include <ctime>
#include "bookType.h"
#include "reports.h"
#include "linkedList.h"
#include "orderedLinkedList.h"

using namespace std;

const int DBSIZE = 125;
void reportsModule(orderedLinkedList<bookType> &list0, orderedLinkedList<bookType> &list1, orderedLinkedList<bookType> &list2, orderedLinkedList<bookType> &list3)
{
  int choice = 0;


  do
  {
    system("clear");

    cout << "Serendipity Booksellers" << endl << endl;

    cout << "           Reports Module            " << endl;
    cout << "*************************************" << endl;
    cout << "* 1. Inventory Listing              *" << endl;
    cout << "* 2. Inventory Wholesale Value      *" << endl;
    cout << "* 3. Inventory Retail Value         *" << endl;
    cout << "* 4. Listing By Quantity            *" << endl;
    cout << "* 5. Listing By Cost                *" << endl;
    cout << "* 6. Listing By Age                 *" << endl;
    cout << "* 7. Return To Main Menu            *" << endl;
    cout << "*************************************" << endl;
    cout << endl;

    cout  << "Enter Your Choice: ";
    cin >> choice;

    while (choice < 0 || choice > 7 || cin.fail())
    {
      cin.clear();
      cin.ignore(1000, '\n');
      cout << "Please Enter Valid Choice: ";
      cin >> choice;
    }

    cout <<  "Choice: " << choice << " Was Selected" << endl;
    cout << "Please Press Enter To Continue.." << endl;
    cin.ignore(1000, '\n');
    cin.get();

    switch (choice)
    {
      case 1:
        repListing(list0, list1, list2, list3);
        break;

      case 2:
        repWholesale(list0, list1, list2, list3);
        break;

      case 3:
        repRetail(list0, list1, list2, list3);
        break;

      case 4:
        repQty(list0, list1, list2, list3);
        break;

      case 5:
        repCost(list0, list1, list2, list3);
        break;

      case 6:
        repAge(list0, list1, list2, list3);
        break;

      case 7:
        break;

      default:
        cout << "<something went wrong>" << endl;
        break;
    }




  } while (choice != 7);


  cin.ignore(1000, '\n');
  cout << "Return To Main Menu" << endl;
  cout << "Please Press Enter To Continue.." << endl;
  cin.get();
}

void repListing(orderedLinkedList<bookType> &list0, orderedLinkedList<bookType> &list1, orderedLinkedList<bookType> &list2, orderedLinkedList<bookType> &list3)
{
  linkedListIterator<bookType> it;
  int pageNumber = 0;
  int counter = 0;
  time_t now = time(0);
  char*dt = ctime(&now);


  system("clear");
  cout << "Inventory Listing" << endl;
  cout << "Date and Time: " << dt << endl;
  cout << "Database Size: " << DBSIZE << endl;
  cout << "Book Count: " << bookType::getBookCount() << endl;
  cout << "Page " << pageNumber << endl;
  cout << endl << endl;


  cout << left;
  cout << setw(40) << "Title";
  cout << setw(15) << "ISBN";
  cout << setw(35) << "Author";
  cout << setw(30) << "Publisher";
  cout << setw(15) << "Date Added";
  cout << right;
  cout << setw(15) << "Qty on Hand";
  cout << setw(20) << "Wholesale Cost($)";
  cout << setw(20) << "Retail Price($)";
  cout << endl;
  cout << right;


  cout << setw(195) << setfill('-') << "-" << endl;
  cout << setfill(' ');


  for (it = list0.begin(); it != list0.end(); ++it)
  {
    if (0 == counter%20)
    {

      system("clear");
      pageNumber++;
      cout << "Inventory Listing" << endl;
      cout << "Date and Time: " << dt << endl;
      cout << "Database Size: " << DBSIZE << endl;
      cout << "Book Count: " << bookType::getBookCount() << endl;
      cout << "Page " << pageNumber << endl;
      cout << endl << endl;
      cout << left;
      cout << setw(40) << "Title";
      cout << setw(15) << "ISBN";
      cout << setw(35) << "Author";
      cout << setw(30) << "Publisher";
      cout << setw(15) << "Date Added";
      cout << right;
      cout << setw(15) << "Qty on Hand";
      cout << setw(20) << "Wholesale Cost($)";
      cout << setw(20) << "Retail Price($)";
      cout << endl;
      cout << right;

      cout << setw(195) << setfill('-') << "-" << endl;
      cout << setfill(' ');
    }
    cout << left;
    cout << setw(40) << (*it).getBookTitle().substr(0, 35);
    cout << setw(15) << (*it).getISBN();
    cout << setw(35) << (*it).getAuthor().substr(0, 25);
    cout << setw(30) << (*it).getPublisher();
    cout << setw(15) << (*it).getDateAdded();
    cout << right;
    cout << setw(15) << (*it).getQtyOnHand();
    cout << setw(20) << (*it).getWholesale();
    cout << setw(20) << (*it).getRetail();
    cout << endl;

    if (19 == counter%20)
    {
      cout << endl;
      cout << "Press Enter To Continue.." << endl;
      cin.get();
    }
    counter++;
  }


  cin.ignore(1000, '\n');
  cout << "Return To Inventory Menu" << endl;
  cin.get();
}

void repWholesale(orderedLinkedList<bookType> &list0, orderedLinkedList<bookType> &list1, orderedLinkedList<bookType> &list2, orderedLinkedList<bookType> &list3)
{
  linkedListIterator<bookType> it;
  int pageNumber = 0;
  int counter = 0;
  double totalWholeSaleValue = 0;
  time_t now = time(0);
  char*dt = ctime(&now);

  system("clear");
  cout << "Inventory Wholesale Value" << endl;
  cout << "Date and Time: " << dt << endl;
  cout << "Database Size: " << DBSIZE << endl;
  cout << "Book Count: " << bookType::getBookCount() << endl;
  cout << "Page " << pageNumber << endl;
  cout << endl << endl;

  cout << left;
  cout << setw(40) << "Title";
  cout << setw(15) << "ISBN";
  cout << right;
  cout << setw(15) << "Qty on Hand";
  cout << setw(25) << "Wholesale Cost($)";
  cout << endl;
  cout << right;


  cout << setw(100) << setfill('-') << "-" << endl;
  cout << setfill(' ');


  for (it = list0.begin(); it != list0.end(); ++it)
  {
    if (0 == counter%20)
    {

      system("clear");
      pageNumber++;
      cout << "Inventory Wholesale Value" << endl;
      cout << "Date and Time: " << dt << endl;
      cout << "Database Size: " << DBSIZE << endl;
      cout << "Book Count: " << bookType::getBookCount() << endl;
      cout << "Page " << pageNumber << endl;
      cout << endl << endl;
      cout << left;
      cout << setw(40) << "Title";
      cout << setw(15) << "ISBN";
      cout << right;
      cout << setw(15) << "Qty on Hand";
      cout << setw(25) << "Wholesale Cost($)";
      cout << endl;


      cout << setw(100) << setfill('-') << "-" << endl;
      cout << setfill(' ');
    }
    cout << left;
    cout << setw(40) << (*it).getBookTitle().substr(0, 35);
    cout << setw(15) << (*it).getISBN();
    cout << right;
    cout << setw(15) << (*it).getQtyOnHand();
    cout << setw(25) << (*it).getWholesale();
    cout << endl;

    totalWholeSaleValue = totalWholeSaleValue + ((*it).getQtyOnHand() * (*it).getWholesale());

    if (19 == counter%20)
    {
      cout << endl;
      cout << "Press Enter To Continue.." << endl;
      cin.get();
    }
    counter++;
  }
  cout << endl << endl;
  cout << fixed << showpoint << setprecision(2);
  cout << "Total Wholesale Value: $ " << totalWholeSaleValue << endl << endl;

  cout << "Return To Inventory Menu" << endl;
  cin.get();
}

void repRetail(orderedLinkedList<bookType> &list0, orderedLinkedList<bookType> &list1, orderedLinkedList<bookType> &list2, orderedLinkedList<bookType> &list3)
{
  linkedListIterator<bookType> it;
  int pageNumber = 0;
  int counter = 0;
  double totalRetailValue = 0;
  time_t now = time(0);
  char*dt = ctime(&now);

  system("clear");
  cout << "Inventory Retail Value" << endl;
  cout << "Date and Time: " << dt << endl;
  cout << "Database Size: " << DBSIZE << endl;
  cout << "Book Count: " << bookType::getBookCount() << endl;
  cout << "Page " << pageNumber << endl;
  cout << endl << endl;
  cout << left;
  cout << setw(40) << "Title";
  cout << setw(15) << "ISBN";
  cout << right;
  cout << setw(15) << "Qty on Hand";
  cout << setw(25) << "Retail Price($)";
  cout << endl;
  cout << right;


  cout << setw(100) << setfill('-') << "-" << endl;
  cout << setfill(' ');


  for (it = list0.begin(); it != list0.end(); ++it)
  {
    if (0 == counter%20)
    {

      system("clear");
      pageNumber++;
      cout << "Inventory Retail Value" << endl;
      cout << "Date and Time: " << dt << endl;
      cout << "Database Size: " << DBSIZE << endl;
      cout << "Book Count: " << bookType::getBookCount() << endl;
      cout << "Page " << pageNumber << endl;
      cout << endl << endl;
      cout << left;
      cout << setw(40) << "Title";
      cout << setw(15) << "ISBN";
      cout << right;
      cout << setw(15) << "Qty on Hand";
      cout << setw(25) << "Retail Price($)";
      cout << endl;
      cout << right;

      cout << setw(100) << setfill('-') << "-" << endl;
      cout << setfill(' ');
    }

    cout << left;
    cout << setw(40) << (*it).getBookTitle().substr(0, 35);
    cout << setw(15) << (*it).getISBN();
    cout << right;
    cout << setw(15) << (*it).getQtyOnHand();
    cout << setw(25) << (*it).getRetail();
    cout << endl;

    totalRetailValue = totalRetailValue + ((*it).getQtyOnHand() * (*it).getRetail());
    if (19 == counter%20)
    {
      cout << endl;
      cout << "Press Enter To Continue.." << endl;
      cin.get();
    }
    counter++;
  }

  cout << endl << endl;
  cout << "Total Retail Value: $" << totalRetailValue << endl << endl;

  cout << "Return To Inventory Menu" << endl;
  cin.get();
}

void repQty(orderedLinkedList<bookType> &list0, orderedLinkedList<bookType> &list1, orderedLinkedList<bookType> &list2, orderedLinkedList<bookType> &list3)
{
  linkedListIterator<bookType> it;
  int pageNumber = 0;
  int counter = 0;
  time_t now = time(0);
  char*dt = ctime(&now);

  system("clear");
  cout << "Listing By Quantity" << endl;
  cout << "Date and Time: " << dt << endl;
  cout << "Database Size: " << DBSIZE << endl;
  cout << "Book Count: " << bookType::getBookCount() << endl;
  cout << "Page " << pageNumber << endl;
  cout << endl << endl;

  cout << left;
  cout << setw(90) << "Title";
  cout << setw(20) << "ISBN";
  cout << right;
  cout << setw(15) << "Qty on Hand";
  cout << endl;



  cout << setw(150) << setfill('-') << "-" << endl;
  cout << setfill(' ');


  for (it = list1.begin(); it != list1.end(); ++it)
  {
    if (0 == counter%20)
    {
      system("clear");
      pageNumber++;
      cout << "Listing By Quantity" << endl;
      cout << "Date and Time: " << dt << endl;
      cout << "Database Size: " << DBSIZE << endl;
      cout << "Book Count: " << bookType::getBookCount() << endl;
      cout << "Page " << pageNumber << endl;
      cout << endl << endl;

      cout << left;
      cout << setw(90) << "Title";
      cout << setw(20) << "ISBN";
      cout << right;
      cout << setw(15) << "Qty on Hand";
      cout << endl;



      cout << setw(150) << setfill('-') << "-" << endl;
      cout << setfill(' ');
    }


    cout << left;
    cout << setw(90) << (*it).getBookTitle();
    cout << setw(20) << (*it).getISBN();
    cout << right;
    cout << setw(15) << (*it).getQtyOnHand() << endl;


    if (19 == counter%20)
    {
      cout << endl;
      cout << "Press Enter To Continue.." << endl;
      cin.get();
    }
    counter++;
  }



  cin.get();
}

void repCost(orderedLinkedList<bookType> &list0, orderedLinkedList<bookType> &list1, orderedLinkedList<bookType> &list2, orderedLinkedList<bookType> &list3)
{
  linkedListIterator<bookType> it;
  int pageNumber = 0;
  int counter = 0;
  time_t now = time(0);
  char*dt = ctime(&now);

  system("clear");
  cout << "Listing By Cost" << endl;
  cout << "Date and Time: " << dt << endl;
  cout << "Database Size: " << DBSIZE << endl;
  cout << "Book Count: " << bookType::getBookCount() << endl;
  cout << "Page " << pageNumber << endl;
  cout << endl << endl;

  cout << left;
  cout << setw(90) << "Title";
  cout << setw(20) << "ISBN";
  cout << right;
  cout << setw(15) << "Wholesale Cost";
  cout << endl;

  cout << setw(150) << setfill('-') << "-" << endl;
  cout << setfill(' ');

  for (it = list2.begin(); it != list2.end(); ++it)
  {
    if (0 == counter%20)
    {
      system("clear");
      pageNumber++;
      cout << "Listing By Cost" << endl;
      cout << "Date and Time: " << dt << endl;
      cout << "Database Size: " << DBSIZE << endl;
      cout << "Book Count: " << bookType::getBookCount() << endl;
      cout << "Page " << pageNumber << endl;
      cout << endl << endl;

      cout << left;
      cout << setw(90) << "Title";
      cout << setw(20) << "ISBN";
      cout << right;
      cout << setw(15) << "Wholesale Cost";
      cout << endl;

      cout << setw(150) << setfill('-') << "-" << endl;
      cout << setfill(' ');
    }

    cout << left;
    cout << setw(90) << (*it).getBookTitle();
    cout << setw(20) << (*it).getISBN();
    cout << right << fixed << showpoint << setprecision(2);
    cout << setw(15) << (*it).getWholesale() << endl;




    if (19 == counter%20)
    {
      cout << endl;
      cout << "Press Enter To Continue.." << endl;
      cin.get();
    }
    counter++;
  }






  cin.get();
}

void repAge(orderedLinkedList<bookType> &list0, orderedLinkedList<bookType> &list1, orderedLinkedList<bookType> &list2, orderedLinkedList<bookType> &list3)
{
  linkedListIterator<bookType> it;
  int pageNumber = 0;
  int counter = 0;
  time_t now = time(0);
  char*dt = ctime(&now);

  system("clear");
  cout << "Listing By Date Added" << endl;
  cout << "Date and Time: " << dt << endl;
  cout << "Database Size: " << DBSIZE << endl;
  cout << "Book Count: " << bookType::getBookCount() << endl;
  cout << "Page " << pageNumber << endl;
  cout << endl << endl;

  cout << left;
  cout << setw(90) << "Title";
  cout << setw(20) << "ISBN";
  cout << right;
  cout << setw(15) << "Qty on Hand";
  cout << setw(15) << "Date Added";
  cout << endl;



  cout << setw(150) << setfill('-') << "-" << endl;
  cout << setfill(' ');


  for (it = list3.begin(); it != list3.end(); ++it)
  {
    if (0 == counter%20)
    {
      system("clear");
      pageNumber++;
      cout << "Listing By Date Added" << endl;
      cout << "Date and Time: " << dt << endl;
      cout << "Database Size: " << DBSIZE << endl;
      cout << "Book Count: " << bookType::getBookCount() << endl;
      cout << "Page " << pageNumber << endl;
      cout << endl << endl;

      cout << left;
      cout << setw(90) << "Title";
      cout << setw(20) << "ISBN";
      cout << right;
      cout << setw(15) << "Qty on Hand";
      cout << setw(15) << "Date Added";
      cout << endl;



      cout << setw(150) << setfill('-') << "-" << endl;
      cout << setfill(' ');
    }


    cout << left;
    cout << setw(90) << (*it).getBookTitle();
    cout << setw(20) << (*it).getISBN();
    cout << right;
    cout << setw(15) << (*it).getQtyOnHand();
    cout << setw(15) << (*it).getDateAdded() << endl;


    if (19 == counter%20)
    {
      cout << endl;
      cout << "Press Enter To Continue.." << endl;
      cin.get();
    }
    counter++;
  }





  cin.get();
}
