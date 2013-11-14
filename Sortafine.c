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

void sfs_read(int fd, int start, int length, char* mem_pointer);
void sfs_write(int fd, int start, int length, char* mem_pointer);
void sfs_open(char* pathname);
void sfs_close(int fd);
void sfs_create(char* pathname);
void sfs_delete(char* pathname);
void sfs_initilize(int erase);


int main (void){
	return 0;
}

void sfs_read(int fd, int start, int length, char* mem_pointer){
//Make sure the fetching is correct
        int i_number = get_fd(fd);
        //int* node_buff = NULL;
        int* size = NULL; 
        int* i_node = NULL;
        int to_read = 0;
        int current;
        int buff_length=0; // WUT??? this never got defined... like ever... dude... I'm so high.. this is fun. kk bai put a sloth
        int position = 0;
        sfs_buff = calloc(BUFFER_SIZE, sizeof(char*));

        if (i_number < 0) {
                return;
        }

        get_file_pointer(i_number, size);
        get_inode(i_number, i_node);

        while(start > BLOCK_SIZE) {
                start = start - BLOCK_SIZE;
                to_read++;
        }

        do {
                current = start;
                get_block(i_node[to_read], sfs_buff);
                length = sizeof(sfs_buff)/sizeof(char*);
                while(current <= start+length || current <= buff_length) {
                        mem_pointer[position] = sfs_buff[current];
                        current++;
                        position++;
                }
                start = 0;
        } while(position <= length);
}
	/*	get_inode_table
		get_fd
		get_file
		get_file_pointer*/
void sfs_write(int fd, int start, int length, char* mem_pointer){

}
	/*	get_file_pointer
		get_inode_table
		get_fd
		get_file
		set_file_pointer
		put_file*/
void sfs_open(char* pathname){

	get_block(DATA_START, sfs_buff);
	char* pntStr = strstr(sfs_buff, pathname);
	if(pntStr == NULL){
		printf("FILE NOT FOUND");
		return;
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
		return;
	}
	///////////////////////////////////////////////////////////
	
	error_check = get_reference_count(fd, count);
	if(error_check==-1){
		printf("There was a problem getting refrence count.\n");
	}
	error_check = set_reference_count(fd, *count+1);
	if(error_check==-1){
		printf("There was a problem setting reference count\n");
	}
}
	/*	get_reference_count
		get_inode_table
		compare_component_tobuff
		get_file_pointer
		get_file
		set_reference_count
		set_fd*/
void sfs_close(int fd){
	////////////////////////////////////////////////////
	error_check = close_fd(fd);
	if (error_check<0){
		printf("There is not file %d open currently\n",fd);
	}
	////////////////////////////////////////////////////
}
	/*	get_fd
		get_reference_count
		set_fd
		set_reference_count*/
void sfs_create(char* pathname){

}
	/*	get_inode_table
		compare_component_tobuff
		get_file_pointer
		get_file
		set_file_pointer
		get_empty_blk
		put_inode_table*/
void sfs_delete(char* pathname){

}
	/*	get_inode_table
		get_file_pointer
		compare_component_tobuff
		get_file
		get_reference_count
		set_file_pointer
		release_allblocks_fromfiles
		put_file*/
void sfs_initialize(int erase){
	int* i_node_buff = calloc(BLOCKS, sizeof(int));
	if(erase==1){
		error_check=release_allblocks_fromfile();
		if(error_check==-1){
			printf("Error freeing memory in disk_bitmap.\n");
		}
		error_check=inode_initialize(1);

	}
	error_check = get_super_blk();
	if(error_check==-1){
		printf("Error in get super blk\n");
	}
	error_check=put_super_blk();
	if(error_check==-1){
		printf("Error in putting super_blk back\n");
	}
	free(i_node_buff);
//<<<<<<< Updated upstream
}

int sfs_exist(char* pathname){
	get_block(11, sfs_buff);
	char* pntStr = strstr(sfs_buff, pathname);
	if(pntStr == NULL){
		return 0;
	}else{
		return 1;
	}
	return -1;
//=======
//>>>>>>> Stashed changes
}
	/*	get_inode_table
		get_super_blk
		put_block
		put_inode_table
		put_super_blk*/