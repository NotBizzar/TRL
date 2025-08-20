#include <Buffer.h>
#include <Chain.h>

#include <stdio.h>

int main()
{
  TRL_Chain chain = TRL_Chain_Create(TRL_DataType_Int);
  TRL_Chain_InsertBack(&chain, &(int){10});
  TRL_Chain_InsertBack(&chain, &(int){11});
  TRL_ChainItem *item = TRL_Chain_InsertBack(&chain, &(int){12});
  TRL_Chain_InsertBack(&chain, &(int){13});

  TRL_Chain_InsertFront(&chain, &(int){100});
  TRL_Chain_InsertFront(&chain, &(int){99});
  TRL_Chain_InsertFront(&chain, &(int){98});
  TRL_Chain_InsertFront(&chain, &(int){97});
  TRL_Chain_InsertFront(&chain, &(int){96});

  TRL_Chain_InsertAfter(&chain, item, &(int){69});
  TRL_Chain_InsertBefore(&chain, item, &(int){31});

  TRL_Chain_RemoveAt(&chain, item);

  TRL_ChainItem *node = chain.First;
  while(node != NULL)
  {
    printf("%d\n", *(int *)node->Data);
    node = node->Next;
  }

  TRL_Chain_Destroy(&chain);
}
