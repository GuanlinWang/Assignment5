// Guanlin Wang
// Section # 02
#include <iostream>
#include <fstream>
#include <string>
#include<sstream>
#include<algorithm>
#include <vector>
#include "person.cpp"
#include "book.cpp"

using namespace std;

void printMenu() {
    cout << "----------Library Book Rental System----------" << endl;
    cout << "1.  Book checkout" << endl;
    cout << "2.  Book return" << endl;
    cout << "3.  View all available books" << endl;
    cout << "4.  View all outstanding rentals" << endl;
    cout << "5.  View outstanding rentals for a cardholder" << endl;
    cout << "6.  Open new library card" << endl;
    cout << "7.  Close library card" << endl;
    cout << "8.  Exit system" << endl;
    cout << "Please enter a choice: ";
}


void readBooks(vector<Book *> & myBooks)
{
  int bookId=1;
  string tempId;
  string title="2";
  string author="2";
  string category="4";
  ifstream file;
  file.open("books.txt");

 while(true)
 {
  getline(file,tempId);
  getline(file, title);
  getline(file,author);
  getline(file,category);
  file.ignore();

  stringstream geek(tempId);
  geek>>bookId;
  Book * book=new Book(bookId,title,author,category);
  myBooks.push_back(book);
  if (file.peek(),file.eof())
  {break;}
 }
 file.close();

}

 void readPersons(vector<Person *> & myCardholders) {
     int cardNum;
     bool isAct;
     string first,last;
     ifstream file;
     file.open("persons.txt");

     while(true)
     {
     file>>cardNum>>isAct>>first>>last;
     file.ignore();
     if(file.peek(),file.eof())
     {break;}
      Person * cardHolder=new Person(cardNum,isAct,first,last);
      myCardholders.push_back(cardHolder);

    }
    file.close();

 }

 void bookCheckout(vector<Book*> &myBooks, vector<Person*> &myCardholders)
 {
   int enteredID,bookID;
   int pos1,pos2;
   bool found=false;
   cout<<"Please enter the card ID: "; cin>>enteredID;
   for (int i=0; i<myCardholders.size();i++)
   {
     if(myCardholders.at(i)->getId()==enteredID)
     {
       found=true;
       pos1=i;
       break;
     }
   }
   if(found==false||myCardholders.at(pos1)->isActive()==0)
   {
     cout<<"Card ID not found"<<endl;
   }
   else if(found==true)
  {
    cout<<"Cardholder: "<< myCardholders.at(pos1)->fullName()<<endl;
    cout<<"Please enter the book ID: "; cin>>bookID;
    for (int i=0; i<myBooks.size();i++)
    {
      if(myBooks.at(i)->getId()==bookID)
      {
        pos2=i;
        found=true;
        break;
      }
      else{found=false;}
    }
    if (found==false)
    {
      cout<<"Book ID not found"<<endl;
    }
    else if(found==true)
    {
      if(myBooks.at(pos2)->getPersonPtr()!=nullptr)
      {
        cout<<"Book already checked out"<<endl;
      }
      else{
      cout<<"Title: "<<myBooks.at(pos2)->getTitle()<<endl;

      myBooks.at(pos2)->setPersonPtr(myCardholders.at(pos1));
      cout<<"Rental Completed"<<endl;
     }
    }
  }

 }
void bookReturn(vector<Book*> &myBooks, vector<Person*> &myCardholders)
{
  int  bookID,pos;
  bool found=false;
  cout<<"Please enter the book ID to return: ";cin>>bookID;
  for (int i=0; i<myBooks.size();i++)
  {
    if(myBooks.at(i)->getId()==bookID)
    {
      pos=i;
      found=true;
      break;
    }
}
if (found==false)
{
  cout<<"Book ID not found"<<endl;
}
else
{
  cout<<"Title: "<<myBooks.at(pos)->getTitle()<<endl;
  myBooks.at(pos)->setPersonPtr(nullptr);
  cout<<"Return Completed"<<endl;
}
}

//
// void readRentals(vector<Book *> & myBooks, vector<Person *> myCardholders) {
//     return;
// }
//
//
// Book * searchBook(vector<Book *> myBooks, int id) {
//     return nullptr;
// }
// */

 void openCard(vector<Person *> & myCardholders, int nextID)
  {
    string first,last;
    cout<<"Please enter the first name: ";
    cin>>first;
    cout<<"Please enter the last name: ";
    cin>>last;
    Person *newCard=new Person(nextID,true,first,last);
    myCardholders.push_back(newCard);
    cout<<"Card ID "<<nextID<<" active"<<endl;
    cout<<"Cardholder: "<<first<<" "<<last;

  }

int main()
{
    vector<Book *> books;
    vector<Person *> cardholders;
   readBooks(books);
   readPersons(cardholders);
    int choice;
    do
    {
        // If you use cin anywhere, don't forget that you have to handle the <ENTER> key that
        // the user pressed when entering a menu option. This is still in the input stream.
        printMenu();
        cin >> choice;
        switch(choice)
        {
            case 1:
                // Book checkout
               bookCheckout(books,cardholders);
                break;

            case 2:
                // Book return
                bookReturn(books,cardholders);
                break;

            case 3:
                // View all available books
                for (int i =0; i<books.size();i++)
                {
                cout<<"Book ID: "<<books.at(i)->getId()<<endl;
                cout<<"Title: "<<books.at(i)->getTitle()<<endl;
                cout<<"Author: "<<books.at(i)->getAuthor()<<endl;
                cout<<"Category: "<<books.at(i)->getCategory()<<endl;
                cout<<endl;
              }
                break;

            case 4:
                // View all outstanding rentals
                break;

            case 5:
                // View outstanding rentals for a cardholder
                break;

            case 6:
                // Open new library card
                int newID;
                newID=cardholders.at(cardholders.size()-1)->getId()+1;
                openCard(cardholders,newID);
                break;

            case 7:
                // Close library card
                break;

            case 8:
                // Must update records in files here before exiting the program
                break;

            default:
                cout << "Invalid entry" << endl;
                break;
        }
        cout << endl;
   } while(choice != 8);
      return 0;
}
