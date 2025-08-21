#include "DataType.h"

#include "Buffer.h"
#include "Chain.h"

// clang-format off
size_t TRL_DataTypeValue(const TRL_DataType type)
{
  switch(type)
  {
    case TRL_DataType_Char:   return sizeof(char);
    case TRL_DataType_Int:    return sizeof(int);
    case TRL_DataType_Float:  return sizeof(float);
    case TRL_DataType_Double: return sizeof(double);
    case TRL_DataType_Buffer: return sizeof(TRL_Buffer);
    case TRL_DataType_Chain:  return sizeof(TRL_Chain);
  }
  return 0;
}
// clang-format on
