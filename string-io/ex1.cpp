#include<iostream>
#include<string>

using namespace std;

int main(){
    string id, name, score;

    cout << "type your student ID: ";
    cin >> id;

    cout << "type your name and score: "; //입력형식은 이름:스코어여야 함
    cin.ignore(100, '\n');
    getline(cin, name, ':');
    getline(cin, score);

    cout << name << '(' << id << ")\'s score is" << score << endl; 
}