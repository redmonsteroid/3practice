#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

using namespace std;

struct Applicant {
    string surname;
    int score;
};

int main() {
    vector<Applicant> applicants = {
        {"Ivanov", 220},
        {"Petrov", 210},
        {"Sidorov", 230},
        {"Smirnov", 200},
        {"Kuznetsov", 240}
    };

    // Новый вектор для отфильтрованных и отсортированных данных
    vector<Applicant> filteredApplicants;

    // Фильтрация и копирование абитуриентов с баллами >= 215
    copy_if(applicants.begin(), applicants.end(), back_inserter(filteredApplicants), [](const Applicant& applicant) {
        return applicant.score >= 215;
    });

    // Сортировка отфильтрованных абитуриентов по баллам в порядке убывания
    sort(filteredApplicants.begin(), filteredApplicants.end(), [](const Applicant& a, const Applicant& b) {
        return a.score > b.score;
    });

    // Вывод отфильтрованных и отсортированных абитуриентов
    cout << "Filtered and sorted applicants:" << endl;
    for (const auto& applicant : filteredApplicants) {
        cout << applicant.surname << ": " << applicant.score << endl;
    }

    return 0;
}
