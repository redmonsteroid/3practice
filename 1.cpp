#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <unordered_set>

using namespace std;

struct Student {
    string first_name;
    string last_name;
};

// Функция для вывода списка студентов
void print_students(const vector<Student>& students) {
    for (const auto& student : students) {
        cout << student.first_name << " " << student.last_name << endl;
    }
}

int main() {
    vector<Student> students = {
        {"Ivan", "Petrov"},
        {"Anna", "Ivanova"},
        {"Pavel", "Sidorov"},
        {"Olga", "Kuznetsova"},
        {"Ivan", "Ivanov"} // Добавлен студент с дублирующимся именем для тестирования
    };

    sort(students.begin(), students.end(), [](const Student& s1, const Student& s2) {
        return s1.last_name < s2.last_name;
    });

 
    cout << "Students sorted by last name:" << endl;
    print_students(students);

    // Задание 2. Сортировка студентов по имени
    sort(students.begin(), students.end(), [](const Student& s1, const Student& s2) {
        return s1.first_name < s2.first_name;
    });
    vector<Student> unique_students;
    unordered_set<string> seen_names;
    for (const auto& student : students) {
        if (seen_names.find(student.first_name) == seen_names.end()) {
            unique_students.push_back(student);
            seen_names.insert(student.first_name);
        }
    }

    // Вывод финального списка студентов
    cout << "\nUnique students sorted by first name:" << endl;
    print_students(unique_students);

    return 0;
}
