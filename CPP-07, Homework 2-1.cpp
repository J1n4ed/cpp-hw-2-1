// CPP-07, Homework 2-1.cpp

/*
  20.01.2023
  Тема 2, Занятие 1
  Работа 1, Знакомство с Visual Studio 2022
  Version 1
  CPP-07
  @j1n4ed
*/


#include <iostream>
#include <fstream>

/* my array utilities*/
#include "arrayutils.h"

// homework functions for array transformation
void twist_first_array(int*, int);
void twist_second_array(int*, int);

int main()
{
	int fArrSize = 0, sArrSize = 0;

	std::fstream file;

	file.open("in.txt", std::ios_base::out | std::ios_base::in);

	if (file)
	{
		file.seekg(0);

		file >> fArrSize;							// read first array size

		int* firstArr;								// make first array pointer
		jinx::create_array(firstArr, fArrSize);		// create first array

		for (int i = 0; i < fArrSize; ++i)			// read data to first array
		{
			file >> firstArr[i];
		} // END FOR

		file >> sArrSize;							// read second array size

		int* secondArr;								// make second array pointer
		jinx::create_array(secondArr, sArrSize);	// create second array

		for (int i = 0; i < sArrSize; ++i)			// read data to second array
		{
			file >> secondArr[i];
		} // END FOR

		file.close();

		// print reading result
		std::cout << "FILE READING RESULTS:" << std::endl;

		// first array
		std::cout << fArrSize << "\n";
		jinx::print_array(firstArr, fArrSize);
		std::cout << std::endl;

		// second array
		std::cout << sArrSize << "\n";
		jinx::print_array(secondArr, sArrSize);
		std::cout << std::endl;

		// change arrays
		twist_first_array(firstArr, fArrSize);
		twist_second_array(secondArr, sArrSize);

		// printing of changed arrays
		std::cout << "\nARRAY CHANGING RESULTS:" << std::endl;

		// first array
		std::cout << fArrSize << "\n";
		jinx::print_array(firstArr, fArrSize);
		std::cout << std::endl;

		// second array
		std::cout << sArrSize << "\n";
		jinx::print_array(secondArr, sArrSize);
		std::cout << std::endl;		

		// send new arrays into new file out.txt
		std::ofstream output_file;
		output_file.open("out.txt", std::ofstream::out);

		if (output_file.is_open())
		{
			output_file << sArrSize << "\n";
			for (int i = 0; i < sArrSize; ++i)
			{
				output_file << secondArr[i] << ' ';
			}

			output_file << "\n" << fArrSize << "\n";
			for (int i = 0; i < fArrSize; ++i)
			{
				output_file << firstArr[i] << ' ';
			}

			output_file.close();
		}
		else
		{
			std::cerr << "ERROR OPENING THE FILE FOR WRIGHTING!" << std::endl;
		}

		// cleanup
		jinx::destroy_array(firstArr);
		jinx::destroy_array(secondArr);
		
	} 
	else // IF FSTREAM IS INVALID
	{
		std::cerr << "ERROR READING FILE!" << std::endl;
	}

	system("pause");
	return 0;
}

/*
изначально первый по счёту массив, 
должны быть сдвинуты на один элемент влево 
с переносом первого элемента на место последнего
*/
void twist_first_array(int* arr, int size)
{
	int tmp = arr[0];

	for (int i = 0; i < (size - 1); ++i)
	{
		arr[i] = arr[i + 1];
	}

	arr[size - 1] = tmp;
}

/* 
изначально второй по счёту массив, 
должны быть сдвинуты на один элемент вправо 
с переносом последнего элемента на место первого
*/
void twist_second_array(int* arr, int size)
{
	int tmp = arr[size - 1];
	
	for (int i = (size - 1); i > 0; --i)
	{
		arr[i] = arr[i - 1];
	}

	arr[0] = tmp;
}