#include <iostream>
using namespace std;

int main(){
    int n;
    cout << "n";
    cin >> n;
    int num1 = 0, num2 = 1, sum = 0;

    for(int i = 0; i <= n; i++){

        sum = num1 + num2;
        num1 = num2;
        num2 = sum;

        cout << sum << ", ";
    }
return 0;

}