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
int put_file_pointer(void);
	//put_block
int get_inode_table(int** table);
	// get_block
int put_inode_table(void);
	// put_block
void get_file(void);
	// get_block	
int get_empty_inode(void);

int set_inode(int wrekd,int* new_inode);

int add_inode(int* new_inode);

// Global Variables //
int** i_node_table=NULL; 
char* buffer=NULL;
int** file_pointer=NULL;

// Function Definitions //
/*int main (void){
	buffer=(char*)calloc(BUFFER_SIZE,sizeof(char));
	file_pointer=(int**)calloc(COMPONENTS,sizeof(int*));
	i_node_table=(int**)calloc(BLOCKS, COMPONENTS*sizeof(int));
}*/

int inode_initialize(int erase){
	//#ifndef 
	buffer=(char*)calloc(BUFFER_SIZE, sizeof(char));
	file_pointer=(int**)calloc(COMPONENTS, sizeof(int*));
	i_node_table=(int**)calloc (BLOCKS, COMPONENTS*sizeof(int));
	if(erase == 1){
		for (int block=0; block<BLOCKS; block++)
			for (int comp=0; comp<COMPONENTS; comp++)
				i_node_table[block][comp]=0;
		put_inode_table();
		for (int file=0;file<COMPONENTS;file++)
			set_file_pointer(file, 0);
	}
	get_inode_table(i_node_table);
	for (int comp=0; comp<COMPONENTS;comp++)
		get_file_pointer(comp, file_pointer[comp]);
	return 0;
}

int set_file_pointer(int i_number, int* file_ptr){
	file_pointer[i_number]=file_ptr;
	put_file_pointer();
	return 0;
}


int get_file_pointer(int i_number, int* file_ptr){
	// file_pointer is the 10th block
	get_block(FILE_POINTER, (char*)buffer);
	int** temp = (int**) buffer;
	file_ptr = (int*)temp[i_number];
	free(temp);
	return 0;
}

int put_file_pointer(){
	put_block(FILE_POINTER, (char*)file_pointer);
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

int get_inode(int i_num, int* table){
	for (int node=0; node<BLOCKS; node++){
		table[node]=i_node_table[i_num][node];
	}
	return 0;
}

int put_inode_table(){
	for (int file=0; file<BLOCKS; file++){
		strcpy(buffer,(char*)i_node_table[file]);
		put_block(I_NODE_START+file, buffer);
	}
	return 0;
}

int get_empty_inode(){
        for(int e = 0; e <COMPONENTS; e++)
        {        
        	if(i_node_table[e][0]==0){
        		return e;
        	}
        }
        return -1;
}

int set_inode(int i_num,int* new_inode){
	i_node_table[i_num] = new_inode;
	return 0;
}

int add_inode(int* new_inode){
	int temp_loc = get_empty_inode();
	if(temp_loc<0){
		return -1;
	}
	i_node_table[temp_loc] = new_inode;
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

