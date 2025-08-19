#pragma once

typedef enum
{
  TRL_DataType_Char,
  TRL_DataType_Int,
  TRL_DataType_Float,
  TRL_DataType_Double,
} TRL_DataType;

/// @brief Returns the memory size took by the spesified datatype
/// @param type the datatype in question
/// @return memory size took
// clang-format off
static inline size_t TRL_DataTypeValue(TRL_DataType type)
{
  switch(type)
  {
    case TRL_DataType_Char:   return sizeof(char);
    case TRL_DataType_Int:    return sizeof(int);
    case TRL_DataType_Float:  return sizeof(float);
    case TRL_DataType_Double: return sizeof(double);
  }
  return 0;
}
// clang-format on
