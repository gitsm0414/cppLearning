#include<iostream>
#include<string>

using namespace std;

/*
참고: 벡터를 이용하여 마스킹배열의 동적할당과정을 굳이 하지 않는 방법
#include <iostream>
#include <string>
#include <vector> // vector 사용을 위해 추가

using namespace std;

int main() {
    string s_input, s_output;
    if (!(cin >> s_input)) return 0; // 입력 실패 대비

    s_output = s_input;
    size_t len = s_input.length();

    // 동적 배열 대신 vector 사용 (크기는 len)
    vector<int> mask(len);

    cout << len << "개의 마스크 값(0 또는 1)을 입력하세요: ";
    for (size_t i = 0; i < len; i++) {
        cin >> mask[i];
    }

    for (size_t i = 0; i < len; i++) {
        if (mask[i] == 0) {
            s_output.at(i) = '_';
        }
    }

    cout << "결과: " << s_output << endl;

    // vector는 함수가 끝날 때 자동으로 메모리가 해제됩니다.
    return 0;
}
*/

int main(){
    string s_input, s_output;
    cin >> s_input;
    s_output = s_input;

    size_t len = s_input.length();

    int* mask = new int[len];

    for(size_t i = 0; i < len; i++){
        cin >> mask[i];
    }

    for(size_t i = 0; i < len; i++){
        if(mask[i] == 0){
            s_output.at(i) = '_';
        }
    }
    cout << s_output;

    delete[] mask;

    return 0;
}