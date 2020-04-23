#include <stdio.h>

#include <stdlib.h>

#include <string.h>

#include "proj1.h"


//Create file array.  

DTable_arr * create()

{

  DTable_arr * ptrDirectory = (DTable_arr * ) malloc(sizeof(DTable_arr) * 1);

  return ptrDirectory;

}

//Grow file array. 

DTable_arr * grow(DTable_arr * toGrow, int from)

{
  int pluser;
  pluser = from + 1;
  toGrow = (DTable_arr * ) realloc(toGrow, sizeof(DTable_arr) * from * pluser / from);

  return toGrow;

}

//Add file to file array. 

int add(DTable_arr * toAdd, int i, int * dirSize, int block, int * calcStart)

{

  int calcLength = 0;

  printf("Adding – enter filename:");
  scanf("%s", toAdd[i].fileName);
  printf("Adding - enter file size:");
  scanf("%d", & toAdd[i].fileSize);
  toAdd[i].active = 7;

  if ( * & toAdd[i].fileSize < * & block)

  {

    calcLength = 1;
    toAdd[i].length = calcLength;
    toAdd[i].start = * calcStart;

  } else

  {

    calcLength = ( * & toAdd[i].fileSize + ( * & block - 1)) / * & block;
    toAdd[i].length = calcLength;
    toAdd[i].start = * calcStart;

  }

  * calcStart += calcLength;

  return 0;
}

//Delete file from file array.  

int del(DTable_arr * toDel, char * toDelete, int dirSize)

{

  int cc;

  for (int cc = 0; cc < dirSize; cc++)

  {

    if (strcmp(toDel[cc].fileName, toDelete) == 0) {
      strcpy(toDel[cc].fileName, "");
      toDel[cc].fileSize = 0;
      toDel[cc].active = 0;
      toDel[cc].deleted = 1;
      break;
    }

  }
  return 0;

}

//Print directory table and block table. 

int print(DTable_arr * toPr, int * dirSize, int blockTableSize, int block)

{

  printf("Printing – \n");
  printf("-------------------------------------------\n");
  printf("Directory table:\n");
  printf("%-10s%-10s%-10s%-10s\n", "Filename", "Size", "Start", "Length");
  int j;
  int k;

  for (j = 0; j < * dirSize; j++)

  {

    if (toPr[j].active == 7)

    {

      printf("%-10s", toPr[j].fileName);
      printf("%-10d", toPr[j].fileSize);
      printf("%-10d", toPr[j].start);
      printf("%-10d\n", toPr[j].length);

    }

  }

  printf("-------------------------------------------\n");
  printf("Block table:\n");
  printf("%-20s %-20s %-20s\n", "Block number", "Size used", "Fragmented");

  int l;
  int frag;
  int unused;
  for (k = 0; k < blockTableSize; k++)
  //printf("Block Table Row");

  {

    for (j = 0; j < * dirSize; j++)

    {

      if (toPr[j].active == 7 && toPr[j].start == k)

      {

        frag = toPr[j].fileSize % block;

        if (frag == 0 && toPr[j].length == 1)

        {

          for (int l = 0; l < toPr[j].length; l++)

          {

            printf("%-20d", k);
            printf("%-20d", block);
            printf("%-20d\n", 0);
            //k++;
          }
        } else if (frag == 0 && toPr[j].length != 1)

        {
          for (int l = 0; l < toPr[j].length; l++)

          {

            printf("%-20d", k);
            printf("%-20d", block);
            printf("%-20d\n", 0);
            k++;

          }

        } else

        {

          if (toPr[j].fileSize < block)

          {

            printf("%-20d", k);
            printf("%-20d", toPr[j].fileSize);
            unused = block - frag;
            printf("%-20d\n", unused);
          } else

          {

            for (int l = 0; l < toPr[j].length - 1; l++)

            {

              printf("%-20d", k);
              printf("%-20d", block);
              printf("%-20d\n", 0);
              k++;

            }

            printf("%-20d", k);
            unused = block - frag;
            printf("%-20d", frag);
            printf("%-20d\n", unused);
          }
        }
      } else

      {

        if (toPr[j].start == k)

        {

          if (toPr[j].length == 1) {

            printf("%-20d", k);
            printf("%-20d", 0);
            printf("%-20d\n", 0);

          } else

          {

            for (int l = 0; l < toPr[j].length; l++)

            {

              printf("%-20d", k);
              printf("%-20d", 0);
              printf("%-20d\n", 0);
              k++;

            }

          }

        } else

        {
          printf("%-20d", k);
          printf("%-20d", 0);
          printf("%-20d\n", 0);

        }

      }
    }
  }

  return 0;

}