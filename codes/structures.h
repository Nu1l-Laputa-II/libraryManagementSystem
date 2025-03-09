#ifndef STRUCTURES_H
#define STRUCTURES_H

#include <time.h>

// 系统常量定义
#define MAX_BOOKS 1000      // 最大图书数量
#define MAX_READERS 500     // 最大读者数量
#define MAX_NAME_LEN 50     // 最大名称长度
#define MAX_ISBN_LEN 20     // ISBN号最大长度

// 图书结构体：用于存储图书的基本信息
typedef struct {
    char isbn[MAX_ISBN_LEN];        // ISBN号，图书的唯一标识
    char title[MAX_NAME_LEN];       // 图书名称
    char author[MAX_NAME_LEN];      // 作者名称
    int total_count;                // 总藏书量：图书馆该书籍的总数量
    int available_count;            // 可借数量：当前可供借阅的数量
} Book;

// 读者结构体：用于存储读者的基本信息
typedef struct {
    int id;                         // 读者ID，唯一标识
    char name[MAX_NAME_LEN];        // 读者姓名
    char phone[20];                 // 联系电话
    int borrowed_count;             // 已借书数量：当前已借阅的图书数量
} Reader;

// 借阅记录结构体：用于记录借阅信息
typedef struct {
    int reader_id;                  // 借阅者ID
    char isbn[MAX_ISBN_LEN];        // 借阅图书ISBN
    time_t borrow_date;             // 借阅日期
    time_t return_date;             // 归还日期
    int is_returned;                // 是否已归还：0-未归还，1-已归还
} BorrowRecord;

#endif
