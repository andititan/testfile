#include <iostream>
using namespace std;

int main(){
	char player = '@';

	FILE *fptr = fopen("newprogram.txt","r");

	int x = 1;
	int y = 1;

    char arr[201][201] = {0};

	char n;

	int MAX = 0;

	for(int i = 0; i < 200; i++){
		char* c = fgets(arr[i], 200, fptr);

		if(c == 0){
			MAX = i;
			break;
		}
	}

	char input;

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

		for(int i = 0; i < MAX; i ++){
			cout << arr[i];
		}
		cout << "\n";
		arr[x][y] = ' ';
	}
	
    return 0;	
}