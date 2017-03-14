#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(){
    srand(time(NULL));

    for(int i = 0; i < 100; i++)
        printf("%c", 'a' + rand()%4);

    return 0;
}
