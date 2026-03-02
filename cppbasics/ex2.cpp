#include<iostream>

using namespace std;

int main(){
    int x, y, z;

    cout << "Enter 3 nums" << endl;
    cin >> x >> y >> z;

    auto result = (static_cast<float>(x+y))/z; //static_cast는 컴파일과정에서 체크해줌. 이걸 이용해 컴파일 하는 습관 들이기

    cout << "Result: " << result << endl;

}