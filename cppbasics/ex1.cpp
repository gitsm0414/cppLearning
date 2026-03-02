#include<iostream>

using namespace std;

int main(){
    float celsius, fahranheit;

    cout << "How many Celsius now?\n";
    cin >> celsius;
    fahranheit = celsius*9/5 + 32;

    cout << "Then it is " << fahranheit << " degrees Fahranheit." << endl;
    return 0;
}