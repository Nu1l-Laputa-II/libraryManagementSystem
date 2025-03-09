# 图书管理系统 API 文档

## 目录
- [数据结构](#数据结构)
- [图书管理模块](#图书管理模块)
- [读者管理模块](#读者管理模块)
- [错误处理](#错误处理)
- [使用示例](#使用示例)

## 数据结构

### 图书结构体 (Book)
```c
typedef struct {
    char isbn[MAX_ISBN_LEN];     // ISBN号，图书的唯一标识
    char title[MAX_NAME_LEN];    // 图书名称
    char author[MAX_NAME_LEN];   // 作者名称
    int total_count;             // 总藏书量
    int available_count;         // 可借数量
} Book;
```

### 读者结构体 (Reader)
```c
typedef struct {
    int id;                      // 读者ID
    char name[MAX_NAME_LEN];     // 读者姓名
    char phone[20];              // 联系电话
    int borrowed_count;          // 已借书数量
} Reader;
```

### 系统常量
```c
#define MAX_BOOKS 1000           // 最大图书数量
#define MAX_READERS 500          // 最大读者数量
#define MAX_NAME_LEN 50          // 最大名称长度
#define MAX_ISBN_LEN 20          // ISBN号最大长度
```

## 图书管理模块

### addBook
添加新图书到系统
```c
int addBook(Book *books, int *book_count, Book new_book);
```
- 参数
  - `books`: 图书数组
  - `book_count`: 当前图书总数指针
  - `new_book`: 要添加的新图书
- 返回值
  - 成功返回1
  - 失败返回0
- 错误情况
  - 系统图书数量已达上限
  - 图书ISBN已存在（此时会更新库存）

### removeBook
从系统中删除指定图书
```c
int removeBook(Book *books, int *book_count, const char *isbn);
```
- 参数
  - `books`: 图书数组
  - `book_count`: 当前图书总数指针
  - `isbn`: 要删除的图书ISBN
- 返回值
  - 成功返回1
  - 失败返回0
- 错误情况
  - 图书不存在

### findBook
查找指定ISBN的图书
```c
Book* findBook(Book *books, int book_count, const char *isbn);
```
- 参数
  - `books`: 图书数组
  - `book_count`: 当前图书总数
  - `isbn`: 要查找的图书ISBN
- 返回值
  - 成功返回图书指针
  - 失败返回NULL

### listAllBooks
显示所有图书信息
```c
void listAllBooks(Book *books, int book_count);
```
- 参数
  - `books`: 图书数组
  - `book_count`: 当前图书总数

### saveBooks
将图书信息保存到文件
```c
int saveBooks(Book *books, int book_count);
```
- 参数
  - `books`: 图书数组
  - `book_count`: 当前图书总数
- 返回值
  - 成功返回1
  - 失败返回0

### loadBooks
从文件加载图书信息
```c
int loadBooks(Book *books, int *book_count);
```
- 参数
  - `books`: 图书数组
  - `book_count`: 当前图书总数指针
- 返回值
  - 成功返回1
  - 失败返回0

## 读者管理模块

### addReader
添加新读者到系统
```c
int addReader(Reader *readers, int *reader_count, Reader new_reader);
```
- 参数
  - `readers`: 读者数组
  - `reader_count`: 当前读者总数指针
  - `new_reader`: 要添加的新读者
- 返回值
  - 成功返回1
  - 失败返回0
- 错误情况
  - 系统读者数量已达上限
  - 读者ID已存在

### removeReader
从系统中删除指定读者
```c
int removeReader(Reader *readers, int *reader_count, int id);
```
- 参数
  - `readers`: 读者数组
  - `reader_count`: 当前读者总数指针
  - `id`: 要删除的读者ID
- 返回值
  - 成功返回1
  - 失败返回0
- 错误情况
  - 读者不存在

### findReader
查找指定ID的读者
```c
Reader* findReader(Reader *readers, int reader_count, int id);
```
- 参数
  - `readers`: 读者数组
  - `reader_count`: 当前读者总数
  - `id`: 要查找的读者ID
- 返回值
  - 成功返回读者指针
  - 失败返回NULL

### listAllReaders
显示所有读者信息
```c
void listAllReaders(Reader *readers, int reader_count);
```
- 参数
  - `readers`: 读者数组
  - `reader_count`: 当前读者总数

### saveReaders
将读者信息保存到文件
```c
int saveReaders(Reader *readers, int reader_count);
```
- 参数
  - `readers`: 读者数组
  - `reader_count`: 当前读者总数
- 返回值
  - 成功返回1
  - 失败返回0

### loadReaders
从文件加载读者信息
```c
int loadReaders(Reader *readers, int *reader_count);
```
- 参数
  - `readers`: 读者数组
  - `reader_count`: 当前读者总数指针
- 返回值
  - 成功返回1
  - 失败返回0

## 错误处理

所有返回整数的函数都使用以下约定：
- 成功操作返回1
- 失败操作返回0

查找类函数使用以下约定：
- 找到目标返回指针
- 未找到返回NULL

## 使用示例

### 图书管理示例
```c
// 添加新图书
Book new_book = {
    .isbn = "9787111111111",
    .title = "C程序设计",
    .author = "张三",
    .total_count = 5,
    .available_count = 5
};
if (addBook(books, &book_count, new_book)) {
    printf("图书添加成功\n");
}

// 查找图书
Book* book = findBook(books, book_count, "9787111111111");
if (book) {
    printf("找到图书：%s\n", book->title);
}
```

### 读者管理示例
```c
// 添加新读者
Reader new_reader = {
    .id = 1001,
    .name = "李四",
    .phone = "13800138000",
    .borrowed_count = 0
};
if (addReader(readers, &reader_count, new_reader)) {
    printf("读者添加成功\n");
}

// 查找读者
Reader* reader = findReader(readers, reader_count, 1001);
if (reader) {
    printf("找到读者：%s\n", reader->name);
}
```
