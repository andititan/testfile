#include <iostream>
using namespace std;

int main(){

    int n = 0;
    int m = 0;
    
    int a = 0;

    double sum = 0;
    double avg = 0;

    FILE *fptr = fopen("newprogram.txt","r");

    fscanf(fptr, "%d,", &n);

    for (int i = 0; i < n; i++){
        
        fscanf(fptr, "%d,", &m);
        for(int y = 0; y < m; y++){
            fscanf(fptr, "%d,", &a);
            sum += a;

        }
        avg = sum / m;
        sum = 0;
        cout << avg << endl;
    }

    fclose(fptr);

return 0;
}