#include <iostream>
#include <vector>

using namespace std;

/*
На вход дано целое положительное число N. Выведите его в двоичной системе счисления без ведущих нулей.
*/

int main() {
    vector<int> v;
    int n;
    cin >> n;
    while (n > 0) {
        v.push_back(n % 2);
        n = n / 2;
    }
    for (int i = v.size() - 1; i >= 0; i--)
    {
        cout << v[i];
    }
    
    return 0;
    }