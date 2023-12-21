//Write a structure called student containing character array named name with values that may be as
//long as 50; character array named faculty with values that may be as long as 50; decimal point variable
//named gpa and integer student id variable

#include <stdio.h>
#include <string.h>

struct Books {
    char title[50];
    char author[50];
    char subject[100];
    int book_id;
} book, book1;

int main() {

    strcpy(book.title, "C Programming");
    strcpy(book.author, "Nuha Ali");
    strcpy(book.subject, "C Programming Tutorial");
    book.book_id = 6495407;
    printf("\n");
    strcpy(book1.title, "Telecom Billing");
    strcpy(book1.author, "Zara Ali");
    strcpy(book1.subject, "Telecom Billing Tutorial");
    book1.book_id = 6495700;

    printf("Book 1 title : %s\n", book.title);
    printf("Book 1 author : %s\n", book.author);
    printf("Book 1 subject : %s\n", book.subject);
    printf("Book 1 book_id : %d\n", book.book_id);

    printf("Book 2 title : %s\n", book1.title);
    printf("Book 2 author : %s\n", book1.author);
    printf("Book 2 subject : %s\n", book1.subject);
    printf("Book 2 book_id : %d\n", book1.book_id);

    return 0;
}

//Write a program that reads the information about a student from the keyboard and then prints out the
//information in the following format:




