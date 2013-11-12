//super_block.c
//Sortafine Industries
//Compile with: gcc -Wall -std=c99 open_file.c -lm blockio.c
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "blockio.h"
#define BUFFER_SIZE 512
#define BITMAP_BUFF 512
#define FD_SIZE 4

// Function Declarations //
int set_refrence_count(int fd, int ref);
	// get_block
	// put_block
int get_refrence_count(int fd, int* ref_buf);
	// get_block

int set_fd(int loc);
	// get_block
	// put_block

int get_fd(int fd);
	// get_block

int close_fd(int fd);


// Global Variables //
short int* super_blk_buf = NULL;
int* disk_bitmap = NULL;
int* reference_count=NULL;
int* fd_table=NULL;
char* buff = NULL;


// Function Definitions //
int set_fd(int loc){
	for (int check=0; check<FD_SIZE; check++){
		if (fd_table[check]==0){
			fd_table[check]=loc;
			return check;
		}
	}
	return -1;
}

int get_fd (int fd){
	if (fd_table[fd]==0){
		return -1;
	}
	else return fd_table[fd];
}

int close_fd(int fd){
	if (fd_table[fd]==0){
		return -1;
	} else {
		if (reference_count[fd]>1){
			reference_count[fd]--;
			return 1;
		}
		else{
			reference_count[fd]--;
			fd_table[fd]=0;
			return 1;
		}
	}
}

int set_refrence_count(int fd, int ref){
	if (ref>=0){
		reference_count[fd] = ref;
		return 1;
	} 
	return -1;
}
	// get_block
	// put_block
int get_reference_count(int fd, int* ref_buf){
	*ref_buf=reference_count[fd];
	return 1;
}