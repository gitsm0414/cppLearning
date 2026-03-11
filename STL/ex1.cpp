#include<iostream>
#include<vector>
using namespace std;

int main(){
    vector<int> v;

    while(true){
        int n;
        cout << "Input number: ";
        cin >> n;
        if(n == -1) break;

        v.push_back(n);
    }

    int is_reverse; 
    cout << "select direction: ";
    cin >> is_reverse; //0 or 1

    if(is_reverse == 1){//반대방향
        vector<int>::reverse_iterator r_it;
        for(r_it = v.rbegin(); r_it != v.rend(); r_it++){
            cout << *r_it << ' ';
        }
    }else if(is_reverse == 0){//정방향
        vector<int>::iterator it;
        for(it = v.begin(); it != v.end(); it++){
            cout << *it << ' ';
        }
    }

    return 0;
}