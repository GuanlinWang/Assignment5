// Guanlin Wang
// Section # 02
#include <iostream>
#include <fstream>
#include <string>
#include<sstream>
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
//
// void readRentals(vector<Book *> & myBooks, vector<Person *> myCardholders) {
//     return;
// }
//
 void openCard(vector<Person *> & myCardholders, int nextID)
  {
    string first,last;
    cout<<"Please enter the first name: ";
    cin>>first;
    cout<<"Please enter the last name: ";
    cin>>last;
  }
//
// Book * searchBook(vector<Book *> myBooks, int id) {
//     return nullptr;
// }
// */

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
  
                break;

            case 2:
                // Book return
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
