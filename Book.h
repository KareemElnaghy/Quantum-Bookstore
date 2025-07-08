//
// Created by Kareem Elnaghy on 08/07/2025.
//

#ifndef BOOK_H
#define BOOK_H

#include <iostream>
using namespace std;

class Book {
protected:  // attributes that will be passed to derived classes
    string isbn, title, author;
    int year;
    double price;
public:
    Book(string isbn, string title, string author, int year, double price)
        : isbn(isbn), title(title), author(author), year(year), price(price) {}

    // setters and getters
    virtual string getType() const = 0; // note: pure virtual function that will return type of the book depending on which class type it is
    string getISBN() const {
        return isbn;
    }
    int getYear() const {
        return year;
    }
    double getPrice() const {
        return price;
    }
    virtual bool isAvailable(int qty) const = 0;
    virtual void buy(int qty) = 0;
    virtual void send(const string& email, const string& address) const = 0;
    virtual bool isForSale() const = 0;
};

// Derive classes from Book i.e. the paper book, ebook and the showcase book
class PaperBook : public Book {
    int stock;
    bool shipped;
public:
    PaperBook(string isbn, string title, string author, int year, double price, int stock)
        : Book(isbn, title, author, year, price), stock(stock), shipped(false) {}
    string getType() const override {
        return "PaperBook";
    }
    bool isAvailable(int qty) const override {
        return (stock >= qty);
    }
    void buy(int qty) override {
        stock -= qty;
    }
    void send(const string& email, const string& address) const override {
        cout << "Sending Paper book to Shipping Service for address: " << address << endl;
    }
    bool isForSale() const override {
        return true;
    }
};

class EBook : public Book {
    string filetype;
    bool shippedViaEmail;
public:
    EBook(string isbn, string title, string author, int year, double price, string filetype)
        : Book(isbn, title, author, year, price), filetype(filetype), shippedViaEmail(false) {}
    string getType() const override {
        return "EBook";
    }
    bool isAvailable(int qty) const override {
        return true;
    }
    void buy(int qty) override {} // no stock
    void send(const string& email, const string& address) const override {
        cout << "Sending ebook to Mail Service with the email: " << email << endl;
    }
    bool isForSale() const override {
        return true;
    }
};

class ShowcaseBook : public Book {
public:
    ShowcaseBook(string isbn, string title, string author, int year)
        : Book(isbn, title, author, year, 0.0) {}
    string getType() const override {
        return "ShowcaseBook";
    }
    bool isAvailable(int qty) const override {
        return false;
    }
    void buy(int qty) override {} // no stock
    void send(const string& email, const string& address) const override {}
    bool isForSale() const override {
        return false;
    }
};


#endif //BOOK_H
