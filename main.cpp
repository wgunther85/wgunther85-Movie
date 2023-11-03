
#include <iostream>
#include <istream>
#include <iomanip>
#include "MovieList.h"
#include "Movie.h"
/*
 * @file main.cpp
 * @author Will Gunther
 * @brief Searches Movies and Reviews
 * @date
*/

using namespace std;
int main()
{
    std::cout << "\n***************************************************" << std::endl;
    std::cout << "Part 1: Test the Movie class." << std::endl;
    std::cout << "****************************************************\n" << std::endl;

    //Instance of a movie with the following string:  "tt7649664	Spirited Away	2017	22	Action,Adventure,Animation	8.4"
    Movie m("tt7649664\tSpirited Away\t2017\t22\tAction,Adventure,Animation\t8.4");
    std::cout << m.GetId() << "\t" << m.GetTitle() << "\t" << m.GetYear() << "\t" << m.GetMinutes() << "\t" << m.GetReview() << std::endl;


    //If statement to determine if the movie contains the "Action" genre by calling the ContainGenre() method
    if(m.ContainGenre("Action")){
        std::cout << "Action" << std::endl;
    }


    //Run the program and verify that the data is returning the information from the given string.
    cout << m << endl;


    std::cout << "\n***************************************************" << std::endl;
    std::cout << "Part 2: Create the MovieList class." << std::endl;
    std::cout << "****************************************************\n" << std::endl;


    //Instance of the MovieList that reads from the movies.tsv file in the data folder.
    MovieList ml("../../data/movies.tsv");

    ml.GetMovies();

    //Call the GetGenreCounts() to get a map of all the genre counts.  Display the genres and counts
    for(auto i: ml.GetGenreCounts()){
        cout << left << setw(13) << i.first
             << right << setw(5) << i.second << endl;
    }
    //Allow the user to enter the genre, year, and minimum IMDB review score.
    std::cout << std::endl;
    std::cout <<
    "Action      Adventure   Animation   Biography\n" <<
    "Comedy      Crime       Documentary Drama\n" <<
    "Family      Fantasy     Game-Show   History\n" <<
    "Horror      Music       Musical     Mystery\n" <<
    "News        Reality-TV  Romance     Sci-Fi\n" <<
    "Short       Sport       Talk-Show   Thriller\n" <<
    "War         Western" << std::endl;


    std::string genre;
    std::cout << "Choose a Genre: ";
    cin >> genre;
    std::cout << std::endl;

    int year;
    std::cout << "Enter a year: ";
    cin >> year;
    std::cout << std::endl;

    std::cout << "There are " << ml.CountsByYear(year) << " Titles in that year." << std::endl;

    float rating;
    std::cout << "What is the minimum User Rating you will watch? (0 for any movie): ";
    cin >> rating;
    std::cout << std::endl;

    std::cout << "Movies" << std::endl;

    //Call the filter function to get a list of those movies.
    std::vector<Movie> Final;
    Final = ml.Filter(year, genre, rating);

// Display the list of movies.
    for(Movie mo: Final){
        cout  << mo << endl;

    }

    return 0;
}