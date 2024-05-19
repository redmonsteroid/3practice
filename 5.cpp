#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

using namespace std;

struct Product {
    string name;
    double price;
};

int main() {
    vector<Product> products = {
        {"Bread", 1.50},
        {"Milk", 0.99},
        {"Eggs", 2.99},
        {"Butter", 1.75},
        {"Cheese", 3.49}
    };

    // Сортировка продуктов по возрастанию цены
    sort(products.begin(), products.end(), [](const Product& a, const Product& b) {
        return a.price < b.price;
    });

    // Вывод отсортированного списка продуктов
    cout << "Products sorted by price in ascending order:" << endl;
    for (const auto& product : products) {
        cout << product.name << ": $" << product.price << endl;
    }

    return 0;
}
