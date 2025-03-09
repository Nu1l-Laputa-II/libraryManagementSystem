#ifndef BOOK_MANAGEMENT_H
#define BOOK_MANAGEMENT_H

#include "structures.h"

// 添加新图书到系统
// 参数：books-图书数组，book_count-当前图书总数，new_book-要添加的新图书
// 返回：成功返回1，失败返回0
int addBook(Book *books, int *book_count, Book new_book);

// 从系统中删除指定图书
// 参数：books-图书数组，book_count-当前图书总数，isbn-要删除的图书ISBN
// 返回：成功返回1，失败返回0
int removeBook(Book *books, int *book_count, const char *isbn);

// 查找指定ISBN的图书
// 参数：books-图书数组，book_count-当前图书总数，isbn-要查找的图书ISBN
// 返回：成功返回图书指针，失败返回NULL
Book* findBook(Book *books, int book_count, const char *isbn);

// 显示所有图书信息
// 参数：books-图书数组，book_count-当前图书总数
void listAllBooks(Book *books, int book_count);

// 将图书信息保存到文件
// 参数：books-图书数组，book_count-当前图书总数
// 返回：成功返回1，失败返回0
int saveBooks(Book *books, int book_count);

// 从文件加载图书信息
// 参数：books-图书数组，book_count-当前图书总数指针
// 返回：成功返回1，失败返回0
int loadBooks(Book *books, int *book_count);

#endif
