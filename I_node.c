//I_node.c
//Sortafine Industries
#include blockio.h

compare_component_tobuff
	
get_empty_blk
	// dependant on put_super_blk
	// dependant on get_super_blk
get_fd
	// dependant on get_block
get_file
	// dependant on get_block
get_file_pointer
	// get_block
get_inode_table
	// get_block
get_refrence_count
	// get_block
get_super_blk
	// get_block
put_file
	// get_empty_blk
	// put_inode_table
	// put_block
put_inode_table
	// put_block
put_super_blk
	// put_block
release_allblocks_fromfile
	// release_block
	// put_inode_table
release_block
	// get_super_blk
	// put_super_blk
set_fd
	// get_block
	// put_block
set_file_pointer
	// get_block
	// put_block
set_refrence_count
	// get_block
	// put_block
