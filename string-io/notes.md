C방식 스트링
-char 배열을 선언해야함. 스트링의 맨 끝에는 항상 '\0' = NULL character로 끝남.('\n'과 헷갈리지 말길)

<string.h> or <cstring>안에 있음

라이브러리 안쓸 경우 참고
char s1[10]; //초기화 안되었으니 쓰레기값으로 참
char s2[10] = ""; 
char s3[10] = {}; 
char s4[10] = {'\0'}
//나머지는 0(NULL)로 초기화됨

cf. 배열 초기화를 = "asdf"이렇게하면 컴파일러가 끝에 '\0'을 알아서 추가해주지만, = {'a', 'b', 'c'}
 이렇게하면 엄밀히 말하자면 이는 스트링과 다르다. 그래서 cout을 이용했을 때 '\0'을 못찾아서 예상치못한 일이 일어날 수 있다.


C++스트링(Standard Class String)
include<string>
std::string s;


C++ string lexicographical comparison(사전적 비교)
>, <, <= , =>

-첫 번째 문자 비교: 두 문자가 다르면, 그 문자의 값이 작은 쪽이 "사전적으로 앞선(작은)" 문자열이 됩니다.
-문자가 같을 경우: 다음 문자로 넘어가서 다시 비교합니다.
-한쪽이 먼저 끝날 경우: 모든 문자가 같은데 한 문자열이 더 짧다면, 짧은 문자열이 더 작은 것으로 간주합니다. (예: "apple" vs "apples")

==, !=는 문자열의 단순 일치여부를 판단한다.

스트링의 사용
string str;
string str("string");
string str(aString);

str[i] or str.at(i) // returns read/write reference to character
//[i] 보다는 .at(i)가 좀더 안전한 방식인데, 왜냐하면 범위밖의 인덱스 접근을 미리 체크해주기 때문이다.
str.substr(position, length)

str.length()
str.empty()
str1 = str2;
str1 += str2;
str1 + str2

str.append(str1); //예시) firstname.append(" ").append(lastname)

str.insert(pos, str1)
str.erase(pos, length)

str.find(str1, pos = 0) //index pos부터 시작하여 처음으로 str1이 발생하는 idx를 리턴
str.find_first_of(str1, pos) // str1중에 있는 char가 처음 발견되는 위치 리턴
str.find_first_not_of(str1, pos) // str1중에 없는 char가 처음 발견되는 위치 리턴


c-string > c++ string object: 자동 형변환가능
반대방향은 불가능 explicit conversion 필요
ex) strcpy( aCstring, stringVar.c_str());

numbers >> string object
-string s = to_string(d*2);

string object >> numbers
stoi(), stof(), stod(), stol()


<cin 과 getline()을 함께 쓸 때 주의점>
int age;
string name;

cin >> age; // 이때 숫자 뒤의 '\n'은 아직 남아있기 때문에 버처를 비워줘야 getline()이 정상작동한다.
cin.ignore(100, '\n'); // 최대 100자 혹은 '\n'을 만날 때까지 버퍼를 비움
getline(cin, name);


<string parsing>
getline()세번째 인자의 특징
-중단점 설정: 지정한 문자를 만나는 즉시 입력을 중단하고, 그 전까지의 내용을 변수에 저장합니다.

--구분자 소모: 입력 버퍼에서 해당 구분자를 찾아 읽어내지만, 결과 문자열(str)에는 포함시키지 않고 버립니다. (다음 입력은 그 구분자 바로 다음 칸부터 시작됩니다.)

데이터 파싱(Parsing): CSV 파일(쉼표로 구분된 값)이나 특정 기호로 나뉜 데이터를 읽을 때 매우 강력합니다.


예시)
#include <iostream>
#include <string>
#include <sstream> // 문자열 파싱을 위해 사용

using namespace std;

int main() {
    string input = "홍길동,20,서울";
    stringstream ss(input); // 문자열을 스트림으로 변환
    string name, age, city;

    // 쉼표(',')를 기준으로 잘라서 읽기
    getline(ss, name, ',');
    getline(ss, age, ',');
    getline(ss, city); // 마지막은 엔터(기본값)까지 읽음

    cout << "이름: " << name << endl;
    cout << "나이: " << age << endl;
    cout << "도시: " << city << endl;

    return 0;
}
