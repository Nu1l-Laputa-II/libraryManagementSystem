#include <stdio.h>
#include <string.h>
#include "reader_management.h"

int addReader(Reader *readers, int *reader_count, Reader new_reader) {
    if (*reader_count >= MAX_READERS) return 0;
    
    // Check if reader already exists
    for (int i = 0; i < *reader_count; i++) {
        if (readers[i].id == new_reader.id) return 0;
    }
    
    readers[*reader_count] = new_reader;
    (*reader_count)++;
    return 1;
}

int removeReader(Reader *readers, int *reader_count, int id) {
    for (int i = 0; i < *reader_count; i++) {
        if (readers[i].id == id) {
            for (int j = i; j < *reader_count - 1; j++) {
                readers[j] = readers[j + 1];
            }
            (*reader_count)--;
            return 1;
        }
    }
    return 0;
}

Reader* findReader(Reader *readers, int reader_count, int id) {
    for (int i = 0; i < reader_count; i++) {
        if (readers[i].id == id) {
            return &readers[i];
        }
    }
    return NULL;
}

void listAllReaders(Reader *readers, int reader_count) {
    printf("\n读者列表:\n");
    printf("%-10s %-20s %-15s %-10s\n", "ID", "姓名", "电话", "已借书数");
    for (int i = 0; i < reader_count; i++) {
        printf("%-10d %-20s %-15s %-10d\n",
               readers[i].id,
               readers[i].name,
               readers[i].phone,
               readers[i].borrowed_count);
    }
}

int saveReaders(Reader *readers, int reader_count) {
    FILE *file = fopen("readers.dat", "wb");
    if (!file) return 0;
    
    fwrite(&reader_count, sizeof(int), 1, file);
    fwrite(readers, sizeof(Reader), reader_count, file);
    fclose(file);
    return 1;
}

int loadReaders(Reader *readers, int *reader_count) {
    FILE *file = fopen("readers.dat", "rb");
    if (!file) return 0;
    
    fread(reader_count, sizeof(int), 1, file);
    fread(readers, sizeof(Reader), *reader_count, file);
    fclose(file);
    return 1;
}
