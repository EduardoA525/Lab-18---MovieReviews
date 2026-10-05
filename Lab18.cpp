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
};


int main(){

    return 0;
}