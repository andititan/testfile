#include <iostream>
using namespace std;

int main(){

    FILE *fptr = fopen("newprogram.txt","r");

    int n = 0;
    char line [100];

    int sum = 0;

    for(int i = 0; i < 7; i++){

        fgets(line, 100, fptr);
        sscanf(line, "%d,", &n);

        for(int y = 1; y < 100; y++){

            const char ch = line[y];

            if(ch == '\0'){

                break;
            }else if(ch != ' ' && ch != '\n'){

                int a = 0;

                sscanf(&line[y], "%d,", &a);
                //printf("%d ",a);

                sum += a;
            }
        }
        cout << sum << endl;
        sum = 0;   
    }
    fclose(fptr);

return 0;
}