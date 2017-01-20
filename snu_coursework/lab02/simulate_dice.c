#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>

int flip_coin(){
    return rand() % 2;
}

int flip_and_convert(int i){
    return (int)(pow(2, i) * flip_coin());  
}

int simulate_dice(int n){
    int result;
    do{
        result = 0;
        int m = (int)ceil(log2(n));
    
        for(int i = 0; i < m; i++)
            result += flip_and_convert(i);
    
    } while(result == 0 || result > n);
    return result;
}

int main(){
    int seed = time(NULL);
    srand(seed);

    // Roll a 6 Sided Die simulated by a Coin

    int sample[7] = {0};
    for(int i = 0; i < 1000; i++)
        sample[simulate_dice(6) - 1] += 1;
    for(int i = 0; i < 6; i++)
        printf("Probability of Event #%d = %f\n", i+1, sample[i]/1000.0);
    return 0;
}
