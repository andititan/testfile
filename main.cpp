#include <iostream>
using namespace std;

int main(){
    int n = 0;
    cin >> n;
    for(int line = 1; line <= n; line++){
        
		for(int i = 1; i < (n - line + 1); i++){
			cout << " ";
		}
        
		cout << "/";
		
        for(int a = 2; a < line + line; a++){
			if(line == n){
				cout << "_";
			}else{
				cout << " ";
			}
		}
        
		cout << "\\";

		cout << "\n";
	}
    return 0;
}