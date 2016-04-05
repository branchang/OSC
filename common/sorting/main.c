#include <stdlib.h>
#include <time.h>
#include <stdio.h>
#include "Common.h"

int main() {
    srand((unsigned )time(0));
//    srand(50);
    float random_variable = rand()/(float)(RAND_MAX/100);

    printf("random value on [0,%d]: %f %d\n",RAND_MAX, random_variable, rand()/100);
//    test_insert();
//    test_Quick();
    test_simple();
    return 0;
}