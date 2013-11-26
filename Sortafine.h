#ifndef Sortafine_Guard
#define Sortafine_Guard

int sfs_read(int fd, int start, int length, char* mem_pointer);
int sfs_write(int fd, int start, int length, char* mem_pointer);
int sfs_open(char* pathname);
int sfs_close(int fd);
int sfs_create(char* pathname, int type);
int sfs_delete(char* pathname);
int sfs_initilize(int erase);

#endif