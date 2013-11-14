all:
	gcc -Wall -std=c99 I_node.c blockio.c -lm
	gcc -Wall -std=c99 bitmap.c I_node.c blockio.c -lm
	gcc -Wall -std=c99 open_file_table.c blockio.c -lm
	gcc -Wall -std=c99 Sortafine.c open_file_table bitmap.c I_node.c blockio.c -lm
	gcc -Wall -std=c99 sfstest.c Sortafine.c