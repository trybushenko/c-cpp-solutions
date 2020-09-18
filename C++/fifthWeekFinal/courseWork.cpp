#include <iostream>
#include <string>
#include <exception>
#include <set>
#include <map>
#include <vector>
#include <sstream>


/*
developer: Artem Trybushenko
language: cpp
*/

using namespace std;

/*
task:   Необходимо написать программу на С++, которая реализует работу с простой базой данных (сокращённо «БД»).
        Программа будет общаться с пользователем через стандартный ввод и вывод (потоки stdin и stdout).
        Будем хранить в нашей БД пары вида: дата, событие. Определим дату как строку вида Год-Месяц-День, 
        где Год, Месяц и День — целые числа.
        Событие определим как строку из произвольных печатных символов без разделителей внутри (пробелов, табуляций и пр.). 
        Событие не может быть пустой строкой. В одну и ту же дату может произойти много разных событий, 
        БД должна суметь их все сохранить. Одинаковые события, произошедшие в один и тот же день, 
        сохранять не нужно: достаточно сохранить только одно из них.
        
        Наша БД должна понимать определённые команды, чтобы с ней можно было взаимодействовать:
            - добавление события:                        Add Дата Событие
            - удаление события:                          Del Дата Событие
            - удаление всех событий за конкретную дату:  Del Дата
            - поиск событий за конкретную дату:          Find Дата
            - печать всех событий за все даты:           Print

        Все команды, даты и события при вводе разделены пробелами. Команды считываются из стандартного ввода. 
        В одной строке может быть ровно одна команда, но можно ввести несколько команд в несколько строк. 
        На вход также могут поступать пустые строки — их следует игнорировать 
        и продолжать обработку новых команд в последующих строках.

        Добавление события (Add Дата Событие)
            При добавлении события БД должна его запомнить и затем показывать его при поиске (командой Find) 
            или печати (командой Print). Если указанное событие для данной даты уже существует, 
            повторное его добавление нужно игнорировать. В случае корректного ввода (см. раздел «Обработка ошибок ввода») 
            программа ничего не должна выводить на экран.
        
        Удаление события (Del Дата Событие)
            Команда должна удалить добавленное ранее событие с указанным именем в указанную дату, 
            если оно существует. Если событие найдено и удалено, 
            программа должна вывести строку «Deleted successfully» (без кавычек). 
            Если событие в указанную дату не найдено, программа должна вывести строку «Event not found» (без кавычек).

        Удаление нескольких событий (Del Дата)
            Команда удаляет все ранее добавленные события за указанную дату. 
            Программа всегда должна выводить строку вида «Deleted N events», 
            где N — это количество всех найденных и удалённых событий. 
            N может быть равно нулю, если в указанную дату не было ни одного события.

        Поиск событий (Find Дата)
            Найти и распечатать ранее добавленные события в указанную дату. 
            Программа должна вывести на печать только сами события, по одному на строке. 
            События должны быть отсортированы по возрастанию в порядке сравнения строк между собой (тип string).

        Печать всех событий (Print)
            С помощью этой команды можно показать полное содержимое нашей БД. 
            Программа должна вывести на печать все пары Дата Событие по одной на строке. 
            Все пары должны быть отсортированы по дате, 
            а события в рамках одной даты должны быть отсортированы по возрастанию в порядке сравнения строк между собой (тип string). 
            Даты должны быть отформатированы специальным образом: ГГГГ-ММ-ДД, где Г, М, Д — это цифры чисел года, месяца и дня соответственно. 
            Если какое-то число имеет меньше разрядов, то оно должно дополняться нулями, например, 0001-01-01 — первое января первого года. 
            Вам не понадобится выводить дату с отрицательным значением года.    

        Обработка ошибок ввода
            Ввод в этой задаче не всегда корректен: некоторые ошибки ввода ваша программа должна корректно обрабатывать.

            Какие ошибки ввода нужно обрабатывать
                Если пользователь ввёл неизвестную команду, 
                то программа должна об этом сообщить, выведя строку «Unknown command: COMMAND», 
                где COMMAND — это та команда, которую ввёл пользователь. 
                Командой считается первое слово в строке (до пробела).

                Если дата не соответствует формату Год-Месяц-День, 
                где Год, Месяц и День — произвольные целые числа, 
                то программа должна напечатать «Wrong date format: DATE», 
                где DATE — это то, что пользователь ввёл вместо даты (до пробела). 
                Обратите внимание, что части даты разделяются ровно одним дефисом, 
                а сама дата не должна содержать лишних символов ни перед годом, ни после дня. 
                Части даты не могут быть пустыми, но могут быть нулевыми и даже отрицательными.

                Если формат даты верен, необходимо проверить валидность месяца и дня.
        
        Примеры:
            Add 0-1-2 event1
            Add 1-2-3 event2
            Find 0-1-2
            
            Del 0-1-2
            Print
            Del 1-2-3 event2
            Del 1-2-3 event2

        Вывод:
            event1
            Deleted 1 events
            0001-02-03 event2
            Deleted successfully
            Event not found

*/

