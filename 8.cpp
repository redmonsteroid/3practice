#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

using namespace std;

// Структура для хранения информации о продукте
struct Product {
    string name;
    int expiry_day; // день месяца окончания срока годности
};

int main() {
    vector<Product> products = {
        {"Milk", 18},
        {"Bread", 22},
        {"Cheese", 25},
        {"Yogurt", 19},
        {"Butter", 20},
        {"Eggs", 21}
    };

    // День для фильтрации (просроченные продукты до 20-го числа)
    int cutoff_day = 20;

    // Фильтрация продуктов с учетом дня
    vector<Product> filteredProducts;
    copy_if(products.begin(), products.end(), back_inserter(filteredProducts), [cutoff_day](const Product& product) {
        return product.expiry_day >= cutoff_day;
    });

    // Сортировка отфильтрованных продуктов по дню окончания срока годности
    sort(filteredProducts.begin(), filteredProducts.end(), [](const Product& a, const Product& b) {
        return a.expiry_day < b.expiry_day;
    });

    // Вывод отсортированных продуктов
    cout << "Filtered and sorted products by expiry day:" << endl;
    for (const auto& product : filteredProducts) {
        cout << product.name << ": " << product.expiry_day << endl;
    }

    return 0;
}
