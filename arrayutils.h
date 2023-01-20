// ARRAYUTILS.H
/*
Шаблонные функции для работы с
динамическими массивами 1 и 2х
рагновыми.
*/

#ifndef ARRAYUTILSH
#define ARRAYUTILSH

#include <algorithm>
#include <iostream>

namespace jinx {

// Создать массив
template <typename T> 
void create_array(T* &array, int size) 
{
  array = new T[size];

  for (int i = 0; i < size; ++i) {
    array[i] = 0;
  } // for (int i = 0; i < size; ++i)
} // void create_array(T* array, int size)

// Наполнить массив случайкой
template <typename T> 
void fill_array(T *array, int size) 
{
  srand(time(NULL));

  for (int i = 0; i < size; ++i) {
    array[i] = rand() % 99;
    array[i] = static_cast<T>(array[i]);
    if ((rand() % 2 == 1)) {
      array[i] *= -1;
    } // if ( (rand() % 2 == 1) )
  }   // for (int i = 0; i < size; ++i)
} /* END OF void fill_array(T*, int) */

// Вывести массив в столбик + тип
template <typename T> 
void print_array(T *array, int size) 
{

  for (int i = 0; i < size; ++i) {
    // std::cout << "Array[" << i << "]\t";
    std::cout << static_cast<T>(array[i]);
    // std::cout << "\tТип: " << typeid(array[i]).name();
    if (i != (size - 1)) {
      std::cout << '\t';
    } // if ( i != (size - 1) )
  }   // for (int i = 0; i < size; ++i)
} /* END OF void print_array(T*, int) */

// Отсортировать массив
template <typename T> 
void sort_array(T *array, int size) 
{
  std::sort(array, array + size);
} /* END OF void sort_array(T*, int) */

// Утилизация массив
template <typename T> 
void destroy_array(T *array) 
{
  delete[] array;
  array = nullptr;
} /* END OF void destroy_array(T* array, int size) */

// Выделение памяти под двойной массив
template <typename T> 
void create_array_2dim(T **&array, int rows, int cols) 
{
  array = new T *[rows];
  for (int i = 0; i < rows; i++) {
    array[i] = new T[cols];
  } // for (int i = 0; i < rows; i++)
} /* END OF void create_array(T** array, const int rows, const int cols) */

// Заполнение под двойной массив
template <typename T> 
void fill_array_2dim(T **array, int rows, int cols) 
{
  srand(time(NULL));

  for (int i = 0; i < rows; i++) {
    for (int j = 0; j < cols; j++) {
      array[i][j] = rand() % 99;
      array[i][j] = static_cast<T>(array[i][j]);
      if ((rand() % 2 == 1)) {
        array[i][j] *= -1;
      } // if ( (rand() % 2 == 1) )
    }   // for (int j = 0; j < cols; j++)
  }     // for (int i = 0; i < rows; i++)
} /* END OF void fill_array_2dim(T** array, const int rows, const int cols) */

// Печать под двойной массив
template <typename T> 
void print_array_2dim(T **array, int rows, int cols) 
{
  int counter = 0;

  for (int i = 0; i < rows; i++) {
    for (int j = 0; j < cols; j++) {
      std::cout << array[i][j];
      if ((i + 1) <= rows) {
        std::cout << "\t\t";
      } // if ( (i + 1) < rows)
    }   // for (int j = 0; j < cols; j++)
    std::cout << std::endl;
  } // for (int i = 0; i < rows; i++)
} /* END OF void print_array_dim(T** array, const int rows, const int cols) */

// Для сортировки
template <typename T> 
void swap_elements(T &x, T &y) 
{
  T temp = x;
  x = y;
  y = temp;
} /* END OF void swap_elements (T &x, T &y) */

// Отсортировать под двойной массив
template <typename T> 
void sort_array_2dim(T **array, int rows, int cols) 
{
  for (int i = 0; i < rows; ++i) {
    std::sort(array[i], array[i] + cols);
  } // for (int i = 0; i < rows; ++i)
} /* void sort_array(T** array, const int rows, const int cols) */

// Утилизация под двойной массив
template <typename T> 
void destroy_array_2dim(T **array, int rows) 
{
  for (int i = 0; i < rows; ++i) {
    delete[] array[i];
    array[i] = nullptr;
  } // for (int i = 0; i < rows; ++i)
  array = nullptr;
} /* END OF void destroy_array_dim(T** array, const int rows, const int cols) */

// Переворот однострочного массива
template <typename T> 
void reverse_array(T *array, int size) 
{
  T tmp, i = 0, j = 0;
  
  for ( i = 0, j = size - 1; i < size/2; i++, j--)
	{	
		tmp = array[i];
		array[i] = array[j];
		array[j] = tmp;
	}
} /* END OF void reverse_array(int * array, int size) */

} // namespace jinx

#endif