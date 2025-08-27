#include "DataType.h"

#include <stdlib.h>
#include <string.h>

void TRL_BubbleSort(void *arr, int len, TRL_DataType type)
{
  int sort_check = 0;
  size_t dataType_size = TRL_DataTypeValue(type);
  for(int i = len - 1; i >= 0; i--)
  {
    for(int j = 1; j <= i; j++)
    {
      char *num1 = (char *)arr + ((j - 1) * dataType_size);
      char *num2 = (char *)arr + (j * dataType_size);
      int cmp = memcmp(num1, num2, dataType_size);

      if(cmp == 1)
      {
        // dont really think this would be optimal
        // i dont know for sure but someone needs to look into it
        void *temp = malloc(dataType_size);
        memcpy(temp, num2, dataType_size);
        memcpy(num2, num1, dataType_size);
        memcpy(num1, temp, dataType_size);

        sort_check = 1;
      }
    }

    if(sort_check == 0)
    {
      return;
    }
  }
}