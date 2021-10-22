#include <iostream>
using namespace std;

int getStringLength(char *str){
    int n = 0;
    while(str[n] != '\0'){
        n++;
    }
    return n;
}

void getLine(char *str, FILE *file, int size = 0){
    for(int i = 0; i < size; i++){
        char ch;
        ch = fgetc(file);

        if(ch == '\n' || ch == '\0'){
            break;
        }else{
            str[i] = ch;
        }
    }
}

int main(){
    FILE *fptr = fopen("newprogram.txt","r");

    char line [256];
    
    getLine(line, fptr, 256);

    int a = getStringLength(line); 
    int b = a-1;

    for(int i = 0; i < a/2; i++){
            char c;
            c = line[i];
            line[i] = line[b];
            line[b] = c;
            b--;
    }

    cout << line << endl;
    fclose(fptr);

    return 0;
}