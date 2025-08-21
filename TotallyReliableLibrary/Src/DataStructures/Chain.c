#include "Chain.h"
#include "Util/TRL_Assert.h"

#include <stdlib.h>
#include <string.h>

// file functions
inline static TRL_ChainItem *s_CreateChainItem(TRL_Chain *chain)
{
  TRL_ChainItem *item = malloc(sizeof(TRL_ChainItem));
  if(!item)
  {
    free(item);
    TRL_ABORT("Failed To Create Chain Item. This Normally Shouldn't Happen.");
  }
  item->Data = malloc(TRL_DataTypeValue(chain->Type));
  if(!item->Data)
  {
    free(item->Data);
    free(item);
    TRL_ABORT(("Failed To Allocate Data For The ChainItem. "
               "Did You Pass In A Valid DataType?"));
  }
  return item;
}

TRL_Chain *TRL_Chain_CreatePointer(TRL_DataType type)
{
  TRL_Chain *chain = malloc(sizeof(TRL_Chain));
  if(!chain)
  {
    free(chain);
    TRL_ABORT("Failed To Create A Chain. This Normally Shouldn't Happen.")
  }
  chain->Type = type;
  chain->First = NULL;
  chain->Last = NULL;
  return chain;
}

TRL_Chain TRL_Chain_Create(TRL_DataType type)
{
  TRL_Chain chain;
  chain.Type = type;
  chain.First = NULL;
  chain.Last = NULL;
  return chain;
}

void TRL_Chain_Destroy(TRL_Chain *chain)
{
  TRL_ASSERT(chain, "The Chain Provided Doesn't Seem To Exist");

  TRL_ChainItem *item = chain->First;
  while(item != NULL)
  {
    TRL_ChainItem *nxtItem = item->Next;
    free(item->Data);
    free(item);
    item = nxtItem;
  }
}

TRL_ChainItem *TRL_Chain_InsertBack(TRL_Chain *chain, const void *data)
{
  TRL_ASSERT(chain, "The Chain Provided Doesn't Seem To Exist");
  TRL_ASSERT(data, "The Data Provided Is Not Valid");
  TRL_ChainItem *item = s_CreateChainItem(chain);
  memcpy(item->Data, data, TRL_DataTypeValue(chain->Type));

  if(!chain->First)
  {
    item->Next = item->Previous = NULL;
    chain->First = chain->Last = item;
    return item;
  }
  item->Next = NULL;
  item->Previous = chain->Last;
  chain->Last->Next = item;
  chain->Last = item;

  return item;
}

TRL_ChainItem *TRL_Chain_InsertFront(TRL_Chain *chain, const void *data)
{
  TRL_ASSERT(chain, "The Chain Provided Doesn't Seem To Exist");
  TRL_ASSERT(data, "The Data Provided Is Not Valid");
  TRL_ChainItem *item = s_CreateChainItem(chain);
  memcpy(item->Data, data, TRL_DataTypeValue(chain->Type));

  item->Previous = NULL;
  item->Next = chain->First;
  chain->First->Previous = item;
  chain->First = item;

  return item;
}

TRL_ChainItem *TRL_Chain_InsertAfter(TRL_Chain *chain, TRL_ChainItem *item,
                                     const void *data)
{
  TRL_ASSERT(chain, "The Chain Provided Doesn't Seem To Exist");
  TRL_ASSERT(item, "The ChainItem Provided Doesn't Seem To Exist");
  TRL_ASSERT(data, "The Data Provided Is Not Valid");
  TRL_ChainItem *createdItem = s_CreateChainItem(chain);
  memcpy(createdItem->Data, data, TRL_DataTypeValue(chain->Type));

  createdItem->Next = item->Next;
  item->Next->Previous = createdItem;
  item->Next = createdItem;
  createdItem->Previous = item;

  return createdItem;
}

TRL_ChainItem *TRL_Chain_InsertBefore(TRL_Chain *chain, TRL_ChainItem *item,
                                      const void *data)
{
  TRL_ASSERT(chain, "The Chain Provided Doesn't Seem To Exist");
  TRL_ASSERT(item, "The ChainItem Provided Doesn't Seem To Exist");
  TRL_ASSERT(data, "The Data Provided Is Not Valid");
  TRL_ChainItem *createdItem = s_CreateChainItem(chain);
  memcpy(createdItem->Data, data, TRL_DataTypeValue(chain->Type));

  createdItem->Previous = item->Previous;
  item->Previous->Next = createdItem;
  item->Previous = createdItem;
  createdItem->Next = item;

  return createdItem;
}

TRL_ChainItem *TRL_Chain_GetItemWith(TRL_Chain *chain, const void *data)
{
  TRL_ASSERT(chain, "The Chain Provided Doesn't Seem To Exist");
  TRL_ASSERT(data, "The Data Provided Is Not Valid");

  TRL_ChainItem *item = chain->First;
  while(item != NULL)
  {
    if(memcmp(item->Data, data, TRL_DataTypeValue(chain->Type)) == 0)
      return item;
    item = item->Next;
  }

  return NULL;
}

void TRL_Chain_RemoveBack(TRL_Chain *chain)
{
  TRL_ASSERT(chain, "The Chain Provided Doesn't Seem To Exist");
  TRL_ASSERT(chain->Last, "The Last ChainItem Doesn't Seem To Exist. "
                          "Does The Chain Have Any Elements?");

  chain->Last->Previous->Next = NULL;
  TRL_ChainItem *temp = chain->Last->Previous;
  chain->Last->Previous = NULL;
  free(chain->Last);
  chain->Last = temp;
}

void TRL_Chain_RemoveFront(TRL_Chain *chain)
{
  TRL_ASSERT(chain, "The Chain Provided Doesn't Seem To Exist");
  TRL_ASSERT(chain->Last, "The Last ChainItem Doesn't Seem To Exist. "
                          "Does The Chain Have Any Elements?");

  chain->First->Next->Previous = NULL;
  TRL_ChainItem *temp = chain->First->Next;
  chain->First->Next = NULL;
  free(chain->First);
  chain->First = temp;
}

void TRL_Chain_RemoveAt(TRL_Chain *chain, TRL_ChainItem *item)
{
  TRL_ASSERT(chain, "The Chain Provided Doesn't Seem To Exist");
  TRL_ASSERT(item, "The ChainItem Provided Doesn't Seem To Exist");

  item->Previous->Next = item->Next;
  item->Next->Previous = item->Previous;
  free(item);
}
