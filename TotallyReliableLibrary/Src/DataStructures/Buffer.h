#pragma once

#include "Util/Datatype.h"

#include <stdlib.h>

typedef struct
{
  void *Raw;
  size_t Size;
  TRL_DataType Type;
} TRL_Buffer;

/// @brief Creates A TRL_Buffer
/// @param type TRL_DataType of the buffer (Default = int)
/// @param size Size of the buffer (Default = 0)
TRL_Buffer *TRL_Buffer_Create(TRL_DataType type, size_t size);

/// @brief Deletes a specified buffer from memory
void TRL_Buffer_Destroy(TRL_Buffer *buffer);

/// @brief Gets value at specified index
/// @return Typecast the value for avoiding any potential hassle
void *TRL_Buffer_Read(const TRL_Buffer *buffer, size_t index);

/// @brief pushes provided value into the buffer
/// @return the new size of the buffer
size_t TRL_Buffer_Write(TRL_Buffer *buffer, const void *data);
/// @brief Writes/ReWrites at a given indexition
void TRL_Buffer_WriteAt(TRL_Buffer *buffer, size_t index, const void *data);

/// @brief Removes a value at specified index
void TRL_Buffer_Remove(TRL_Buffer *buffer, size_t index);

/// @brief gives the data of the specified buffer in the specified type.
/// Can be used for debugging.
#define TRL_Buffer_GetDataInType(buffer, type) ((type *)buffer->Raw)
