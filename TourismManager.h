
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

// Function to display main menu
void displayMainMenu() {
    cout << "===================================" << endl;
    cout << "       TOURISM MANAGEMENT SYSTEM    " << endl;
    cout << "===================================" << endl;
    cout << "1. View Tours" << endl;
    cout << "2. View Bookings" << endl;
    cout << "3. Add Booking" << endl;
    cout << "4. Exit" << endl;
    cout << "Enter your choice: ";
}

// Function to display tour menu
void displayTourMenu() {
    cout << "===================================" << endl;
    cout << "              TOURS MENU            " << endl;
    cout << "===================================" << endl;
    cout << "1. Safari Adventure (7 days) - $2000.0" << endl;
    cout << "2. Beach Getaway (5 days) - $1500.0" << endl;
    cout <<
