#pragma once

#include <stdio.h>
#include <stdlib.h>

#define TRL_ASSERT(expr, msg)                                                  \
  do                                                                           \
  {                                                                            \
    if(!(expr))                                                                \
    {                                                                          \
      printf("ASSERTION CALLED: %s\n", msg);                                   \
      abort();                                                                 \
    }                                                                          \
  } while(0)

#define TRL_ABORT(msg)                                                         \
  printf("ABORTING: %s\n", msg);                                               \
  abort();
