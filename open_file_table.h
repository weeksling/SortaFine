#ifndef OPEN_FILE_TABLE_GUARD
#define OPEN_FILE_TABLE_GUARD
extern int
 set_refrence_count(int fd, int ref);
	// get_block
	// put_block
extern int
 get_refrence_count(int fd, int* ref_buf);
	// get_block

extern int
 set_fd(int loc);
	// get_block
	// put_block

extern int
 get_fd(int fd);
	// get_block

extern int
 close_fd(int fd);
 #endif