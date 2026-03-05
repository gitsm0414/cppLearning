/*
Exercise 3

Define the functions(getNumbers, getArray, blackjack)
▪ getNumbers: Take 2 integers and assign them to variables
▪ getArray: Allocate entered elements after array dynamic assignment based on size
▪ blackjack: Given the number written on N cards, find the sum of the three cards as close as possible to M without exceeding M
*/

/*
사실 possible_sum을 레퍼런스로 넘길 이유가 굳이 없다.

int blackjack(int* arr, int n, int m){
    int best = 0;

    for(int i = 0; i < n-2; i++){
        for(int j = i+1; j < n-1; j++){
            for(int k = j+1; k < n; k++){
                int sum = arr[i] + arr[j] + arr[k]; // 이렇게 sum도 굳이 for문 밖에서 미리 정의 하지 않고 그때그때 해도 된다.

                if(sum <= m && sum > best){
                    best = sum;
                    if(best == m) return best;
                }
            }
        }
    }
    return best;
}

이러면 main함수 안에서:
possible_sum = blackjack(cards, N, M)

방식의 차이이긴 하다.
*/

#include<iostream>
using namespace std;

void getNumbers(int& n, int& m);
int* getArray(int n);
void blackjack(int* arr, int& possible_sum, int n, int m);


int main(){
    int N, M;
    int possible_sum = 0;

    getNumbers(N, M);
    int* cards = getArray(N);

    blackjack(cards, possible_sum, N, M);
    cout << possible_sum << endl;

    delete[] cards;
    return 0;
}

void getNumbers(int& n, int& m){
    cout << "enter n, m: ";
    cin >> n >> m;
    return;
}
int* getArray(int n){
    int* arr = new int[n];

    for(int i = 0; i < n; i++){
        cin >> arr[i];
    }
    return arr;
}
void blackjack(int* arr, int& possible_sum, int n, int m){
    int cur_sum = 0;

    for(int i = 0; i < n-2; i++){
        for(int j = i+1; j < n-1; j++){
            for(int k = j+1; k < n; k++){

                cur_sum = arr[i] + arr[j] + arr[k];

                if(possible_sum < cur_sum && cur_sum <= m){
                    possible_sum = cur_sum;
                    if(possible_sum == m) return;
                }
                
            }
        }
    }
    return;
}