#include<iostream>
using namespace std;

void increase(int& var);
void inverse(int& var);

int main(){
    int var;
    cin >> var;
    increase(var);
    cout << var << endl;
    inverse(var);
    cout << var << endl;

    return 0;
}

void increase(int& var){
    var+=1;
    return;
}
void inverse(int& var){
    var *= -1;
    return;
}