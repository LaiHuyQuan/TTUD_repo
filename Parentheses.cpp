#include<bits/stdc++.h>
#include<stack>
#include<string>

using namespace std;

int main() {
    string strIn;
    int i = 0;
    stack<char> database;
    bool result;
    char m;
    char checkChar;

    cin >> strIn;
    for(i = 0; i <= strIn.length(); i++) {
        checkChar = strIn[i];

        if (checkChar == '(' || checkChar == '[' || checkChar == '{'){
            database.push(checkChar);
        }

        if (checkChar == ')' || checkChar == ']' || checkChar == '}'){
            if (database.empty()){
                result = false;
                break;
            }
            m = database.top();
            database.pop();
            if ((checkChar == ')' && m == '(') || (checkChar == ']' && m == '[') ||  (checkChar == '}' && m == '{') ){
                result = true;
            }
            else {
                result = false;
                break;
            }    
        }
    }
    if (!database.empty()) result = false;
    cout << result;
}