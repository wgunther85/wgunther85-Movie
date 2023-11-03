//
// Created by Will Gunther
//
#include "Movie.h"
#include <vector>
#include <iostream>
#include <map>

#ifndef MOVIES_MOVIELIST_H
#define MOVIES_MOVIELIST_H

class MovieList {
    std::vector<Movie> movies_;
public:
    MovieList(const std::string& filename) {LoadData(filename);}

    std::vector<Movie> GetMovies() const {return movies_;}

    void LoadData(const std::string& filename);

    int CountsByYear(int year);



    std::map<std::string, int> GetGenreCounts();


    // Filters a movie by year, genre, and minimum rating and then sort the movies by title
    std::vector<Movie> Filter(const int year, const std::string& genre, float rating) const;
};






#endif //MOVIES_MOVIELIST_H
