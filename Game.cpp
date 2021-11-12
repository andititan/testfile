#include <iostream>
using namespace std;

int main(){
	char player = '*';

	FILE *fptr = fopen("newprogram.txt","r");

	int x = 1;
	int y = 1;

    char arr[201][201] = {0};

	char n;

	int rows = 0;

	int j = 0;

	for(int i = 0; i < 200; i++){
		char* c = fgets(arr[i], 200, fptr);

		if(c == 0){
			rows = i;
			break;
		}
	}

	for(int i = 0; i < 200; i++){
		if(arr[0][i] == '\n'){
			j = i;
			break;
		}
	}

	char input;

    while(true){
		system("stty raw");
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

		arr[x][y] = player;
		
		for(int i = 0; i < rows; i ++){
			for(int a = 0; a < j; a++){
				int radius = 2;
				if(i < x - radius || i > x + radius || a < y - radius || a > y + radius){
					cout << " ";

				}else{
					printf("%c", arr[i][a]);

				}
			}

		printf("\n\r");	
		}
		
		arr[x][y] = ' ';
		
		system("stty cooked");
	}
	
    return 0;	
}