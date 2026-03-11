
//행맨 assignment관련하여 참고할 만한 함수. 마스크배열을 업데이트하고, 만약 다 맞췄다면 flag를 false로 바꿔 게임을 종료시키도록 한다.
//추가로 string::npos나, while문에서의 word.find(c, i)의 활용 등을 참고하자.
#include<string>
using namespace std;

void update_mask(string word, int* mask, char c, bool& flag) {
    int i = 0;
    
    // 1. 단어에서 입력받은 문자 c의 위치를 모두 찾아 mask를 1로 변경
    while ((i = word.find(c, i)) != string::npos) {
        mask[i] = 1;
        i++;
    }

    int sum = 0;
    // 2. 현재까지 맞춘 글자의 총 개수를 계산
    for (int j = 0; j < word.length(); j++) {
        sum += mask[j];
    }

    // 3. 모든 글자를 다 맞췄다면 flag를 false로 설정하여 게임 종료 신호를 보냄
    if (sum == word.length()) {
        flag = false;
    }
}