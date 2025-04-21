#include<iostream>
#include<vector>
#include<string>
using namespace std;

class Room {
    int roomNumber;
    float roomPrice;
    bool isBooked;
public: 
    // Parameterized constructor for instantiating rooms programatically
    Room(int n, float p) {
        roomNumber = n;
        roomPrice = p;
        isBooked = false;
    }
    // Default constructor currently unused
    // Room() {
    //     roomNumber = 0;
    //     roomPrice = 0.0;
    //     isBooked = false;
    // }

    int GetRoomNumber(){
        return roomNumber;
    }
    float GetRoomPrice(){
        return roomPrice;
    }
    void SetIsBooked(bool b){
        isBooked = b;
    }
    bool GetIsBooked(){
        return isBooked;
    }
    void DisplayRoomDetails(){
        cout << "Room number: "  << roomNumber << endl <<
            "Room price : $" << roomPrice << endl <<
            (isBooked ? "Unavailable" : "Available") << endl;
    }
    
};

class Guest {
    std::string guestName;
    std::string guestPhone;
    int guestID;
    static int nextGuestID;
public:
    // Default constructor assigns a unique guest ID starting at 100
    Guest(){ 
        guestID = nextGuestID++;
    }

    bool SetGuestDetails(){
        cout << "Enter guest name (or C to cancel): " << endl;
        cin >> guestName;
        // Checks for exit condition (exits function and returns false if input = C or c)
        if (guestName == "C" || guestName == "c"){
            return false;
        }
        cout << "Enter guest Phone number (or C to cancel): " << endl;
        cin >> guestPhone;
        // Checks for exit condition (exits function and returns false if input = C or c)
        if (guestPhone == "C" || guestPhone == "c"){
            return false;
        }
        return true;
    }
    int GetGuestID(){
        return guestID;
    }
    string GetGuestName(){
        return guestName;
    }
    string GetGuestPhone(){
        return guestPhone;
    }
    void DisplayGuestDetails(){
        cout << "Guest ID: "  << guestID << endl <<
            "Guest Name: " << guestName << endl <<
            "Guest phone number: " << guestPhone << endl;
    }
};
// Initializes static guest ID counter to 100
int Guest::nextGuestID = 100;

class Booking {
public:
    int bookingID;
    Room* bookedRoom; // Pointer to room object associated with this booking
    Guest* bookedGuest; // Pointer to guest object associated with this booking
    static int nextBookingID;
    // Default constructor initializes pointers to nullptr
    // and assigns a unique booking ID starting at 1
    Booking() {
        bookedRoom = nullptr;
        bookedGuest = nullptr;
        bookingID = nextBookingID++;
    }
    // Parameterized constructor currently unused
    // Booking(Room* r, Guest* g){
    //     bookedRoom = r;
    //     bookedGuest = g; 
    //     bookingID = nextBookingID++;
    // }
    
    // Function to check if string input is numeric
    bool IsNumeric(const string& str) {
        if (str.empty()) {
            return false;
        }
        for (int i = 0; i < str.length(); i++) {
            if (!isdigit(str[i])) {
                return false;
            }
        }
        return true;
    }

    bool SetBookingDetails(vector<Guest>& guests, vector<Room>& rooms){
        int inputGuestID;
        int inputRoomNumber;
        bool guestFound = false; // Flag to check if a valid guest is found
        bool roomFound = false; // Flag to check if a valid room is found
        string stringInputGuestID; // String to store user input before conversion
        string stringInputRoomNumber; // String to store user input before conversion

        cout << "Enter guest ID (or C to cancel): " << endl;
        cin >> stringInputGuestID;
        // Checks for exit condition (exits function and returns false if input = C or c)
        if (stringInputGuestID == "C" || stringInputGuestID == "c") {
            return false;
        }
        // Checks if string input is numeric (exits function and returns false if not numeric)
        if (!IsNumeric(stringInputGuestID)){
            cout << "Invalid input" << endl;
            return false;
        }
        cout << "Enter room number (or C to cancel): " << endl;
        cin >> stringInputRoomNumber;
        // Checks for exit condition (exits function and returns false if input = C or c)
        if (stringInputRoomNumber == "C" || stringInputRoomNumber == "c") {
            return false;
        }
        // Checks if string input is numeric (exits function and returns false if not numeric)
        if (!IsNumeric(stringInputRoomNumber)){
            cout << "Invalid input" << endl;
            return false;
        }
        // Converts string inputs to integers
        inputGuestID = stoi(stringInputGuestID);
        inputRoomNumber = stoi(stringInputRoomNumber);

        // Checks if inputGuestID matches a guestID from guests vector
        for (int i = 0; i < guests.size(); i++){
            if (guests[i].GetGuestID() == inputGuestID){
                // If so: assigns bookedGuest pointer to guest object in guests vector
                // and sets guestFound flag to true
                bookedGuest = &guests[i];
                guestFound = true;
                break;
            }
        }
        if (!guestFound){
            // If not: exits function and returns false
            cout << "Guest not found" << endl;
            return false;
        }
        // Checks if inputRoomNumber matches a roomNumber from rooms vector
        for (int i = 0; i < rooms.size(); i++) {
            if (rooms[i].GetRoomNumber() == inputRoomNumber) {
                if (!rooms[i].GetIsBooked()){
                    // If so: assigns bookedRoom pointer to room object in rooms vector
                    // and sets room object's isBooked to true and sets roomFound flag to true
                    bookedRoom = &rooms[i];
                    rooms[i].SetIsBooked(true);
                    roomFound = true;
                }
                break;
            }
        }
        if (!roomFound){
            // If not: exits function and returns false
            cout << "Room not found or unavailable" << endl;
            return false;
        }
        // returns true roomFound and guestFound flags are true
        return guestFound && roomFound;
    }
    int GetBookingID(){
        return bookingID;
    }
    // Returns a pointer to the booked Room object
    Room* GetBookedRoom(){
        return bookedRoom;
    }
    // Returns a pointer to the booked Guest object
    Guest* GetBookedGuest(){
        return bookedGuest;
    }

