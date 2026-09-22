//==================================================================================================
// (C) Copyright г.Ульяновск, 2026г.
// г. Ульяновск, Россия
//
// Компонент: Односвязный список
// Назначение: Динамическое управление данными
// Примечание: нет.
//--------------------------------------------------------------------------------------------------
// История изменений:
//     дата     автор       CR  описание
//--------------------------------------------------------------------------------------------------
//   22 сент. 2026 г.   i.volkov    ----- Начальная версия
//==================================================================================================

#include "list.h"

/// @brief Добавление узла в список
/// @param [in,out] fList список
/// @param [in] fType тип добавляемых данных
/// @param [in] fData добавляемые данные
/// @return Возвращает результат выполнения
/// @retval LIST_RESULT_ERROR_ADD_NODE - ошибка добавления узла
/// @retval LIST_RESULT_OK             - нет ошибки
LIST_RESULT List_AddNode(LIST* fList, LIST_TYPE_DATA fType, const void* fData)
{
  // выделяем память под узел
  LIST_NODE* fNode = malloc(sizeof(LIST_NODE));
  if(fNode == NULL) {return LIST_RESULT_ERROR_ADD_NODE;} // если ошибка выделения памяти под узел

  // выделяем память под данные
  fNode->Type = fType;
  switch(fNode->Type)
  {
    case LIST_TYPE_DATA_BYTE:
      fNode->Data = malloc(sizeof(char));
      *(char*)fNode->Data = *(const char*)fData;
      break;
    case LIST_TYPE_DATA_STRING:
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
    return LIST_RESULT_ERROR_ADD_DATA;
  }

  // добавляем нод
  fNode->Next = NULL;
  if(fLIST->Head == NULL)
  {
    // добавление первого узла в пустое дерево
    fList->Head = fNode;
    fList->End = fLIST->Head;
  }
  else
  {
    // добавление очередного узла в дерево
    fList->End->Next = fNode;
    fList->End = fNode;
  }

  return LIST_RESULT_OK;
}

/// @brief Очистка списка
/// @param [in,out] fList список
/// @return Возвращает результат выполнения
/// @retval LIST_RESULT_OK - нет ошибки
LIST_RESULT LIST_Clear(LIST* fList)
{
  // сли дерево пустое выходим
  if(fList->Head == NULL) {return LIST_RESULT_OK;}

  // перебираем узлы с первого закрывая память текущего узла
  LIST_NODE* fTemp;
  do
  {
    fTemp = fList->Head;
    fList->Head = fList->Head->Next;
    free(fTemp->Data); // закрываем буфер данных
    free(fTemp);       // закрываем буфер узла
  } while(fList->Head != NULL);
  fList->End = NULL;

  return LIST_RESULT_OK;
}
