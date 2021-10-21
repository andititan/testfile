#include <iostream>
using namespace std;

int main(){

    FILE *fptr = fopen("newprogram.txt","r");

    int eof();

    int n = 0;
    char line [100];
    int sum = 0;
    int avg = 0;
    
    do{
        fgets(line, 100, fptr);
        sscanf(line, "%d,", &n);

        int k = 0;
        for(int y = 0; y < 100; y++){
            if(k >= n){
                break;
            }

            const char ch = line[y];
            if(ch == '\0'){
                break;

            }else if(ch != ' ' && ch != '\n'){
                if(y > 0 && line[y - 1] == ' '){

                    int a = 0;

                    sscanf(&line[y], "%d,", &a);

                    sum += a;
                    k++;
                }
            }
        }
        avg  = sum / n;
        cout << avg << endl;

        sum = 0;
        avg = 0;

    }while(feof(fptr) == 0);

    fclose(fptr);

    return 0;
}