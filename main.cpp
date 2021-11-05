#include <iostream>
using namespace std;

int main(){
	char player = '@';
    
	int m = 0;
    int n = 0;

    cin >> n;
    cin >> m;

	char map[200][200];
    
	int x = m / 2;
	int y = n / 2;

	char input;
    while(true){
		scanf("%c", &input);

		for(int i = 0; i < n; i++){
			for(int a = 0; a < m; a++){
				if(i == 0 || i == n - 1 || a == 0 || a == m - 1){
					map[i][a] = '#';
				}else{
					map[i][a] = ' ';
				}
			}
		}

		if(input == 'd'){
			if(x + 1 == m - 1){
				break;
			}else{
				x++;
			}
		}
		else if(input == 'a'){
			if(x - 1 == 0){
				break;
			}else{
				x--;
			}
		}
		else if(input == 'w'){
			if(y - 1 == 0){
				break;
			}else{
				y--;
			}
		}
		else if(input == 's'){
			if(y + 1 == n - 1){
				break;
			}
			y++;
		}

		map[y][x] = player;

		for(int i = 0; i < n; i++){
			printf("%s\n", map[i]);
		}
	}
	
    return 0;	
}