#include<stdio.h>
#include"header.h"

int main(){
    int n;
    int choice=2;
    long int arr[3]={900000,950000,1000000};
   int t=sizeof(arr)/sizeof(arr[0]);
    // printf("Enter the number:");
    // scanf("%d",&n);
    // printf("Enter the sorting method:\n");
    // printf("1.Selection sort\n2.Bubble sort\n3.Merge sort\n4.Quick sort\n");
    // scanf("%d",&choice);
    // for(int i=0;i<t-1;i++){
    // sort(arr[i],choice);
    // }
    sort(1000000,choice);
    // sort(n,choice);
    return 0;
}