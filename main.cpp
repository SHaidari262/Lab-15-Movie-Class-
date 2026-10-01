#include <iostream>
#include <fstream>
#include <string>
#include <vector>
using namespace std;

class Movie {
private:
    string screenWriter;
    int yearReleased;
    string title;

public:
    // Setters
    void setScreenWriter(string writer) {
        screenWriter = writer;
    }

    void setYearReleased(int year) {
        yearReleased = year;
    }

    void setTitle(string movieTitle) {
        title = movieTitle;
    }

    // Getters
    string getScreenWriter() const {
        return screenWriter;
    }

    int getYearReleased() const {
        return yearReleased;
    }

    string getTitle() const {
        return title;
    }

    // Print movie information
    void print() const {
        cout << "Movie: " << title << endl;
        cout << "    Year released: " << yearReleased << endl;
        cout << "    Screenwriter: " << screenWriter << endl;
        cout << endl;
    }
};

int main() {
    ifstream inputFile("input.txt");

    if (!inputFile) {
        cout << "Error opening input.txt" << endl;
        return 1;
    }

    vector<Movie> movies;

    string title;
    string writer;
    int year;

    while (getline(inputFile, title)) {
        inputFile >> year;
        inputFile.ignore();
        getline(inputFile, writer);

        Movie tempMovie;

        tempMovie.setTitle(title);
        tempMovie.setYearReleased(year);
        tempMovie.setScreenWriter(writer);

        movies.push_back(tempMovie);
    }

    inputFile.close();

    for (const Movie& movie : movies) {
        movie.print();
    }

    return 0;
}