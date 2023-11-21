#include <stdio.h>
#include <string.h>
#include <ctype.h> 
#define MAX 5

typedef struct
{
int bookID;
      char title[40];
      char author[40];
      double price;
      int quantity;
} Book;
// Function declarations
void listBooks(Book *books, int size);
int addBook(Book *books, int size);
int removeBook(Book *books, int *size);
void findBook(Book *books, int size);  // if implemented
void updateBook(Book *books, int size);
void sortBooksAsc(Book *books, int size);




int main() {
    Book bookshop[MAX];
    char dummy;
    int size = 0, choice;

    // Menu
    printf("NTU BOOKSHOP MANAGEMENT PROGRAM:\n");
    printf("1: listBooks()\n");
    printf("2: addBook()\n");
    printf("3: removeBook()\n");
    printf("4: findBook()\n");
    printf("5: updateBook()\n");
    printf("6: quit\n");

    do {
        printf("Enter your choice: \n");
        scanf("%d", &choice);
        scanf("%c", &dummy);

        switch (choice) {
            case 1:
                listBooks(bookshop, size);
                break;
            case 2:
                size = addBook(bookshop, size);
                break;
            case 3:
                size = removeBook(bookshop, &size);
                break;
            case 4:
                findBook(bookshop, size);
                break;
            case 5:
                updateBook(bookshop, size);
                break;
        }
    } while (choice < 6);

    return 0;
}



void listBooks(Book *books, int size) {
    printf("listBooks():\n");

    if (size > 0) {
        int i;
        for (i = 0; i < size; i++) {
            printf("Book ID: %d\n", books[i].bookID);
            printf("Title: %s\n", books[i].title);
            printf("Author: %s\n", books[i].author);
            printf("Price: %.2f\n", books[i].price);
            printf("Quantity: %d\n", books[i].quantity);
            printf("\n");
        }
    } else {
        printf("The bookshop is empty\n");
    }
}




int addBook(Book *books, int size) {
    printf("addBook():\n");

    if (size == MAX) {
        printf("The bookshop is full! Unable to addBook()\n");
        return size;
    }

    int i, bookID;
    char title[40], author[40], dummy[20], *p;

    printf("Enter bookID:\n");
    scanf("%d", &bookID);
    scanf("%c", &dummy);  // Consume the newline character

    // Check if bookID already exists
    for (i = 0; i < size; i++) {
        if (bookID == books[i].bookID) {
            printf("The bookID has already existed! Unable to addBook()\n");
            return size;
        }
    }

    printf("Enter book title:\n");
    fgets(title, 40, stdin);
    if (p = strchr(title, '\n')) {
        *p = '\0';
    }

    printf("Enter author name:\n");
    fgets(author, 40, stdin);
    if (p = strchr(author, '\n')) {
        *p = '\0';
    }

    printf("Enter price:\n");
    scanf("%lf", &books[size].price);

    printf("Enter quantity:\n");
    scanf("%d", &books[size].quantity);

   
    books[size].bookID = bookID;
    strcpy(books[size].title, title);
    strcpy(books[size].author, author);

    printf("The book has been added successfully\n");

    size++;
    sortBooksAsc(books, size);

    return size;
}

int removeBook(Book *books, int *size) {
    printf("removeBook():\n");

    char targetTitle[40], targetAuthor[40], *p;

    // Check if the bookshop is empty
    if (*size == 0) {
        printf("The bookshop is empty\n");
        return *size;
    }

    // Read target book information
    printf("Enter the target book title: \n");
    fgets(targetTitle, 40, stdin);
    if (p = strchr(targetTitle, '\n')) {
        *p = '\0';
    }

    printf("Enter the target author name: \n");
    fgets(targetAuthor, 40, stdin);
    if (p = strchr(targetAuthor, '\n')) {
        *p = '\0';
    }

    // Convert target book information to lowercase for case-insensitive comparison
    for (int i = 0; targetTitle[i]; i++) {
        targetTitle[i] = tolower(targetTitle[i]);
    }

    for (int i = 0; targetAuthor[i]; i++) {
        targetAuthor[i] = tolower(targetAuthor[i]);
    }

    // Search for the target book in the bookshop
    for (int i = 0; i < *size; i++) {
        char tempTitle[40], tempAuthor[40];

        // Convert book information to lowercase for case-insensitive comparison
        strcpy(tempTitle, books[i].title);
        strcpy(tempAuthor, books[i].author);

        for (int j = 0; tempTitle[j]; j++) {
            tempTitle[j] = tolower(tempTitle[j]);
        }

        for (int j = 0; tempAuthor[j]; j++) {
            tempAuthor[j] = tolower(tempAuthor[j]);
        }

        // Check if the current book matches the target book
        if (strcmp(tempTitle, targetTitle) == 0 && strcmp(tempAuthor, targetAuthor) == 0) {
            // Display information about the removed book
            printf("The target book is removed\n");
            printf("Book ID: %d\n", books[i].bookID);
            printf("Title: %s\n", books[i].title);
            printf("Author: %s\n", books[i].author);
            printf("Price: %.2f\n", books[i].price);
            printf("Quantity: %d\n", books[i].quantity);

            // Shift remaining elements to fill the gap
            for (int j = i; j < *size - 1; j++) {
                books[j] = books[j + 1];
            }

            (*size)--;
            sortBooksAsc(books, *size);
            return *size;
        }
    }

    // If the target book is not found
    printf("The target book is not in the bookshop\n");
    return *size;
}

