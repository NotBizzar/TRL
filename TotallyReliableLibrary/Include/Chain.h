#pragma once

#include "DataType.h"

#include <stdint.h>

/// @brief This struct is a single Item of a Chain aka Node of a Linked List.
/// You can use this to get an Item from functions like TRL_Chain_Get*
typedef struct TRL_ChainItem
{
  void *Data;
  struct TRL_ChainItem *Previous;
  struct TRL_ChainItem *Next;
} TRL_ChainItem;

/// @brief This struct is like the controller of Chain in TRL. It has the base
/// properties of what is first, what is last and the TRL_DataType of the Chain
typedef struct
{
  TRL_ChainItem *First;
  TRL_ChainItem *Last;
  TRL_DataType Type;
} TRL_Chain;

/// @brief Creates a chain with a given size as a pointer.
/// @param type The TRL_DataType you want to create a chain with
/// @return Chain Pointer (*) with first and last Chain Items
TRL_Chain *TRL_Chain_CreatePointer(TRL_DataType type);

/// @brief Creates a chain with a given size as a pointer.
/// @param type The TRL_DataType you want to create a chain with
/// @return Chain Pointer (*) with first and last Chain Items
TRL_Chain TRL_Chain_Create(TRL_DataType type);

/// @brief Deletes the providede chain and all of its ChainItems from memory
/// @param chain The chain you want to delete
void TRL_Chain_Destroy(TRL_Chain *chain);

/// @brief Creates and Inserts Item into the Chain with given data at the back
/// @param chain The chain you want to create an item in
/// @param Data The data you want to create the item with
/// @return The newly created ChainItem
TRL_ChainItem *TRL_Chain_InsertBack(TRL_Chain *chain, const void *Data);

/// @brief Creates and Inserts Item into the Chain with given data at the front
/// @param chain The chain you want to create an item in
/// @param data The data you want to create the item with
/// @return The newly created ChainItem
TRL_ChainItem *TRL_Chain_InsertFront(TRL_Chain *chain, const void *data);

/// @brief Creates and Inserts a ChainItem AFTER the specified ChainItem.
/// @param chain The chain you want to insert in
/// @param item The ChainItem you need to insert after
/// @param data The data you want to create the ChainItem with
/// @return The newly created ChainItem
TRL_ChainItem *TRL_Chain_InsertAfter(TRL_Chain *chain, TRL_ChainItem *item,
                                     const void *data);

/// @brief Creates and Inserts a ChainItem BEFORE the specified ChainItem.
/// @param chain The chain you want to insert in
/// @param item The ChainItem you need to insert before
/// @return The newly created ChainItem
TRL_ChainItem *TRL_Chain_InsertBefore(TRL_Chain *chain, TRL_ChainItem *item,
                                      const void *data);

/// @brief Get a ChainItem with the provided value
/// or returns NULL if it doesn't exist
/// @param chain The chain you want to get the item from
/// @param data The Data you want to check with the ChainItem
/// @return The ChainItem that has the value provided
/// or NULL if no ChainItem with the value exist
TRL_ChainItem *TRL_Chain_GetItemWith(TRL_Chain *chain, const void *data);

/// @brief Removes specified Chain's Last ChainItem
/// @param chain The chain you want to remove from
void TRL_Chain_RemoveBack(TRL_Chain *chain);

/// @brief Removes specified Chain's First ChainItem
/// @param chain The chain you want to remove from
void TRL_Chain_RemoveFront(TRL_Chain *chain);

/// @brief Removes a ChainItem at a specified place in the Chain
/// @param chain The chain you want to remove from
/// @param item The ChainItem you want to remove
void TRL_Chain_RemoveAt(TRL_Chain *chain, TRL_ChainItem *item);
