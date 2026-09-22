/*
 ============================================================================
 Name        : tree.c
 Author      : Volkov I.V.
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>

#include "tree.h"

int main(void)
{
  TREE fTree = {0};

  TREE_RESULT fResult = Tree_AddNode(&fTree, TREE_TYPE_DATA_STRING, "111");
  fResult = Tree_AddNode(&fTree, TREE_TYPE_DATA_STRING, "222");
  fResult = Tree_AddNode(&fTree, TREE_TYPE_DATA_STRING, "333");
  fResult = Tree_AddNode(&fTree, TREE_TYPE_DATA_STRING, "444");
  fResult = Tree_AddNode(&fTree, TREE_TYPE_DATA_STRING, "555");

  int i = 1;
  fResult = Tree_AddNode(&fTree, TREE_TYPE_DATA_BYTE, (void*)&i);

  Tree_Clear(&fTree);

	return 0;
}
