#include <stdio.h>

#include "proj1.h"

#include <string.h>

#include <stdlib.h>

int main()

{

  //Declare file object pointer

  DTable_arr * d_table;

  //Create array of file objects 

  d_table = create();

  //User input variables

  int storage;
  int block;
  int numSelect;
  int quit = 0;
  int blockTableSize;
  int dirSize = 1;
  int * ptrDirSize;
  ptrDirSize = & dirSize;

  //User input prompt. 

  printf("Enter the size of your storage device: ");
  scanf("%d", & storage);
  printf("Enter the size of each block: ");
  scanf("%d", & block);

  //More user input variables 

  blockTableSize = storage / block;
  int i = 0;
  int calcStart = 0;
  int calcLength = 0;
  int * ptrCalcStart;
  ptrCalcStart = & calcStart;

  //Block table creation.  

  int * blockTable = (int * ) malloc(blockTableSize * 2 * sizeof(int));

  //Loop for user interaction.

  while (quit == 0)

  {

    printf("Do you want to: \n"
      "Add a file? Enter 1 \n"
      "Delete a file? Enter 2 \n"
      "Print values? Enter 3 \n"
      "Quit? Enter 4 \n");

    scanf("%d", & numSelect);

    switch (numSelect)

    {
      //Case 1 for adding a file. 

    case 1:
      if (i == dirSize)

      {
        d_table = grow(d_table, dirSize);
        dirSize += 1;

      }

      add(d_table, i, ptrDirSize, block, ptrCalcStart);
      i += 1;
      break;

      //Case 2 for deleting a file. 

    case 2:
      printf("Deleting – enter filename:");
      char toDelete[30];
      scanf("%s", toDelete);
      del(d_table, toDelete, dirSize);
      break;

      //Case 3 for printing. 

    case 3:
      print(d_table, ptrDirSize, blockTableSize, block);
      break;

      //Case 4 for quitting. 

    case 4:

      printf("Quitting – \n");
      quit = 1;
      break;
    }
  }

  free(d_table);
  free(blockTable);
  return 0;
}