//Sortafine.c
//Sortafine Industries
#include "blockio.h"
#include "open_file_table.h"
#include "bitmap.h"
#include "I_node.h"
#include <string.h>
#include <stdlib.h>
#include <malloc.h>
#include <stdio.h>


#define BLOCK_SIZE 128
#define BUFFER_SIZE 512

#define BLOCKS 8
#define COMPONENTS 64
#define DATA_START 11

int error_check = 0;
char* sfs_buff = NULL;
int* count = NULL;

int sfs_read(int fd, int start, int length, char* mem_pointer);
int sfs_write(int fd, int start, int length, char* mem_pointer);
int sfs_open(char* pathname);
int sfs_close(int fd);
int sfs_create(char* pathname, int type);
int sfs_delete(char* pathname);
int sfs_initilize(int erase);
int sfs_exists (char* pathname);


int main (void){
	return 0;
}

int sfs_read(int fd, int start, int length, char* mem_pointer){
//Make sure the fetching is correct
        int i_number = get_fd(fd);
        //int* node_buff = NULL;
        int* size = NULL; 
        int* i_node = NULL;
        int to_read = 0;
        int current;
        int position = 0;
        sfs_buff = calloc(BUFFER_SIZE, sizeof(char*));

        if (i_number < 0) {
                return -1;
        }

        get_file_pointer(i_number, size);
        get_inode(i_number, i_node);

        if (start < BLOCK_SIZE) {
       		 to_read = 0;
    	} else if (start < 2*BLOCK_SIZE) {
        	to_read = 1;
    	} else if (start < 3*BLOCK_SIZE) {
        	to_read = 2;
    	} else if (start < 4*BLOCK_SIZE) {
    	    to_read = 3;
    	} else if (start < 5*BLOCK_SIZE) {
    		to_read = 4;
    	} else if (start < 6*BLOCK_SIZE) {
    		to_read = 5;
    	} else if (start < 7*BLOCK_SIZE) {
    		to_read = 6;
    	} else if (start < 8*BLOCK_SIZE) {
    		to_read = 7;
    	}

        do {
            current = start;
            error_check=get_block(i_node[to_read], sfs_buff);
            if (error_check<0)
            	return -1;
            while(current <= start+length || current <= BLOCK_SIZE) {
                mem_pointer[position] = sfs_buff[current];
                current++;
                position++;
            }
            start = 0;
            to_read++;
        } while(position <= length);

        free(sfs_buff);
    	free(i_node);
    	free(size);
    	return 1;
}
	/*	get_inode_table
		get_fd
		get_file
		get_file_pointer*/
int sfs_write(int fd, int start, int length, char* mem_pointer){
	int i_number = get_fd(fd);
	int* i_node = NULL;
	int to_read;
	int* size = NULL;
	int current = 0;
	int position = 0;
	sfs_buff = calloc(BUFFER_SIZE, sizeof(char*));

	if (i_number < 0) {
		return -1;
	}

	get_inode(i_number, i_node);
	get_file_pointer(i_number, size);

	if (start < 0) {
		to_read = *size / BLOCK_SIZE;
	} else if (start < BLOCK_SIZE) {
        to_read = 0;
    } else if (start < 2*BLOCK_SIZE) {
        to_read = 1;
    } else if (start < 3*BLOCK_SIZE) {
        to_read = 2;
    } else if (start < 4*BLOCK_SIZE) {
        to_read = 3;
    } else if (start < 5*BLOCK_SIZE) {
    	to_read = 4;
    } else if (start < 6*BLOCK_SIZE) {
    	to_read = 5;
    } else if (start < 7*BLOCK_SIZE) {
    	to_read = 6;
    } else if (start < 8*BLOCK_SIZE) {
    	to_read = 7;
    }

    do {
    	error_check=get_block(i_node[to_read], sfs_buff);
    	if(error_check<0)
    		return -1;
    	if (start > 0) {
    		current = start; 
    	} else {
    		current = *size % BLOCK_SIZE +1;
    	}
    	while(current <= start+length || current <= BLOCK_SIZE) {
    		sfs_buff[current] = mem_pointer[position];
    		current++;
    		position++;
    	}
    	start = 0;
    	to_read++;
    } while(position <= length);

    free(sfs_buff);
    free(i_node);
    free(size);
    return 1;
}
	/*	get_file_pointer
		get_inode_table
		get_fd
		get_file
		set_file_pointer
		put_file*/
