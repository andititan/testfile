#include <iostream>
using namespace std;

int main(){

    int n = 0;
    int sum = 0;

    FILE *fptr = fopen("newprogram.txt","r");

    fscanf(fptr, "%d,", &n);
    int *arr = new int[n];

    for (int i = 0; i < n; i++){
        fscanf(fptr, "%d,", &arr[i] );
        sum+=arr[i];
    }

    cout << sum;

    fclose(fptr);
    delete [] arr;

return 0;
}