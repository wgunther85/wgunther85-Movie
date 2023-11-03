//
// Created by Will Gunther
//
#include <iostream>
#include <vector>

#ifndef Movie_H
#define Movie_H

class Movie {
private:
    std::string original_input;
    std::string id_;
    std::string title_;
    int year_;
    int length_;
    std::vector<std::string> genres_;
    float rating_;

public:
    Movie(std::string str);
    std::string GetId(){return id_;}
    std::string GetTitle(){return title_;}
    int GetYear(){return year_;}
    int GetMinutes(){return length_;}
    std::vector<std::string> GetGenres(){return genres_;}
    float GetReview(){return rating_;}
    void SetGenre(std::string genres_str);
    bool ContainGenre(std::string genre);
    friend std::ostream &operator<<(std::ostream &out, const Movie &m);
};

#endif  //Movie_H

