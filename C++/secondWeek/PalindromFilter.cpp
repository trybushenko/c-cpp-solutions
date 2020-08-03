#include <iostream>
#include <vector>
#include <string>

using namespace std;

vector<string> PalindromFilter(vector<string> words, int minLength) {
    vector<string> filtered;
    for (int i = 0; i < words.size(); i++)
    {
        if (words[i].size() < minLength) continue;
        else {
            bool flag = false;
            flag = IsPalindrom(words[i]);
            if (flag == true) filtered.push_back(words[i]);
        }
    }
    return filtered;
}

//функция правильно написана, поэтому ошибка не в ней
bool IsPalindrom(string str) {
    if (str == "") return true;
    else if (str.size() == 1) return true;
    else {
        int len = str.size();
        for (int i = 0; i < len/2; i++)
        {
            if (str[i] != str[len-i-1]) return false;
        }
         return true;
    }
}
//fix bugs
// что-то не так с вектором и вызовом функции
int main() {
    vector<string> palindromArray{"abacaba", "aba"};
    cout << PalindromFilter(palindromArray, 5) << endl;
    return 0;
}