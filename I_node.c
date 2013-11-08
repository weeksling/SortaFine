//I_node.c
//Sortafine Industries
#include <blockio.h>
#include <string.h>

// Common Values //
#define BLOCKS 8
#define COMPONENTS 64
#define I_NODE_START 2
#define FILE_POINTER 10


// Global Variables //
int i_node_table[BLOCKS][COMPONENTS]; 
char* buff=(char*)calloc(1024*sizeof(char));
int* file_pointer=(char*)calloc(COMPONENTS*sizeof(int));

// Function Declarations //
get_fd(void);
	// get_block
get_file(void);
	// get_block
get_file_pointer(int i_number, int* file_ptr);
	// get_block
get_inode_table(void);
	// get_block
get_refrence_count(void);
	// get_block
get_super_blk(void);
	// get_block
put_file(void);
	// get_empty_blk
	// put_inode_table
	// put_block
put_inode_table(void);
	// put_block
set_fd(void);
	// get_block
	// put_block
set_file_pointer(void);
	// get_block
	// put_block
set_refrence_count(void);
	// get_block
	// put_block
int compare_component_tobuff(char *comp, char *buff);

// Function Definitions //
int compare_component_tobuff(char *comp, char *buff){
	return strncmp(comp,buff);
}

int put_inode_table(){
	for (int file=0; i<BLOCKS; i++){
		put_block(I_NODE_START+i, i_node_table[i]);
	}
}

int get_file_pointer(int i_number, int* file_ptr){
	// file_pointer is the 10th block
	get_block(FILE_POINTER, buff);
	file_ptr=(int)file_pointer[i_number];
	return file_ptr;
}