/*
Define functions (swap, selectionSort, printArray)

Implementation details
▪ All elements of arr are rand()%100
▪ Prints all the elements of arr before selectionSort and after selectionSort
▪ The seed for initializing the array is received as an input.
*/


#include<iostream>
#include<cstdlib>

using namespace std;
const int SIZE = 30;

//실제 cpp에서는 <utility> or <algorithm>에서 swap(a,b)를 사용할 수 있다.
void swap(int& a, int&b){
    int temp = a;
    a = b;
    b = temp;
    //return; 이 void 함수에서는 굳이 필요 없다. 중간에 리턴하고 싶지 않은 이상.
}
/*
청므에 이렇게 했었는데 이건 마치 버블소트마냥 한다. min값의 설정과 swap을 할 타이밍을 제대로 이해하자. 개념 이해 확실히
void selectionSort(int* arr, const int n){
    for(int i = 0; i < n-1; i++){
        int min = arr[i];

        for(int j = i+1; j < n; j ++){
            if(arr[j] < min){
                min = arr[j];
                swap(arr[i], arr[j]);   
            }
        }
    }
    return;
}
*/
void selectionSort(int* arr, int n){ // 파라미터를 굳이 const int n으로 할 필요없다. 어차피 밸류 카피로 전달되니까.
    for(int i = 0; i < n-1; i++){
        //int min = arr[i]; 또하나의 실수, min_idx = i 로 설정했으니 min값을 따로 선언할 필요없다.
        //그리고 하나더, min이란 변수 이름은 <algoritm>에 있는 함수이름과 헷갈릴 수 있다.
        int min_idx = i;
        for(int j = i+1; j < n; j ++){
            if(arr[j] < arr[min_idx]){
                min_idx = j;
            }
        }
        if(min_idx != i) swap(arr[i], arr[min_idx]);
    }
    //return; 이 void 함수에서는 굳이 필요 없다. 중간에 리턴하고 싶지 않은 이상.
}

void printArray(int* arr, int n){
    for(int i = 0; i < n; i++){
        cout << arr[i] << ' ';
    }
    cout << '\n';
}


int main(){
    unsigned int seed;
    cout << "enter seed: ";
    cin >> seed;
    srand(seed);

    int arr[SIZE];
    for(int i = 0; i < SIZE; i++){
        arr[i] = rand()%100;
    }

    //print before sort
    printArray(arr, SIZE);

    selectionSort(arr, SIZE);

    //print after sort
    printArray(arr, SIZE);

    return 0;
}