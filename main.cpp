#include <iostream>
using namespace std;

int main(){

    int n = 0;
    int sum = 0;
    int fNum = 0;
    int sNum = 0;

    FILE *fptr = fopen("newprogram.txt","r");

    fscanf(fptr, "%d,", &n);
    //int *arr = new int[n];

    for (int i = 0; i < n; i++){
        fscanf(fptr, "%d %d,", &fNum, &sNum);
        //fscanf(fptr, "%d,", &sNum);
        sum = fNum + sNum;
        cout << sum << endl;
    }

    fclose(fptr);
    //delete [] arr;

return 0;
}