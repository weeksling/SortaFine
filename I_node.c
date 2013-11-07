//I_node.c
//Sortafine Industries
#include blockio.h

#define BLOCKS 8
#define COMPONENTS 64

// 
int* i_node_table[8][64]; 

get_empty_blk(void)
	// dependant on put_super_blk
	// dependant on get_super_blk
get_fd(void)
	// dependant on get_block
get_file(void)
	// dependant on get_block
get_file_pointer(void)
	// get_block
get_inode_table(void)
	// get_block
get_refrence_count(void)
	// get_block
get_super_blk(void)
	// get_block
put_file(void)
	// get_empty_blk
	// put_inode_table
	// put_block
put_inode_table(void)
	// put_block
put_super_blk(void)
	// put_block
release_allblocks_fromfile(void)
	// release_block
	// put_inode_table
release_block(void)
	// get_super_blk
	// put_super_blk
set_fd(void)
	// get_block
	// put_block
set_file_pointer(void)
	// get_block
	// put_block
set_refrence_count(void)
	// get_block
	// put_block

compare_component_tobuff(void);