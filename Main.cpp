#include <iostream>
#include <cstdlib>
#include <string>
#include <string.h>
#include <vector>
#include <fstream>
#include <sstream>
#include <map>
#include <algorithm>
#include <ctime>

using namespace std;

// a class name person to store id, name and password
class person{
    private:
        string id;
        string name;
        string password;
    public:
        person() = default;
        person(string ID, string n, string p){
            id = ID;
            name = n;
            password = p;
        }
        // setter and getter function to manipulate attribute of a certain object and retrieve attribute value 
        void setID(string ID){
            id = ID;
        }
        string getID(){
            return id;
        }
        void setName(string n){
            name = n;
        }
        string getName(){
            return name;
        }
        void setPassword(string p){
            password = p;
        }
        string getPassword(){
            return password;
        }
};
// client loader which act as a database
class allClient{
    private:
        // create a vector call "clients" to store the information of all clients
        vector <person> clients;
    // this is a constructor to call "saveClient" function.
    public:
        allClient(){
            saveClient();
        }
        // a function to save Client information to the file.
        void saveClient(){
            // Define the path to the client file
            string clientPath = "client.txt";
            // read file
            ifstream clientFile(clientPath);
            // if the file could not open it will print "Error Opening"
            if(!clientFile){
                cout << "Error opening " << clientPath << endl;
            }
            else{
                string line;
                person client;
                string temp;
                // read the file line by line
                while(getline(clientFile, line)){
                    // create a string stream from the lien
                    stringstream ss(line);
                    // Extract and set Client Info.
                    getline(ss, temp, ',');
                    client.setID(temp);
                    getline(ss, temp, ',');
                    client.setName(temp);
                    getline(ss, temp, ',');
                    client.setPassword(temp);
                    // add the client to the list of clients
                    clients.push_back(client);
                }
            }
        }
        // A function that returns a referance of client vector
        vector <person> &getClients(){
            return clients;
        }
        // A function to print client ID and Name by using get function.
        void printClient(){
            // this will go through all the all client in the vector
            for(int i = 0; i < clients.size(); i++){
                cout << clients[i].getID() << clients[i].getName() << endl;
            }
        }
        void selectionSort(){
            int min_idx;
            // One by one move boundary of
            // unsorted subvector
            for(int i = 0; i < clients.size(); i++){
                // Find the minimum element in
                // unsorted vector
                min_idx = i;
                for(int j = i + 1; j < clients.size(); j++){
                    if(clients[j].getID() < clients[min_idx].getID())
                        min_idx = j;
                }
                // Swap the found minimum element
                // with the first element
                if(min_idx != i){
                    swap(clients[min_idx], clients[i]);
                }
            }
        }
        int binarySearch(int low, int high, string x){
            while(low <= high) {
                int mid = low + (high - low) / 2;

                // Check if x is present at mid
                if(clients[mid].getID() == x){
                    return mid;
                }
                // If x greater, ignore left half
                if(clients[mid].getID() < x){
                    low = mid + 1;
                }
                // If x is smaller, ignore right half
                else{
                    high = mid - 1;
                }
            }
            // If we reach here, then element was not present
            cout << 1 << endl;
            return -1;
        }
};
// admin loader which act as a database
class allAdmin{
    private:
        // create a vector call "admins" to store the information of all admins
        vector <person> admins;
    public:
        // a constructor to call "saveAdmin" function
        allAdmin(){
            saveAdmin();
        }
        // A function to save admin info to file
        void saveAdmin(){
            //Define the path to the admin file
            string adminPath = "admin.txt";
            // read file
            ifstream adminFile(adminPath);
            if(!adminFile){
                cout << "Error opening " << adminPath << endl;
            }
            else{
                string line;
                person admin;
                string temp;
                // read file line by line.
                while(getline(adminFile, line)){
                    // Extract and set admins Info.
                    stringstream ss(line);
                    getline(ss, temp, ',');
                    admin.setID(temp);
                    getline(ss, temp, ',');
                    admin.setName(temp);
                    getline(ss, temp, ',');
                    admin.setPassword(temp);
                    // add the admin to the list of admins
                    admins.push_back(admin);
                }
            }
        }
        // A function that returns a referance of admin vector
        vector <person> &getAdmin(){
            return admins;
        }
        // A function to print admins ID and Name by using get function.
        void printAdmin(){
            // read through all the admins in the vector.
            for(int i = 0; i < admins.size(); i++){
                cout << admins[i].getID() << admins[i].getName() << endl;
            }
        }
        // A function to perform linear search for admin by ID.
        int LinearSearch(string id){
            for(int i = 0; i < admins.size(); i++){
                // check if the current admin's ID match the given ID
                if (admins[i].getID() == id){
                    //return the index of matched admin.
                    return i;
                }
            }
            // return -1 if not found matched admin.
            return -1;
        }
};
// A car class which stores information that a car has.
class car{
    protected:
        string id;
        string brand;
        string color;
        string country;
        string year;
        int price;
        // a function to generate random ID
        void generateID(){
            // seed the random number generator with the current time
            srand(time(nullptr));
            // the first 3 char of the brand will be initialize as ID.
            id = brand.substr(0,3);
            // generate 9 random digits to the ID.
            for(int i = 0; i < 9; i++){
                id += to_string(rand()%10);
            }
        }

