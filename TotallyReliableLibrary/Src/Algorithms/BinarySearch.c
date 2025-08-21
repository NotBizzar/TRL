#include "BinarySearch.h"

#include <stdlib.h>
#include <string.h>

int TRL_BinarySearch(const void *arr, int length, const void *target,
                     TRL_DataType type)
{
  size_t dataType_size = TRL_DataTypeValue(type);

  char *low = (char *)arr;
  char *high = ((char *)arr) + (length - 1) * dataType_size;

  while(low <= high)
  {
    char *mid = low + ((high - low) / dataType_size / 2) * dataType_size;

    int cmp = memcmp(mid, target, dataType_size);

    if(cmp == 0)
    {
      // return ((char *)mid-(char *)arr)/length;
      return (mid - (char *)arr) / dataType_size;
    }

    if(cmp < 0)
    {
      low = mid + dataType_size;
    }
    else
    {
      high = mid - dataType_size;
    }
  }
  return -1;
}
