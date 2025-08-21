#pragma once

#include "DataType.h"

/// @brief perform binary search algo on a sorted array of any datatype
/// @param arr pass the address of the starting point of the array
/// @param length pass length of the array
/// @param target pass the address of the target that you want to search in the
/// array
/// @param type pass the data type of the array
/// @return it returns the index if found or -1
int TRL_BinarySearch(const void *arr, int length, const void *target,
                     TRL_DataType type);
