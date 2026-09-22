//==================================================================================================
/// @copyright (C) Copyright 2026 АО "УКБП"
//
// г. Ульяновск, Россия
//
/// @brief Компонент:
/// @brief Назначение:
/// @brief Примечание: нет.
//--------------------------------------------------------------------------------------------------
// История изменений:
//     дата     автор       CR  описание
//--------------------------------------------------------------------------------------------------
/// @version   21 сент. 2026 г.   i.volkov    ----- Начальная версия
//
//==================================================================================================

#include <stdlib.h>
#include <stddef.h>
#include <string.h>

#ifndef TREE_H_
#define TREE_H_

//--------------------------------------------------------------------------------------------------
// Определения и типы данных
//--------------------------------------------------------------------------------------------------

/// @brief  Тип добавляемых данных
typedef enum
{
  TREE_TYPE_DATA_NO = 0, ///< не определен
  TREE_TYPE_DATA_BYTE,   ///< байт
  TREE_TYPE_DATA_SHORT,  ///< 2 байта
  TREE_TYPE_DATA_INT,    ///< 4 байта
  TREE_TYPE_DATA_LONG,   ///< 8 байт
  TREE_TYPE_DATA_STRING, ///< строка
} TREE_TYPE_DATA;

/// @brief  Структура узла
typedef struct tree_node
{
  struct tree_node*  Next; ///< следующий узел
  TREE_TYPE_DATA     Type; ///< тип данных
  void*              Data; ///< данные узла
}TREE_NODE;

/// @brief  Структура дерева
typedef struct
{
  TREE_NODE* Head; ///< 
  TREE_NODE* End;  ///< 
} TREE;

/// @brief  Результат функций
typedef enum
{
  TREE_RESULT_OK = 0,         ///< нет ошибки
  TREE_RESULT_ERROR_ADD_NODE, ///< ошибка добавления нода
  TREE_RESULT_ERROR_ADD_DATA, ///< ошибка добавления данных
} TREE_RESULT;

/// @defgroup Tree_Interface Интерфейсные функции
/// @brief  Функции для работы с односвязным деревом
/// @details Для работы с деревом необходимо использовать данные функции
///@{
TREE_RESULT Tree_AddNode(TREE* fTree, TREE_TYPE_DATA fType, const void* fData);
TREE_RESULT Tree_Clear(TREE* fTree);
/// @}

#endif /* TREE_H_ */
