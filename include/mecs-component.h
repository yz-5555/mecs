#ifndef MECS_COMPONENT_H
#define MECS_COMPONENT_H

#include "mecs-utils.h"

typedef struct {
	void* data;
	u32 size;
	u32 count;
} ComponentArray;

#endif
