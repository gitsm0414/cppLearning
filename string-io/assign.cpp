#include<iostream>
#include<string>
using namespace std;

/*
제미나이: 맞은 문자는 최초 한번만 체크되는 로직 적용 및 함수를 이용해 메인함수의 로직 간단화 및 구조화
이 코드와 내가 쓴 코드를 잘 비교해보자.

#include <iostream>
#include <string>

using namespace std;

// 단어를 업데이트하고 일치 여부를 반환하는 함수
bool update_output(const string& target, string& output, char guess) {
    bool found = false;
    for (size_t i = 0; i < target.length(); i++) {//여기서 같은문자로 여러번 맞춰도 기회소모되지 않는다는건 나와 동일하다.
        if (target[i] == guess) {
            output[i] = guess;
            found = true;
        }
    }
    return found;
}

int main() {
    string s_input, s_output;
    char c_input;
    int chance = 10;

    cout << "Input word: ";
    cin >> s_input;
    s_output = string(s_input.length(), '_');

    while (chance > 0 && s_input != s_output) {
        cout << "\nGuess: ";
        cin >> c_input;

        if (!update_output(s_input, s_output, c_input)) { // 여기가 내코드와 비교했을 때 다른 핵심 부분
            chance--;
            cout << "Wrong! Remaining: " << chance << endl;
        }
        cout << s_output << endl;
    }

    cout << (s_input == s_output ? "Correct!" : "You lose!") << endl; // 여기도
    return 0;
}
*/

int main(){
    string s_input;
    char c_input;
    int chance = 10;
    size_t len;
    bool found;

    cout << "Input word for hangman: ";
    cin >> s_input;
    len = s_input.length();
    string s_output(len, '_');
    

    while(chance){//틀렸을 때 기회소모
        cin >> c_input;

        found = false;
        for(size_t i = 0; i < len; i++){//이경우엔 맞은 문자를 여러번 입력해도 기회가 소모되지 않는다.
            if(c_input == s_input[i]){
                s_output[i] = c_input;
                found = true;
            }
        }
        cout << s_output << '\n';

        if(s_input == s_output){
            cout << "correct!\n";
            return 0;
        }

        if(!found) chance--;
    }
    cout << "You lose!\n";

    return 0;
}