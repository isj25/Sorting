#ifndef header_h
#define header_h
void swap(int *x,int * y);
int * generate(int n);
void sort(int n,int t);
int * selsort(int * ptr,int n);
int * bubblesort(int *ptr,long long int n);
int * mergeSort(int *arr,long long int,long long int);
void merge(int *,long long int,long long int,long long int);
void print(int *p,int n);
int partition(int *arr, int start, int end);
int * quicksort(int *arr, int start, int end);
#endif