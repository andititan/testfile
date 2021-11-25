#include <iostream>
using namespace std;


bool isVisible(int x, int y, int x1, int y1, char arr[][201]){
	int newX = x;
    int	newY = y;

	float dx = x1 - x;
	float dy = y1 - y;
	float tgd = dx / dy;
	float e = 0;

	while(newX != x1 && newY != y1){

		e += tgd;

		if(dx < x && dy > y){
			if(e > 0.5){
				newX--;
				newY++;
				e--;
			}else{
				newY++;
			}
		}

		if(dx < x && dy < y){
			if(e > 0.5){
				newX--;
				newY--;
				e--;
			}else{
				newY--;
			}
		}

		if(dx > x && dy < y){
			if(e > 0.5){
				newX++;
				newY--;
				e--;
			}else{
				newY--;
			}
		}

		if(dx > x && dy > y){
			if(e > 0.5){
				newX++;
				newY++;
				e--;
			}else{
				newY++;
			}
		}

		if(dx < x && dy == 0){
			newX++;
		}

		if(dx > x && dy == 0){
			newX--;
		}

		if(dx == 0 && dy > y){
			newY++;
		}

		if(dx == 0 && dy < y){
			newY--;
		}

		if(newX == x1 && newY == y1){
			return true;
		}
		if(arr[newX][newY] == '#'){
			return false;
		}

	}
	return true;
}

int main(){
	char player = '*';

	FILE *fptr = fopen("newprogram.txt","r");

	int x = 0;
	int y = 0;

    char arr[201][201] = {0};

	int rows = 0;

	int j = 0;

	int radius = 3;

	fgets(arr[0],200, fptr);
	sscanf(arr[0], "%d %d", &x, &y);

	for(int i = 1; i < 200; i++){
		char* c = fgets(arr[i], 200, fptr);

		if(c == 0){
			rows = i;
			break;
		}
	}
	
	for(int i = 0; i < 200; i++){
		if(arr[1][i] == '\n'){
			j = i;
			break;
		}
	}

	if(arr[x][y] == '#'){
		cout << "Ne mojeee";
		return 0;
	}

	char input;
	
	system("stty raw");
    while(true){

		cin >> input;
		
		if(input == 'd'){
			if(arr[x][y + 1] != '#'){
			y++;
			}
		}
		else if(input == 'a'){
			if(arr[x][y - 1] != '#'){
			y--;
			}
		}
		else if(input == 'w'){
			if(arr[x - 1][y] != '#'){
			x--;
			}
		}
		else if(input == 's'){	
			if(arr[x + 1][y] != '#'){
			x++;
			}
		}

		if(arr[x][y] == 'L'){
			radius++;
		}

		if(arr[x][y] == 'l'){
			radius --;
		}

		if(arr[x][y] == 'E'){
			printf("You win!!!!");
			return 0;
		}

		arr[x][y] = player;

		system("clear");

		for(int i = 0; i < rows; i ++){

			for(int a = 0; a < j; a++){
				if((x - i) * (x - i) + (y - a) * (y - a) > radius * radius){
					cout << " ";
				}else{
					if (isVisible(x,y, i,a, arr) == true) {
						printf("%c", arr[i][a]);
					} else {
						cout << " ";
					}
				}
			}

			printf("\n\r");	
		}

		arr[x][y] = ' ';
	}

	system("stty cooked");

	fclose(fptr);

    return 0;	
}