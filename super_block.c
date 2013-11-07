//super_block.c
//Sortafine Industries

int get_super_blk(void);

int put_super_blk(void);


int get__super_blk(void){
	//Encode each 4 locations of diskbitmap[512] into an integer and puts
	// it in super_blk_buf[128]
	// Puts super_blk_buf[128] into the super-block
}

int put_super_blk(void){
	//Get super-block (blocks 0 and 1 of disk) as "short integer bytes" and
	// puts them in the super_blk_buf[128]

	// Decodes each integer (<15 & >0) in super_blk_buf[128] into 4
	// bits and puts them in disk_bitmap[512]
}