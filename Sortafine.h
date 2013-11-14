#ifndef Sortafine_Guard
#define Sortafine_Guard

void sfs_read(int fd, int start, int length, char* mem_pointer);
void sfs_write(int fd, int start, int length, char* mem_pointer);
void sfs_open(char* pathname);
void sfs_close(int fd);
void sfs_create(char* pathname);
void sfs_delete(char* pathname);
void sfs_initilize(int erase);

#endif