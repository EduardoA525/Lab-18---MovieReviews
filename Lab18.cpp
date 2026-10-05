//Eduardo Avila
//COMSC - 210 - 5293
//Lab 17 - Movie Reviews

#include <iostream>
#include <string>
#include <iomanip>
#include <fstream>
#include <cstdlib>

using namespace std;

//Start with struct
struct Review {

    double rating;
    string reviewComment;
    Review *next; //for linked list
};

class Movie { 
private:
    string title;
    Review *head; //for linked list

public:
    Movie(string movieTitle){ //movie constructor
        title = movieTitle;
        head = nullptr;
    }


};


int main(){

    return 0;
}