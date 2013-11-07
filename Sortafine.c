//Sortafine.c
//Sortafine Industries

sfs_read
	get_inode_table
	get_fd
	get_file
	get_file_pointer
sfs_write
	get_file_pointer
	get_inode_table
	get_fd
	get_file
	set_file_pointer
	put_file
sfs_open
	get_reference_count
	get_inode_table
	compare_component_tobuff
	get_file_pointer
	get_file
	set_reference_count
	set_fd
sfs_close
	get_fd
	get_reference_count
	set_fd
	set_reference_count
sfs_create
	get_inode_table
	compare_component_tobuff
	get_file_pointer
	get_file
	set_file_pointer
	get_empty_blk
	put_inode_table
sfs_delete
	get_inode_table
	get_file_pointer
	compare_component_tobuff
	get_file
	get_reference_count
	set_file_pointer
	release_allblocks_fromfiles
	put_file
sfs_initilize
	get_inode_table
	get_super_blk
	put_inode_table
	put_super_blk