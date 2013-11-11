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


void get_file(void);


// Global Variables //
short int* super_blk_buf = NULL;
int* disk_bitmap = NULL;
char* buff = NULL;


// Function Definitions //
void put_file(int file_type, char* name){
	int space = get_empty_blk();
	int** I_node_buff = get_inode_table();


} // Not finished yet!
	// get_empty_blk
	// put_inode_table
	// put_block
void get_file(void);
	// get_block
