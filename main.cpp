#include <iostream>
using namespace std;

int initialSpaces(int lines, int currentLine){
	return lines - (currentLine + 1);
}

void printSpaces(int n) {
	for(int i = 0; i < n; i++){
		cout << " ";
	}	
}

int firstLine(int n){
	for(int a = 0; a < initialSpaces(n, 0); a++){
		cout << " ";
	}

	for(int i = 0; i < n; i++){
		cout << "* ";
	}
	cout << "\n";
}


int Mid(int n){
	for(int a = 1; a < n - 1; a ++){

		printSpaces(initialSpaces(n, a));
		cout << "*";
		
		const int spaces2 = a * 2 - 1;
		printSpaces(spaces2);
		cout << "*";

		const int spacesMid = 2 * initialSpaces(n, a) - 1;
		printSpaces(spacesMid);
		cout << "*";

		printSpaces(spaces2);
		cout << "*";
		cout << "\n";
	}
}

int Last(int n){
	for(int i = 0; i < n * 2 - 1; i++){
		cout << "*" << " ";
	}
}

int main(){
    int n = 0;
    cin >> n;
    
    firstLine(n);

	Mid(n);
    
	Last(n);
    return 0;
}