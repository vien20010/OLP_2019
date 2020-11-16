#ifndef __DEBUG_H
#define __DEBUG_H

#define DEBUG

#ifdef DEBUG
#define DBG(fmt, ...) printf("%s:\t%s:\t%d:\t" fmt, __FILE__, __FUNCTION__, __LINE__, ##__VA_ARGS__)
#elif
#define DBG(fmt, ...)
#endif
#endif
