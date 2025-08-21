#include "Buffer.h"
#include "Util/Assert.h"

#include <malloc.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

TRL_Buffer *TRL_Buffer_Create(TRL_DataType type, size_t size)
{
  TRL_Buffer *buffer = malloc(sizeof(TRL_Buffer));
  TRL_ASSERT(
      buffer,
      "Failed To Create A Buffer. This Shouldn't Happen And Is Not Normal");

  buffer->Type = type;
  buffer->Size = size;

  buffer->Raw = malloc(size * TRL_DataTypeValue(type));
  if(!buffer->Raw)
  {
    free(buffer);
    TRL_ABORT("Failed To Allocate Buffer Data. What Size Did You Insert?");
  }

  return buffer;
}

void TRL_Buffer_Destroy(TRL_Buffer *buffer)
{
  TRL_ASSERT(buffer, "The Specified Buffer Doesn't Exist. Did You Create One "
                     "With TRL_Buffer_Create?");
  free(buffer->Raw);
  free(buffer);
}

void *TRL_Buffer_Read(const TRL_Buffer *buffer, size_t index)
{
  TRL_ASSERT(buffer, "The Specified Buffer Doesn't Exist. Did You Create One "
                     "With TRL_Buffer_Create?");
  if(index >= buffer->Size)
  {
    TRL_ABORT("You Can't Access Memory At That Location");
  }

  size_t offset = index * TRL_DataTypeValue(buffer->Type);
  return (char *)buffer->Raw + offset;
}

size_t TRL_Buffer_Write(TRL_Buffer *buffer, const void *data)
{
  TRL_ASSERT(buffer, "The Specified Buffer Doesn't Exist. Did You Create One "
                     "With TRL_Buffer_Create?");
  size_t offset = buffer->Size++ * TRL_DataTypeValue(buffer->Type);
  memcpy((char *)buffer->Raw + offset, data, TRL_DataTypeValue(buffer->Type));

  return buffer->Size;
}
void TRL_Buffer_WriteAt(TRL_Buffer *buffer, size_t index, const void *data)
{
  TRL_ASSERT(buffer, "The Specified Buffer Doesn't Exist. Did You Create One "
                     "With TRL_Buffer_Create?");
  if(index >= buffer->Size)
  {
    TRL_ABORT("You Can't Access Memory At That Location");
  }
  size_t offset = index * TRL_DataTypeValue(buffer->Type);
  memcpy((char *)buffer->Raw + offset, data, TRL_DataTypeValue(buffer->Type));
}

void TRL_Buffer_Remove(TRL_Buffer *buffer, size_t index)
{
  TRL_ASSERT(buffer, "The Specified Buffer Doesn't Exist. Did You Create One "
                     "With TRL_Buffer_Create?");
  size_t elemSize = TRL_DataTypeValue(buffer->Type);
  size_t offset = index * elemSize;
  void *removed = (char *)buffer->Raw + offset;

  memmove(removed, (char *)removed + elemSize, buffer->Size-- * elemSize);
}
