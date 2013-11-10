//I_node.c
//Sortafine Industries
#include "blockio.h"
#include <string.h>
#include <stdlib.h>
#include <malloc.h>

// Common Values //
#define BLOCKS 8
#define COMPONENTS 64
#define I_NODE_START 2
#define FILE_POINTER 10
#define BUFFER_SIZE 1024

// Function Declarations //
void get_fd(void);
	// get_block
void get_file(void);
	// get_block
int get_file_pointer(int i_number, int* file_ptr);
	// get_block
void get_inode_table(void);
	// get_block
void get_refrence_count(void);
	// get_block
void get_super_blk(void);
	// get_block
void put_file(void);
	// get_empty_blk
	// put_inode_table
	// put_block
int put_inode_table(void);
	// put_block
void set_fd(void);
	// get_block
	// put_block
void set_file_pointer(void);
	// get_block
	// put_block
void set_refrence_count(void);
	// get_block
	// put_block
int compare_component_tobuff(char *comp, char *buff);

// Global Variables //
int i_node_table[BLOCKS][COMPONENTS]; 
char* buff=NULL;
int* file_pointer=NULL;

// Function Definitions //
int main (){
	buff=(char*)calloc(BUFFER_SIZE,sizeof(char));
	file_pointer=(int*)calloc(64,COMPONENTS*sizeof(int));
}
int compare_component_tobuff(char *comp, char *buff){
	return strcmp(comp,buff);
}

int put_inode_table(){
	for (int file=0; file<BLOCKS; file++){
		buff=(char*)i_node_table;
		put_block(I_NODE_START+file, buff);
	}
}

int get_file_pointer(int i_number, int* file_ptr){
	// file_pointer is the 10th block
	get_block(FILE_POINTER, (char*)file_ptr);
	/*int* temp = (int*) buff;
	file_ptr = temp[i_number];
	free(temp);*/
	return 1;
}