    public:
        car() = default;
        // constructor of car.
        car(string BRAND, string COLOUR, string COM, string YOM, int PRICE){
            brand = BRAND;
            color = COLOUR;
            country = COM;
            year = YOM;
            price = PRICE;
            generateID();
        }
        // setter and getter method of car class
        void setID(string ID){
            id = ID;
        }
        string getID()const{
            return id;
        }

        void setBrand(string b){
            brand = b;
        }
        string getBrand()const{
            return brand;
        }
        void setColor(string c){
            color = c;
        }
        string getColor()const{
            return color;
        }
        void setCountry(string c){
            country = c;
        }
        string getCountry()const{
            return country;
        }
        void setYear(string y){
            year = y;
        }
        string getYear()const{
            return year;
        }
        void setPrice(string p){
            price = stoi(p);
        }
        void setPrice(int p){
            price = p;
        }
        int getPrice()const{
            return price;
        }
};
// A car loader which act as a database
class Allcar{
    // a vector name call "cars" to car details.
    private:
        vector <car> cars;
    public:
        // a structure to call "saveCar" function.
        Allcar(){
            saveCar();
        }
        // A function to save car info to file
        void saveCar(){
            //Define the path to the car file
            string carPath = "car.txt";
            // read file
            ifstream carFile(carPath);
            if(!carFile){
                cout << "Error opening " << carPath << endl;
            }
            else{
                string line;
                car c;
                //read file line by line.
                while(getline(carFile, line)){
                    // Extract and set car Info.
                    stringstream ss(line);
                    string temp;
                    getline(ss, temp, ',');
                    c.setID(temp);
                    getline(ss, temp, ',');
                    c.setBrand(temp);
                    getline(ss, temp, ',');
                    c.setColor(temp);
                    getline(ss, temp, ',');
                    c.setCountry(temp);
                    getline(ss, temp, ',');
                    c.setYear(temp);
                    getline(ss, temp, ',');
                    c.setPrice(temp);
                    //add car to the list of cars
                    cars.push_back(c);
                }
            }
            cars = cars;
        }
        // A function to get the referance of the cars vector
        vector <car> &getCar(){
            return cars;
        }
        // Function to partition the vector based on car IDs.
        int partitionID(int start, int end){
            // the first car of the vector or sub-vector will be the pivot
            car pivot = cars[start];
            int count = 0;
            // count how many car are less than or equal to the pivoted-car.
            for(int i = start + 1; i <= end; i++){
                if(cars[i].getID() <= pivot.getID())
                    count++;
            }
            // position the pivoted-car at the correct oppsition
            int pivotIndex = start + count;
            swap(cars[pivotIndex], cars[start]);

            // Sorting left and right parts of the pivoted-car
            int i = start, j = end;
            while(i < pivotIndex && j > pivotIndex){
                // increment i until a car larger than the pivoted-car is found.
                while (cars[i].getID() <= pivot.getID()){
                    i++;
                }
                // Decrement j until a car smaller than the pivoted-car is found.
                while(cars[j].getID() > pivot.getID()){
                    j--;
                }
                // swap element at i-car and j-car if they are on the wrong side of the pivot.
                if(i < pivotIndex && j > pivotIndex){
                    swap(cars[i++], cars[j--]);
                }
            }
            // return the final position of the pivoted-car
            return pivotIndex;
        }
        void quickSortID(int start, int end){
            // base case
            if (start >= end)
                return;
            // partitioning the vector of car
            int p = partitionID(start, end);
            // Sorting the left part
            quickSortID(start, p - 1);
            // Sorting the right part
            quickSortID(p + 1, end);
        }
        // A function to partition the vector of cars based on car brand.
        int partitionBrand(int start, int end){
            // The first car of vector or sub-vector will act the pivot.
            car pivot = cars[start];
            int count = 0;
            // Count how many cars are less than or equal to the pivoted-car
            for(int i = start + 1; i <= end; i++){
                if(cars[i].getBrand() <= pivot.getBrand())
                    count++;
            }
            // position the pivoted-car at the correct position
            int pivotIndex = start + count;
            swap(cars[pivotIndex], cars[start]);
            // Sorting left and right parts of the pivoted-car
            int i = start, j = end;
            while(i < pivotIndex && j > pivotIndex){
                // Increment i until a car brand larger than the pivoted-car brand is found
                while(cars[i].getBrand() <= pivot.getBrand()){
                    i++;
                }
                // Decrement j until a car brand smaller than the pivoted-car brand is found
                while(cars[j].getBrand() > pivot.getBrand()){
                    j--;
                }
                // Swap cars at i and j if they are on the wrong side of the pivot
                if(i < pivotIndex && j > pivotIndex){
                    swap(cars[i++], cars[j--]);
                }
            }
            // Return the final position of the pivoted-car
            return pivotIndex;
        }
        void quickSortBrand(int start, int end){
            // base case
            if(start >= end)
                return;
            // partitioning the vector
            int p = partitionBrand(start, end);
            // Sorting the left part
            quickSortBrand(start, p - 1);
            // Sorting the right part
            quickSortBrand(p + 1, end);
        }
        // A function to partition the vector based on price.
        int partitionPrice(int start, int end){
            car pivot = cars[start];
            int count = 0;
            for(int i = start + 1; i <= end; i++){
                if(cars[i].getPrice() <= pivot.getPrice())
                    count++;
            }
            int pivotIndex = start + count;
            swap(cars[pivotIndex], cars[start]);
            int i = start, j = end;
            while(i < pivotIndex && j > pivotIndex){
                while(cars[i].getPrice() <= pivot.getPrice()){
                    i++;
                }
                while(cars[j].getPrice() > pivot.getPrice()){
                    j--;
                }
                if(i < pivotIndex && j > pivotIndex){
                    swap(cars[i++], cars[j--]);
                }
            }
            return pivotIndex;
        }
        void quickSortPrice(int start, int end){
            // base case
            if(start >= end)
                return;
            // partitioning the vector
            int p = partitionPrice(start, end);
            // Sorting the left part
            quickSortPrice(start, p - 1);
            // Sorting the right part
            quickSortPrice(p + 1, end);
        }
        // Function to perform a linear search for a car by ID.
        int LinearSearch(string ID){
            for(int i = 0; i < cars.size(); i++){
                if(cars[i].getID() == ID){
                    return i;
                }
            }
            return -1;
        }
        // print function.
        void printCars()const{
            system("CLS");
            for(const auto &c : cars){
                cout << "-----------------------------------------" << endl;
                cout << "Car ID: " << c.getID() << endl;
                cout << "Car Brand: " << c.getBrand() << endl;
                cout << "Colour of the Car: " << c.getColor() << endl;
                cout << "Country Manufacture: " <<c.getCountry() << endl;
                cout << "Year produced: " << c.getYear() << endl;
                cout << "Price of the car: RM" << c.getPrice() << endl;
            }
            cout << "-----------------------------------------" << endl;
        }
};
// A class name "SoldCar" inheritance from car class.
class SoldCar : public car{
    private:
        string timer;
        string period;
        string userID;

