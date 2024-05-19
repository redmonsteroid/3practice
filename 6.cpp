#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <unordered_map>

using namespace std;

struct Survivor {
    string name;
    int catches;
};

int main() {
    vector<Survivor> survivors = {
        {"Dwight", 0},
        {"Meg", 0},
        {"Claudette", 0},
        {"Jake", 0}
    };

    // Моделируем процесс поимок
    vector<string> catches = {"Dwight", "Meg", "Jake", "Claudette", "Meg", "Dwight", "Claudette", "Jake", "Meg", "Dwight", "Jake", "Claudette"};

    // Обновляем количество поимок
    for (const auto& catch_name : catches) {
        auto it = find_if(survivors.begin(), survivors.end(), [&](const Survivor& survivor) {
            return survivor.name == catch_name; // ходим по вектору выживших пока не найдём нужного 
        });

        if (it != survivors.end()) {
            it->catches++; // увелиичиваем число поимок 
        }
    }

    // Проверяем, пойманы ли все выжившие по 3 раза
    bool all_caught = all_of(survivors.begin(), survivors.end(), [](const Survivor& survivor) {
        return survivor.catches >= 3;
    });

    // Вывод результатов
    if (all_caught) {
        cout << "The hunter has won! All survivors have been caught 3 times." << endl;
    } else {
        cout << "Current status of catches:" << endl;
        for (const auto& survivor : survivors) {
            cout << survivor.name << " has been caught " << survivor.catches << " times." << endl;
        }
    }

    return 0;
}
