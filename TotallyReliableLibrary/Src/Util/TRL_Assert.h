#pragma once

#include <stdio.h>
#include <stdlib.h>

/// @todo add this to docs.
/// You can disable asserts by adding the compile definition "TRL_ASSERTS_OFF"
#ifndef TRL_ASSERTS_OFF
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
#else
#define TRL_ASSERT(expr, msg)                                                  \
  do                                                                           \
  {                                                                            \
    if(!(expr))                                                                \
    {                                                                          \
      printf("ASSERTION CALLED: %s\n", msg);                                   \
    }                                                                          \
  } while(0)

#define TRL_ABORT(msg) printf("ABORTING: %s\n", msg);
#endif