int sfs_open(char* pathname){

	get_block(DATA_START, sfs_buff);
	char* pntStr = strstr(sfs_buff, pathname);
	if(pntStr == NULL){
		printf("FILE NOT FOUND");
		return -1;
	}
	int length = sizeof(pathname)/sizeof(char);
	pntStr+=length;
	char* pntEnd = strstr(pntStr, "\n");
	char* store = calloc(1,sizeof(sfs_buff));
	strncpy(store, pntStr, pntEnd-pntStr);
	int* loc = (int*) store;
	//
	int fd = set_fd(*loc);
	if (fd < 0){
		printf("Could not open file!");
		return -1;
	}
	///////////////////////////////////////////////////////////
	
	error_check = get_reference_count(fd, count);
	if(error_check<0){
		printf("There was a problem getting refrence count.\n");
		return -1;
	}
	error_check = set_reference_count(fd, *count+1);
	if(error_check<0){
		printf("There was a problem setting reference count\n");
		return -1;
	}
	return 1;
}
	/*	get_reference_count
		get_inode_table
		compare_component_tobuff
		get_file_pointer
		get_file
		set_reference_count
		set_fd*/
int sfs_close(int fd){
	////////////////////////////////////////////////////
	error_check = close_fd(fd);
	if (error_check<0){
		printf("There is not file %d open currently\n",fd);
	}
	return 0;
	////////////////////////////////////////////////////
}
	/*	get_fd
		get_reference_count
		set_fd
		set_reference_count*/
int sfs_create(char* pathname, int type){
	sfs_buff = calloc(BUFFER_SIZE, sizeof(char*));
	int* location_blk;
	int* sfs_size;
	int i_number;
	error_check = sfs_exists(pathname);
	if (error_check<0){
		printf("Does not exist.\n");
		return -1;
	}
	error_check = get_empty_blk(location_blk);
	if (error_check<0){
		printf("No blocks free..\n");
		return -1;
	}
	i_number = add_inode(location_blk);
	error_check = get_file_pointer(0,sfs_size);
	if (error_check<0){
		printf("Error.\n");
		return -1;
	}
	error_check = get_block(DATA_START, sfs_buff);
	if (error_check<0){
		printf("Error.\n");
		return -1;
	}
	strcat(sfs_buff,pathname);
	strcat(sfs_buff," ");
	sprintf(sfs_buff+strlen(sfs_buff),"%d",i_number);
	strcat(sfs_buff,"\n");
	free(sfs_buff);
	free(sfs_size);
	free(location_blk);
	return 1;
}
	/*	get_inode_table
		compare_component_tobuff
		get_file_pointer
		get_file
		set_file_pointer
		get_empty_blk
		put_inode_table*/
int sfs_delete(char* pathname){
	sfs_buff = calloc(BUFFER_SIZE, sizeof(char*));
	int* sfs_size;
	int* sfs_table;
	char* newDir;
	error_check = sfs_exists(pathname);
	if (error_check<0){
		printf("Does not exist.\n");
		return -1;
	}
	//check to open first
	get_block(DATA_START, sfs_buff);
	char* pntStr = strstr(sfs_buff, pathname);
	if(pntStr == NULL){
		printf("FILE NOT FOUND");
		return -1;
	}
	int length = sizeof(pathname)/sizeof(char);
	pntStr+=length;
	char* pntEnd = strstr(pntStr, "\n");
	char* store = calloc(1,sizeof(sfs_buff));
	strncpy(store, pntStr, pntEnd-pntStr);
	int loc = (int) *store;
	error_check = get_inode(loc, sfs_table);
	for(int i=0; i<8;i++){
		if(sfs_table[i]!=0){
			error_check = release_block(sfs_table[i]);
			if(error_check<0)
				return -1;
		}
	}	
	delete_inode(loc);
	int temp_star = pntStr - sfs_buff;
	int temp_fin = pntEnd - sfs_buff;
	error_check = get_file_pointer(0,sfs_size);
	if (error_check<0){
		printf("Error.\n");
		return -1;
	}
	strncpy(newDir, sfs_buff, temp_star);
	strcat(newDir, pntEnd);
	put_block(11, newDir);
	free(sfs_size);
	free(sfs_table);
	free(pntStr);
	free(store);
	free(pntEnd);
	return 1;
}
	/*	get_inode_table
		get_file_pointer
		compare_component_tobuff
		get_file
		get_reference_count
		set_file_pointer
		release_allblocks_fromfiles
		put_file*/
int sfs_initialize(int erase){
	int* i_node_buff = calloc(BLOCKS, sizeof(int));
	if(erase==1){
		error_check=release_allblocks_fromfile();
		if(error_check==-1){
			printf("Error freeing memory in disk_bitmap.\n");
			return -1;
		}
		error_check=inode_initialize(1);
		if(error_check==-1){
			printf("Error initializing inode.\n");
			return -1;
		}
	}
	error_check = get_super_blk();
	if(error_check<0){
		printf("Error in get super blk\n");
		return -1;
	}
	error_check=put_super_blk();
	if(error_check<0){
		printf("Error in putting super_blk back\n");
		return -1;
	}
	free(i_node_buff);
	return 1;
}

int sfs_exists(char* pathname){
	get_block(11, sfs_buff);
	char* pntStr = strstr(sfs_buff, pathname);
	if(pntStr == NULL){
		return 0;
	}else{
		return 1;
	}
	return -1;
}
	/*	get_inode_table
		get_super_blk
		put_block
		put_inode_table
		put_super_blk*/
