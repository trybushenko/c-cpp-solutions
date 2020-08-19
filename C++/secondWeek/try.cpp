#include <iostream>
#include <map>
#include <algorithm>
#include <vector>
#include <string>       

/*
developer: Artem Trybushenko
language: cpp
*/

using namespace std;

/*
task: 
*/

void printMap(const map<int, vector<string>>& busStopsMap) {
    for (auto kv: busStopsMap) {
        cout << kv.first << " : ";
        for (auto kvSecond: kv.second) {
            cout << kvSecond << ", ";
        }
    }
}

int main() {
    map<int, vector<string>> busStopsMap;
    busStopsMap[5].push_back("qwerty");
    busStopsMap[5].push_back("asdfgh");
    busStopsMap[5].push_back("zxcvbn");
    busStopsMap[5].push_back("qazwsx");
    busStopsMap[5].push_back("wsxedc");
    busStopsMap[5].push_back("edcrfv");
    printMap(busStopsMap);
    return 0;
}