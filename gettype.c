int sfs_gettype(char* pathname){
	int* intBuff = NULL;
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
	
	error_check = get_inod(*loc, intBuff);
	return(buff[0]); //File type stored in first location. 

	release(pntStr);
	release(pntEnd);
	release(store);
	release(loc);
}
