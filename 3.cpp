#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <random>

using namespace std;
int main() {
    // Инициализация генератора случайных чисел
    random_device rd;
    mt19937 gen(rd());
  

    // Определение цветов
    vector<string> color = {"Red", "Blue", "Green"};
    vector<string> colors(200);

    for (int i = 0; i < 200; i++) {
        int index = gen() % 3; // Генерируем случайный индекс от 0 до 2
        colors.push_back(color[index]);
    }
    // Подсчет количества каждого цвета
    int red_count = count(colors.begin(), colors.end(), "Red");
    int blue_count = count(colors.begin(), colors.end(), "Blue");
    int green_count = count(colors.begin(), colors.end(), "Green");

    // Вывод результатов
    cout << "Red count: " << red_count << endl;
    cout << "Blue count: " << blue_count << endl;
    cout << "Green count: " << green_count << endl;


    return 0;
}
