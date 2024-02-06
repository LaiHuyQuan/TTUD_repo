#include <iostream>
using namespace std;

int check(int a)
{
    int count = 0;
    for(int i = 1; i <= a; i++){
        if (a % i == 0) count++;
    }

    if (count % 2 != 0 && count > 1){
        return 1;
    }
    
    return 0;
}

int solve(int a, int b)
{   
    int sol = 0;
    for (int i = a; i <= b; i++){
        sol += check(i);
    }
    return sol;
}

int main(){
    int a, b;
    cin >> a >> b;
    int c = solve(a, b);
    cout << c;
}