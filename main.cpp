#include <iostream>
#include <string.h>
using namespace std;

int getStringLength(char*str){
    int n = 0;
    while(str[n] != '\0'){
        n++;
    }
    return n;
}

int main(){
    FILE *fptr = fopen("newprogram.txt","r");

    char line [256];
    
    fgets(line, 256, fptr);

    int a = getStringLength(line); 
    int b = a-1;

    for(int i = 0; i < a; i++){
        int z = 3;
        if(i != b || line[i - 1] != line[b + 1]){
            char c;
            c = line[i];
            line[i] = line[b];
            line[b] = c;
            b--;
        }else{
            break;
        }
    }
    cout << line << endl;
    fclose(fptr);

    return 0;
}