#include <iostream>
#include <unistd.h>
#include <assert.h>

using namespace std;

int SetArr(char arr[][201], int x, int y, char V){
	assert(x >= 0 && x < 201);
	assert(y >= 0 && y < 201);
	arr[x][y] = V;
}

int AddObject(int x, int y, char arr[][201]){
	
}

int Line(int x, int y, int x1 , int y1, char arr[][201]){
    int newX = x;
    int	newY = y;

	float sdx = x1 - x;
	float sdy = y1 - y;
	float dx = abs(sdx) + 1;
	float dy = abs(sdy) + 1;

	float tgd = dx / dy;

	if (sdx * sdy < 0) {
		tgd = -tgd;
	}

	float e = 0;

    for(int iter = 0; iter<dy; iter++){

		e += tgd;

		float cf = 1;//correction factor

		if(x1 < x && y1 > y){
			if(abs(e) > 0.5){
				while(abs(e) > 0.5){
					SetArr(arr, newX, newY, '#');
					e += cf;
					newX -= cf;
				}
			}
			newY += cf;
			SetArr(arr, newX, newY, '#');
		}

		if(x1 < x && y1 < y){
			if(abs(e) > 0.5){
				while(abs(e) > 0.5){
					SetArr(arr, newX, newY, '#');
					e -= cf;
					newX -= cf;
				}
			}
			newY -= cf;
			SetArr(arr, newX, newY, '#');
		}

		if(x1 > x && y1 < y){
			if(abs(e) > 0.5){
				while(abs(e) > 0.5){
					SetArr(arr, newX, newY, '#');
					e += cf;
					newX += cf;
				}
			}
			newY -= cf;
			SetArr(arr, newX, newY, '#');
		}

		if(x1 > x && y1 > y){
			if(e > 0.5){
				while(abs(e) > 0.5){
					SetArr(arr, newX, newY, '#');
					e -= cf;
					newX += cf;
				}
			}
			newY += cf;
			SetArr(arr, newX, newY, '#');
		}

		if(x1 < x && y1 == y){
			while(newX > x1){
				newX--;
				SetArr(arr, newX, newY, '#');
			}	
		}

		if(x1 > x && y1 == y){
			while(newX < x1){
				newX++;
				SetArr(arr, newX, newY, '#');
			}	
		}

		if(x1 == x && y1 > y){
			newY++;
			SetArr(arr, newX, newY, '#');
		}

		if(x1 == x && y1 < y){
			newY--;
			SetArr(arr, newX, newY, '#');
		}
    }
	return 0;
}

int Print(int rows, int radius, int x, int y, int x1, int y1, char arr[][201]){
	for(int i = 0; i < rows; i ++){
        for(int a = 0; a < rows; a++){
            arr[i][a] = ' ';
        }
    }

    Line(x, y, x1, y1, arr);

	for(int i = 0; i < rows; i ++){
		for(int a = 0; a < rows; a++){
			if((x - i) * (x - i) + (y - a) * (y - a) > radius * radius - 1){
				cout << "* ";
			}else{
				printf("%c ", arr[i][a]);
			}
		}
		printf("\n\r");
	}
}

int main(){
    int radius = 12;
    char arr[201][201] = {0};

    int rows = (radius * 2) + 1;

    int y = radius;
    int x = radius;

    int x1 = 1;
    int y1 = 1;

    while(true){

		system("clear");

		while(y1 != rows){
			y1++;
			Print(rows, radius, x, y, x1, y1, arr);
			usleep(100000);
		}

		while(x1 != rows){
			x1++;
			Print(rows, radius, x, y, x1, y1, arr);
			usleep(100000);
		}

		while(y1 > 1){
			y1--;
			Print(rows, radius, x, y, x1, y1, arr);
			usleep(100000);
		}

		while(x1 > 1){
			x1--;
			Print(rows, radius, x, y, x1, y1, arr);
			usleep(100000);
		}
    }
    return 0;
}