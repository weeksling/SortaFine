#ifndef BITMAP_GUARD
#define BITMAP_GUARD
extern int
 release_allblocks_fromfile(void);
extern int
 release_block(int blk_num);
extern int
 get_empty_blk(int* freeblk);
extern int
 get_super_blk(void);
extern int
 put_super_blk(void);
 #endif