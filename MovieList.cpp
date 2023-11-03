//
// Created by Will Gunther
//

#include "Movie.h"
#include "MovieList.h"
#include <fstream>
#include <iostream>
#include <algorithm>
#include <vector>
#include <string>

using namespace std;

// Load the data from the file into the array of movies
void MovieList::LoadData(const std::string& filename) {
    std::ifstream in(filename);
    if (!in.is_open()) {
        std::cout << "Could not open file" << std::endl;
    }

    std::string line;
    while (std::getline(in, line)) {
        movies_.push_back(Movie(line));
    }

    in.close();
}

//Counts all movies that were created in the given year
int MovieList::CountsByYear(int year) {
    int count = 0;
    count = std::count_if(
    movies_.begin(), movies_.end(), [year] (Movie &ml) {
            return ml.GetYear() == year; });

    return count;

}

//Filters the list of movie for the given criteria
std::vector<Movie> MovieList::Filter(const int year, const std::string& genre, float rating) const {
    std::vector<Movie> filtered_movies;

    for(auto i: movies_) {
        if (i.GetYear() == year) {

            if (i.GetReview() >= rating){
                if(i.ContainGenre(genre)){
                    filtered_movies.push_back(i);
                }

            }
        }

    }
    return filtered_movies;
}

//Counts the movies that have the given genre
std::map<std::string, int> MovieList::GetGenreCounts() {
    std::map<std::string, int> genre_counts;
    for (auto i : movies_) {
        std::vector<std::string> genres = i.GetGenres();
        for (auto genre : genres) {
            genre_counts[genre]++;
        }
    }
    return genre_counts;
}