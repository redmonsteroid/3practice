#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

using namespace std;

struct Movie {
    string title;
    int publication_year;
    double rating;
};

int main() {
    vector<Movie> movies = {
        {"Intouchables", 2011, 8.8},
        {"The Green Mile", 1999, 8.8},
        {"Forrest Gump", 1994, 8.6},
        {"Fight Club", 1999, 8.6},
        {"Shrek", 2001, 8.4},
        {"The Fifth Element", 1997, 8.1},
    };

    int releaseDate = 1996;
    double minRating = 8.5;
    vector<Movie> sortedMovies;

    // Task: Скопировать фильмы в новый массив изходя из рейтинга и даты релиза.
    copy_if(movies.begin(), movies.end(), back_inserter(sortedMovies), [releaseDate, minRating](const Movie& movie) {
        return movie.publication_year > releaseDate && movie.rating > minRating;
    });

    cout << "Movies published after " << releaseDate << " and with rating above " << minRating << ":" << endl;
    for (const auto& movie : sortedMovies) {
        cout << movie.title << " with rating " << movie.rating << " (" << movie.publication_year << ")" << endl;
    }

    return 0;
}
