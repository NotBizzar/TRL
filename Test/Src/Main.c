#include <Buffer.h>

#include <stdio.h>

int main()
{
  TRL_Buffer *buffer = TRL_Buffer_Create(TRL_DataType_Int, 0);
  TRL_Buffer_Write(buffer, &(int){69});
  TRL_Buffer_Write(buffer, &(int){12});
  TRL_Buffer_Write(buffer, &(int){90});
  TRL_Buffer_Write(buffer, &(int){9});

  int *ptr = TRL_Buffer_GetDataInType(buffer, int);

  TRL_Buffer_WriteAt(buffer, 0, &(int){6969});

  int value = *(int *)TRL_Buffer_Read(buffer, 0);
  printf("%d\n", value);
}
