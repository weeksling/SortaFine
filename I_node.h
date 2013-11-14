#ifndef I_NODE_GUARD
#define I_NODE_GUARD

extern int
 inode_initialize(int erase);
extern int
 set_file_pointer(int i_number, int* file_ptr);
extern int
 get_file_pointer(int i_number, int* file_ptr);
extern int
 get_inode(int i_number, int* table);
extern int
 put_inode_table(void);
extern void
 get_file(void);

 #endif