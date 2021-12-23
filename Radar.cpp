#include <iostream>
#include <unistd.h>

using namespace std;

int objectX = -1;
int objectY = -1;

int SetArr(char arr[][201], int x, int y, char V, bool &isSeen){
	if(objectX == x && objectY == y){
		isSeen = true;
	}else{
		arr[x][y] = V;
	}
}

int Line(int x, int y, int x1 , int y1, char arr[][201], bool &isSeen){
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
					SetArr(arr, newX, newY, '#', isSeen);
					e += cf;
					newX -= cf;
				}
			}
			newY += cf;
			SetArr(arr, newX, newY, '#', isSeen);
		}

		if(x1 < x && y1 < y){
			if(abs(e) > 0.5){
				while(abs(e) > 0.5){
					SetArr(arr, newX, newY, '#', isSeen);
					e -= cf;
					newX -= cf;
				}
			}
			newY -= cf;
			SetArr(arr, newX, newY, '#', isSeen);
		}

		if(x1 > x && y1 < y){
			if(abs(e) > 0.5){
				while(abs(e) > 0.5){
					SetArr(arr, newX, newY, '#', isSeen);
					e += cf;
					newX += cf;
				}
			}
			newY -= cf;
			SetArr(arr, newX, newY, '#', isSeen);
		}

		if(x1 > x && y1 > y){
			if(e > 0.5){
				while(abs(e) > 0.5){
					SetArr(arr, newX, newY, '#', isSeen);
					e -= cf;
					newX += cf;
				}
			}
			newY += cf;
			SetArr(arr, newX, newY, '#', isSeen);
		}

		if(x1 < x && y1 == y){
			while(newX > x1){
				newX--;
				SetArr(arr, newX, newY, '#', isSeen);
			}	
		}

		if(x1 > x && y1 == y){
			while(newX < x1){
				newX++;
				SetArr(arr, newX, newY, '#', isSeen);
			}	
		}

		if(x1 == x && y1 > y){
			newY++;
			SetArr(arr, newX, newY, '#', isSeen);
		}

		if(x1 == x && y1 < y){
			newY--;
			SetArr(arr, newX, newY, '#', isSeen);
		}
    }
	return 0;
}

int Print(int rows, int radius, int x, int y, int x1, int y1, char arr[][201], bool &isSeen, bool Add, bool &ObjectSeen){
	for(int i = 0; i < rows; i ++){
        for(int a = 0; a < rows; a++){
            arr[i][a] = ' ';
        }
    }

    Line(x, y, x1, y1, arr, isSeen);

	if(isSeen == true && Add == true){
		ObjectSeen = true;
	}else if(isSeen == true && Add == false){
		ObjectSeen = false;	
	}

	if(ObjectSeen == true){
		arr[objectX][objectY] = '$';
	}else if(ObjectSeen == false){
		arr[objectX][objectY] = ' ';
	}

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
    int radius = 18;
    char arr[201][201] = {0};

    int rows = (radius * 2) + 1;

    int y = radius;
    int x = radius;
	
	bool isSeen = false;
	bool ObjectSeen = false;
	bool Add = false;

    int x1 = 1;
    int y1 = 1;

	char input;

	Print(rows, radius, x, y, x1, y1, arr, isSeen, Add, ObjectSeen);

	system("stty raw");

    while(true){
		cout << "Enter 'e' to move, 'a' to add, and 'd' to delete: ";
		cin >> input;

		cout << "'\n";
		if(input == 'a'){
			cout << "Enter cordinates: ";
			cin >> objectX;
			cin >> objectY;
			Add = true;
			
		}
		
		if(input == 'q'){
			return 0;
		}

		if(input == 'd'){
			Add = false;
		}

		system("clear");

		if(input == 'e'){
			if(y1 != rows - 1 && x1 == 1){
				y1++;
				Print(rows, radius, x, y, x1, y1, arr, isSeen, Add, ObjectSeen);
			}

			else if(x1 != rows - 1 && y1 > 1){
				x1++;
				Print(rows, radius, x, y, x1, y1, arr, isSeen, Add, ObjectSeen);
			}

			else if(y1 > 1 && x1 == rows - 1){
				y1--;
				Print(rows, radius, x, y, x1, y1, arr, isSeen, Add, ObjectSeen);
			}

			else if(x1 > 1 && y1 == 1){
				x1--;
				Print(rows, radius, x, y, x1, y1, arr, isSeen, Add, ObjectSeen);
			}
		}	
		isSeen = false;
    }
	system("stty cooked");

    return 0;
}