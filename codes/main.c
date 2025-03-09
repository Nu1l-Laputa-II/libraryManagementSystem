#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "structures.h"
#include "book_management.h"
#include "reader_management.h"

// 全局变量定义
Book books[MAX_BOOKS];          // 图书数组，存储所有图书信息
Reader readers[MAX_READERS];    // 读者数组，存储所有读者信息
int book_count = 0;            // 当前图书总数
int reader_count = 0;          // 当前读者总数

// 显示主菜单
void showMenu() {
    printf("\n图书管理系统\n");
    printf("1. 添加图书\n");
    printf("2. 删除图书\n");
    printf("3. 查找图书\n");
    printf("4. 显示所有图书\n");
    printf("5. 添加读者\n");
    printf("6. 删除读者\n");
    printf("7. 显示所有读者\n");
    printf("8. 借书\n");
    printf("9. 还书\n");
    printf("0. 退出\n");
    printf("请选择操作: ");
}

// 图书借阅功能
// 处理图书借阅操作，包括读者和图书验证，更新相关计数
void borrowBook() {
    int reader_id;
    char isbn[MAX_ISBN_LEN];
    
    // 验证读者
    printf("请输入读者ID: ");
    scanf("%d", &reader_id);
    Reader* reader = findReader(readers, reader_count, reader_id);
    if (!reader) {
        printf("读者不存在!\n");
        return;
    }
    
    // 验证图书
    printf("请输入图书ISBN: ");
    scanf("%s", isbn);
    Book* book = findBook(books, book_count, isbn);
    if (!book) {
        printf("图书不存在!\n");
        return;
    }
    
    // 检查图书可借状态
    if (book->available_count <= 0) {
        printf("图书已无可借册数!\n");
        return;
    }
    
    // 更新借阅信息
    book->available_count--;
    reader->borrowed_count++;
    printf("借书成功!\n");
}

// 图书归还功能
// 处理图书归还操作，包括读者和图书验证，更新相关计数
void returnBook() {
    int reader_id;
    char isbn[MAX_ISBN_LEN];
    
    // 验证读者
    printf("请输入读者ID: ");
    scanf("%d", &reader_id);
    Reader* reader = findReader(readers, reader_count, reader_id);
    if (!reader) {
        printf("读者不存在!\n");
        return;
    }
    
    // 验证图书
    printf("请输入图书ISBN: ");
    scanf("%s", isbn);
    Book* book = findBook(books, book_count, isbn);
    if (!book) {
        printf("图书不存在!\n");
        return;
    }
    
    // 更新归还信息
    book->available_count++;
    reader->borrowed_count--;
    printf("还书成功!\n");
}

// 主函数
int main() {
    // 初始化：从文件加载数据
    loadBooks(books, &book_count);
    loadReaders(readers, &reader_count);
    
    int choice;
    Book new_book;
    Reader new_reader;
    char isbn[MAX_ISBN_LEN];
    
    // 主程序循环
    while (1) {
        showMenu();
        scanf("%d", &choice);
        
        // 根据用户选择执行相应操作
        switch (choice) {
            case 1:  // 添加图书
                printf("请输入ISBN: ");
                scanf("%s", new_book.isbn);
                printf("请输入书名: ");
                scanf("%s", new_book.title);
                printf("请输入作者: ");
                scanf("%s", new_book.author);
                printf("请输入数量: ");
                scanf("%d", &new_book.total_count);
                new_book.available_count = new_book.total_count;
                if (addBook(books, &book_count, new_book))
                    printf("添加成功!\n");
                else
                    printf("添加失败!\n");
                break;
                
            case 2:  // 删除图书
                printf("请输入要删除的图书ISBN: ");
                scanf("%s", isbn);
                if (removeBook(books, &book_count, isbn))
                    printf("删除成功!\n");
                else
                    printf("删除失败!\n");
                break;
                
            case 3:  // 查找图书
                printf("请输入要查找的图书ISBN: ");
                scanf("%s", isbn);
                Book* found = findBook(books, book_count, isbn);
                if (found)
                    printf("找到图书: %s - %s\n", found->title, found->author);
                else
                    printf("未找到图书!\n");
                break;
                
            case 4:  // 显示所有图书
                listAllBooks(books, book_count);
                break;
                
            case 5:  // 添加读者
                printf("请输入读者ID: ");
                scanf("%d", &new_reader.id);
                printf("请输入姓名: ");
                scanf("%s", new_reader.name);
                printf("请输入电话: ");
                scanf("%s", new_reader.phone);
                new_reader.borrowed_count = 0;
                if (addReader(readers, &reader_count, new_reader))
                    printf("添加成功!\n");
                else
                    printf("添加失败!\n");
                break;
                
            case 6:  // 删除读者
                printf("请输入要删除的读者ID: ");
                int id;
                scanf("%d", &id);
                if (removeReader(readers, &reader_count, id))
                    printf("删除成功!\n");
                else
                    printf("删除失败!\n");
                break;
                
            case 7:  // 显示所有读者
                listAllReaders(readers, reader_count);
                break;
                
            case 8:  // 借书
                borrowBook();
                break;
                
            case 9:  // 还书
                returnBook();
                break;
                
            case 0:  // 退出系统
                // 保存数据到文件并退出
                saveBooks(books, book_count);
                saveReaders(readers, reader_count);
                printf("谢谢使用，再见!\n");
                return 0;
                
            default:
                printf("无效的选择!\n");
        }
    }
    
    return 0;
}
