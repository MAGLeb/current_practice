#include <iostream>
#include <string>

using namespace std;

struct Specialization {
    string name;
    explicit Specialization(const string& new_name) {
        name = new_name;
    }
};

struct Course {
    string name;
    explicit Course(const string& new_name) {
        name = new_name;
    }
};

struct Week {
    string name;
    explicit Week(const string& new_name) {
        name = new_name;
    }
};

struct LectureTitle {
    string specialization;
    string course;
    string week;

    LectureTitle(const Specialization& specialization_name, const Course& course_name, const Week& week_name) {
        specialization = specialization_name.name;
        course = course_name.name;
        week = week_name.name;
    }
};

//int main() {
//
//
//
//    return 0;
//}
