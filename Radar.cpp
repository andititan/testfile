#include <iostream>
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
			newX--;
			arr[newX][newY] = '#';
		}

		if(x1 > x && y1 == y){
			newX++;
			arr[newX][newY] = '#';
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

int main(){
    int radius = 8;
    char arr[201][201] = {0};

    int rows = (radius * 2) + 1;

    for(int i = 0; i < rows; i ++){
        for(int a = 0; a < rows; a++){
            arr[i][a] = ' ';
        }
    }

    int y = radius;
    int x = radius;

    int x1 = 0;
    int y1 = radius;

    arr[x][y] = '*';

	char input;
	
	system("stty raw");

    while(true){

		system("clear");

        Line(x, y, x1, y1, arr);

        for(int i = 0; i < rows; i ++){
            for(int a = 0; a < rows; a++){
                printf("%c", arr[i][a]);
            }
        	printf("\n\r");
        }

		printf("Enter e to move");
		cin >> input;

		if(input == 'e'){
			x1++;
		}
    }

    system("stty cooked");

    return 0;
}