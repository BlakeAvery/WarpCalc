#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#define LIGHT 299792458

/*
 * WarpCalc - A program to convert warp factors from Star Trek to factors of c, the speed of light.
 * Uses what I'm pretty sure is the Okuda scale, cause whatever scale they were using in TOS doesn't
 * really line up with the rest of the series.
 * Made at 3 AM so don't expect any of this code to be good
 */

float warp_to_c(float warp);
float c_to_warp(float c);

int main() {
    printf("WarpCalc v1\nSelect conversion type:\n");
    while(1) {
        printf("1: Warp Factor to c\n2: c to Warp Factor\n");
        int opt;
        scanf("%d", &opt);
        if(opt > 2 || opt < 1) {
            printf("Incorrect input.\n");
        } else if(opt == 1) {
            printf("Enter warp factor:\n");
            float warp;
            scanf("%f", &warp);
            //printf("warp %f\n", warp);
            printf("Warp %f is equal to %fc.\n", warp, warp_to_c(warp));
        } else {
            printf("Enter c factor:\n");
            float c;
            scanf("%f", c);
            //printf("%fc is equal to Warp %f.", c, c_to_warp(c));
        }
    }
    return 0;
}

float warp_to_c(float warp) {
    //first check if warp is below one. if it is, this is sublight
    if(warp < 1.0) {
        return warp;
    }
    //next check if warp is above 9.
    if(warp > 9.0) {
        printf("We aren't so good with anything above warp 9 yet. Returning very bogus value.\n");
        return 100.3859384920;
    }
    float c = (pow(warp, (10.0/3)) * LIGHT) / LIGHT;
    return c;
}