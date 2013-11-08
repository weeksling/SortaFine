//Sortafine.c
//Sortafine Industries
#include blockio.h

void sfs_read(int fd, int start, int length, char* mem_pointer)
	/*	get_inode_table
		get_fd
		get_file
		get_file_pointer*/
void sfs_write(int fd, int start, int length, char* mem_pointer)
	/*	get_file_pointer
		get_inode_table
		get_fd
		get_file
		set_file_pointer
		put_file*/
void sfs_open(char* pathname)
	/*	get_reference_count
		get_inode_table
		compare_component_tobuff
		get_file_pointer
		get_file
		set_reference_count
		set_fd*/
void sfs_close(int fd)
	/*	get_fd
		get_reference_count
		set_fd
		set_reference_count*/
void sfs_create(char* pathname)
	/*	get_inode_table
		compare_component_tobuff
		get_file_pointer
		get_file
		set_file_pointer
		get_empty_blk
		put_inode_table*/
void sfs_delete(char* pathname)
	/*	get_inode_table
		get_file_pointer
		compare_component_tobuff
		get_file
		get_reference_count
		set_file_pointer
		release_allblocks_fromfiles
		put_file*/
void sfs_initilize(int erase)
	/*	get_inode_table
		get_super_blk
		put_block
		put_inode_table
		put_super_blk*/