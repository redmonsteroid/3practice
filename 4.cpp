#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

using namespace std;

int main() {
    vector<string> words = {"computer", "programming", "example", "homework", "algorithm", "system", "information"};

    // Удаление слов, у которых третья буква 'm'
    auto it = remove_if(words.begin(), words.end(), [](const string& word) {
        return word.length() >= 3 && word[2] == 'm';
    });

    // Удаляем "хвост" из вектора после remove_if
    words.erase(it, words.end());

    // Вывод результатов
    cout << "Words after removing those with 'm' as the third letter:" << endl;
    for (const auto& word : words) {
        cout << word << endl;
    }

    return 0;
}
