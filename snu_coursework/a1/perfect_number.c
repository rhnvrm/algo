#include <stdio.h>
#include <time.h>
#include <math.h>

int main(){

    unsigned long long n;

    scanf("%llu", &n);

    unsigned long long sof = 0, i = 1;

    clock_t t = clock();

    while(i < n){
        if (n % i  == 0)
            sof += i;
        i+=1;
    }

    t = clock() - t;

    printf("%llu %f\n", n, ((double)t)/CLOCKS_PER_SEC);

    /* Uncomment to view results. Commenting to save time in output for analysis.
    if (n == sof) 
        printf("True\n");
    else 
        printf("False\n");
    */
    return 0;
}
