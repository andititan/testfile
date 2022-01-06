#include <iostream>
#include <unistd.h>

using namespace std;

int objectX = -1;
int objectY = -1;

struct Point{
	int x;
	int y;
};

struct Object{
	Point pos;
	bool Add;
	bool isSeen;
	bool ShowObject;
};

Object objects[50];

int setArr(char arr[][201], int x, int y, char V, int ObjectCounter){
	for(int i = 0; i < ObjectCounter; i++){
		Object & obj = objects[i];
		if(obj.pos.x == x && obj.pos.y == y){
			obj.isSeen = true;
		}	
	}
	arr[x][y] = V;
}

int line(Point StartingPoint, Point LinePoint, char arr[][201], int ObjectCounter){
    int newX = StartingPoint.x;
    int	newY = StartingPoint.y;

	float sdx = LinePoint.x - StartingPoint.x;
	float sdy = LinePoint.y - StartingPoint.y;

	float dx = abs(sdx) + 1;
	float dy = abs(sdy) + 1;

	float tgd = dx / dy;

	if (sdx * sdy < 0){
		tgd = -tgd;
	}

	float e = 0;

    for(int iter = 0; iter < dy; iter++){

		e += tgd;

		float cf = 1;//correction factor

		if(LinePoint.x < StartingPoint.x && LinePoint.y > StartingPoint.y){
			if(abs(e) > 0.5){
				while(abs(e) > 0.5){
					setArr(arr, newX, newY, '#', ObjectCounter);
					e += cf;
					newX -= cf;
				}
			}
			newY += cf;
			setArr(arr, newX, newY, '#', ObjectCounter);
		}

		if(LinePoint.x < StartingPoint.x && LinePoint.y < StartingPoint.y){
			if(abs(e) > 0.5){
				while(abs(e) > 0.5){
					setArr(arr, newX, newY, '#', ObjectCounter);
					e -= cf;
					newX -= cf;
				}
			}
			newY -= cf;
			setArr(arr, newX, newY, '#', ObjectCounter);
		}

		if(LinePoint.x > StartingPoint.x && LinePoint.y < StartingPoint.y){
			if(abs(e) > 0.5){
				while(abs(e) > 0.5){
					setArr(arr, newX, newY, '#', ObjectCounter);
					e += cf;
					newX += cf;
				}
			}
			newY -= cf;
			setArr(arr, newX, newY, '#', ObjectCounter);
		}

		if(LinePoint.x > StartingPoint.x && LinePoint.y > StartingPoint.y){
			if(e > 0.5){
				while(abs(e) > 0.5){
					setArr(arr, newX, newY, '#', ObjectCounter);
					e -= cf;
					newX += cf;
				}
			}
			newY += cf;
			setArr(arr, newX, newY, '#', ObjectCounter);
		}

		if(LinePoint.x < StartingPoint.x && LinePoint.y == StartingPoint.y){
			while(newX > LinePoint.x){
				newX--;
				setArr(arr, newX, newY, '#', ObjectCounter);
			}	
		}

		if(LinePoint.x > StartingPoint.x && LinePoint.y == StartingPoint.y){
			while(newX < LinePoint.x){
				newX++;
				setArr(arr, newX, newY, '#', ObjectCounter);
			}	
		}

		if(LinePoint.x == StartingPoint.x && LinePoint.y > StartingPoint.y){
			newY++;
			setArr(arr, newX, newY, '#', ObjectCounter);
		}

		if(LinePoint.x == StartingPoint.x && LinePoint.y < StartingPoint.y){
			newY--;
			setArr(arr, newX, newY, '#', ObjectCounter);
		}
    }
	return 0;
}

int print(int rows, int radius, Point StartingPoint, Point LinePoint, char arr[][201], int ObjectCounter){
	for(int i = 0; i < rows; i ++){
        for(int a = 0; a < rows; a++){
            arr[i][a] = ' ';
        }
    }

    line(StartingPoint, LinePoint, arr, ObjectCounter);

	for(int i = 0; i < ObjectCounter; i++){
		Object & obj = objects[i];
		
		if(obj.isSeen == true && obj.Add == true){
			obj.ShowObject = true;
		}else if(obj.isSeen == true && obj.Add == false){
			obj.ShowObject = false;	
		}

		if(obj.ShowObject == true){
			arr[obj.pos.x][obj.pos.y] = '0' + i;
		}
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

	int objectCounter = 0;

	char input;

	print(rows, radius, StartingPoint, LinePoint, arr, objectCounter);

	system("stty raw");

    while(true){
		cout << "Enter 'e' to move, 'a' to add, and 'd' to delete: ";
		cin >> input;

		cout << "'\n";
		if(input == 'a'){
			cout << "Enter cordinates: ";
			cin >> objectX;
			cin >> objectY;
			Object & curObj = objects[objectCounter];
			curObj.pos.x = objectX;
			curObj.pos.y = objectY;
			curObj.Add = true;
			curObj.isSeen = false;
			objectCounter++;
		}
		
		if(input == 'q'){
			return 0;
		}

		if(input == 'd'){
			int objId;
			cout << "Enter object to delete: ";
			cin >> objId;
			Object & curObj = objects[objId];
			curObj.Add = false;
			// objectCounter--;
		}

		system("clear");

		if(input == 'e'){
			if(LinePoint.y != rows - 1 && LinePoint.x == 1){
				LinePoint.y++;
				print(rows, radius, StartingPoint, LinePoint, arr, objectCounter);
			}

			else if(LinePoint.x != rows - 1 && LinePoint.y > 1){
				LinePoint.x++;
				print(rows, radius, StartingPoint, LinePoint, arr, objectCounter);
			}

			else if(LinePoint.y > 1 && LinePoint.x == rows - 1){
				LinePoint.y--;
				print(rows, radius, StartingPoint, LinePoint, arr, objectCounter);
			}

			else if(LinePoint.x > 1 && LinePoint.y == 1){
				LinePoint.x--;
				print(rows, radius, StartingPoint, LinePoint, arr, objectCounter);
			}
		}
		for(int i = 0; i < objectCounter; i++){
			objects[i].isSeen = false;
		}	
    }
	system("stty cooked");

    return 0;
}