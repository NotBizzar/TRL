#include "Datatype.h"

#include <stdlib.h>

// clang-format off
size_t TRL_DataTypeValue(TRL_DataType type)
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
