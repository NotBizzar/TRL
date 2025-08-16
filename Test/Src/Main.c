#include <DataStructures.h>

#include <stdio.h>

int main()
{
  TRL_Buffer *buffer = TRL_Buffer_Create(TRL_DataType_Int, 0);
  TRL_Buffer_Write(buffer, &(int){69});
  TRL_Buffer_Write(buffer, &(int){12});
  TRL_Buffer_Write(buffer, &(int){90});
  TRL_Buffer_Write(buffer, &(int){9});

  TRL_Buffer_Remove(buffer, 2);

  int *ptr = TRL_Buffer_GetDataInType(buffer, int);

  int value = *(int *)TRL_Buffer_Read(buffer, 2);
  printf("%d\n", value);
}
