#ifndef READER_MANAGEMENT_H
#define READER_MANAGEMENT_H

#include "structures.h"

// 添加新读者到系统
// 参数：readers-读者数组，reader_count-当前读者总数，new_reader-要添加的新读者
// 返回：成功返回1，失败返回0
int addReader(Reader *readers, int *reader_count, Reader new_reader);

// 从系统中删除指定读者
// 参数：readers-读者数组，reader_count-当前读者总数，id-要删除的读者ID
// 返回：成功返回1，失败返回0
int removeReader(Reader *readers, int *reader_count, int id);

// 查找指定ID的读者
// 参数：readers-读者数组，reader_count-当前读者总数，id-要查找的读者ID
// 返回：成功返回读者指针，失败返回NULL
Reader* findReader(Reader *readers, int reader_count, int id);

// 显示所有读者信息
// 参数：readers-读者数组，reader_count-当前读者总数
void listAllReaders(Reader *readers, int reader_count);

// 将读者信息保存到文件
// 参数：readers-读者数组，reader_count-当前读者总数
// 返回：成功返回1，失败返回0
int saveReaders(Reader *readers, int reader_count);

// 从文件加载读者信息
// 参数：readers-读者数组，reader_count-当前读者总数指针
// 返回：成功返回1，失败返回0
int loadReaders(Reader *readers, int *reader_count);

#endif
