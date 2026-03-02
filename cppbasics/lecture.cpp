#include<cinttypes>
#include<iostream>
#include<typeinfo>

using namespace std;

int main(){

    size_t int64_t_size = sizeof(int64_t); // int64_t etc. -> from cinttypes or inttypes.h 
    size_t long_long_size = sizeof(long long);

    string s = R"(\t\\t\n)"; // raw string literally.. 'R' is important point

    cout << int64_t_size << '\n' << long_long_size << endl;
    cout << s << endl;

    float f1 = 3.0;
    decltype(f1*8) f2 = 2.0; 
    cout << f2 << " is type of.. " << typeid(f2).name() << endl;

    return 0;
}