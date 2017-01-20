#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define N 1e6L

#define ll unsigned long long

int linear_search(char file_name[256], ll key){
    FILE* fp;
    fp = fopen(file_name, "r");
    ll num;
    while(!feof(fp)){
        fscanf(fp, "%llu\n", &num);
        if (num == key){
            return 1;
        }
    }
    return -1;
}

void find_and_time(ll key){

    double t1, t2, t3;

    clock_t t;
    t = clock();
    linear_search("first.txt", key);
    t = clock() - t;
    t1 = ((double)t)/CLOCKS_PER_SEC;
    t = clock();
    linear_search("second.txt", key);
    t = clock() - t;
    t2 = ((double)t)/CLOCKS_PER_SEC;
    t = clock();
    linear_search("third.txt", key);
    t = clock() - t;
    t3 = ((double)t)/CLOCKS_PER_SEC;
    printf("%llu\t%f\t%f\t%f\n", key, t1, t2, t3);
}

int main(){
    printf("key\tTime in File 1\tTime in File 2\tTime and File 3\n");

    find_and_time(500);
    find_and_time(700);

    find_and_time(387745451);
    find_and_time(rand()%1000000000);
}