void findBook(Book *books, int size) {
    printf("findBook():\n");

    char targetTitle[40], targetAuthor[40], *p;

    // Read target book information
    printf("Enter the target book title: \n");
    fgets(targetTitle, 40, stdin);
    if (p = strchr(targetTitle, '\n')) {
        *p = '\0';
    }

    printf("Enter the target author name: \n");
    fgets(targetAuthor, 40, stdin);
    if (p = strchr(targetAuthor, '\n')) {
        *p = '\0';
    }

    // Convert target book information to lowercase for case-insensitive comparison
    for (int i = 0; targetTitle[i]; i++) {
        targetTitle[i] = tolower(targetTitle[i]);
    }

    for (int i = 0; targetAuthor[i]; i++) {
        targetAuthor[i] = tolower(targetAuthor[i]);
    }

    // Search for the target book in the bookshop
    for (int i = 0; i < size; i++) {
        char tempTitle[40], tempAuthor[40];

        // Convert book information to lowercase for case-insensitive comparison
        strcpy(tempTitle, books[i].title);
        strcpy(tempAuthor, books[i].author);

        for (int j = 0; tempTitle[j]; j++) {
            tempTitle[j] = tolower(tempTitle[j]);
        }

        for (int j = 0; tempAuthor[j]; j++) {
            tempAuthor[j] = tolower(tempAuthor[j]);
        }

        // Check if the current book matches the target book
        if (strcmp(tempTitle, targetTitle) == 0 && strcmp(tempAuthor, targetAuthor) == 0) {
            // Display information about the found book
            printf("The target book is found\n");
            printf("Book ID: %d\n", books[i].bookID);
            printf("Title: %s\n", books[i].title);
            printf("Author: %s\n", books[i].author);
            printf("Price: %.2f\n", books[i].price);
            printf("Quantity: %d\n", books[i].quantity);
            return;
        }
    }

    // If the target book is not found
    printf("The target book is not found\n");
}

void updateBook(Book *books, int size) {
    printf("updateBook():\n");

    char targetTitle[40], targetAuthor[40], *p;

    // Read target book information
    printf("Enter the target book title: \n");
    fgets(targetTitle, 40, stdin);
    if (p = strchr(targetTitle, '\n')) {
        *p = '\0';
    }

    printf("Enter the target author name: \n");
    fgets(targetAuthor, 40, stdin);
    if (p = strchr(targetAuthor, '\n')) {
        *p = '\0';
    }

    // Search for the target book in the bookshop
    for (int i = 0; i < size; i++) {
        // Check if the current book matches the target book
        if (strcmp(books[i].title, targetTitle) == 0 && strcmp(books[i].author, targetAuthor) == 0) {
            // Read updated price and quantity
            printf("Enter the updated price for the book: ");
            scanf("%lf", &books[i].price);

            printf("Enter the updated quantity for the book: ");
            scanf("%d", &books[i].quantity);

            // Display information about the updated book
            printf("The target book is updated\n");
            printf("Book ID: %d\n", books[i].bookID);
            printf("Title: %s\n", books[i].title);
            printf("Author: %s\n", books[i].author);
            printf("Price: %.2f\n", books[i].price);
            printf("Quantity: %d\n", books[i].quantity);

            return;
        }
    }
}

void sortBooksAsc(Book *books, int size) {
   
    for (int i = 0; i < size - 1; i++) {
        for (int j = 0; j < size - 1 - i; j++) {
            // Compare IDs
            // and swap if necessary
            if (books[j].bookID > books[j + 1].bookID) {
                // Swap books
                Book temp = books[j];
                books[j] = books[j + 1];
                books[j + 1] = temp;
            }
        }
    }
}
