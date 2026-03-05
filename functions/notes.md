cout.setf(ios::showpoint); //실수형은 소수점을 항상 표기하라
cout.setf(ios::fixed);  //소tn점을 고정해서 표시해라
cout.precision(3);  //소수점 아래 3자리까지 표시하라

하지만 요즘은 이걸 더 많이 씀
#include <iomanip>

cout << fixed << setprecision(3) << x;


함수의 리턴값 또한 copy값, reference, pointer 등이 될 수 있다.

Returning reference
ex) double& func(double& var){
    retrurn var
};
참조값을 반환한다는 것은 값이 아닌 별명자체를 돌려주는 것.
참조값을 반환하려면 실제로 메모리에 존재하는 것을 반환해야한다. >> 지역 변수나 표현식 불가
>>함수 인자로 받은 변수, 전역 변수, 클래스 멤버 변수의 경우에 반환 가능하다.


#include <iostream>
using namespace std;
double& func( double& variable ) {
    variable++;
    return variable;
}
//리턴값의 타입이 맞지 않는다.
double& mal_func( double variable) {
    return variable; 
}
int main() {
    double dVar = 3.14;
    cout << dVar << endl;
    cout << func(dVar) << endl;
    cout << dVar << endl;

    double& dVar2 = mal_func(dVar); 

    //의도치 않은 동작이 일어날 수 있다.
    cout << "&dVar:" << &dVar << endl; 
    cout << "&dVar2:" << &dVar2 << endl;
}



헷갈릴 수 있는 용어
Formal parameters: 함수의 선언과 정의에서 나타남.
Arguments: 함수의 콜링이 일어날 때 전달되는 것. Formal parameters를 채우기 위한 것.


const reference parameter의 중요성
ex) void send_const_ref( const int& par1, const int& par2);
>> read-only로 파라미터를 설정한다. 중요한 관습.


C에서는 기능이 거의 동일한 함수도 이름을 다 다르게 써야함. 중복불가.

C++에서는 하나의 function name에 여러개의 function signatures를 배치할 수 있다.
function signatures: function name & parameter list (return type은 포함 x)


<functino overloading>
함수 콜링 과정에서 컴파일러는
1. fucntion signature의 정확한 일치가 있는지 확인한다.
2. 없다면, compatible match가 있는지 확인한다. 
>> 예를들어 arguments로 보내진 값이 5인데 파라미터는 더블이라면 automatic type conversion을 해준다.
3. 만약 ambiguity가 있다면 컴파일러는 에러를 일으킨다!


<default arguments>
함수의 선언(prototype)과정에서 설정할 수 있다. (definition에서 말고.)
이때 default argument는 반드시 파라미터 중 맨 오른쪽부터 순서대로 설정해야한다.(만약 default argument가 중간에 끼거나 하면 오류)


<inline functions>
컴파일러가 함수호출을 하지 않고 코드에 바로 심어버린다.(코드로 치환시켜버린다.)
ex) inline int add(int a, int b){return a+b;}

function call이 발생하지 않아 overhead를 없앨 수 있다.

cf. fucntion call overhead
1. 스택에 매개변수 push
2. return address 저장
3. 함수로 점프
4. 함수 종료 후 복귀

하지만 항상 이걸 보장할 순 없다. 예를들어 코드가 재귀함수이거나, 너무 크고 복잡하다면 컴파일러가 inline을 거부한다.
따라서 작고 간단한 함수의 경우에 활용할 수 있다.
그러나  g++에서는 -O2에서 이미 컴파일러가 알아서 해주긴한다.

그래서 C++에서 inline은 주로 성능보다는 "링크 문제 해결"때문에 쓰인다고한다.
>> 선 핵심 요약: 
inline은 "이 함수 정의가 여러 번 있어도 괜찮다"는 규칙을 만들어서 링크 에러를 막는다.
그래서 C++에서 헤더에 함수 구현 넣을 때 inline을 많이 쓴다.
>> 설명

예를 들어 add.h:

int add(int a, int b){
    return a + b;
}

그리고 이 헤더를 여러 cpp 파일에서 include 하면: #include "add.h"

컴파일 후에는 file1.cpp 안에도 add()가 하나 생기고 file2.cpp 안에도 add()가 하나 생긴다

그러면 링커가 이렇게 말한다. add 함수가 여러 개 정의되어 있다 (multiple definition)

이게 링크 에러다.

여기서 inline을 붙이면:

inline int add(int a, int b){
    return a + b;
}

컴파일러가 "이 함수는 여러 파일에 정의가 있어도 괜찮다"라고 이해한다.

그래서 multiple definition 에러가 안 난다.