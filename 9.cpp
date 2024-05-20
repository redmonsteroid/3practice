#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

using namespace std;

// Структура для хранения информации об автомобиле
struct Car {
    string name;
    double price;
};
void carsort(vector<Car>& cars) {
      auto min_it = min_element(cars.begin(), cars.end(), [](const Car& a, const Car& b) {
        return a.price < b.price;
    });

    // Нахождение самой дорогой машины
    auto max_it = max_element(cars.begin(), cars.end(), [](const Car& a, const Car& b) {
        return a.price < b.price;
    });

    // Вывод информации о самой дешевой машине
    if (min_it != cars.end()) {
        cout << "Cheapest car: " << min_it->name << " with price $" << min_it->price << endl;
    }

    // Вывод информации о самой дорогой машине
    if (max_it != cars.end()) {
        cout << "Most expensive car: " << max_it->name << " with price $" << max_it->price << endl;
    }

}
int main() {
    vector<Car> cars = {
        {"Toyota Camry", 24000},
        {"BMW 3 Series", 41000},
        {"Honda Accord", 26000},
        {"Mercedes-Benz C-Class", 42000},
        {"Ford Fusion", 22000}
    };

    // Нахождение самой дешевой машины
   

    // Нахождение самой дорогой машины
   carsort(cars);

    return 0;
}
