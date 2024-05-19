#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

using namespace std;

// Структура для хранения информации о проекте
struct Project {
    string name;
    int priority;
};

int main() {
    vector<Project> projects = {
        {"Project A", 8},
        {"Project B", 6},
        {"Project C", 9},
        {"Project D", 4},
        {"Project E", 7},
        {"Project F", 5},
        {"Project G", 10},
        {"Project H", 3}
    };

    // Сортировка проектов по убыванию приоритета
    sort(projects.begin(), projects.end(), [](const Project& a, const Project& b) {
        return a.priority > b.priority;
    });

    // Нахождение проекта с самым высоким приоритетом
    auto max_priority_project = max_element(projects.begin(), projects.end(), [](const Project& a, const Project& b) {
        return a.priority < b.priority;
    });

    // Нахождение проекта с наименьшим приоритетом
    auto min_priority_project = min_element(projects.begin(), projects.end(), [](const Project& a, const Project& b) {
        return a.priority < b.priority;
    });

    // Вывод отсортированного списка проектов
    cout << "Sorted projects by priority (descending):" << endl;
    for (const auto& project : projects) {
        cout << project.name << " - Priority: " << project.priority << endl;
    }

    // Вывод информации о проекте с самым высоким приоритетом
    if (max_priority_project != projects.end()) {
        cout << "\nProject with highest priority: " << max_priority_project->name 
             << " - Priority: " << max_priority_project->priority << endl;
    }

    // Вывод информации о проекте с наименьшим приоритетом
    if (min_priority_project != projects.end()) {
        cout << "Project with lowest priority: " << min_priority_project->name 
             << " - Priority: " << min_priority_project->priority << endl;
    }

    return 0;
}
