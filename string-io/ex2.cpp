#include<iostream>
#include<string>

using namespace std;

/*
#include <iostream>
#include <string>
#include <algorithm> // reverse 함수를 위해 필요

using namespace std;

int main() {
    string s;
    getline(cin, s);

    // 원본 문자열을 그 자리에서 바로 뒤집음
    reverse(s.begin(), s.end());

    cout << s;
    return 0;
}
*/


int main(){
    string s_input, s_output;
    getline(cin, s_input);

    int len = static_cast<int>(s_input.length());

    s_output = "";
    for(int i = len-1; i >= 0; i--){//이 방법은 계속해서 스트링크기를 재할당해야하기 때문에 위의 방법을 쓰는게 좋다.
        s_output += s_input.at(i);
    }

    cout << s_output;

    return 0;
}