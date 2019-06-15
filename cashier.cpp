//File name:cashier.cpp
//Project name: serendipity
//----------------------------------------------------------------
//creator's name and email: Ryota Yamaoka ryamaoka0@saddleback.edu
//course-section:cs 1b ticket#23650
//creation date:1/21/19
//date of last modification:5/20/19
//----------------------------------------------------------------
//purpose: create cashier module to have user input book information
//          necessary for the transaction to be completed and to Display
//          receipt of transaction details.
//----------------------------------------------------------------
//Algorithm:
// step 1: call lookUpBook Function and have user search for a book
// step 2: if the book exists, display quantity avaiable and the book Title
// step 3: have user input if they want to purchase book and the quantity
//          they want to purchase
// step 4: make sure the quantity they want to buy is a valid value
//          greater than zero and not exceed the quantity in stock
// step 5: finalize transaction and if THEN after everything else, subtract the quantity
//          purchased from the quantity in stock
// step 6: ask user if they want to purchase another book and repeat if so
// step 7: print receipt
//----------------------------------------------------------------
//data dictionary
//
//constants
//name     data type    initial Value
//SALESTAX double       0.06
//----------------------------------------------------------------
//variables
//
// name                       data type     initial Value
// doAgain                    char          'n'
// subTotal                   double         0
// totalAmount                double         0
// taxAmount                  double         0
// quantityToPurchase         int            0
// purchaseIndex              int            0
// lookUpIndex                int            0
// purchaseBook               char           'n'
// completeTransaction        char           'n'
// buyIndex                   int            1
// grandSubTotal              double         0
// grandTax                   double         0
// grandTotal                 double         0
// finalSubTotal              double         0
// it                         linkedListIterator<bookType>
// *t                         bookType ptr   nullptr
// *p                         bookType ptr   nullptr
// newQty                     double         0


#include <iostream>
#include <iomanip>
#include <ctime>
#include "invmenu.h"
#include "cashier.h"
#include "bookinfo.h"
#include "linkedList.h"
#include "orderedLinkedList.h"

using namespace std;

const int DBSIZE = 20;


