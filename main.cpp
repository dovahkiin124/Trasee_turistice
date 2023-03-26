#include <iostream>
#include <string>
#include <vector>

using namespace std;

// Class definition for managing tours
class TourManager {
  private:
    string tourName;
    int duration;
    double price;

  public:
    // Constructors
    TourManager() {
        tourName = "";
        duration = 0;
        price = 0.0;
    }
    TourManager(string name, int dur, double p) {
        tourName = name;
        duration = dur;
        price = p;
    }

    // Getters and Setters
    void setTourName(string name) {
        tourName = name;
    }
    void setDuration(int dur) {
        duration = dur;
    }
    void setPrice(double p) {
        price = p;
    }
    string getTourName() {
        return tourName;
    }
    int getDuration() {
        return duration;
    }
    double getPrice() {
        return price;
    }

    // Print function
    void printTour() {
        cout << "Tour Name: " << tourName << endl;
        cout << "Duration: " << duration << " days" << endl;
        cout << "Price: $" << price << endl;
    }
};

// Class definition for managing bookings
class BookingManager {
  private:
    string customerName;
    int numOfPeople;
    TourManager tour;
    string startDate;

  public:
    // Constructors
    BookingManager() {
        customerName = "";
        numOfPeople = 0;
        startDate = "";
    }
    BookingManager(string name, int num, TourManager t, string start) {
        customerName = name;
        numOfPeople = num;
        tour = t;
        startDate = start;
    }

    // Getters and Setters
    void setCustomerName(string name) {
        customerName = name;
    }
    void setNumOfPeople(int num) {
        numOfPeople = num;
    }
    void setTour(TourManager t) {
        tour = t;
    }
    void setStartDate(string start) {
        startDate = start;
    }
    string getCustomerName() {
        return customerName;
    }
    int getNumOfPeople() {
        return numOfPeople;
    }
    TourManager getTour() {
        return tour;
    }
    string getStartDate() {
        return startDate;
    }

    // Print function
    void printBooking() {
        cout << "Customer Name: " << customerName << endl;
        cout << "Number of People: " << numOfPeople << endl;
        tour.printTour();
        cout << "Start Date: " << startDate << endl;
    }
};

int main() {
    // Creating tours
    string destination,date,name;

    int nr,duration;
    double price;
    cout<<"Destination:";
    cin>>destination;
    cout<<"\nDuration:";
    cin>>duration;
    cout<<"\nPrice:";
    cin>>price;
    TourManager tour(destination, duration, price);



    cout<<"\nName:";
    cin>>name;
    cout<<"\nNumber of people:";
    cin>>nr;
    cout<<"\nDate:";
    cin>>date;

    // Creating bookings
    BookingManager booking(name, nr, tour, date);


    // Printing bookings
    booking.printBooking();
    cout << endl;


    return 0;
}
