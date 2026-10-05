//Eduardo Avila
//COMSC - 210 - 5293
//Lab 17 - Movie Reviews

#include <iostream>
#include <string>
#include <iomanip>
#include <fstream>
#include <cstdlib>
#include <vector>
#include <ctime>

using namespace std;

const int TOTAL_MOVIES = 3;

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

    void addReviews(double rating, string reviewComment){
        Review *newReview = new Review; //dynamically creates node

        newReview -> rating = rating;
        newReview -> reviewComment = reviewComment;
        newReview -> next = head;

        head = newReview;
    }

    void displayReviews() {
        cout << "Movie Title: " << title << endl;
        Review *current = head;
        
        double total = 0.0;
        int count = 0;
        int reviewNumber = 1;

        while(current != nullptr){
            //outputting while there is a review
            cout << "Review #" << reviewNumber << ": ";
            cout << fixed << setprecision(1) << current -> rating;
            cout << ": " << current -> reviewComment << endl;

            //for calculate average
            total += current -> rating;
            count++;
            reviewNumber++;
            current = current -> next;
        }

        if (count > 0) {
            double averageRating = total / count;

            cout << "Average: ";
            cout << fixed << setprecision(1) << averageRating << endl;
        }

    }

    ~Movie(){ //DESTRUCTION
        Review *current = head;

        while (current != nullptr){
            head = current -> next;
            delete current;
            current = head;
        }
        head = nullptr;
    }

    //copy constructor
    Movie(const Movie &otherMovie){
        title = otherMovie.title;
        head = nullptr;

        Review *current = otherMovie.head;

        while (current != nullptr){
            Review *newReview = new Review;

            newReview -> rating = current -> rating;
            newReview -> reviewComment = current -> reviewComment;
            newReview -> next = nullptr;

            if (head == nullptr){
                head = newReview;
            }
            else {
                Review *end = head;

                while(end -> next != nullptr){
                    end = end -> next;
                }

                end -> next = newReview;
            }
        }
    }

    //copy assignment operator
    Movie& operator=(const Movie &otherMovie){
        if (this != &otherMovie){ //make sure its not the same object
            //Delete the current list
            Review *current = head;

            while (current != nullptr){
                head = current -> next;
                delete current;
                current = head;
            }

            title = otherMovie.title;
            head = nullptr;

            current = otherMovie.head;

            while (current != nullptr){
                Review *newReview = new Review;

                newReview -> rating = current -> rating;
                newReview -> reviewComment = current ->  reviewComment;
                newReview -> next = nullptr;

                if (head == nullptr){
                    head = newReview;
                }
                else {
                    Review *end = head;

                    while (end -> next != nullptr){
                        end = end -> next;
                    }

                    end -> next = newReview;
                }

                current = current -> next;
            }
        }

        return *this;
    }


};

int main(){

    srand(time(0));

    ifstream fin;
    fin.open("input.txt");

    if (fin.good()){

        vector<Movie> movies;

        movies.push_back(Movie("Backrooms"));
        movies.push_back(Movie("Spider-Man 3"));
        movies.push_back(Movie("Resident Evil"));
        movies.push_back(Movie("Forgotten Island"));

        string reviewComment;

        for (int i = 0; i < TOTAL_MOVIES; i++){
            getline(fin, reviewComment);

            double rating = (rand() % 41 + 10) / 10.0;

            movies[0].addReviews(rating, reviewComment);
        }

        movies[0].displayReviews(); //test

        fin.close();
    }
    else {
        cout << "Error: File not found. Whoops!" << endl;
    }


    return 0;
}