    public:
        SoldCar() = default;
        SoldCar(string ID, car outCar) : car(outCar){
            userID = ID;
            period = getTimer();
        }
        void setPeriod(string p){
            period = p;
        }
        string getPeriod()const{
            return period;
        }
        void setUserID(string id){
            userID = id;
        }
        string getUserID()const{
            return userID;
        }
        string getTimer(){
            // Get the timestamp for the current date and time
            time_t timestamp;
            time(&timestamp);
            period = strtok(ctime(&timestamp), "\n");
            return period;
        }
        // Method to add sold car in to "soldCar.txt by appending a new line"
        void addSoldCarToFile(){
            ofstream file;
            //  open file in append mode
            file.open("soldCar.txt", ios::app);
            // the format of sold car info.
            file << endl << id << ',' << brand << ',' << color << ',' << country << ',' << year << ',' << price << ',' << period << ',' << userID;
        }
};
// A class act as a database loader for sold car
class SoldCarLoader{
    private:
        vector <SoldCar> soldVec;
    public:
        SoldCarLoader(){
            saveSoldCar();
        }
        vector <SoldCar> &getSoldCar(){
            return soldVec;
        }
        void saveSoldCar(){
            string soldCarPath = "soldCar.txt";
            ifstream soldFile(soldCarPath);
            if(!soldFile){
                cout << "Error opening " << soldCarPath << endl;
            }
            else{
                string line;
                SoldCar s;
                while(getline(soldFile, line)){
                    stringstream ss(line);
                    string temp;
                    getline(ss, temp, ',');
                    s.setID(temp);
                    getline(ss, temp, ',');
                    s.setBrand(temp);
                    getline(ss, temp, ',');
                    s.setColor(temp);
                    getline(ss, temp, ',');
                    s.setCountry(temp);
                    getline(ss, temp, ',');
                    s.setYear(temp);
                    getline(ss, temp, ',');
                    s.setPrice(temp);
                    getline(ss, temp, ',');
                    s.setPeriod(temp);
                    getline(ss, temp, ',');
                    s.setUserID(temp);
                    soldVec.push_back(s);
                }
            }
            soldVec = soldVec;
        }
        // Function that perform bubble by sorting the ID;
        void bubbleSort(){
            bool swaps;
            // go throught over each soldcar in the soldVec vector
            for(int i = 0; i < soldVec.size() - 1; i++){
                swaps = false;
                // Compare adjacent car and swap if they are in the wrong order
                for(int j = 0; j < soldVec.size() - i - 1; j++){
                    if(soldVec[j].getID() > soldVec[j + 1].getID()){
                        swap(soldVec[j], soldVec[j + 1]);
                        swaps = true;
                    }
                }
                // the vector sorted if no swaps were made in the inner loop.
                if(!swaps){
                    break;
                }
            }
        }
        // function to count and print the number of car of each brand.
        void countBrands(){
            system("CLS");
            // call bubble sort function.
            bubbleSort();
            bool swaps;
            int totalCount = 0;

            // A map which stores in a way <brand of the car, number of car sold>
            map<string, int> brandCount;
            // count the number of cars for each brand.
            for(const auto& car : soldVec){
                brandCount[car.getBrand()]++;
            }
            // Transfer the map to a vector of pairs
            vector<pair<string, int>> brandCountVec(brandCount.begin(), brandCount.end());

            for(int i = 0; i < brandCountVec.size() - 1; i++){
                swaps = false;
                for(int j = 0; j < brandCountVec.size() - i - 1; j++){
                    if(brandCountVec[j].second < brandCountVec[j + 1].second){
                        swap(brandCountVec[j], brandCountVec[j + 1]);
                        swaps = true;
                    }
                }
                if(!swaps){
                    break;
                }
            }
            // print the count of each brand.
            for(const auto& [brand, count] : brandCountVec){
                cout << brand << " Count is " << count << endl;
                totalCount += count;
            }
            cout << "Total Number Car Sold: " << totalCount << endl;
            cout << "-----------------------------------------" << endl;
        }
        int binarySearch(int low, int high, string x){
            while(low <= high){
                int mid = low + (high - low) / 2;
                // Check if x is present at mid
                if(soldVec[mid].getBrand() == x){
                    return mid;
                }
                // If x greater, ignore left half
                if(soldVec[mid].getBrand() < x){
                    low = mid + 1;
                }
                // If x is smaller, ignore right half
                else{
                    high = mid - 1;
                }
            }
                return -1;
        }
        // printBills Function.
        void printBills(){
            for(auto &s : soldVec){
                cout << "-----------------------------------------" << endl;
                cout << "User ID: " << s.getUserID() << endl;
                cout << "Car ID: " << s.getID() << endl;
                cout << "Car Brand: " << s.getBrand() << endl;
                cout << "Colour of the Car: " << s.getColor() << endl;
                cout << "Country Manufacture: " <<s.getCountry() << endl;
                cout << "Year produced: " << s.getYear() << endl;
                cout << "Price of the car: RM" << s.getPrice() << endl;
                cout << "Time purchase: " << s.getPeriod() << endl;
            }
            cout << "-----------------------------------------" << endl;
        }
        // print Bills function on a specific year.
        void printBills(string year){
            double totalSales = 0.0;
            for(auto &s : soldVec){
                string tempYear = s.getPeriod().substr(20,4);
                if(tempYear == year){
                    cout << "-----------------------------------------" << endl;
                    cout << "User ID: " << s.getUserID() << endl;
                    cout << "Car ID: " << s.getID() << endl;
                    cout << "Car Brand: " << s.getBrand() << endl;
                    cout << "Colour of the Car: " << s.getColor() << endl;
                    cout << "Country Manufacture: " <<s.getCountry() << endl;
                    cout << "Year produced: " << s.getYear() << endl;
                    cout << "Price of the car: RM" << s.getPrice() << endl;
                    totalSales += s.getPrice();
                    cout << "Time purchase: " << s.getPeriod() << endl;
                }
            }
            cout << "-----------------------------------------" << endl;
            cout << "Total Sales for " << year << ": RM" << totalSales << endl;
            cout << "-----------------------------------------" << endl;
        }
        // Function to print bill based on user ID
        void printBillsID(string ID){
            for(auto &s : soldVec){
                if(s.getUserID() == ID){
                    cout << "-----------------------------------------" << endl;
                    cout << "User ID: " << s.getUserID() << endl;
                    cout << "Car ID: " << s.getID() << endl;
                    cout << "Car Brand: " << s.getBrand() << endl;
                    cout << "Colour of the Car: " << s.getColor() << endl;
                    cout << "Country Manufacture: " <<s.getCountry() << endl;
                    cout << "Year produced: " << s.getYear() << endl;
                    cout << "Price of the car: RM" << s.getPrice() << endl;
                    cout << "Time purchase: " << s.getPeriod() << endl;
                }
            }
            cout << "-----------------------------------------" << endl;
        }
};
// A class which coordianted the whole programme (core class)
class carSystem{
    private:
        allClient clients; // object to handle all clients.
        Allcar cars; // object to handle all cars.
        SoldCar vended;// object to handle all sold cars.
        SoldCarLoader solds; // Object to load sold cars
        allAdmin admins;// Object to handle all admins
        person currentUser;// Current user
        vector <car> chosenCar;// Vector to store chosen cars
        int type; // type of user ( admin or client)
    public:
        // this function is use to run car system
        void run(){
            int choice;
            int flag = 0;
            string line;
            // make sure the system keep running until the user inputs "-1".
            while(1){
                if(flag == 0){
                    cout << "1) Client" << endl;
                    cout << "2) Admin" << endl;
                    cout << "-1) Exit" << endl;
                    cout << "choice> ";
                    cin >> choice;
                    switch(choice){
                        // login for client
                        case 1:
                            if(login(1)){
                                system("CLS");
                                type = 1;
                                break;
                            }
                            continue;
                        case 2:
                            // login for admin
                            if(login(2)){
                                system("CLS");
                                type = 2;
                                break;
                            }
                            continue;
                        case -1:
                            // quit system
                            flag = 1;
                            break;
                        default:
                            // prompt error
                            cout << "Invalid Input :(" << endl;
                            continue;
                    }
                }
                cout << "Welcome to SHARK BEE" << endl;
                if(flag == 1){
                    cout << "Please visit us again";
                    break;
                }
                if(type == 1){
                    clientPage();
                }
                if(type == 2){
                    adminPage();
                }
            }
        }
        bool login(int type){
            string line;
            int flag;
            int temp;
            // client login
            if(type == 1){
                cout << "ID> ";
                cin >> line;
                clients.selectionSort(); // sort clients for binary search.
                // search client ID
                temp = clients.binarySearch(0, clients.getClients().size()-1, line);
                // if client found,
                if(temp >= 0){
                    currentUser = clients.getClients()[temp];
                    cout << "Password> ";
                    cin >> line;
                    // check password
                    if(line == currentUser.getPassword()){
                        return 1;// login successful
                    }
                    else{
                        // promp error when password is not match
                        cout << "Incorrect Password :(" << endl;
                    }
                }
                else{
                    // promp error when user is not found in our system
                    cout << "User Not Found :(" << endl;
                }
                return 0;// login failed.
            }
            // admin login
            else if(type == 2){
                cout << "ID> ";
                cin >> line;
                // Iterate through admin list to find the admin by ID (linear search without using function)
                for(int i = 0; i < admins.getAdmin().size(); i++){
                    // if admin found
                    if(line == admins.getAdmin()[i].getID()){
                        cout << "Password> ";
                        cin >> line;
                        // check for password
                        if(line == admins.getAdmin()[i].getPassword()){
                            return true;// login successful
                        }
                        // wrong password.
                        cout << "Incorrect Password :)" << endl;
                        break;
                    }
                }
            }
            return false; // login fail
        }
        // clientPage function.
        void clientPage(){
            system("CLS");
            int choice;
            int flag = 0;
            string line;
            while(1){// display client menu.
                cout << "1) View history purchase" << endl;
                cout << "2) Make Purchase" << endl;
                cout << "-1) log Out" << endl;
                cout << "> ";
                cin >> choice;
                if(choice == 1){
                    // view purchase history.
                    cout << "Purchase History" << endl;
                    // print bills for current user ID.
                    solds.printBillsID(currentUser.getID());
                }
                else if(choice == 2){// make purchase and print out cars details.
                    while(1){
                        cars.printCars();
                        cout << "Sort by" << endl;
                        cout << "1) ID" << endl;
                        cout << "2) Price" << endl;
                        cout << "3) Brand" << endl;
                        cout << "4) Select Purchase" << endl;
                        cout << "5) Checkout" << endl;
                        cout << "6) Back" << endl;
                        cout << "> ";
                        cin >> choice;
                        switch (choice){
                        case 1:
                            // the cars are sorted by ID
                            system("CLS");
                            cars.quickSortID(0, cars.getCar().size()-1);
                            break;
                        case 2:
                            // the cars are sorted by price
                            system("CLS");
                            cars.quickSortPrice(0,cars.getCar().size()-1);
                            break;
                        case 3:
                            // the cars are sorted by barnd
                            system("CLS");
                            cars.quickSortBrand(0, cars.getCar().size()-1);
                            break;
                        case 4:
                            // select a car to purchase
                            selectPurchase();
                            break;
                        case 5:
                            // confirm and purchase
                            confirmPurchase();
                            flag = 1;
                            break;
                        case 6:
                            flag = 1;
                            break;
                        default:
                            cout << "Invalid Input";
                            continue;
                        }
                        if(flag == 1){
                            break; // exit client page
                        }
                    }
                }
                else if(choice == -1){ //logout
                    cout << "Thank You for choosing us" << endl;
                    break;// exit outer loop
                }
                else{
                    cout << "Invalid Input" << endl;
                }
            }
        }
        void selectPurchase(){
            system("CLS");
            string line;
            int flag = 0;
            int index = 0;
            cars.printCars(); // print all available cars
            while(flag == 0){
                cout << "Enter Car ID> ";
                cin >> line;
                index = cars.LinearSearch(line);// search for the car by ID
                // add chosen car to the    cart
                chosenCar.push_back(cars.getCar()[index]);
                flag = 1;// set flag to exits loop
                // wrong car ID
                if(index == -1){
                    // promp error when incorrect ID is entered or car ID is not in our dataset
                    cout << "Incorrect Car ID" << endl;
                }
                if(flag == 1){
                    break;// break the while loop
                }
            }
        }
        void confirmPurchase(){
            system("CLS");
            string flag;
            while(1){
                cout << "       Your Purchase" << endl;
                cout << "----------------------------" << endl;
                // print details of the chosen cars.
                for(int i = 0; i < chosenCar.size(); i++){
                    cout << "ID: " << chosenCar[i].getID() << endl;
                    cout << "Brand: " << chosenCar[i].getBrand() << endl;
                    cout << "Country of manufacture: " << chosenCar[i].getCountry() << endl;
                    cout << "Year of Manufacture: " << chosenCar[i].getYear() << endl;
                    cout << "Color: " << chosenCar[i].getColor() << endl;
                    cout << "Price: " << chosenCar[i].getPrice() << endl;
                    cout << "---------------------------------------------" << endl;
                }
                // ask user to confirm purchase.
                cout << "Confirm Purchase [Y/N]" << endl;
                cout << "> ";
                cin >> flag;
                // if user select Y
                if(flag ==  "Y" || flag == "y"){
                    payment();// process payment.
                    break;// exit the loop.
                }
                // if user select N
                else if(flag ==  "N" || flag == "n"){
                    chosenCar.clear();// clear of the selected item(s)
                    cout << "Cart is clear, please choose again" << endl;
                    break;// exit loop.
                }
                else{
                    // invalid input, continue the loop
                    continue;
                }
                system("CLS");
            }
        }
        // payment function.
        void payment(){
            system("CLS");
            string soldCarPath = "soldCar.txt";
            ofstream writeCar;
            // open file to append sold car details
            writeCar.open(soldCarPath, ios::app);
            double total = 0;
            double discount = 0;
            if(!chosenCar.empty()){
                cout << "        Invoice" << endl;
                cout << "Date: " << vended.getTimer() << endl; // get the current data/time
                cout << "--------------------------" << endl;
                // Display chosen cars and calculate the total price.
                for(int i = 0; i < chosenCar.size(); i++){
                    cout << "ID: " << chosenCar[i].getID() << endl;
                    cout << "Brand: " << chosenCar[i].getBrand() << endl;
                    cout << "Country: " << chosenCar[i].getCountry() << endl;
                    cout << "Year: " << chosenCar[i].getYear() << endl;
                    cout << "Colour: " << chosenCar[i].getBrand() << endl;
                    cout << "Price: " << chosenCar[i].getPrice() << endl;
                    total += chosenCar[i].getPrice();
                    cout << "-------------------------------" << endl;
                }
                cout << "Total Price: RM" <<  total << endl;
                // which discount avaibility
                discount =  checkDiscount();
                cout << "Discount: " << discount << "%" << endl;
                cout << "Total Price After Discount: " << total - total*discount << endl;
                cout << "Only Online Banking is Available" << endl;
                cout << "MayBank" << endl;
                cout << "Account Number: 123456789876" << endl;

                // update the sold car file.
                for(int i = 0; i < chosenCar.size(); i++){
                    SoldCar tempSoldCar(currentUser.getID(), chosenCar[i]);
                    tempSoldCar.addSoldCarToFile();
                }
            }
            else{
                cout << "No Payment Available, please choose a car to make payment" << endl;
            }
        }
        // function to check discount.
        double checkDiscount(){
            string line;
            cout << "Enter Discount Code(-1 if you dont have it)> ";
            cin >> line;
            // -1 means no voucher.
            if(line == "-1"){
                cout << "Voucher applied";
                return 0;
            }
            // voucher code No.1
            else if(line == "BUBBLE10"){
                return 0.10; // amount of discount.
            }
            // voucher code No.2
            else if(line == "QUICK20"){
                return 0.20;// amount of discount.
            }
            else{
                // wrong voucher.
                cout << "INCORRECT VOUCHER, NO MORE DISCOUNT FOR YOU!" << endl;
                cout << "-------------------------------" << endl;
                return 0;
            }
        }
        // admin page function
        void adminPage(){
            // system("CLS");
            int choice;
            string line;
            // print admin menu.
            while(1){
                cout << "Edit page" << endl;
                cout << "1) Add new car" << endl;
                cout << "2) Modify car data" << endl;
                cout << "3) Remove car record" << endl;
                cout << "4) Number car sold" << endl;
                cout << "5) Check Bill" << endl;
                cout << "6) Logout" << endl;
                cout << "> ";
                cin >> choice;
                switch (choice){
                // call addcar function.
                case 1:
                    addCar();
                    break;
                // call editcar function.
                case 2:
                    editCar();
                    break;
                // call removercar function.
                case 3:
                    removeCar();
                    break;
                // call soldcar function.
                case 4:
                    soldCar();
                    break;
                // call checkbill function.
                case 5:
                    checkBill();
                    break;
                // logout
                case 6:
                    return;
                default:
                    // promp error when an invalid input is entered (only integer)
                    cout << "Invalid Input";
                    continue;
                }
            }
            system("CLS");
        }
        void addCar(){
            system("CLS");
            string brand, color, country, year, newID;
            int num, price;
            //Define the path to the car file
            string carPath = "car.txt";
            ofstream writeCar;
            // open file to append new cars
            writeCar.open(carPath, ios::app);
            // ask the user the number of car needed to add into our system
            cout << "How many car you want to add: ";
            cin >> num;
            // loop to add the number of car the user wants.
            for(int i = 0; i < num; i++){
                cout << "-----------------------------------------" << endl;
                cout << "Brand of the car: ";
                cin >> brand;
                cout << "Color of the car: ";
                cin >> color;
                cout << "Country of the car produced: ";
                cin >> country;
                cout << "Year of the car manufactured: ";
                cin >> year;
                cout << "Price of the car: ";
                cin >> price;
                // create a new car object
                car carcar(brand, color, country, year, price);
                // add the new car to cars dataset.
                cars.getCar().push_back(carcar);
                cout << "Generated car ID" << endl;
                // append a new car to our file
                writeCar << endl << carcar.getID() << "," << carcar.getBrand() << "," << carcar.getColor() << "," << carcar.getCountry() << "," << carcar.getYear() << "," << carcar.getPrice();
            }
            writeCar.close(); // close file
            cars.saveCar(); // updated list of cars
            // cars.printCars();
        }
        // editCar function.
        void editCar(){
            system("CLS");
            string carPath = "car.txt";
            string id, color;
            int sb, price;
            bool carFound = false;

            // read whole car.txt file into a vector of strings
            ifstream file(carPath);
            vector<string> fileLines;
            string line;
            while(getline(file, line)){
                fileLines.push_back(line);
            }
            file.close();
            // Display the current car list in our files 
            cars.printCars();
            while(1){
                cout << "Enter the car ID you want to edit: ";
                cin >> id;
                int index;
                // search for the car with the given ID (linear seach).
                for(int i = 0; i < cars.getCar().size(); i++){
                    if(cars.getCar()[i].getID() == id){
                        carFound = true;
                        cout << "What you want to change" << endl;
                        cout << "1) Car Colour" << endl;
                        cout << "2) Car Price" << endl;
                        cout << ">> ";
                        cin >> sb;
                        // change car color
                        if(sb == 1){
                            cout << "Before change: " << cars.getCar()[i].getColor() << endl;
                            cout << "After change: ";
                            cin >> color;
                            cars.getCar()[i].setColor(color);
                            index = i;
                        }
                        // change car price
                        else if(sb == 2){
                            cout << "Before change: " << cars.getCar()[i].getPrice() << endl;
                            cout << "After change: ";
                            cin >> price;
                            cars.getCar()[i].setPrice(price);
                            index = i;
                        }
                        // Update the specific line in the fileLines vector
                        for(int j = 0; j < fileLines.size(); j++){
                            vector<string> carData;
                            stringstream ss(fileLines[j]);
                            string token;
                            while(getline(ss, token, ',')){
                                carData.push_back(token);
                            }
                            // If the current line corresponds to the edited car, update it
                            if(carData.size() > 0 && carData[0] == id){
                                fileLines[j] = cars.getCar()[i].getID() + "," +
                                            cars.getCar()[i].getBrand() + "," +
                                            cars.getCar()[i].getColor() + "," +
                                            cars.getCar()[i].getCountry() + "," +
                                            cars.getCar()[i].getYear() + "," +
                                            to_string(cars.getCar()[i].getPrice());
                                break;
                            }
                        }
                        break;
                    }
                }
                // If the car was found and edited, write the updated vector back to the file
                if(carFound){
                    cout << "Updated datasets" << endl;
                    ofstream out(carPath);
                    for(const auto& fileLine : fileLines){
                        out << fileLine << endl;
                    }
                    out.close();
                    cars.saveCar();
                    // cars.printCars();
                    break;
                }
                else{
                    // prompt error when an invalid car ID was found
                    cout << "Car ID not found. Please try again." << endl;
                }
            }
        }
        // removecar function
        void removeCar(){
            system("CLS");
            string carPath = "car.txt";
            string id;
            bool carFound = false;

            // read the entire car.txt file into a vector of strings
            ifstream file(carPath);
            vector <string> fileLines;
            string line;
            while(getline(file, line)){
                if(!line.empty()){
                    fileLines.push_back(line);
                }
            }
            file.close();
            // display the current list of cars.
            cars.printCars();

            while(true){ // enter the car ID that want to delete.
                cout << "Enter the car ID to delete: ";
                cin >> id;
                // Search for the car with the given ID in the cars list
                auto& carList = cars.getCar();
                for(auto it = carList.begin(); it != carList.end(); ++it){
                    if(it->getID() == id){
                        carList.erase(it);
                        carFound = true;
                        // Remove the specific line from the fileLines vector
                        for(auto fileIt = fileLines.begin(); fileIt != fileLines.end(); ++fileIt){
                            vector<string> carData;
                            stringstream ss(*fileIt);
                            string token;
                            while(getline(ss, token, ',')){
                                carData.push_back(token);
                            }
                            if(!carData.empty() && carData[0] == id){
                                fileLines.erase(fileIt);
                                break;
                            }
                        }
                        break;
                    }
                }
                if(carFound){
                    cout << "Updated datasets" << endl;
                    // Remove any empty lines
                    fileLines.erase(
                        remove_if(fileLines.begin(), fileLines.end(), [](const string& line) {return line.empty();}),fileLines.end()
                    );
                    // Write the updated vector back to the file
                    ofstream out(carPath);
                    for(size_t i = 0; i < fileLines.size(); ++i){
                        out << fileLines[i];
                        if(i != fileLines.size() - 1){
                            out << endl;
                        }
                    }
                    out.close();
                    cars.saveCar();
                    // cars.printCars();
                    break;
                }
                else{
                    cout << "Car ID not found. Please try again." << endl;
                }
            }
        }
        // Function that allows the user to view all the sold car
        void soldCar(){
            system("CLS");
            solds.bubbleSort();
            //solds.printBills();
            solds.countBrands();
        }
        // Function that allow the user to view bills on a specific year.
        void checkBill(){
            system("CLS");
            string year;
            cout << "Enter the year of bill" << endl;
            cout << "> ";
            cin >> year;
            solds.printBills(year);
        }
};
// main function
int main(){
    // call the system class
    carSystem sys;
    sys.run();// run the system
}
