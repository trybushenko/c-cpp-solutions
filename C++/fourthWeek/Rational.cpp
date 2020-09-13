#include <iostream>
#include <string>
#include <algorithm>    
/*
developer: Artem Trybushenko
language: cpp
*/

using namespace std;

/*
task:   В этой задаче вам надо разработать класс для представления рациональных чисел 
        и внедрить его в систему типов языка С++ так, чтобы им можно было пользоваться естественным образом. 
        Задание состоит из нескольких частей. К каждой части приложен файл с заготовкой программы, 
        который имеет следующую структуру:
            #include <iostream>
            using namespace std;

            // Комментарии, которые говорят, что именно нужно реализовать в этой программе

            int main() {
                // Набор юнит-тестов для вашей реализации
                cout << "OK" << endl;
                return 0;
            }
        Вам нужно, не меняя тело функции main, реализовать то, что предложено в комментариях, 
        так, чтобы ваша программа выводила на экран сообщение OK. 
        Функция main содержит ряд юнит-тестов, которые проверяют правильность вашей реализации. 
        Если эти тесты находят ошибку в вашей реализации, то вместо OK программа выведет подсказку о том, 
        что именно работает неправильно.
        Когда ваша программа начнёт выводить OK, можете отправлять свой файл на проверку. 
        Ваша реализация будет тестироваться на другом, более полном наборе тестов. 
        То есть, если ваша программа выводит OK, то это не даёт гарантии, что ваша реализация будет принята тестирующей системой. 
        В случае неудачной посылки тестирующая система также выдаст вам подсказку о том, какая именно часть реализации работает неправильно.
        Внимательно изучите набор юнит-тестов для каждой заготовки решения. 
        Тесты описывают требования, предъявляемые к вашей реализации, которые могут быть не указаны в условии задач
        На проверку можно отправлять весь файл с вашей реализацией: функцию main удалять из него не нужно.

        Часть 1
        В первой части Вам надо реализовать класс Rational, 
        который представляет собой рациональное число вида p/q, 
        где p — целое, а q — натуральное и диапазоны возможных значений p, q таковы, 
        что могут быть представлены типом int. 
        При этом, класс Rational должен иметь следующий интерфейс:
            class Rational {
            public:
              Rational();
              Rational(int numerator, int denominator);

              int Numerator() const;
              int Denominator() const;
            };
        Класс Rational должен гарантировать, что p/q — это несократимая дробь. 
        Например, код:
            Rational r(4, 6);
            cout << r.Numerator() << '/' << r.Denominator();
        -должен выводить «2/3» — именно поэтому мы делаем Rational классом, 
        а не структурой. Структура позволила бы нарушить этот инвариант:
            struct Rational {
                int numerator, denominator;
            };

            Rational r{2, 3};
            r.numerator = 6; // Нарушен инвариант несократимости
        
        Часть 2:
        Реализуйте для класса Rational операторы ==, + и - так, 
        чтобы операции с дробями можно было записывать естественным образом. 

        Гарантируется, что во всех тестах, на которых будет тестироваться ваша реализация, 
        числители и знаменатели ВСЕХ дробей (как исходных, 
        так и получившихся в результате соответствующих арифметических операций) будут укладываться в диапазон типа int.

        Часть 3
        Аналогично предыдущей части, реализуйте операторы * и /.  
        Как и в предыдущем случае, гарантируется, что во всех тестах,
        на которых будет тестироваться ваша реализация, 
        числители и знаменатели ВСЕХ дробей (как исходных, так и получившихся в результате соответствующих арифметических операций) 
        будут укладываться в диапазон типа int.
        Кроме того, гарантируется, что ни в одном из тестов, 
        на которых будет тестироваться ваша реализация, 
        не будет выполняться деление на ноль.
*/

class Rational {
    public:
        Rational() {
            numerator = 0;
            denominator = 1;
        }
        Rational(int _numerator, int _denominator) {
            int gcd = __gcd(_numerator, _denominator);
            numerator = _numerator / gcd;
            denominator = _denominator / gcd;
        }

