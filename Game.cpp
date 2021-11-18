#include <iostream>
using namespace std;

int main(){
	char player = '*';

	FILE *fptr = fopen("newprogram.txt","r");

	int x = 0;
	int y = 0;

    char arr[201][201] = {0};

	int rows = 0;

	int j = 0;

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

		arr[x][y] = player;

		system("clear");

		for(int i = 0; i < rows; i ++){

			for(int a = 0; a < j; a++){
				int radius = 4;

				if((x - i) * (x - i) + (y - a) * (y - a) > 4 * 4){
					cout << " ";
				}else{
					printf("%c", arr[i][a]);
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