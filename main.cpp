#include <iostream>
using namespace std;

int main(){
    int n = 0;
    cin >> n;
    for (int line = 1; line <= n; line++){

		for (int i = 1; i < (n - line + 1); i++){
			cout << " ";
		}
        
        int a = 1;

		for (int i = 1; i <= line; i++){
			cout << a << " ";
			a = a * (line - i) / i;
		}

		cout << "\n";
	}
    return 0;
}