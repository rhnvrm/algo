#include <stdio.h>
#include <stdlib.h>

#define N 1e6

#define ll unsigned long long 
// Generate n random numbers between x and y and save in file_name
int generate(ll n, ll x, ll y, char file_name[256], int randomize){

    // Open File
    FILE* fp;
    fp = fopen(file_name, "w");

    if(randomize == 0){
        for(ll i = x; i <= y; i++)
            for(ll j = 0; j < N/1000; j++)
            fprintf(fp, "%llu\n", j);
    }
    else{
        for(ll i = 0; i < n; i++){
            fprintf(fp, "%llu\n", x + (rand() % (y-x)));
        }
    }

    printf("Generated file %s\n", file_name);
    return 0;
}       

int main(){

    generate(N, 1,1000,"first.txt", 0);
    generate(N, 1,1000,"second.txt", 1);
    generate(N, 1e6,1e9,"third.txt", 1);
}
