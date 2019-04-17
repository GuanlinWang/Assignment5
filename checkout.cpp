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

void overWrite(vector<Book *> & myBooks, vector<Person *> & myCardholders)
{
  ofstream file;
  file.open("persons.txt");
  for (int i =0; i<myCardholders.size();i++)
  {
    file<<myCardholders.at(i)->getId()<<" "<<myCardholders.at(i)->isActive()
    <<" "<<myCardholders.at(i)->getFirstName()<<" "<<myCardholders.at(i)->
    getLastName()<<endl;
  }
  file.close();

  file.open("rentals.txt");
  for(int i=0; i<myBooks.size();i++)
  {
    if (myBooks.at(i)->getPersonPtr()!=nullptr)
    {
      file<<myBooks.at(i)->getId()<<" "<<myBooks.at(i)->getPersonPtr()->getId()
      <<endl;
    }
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


 void readRentals(vector<Book *> & myBooks, vector<Person *> myCardholders)
 {
   int bookId, personId,bookPos,personPos;
   ifstream file;
   file.open("rentals.txt");
   while(true)
   {
     file>>bookId>>personId;
     for (int i =0; i<myBooks.size();i++)
     {
       if (myBooks.at(i)->getId()==bookId)
       {
         bookPos=i;
         break;
       }
     }
     for (int i=0;i<myCardholders.size();i++)
     {
       if (myCardholders.at(i)->getId()==personId)
       {
         personPos=i;
         break;
       }
     }

     myBooks.at(bookPos)->setPersonPtr(myCardholders.at(personPos));

   if(file.peek(),file.eof())
   {break;}

  }
  file.close();
 }


 void openCard(vector<Person *> & myCardholders)
  {
    string first,last;
    int newID,temp;
    cout<<"Please enter the first name: ";
    cin>>first;
    cout<<"Please enter the last name: ";
    cin>>last;
    temp=myCardholders.size()-1;
    newID=myCardholders.at(temp)->getId();
    Person *newCard=new Person(newID+1,true,first,last);
     myCardholders.push_back(newCard);
    cout<<"Card ID "<<newID+1<<" active"<<endl;
    cout<<"Cardholder: "<<first<<" "<<last;

  }
  void closeCard(vector<Person *> & myCardholders)
   {
     char choice;
     int id,pos;
     bool found=false;
     cout<<"Please enter the card ID: ";
     cin>>id;
     for (int i =0; i<myCardholders.size();i++)
     {
       if(myCardholders.at(i)->getId()==id)
       {
         found=true;
         pos=i;
         break;
       }
     }
     if(found==false)
     {
       cout<<"Card ID not found;"<<endl;
     }
     else
     {
       cout<<"Cardholder: "<<myCardholders.at(pos)->fullName()<<endl;
       if (myCardholders.at(pos)->isActive()==false)
       {
         cout<<"Card ID is already inactive";
       }
       else
       {
         cout<<"Are you sure you want to deactivate card(y/n)? ";
          cin>>choice;
         if (choice=='y'||choice=='Y')
         {
           myCardholders.at(pos)->setActive(false);
           cout<<"Card ID deactivated"<<endl;
         }
       }
     }
   }

   void allRentals(vector<Book *> & myBooks)
   {
     bool anyRental=false;
     for (int i =0;i<myBooks.size();i++)
     {
       if (myBooks.at(i)->getPersonPtr()!=nullptr)
        {
          anyRental=true;
          cout<<"Book ID: "<<myBooks.at(i)->getId()<<endl;
          cout<<"Title: "<<myBooks.at(i)->getTitle()<<endl;
          cout<<"Author: "<<myBooks.at(i)->getAuthor()<<endl;
          cout<<"Cardholder: "<<myBooks.at(i)->getPersonPtr()->fullName()<<endl;
          cout<<"Card ID: "<<myBooks.at(i)->getPersonPtr()->getId()<<endl;
          cout<<endl;
        }
     }
     if (anyRental==false)
     {
       cout<<"No outstanding rentals"<<endl;
     }
   }

   void personRentals(vector<Book *> & myBooks, vector<Person *> myCardholders)
   {
     int cardId,pos1;
     bool noBooks=true;
     bool found=false;
     cout<<"Please enter the card ID: ";
     cin>>cardId;
     for (int i=0; i<myCardholders.size();i++)
     {
       if(myCardholders.at(i)->getId()==cardId)
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
     else
     {
       cout<<"Cardholder: "<<myCardholders.at(pos1)->fullName()<<endl;
       for (int i =0; i<myBooks.size();i++)
       {
         if (myBooks.at(i)->getPersonPtr()!=nullptr)
         {
          if (myBooks.at(i)->getPersonPtr()->getId()==cardId)
          {
            noBooks=false;
            cout<<"Book ID: "<<myBooks.at(i)->getId()<<endl;
            cout<<"Title: "<<myBooks.at(i)->getTitle()<<endl;
            cout<<"Author: "<<myBooks.at(i)->getAuthor()<<endl;
            cout<<endl;
          }
       }

       }
       if (noBooks==true)
      {
        cout<<"No books currently checkout"<<endl;
      }
     }

   }

int main()
{
    vector<Book *> books;
    vector<Person *> cardholders;
   readBooks(books);
   readPersons(cardholders);
   readRentals(books,cardholders);
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
                allRentals(books);
                break;

            case 5:
                // View outstanding rentals for a cardholder
                personRentals(books,cardholders);
                break;

            case 6:
                // Open new library card
                openCard(cardholders);
                break;

            case 7:
                // Close library card
                closeCard(cardholders);
                break;

            case 8:
                // Must update records in files here before exiting the program
               overWrite(books,cardholders);
                break;

            default:
                cout << "Invalid entry" << endl;
                break;
        }
        cout << endl;
   } while(choice != 8);
      return 0;
}
