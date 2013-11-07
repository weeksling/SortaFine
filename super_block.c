//super_block.c
//Sortafine Industries
#include blockio.h

int get_super_blk(void);

int put_super_blk(void);

int get_empty_blk(int* freeblk);

int release_block(int blk_num);

int release_allblocks_fromfile(void);

int release_allblocks_fromfile(void){
	// release_block
	// put_inode_table
}
int release_block(int blk_num){
	// get_super_blk
	// put_super_blk
}
int get_empty_blk(int* freeblk){
	// dependant on put_super_blk
	// dependant on get_super_blk
	// Returns the location of the found empty block
}
int get__super_blk(void){
	//Get super-block (blocks 0 and 1 of disk) as "short integer bytes" and
	// puts them in the super_blk_buf[128]

	// Decodes each integer (<15 & >0) in super_blk_buf[128] into 4
	// bits and puts them in disk_bitmap[512]
}

int put_super_blk(void){
	//Encode each 4 locations of diskbitmap[512] into an integer and puts
	// it in super_blk_buf[128]
	// Puts super_blk_buf[128] into the super-block
}