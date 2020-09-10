#include <iostream>
#include <fstream>
#include <iomanip>

/*
developer: Artem Trybushenko
language: cpp
*/

using namespace std;

/*
task:   В файле input.txt записаны вещественные числа, 
        по одному на строчку. На стандартный вывод напечатайте эти числа в том же порядке,
        по одному на строке, но сделайте так, чтобы у каждого из них было ровно три знака после десятичной точки.

        Пример ввода 1:
            5
            0.34567
            10.4
        Пример вывода 1:
            5.000
            0.346
            10.400

        Пример ввода 2:
            3.33353
            3.333
            3.3
        Пример вывода 2:
            3.334
            3.333
            3.300
*/

int main() {
    ifstream input("outputWithPrecision/input.txt");
    double a;
    if (input) {
        while(input >> a) {
            cout << fixed << setprecision(3);
            cout << a << endl;
        }
    }
    return 0;
}