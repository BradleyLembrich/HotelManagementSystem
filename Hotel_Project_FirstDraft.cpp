#include<iostream>
#include<vector>
#include<string>
using namespace std;

class Room {

    int roomNumber;
    float roomPrice;
    // bool isOccupied;
public: 
    Room(int number, float price) {
        roomNumber = number;
        roomPrice = price;
        // isOccupied = false;
    }

    int GetRoomNumber(){
        return roomNumber;
    }
    float GetRoomPrice(){
        return roomPrice;
    }
    
};

class Guest {
    std::string guestName;
    std::string guestPhone;
    int guestID;
    static int nextID;
public:
   // Guest (string name, string, phone, )
    void SetGuestDetails(){
        cout << "Enter guest name: " << endl;
        cin >> guestName;
        cout << "Enter guest Phone number: " << endl;
        cin >> guestPhone;
        guestID = nextID;
        nextID = nextID + 1;
    }
    void DisplayGuestDetails(){
        cout << "*** Guest Details ***" << endl << "Guest ID: "  << guestID << endl <<
            "Guest Name: " << guestName << endl <<
            "Guest phone number: " << guestPhone << endl;
    }
};
int Guest::nextID = 1000;

class Hotel {
    std::vector <Room> rooms;
    std::vector <Guest> guests;
public:
    void AddRoom(Room room){
        rooms.push_back(room);
    }
    void AddGuest (){
        Guest guest;
        guest.SetGuestDetails();
        guests.push_back(guest);
        guest.DisplayGuestDetails();

    }
    void DisplayAllRooms(){
        for (int i = 0; i < rooms.size(); i++) {
            cout << rooms[i].GetRoomNumber() << ", $" << rooms[i].GetRoomPrice() << endl;
        }
    }     
    // void BookRoom(){}
    // void SearchAvailableRooms(){}
    // void DislayAllGuests() {}
    // void SearchGuests(){}
};


// class Booking {
// public:
//     Booking(Room, Guest){}
// };

class HotelManager {

    int choice;

public:
    void Start(Hotel hotel){
        cout << "1. Add guest" << endl << "2. Book room (not yet implemented)" << endl << "3. Display all rooms"
        << endl;
        cin >> choice;
        switch (choice) {
            case 1: 
                hotel.AddGuest();
                break;
            // case 2:
            //     hotel.BookRoom();
            //     break;
            case 3:
                hotel.DisplayAllRooms();
                break;
            // case 4: 
            //     hotel.SearchAvailableRooms();
            //     break;
        }
    }
};

int main() {

    Hotel hotel1;
    HotelManager manager;

    Room r1(100, 99.99);
    hotel1.AddRoom(r1);
    Room r2(101, 99.99);
    hotel1.AddRoom(r2);
    Room r3(102, 99.99);
    hotel1.AddRoom(r3);
    Room r4(103, 99.99);
    hotel1.AddRoom(r4);
    Room r5(104, 99.99);
    hotel1.AddRoom(r5);
    Room r6(105, 99.99);
    hotel1.AddRoom(r6);
    Room r7(106, 99.99);
    hotel1.AddRoom(r7);
    Room r8(200, 199.99);
    hotel1.AddRoom(r8);
    Room r9(201, 199.99);
    hotel1.AddRoom(r9);
    Room r10(203, 199.99);
    hotel1.AddRoom(r10);

    manager.Start(hotel1);

return 0;    
}