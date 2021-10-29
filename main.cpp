#include <iostream>
using namespace std;

int main(){
    int x = 0;

    int date = 0;

    int month = 0;
    int m = 0;

    int century = 0;
    int c = 0;

    int year = 0;
    int y = 0;
    
    cout << "Enter date: ";
    cin >> date;

    cout << "Enter month: ";
    cin >> month;

    cout << "Enter year: ";
    cin >> year;

    switch(month){
        case 1:
        m = 0;
        break;

        case 2:
        m = 3;
        break;

        case 3:
        m = 3;
        break;

        case 4:
        m = 6;
        break;

        case 5:
        m = 1;
        break;

        case 6:
        m = 4;
        break;

        case 7:
        m = 6;
        break;

        case 8:
        m = 2;
        break;

        case 9:
        m = 5;
        break;

        case 10:
        m = 0;
        break;

        case 11:
        m = 3;
        break;
        
        case 12:
        m = 5;
        break;
    }

    if(year > 1699 && year < 1800){
        c = 4;
    }

    if(year > 1799 && year < 1900){
        c = 2;
    }

    if(year > 1899 && year < 2000){
        c = 0;
    }

    if(year > 1999 && year < 2100){
        c = 6;
    }

    if(year > 2099 && year < 2200){
        c = 4;
    }

    if(year > 2199 && year < 2300){
        c = 2;
    }

    if(year > 2299 && year < 2400){
        c = 0;
    }
    
    int b = 0;
    int sum = 0;

    y = year % 100;
    b = y / 4;
    sum = y + b;
    y = sum % 7;

    x = (y + m + c + date) % 7;
    
    if(year %4 == 0 && year % 100 != 0 || year % 400 == 0){
        if(m == 1 || m == 2){
            x = x - 1;
        }
    }
    
    switch(x){
        case -1:
            cout << "Saturday" << endl;
            break;

        case 0:
            cout << "Sunday" << endl;
            break;

        case 1:
            cout << "Monday" << endl;
            break;

        case 2:
            cout << "Tuesday" << endl;
            break;

        case 3:
            cout << "Wednesday" << endl;
            break;

        case 4:
            cout << "Thursday" << endl;
            break;

        case 5:
            cout << "Friday" << endl;
            break;

        case 6:
            cout << "Saturday" << endl;
            break;
    }
    return 0;
}