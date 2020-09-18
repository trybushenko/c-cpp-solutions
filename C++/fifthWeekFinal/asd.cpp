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

class Date {
    public:
        Date(int _year, int _month, int _day) {
            if (_month > 12 || _month < 1) throw runtime_error("Month value is invalid: " + to_string(_month));
            else {
                if (_day < 1 || _day > 31) throw runtime_error("Day value is invalid: " + to_string(_day));
                else {
                    year = _year;
                    month = _month;
                    day = _day; 
                }
            }
        }
        int GetYear() const {return year;}
        int GetMonth() const {return month;}
        int GetDay() const {return day;}
        void SetYear(int _year) {year = _year;}
        void SetMonth(int _month) {
            if (_month > 12 || _month < 1) throw runtime_error("Month value is invalid: " + to_string(_month));
            else month = _month;
            }
        void SetDay(int _day) {
            if (_day < 1 || _day > 31) throw runtime_error("Day value is invalid: " + to_string(_day));
            else day = _day;
        }
    private:
        int year;
        int month;
        int day;
};

bool operator<(const Date& lhs, const Date& rhs) {
    if (lhs.GetYear() == rhs.GetYear()) {
        if (lhs.GetMonth() == rhs.GetMonth()) {
            if (lhs.GetDay() == rhs.GetDay()) return false;
            else return lhs.GetDay() < rhs.GetDay();
        }
        else return lhs.GetMonth() < rhs.GetMonth();
    } return lhs.GetYear() < rhs.GetYear();
}


int main(int argc, const char** argv) {
    Date date1(2020, 10, 18);
    Date date2(2020, 9 ,18);
    bool check = (date2 < date1);
    cout <<  check << endl;
    return 0;
}