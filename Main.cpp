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
class allClient : public person{
    private:
        vector <person> clients;
    public:
        allClient(){
            saveClient();
        }
        void saveClient(){
            string clientPath = "client.txt";
            ifstream clientFile(clientPath);
            if(!clientFile){
                cout << "Error opening " << clientPath << endl;
            } 
            else{
                string line;
                person client;
                string temp;
                while(getline(clientFile, line)){
                    stringstream ss(line);
                    getline(ss, temp, ',');
                    client.setID(temp);
                    getline(ss, temp, ',');
                    client.setName(temp);
                    getline(ss, temp, ',');
                    client.setPassword(temp);
                    clients.push_back(client);
                }
            }
        }
        vector <person> &getClients(){
            return clients;
        }
        void printClient(){
            for(int i = 0; i < clients.size(); i++){
                cout << clients[i].getID() << clients[i].getName() << endl;
            }
        }
        void selectionSort(){
            int min_idx;
            // One by one move boundary of
            // unsorted subarray
            for(int i = 0; i < clients.size(); i++){
                // Find the minimum element in
                // unsorted array
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
class allAdmin{
    private:
        vector <person> admins;
    public:
        allAdmin(){
            saveAdmin();
        }
        void saveAdmin(){
            string adminPath = "admin.txt";
            ifstream adminFile(adminPath);
            if(!adminFile){
                cout << "Error opening " << adminPath << endl;
            } 
            else{
                string line;
                person admin;
                string temp;
                while(getline(adminFile, line)){
                    stringstream ss(line);
                    getline(ss, temp, ',');
                    admin.setID(temp);
                    getline(ss, temp, ',');
                    admin.setName(temp);
                    getline(ss, temp, ',');
                    admin.setPassword(temp);
                    admins.push_back(admin);
                }
            }
        }
        vector <person> &getAdmin(){
            return admins;
        }
        void printAdmin(){
            for(int i = 0; i < admins.size(); i++){
                cout << admins[i].getID() << admins[i].getName() << endl;
            }
        }
        int LinearSearch(string id){
            for(int i = 0; i < admins.size(); i++){
                if (admins[i].getID() == id){
                    return i;
                }
            }
            return -1;
        }
};
class car{
    protected:
        string id;
        string brand;
        string color;
        string country;
        string year;
        int price;
        void generateID(){
            srand(time(nullptr));
            id = brand.substr(0,3);
            for(int i = 0; i < 9; i++){
                id += to_string(rand()%10);
            }
        }

    public:
        car() = default;
        car(string BRAND, string COLOUR, string COM, string YOM, int PRICE){
            brand = BRAND;
            color = COLOUR;
            country = COM;
            year = YOM;
            price = PRICE;
            generateID();
        }
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

class Allcar{
    private:
        vector <car> cars;
    public:
        Allcar(){
            saveCar();
        }
        void saveCar(){
            string carPath = "car.txt";
            ifstream carFile(carPath);
            if(!carFile){
                cout << "Error opening " << carPath << endl;
            } 
            else{
                string line;
                car c;
                while(getline(carFile, line)){
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
                    cars.push_back(c);
                }
            }
            cars = cars;
        }
        vector <car> &getCar(){
            return cars;
        }
        int partitionID(int start, int end){
            car pivot = cars[start];
            int count = 0;
            for(int i = start + 1; i <= end; i++){
                if(cars[i].getID() <= pivot.getID())
                    count++;
            }
            // Giving pivot element its correct position
            int pivotIndex = start + count;
            swap(cars[pivotIndex], cars[start]);
            // Sorting left and right parts of the pivot element
            int i = start, j = end;
            while(i < pivotIndex && j > pivotIndex){
                while (cars[i].getID() <= pivot.getID()){
                    i++;
                }
                while(cars[j].getID() > pivot.getID()){
                    j--;
                }
                if(i < pivotIndex && j > pivotIndex){
                    swap(cars[i++], cars[j--]);
                }
            }
            return pivotIndex;
        }
        void quickSortID(int start, int end){
            // base case
            if (start >= end)
                return;
            // partitioning the array
            int p = partitionID(start, end);
            // Sorting the left part
            quickSortID(start, p - 1);
            // Sorting the right part
            quickSortID(p + 1, end);
        }
        int partitionBrand(int start, int end){
            car pivot = cars[start];
            int count = 0;
            for(int i = start + 1; i <= end; i++){
                if(cars[i].getBrand() <= pivot.getBrand())
                    count++;
            }
            // Giving pivot element its correct position
            int pivotIndex = start + count;
            swap(cars[pivotIndex], cars[start]);
            // Sorting left and right parts of the pivot element
            int i = start, j = end;
            while(i < pivotIndex && j > pivotIndex){
                while(cars[i].getBrand() <= pivot.getBrand()){
                    i++;
                }
                while(cars[j].getBrand() > pivot.getBrand()){
                    j--;
                }
                if(i < pivotIndex && j > pivotIndex){
                    swap(cars[i++], cars[j--]);
                }
            }
            return pivotIndex;
        }
        void quickSortBrand(int start, int end){        
            // base case
            if(start >= end)
                return;
            // partitioning the array
            int p = partitionBrand(start, end);
            // Sorting the left part
            quickSortBrand(start, p - 1);
            // Sorting the right part
            quickSortBrand(p + 1, end);
        }
        int partitionPrice(int start, int end){
            car pivot = cars[start];
            int count = 0;
            for(int i = start + 1; i <= end; i++){
                if(cars[i].getPrice() <= pivot.getPrice())
                    count++;
            }
            // Giving pivot element its correct position
            int pivotIndex = start + count;
            swap(cars[pivotIndex], cars[start]);
            // Sorting left and right parts of the pivot element
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
            // partitioning the array
            int p = partitionPrice(start, end);
            // Sorting the left part
            quickSortPrice(start, p - 1);
            // Sorting the right part
            quickSortPrice(p + 1, end);
        }
        int LinearSearch(string ID){
            for(int i = 0; i < cars.size(); i++){
                if(cars[i].getID() == ID){
                    return i;
                }
            }
            return -1;
        }
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
        void addSoldCarToFile(){
            ofstream file;
            file.open("soldCar.txt", ios::app);
            file << endl << id << ',' << brand << ',' << color << ',' << country << ',' << year << ',' << price << ',' << period << ',' << userID;
        }
};

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
        void bubbleSort(){
            bool swaps;
            for(int i = 0; i < soldVec.size() - 1; i++){
                swaps = false;
                for(int j = 0; j < soldVec.size() - i - 1; j++){
                    if(soldVec[j].getID() > soldVec[j + 1].getID()){
                        swap(soldVec[j], soldVec[j + 1]);
                        swaps = true;
                    }
                }
                if(!swaps){
                    break;
                }
            }
        }
        void countBrands(){
            system("CLS");
            bubbleSort();
            bool swaps;
            int totalCount = 0;
            map<string, int> brandCount;

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
class carSystem{
    private:
        allClient clients;
        Allcar cars;
        SoldCar vended;
        SoldCarLoader solds;       
        allAdmin admins;
        person currentUser;
        vector <car> chosenCar;
        int type;
    public:
        void run(){
            int choice;
            int flag = 0;
            string line;
            while(1){
                if(flag == 0){
                    cout << "1) Client" << endl;
                    cout << "2) Admin" << endl;
                    cout << "-1) Exit" << endl;
                    cout << "choice> ";
                    cin >> choice;
                    switch(choice){
                        case 1:
                            if(login(1)){
                                system("CLS");
                                type = 1;
                                break;
                            }
                            continue;
                        case 2:
                            if(login(2)){
                                system("CLS");
                                type = 2;
                                break;
                            }
                            continue;
                        case -1:
                            flag = 1;
                            break;
                        default:
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

            if(type == 1){
                cout << "ID> ";
                cin >> line;
                clients.selectionSort();
                temp = clients.binarySearch(0, clients.getClients().size()-1, line);
                if(temp >= 0){
                    currentUser = clients.getClients()[temp];
                    cout << "Password> ";
                    cin >> line;
                    if(line == currentUser.getPassword()){
                        return 1;
                    }
                    else{
                        cout << "Incorrect Password :(" << endl;
                    }
                }
                else{
                    cout << "User Not Found :(" << endl;
                }
                return 0;
            }
            else if(type == 2){
                cout << "ID> ";
                cin >> line;
                // change to function
                for(int i = 0; i < admins.getAdmin().size(); i++){
                    if(line == admins.getAdmin()[i].getID()){
                        cout << "Password> ";
                        cin >> line;
                        if(line == admins.getAdmin()[i].getPassword()){
                            return true;
                        }
                        cout << "Incorrect Password :)" << endl;
                        break;
                    }
                }
            }
            return false;
        }
        void clientPage(){
            system("CLS");
            int choice;
            int flag = 0;
            string line;
            while(1){
                cout << "1) View history purchase" << endl;
                cout << "2) Make Purchase" << endl;
                cout << "-1) log Out" << endl;
                cout << "> ";
                cin >> choice;
                if(choice == 1){
                    cout << "Purchase History" << endl;
                    solds.printBillsID(currentUser.getID());
                }
                else if(choice == 2){
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
                            system("CLS");
                            cars.quickSortID(0, cars.getCar().size()-1);
                            break;
                        case 2:
                            system("CLS");
                            cars.quickSortPrice(0,cars.getCar().size()-1);
                            break;
                        case 3:
                            system("CLS");
                            cars.quickSortBrand(0, cars.getCar().size()-1);
                            break;
                        case 4:
                            selectPurchase();
                            break;
                        case 5:
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
                            break;
                        }
                    }
                }
                else if(choice == -1){
                    cout << "Thank You for choosing us" << endl;
                    break;
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
            cars.printCars();
            while(flag == 0){
                cout << "Enter Car ID> ";
                cin >> line;
                index = cars.LinearSearch(line);
                chosenCar.push_back(cars.getCar()[index]);
                flag = 1;
                if(index == -1){
                    cout << "Incorrect Car ID" << endl;
                }
                if(flag == 1){
                    break;
                }
            }
        }
        void confirmPurchase(){
            system("CLS");
            string flag;
            while(1){
                cout << "       Your Purchase" << endl;
                cout << "----------------------------" << endl;
                for(int i = 0; i < chosenCar.size(); i++){
                    cout << "ID: " << chosenCar[i].getID() << endl;
                    cout << "Brand: " << chosenCar[i].getBrand() << endl;
                    cout << "Country of manufacture: " << chosenCar[i].getCountry() << endl;
                    cout << "Year of Manufacture: " << chosenCar[i].getYear() << endl;
                    cout << "Color: " << chosenCar[i].getColor() << endl;
                    cout << "Price: " << chosenCar[i].getPrice() << endl;
                    cout << "---------------------------------------------" << endl;
                }
                cout << "Confirm Purchase [Y/N]" << endl;
                cout << "> ";
                cin >> flag;
                if(flag ==  "Y" || flag == "y"){
                    payment();
                    break;
                }
                else if(flag ==  "N" || flag == "n"){
                    chosenCar.clear();
                    cout << "Cart is clear, please choose again" << endl;
                    break;
                }
                else{
                    continue;
                }
                system("CLS");
            }
        }
        void payment(){
            system("CLS");
            string soldCarPath = "soldCar.txt";
            ofstream writeCar;
            writeCar.open(soldCarPath, ios::app);
            double total = 0;
            double discount = 0;
            if(!chosenCar.empty()){
                cout << "        Invoice" << endl;
                cout << "Date: " << vended.getTimer() << endl;
                cout << "--------------------------" << endl;
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
                discount =  checkDiscount();
                cout << "Discount: " << discount << "%" << endl;
                cout << "Total Price After Discount: " << total - total*discount << endl;
                cout << "Only Online Banking is Available" << endl;
                cout << "MayBank" << endl;
                cout << "Account Number: 123456789876" << endl;

                for(int i = 0; i < chosenCar.size(); i++){
                    SoldCar tempSoldCar(currentUser.getID(), chosenCar[i]);
                    tempSoldCar.addSoldCarToFile();
                }
            }
            else{
                cout << "No Payment Available, please choose a car to make payment" << endl;
            }
        }
        double checkDiscount(){
            string line;
            cout << "Enter Discount Code(-1 if you dont have it)> ";
            cin >> line;
            if(line == "-1"){
                cout << "Voucher applied";
                return 0;
            }
            else if(line == "BUBBLE10"){
                return 0.10;
            }
            else if(line == "QUICK20"){
                return 0.20;
            }
            else{
                cout << "INCORRECT VOUCHER, NO MORE DISCOUNT FOR YOU!" << endl;
                cout << "-------------------------------" << endl;
                return 0;
            }
        }
        void adminPage(){
            // system("CLS");
            int choice;
            string line;
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
                case 1:
                    addCar();
                    break;
                case 2:
                    editCar();
                    break;
                case 3:
                    removeCar();
                    break;
                case 4:
                    soldCar();
                    break;
                case 5:
                    checkBill();
                    break;
                case 6:
                    return;
                default:
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
            string carPath = "car.txt";
            ofstream writeCar;
            writeCar.open(carPath, ios::app);
            cout << "How many car you want to add: ";
            cin >> num;
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
                car carcar(brand, color, country, year, price);
                cars.getCar().push_back(carcar);
                cout << "Generated car ID" << endl;
                writeCar << endl << carcar.getID() << "," << carcar.getBrand() << "," << carcar.getColor() << "," << carcar.getCountry() << "," << carcar.getYear() << "," << carcar.getPrice();
            }
            writeCar.close();
            cars.saveCar();
            // cars.printCars();
        }
        void editCar(){
            system("CLS");
            string carPath = "car.txt";
            string id, color;
            int sb, price;
            bool carFound = false;

            ifstream file(carPath);
            vector<string> fileLines;
            string line;
            while(getline(file, line)){
                fileLines.push_back(line);
            }
            file.close();
            cars.printCars();
            while(1){
                cout << "Enter the car ID you want to edit: ";
                cin >> id;
                int index;
                for(int i = 0; i < cars.getCar().size(); i++){
                    if(cars.getCar()[i].getID() == id){
                        carFound = true;
                        cout << "What you want to change" << endl;
                        cout << "1) Car Colour" << endl;
                        cout << "2) Car Price" << endl;
                        cout << ">> ";
                        cin >> sb;
                        if(sb == 1){
                            cout << "Before change: " << cars.getCar()[i].getColor() << endl;
                            cout << "After change: ";
                            cin >> color;
                            cars.getCar()[i].setColor(color);
                            index = i;
                        }
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
                    cout << "Car ID not found. Please try again." << endl;
                }
            }
        }

        void removeCar(){
            system("CLS");
            string carPath = "car.txt";
            string id;
            bool carFound = false;

            ifstream file(carPath);
            vector <string> fileLines;
            string line;
            while(getline(file, line)){
                if(!line.empty()){
                    fileLines.push_back(line);
                }
            }
            file.close();
            cars.printCars();

            while(true){
                cout << "Enter the car ID to delete: ";
                cin >> id;
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
        void soldCar(){
            system("CLS");
            solds.bubbleSort();
            //solds.printBills();
            solds.countBrands();
        }
        void checkBill(){
            system("CLS");
            string year;
            cout << "Enter the year of bill" << endl;
            cout << "> ";
            cin >> year;
            solds.printBills(year);
        }
};
int main(){
    carSystem sys;
    sys.run();
}
