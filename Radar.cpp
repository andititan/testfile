#include <iostream>
#include <unistd.h>
using namespace std;

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

    for(int iter = 0; iter<dy; iter++) {
		e += tgd;

		float cf = 1;//correction factor

		if(x1 < x && y1 > y){
			if(abs(e) > 0.5){
				while(abs(e) > 0.5){
					arr[newX][newY] = '#';
					e += cf;
					newX -= cf;
				}
			}
			newY += cf;
		}

		if(x1 < x && y1 < y){
			if(abs(e) > 0.5){
				while(abs(e) > 0.5){
					arr[newX][newY] = '#';
					e -= cf;
					newX -= cf;
				}
			}
			newY -= cf;
		}

		if(x1 > x && y1 < y){
			if(abs(e) < 0.5){
				while(abs(e) < 0.5){
					arr[newX][newY] = '#';
					e += cf;
					newX += cf;
				}
			}
			newY-= cf;
		}

		if(x1 > x && y1 > y){
			if(e > 0.5){
				while(abs(e) > 0.5){
					arr[newX][newY] = '#';
					e -= cf;
					newX += cf;
				}
			}
			newY += cf;
		}

		if(x1 < x && y1 == y){
			while(newX > x1){
				newX--;
				arr[newX][newY] = '#';
			}	
		}

		if(x1 > x && y1 == y){
			while(newX < x1){
				newX++;
				arr[newX][newY] = '#';
			}	
		}

		if(x1 == x && y1 > y){
			newY++;
			arr[newX][newY] = '#';
		}

		if(x1 == x && y1 < y){
			newY--;
			arr[newX][newY] = '#';
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
				if((x - i) * (x - i) + (y - a) * (y - a) > radius * radius){
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

    int x1 = 0;
    int y1 = radius;

	arr[x][y] = '*';

	char input;

	system("stty raw");

    while(true){

		system("clear");

		printf("Enter e to move");
		cin >> input;

		if(input == 'e'){
			do{
				y1++;
				Print(rows, radius, x, y, x1, y1, arr);
				usleep(700000);
			}while(y1 != rows - 1);

			do{
				x1++;
				Print(rows, radius, x, y, x1, y1, arr);
				usleep(700000);
			}while(x1 != rows - 1);

			do{
				y1--;
				Print(rows, radius, x, y, x1, y1, arr);
				usleep(700000);
			}while(y1 != 0);

			do{
				x1--;
				Print(rows, radius, x, y, x1, y1, arr);
				usleep(700000);
			}while(x1 != 0);

		}
    }

    system("stty cooked");

    return 0;
}