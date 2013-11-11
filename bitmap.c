// Compile with: gcc -Wall -std=c99 bitmap.c -lm blockio.c

#include <math.h>
#include "blockio.h"
#include <stdio.h>
#include <stdlib.h>
#define BUFFER_SIZE 512
#define BITMAP_BUFF 512
#define ROOT_DIR 11

int release_allblocks_fromfile(void);
int release_block(int blk_num);
int get_empty_blk(int* freeblk);
int get_super_blk(void);
int put_super_blk(void);

// Global Variables //
short int* super_blk_buf = NULL;
int* disk_bitmap = NULL;
char* buff = NULL;

int release_allblocks_fromfile(void){
	// release_block
	// put_inode_table
	if (disk_bitmap == NULL) {
		return -1;
	}
	int length = sizeof(disk_bitmap)/sizeof(int);
	for (int i=0; i<length; i++) {
		disk_bitmap[i] = 0;
	}
	return 0;
}
int release_block(int blk_num){
	// get_super_blk
	// put_super_blk
	if (disk_bitmap == NULL) {
		return -1;
	}
	disk_bitmap[blk_num] = 0;
	return 0;
}
int get_empty_blk(int* freeblk){
	for (int e = 11; e < BITMAP_BUFF; e+4)
	{	
		if(disk_bitmap[blk_num] == NULL){
			return -1;
		}
		if(disk_bitmap[blk_num] == 0){
			freeblk = e;
			return 1;
			break;
			}
		}
		return -1;
	}
	return 0;
}
int get_super_blk(void){
	//super_blk_buf = (short int*) calloc(BUFFER, sizeof(short int));
	disk_bitmap = (int*) calloc(BITMAP_BUFF, sizeof(int));
	buff = (char*) calloc(BUFFER_SIZE, sizeof(char));

	int bitmap_pos = 0;
	int current = 0;
	int length = sizeof(super_blk_buf)/sizeof(short int);

	for(int a=0; a<=1; a++) {
		int result = get_block(a, buff);
		super_blk_buf = (short int*) buff;
		
		if (result < 0) {
			return -1;
		}

		for(int i=0; i<length; i++) {
			current = super_blk_buf[i];
			for(int j=3; j>=0; j--) {
				if (current >= pow(2,j)) {
					disk_bitmap[bitmap_pos] = 1;
					current = current - pow(2.0,(double)j);
				} else {
					disk_bitmap[bitmap_pos] = 0;
				}
				bitmap_pos++;
			}
		}
	}
	return 0;
}

int put_super_blk(void){
	//Encode each 4 locations of diskbitmap[512] into an integer and puts
	// it in super_blk_buf[128]
	// Puts super_blk_buf[128] into the super-block
	char* buff = NULL;
	buff = (char*) calloc(BUFFER_SIZE, sizeof(char));

	int bitmap_pos = 0;
	int current = 0;
	int length = sizeof(super_blk_buf)/sizeof(short int);
	int toWrite = 0;

	for (int a=0; a<=1; a++) {
		int result = get_block(a, buff);
		super_blk_buf = (short int*) buff;

		if (result < 0) {
			return -1;
		}

		for(int i=0; i<length; i++) {
			current = disk_bitmap[i];

			
		}
	}
	return 0;
}