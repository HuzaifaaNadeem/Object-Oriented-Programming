#include <iostream>
#include <string>
using namespace std;

struct Event {
    string name;
    string date;
    string venue;
    string organizer;
};

void inputEventDetails(Event events[], int& totalEvents) {
    cout << "Enter the number of events to add: ";
    cin >> totalEvents;
    cin.ignore(); // To clear the input buffer

    for (int i = 0; i < totalEvents; i++) {
        cout << "\nEnter details for Event " << i + 1 << ":\n";
        cout << "Enter Event Name: ";
        getline(cin, events[i].name);
        cout << "Enter Event Date (DD/MM/YYYY): ";
        getline(cin, events[i].date);
        cout << "Enter Event Venue: ";
        getline(cin, events[i].venue);
        cout << "Enter Event Organizer: ";
        getline(cin, events[i].organizer);
    }
}

void displayAllEvents(const Event events[], int totalEvents) {
    if (totalEvents == 0) {
        cout << "No events have been added yet.\n";
        return;
    }

    for (int i = 0; i < totalEvents; i++) {
        cout << "\nEvent " << i + 1 << ":\n";
        cout << "Event Name: " << events[i].name << "\n";
        cout << "Event Date: " << events[i].date << "\n";
        cout << "Event Venue: " << events[i].venue << "\n";
        cout << "Event Organizer: " << events[i].organizer << "\n";
    }
}

void searchEventsByDate(const Event events[], int totalEvents) {
    if (totalEvents == 0) {
        cout << "No events have been added yet.\n";
        return;
    }

    string searchDate;
    cout << "\nEnter the date to search for events (DD/MM/YYYY): ";
    cin.ignore();
    getline(cin, searchDate);

    bool found = false;
    cout << "\nEvents on " << searchDate << ":\n";
    for (int i = 0; i < totalEvents; i++) {
        if (events[i].date == searchDate) {
            cout << "Event Name: " << events[i].name << "\n";
            cout << "Event Venue: " << events[i].venue << "\n";
            cout << "Event Organizer: " << events[i].organizer << "\n";
            found = true;
        }
    }

    if (!found) {
        cout << "No events found on this date.\n";
    }
}

void menu(Event events[], int& totalEvents) {
    int choice;

    while (true) {
        cout << "\nMenu:\n";
        cout << "1. Add Event\n";
        cout << "2. Search Events by Date\n";
        cout << "3. Display All Events\n";
        cout << "4. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                inputEventDetails(events, totalEvents);
                break;
            case 2:
                searchEventsByDate(events, totalEvents);
                break;
            case 3:
                displayAllEvents(events, totalEvents);
                break;
            case 4:
                cout << "Exiting program...\n";
                return;
            default:
                cout << "Invalid choice. Please try again.\n";
        }
    }
}

int main() {
    Event events[100];
    int totalEvents = 0;
    menu(events, totalEvents);
    return 0;
}