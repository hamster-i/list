/*
 ============================================================================
 Name        : list_test.c
 Author      : Volkov I.V.
 Version     :
 Copyright   : Your copyright notice
 Description : test list in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>

#include "list.h"

int main(void)
{
  LIST fTree = {0};

  LIST_RESULT fResult = List_AddNode(&fTree, LIST_TYPE_DATA_STRING, "111");
  fResult = List_AddNode(&fTree, LIST_TYPE_DATA_STRING, "222");
  fResult = List_AddNode(&fTree, LIST_TYPE_DATA_STRING, "333");
  fResult = List_AddNode(&fTree, LIST_TYPE_DATA_STRING, "444");
  fResult = List_AddNode(&fTree, LIST_TYPE_DATA_STRING, "555");

  int i = 1;
  fResult = List_AddNode(&fTree, LIST_TYPE_DATA_BYTE, (void*)&i);

  List_Clear(&fTree);

	return 0;
}
