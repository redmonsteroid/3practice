#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

using namespace std;

int main() {
    vector<string> words = {"computer", "programming", "example", "homework", "algorithm", "system", "information"};

    // Удаление слов, у которых вторая буква 'm'
    auto it = remove_if(words.begin(), words.end(), [](const string& word) {
        return word.length() >= 2 && word[1] == 'm';
    });

    // Удаляем "хвост" из вектора после remove_if
    words.erase(it, words.end());

    // Удаление слов с нечетным количеством символов
    it = remove_if(words.begin(), words.end(), [](const string& word) {
        return word.length() % 2 != 0;
    });

    // Удаляем "хвост" из вектора после remove_if
    words.erase(it, words.end());

    // Сортировка слов по длине
    sort(words.begin(), words.end(), [](const string& a, const string& b) {
        return a.length() < b.length();
    });

    // Вывод результатов
    cout << "Words after processing:" << endl;
    for (const auto& word : words) {
        cout << word << endl;
    }

    return 0;
}
