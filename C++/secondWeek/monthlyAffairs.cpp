#include <iostream>
#include <vector>
#include <string>

/*
developer: Artem Trybushenko
language: cpp
*/

using namespace std;

/*
task: У каждого из нас есть повторяющиеся ежемесячные дела, 
каждое из которых нужно выполнять в конкретный день каждого месяца: оплата счетов за электричество, абонентская плата за связь и пр. 
Вам нужно реализовать работу со списком таких дел на месяц, а именно, реализовать набор следующих операций:
ADD i s - Назначить дело с названием s на день i текущего месяца.
DUMP i - Вывести все дела, запланированные на день i текущего месяца.
NEXT - Перейти к списку дел на новый месяц. 
При выполнении данной команды вместо текущего (старого) списка дел на текущий месяц создаётся 
и становится активным (новый) список дел на следующий месяц: все дела со старого списка дел копируются в новый список. 
После выполнения данной команды новый список дел и следующий месяц становятся текущими, 
а работа со старым списком дел прекращается. При переходе к новому месяцу необходимо обратить внимание на разное количество дней в месяцах:
если следующий месяц имеет больше дней, чем текущий, «дополнительные» дни необходимо оставить пустыми (не содержащими дел);
если следующий месяц имеет меньше дней, чем текущий, дела со всех «лишних» дней необходимо переместить на последний день следующего месяца.

Замечания
Историю списков дел хранить не требуется, работа ведется только с текущим списком дел текущего месяца. 
Более того, при создании списка дел на следующий месяц, он «перетирает» предыдущий список.
Обратите внимание, что количество команд NEXT в общей последовательности команд при работе со списком дел может превышать 11.
Начальным текущим месяцем считается январь.
Количества дней в месяцах соответствуют Григорианскому календарю с той лишь разницей, что в феврале всегда 28 дней.

Формат ввода
Сначала число операций Q, затем описания операций.
Названия дел s уникальны и состоят только из латинских букв, цифр и символов подчёркивания. 
Номера дней i являются целыми числами и нумеруются от 1 до размера текущего месяца.

Формат вывода
Для каждой операции типа DUMP в отдельной строке выведите количество дел в соответствующий день, 
а затем их названия, разделяя их пробелом. Порядок вывода дел в рамках каждой операции значения не имеет.

Пример:
Ввод:
    12
    ADD 5 Salary
    ADD 31 Walk
    ADD 30 WalkPreparations
    NEXT
    DUMP 5
    DUMP 28
    NEXT
    DUMP 31
    DUMP 30
    DUMP 28
    ADD 28 Payment
    DUMP 28

Вывод:
    1 Salary
    2 WalkPreparations Walk
    0
    0
    2 WalkPreparations Walk
    3 WalkPreparations Walk Payment
*/

void add(vector<string>& affairs, int index, string task) {
    string blankLine = " ";
    if (affairs[index - 1].length() == 0) {
        affairs[index - 1] = task;
    }
    else {
        affairs[index - 1] += blankLine + task;
    }
    
}

string dump(vector<string> affairs, int index) {
    int quantityOfTasks = 0;
    for (int i = 0; affairs[index - 1][i] != '\0'; i++)
    {
        if (affairs[index - 1][i] == ' ') quantityOfTasks++; 
    }
    quantityOfTasks++;
    return to_string(quantityOfTasks) + " " + affairs[index - 1];
}

void printVector(vector<string> affairs) {
    for (auto str: affairs) cout << str << " ";
}


void next(vector<string>& affairs, int numberOfDays) {
    string blankLine = " ";
    if  (affairs.size() > numberOfDays) {
        for (int i = numberOfDays; i < affairs.size(); i++) {
            if (affairs[numberOfDays].length() == 0) if (affairs[i].length() != 0) affairs[numberOfDays] = affairs[i];
            else affairs[numberOfDays] += blankLine + affairs[i];
        }
        affairs.resize(numberOfDays);
    }
    else {
        affairs.resize(numberOfDays);
    }
}
int main() {
    int q;
    cin >> q;
    vector<int> numberOfDays{31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    int currentMonth = 0;
    vector<string> affairs;
    affairs.resize(numberOfDays[currentMonth]);
    string condition, stringIndex, task;
    for (int i = 0; i < q; i++) {
        cin >> condition;
        if (condition == "ADD") {
            cin >> stringIndex >> task;
            add(affairs, atoi(stringIndex.c_str()), task);
        }
        else if (condition == "DUMP") {
            cin >> stringIndex;
            cout << dump(affairs, atoi(stringIndex.c_str())) << endl;
        }
        else if (condition == "NEXT") {
            currentMonth++;
            next(affairs, numberOfDays[currentMonth]);
        }
    }
    return 0;
}