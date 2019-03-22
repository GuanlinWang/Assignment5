// Guanlin Wang
// Section # 02
#include <iostream>
#include <fstream>
#include <string>
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


void readBooks(vector<Book *> & myBooks) {
  string name,auth,cat,skip;
  int id;
  fstream file;

   file.open("books.txt");
while(true)
{
  file>>id;
  file.clear();
  getline(file,name);
  file.clear();
  getline(file,auth);
  file>>cat;



cout<<id<<endl;
//cout<<name<<endl;
//cout<<auth<<endl;
//cout<<cat<<endl;
  if(file.peek(),file.eof())
  {break;}


}

          //  Book* temp=new Book(id,name,auth,cat);
          // cout<<temp->getTitle()<<endl<<temp->getId()<<endl<<temp->getAuthor()
          //  <<endl<<temp->getCategory()<<endl;

        //   myBooks.emplace_back(temp);


}

// int readPersons(vector<Person *> & myCardholders) {
//     return 0;
// }
//
// void readRentals(vector<Book *> & myBooks, vector<Person *> myCardholders) {
//     return;
// }
//
// void openCard(vector<Person *> & myCardholders, int nextID) {
//     return;
// }
//
// Book * searchBook(vector<Book *> myBooks, int id) {
//     return nullptr;
// }
// */

int main()
{
    vector<Book *> books;
    vector<Person *> cardholders;

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
                readBooks(books);
                break;

            case 2:
                // Book return
                break;

            case 3:
                // View all available books
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