        int Numerator() const {
            return numerator;
        }
        int Denominator() const {
            return denominator;
        }
    private:
        int numerator, denominator;
};

bool operator==(const Rational& lhs, const Rational& rhs) {
    if ((lhs.Numerator() == rhs.Numerator()) && (lhs.Denominator() == rhs.Denominator())) return true;
    else return false;
}

Rational operator+(const Rational& lhs, const Rational& rhs) {
    int num, denom;
    denom = lhs.Denominator() * rhs.Denominator();
    num = lhs.Numerator() * rhs.Denominator() + rhs.Numerator() * lhs.Denominator();
    return Rational(num, denom);
}

Rational operator-(const Rational& lhs, const Rational& rhs) {
    int num, denom;
    denom = lhs.Denominator() * rhs.Denominator();
    num = lhs.Numerator() * rhs.Denominator() - rhs.Numerator() * lhs.Denominator();
    return Rational(num, denom);
}

Rational operator*(const Rational& lhs, const Rational& rhs) {
    int num = lhs.Numerator() * rhs.Numerator();
    int denom = lhs.Denominator() * rhs.Denominator();
    return Rational(num, denom);
}

Rational operator/(const Rational& lhs, const Rational& rhs) {
    int num = lhs.Numerator() * rhs.Denominator();
    int denom = lhs.Denominator() * rhs.Numerator();
    return Rational(num, denom);
}

int main() {
    //проверяем на инициализацию класса и соответствие с тестами
    {
        const Rational r(3, 10);
        if (r.Numerator() != 3 || r.Denominator() != 10) {
            cout << "Rational(3, 10) != 3/10" << endl;
            return 1;
        }
    }

    {
        const Rational r(8, 12);
        if (r.Numerator() != 2 || r.Denominator() != 3) {
            cout << "Rational(8, 12) != 2/3" << endl;
            return 2;
        }
    }

    {
        const Rational r(-4, 6);
        if (r.Numerator() != -2 || r.Denominator() != 3) {
            cout << "Rational(-4, 6) != -2/3" << endl;
            return 3;
        }
    }

    {
        const Rational r(4, -6);
        if (r.Numerator() != -2 || r.Denominator() != 3) {
            cout << "Rational(4, -6) != -2/3" << endl;
            return 3;
        }
    }

    {
        const Rational r(0, 15);
        if (r.Numerator() != 0 || r.Denominator() != 1) {
            cout << "Rational(0, 15) != 0/1" << endl;
            return 4;
        }
    }

    {
        const Rational defaultConstructed;
        if (defaultConstructed.Numerator() != 0 || defaultConstructed.Denominator() != 1) {
            cout << "Rational() != 0/1" << endl;
            return 5;
        }
    }
    //проверка на перегрузку операторов +, -, ==
    {
        Rational r1(4, 6);
        Rational r2(2, 3);
        bool equal = r1 == r2;
        if (!equal) {
            cout << "4/6 != 2/3" << endl;
            return 1;
        }
    }

    {
        Rational a(2, 3);
        Rational b(4, 3);
        Rational c = a + b;
        bool equal = c == Rational(2, 1);
        if (!equal) {
            cout << "2/3 + 4/3 != 2" << endl;
            return 2;
        }
    }
    
    {
        Rational a(5, 7);
        Rational b(2, 9);
        Rational c = a - b;
        bool equal = c == Rational(31, 63);
        if (!equal) {
            cout << "5/7 - 2/9 != 31/63" << endl;
            return 3;
        }
    }
    //проверка на корректную работу прегрузки оператора * и /
    {
        Rational a(2, 3);
        Rational b(4, 3);
        Rational c = a * b;
        bool equal = c == Rational(8, 9);
        if (!equal) {
            cout << "2/3 * 4/3 != 8/9" << endl;
            return 1;
        }
    }

    {
        Rational a(5, 4);
        Rational b(15, 8);
        Rational c = a / b;
        bool equal = c == Rational(2, 3);
        if (!equal) {
            cout << "5/4 / 15/8 != 2/3" << endl;
            return 2;
        }
    }

    cout << "OK" << endl;
    return 0;
}