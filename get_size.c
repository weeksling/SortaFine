//get_size

//look at open or exists, 
//edit so rather than adding it takes inode, &size into get file pointer

int sfs_getsize(char* pathname) {
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

	int size = 0;
	int error = get_file_pointer(*loc, &size);
	if(error < 0) {
		return -1;
	}
	return size;
}