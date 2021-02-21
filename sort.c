#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include"header.h"

static long long int comp=0;

void sort(int n,int t){
    int * p = generate(n);
    int * sorted;

    switch(t){
        case 1:{
            sorted = selsort(p,n);
            free(sorted);
            break;
        }
        case 2:{
            sorted = bubblesort(p,n);
            free(sorted);
            break;
        }

        case 3:{
            FILE * fptr = fopen("merge1.txt","a");
            FILE * fptr2;
            fprintf(fptr,"Size:%d\n",n);
            fptr2 = fopen("merge2.txt","a");
            fprintf(fptr2,"Size:%d\n",n);
            clock_t start,end;
            double duration;
            start = clock();
            sorted  = mergeSort(p,0,n-1);
            end = clock();
            duration = (double)(end-start)/CLOCKS_PER_SEC;

            fprintf(fptr2,"Duration:%lf\n",duration);
            fprintf(fptr,"Number of comparison:%lld\n",comp);
            fclose(fptr);
            fclose(fptr2);
            free(sorted);
            break;
        }

        case 4:{
             FILE * fptr = fopen("quick1.txt","a");
            FILE * fptr2;
            fprintf(fptr,"Size:%d\n",n);
            fptr2 = fopen("quick2.txt","a");
            fprintf(fptr2,"Size:%d\n",n);
            clock_t start,end;
            double duration;
            start = clock();
            sorted = quicksort(p,0,n-1);
            end = clock();
            duration = (double)(end-start)/CLOCKS_PER_SEC;

            fprintf(fptr2,"Duration:%lf\n",duration);
            fprintf(fptr,"Number of comparison:%lld\n",comp);
            fclose(fptr);
            fclose(fptr2);
            free(sorted);
            break;
        }
    }
    
    //print(sorted,n);
}
int * generate(int n){
    int * ptr = (int *)malloc(n*sizeof(int));
    srand(0);
    for(int i=0;i<n;i++){
        ptr[i]= rand();
    }


    return ptr;
}
//selection sort
int * selsort(int *ptr,int n){
clock_t start,end;
double duration;
FILE * fptr;
FILE * fptr2;
fptr = fopen("selection1.txt","a");
fptr2 = fopen("selection2.txt","a");
fprintf(fptr,"size:%d\n",n);
fprintf(fptr2,"Size:%d\n",n);

long long int comparison=0;
int minindex;
int i;
int j;
start = clock();
for(i=0;i<n-1;i++){
    minindex = i;
    for(j=i+1;j<n;j++){
        if(ptr[minindex]>ptr[j]){
            
            swap(&ptr[minindex],&ptr[j]);
        }
        comparison++;
    }
}

end = clock();
duration = (double)(end-start)/CLOCKS_PER_SEC;

fprintf(fptr2,"Duration:%lf\n",duration);

fprintf(fptr,"Number of comparisons: %lld\n",comparison);
fclose(fptr);
fclose(fptr2);
return ptr;
}



//bubble sort
int * bubblesort(int * ptr,long long int n){
clock_t start,end;
double duration;
FILE * fptr;
FILE * fptr2;
int flag;
fptr = fopen("bubble1.txt","a");
fptr2 = fopen("bubble2.txt","a");
fprintf(fptr,"size:%lld\n",n);
fprintf(fptr2,"Size:%lld\n",n);
    long long int comparison=0;
    start = clock();
    for(long long int i=0;i<n-1;i++){
        flag=0;
        for(long long int j=0;j<n-1-i;j++){
            if(ptr[j]>ptr[j+1]){
                
                swap(&ptr[j],&ptr[j+1]);
                flag=1;
            }
            comparison++;
        }
        if(flag==0){
            break;
        }
    }
end = clock();
duration = (double)(end-start)/CLOCKS_PER_SEC;

fprintf(fptr2,"Duration:%lf\n",duration);

fprintf(fptr,"Number of comparisons: %lld\n",comparison);
fclose(fptr);
fclose(fptr2);

    return ptr;


}



//merge sort
void merge(int *arr, long long int l, long long  int m, long long int r)
{    
    
    long long int i, j, k;
   long long int n1 = m - l + 1;
    long long int n2 = r - m;

    long long int L[n1], R[n2];



    for (i = 0; i < n1; i++)
        L[i] = arr[l + i];
    for (j = 0; j < n2; j++)
        R[j] = arr[m + 1 + j];

    i = 0, j = 0, k = l;
    while (i < n1 && j < n2)
    {   comp++;
        if (L[i] <= R[j])
        {   
            arr[k] = L[i];
            i++;
        }
        else
        {
            arr[k] = R[j];
            j++;
        }
        k++;
    }

    while (i < n1)
    {
        arr[k] = L[i];
        i++;
        k++;
    }

    while (j < n2)
    {
        arr[k] = R[j];
        j++;
        k++;
    }
    


}

int * mergeSort(int *arr, long long int l, long long int r)
{   

   
    
    if (l < r)
    {
       long long int m = l + (r - l) / 2;
        mergeSort(arr, l, m);
        mergeSort(arr, m + 1, r);
       merge(arr, l, m, r);
    }


    return arr;
}



void swap(int *x,int *y){
    int temp = *x;
    *x = *y;
    *y = temp;
}


void print(int *p,int n){
    int i;
    for(i=0;i<n;i++){
        printf("%d\t",p[i]);
    }
}


int partition(int *arr, int start, int end)
{   long long int comparison=0;
    int pivot = arr[end];
    int i = (start - 1);

    for (int j = start; j <= end - 1; j++)
    {
        if (arr[j] < pivot)
        {
            i++;
            swap(&arr[i], &arr[j]);
        }
        comp++;
    }
    swap(&arr[i + 1], &arr[end]);
    return (i + 1);
}

int * quicksort(int *arr, int start, int end)
{
    if (start < end)
    {
        int p = partition(arr, start, end);
        quicksort(arr, start, p - 1);
        quicksort(arr, p + 1, end);
    }
    return arr;
}