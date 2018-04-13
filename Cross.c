#include <string.h>
#include <stdio.h>
#include <stdlib.h>
 
const int LOW = 0;
const int HIGH = 10;
int main(int argc, char **argv) {
    time_t seconds;
    time(&seconds);
    srand((unsigned int) seconds);
 
    int u1, u2, u3, v1, v2, v3;
    u1 = rand() % (HIGH - LOW + 1) + LOW;
    u2 = rand() % (HIGH - LOW + 1) + LOW;
    u3 = rand() % (HIGH - LOW + 1) + LOW;
    v1 = rand() % (HIGH - LOW + 1) + LOW;
    v2 = rand() % (HIGH - LOW + 1) + LOW;
    v3 = rand() % (HIGH - LOW + 1) + LOW;
 
    int uvi, uvj, uvk;
    uvi = u2 * v3 - v2 * u3;
    uvj = v1 * u3 - u1 * v3;
    uvk = u1 * v2 - v1 * u2;
 
    printf("The cross product of the 2 vectors \n u = %di + %dj + %dk and \n v = %di + %dj + %dk\n",
            u1, u2, u3, v1, v2, v3);
    printf(" u X v: %di + %dj + %dk", uvi, uvj, uvk);
    return 0;
}
