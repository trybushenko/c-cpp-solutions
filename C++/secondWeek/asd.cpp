#include <iostream>
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

int main(int argc, const char** argv) {
    int n;
    cin >> n;
    vector<int> month_day = { 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };
    vector<vector<string>> action(31);
    int current = 0;

  for (int j(0); j < n; ++j) {
    string x;
    cin >> x;
    if (x == "ADD") {
      int i;
      string s;
      cin >> i >> s;
      action[i - 1].push_back(s);
    }
    else if (x == "DUMP") {
      int i;
      cin >> i;
      cout << action[i - 1].size() << " ";
      for (auto k : action[i - 1])
        cout << k << " ";
      cout << '\n'; 
    }
    else if (x == "NEXT") {
      if (month_day[current % 12] > month_day[(current + 1) % 12]) {
        for (int i = month_day[(current + 1) % 12]; i < action.size(); ++i) {
          action[month_day[(current + 1) % 12] - 1].insert(end(action[month_day[(current + 1) % 12] - 1]),
            begin(action[i]), end(action[i]));
        }
      }
      action.resize(month_day[++current % 12]);

    }

  }
    return 0;
}