#include <iostream>
using namespace std;

int Line(int x, int y, int x1 , int y1){
    int newX = x;
    int	newY = y;

	float dx = x1 - x;
	float dy = y1 - y;
	float tgd = dx / dy;
	float e = 0;

    while(newX != x1 || newY != y1){

		e += tgd;

		if(x1 < x && y1 > y){
			if(e > 0.5){
				newX--;
				newY++;
				e--;
			}else{
				newY++;
			}
		}

		if(x1 < x && y1 < y){
			if(e > 0.5){
				newX--;
				newY--;
				e--;
			}else{
				newY--;
			}
		}

		if(x1 > x && y1 < y){
			if(e > 0.5){
				newX++;
				newY--;
				e--;
			}else{
				newY--;
			}
		}

		if(x1 > x && y1 > y){
			if(e > 0.5){
				newX++;
				newY++;
				e--;
			}else{
				newY++;
			}
		}

		if(x1 < x && y1 == y){
			newX++;
		}

		if(x1 > x && y1 == 0){
			newX--;
		}

		if(x1 == 0 && y1 > y){
			newY++;
		}

		if(x1 == 0 && y1 < y){
			newY--;
		}
    }
}

int main(){
    int radius = 5;
    char arr[201][201] = {0};

    int rows = (radius * 2) + 1;

    for(int i = 0; i < rows; i ++){
        for(int a = 0; a < rows; a++){
            arr[i][a] = ' ';
        }
    }

    int y = radius;
    int x = radius;

    int x1 = 1;
    int y1 = radius;

    arr[x][y] = '*';

    for(int i = 0; i < rows; i ++){
        for(int a = 0; a < rows; a++){
            printf("%c", arr[i][a]);
        }
        
    printf("\n");
    }
    return 0;
}