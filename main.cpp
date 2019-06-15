//File name: main.cpp
//Project name: serendipity
//----------------------------------------------------------------
//creator's name and email: Ryota Yamaoka ryamaoka0@saddleback.edu
//course-section:cs 1b ticket#23650
//creation date:1/21/19
//date of last modification:5/20/19
//----------------------------------------------------------------
//purpose:create main menu screen for cashierModule, invmenu, and reportsModule
//----------------------------------------------------------------
//Algorithm:
//step 1: create 4 ordered linked list to store book data.
//step 2:; input books into data base using txt file
//step 3: Create a menu with the following options
//        1. cashier, 2. inventory, 3. reports, and 4. exit Program
//step 4: Accept user input for choice selection
//step 5: Create a SWITCH (choice) to call FUNCTIONS for each choice
//        and go further into the program or a choice to exit.
//step 6: user input 1 takes user to cashier module to purchase books
//step 7: user input 2 takes user to inventory module to add, delete, lookUp, edit books
//step 8: user input 3 takes user to reports module to see inventory database reports
//step 9: write out database to external file using writeOutData functiton
//----------------------------------------------------------------
//data dictionary
//
//constants
//name         data type    initial Value
// DBSIZE      int          125
//----------------------------------------------------------------
//variables
//
//name                    data type     initial Value
// choice                 int           0
// bookCount              int           0
// fin                    ifstream
// fout                   ofstream
// getTitle               string        "Empty"
// getISBN                string        "Empty"
// getAuthor              string        "Empty"
// getPublisher           string        "Empty"
// getDateAdded           string        "Empty"
// getQtyOnHand           int           0
// getWholesale           double        0
// getRetail              doouble       0
// count                  int           "
// *temp                  bookType ptr
//it                      linkedListIterator<bookType>
//list0                   orderedLinkedList<bookType>
//list1                   orderedLinkedList<bookType>
//list2                   orderedLinkedList<bookType>
//list3                   orderedLinkedList<bookType>



#include <iostream>
#include <string>
#include <fstream>
#include "bookType.h"
#include "cashier.h"
#include "invmenu.h"
#include "bookinfo.h"
#include "reports.h"
#include "linkedList.h"
#include "orderedLinkedList.h"


using namespace std;


const int DBSIZE = 125;
  //database size for bookstore

void readInData(orderedLinkedList<bookType> &list0, orderedLinkedList<bookType> &list1, orderedLinkedList<bookType> &list2, orderedLinkedList<bookType> &list3)
{
  ifstream fin;
  string getTitle = "Empty";
  string getISBN = "Empty";
  string getAuthor = "Empty";
  string getPublisher = "Empty";
  string getDateAdded = "Empty";
  int getQtyOnHand = 0;
  double getWholesale = 0;
  double getRetail = 0;
  int count = 0;
  bookType *temp;  // used for linked list



  fin.open("database-3.txt");
  if (!fin)
  {
    cout << "File was not able to open" << endl;
    cin.ignore(1000, '\n');
    cout << "Press Enter To Continue..." << endl;
    cin.get();
  }


  getline(fin, getTitle, '\n');
  getline(fin, getISBN, '\n');
  getline(fin, getAuthor, '\n');
  getline(fin, getPublisher, '\n');
  getline(fin, getDateAdded, '\n');
  fin >> getQtyOnHand;
  fin >> getWholesale;
  fin >> getRetail;


  bookType::incrementBookCount();
  count = 1;

  // read in data into ordered linked list
  temp = new bookType(getTitle, getISBN, getAuthor, getPublisher, getDateAdded, getQtyOnHand, getWholesale, getRetail);
  list0.insert(*temp);

  temp->setSortCode(1);
  list1.insert(*temp);

  temp->setSortCode(2);
  list1.insert(*temp);

  temp->setSortCode(3);
  list1.insert(*temp);


  while (!fin.fail())
  {
    fin.ignore(1000, '\n');
    getline(fin, getTitle, '\n');
    getline(fin, getISBN, '\n');
    getline(fin, getAuthor, '\n');
    getline(fin, getPublisher, '\n');
    getline(fin, getDateAdded, '\n');
    fin >> getQtyOnHand;
    fin >> getWholesale;
    fin >> getRetail;

    if (!fin.fail())
    {
      bookType::incrementBookCount();
      count++;

      // read in data into ordered linked list
      temp = new bookType(getTitle, getISBN, getAuthor, getPublisher, getDateAdded, getQtyOnHand, getWholesale, getRetail);
      list0.insert(*temp);

      temp->setSortCode(1);
      list1.insert(*temp);

      temp->setSortCode(2);
      list2.insert(*temp);

      temp->setSortCode(3);
      list3.insert(*temp);
    }

  }


/*
  //traverse list using iterator
  for (it = list0.begin(); it != list0.end(); ++it)
  {
    cout << *it << endl;
  }
*/


  cout << "File Input Completed" << endl;
  cout << "Count: " << count << endl;


  fin.close();
}


