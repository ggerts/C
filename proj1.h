#ifndef PROJ1_H
#define PROJ1_H



typedef struct D_Table_arr
{

char fileName[30];
	int fileSize;
	int start;
	int length;
	int active;
	int deleted;

}DTable_arr;


DTable_arr * create();
DTable_arr * grow(DTable_arr * toGrow, int from);
int add(DTable_arr * toAdd, int i, int * dirSize, int block, int * calcStart);
int del(DTable_arr * toDel, char *arr, int  dirSize); 
int print(DTable_arr * toPr, int * dirSize, int blockTableSize, int block);


#endif
