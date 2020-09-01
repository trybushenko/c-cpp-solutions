#include <iostream>
#include <map>
#include <string>

/*
developer: Artem Trybushenko
language: cpp
*/

using namespace std;

/*
task: 
*/

int main(int argc, const char** argv) {
    map<int, string, greater<int>> mapOfTheSurnames;
    map<int, string, greater<int>> :: iterator it;
    mapOfTheSurnames[1931] = "Sraka";
    mapOfTheSurnames[1945] = "QWErty";
    mapOfTheSurnames[1960] = "zxcvbn";
    it = mapOfTheSurnames.lower_bound(1946);
    cout << it -> second << endl;
    it++;
    cout << it -> second << endl;
    return 0;
}   