void cashierModule(orderedLinkedList<bookType> &list0, orderedLinkedList<bookType> &list1, orderedLinkedList<bookType> &list2, orderedLinkedList<bookType> &list3)
{

  const double SALES_TAX = 0.06;
  char doAgain = 'n';

  //int purchaseQuantityList[DBSIZE];
  //double subTotalList[DBSIZE];
  int buyIndex = 1;
  double grandSubTotal = 0;
  double grandTax = 0;
  double grandTotal = 0;
  char completeTransaction = 'n';
  int index = 0;
  int finalQty = 0;
  int i = 0;
  linkedListIterator<bookType> it;


  orderedLinkedList<bookType> purchaseList;
  purchaseList.initializeList();
  bookType *t = nullptr;
  bookType *q = nullptr;

  time_t now = time(0);
  char*dt = ctime(&now);




  do
  {
    double finalSubTotal = 0;
    double subTotal = 0;
    double totalAmount = 0;
    double taxAmount = 0;
    int quantityToPurchase = 0;
    int purchaseIndex = 0;
    int lookUpIndex = 0;
    char purchaseBook = 'n';
    bool newBook = true;
    int newQty = 0;



    int numOfBooks = 0;



    system("clear");
    cout << "Serendipity Booksellers" << endl;
    cout << "Cashier Module" << endl;
    cout << "Database Size: " << DBSIZE << endl;
    cout << "Book Count: " << bookType::getBookCount() << endl;
    cout << endl << endl;

    cout << "Date and Time: " << dt << endl;




    //******************************************* lookUpFunction *******************************************
    q = nullptr;
    q = lookUpBook(list0, list1, list2, list3);


    if (q != nullptr)
    {
      system("clear");
      cout << "Serendipity Booksellers" << endl;
      cout << "Cashier Module" << endl;
      cout << "Database Size: " << DBSIZE << endl;
      cout << "Book Count: " << bookType::getBookCount() << endl;
      cout << endl << endl;
      cout << "Book Title: " << q->getBookTitle() << endl;
      cout << "Quantity Available: " << q->getQtyOnHand() << endl;
      cout << "Purchase This Book? (y/n): ";
      cin >> purchaseBook;

      if (purchaseBook == 'y' || purchaseBook == 'Y')
      {



        cout << "Quantity To Purchase: ";
        cin >> quantityToPurchase;

        while (quantityToPurchase < 0 || quantityToPurchase > q->getQtyOnHand() || cin.fail())
        {
          if (quantityToPurchase > q->getQtyOnHand())
          {
            cout << "Quantity Requested Is Not Available" << endl;
          }
          cin.clear();
          cin.ignore(1000, '\n');
          cout << "Please Enter Valid Quantity: ";
          cin >> quantityToPurchase;
        }


        (*q).setTransactionQty(quantityToPurchase);


        for (it = purchaseList.begin(); it != purchaseList.end(); ++it)
        {
          if (*it == *q)
          {
            newBook = false;
          }
        }
        if (newBook == true)
        {
          purchaseList.insert(*q);
        }





        for (it = purchaseList.begin(); it != purchaseList.end(); ++it)
        {
          //cout << "*it: " << (*it).getBookTitle() << endl;
          //cout << "*q: " << q->getBookTitle() << endl;

          if (*it == *q && newBook == false)
          {
            cout << "same book found" << endl;
            //cout << "*Quantity in Cart: " << (*it).getTransactionQty() << endl;
            //cout << "*q transactionQty: " << quantityToPurchase << endl;
            newQty = (*it).getTransactionQty() + quantityToPurchase;
            while (newQty > (*it).getQtyOnHand() || cin.fail())
            {
              cin.clear();
              cin.ignore(1000, '\n');
              cout << "Quantity is not available" << endl;
              cout << "Quantity already in cart: " << (*it).getTransactionQty() << endl;
              cout << "Enter quanity to purchase: ";
              cin >> quantityToPurchase;
              newQty = (*it).getTransactionQty() + quantityToPurchase;
            }
            //cout << "newQty: " << newQty << endl;
            //(*it).setTransactionQty(newQty);
            (*it).setTransactionQty(newQty);
            //cout << "***************************************" << endl;
            //cout << *it << endl;
            //cout << (*it).getTransactionQty() << endl;
            //cout << "***************************************" << endl;
            //(*it).setTransactionQty(9);
            //cout << "total transactionQty: " << (*it).getTransactionQty() << endl;
            t = new bookType(*it);
            t->setTransactionQty(newQty);
            //cout << "t ***********************:  " << endl;
            //cout << *t << endl;
            //cout << t->getTransactionQty() << endl;
            purchaseList.deleteNode(*it);
            subTotal = (t->getRetail()) * (t->getTransactionQty());
            t->setTransactionTotal(subTotal);
            //cout << "calculate subtotal" << endl;
            //cout << "transaction total: " << t->getTransactionTotal() << endl;
            purchaseList.insert(*t);


            delete t;
            t = nullptr;


            break;
          }



          if (newBook == true)
          {


            //cout << "transactionqty: " << (*it).getTransactionQty() << endl;
            //cout << (*it).getTransactionQty() << endl;

            //cout << "purchase list" << endl;
            //cout << *it << endl;
            subTotal = ((*it).getRetail()) * ((*it).getTransactionQty());
            //cout << "retail: " << (*it).getRetail() << endl;
            //cout << "qty: " << (*it).getTransactionQty() << endl;
            //cout << "subtotal: " << subTotal << endl;
            t = new bookType(*it);
            newQty = (*it).getTransactionQty();
            t->setTransactionQty(newQty);
            //cout << "t ***********************:  " << endl;
            //cout << *t << endl;
            //cout << t->getTransactionQty() << endl;
            purchaseList.deleteNode(*it);
            subTotal = t->getRetail() * t->getTransactionQty();
            //cout << "retail: " << t->getRetail() << endl;
            //cout << "qty: " << t->getTransactionQty() << endl;
            //cout << "subtotal: " << subTotal << endl;
            t->setTransactionTotal(subTotal);
            //cout << "transaction total: " << t->getTransactionTotal() << endl;
            purchaseList.insert(*t);


            delete t;
            t = nullptr;
          }


        }




        delete q;
        q = nullptr;


        for (it = purchaseList.begin(); it != purchaseList.end(); ++it)
        {
          finalSubTotal = finalSubTotal + (*it).getTransactionTotal();
        }





        grandSubTotal = finalSubTotal;
        grandTax = grandSubTotal * SALES_TAX;
        grandTotal = grandSubTotal + grandTax;
      }
    }

    cout << "Make Another Transaction? (y/n): ";
    cin >> doAgain;

    if (doAgain == 'y' || doAgain == 'Y')
    {
      buyIndex++;

      i++;

    }

    cout <<"Please Press Enter To Continue.." << endl;
    cin.ignore(1000, '\n');


  } while (doAgain == 'y' || doAgain == 'Y');



//****************************************************************************************************************

  system("clear");

  cout << "Serendipity Booksellers" << endl;
  cout << "Date and Time: " << dt;

  //cout << "Number of books to buy: " << numOfBooks << endl;

  cout << left << fixed << showpoint << setprecision(2);
  cout << setw(5) << "Qty" << setw(20) << "ISBN" << setw(70) << "Book Title" << setw(10) << "Price" << setw(10) << "Total" << endl;
  cout << setfill('-') << setw(120) << "-" << endl << endl;
  cout << setfill(' ');


  i = 0;
  for (it = purchaseList.begin(); it != purchaseList.end(); ++it)
  {

    //cout << "Display purchase list" << endl;
    //cout << *it << endl;
    //cout << (*it).getTransactionQty() << endl;
    //cout << (*it).getTransactionTotal() << endl;
    cout << setw(5) << noshowpoint << setprecision(0) << (*it).getTransactionQty() << setw(20) << (*it).getISBN() << setw(70) << (*it).getBookTitle()
        << "$" << right << showpoint  << setprecision(2) << setw(6) << (*it).getRetail() << setw(4) << "$" << setw(6) << (*it).getTransactionTotal() << left << endl;
        i++;
  }











  cout << endl << endl << endl;
  cout << right;

  cout << setw(75) << "Subtotal: " << setw(31) << "$" << setw(6) << grandSubTotal << endl;
  cout << setw(75) << "Tax: " << setw(31) << "$" << setw(6) << grandTax << endl;
  cout << setw(75) << "Total: " << setw(31) << "$" << setw(6) << grandTotal << endl;
  cout << endl << endl << endl;

  cout << "Complete Transaction? (y/n): ";
  cin >> completeTransaction;

  if (completeTransaction == 'n' || completeTransaction == 'N')
  {
    cout << "Transaction Cancelled" << endl;
  }
  else if (completeTransaction == 'y' || completeTransaction == 'Y')
  {
    cout << "Transaction Completed" << endl;

    for (it = purchaseList.begin(); it != purchaseList.end(); ++it)
    {

      cout <<endl;
      cout << "Receipt Details" << endl;
      cout << *it;
      cout << "transaction qty: " << (*it).getTransactionQty() << endl << endl;
      finalQty = 0;
      t = new bookType(*it);
      finalQty = (*it).getQtyOnHand() - (*it).getTransactionQty();
      t->setQtyOnHand(finalQty);


      (*it).setSortCode(0);
      list0.deleteNode(*it);


      (*it).setSortCode(1);
      list1.deleteNode(*it);


      (*it).setSortCode(2);
      list2.deleteNode(*it);


      (*it).setSortCode(3);
      list3.deleteNode(*it);

      t->setSortCode(0);
      list0.insert(*t);

      t->setSortCode(1);
      list1.insert(*t);

      t->setSortCode(2);
      list2.insert(*t);

      t->setSortCode(3);
      list3.insert(*t);



    }


  }

  cout << endl << endl;
  cout << "Thank You For Shopping At Serendipity" << endl << endl;
  cin.ignore(1000, '\n');
  cout << "Please Press Enter To Continue.." << endl;
  cin.get();

  delete t;
  t = nullptr;


}
