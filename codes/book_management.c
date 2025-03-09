#include <stdio.h>
#include <string.h>
#include "book_management.h"

int addBook(Book *books, int *book_count, Book new_book) {
    if (*book_count >= MAX_BOOKS) return 0;
    
    // Check if book already exists
    Book* existing = findBook(books, *book_count, new_book.isbn);
    if (existing) {
        existing->total_count += new_book.total_count;
        existing->available_count += new_book.total_count;
        return 1;
    }
    
    books[*book_count] = new_book;
    (*book_count)++;
    return 1;
}

int removeBook(Book *books, int *book_count, const char *isbn) {
    for (int i = 0; i < *book_count; i++) {
        if (strcmp(books[i].isbn, isbn) == 0) {
            for (int j = i; j < *book_count - 1; j++) {
                books[j] = books[j + 1];
            }
            (*book_count)--;
            return 1;
        }
    }
    return 0;
}

Book* findBook(Book *books, int book_count, const char *isbn) {
    for (int i = 0; i < book_count; i++) {
        if (strcmp(books[i].isbn, isbn) == 0) {
            return &books[i];
        }
    }
    return NULL;
}

void listAllBooks(Book *books, int book_count) {
    printf("\n图书列表:\n");
    printf("%-20s %-30s %-20s %-10s %-10s\n", "ISBN", "书名", "作者", "总数量", "可借数量");
    for (int i = 0; i < book_count; i++) {
        printf("%-20s %-30s %-20s %-10d %-10d\n",
               books[i].isbn,
               books[i].title,
               books[i].author,
               books[i].total_count,
               books[i].available_count);
    }
}

int saveBooks(Book *books, int book_count) {
    FILE *file = fopen("books.dat", "wb");
    if (!file) return 0;
    
    fwrite(&book_count, sizeof(int), 1, file);
    fwrite(books, sizeof(Book), book_count, file);
    fclose(file);
    return 1;
}

int loadBooks(Book *books, int *book_count) {
    FILE *file = fopen("books.dat", "rb");
    if (!file) return 0;
    
    fread(book_count, sizeof(int), 1, file);
    fread(books, sizeof(Book), *book_count, file);
    fclose(file);
    return 1;
}
