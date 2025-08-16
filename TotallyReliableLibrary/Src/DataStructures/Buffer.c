#include "Buffer.h"

#include <malloc.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

/// @todo In this file, we return if somethign goes wrong with the buffer.
/// instead, we need an Assertion to occure.

TRL_Buffer *TRL_Buffer_Create(TRL_DataType type, size_t size)
{
  TRL_Buffer *buffer = malloc(sizeof(TRL_Buffer));
  if(!buffer)
    return NULL;

  buffer->Type = type;
  buffer->Size = size;

  buffer->Raw = malloc(size * TRL_DataTypeValue(type));
  if(!buffer->Raw)
  {
    free(buffer);
    return NULL;
  }

  return buffer;
}

void TRL_Buffer_Destroy(TRL_Buffer *buffer)
{
  if(!buffer)
    return;
  free(buffer->Raw);
  free(buffer);
}

void *TRL_Buffer_Read(const TRL_Buffer *buffer, size_t index)
{
  if(!buffer)
    return NULL;
  if(index >= buffer->Size || index < 0)
    return NULL;

  size_t offset = index * TRL_DataTypeValue(buffer->Type);
  return (char *)buffer->Raw + offset;
}

size_t TRL_Buffer_Write(TRL_Buffer *buffer, const void *data)
{
  if(!buffer)
    return 0;
  size_t offset = buffer->Size++ * TRL_DataTypeValue(buffer->Type);
  memcpy((char *)buffer->Raw + offset, data, TRL_DataTypeValue(buffer->Type));

  return buffer->Size;
}
void TRL_Buffer_WriteAt(TRL_Buffer *buffer, size_t index, const void *data)
{
  if(!buffer)
    return;
  if(index >= buffer->Size)
    return;
  size_t offset = index * TRL_DataTypeValue(buffer->Type);
  memcpy((char *)buffer->Raw + offset, data, TRL_DataTypeValue(buffer->Type));
}

void TRL_Buffer_Remove(TRL_Buffer *buffer, size_t index)
{
  size_t elemSize = TRL_DataTypeValue(buffer->Type);
  size_t offset = index * elemSize;
  void *removed = (char *)buffer->Raw + offset;

  memmove(removed, (char *)removed + elemSize, buffer->Size-- * elemSize);
}
