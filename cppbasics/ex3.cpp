#include<iostream>
using namespace std;

int main(){
    
    int int_input;
    cout << "input odd size: " << endl;
    while(true){
        cin >> int_input;
        if(int_input % 2 == 0 || int_input < 0){
            cout << "wrong input\n";
        }else break;
    }
    
    for(int i = 0; i < int_input; i++){
        if(i+1 < int_input - i){
            cout << i+1 << " ";
        }else{
            cout << int_input - i << " ";
        }
    }
    
    
}