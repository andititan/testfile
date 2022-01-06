#include <iostream>
#include <unistd.h>

using namespace std;

int objectX = -1;
int objectY = -1;

struct Point{
	int x;
	int y;
};

int setArr(char arr[][201], int x, int y, char V, bool &isSeen){
	if(objectX == x && objectY == y){
		isSeen = true;
	}else{
		arr[x][y] = V;
	}
}

int line(Point StartingPoint, Point LinePoint, char arr[][201], bool &isSeen){
    int newX = StartingPoint.x;
    int	newY = StartingPoint.y;

	float sdx = LinePoint.x - StartingPoint.x;
	float sdy = LinePoint.y - StartingPoint.y;
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

		if(LinePoint.x < StartingPoint.x && LinePoint.y > StartingPoint.y){
			if(abs(e) > 0.5){
				while(abs(e) > 0.5){
					setArr(arr, newX, newY, '#', isSeen);
					e += cf;
					newX -= cf;
				}
			}
			newY += cf;
			setArr(arr, newX, newY, '#', isSeen);
		}

		if(LinePoint.x < StartingPoint.x && LinePoint.y < StartingPoint.y){
			if(abs(e) > 0.5){
				while(abs(e) > 0.5){
					setArr(arr, newX, newY, '#', isSeen);
					e -= cf;
					newX -= cf;
				}
			}
			newY -= cf;
			setArr(arr, newX, newY, '#', isSeen);
		}

		if(LinePoint.x > StartingPoint.x && LinePoint.y < StartingPoint.y){
			if(abs(e) > 0.5){
				while(abs(e) > 0.5){
					setArr(arr, newX, newY, '#', isSeen);
					e += cf;
					newX += cf;
				}
			}
			newY -= cf;
			setArr(arr, newX, newY, '#', isSeen);
		}

		if(LinePoint.x > StartingPoint.x && LinePoint.y > StartingPoint.y){
			if(e > 0.5){
				while(abs(e) > 0.5){
					setArr(arr, newX, newY, '#', isSeen);
					e -= cf;
					newX += cf;
				}
			}
			newY += cf;
			setArr(arr, newX, newY, '#', isSeen);
		}

		if(LinePoint.x < StartingPoint.x && LinePoint.y == StartingPoint.y){
			while(newX > LinePoint.x){
				newX--;
				setArr(arr, newX, newY, '#', isSeen);
			}	
		}

		if(LinePoint.x > StartingPoint.x && LinePoint.y == StartingPoint.y){
			while(newX < LinePoint.x){
				newX++;
				setArr(arr, newX, newY, '#', isSeen);
			}	
		}

		if(LinePoint.x == StartingPoint.x && LinePoint.y > StartingPoint.y){
			newY++;
			setArr(arr, newX, newY, '#', isSeen);
		}

		if(LinePoint.x == StartingPoint.x && LinePoint.y < StartingPoint.y){
			newY--;
			setArr(arr, newX, newY, '#', isSeen);
		}
    }
	return 0;
}

int print(int rows, int radius, Point StartingPoint, Point LinePoint, char arr[][201], bool &isSeen, bool Add, bool &ObjectSeen){
	for(int i = 0; i < rows; i ++){
        for(int a = 0; a < rows; a++){
            arr[i][a] = ' ';
        }
    }

    line(StartingPoint, LinePoint, arr, isSeen);

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
			if((StartingPoint.x - i) * (StartingPoint.x - i) + (StartingPoint.y - a) * (StartingPoint.x - a) > radius * radius - 1){
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
	struct Point LinePoint;
	struct Point StartingPoint;

    int rows = (radius * 2) + 1;

	StartingPoint.y = radius;
	StartingPoint.x = radius;

	LinePoint.y = 1;
	LinePoint.x = 1;

	bool isSeen = false;
	bool ObjectSeen = false;
	bool Add = false;

	char input;

	print(rows, radius, StartingPoint, LinePoint, arr, isSeen, Add, ObjectSeen);

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
			if(LinePoint.y != rows - 1 && LinePoint.x == 1){
				LinePoint.y++;
				print(rows, radius, StartingPoint, LinePoint, arr, isSeen, Add, ObjectSeen);
			}

			else if(LinePoint.x != rows - 1 && LinePoint.y > 1){
				LinePoint.x++;
				print(rows, radius, StartingPoint, LinePoint, arr, isSeen, Add, ObjectSeen);
			}

			else if(LinePoint.y > 1 && LinePoint.x == rows - 1){
				LinePoint.y--;
				print(rows, radius, StartingPoint, LinePoint, arr, isSeen, Add, ObjectSeen);
			}

			else if(LinePoint.x > 1 && LinePoint.y == 1){
				LinePoint.x--;
				print(rows, radius, StartingPoint, LinePoint, arr, isSeen, Add, ObjectSeen);
			}
		}	
		isSeen = false;
    }
	system("stty cooked");

    return 0;
}