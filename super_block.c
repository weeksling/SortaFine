//super_block.c
//Sortafine Industries
//Compile with: gcc -Wall -std=c99 super_block.c -lm blockio.c
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "blockio.h"
#define BUFFER_SIZE 512
#define BITMAP_BUFF 512

// Function Declarations //
int put_file(int file_type, char* name);

int set_refrence_count(int fd, int ref);
	// get_block
	// put_block
int get_refrence_count(int fd, int* ref_buf);
	// get_block

void get_file(void);

void set_fd(void);
	// get_block
	// put_block

void get_fd(void);
	// get_block

// Global Variables //
short int* super_blk_buf = NULL;
int* disk_bitmap = NULL;
int* reference_count=NULL;
int* fd_table=NULL;
char* buff = NULL;


// Function Definitions //

int set_refrence_count(int fd, int ref){
	reference_count[fd] = ref;
}
	// get_block
	// put_block
int get_reference_count(int fd, int* ref_buf){
	&ref_buf=referenc_count[fd];
}
int put_file(int file_type, char* name){
	int space = get_empty_blk();
	int** I_node_buff = get_inode_table();
	int** 
} // Not finished yet!
	// get_empty_blk
	// put_inode_table
	// put_block
int get_file(void){

	return -1;
}
	// get_block
