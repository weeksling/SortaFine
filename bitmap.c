/** 
  * @author Adam Pacheco, Matthew Weeks, Blair Wiser
  * @version 0.1
  * @since 2013-11-11
  */
// Compile with: gcc -Wall -std=c99 bitmap.c -lm blockio.c I_node.c

#include <math.h>
#include "blockio.h"
#include "I_node.h"
#include <stdio.h>
#include <stdlib.h>

#define BUFFER_SIZE 512
#define BITMAP_BUFF 512
#define ROOT_DIR 11
#define BITMAP_LOC 0
#define CHECKSUM_LOC 1
#define DISK_SIZE 512
#define BLK_BUF_SIZE 128


int release_allblocks_fromfile(void);
int release_block(int blk_num);
int get_empty_blk(void);
int init_super_block(void);
int get_super_blk(void);
int put_super_blk(void);

// Global Variables //
short int* super_blk_buf = NULL;
int* disk_bitmap = NULL;
char* buff = NULL;

/** 
  * Set all entries of disk_bitmap to 0, marking them as free
  * @return 0 	if successful, -1 otherwise
  */

int release_allblocks_fromfile(void){
	// release_block
	if (disk_bitmap == NULL) {
		return -1;
	}
	for (int i=0; i<DISK_SIZE; i++) {
		disk_bitmap[i] = 0;
	}
	put_super_blk();
	return 0;
}

/** 
  * Set specified block in disk_bitmap to 0, marking it as free
  * @param blk_num 	the block number of the block to be freed
  * @return 0 		if successful, -1 otherwise
  */
int release_block(int blk_num){
	// get_super_blk
	// put_super_blk
	if (disk_bitmap == NULL) {
		return -1;
	}
	disk_bitmap[blk_num] = 0;
	return put_super_blk();
}

int init_super_block(){
	super_blk_buf=(short int*) calloc(BLK_BUF_SIZE, sizeof(int));
	disk_bitmap=(int*) calloc(DISK_SIZE, sizeof(int));
	int error_check=get_super_blk();
	if (error_check<0)
		return -1;
	return 0;
}

/** 
  * Find the next free block in disk_bitmap
  * @param freeblk 	pointer to integer where free block is stored in once it is found
  * @return 0 		if successful, -1 otherwise
  */
int get_empty_blk(void){
	for(int e = ROOT_DIR; e < BITMAP_BUFF; e++)
	{	
		if(disk_bitmap == NULL){
			return -1;
		}
		if(disk_bitmap[e] == 0){
			disk_bitmap[e]=1;
			return e;
		}
	}
	return -1;
}

/** 
  * Reads superblock from disk and initializes disk_bitmap
  * @return 0 	if successful, -1 otherwise
  * @Contributors Matthew Weeks
  */
int get_super_blk(void){
	printf("it tried to get super block\n");
	super_blk_buf = (short int*) calloc(DISK_SIZE, sizeof(short int));
	disk_bitmap = (int*) calloc(BITMAP_BUFF, sizeof(int));
	buff = (char*) calloc(BUFFER_SIZE, sizeof(char));

	/* Check that disk is not corrupted */
	int check=0;
	if (*buff!=check){
		printf("Checksum authentication failed!");
		return -1;
	}

	/* Get bitmap from disk */
	int bitmap_pos = 0;
	int current = 0;
	int result = get_block(BITMAP_LOC, buff);
	int error_check = get_block(CHECKSUM_LOC,buff);
	super_blk_buf = (short int*) buff;
	if (result < 0) {
		return -1;
	}

	for(int i=0; i<DISK_SIZE; i++) {
		current = super_blk_buf[i];
		for(int j=3; j>=0; j--) {
			if (current >= pow(2,j)) {
				disk_bitmap[bitmap_pos] = 1;
				current = current - pow(2,j);
			} else {
				disk_bitmap[bitmap_pos] = 0;
			}
			bitmap_pos++;
		}
	}
	for (int i=0; i<DISK_SIZE; i++){
		check += buff[i];
	}

	if(error_check<0){
		return -1;
	}

	free(buff);
	free(super_blk_buf);

	return 0;
}

/** 
  * Writes contents of disk_bitmap to the disk
  * @return 0 	if successful, -1 otherwise
  */
int put_super_blk(void){
	//Encode each 4 locations of diskbitmap[512] into an integer and puts
	// it in super_blk_buf[128]
	// Puts super_blk_buf[128] into the super-block
	char* buff = NULL;
	buff = (char*) calloc(BUFFER_SIZE, sizeof(char));

	int bitmap_pos = 0;
	int toWrite = 0;

	for(int i=0; i<BLK_BUF_SIZE; i++) {
		toWrite = 0;
		for(int j=3; j>=0; j--) {
			if(disk_bitmap[bitmap_pos] == 1) {
				toWrite = toWrite + pow(2,j);
			}
			bitmap_pos++;
		}
		super_blk_buf[i] = toWrite;
	}
	buff = (char*) super_blk_buf;

	int check=0;
	for (int i=0; i<DISK_SIZE; i++){
		check += disk_bitmap[i];
	}

	sprintf(buff,"%d",check);
	int error_check = put_block(CHECKSUM_LOC, buff);
	int result = put_block(BITMAP_LOC, buff);

	if (result < 0 || error_check<0) {
		return -1;
	}

	free(buff);
	return 0;
}