void writeOutData(orderedLinkedList<bookType> &list0, orderedLinkedList<bookType> &list1, orderedLinkedList<bookType> &list2, orderedLinkedList<bookType> &list3)
{
  ofstream fout;
  linkedListIterator<bookType> it;

  fout.open("outputfile.txt");
  if (!fout)
  {
    cout << "File was not able to open" << endl;
    cin.ignore(1000, '\n');
    cout << "Press Enter To Continue..." << endl;
    cin.get();
  }

  for (it = list0.begin(); it != list0.end(); ++it)
  {

    fout << (*it).getBookTitle() << endl;
    fout << (*it).getISBN() << endl;
    fout << (*it).getAuthor() << endl;
    fout << (*it).getPublisher() << endl;
    fout << (*it).getDateAdded() << endl;
    fout << (*it).getQtyOnHand() << endl;
    fout << (*it).getWholesale() << endl;
    fout << (*it).getRetail() << endl;
    fout << endl;


  }

  fout.close();
  cout << "File Output Completed" << endl;
}




int main()
{
  int choice = 0;



  // ordered linked list that stores book data base
  orderedLinkedList<bookType> list0;
  orderedLinkedList<bookType> list1;
  orderedLinkedList<bookType> list2;
  orderedLinkedList<bookType> list3;

  list0.initializeList();
  list1.initializeList();
  list2.initializeList();
  list3.initializeList();


  // read in book data from input file
  readInData(list0, list1, list2, list3);
  cout << "Press Enter To Continue" << endl;
  cin.ignore(1000, '\n');
  cin.get();




  do
  {
    system("clear");

    cout << "Serendipity Booksellers" << endl;
    cout << endl;


    cout << "         Main Menu         " << endl;
    cout << "***************************" << endl;
    cout << "* 1. Cashier Module       *" << endl;
    cout << "* 2. Inventory Module     *" << endl;
    cout << "* 3. Reports Module       *" << endl;
    cout << "* 4. Exit                 *" << endl;
    cout << "***************************" << endl;
    cout << endl;

    cout << "Enter Your Choice: ";
    cin >> choice;

    while (choice < 1 || choice > 4 || cin.fail())
    {
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


    switch(choice)
    {
      case 1:
        cashierModule(list0, list1, list2, list3);
        break;

      case 2:
        inventoryModule(list0, list1, list2, list3);
        break;

      case 3:
        reportsModule(list0, list1, list2, list3);
        break;

      case 4:
        cout << "Exit Program" << endl;
        break;

      default:
        cout << "<something went wrong>" << endl;
        break;
    }



  } while (choice != 4);




  cout << "Thank You For Using This Program" << endl;
  cout << "Program Terminating" << endl;

  writeOutData(list0, list1, list2, list3);     //write out data in output file
  list0.destroyList();                          // deletes linked lists
  list1.destroyList();
  list2.destroyList();
  list3.destroyList();


  return 0;
}
