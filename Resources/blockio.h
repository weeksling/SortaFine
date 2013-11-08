#ifndef BLOCKIO_H_GUARD
#define BLOCKIO_H_GUARD
extern int
get_block(int blknum,    /* which disk block to retrieve */
	  char *buf);    /* where in memory to put retrieved data */

extern int
put_block(int blknum,    /* which disk block to update */
	  char *buf);    /* where in memory to get new disk block contents */
#endif