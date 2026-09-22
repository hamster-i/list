///==================================================================================================
/// @copyright (C) Copyright г.Ульяновск, 2026г.
/// г. Ульяновск, Россия
///
/// @brief Компонент: Односвязный список
/// @brief Назначение: Динамическое управление данными
/// @brief Примечание: нет.
///--------------------------------------------------------------------------------------------------
/// История изменений:
///     дата     автор       CR  описание
///--------------------------------------------------------------------------------------------------
/// @version   22 сент. 2026 г.   i.volkov    ----- Начальная версия
///
///==================================================================================================

#include <stdlib.h>
#include <stddef.h>
#include <string.h>

#ifndef LIST_H_
#define LIST_H_

//--------------------------------------------------------------------------------------------------
// Определения и типы данных
//--------------------------------------------------------------------------------------------------

/// @brief  Тип добавляемых данных
typedef enum
{
  LISt_TYPE_DATA_NO = 0, ///< не определен
  LIST_TYPE_DATA_BYTE,   ///< байт
  LIST_TYPE_DATA_SHORT,  ///< 2 байта
  LIST_TYPE_DATA_INT,    ///< 4 байта
  LIST_TYPE_DATA_LONG,   ///< 8 байт
  LIST_TYPE_DATA_STRING, ///< строка
} LIST_TYPE_DATA;

/// @brief  Структура узла
typedef struct list_node
{
  struct list_node*  Next; ///< следующий узел
  LIST_TYPE_DATA     Type; ///< тип данных
  void*              Data; ///< данные узла
}LIST_NODE;

/// @brief  Структура списка
typedef struct
{
  LIST_NODE* Head; ///< 
  LIST_NODE* End;  ///< 
} LIST;

/// @brief  Результат функций
typedef enum
{
  LIST_RESULT_OK = 0,         ///< нет ошибки
  LIST_RESULT_ERROR_ADD_NODE, ///< ошибка добавления нода
  LIST_RESULT_ERROR_ADD_DATA, ///< ошибка добавления данных
} LIST_RESULT;

/// @defgroup LIST_Interface Интерфейсные функции
/// @brief  Функции для работы с односвязным списком
/// @details В разработке...
///@{
LIST_RESULT LIST_AddNode(LIST* fList, LIST_TYPE_DATA fType, const void* fData);
LIST_RESULT LIST_Clear(LIST* fList);
/// @}

#endif /* LIST_H_ */
