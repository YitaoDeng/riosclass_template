#ifndef __DEBUG_H__
#define __DEBUG_H__

#include <stdio.h>
#include <assert.h>
#define DEBUG

#ifdef DEBUG
#define Log(format, ...) \
    printf("[%s,%d,%s] " format "\n", \
        __FILE__, __LINE__, __func__, ## __VA_ARGS__)
#else
#define Log(format, ...) \

#endif

#endif
