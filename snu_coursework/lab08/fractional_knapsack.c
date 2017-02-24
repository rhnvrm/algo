#include <stdio.h>
#include <stdlib.h>

struct item{
    float w, p, r;
} items[100];

int compare(const void *p, const void *q){

    struct item l = *(const struct item *)p;
    struct item r = *(const struct item *)q;

    return l.r - r.r;
}    


void knapsack(int n, struct item items[], float c){
    int c_w = 0;
    float final_val = 0.0;

    for(int i = 0; i < n; i++){
        if(c_w + items[i].w <= c){
            c_w += items[i].w;
            final_val += items[i].p;
        }
        else{
            int r = c - c_w;
            final_val += items[i].w * ((float)r/items[i].w);
            break;
        }
    }
    printf("%f\n", final_val);
}

int main(){
    float c, temp;

    int n; // number of objects
    scanf("%d", &n);

    // w p
    for(int i = 0; i < n; i++){
        scanf("%f %f", &items[i].w, &items[i].p);
    }

    //capacity
    scanf("%f", &c);

    for(int i = 0; i < n; i++){
        items[i].r = items[i].p/items[i].w;
    }

    //sort
    qsort((void *)items, n, sizeof(items[0]), compare); 

    knapsack(n, items, c);
    return 0;
}
