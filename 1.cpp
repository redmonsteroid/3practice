#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

using namespace std;

struct Student {
    string first_name;
    string last_name;
};

int main() {
    vector<Student> students = {
        {"Ivan", "Petrov"},
        {"Anna", "Ivanova"},
        {"Pavel", "Sidorov"},
        {"Olga", "Kuznetsova"}
    };

    // Задание 1. Сортировка студентов по фамилии
    sort(students.begin(), students.end(), [](const Student& s1, const Student& s2) {
        return s1.last_name < s2.last_name;
    });

    cout << "Students sorted by last name:" << endl;
    for (const auto& student : students) {
        cout << student.first_name << " " << student.last_name << endl;
    }

    return 0;
}
