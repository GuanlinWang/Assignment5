#include "book.h"

Book::Book(int id, string bookName, string auth, string cat) {
    bookID=id;
    author=auth;
    category=cat;
    title=bookName;
}

string Book::getTitle() {
    return title;
}

string Book::getAuthor() {
    return author;
}

string Book::getCategory() {
    return category;
}

int Book::getId() {
    return bookID;
}
void Book::setPersonPtr(Person * ptr) {
} // complete

Person * Book::getPersonPtr() {
    return nullptr; // complete
}
