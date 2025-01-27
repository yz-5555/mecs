#include "mecs.h"
#include <stdio.h>

void hi_mecs() {
    unsigned long num = 1UL << 24;
    printf("hi, %d\n", __builtin_ctz(num));
}
