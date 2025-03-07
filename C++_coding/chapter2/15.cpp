#include <iostream>
#include <cstring>
using namespace std;

int main() {
    string str = "fyy";
    str += "is";
    str += 'a';

    cout << str << endl;
    cout << str.c_str() << endl;
    cout << str.size() << endl;
    cout << str.empty() << endl;
    cout << str.substr(1, 2) << endl;
    str.clear();
    cout << str << endl;
    
    return 0;
}