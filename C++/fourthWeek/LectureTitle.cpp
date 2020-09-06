#include <iostream>
#include <string>

/*
developer: Artem Trybushenko
language: cpp
*/

using namespace std;

/*
task:   Дана структура LectureTitle:

        Допишите конструктор и структуры Specialization, Course, Week так, 
        чтобы объект LectureTitle можно было создать с помощью кода.
        LectureTitle title(
            Specialization("C++"),
            Course("White belt"),
            Week("4th")
        );

        но нельзя было с помощью следующих фрагментов кода:
        LectureTitle title("C++", "White belt", "4th");

        LectureTitle title(string("C++"), string("White belt"), string("4th"));

        LectureTitle title = {"C++", "White belt", "4th"};

        LectureTitle title = {{"C++"}, {"White belt"}, {"4th"}};

        LectureTitle title(
            Course("White belt"),
            Specialization("C++"),
            Week("4th")
        );

        LectureTitle title(
            Specialization("C++"),
            Week("4th"),
            Course("White belt")
        );
*/

struct LectureTitle {
  Specialization specialization;
  Course course;
  Week week;
  explicit LectureTitle(string _specialization, string _course, string _week) {
      specialization = Specialization(_specialization);
      course = Course(_course);
      week = Week(_week);
  }
};

struct Specialization {
    string specialization;
    explicit Specialization(const string& _specialization) {
        specialization = _specialization;
    }
};

struct Course {
    string course;
    explicit Course(const string& _course) {
        course = _course;
    }
};

struct Week {
    string week;
    explicit Week(const string& _week) {
        week = _week;
    }
};

int main() {
    LectureTitle title(
    Specialization("C++"),
    Course("White belt"),
    Week("4th")
);
    return 0;
}