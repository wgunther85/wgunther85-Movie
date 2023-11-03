// Created by Will Gunther

#include "Movie.h"
#include <sstream>
#include <iostream>
#include <algorithm>
#include <vector>
#include <string>

//General Constructor for the Movie Class
Movie::Movie(std::string str) {
    original_input = str;
    std::stringstream ss(str);

    std::getline(ss, id_, '\t');

    std::getline(ss, title_, '\t');

    std::string tempYear;
    std::getline(ss, tempYear, '\t');
    year_ = stoi(tempYear);

    std::string tempLength;
    std::getline(ss, tempLength, '\t');
    length_ = stoi(tempLength);

    std::string genre_str;
    std::getline(ss, genre_str, '\t');
    SetGenre(genre_str);

    std::string tempRating;
    std::getline(ss, tempRating, '\n');
    rating_ = stof(tempRating);
}

//accepts the genres_str string, separates the genres and stores them in the genres_ vector
void Movie::SetGenre(std::string genres_str) {
    int commas = 0;
    std::stringstream ss(genres_str);
    std::string genre;
    std::string temp;

     for (int i = 0; i < genres_str.size(); i++){
            if (genres_str[i] == ',') {
                commas++;
            }
        }

     for(int i=0; i < commas; i++){
            std::getline(ss, genre, ',');
            genres_.push_back(genre);
        }
    std::getline(ss, genre, ' ');
    genres_.push_back(genre);
}

//Declares T/F whether the given genre is in the selected movie object
bool Movie::ContainGenre(std::string genre) {

    if( std::find(genres_.begin(), genres_.end(), genre) != genres_.end()){
        return true;
    }
    else {
        return false;
    }
}


//Outputs the original file that was read in
std::ostream &operator<<(std::ostream &out, const Movie &m) {
    out << m.original_input << std::endl;
    return out;
}

