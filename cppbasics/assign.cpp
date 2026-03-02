#include<iostream>
#include<algorithm> //to use 'min()'
using namespace std;

int main(){
    int odd_num;
    

    //이건 인풋이 0 이하이거나 정수가 아닌 타입일 경우를 베재했음.
    //추후 수정 필요
    while(true){
        cout << "type odd number: ";
        cin >> odd_num;
        if(odd_num % 2 == 0){
            cout << "wrong number\n";
        }else break;
    }
    
    //memory allocation of 2rd dimention array
    int row_size = odd_num;
    int cul_size = odd_num;

    int** arr = new int*[row_size];
    for(int i=0; i < row_size; i++){
        arr[i] = new int[cul_size];
    }


    //printing the pyramid of numbers
    int minimum;
    for(int i = 0; i < row_size; i++){
        for(int j = 0; j < cul_size; j++){
            minimum = min(min(i+1, j+1), min(row_size - i, cul_size - j));
            arr[i][j] = minimum;

            cout << arr[i][j] << " ";
            if(j == cul_size -1) cout << endl;
        }
    }

    //memory dellocation of 2rd dimention array
    for(int i=0; i < row_size; i++){
        delete [] arr[i];
    }
    delete [] arr;
}