//I_node.c
//Sortafine Industries
#include "blockio.h"
#include <string.h>
#include <stdlib.h>
#include <malloc.h>
#include <stdio.h>

// Common Values //
#define BLOCKS 8
#define COMPONENTS 64
#define I_NODE_START 2
#define FILE_POINTER 10
#define BUFFER_SIZE 1024

// Function Declarations //
int set_file_pointer(int i_number, int* file_ptr);
	// get_block
	// put_block
int get_file_pointer(int i_number, int* file_ptr);
	// get_block
int get_inode_table(int** table);
	// get_block
int put_inode_table(void);
	// put_block
void get_fd(void);
	// get_block
void get_file(void);
	// get_block
void get_refrence_count(void);
	// get_block
void set_fd(void);
	// get_block
	// put_block
void set_refrence_count(void);
	// get_block
	// put_block

// Global Variables //
int** i_node_table=NULL; 
char* buffer=NULL;
int** file_pointer=NULL;

// Function Definitions //
int main (void){
	buffer=(char*)calloc(BUFFER_SIZE,sizeof(char));
	file_pointer=(int**)calloc(COMPONENTS,sizeof(int*));
	i_node_table=(int**)calloc(BLOCKS, COMPONENTS*sizeof(int));
}

int set_file_pointer(int i_number, int* file_ptr){
	put_block(FILE_POINTER+i_number, (char*)file_ptr);
	return 0;
}


int get_file_pointer(int i_number, int* file_ptr){
	// file_pointer is the 10th block
	get_block(FILE_POINTER, (char*)buffer);
	int** temp = (int**) buffer;
	file_ptr = temp[i_number];
	free(temp);
	return 0;
}

int get_inode_table(int** table){
	for (int file=0;file<BLOCKS; file++){
		get_block(I_NODE_START+file, buffer);
		i_node_table[file]=(int*)buffer;
	}
	table = i_node_table;
	return 0;
}

int put_inode_table(){
	for (int file=0; file<BLOCKS; file++){
		strcpy(buffer,(char*)i_node_table);
		put_block(I_NODE_START+file, buffer);
	}
	return 0;
}

/**
*Structure of I_Node table will be:
*BLOCK 2:
*Location
*Block 3:
*size
*Block 4:
*ref_count
*Block 5:
*
*Block 6:
*
*Block 7:
*
*Block 8:
*
*Block 9:
**/

