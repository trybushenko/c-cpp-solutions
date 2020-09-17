#include <iostream>
#include <string>

/*
developer: Artem Trybushenko
language: cpp
*/

using namespace std;

/*
task: 
*/

struct Event {
    public :
        string event; 
        Event(const string& _event) {
            if (_event != "") event = _event;
        }
};

bool operator==(const Event& lhs, const Event& rhs) {
    return lhs.event == rhs.event;
}
bool operator==(const Event& lhs, const string& rhs) {
    return lhs.event == rhs;
}
bool operator==(const string& lhs, const Event& rhs) {
    return lhs == rhs.event;
}

int main(int argc, const char** argv) {
    Event event1("string");
    Event event2("string");
    string compare = "string";
    bool flag = event1 == event2;
    cout << (event1 == event2) << flag;
    return 0;
}