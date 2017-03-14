#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <sys/time.h>

void swap( int *a, int *b){
	int temp;
	temp = *a;
	*a = *b;
	*b = temp;
}

void heapify(int arr[], int n, int i){
	int m = i;
	int leftChild = (2*i) + 1;
	int rightChild = (2*i) + 2;
	int temp;

	if(leftChild < n && arr[leftChild] < arr[m]){
		m = leftChild;
	}

	if(rightChild < n && arr[rightChild] < arr[m]){
		m = rightChild;
	}

	if(m!=i){
		swap(&arr[i], &arr[m]);
		heapify(arr, n, m);
	}
}

void heapSort(int arr[], int n) {
	int temp;
	for (int i = (n/2)-1; i >= 0; i--)
		heapify(arr,n,i);

	for (int i = n-1; i >=0; i--)
	{
		swap(&arr[0],&arr[i]);
		heapify(arr,i,0);
	}
}

void printArray(int arr[], int n){
	for (int i = 0; i < n; i++)
		printf("%d ",arr[i]);
	printf("\n");
}

void genArray(int arr[], int n){
	
	srand(time(NULL));

	for (int i = 0; i < n; i++)
		arr[i] = rand() % n;

}

int main(int argc, char* argv[])
{

	if(argc != 2){
		printf("usage: %s <LENGTH>\n", argv[0]);
		exit(1);
	}
	
	// Initialize Array
    int arr[atoi(argv[1]) + 1];
 	genArray(arr,atoi(argv[1]));
 	printArray(arr,atoi(argv[1]));
 	
 	// Sort and Display
    heapSort(arr, atoi(argv[1]));
    printArray(arr, atoi(argv[1]));
}
