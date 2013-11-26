all: sortafine.out bitmap Sortafine
	echo "this works I think?"
openfile: open_file_table.c
	gcc -Wall -std=c99 open_file_table.c bitmap.c I_node.c blockio.c -lm
bitmap: bitmap.c I_node.c blockio.c
	gcc -Wall -std=c99 bitmap.c I_node.c blockio.c -lm -o bitmap.o
Sortafine: Sortafine.c open_file_table.c bitmap.c I_node.c blockio.c
	gcc -Wall -std=c99 Sortafine.c open_file_table.c bitmap.c I_node.c blockio.c -lm -o Sortafine.o
inode: I_node.c blockio.c
	gcc -Wall -std=c99 I_node.c blockio.c -o inode.o