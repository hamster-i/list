//==================================================================================================
// (C) Copyright 2026 АО "УКБП"
// г. Ульяновск, Россия
//
// Компонент:
// Назначение:
// Примечание: нет.
//--------------------------------------------------------------------------------------------------
// История изменений:
//     дата     автор       CR  описание
//--------------------------------------------------------------------------------------------------
//   21 сент. 2026 г.   i.volkov    ----- Начальная версия
//==================================================================================================

#include "tree.h"

// @brief добавление нода в дерево

// @param fTree дерево
// @param fType тип добавляемых данных
// @param fData добавляемые данные
// @return  Не возвращает результат

TREE_RESULT Tree_AddNode(TREE* fTree, TREE_TYPE_DATA fType, const void* fData)
{
  // выделяем память под узел
  TREE_NODE* fNode = malloc(sizeof(TREE_NODE));
  if(fNode == NULL) {return TREE_RESULT_ERROR_ADD_NODE;} // если ошибка выделения памяти под узел

  // выделяем память под данные
  fNode->Type = fType;
  switch(fNode->Type)
  {
    case TREE_TYPE_DATA_BYTE:
      fNode->Data = malloc(sizeof(char));
      *(char*)fNode->Data = *(const char*)fData;
      break;
    case TREE_TYPE_DATA_STRING:
      // если тип данных строка
      fNode->Data = malloc(strlen((const char*)fData));
      strcpy((char*)fNode->Data, (const char*) fData);
      break;
    default:
      // тип данных не определен
      fNode->Data = NULL;
      break;
  }
  // если ошибка выделения памяти под данные
  if(fNode->Data == NULL)
  {
    // закрываем выделенные ресурсы и выходим
    free(fNode);
    return TREE_RESULT_ERROR_ADD_DATA;
  }

  // добавляем нод
  fNode->Next = NULL;
  if(fTree->Head == NULL)
  {
    // добавление первого узла в пустое дерево
    fTree->Head = fNode;
    fTree->End = fTree->Head;
  }
  else
  {
    // добавление очередного узла в дерево
    fTree->End->Next = fNode;
    fTree->End = fNode;
  }

  return TREE_RESULT_OK;
}

// очистка дерева
TREE_RESULT Tree_Clear(TREE* fTree)
{
  // сли дерево пустое выходим
  if(fTree->Head == NULL) {return TREE_RESULT_OK;}

  // перебираем узлы с первого закрывая память текущего узла
  TREE_NODE* fTemp;
  do
  {
    fTemp = fTree->Head;
    fTree->Head = fTree->Head->Next;
    free(fTemp->Data); // закрываем буфер данных
    free(fTemp);       // закрываем буфер узла
  } while(fTree->Head != NULL);
  fTree->End = NULL;

  return TREE_RESULT_OK;
}
