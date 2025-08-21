#pragma once

typedef enum
{
  TRL_DataType_Char,
  TRL_DataType_Int,
  TRL_DataType_Float,
  TRL_DataType_Double,
  TRL_DataType_Buffer,
  TRL_DataType_Chain
} TRL_DataType;

/// @brief Returns the memory size took by the spesified datatype
/// @param type the datatype in question
/// @return memory size took
size_t TRL_DataTypeValue(const TRL_DataType type);
