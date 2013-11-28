int parse_directory(char* pathname) {

	char tempName[10] = strtok(pathname, "/");
	int curr_i_number = DATA_START;

	while(tempName != NULL) {
		get_block(curr_i_number, sfs_buff);
		char* pntStr = strstr(sfs_buff, tempName);
		if(pntStr == NULL){
			printf("FILE NOT FOUND");
			return -1;
		}
		int length = sizeof(tempName)/sizeof(char);
		pntStr+=length;
		char* pntEnd = strstr(pntStr, "\n");
		char* store = calloc(1,sizeof(sfs_buff));
		strncpy(store, pntStr, pntEnd-pntStr);
		curr_i_number = (int*) store;

		tempName = strtok(pathname, "/");
	}

}