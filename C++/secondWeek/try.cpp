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
    bool boolean;
    map<string, string> m;
    m["Ukraine"] = "Kyiv";
    boolean = (m.at("Ukraine") == "Kyiv");
    cout << boolean << endl;
    return 0;
}