// Advanced Book Manager in C++

#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

class Book {
public:
    std::string title;  // Book's title
    std::string author; // Book's author

    // Book's constructor
    Book(std::string title, std::string author) {
        this->title = title;
        this->author = author;
    }

    // Function to display a book
    void display() {
        std::cout << "Title: " << this->title << ", Author: " << this->author << std::endl;
    }
};

class Library {
private:
    std::vector<Book> books; // Vector to store books

public:
    // Function to add a book
    void addBook(std::string title, std::string author) {
        // Adding a new book to the list
        books.push_back(Book(title, author));
    }

    // Function to remove a book
    void removeBook(std::string title) {
        // Removing a book based on its title
        books.erase(std::remove_if(books.begin(), books.end(), [&](Book& book) {
            return book.title == title;
        }), books.end());
    }

    // Function to display all books
    void displayBooks() {
        // Displaying each book in the list
        for(Book& book : books) {
            book.display();
        }
    }

    // Function to search a book
    void searchBook(std::string title) {
        // Searching a book based on its title
        for(Book& book : books) {
            if(book.title == title) {
                std::cout << "Book found: ";
                book.display();
                return;
            }
        }
        std::cout << "Book not found\n";
    }

    // Function to count the number of books
    int countBooks() {
        // Counting the number of books in the library
        return books.size();
    }

    // Function to check if a book is present
    bool isBookPresent(std::string title) {
        // Checking if a book is present in the library
        for(Book& book : books) {
            if(book.title == title) {
                return true;
            }
        }
        return false;
    }

    // Function to sort books by title
    void sortByTitle() {
        // Sorting the books based on their titles
        std::sort(books.begin(), books.end(), [](const Book& book1, const Book& book2) {
            return book1.title < book2.title;
        });
    }

    // Function to sort books by author
    void sortByAuthor() {
        // Sorting the books based on their authors
        std::sort(books.begin(), books.end(), [](const Book& book1, const Book& book2) {
            return book1.author < book2.author;
        });
    }
};

int main() {
    Library library; // Create a library

    // Add books
    library.addBook("1984", "George Orwell");
    library.addBook("To Kill a Mockingbird", "Harper Lee");
    library.addBook("The Great Gatsby", "F. Scott Fitzgerald");

    // Display books
    library.displayBooks();

    // Count the number of books
    std::cout << "Number of books: " << library.countBooks() << std::endl;

    // Check if a book is present
    std::string bookTitle = "1984";
    if(library.isBookPresent(bookTitle)) {
        std::cout << "The book \"" << bookTitle << "\" is present in the library.\n";
    } else {
        std::cout << "The book \"" << bookTitle << "\" is not present in the library.\n";
    }

    // Search a book
    library.searchBook("1984");

    // Sort by title
    std::cout << "Sorting books by title:\n";
    library.sortByTitle();
    library.displayBooks();

    // Sort by author
    std::cout << "Sorting books by author:\n";
    library.sortByAuthor();
    library.displayBooks();

    // Remove a book
    library.removeBook("1984");

    // Display books again to see the changes
    library.displayBooks();

    return 0;
}