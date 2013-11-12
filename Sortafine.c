//Sortafine.c
//Sortafine Industries
#include "blockio.h"
#include "open_file_table.h"
#include "I_node.h"
#include <string.h>
#include <stdlib.h>
#include <malloc.h>
#include <stdio.h>

int error_check = 0;
char* buff = NULL;
int* count = NULL;

void sfs_read(int fd, int start, int length, char* mem_pointer);
void sfs_write(int fd, int start, int length, char* mem_pointer);
void sfs_open(char* pathname);
void sfs_close(int fd);
void sfs_create(char* pathname);
void sfs_delete(char* pathname);
void sfs_initilize(int erase);



void sfs_read(int fd, int start, int length, char* mem_pointer){

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

	get_block(11, buff);
	char* pntStr = strstr(buff, pathname);
	if(pntStr == NULL){
		printf("FILE NOT FOUND");
		return;
	}
	int length = sizeof(pathname)/sizeof(char);
	pntStr+=length;
	char* pntEnd = strstr(buff, "\n");
	char* store = NULL;
	strncpy(store, pntStr, pntEnd-pntStr);
	int* loc = (int) store;
	//
	set_fd(loc);

	///////////////////////////////////////////////////////////
	
	error_check = get_reference_count(fd, count);
	if(error_check==-1){
		printf("There was a problem getting refrence count.\n");
	}
	error_check = set_reference_count(fd, *count+1);
	if(error_check==-1){
		printf("There was a problem setting reference count\n", );
	}
	///////////////////////////////////////////////////////////
	//set_fd();
	///////////////////////////////////////////////////////////
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
	get_fd();
	////////////////////////////////////////////////////
	error_check = get_reference_count(fd, count);
	if(error_check==-1){
		printf("There was a problem getting refrence count.\n");
	}
	error_check = set_reference_count(fd, *count-1);
	if(error_check==-1){
		printf("There was a problem setting reference count\n", );
	}
	////////////////////////////////////////////////////
	set_fd();
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
void sfs_initilize(int erase){
	if(erase==1){
		error_check=release_allblocks_fromfiles();
		if(error_check==-1){
			printf("Error freeing memory.\n");
		}
	}
	error_check = get_super_blk();
	if(error_check==-1){
		printf("Error in get super blk\n");
	}
	error_check=put_super_blk();
	if(error_check==-1){
		printf("Error in putting super_blk back\n");
	}
	error_check = get_inode_table();
	if(error_check==-1){
		printf("Error in geting inode table.\n");
	}
	error_check = put_inode_table();
	if(error_check== -1){
		printf("Error in putting the inode table.\n");
	}
}
	/*	get_inode_table
		get_super_blk
		put_block
		put_inode_table
		put_super_blk*/