struct Event {
    public:
        string event;
        Event(string _event) {
            if (_event != "") event = _event; 
        }
};
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

bool EnsureEqualSlashAndSkip(istream& stream) {
    if (stream.peek() != '-') {
        throw runtime_error("Invalid argument");
    }
    stream.ignore(1); 
}

bool operator<(const Event& lhs, const Event& rhs) {
    return lhs.event < rhs.event;
}

bool operator<(const Date& lhs, const Date& rhs) {
    if (lhs.GetYear() == rhs.GetYear()) {
        if (lhs.GetMonth() == rhs.GetMonth) {
            if (lhs.GetDay() == rhs.GetDay()) return false;
            else return lhs.GetDay() < rhs.GetDay();
        }
        else return lhs.GetMonth() < rhs.GetMonth();
    } return lhs.GetYear() < rhs.GetYear();
}

istream& operator>>(istream& stream, Date& date) {
    int year, month, day;
    stream >> year;
    EnsureEqualSlashAndSkip(stream);
    stream >> month;
    EnsureEqualSlashAndSkip(stream);
    stream >> day;
    EnsureEqualSlashAndSkip(stream);
    date = Date(year, month, day);
    return stream;
}

ostream& operator<<(ostream& stream, const Date& date) {
    stream << setw(4) << setfill('0') << date.GetYear() << '-' 
           << date.GetMonth() << '-' << date.GetDay();
    return stream;
}
class Database {
    public:
        void AddEvent(const Date& date, const string& event) {
            dateEventMap[date].insert(event);
        }
        bool DeleteEvent(const Date& date, const string& event) {
            set<Event> needed_set = dateEventMap[date];
            if (needed_set.count(event)) {
                needed_set.erase(event);
                cout << "Deleted successfully" << endl;
            } else cout << "Event not found" << endl; 
        }
        int  DeleteDate(const Date& date) {
            int len = dateEventMap[date].size();
            dateEventMap.erase(date);
            cout << "Deleted " << len << " events" << endl;
        }
        //todo нужно перегрузить оператор сравнения для структуры Event, - done 
        //также нужно перегрузить оператор вывода, оператор ввода, оператор сравнения - done для класса Date
        Date Find(const Date& date) const {
            if (dateEventMap.count(date) > 0) {
                for (const auto& event : dateEventMap.at(date)) cout << event << endl;
            }
        }
        void Print() const {
            for (const auto& kv : dateEventMap) {
                cout << kv.first << " ";
                for (const auto& event : kv.second) cout << event << " ";
                cout << endl;
            }
        }
    private:
        map<Date, set<Event>> dateEventMap;
};

int main() {
  Database db;
    
  string command;
  while (getline(cin, command)) {
    
  }

  return 0;
}