    void DisplayBookingDetails(){
        cout << "Booking ID: " << bookingID << endl;
        if (bookedGuest) {
            cout << "Guest ID: " << bookedGuest->GetGuestID() << endl;
        } else {
            // Ensuring no dereferencing of nullptr
            cout << "Guest not assigned" << endl;
        }
        if (bookedRoom) { 
            cout << "Room number: " << bookedRoom->GetRoomNumber() << endl;
        } else {
            // Ensuring no dereferencing of nullptr
            cout << "Room not assigned" << endl;
        }
    }
};
// Initializes static booking ID counter to 1
int Booking::nextBookingID = 1;

// Class Hotel manages hotel-related data
class Hotel {
    std::vector <Room> rooms;
    std::vector <Guest> guests;
    std::vector <Booking> bookings;
public:
    void AddRoom(Room room){
        rooms.push_back(room);
    }
    void AddGuest (){
        Guest guest;
        if (guest.SetGuestDetails()){
            guests.push_back(guest);
            cout << endl << "*** Guest added ***" << endl;
            guest.DisplayGuestDetails();
        } else {
            cout << "*** Add guest cancelled ***" << endl;
        }
        cout << endl;
    }
    void AddBooking(){
        Booking booking;
        if (booking.SetBookingDetails(guests, rooms)){
            bookings.push_back(booking);
            cout << endl << "*** Booking added ***" << endl;
            booking.DisplayBookingDetails();
        } else { 
            cout << "*** Add booking cancelled ***" << endl;
        }
        cout << endl;
    }
    void DisplayAllRooms(){
        cout << "*** All rooms ***" << endl << endl;
        for (int i = 0; i < rooms.size(); i++) {
            rooms[i].DisplayRoomDetails();
            cout << endl;
        }
    }     
    void DisplayAllGuests(){
        cout << "*** All guests ***" << endl << endl;
        for (int i = 0; i < guests.size(); i++) {
            guests[i].DisplayGuestDetails(); 
            cout << endl;
        }
    }
    void DisplayAllBookings(){
        cout << "*** All bookings ***" << endl << endl;
        for (int i = 0; i < bookings.size(); i++) {
            bookings[i].DisplayBookingDetails();
            cout << endl;
        }
    }
};

// Class HotelManager controls hotel operations and user input
class HotelManager {

    char choice;
    bool quitFlag = false;

public:
    void Start(Hotel& hotel){
        cout << "*** Welcome to hotel manager ***" << endl;
        while (!quitFlag){
            cout << "1. Add guest" << endl << "2. Add booking (have guest ID and room number ready)"
            << endl << "3. Display all rooms" << endl << "4. Display all guests" 
            << endl << "5. Display all bookings" << endl << "Q to quit" << endl;
            cin >> choice;
            switch (choice) {
                case '1': 
                    hotel.AddGuest();
                    break;
                case '2':
                    hotel.AddBooking();
                    break;
                case '3':
                    hotel.DisplayAllRooms();
                    break;
                case '4':
                    hotel.DisplayAllGuests();
                    break;
                case '5':
                    hotel.DisplayAllBookings();
                    break;
                case 'Q':
                case 'q':
                    quitFlag = true;
                    break;
                default:
                    cout << "**** Invalid entry ***" << endl << endl;
                    break;
            }
        }
        cout << "Quitting program..." << endl;
    }
};

int main() {

    Hotel hotel1;
    HotelManager manager;

    // Programatically instantiates rooms
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

    // Starts HotelManager 
    manager.Start(hotel1);

return 0;    
}