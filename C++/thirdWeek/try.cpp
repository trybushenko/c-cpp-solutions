#include <iostream>
#include <string>
#include <map>

/*
developer: Artem Trybushenko
language: cpp
*/

using namespace std;

/*
task: 
*/

int main(int argc, const char** argv) {
    map<int, string> mymap;
    mymap[1965] = "Polina";
    mymap[1970] = "Antonina";
    map<int, string> :: iterator it = mymap.upper_bound(1900);
    it--;
    it--;
    cout << it -> first << " : " << it -> second << endl;
    return 0;
}