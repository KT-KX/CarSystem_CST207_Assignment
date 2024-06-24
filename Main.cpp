#include <iostream>
#include <cstdlib>
#include <string>
#include <vector>
#include <fstream>
#include <sstream>
#include <map>
#include <ctime>

using namespace std;

class sortingNsearch{
    public:
        
};

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
            if (!clientFile) {
                cout << "Error opening " << clientPath << endl;
            } 
            else {
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


        int partition(int arr[], int start, int end){
            int pivot = arr[start];
    
            int count = 0;
            for(int i = start + 1; i <= end; i++){
                if (arr[i] <= pivot)
                    count++;
            }
        
            // Giving pivot element its correct position
            int pivotIndex = start + count;
            swap(arr[pivotIndex], arr[start]);
        
            // Sorting left and right parts of the pivot element
            int i = start, j = end;
        
            while(i < pivotIndex && j > pivotIndex){
                while(arr[i] <= pivot){
                    i++;
                }
        
                while(arr[j] > pivot){
                    j--;
                }
        
                if(i < pivotIndex && j > pivotIndex){
                    swap(arr[i++], arr[j--]);
                }
            }
        
            return pivotIndex;
        }
 
        void quickSort(int arr[], int start, int end)
        {
        
            // base case
            if(start >= end){
                return;
            }
        
            // partitioning the array
            int p = partition(arr, start, end);
        
            // Sorting the left part
            quickSort(arr, start, p - 1);
        
            // Sorting the right part
            quickSort(arr, p + 1, end);
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
        int LinearSearch(int arr[], int n, int x){
            for(int i = 0; i < n; i++){
                if (arr[i] == x){
                    return i;
                }
            }
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
    private:
        string id;
        string brand;
        string color;
        string country;
        string year;
        int price;
        void generateID(){
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
        vector <car> copy_cars;
        
    public:
        Allcar(){
            saveCar();
            copy_cars = cars;
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
            copy_cars = cars;
        }
        vector <car> &getCar(){
            return copy_cars;
        }

        void selectionSort(){
            copy_cars = cars;
            int min_idx;
            for(int i = 0; i < copy_cars.size(); i++){
                // Find the minimum element in
                // unsorted array
                min_idx = i;
                for(int j = i + 1; j < copy_cars.size(); j++){
                    if(copy_cars[j].getID() < copy_cars[min_idx].getID()){
                        min_idx = j;
                    }
                }
                // Swap the found minimum element
                // with the first element
                if(min_idx != i){
                    swap(copy_cars[min_idx], copy_cars[i]);
                }
            }
        }

        int binarySearch(int low, int high, string x){
            copy_cars = cars;

            while(low <= high){
                int mid = low + (high - low) / 2;

                // Check if x is present at mid
                if(copy_cars[mid].getBrand() == x){
                    return mid;
                }

                // If x greater, ignore left half
                if(copy_cars[mid].getBrand() < x){
                    low = mid + 1;
                }

                // If x is smaller, ignore right half
                else{
                    high = mid - 1;
                }
            }
                // If we reach here, then element was not present
                return -1;
        }

        void printCars()const{
            system("CLS");
            for(const auto &c : copy_cars){
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
class allSoldCar : public car{
    private:
        vector <car> soldVec;
        vector <car> copySoldVec;
        string timer;
        string period;

    public:
        allSoldCar(){
            saveSoldCar();
        }

        void saveSoldCar(){
            string soldCarPath = "soldCar.txt";
            ifstream soldFile(soldCarPath);
            if(!soldFile){
                cout << "Error opening " << soldCarPath << endl;
            }
            else{
                string line;
                car s;
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
                    soldVec.push_back(s);
                }
            }
            copySoldVec = soldVec;
        }

        vector <car> &getCar(){
            return copySoldVec;
        }

        void bubbleSort(){
            copySoldVec = soldVec;
            bool swaps;

            for(int i = 0; i < copySoldVec.size() - 1; i++){
                swaps = false;
                for(int j = 0; j < copySoldVec.size() - i - 1; j++){
                    if(copySoldVec[j].getID() > copySoldVec[j + 1].getID()){
                        swap(copySoldVec[j], copySoldVec[j + 1]);
                        swaps = true;
                    }
                }
                if(!swaps){
                    break;
                }
            }
        }

        void countBrands(){
            //system("CLS");
            bubbleSort();
            bool swaps;
            int totalCount;
            map<string, int> brandCount;

            for(const auto& car : copySoldVec){
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
            copySoldVec = soldVec;

            while(low <= high){
                int mid = low + (high - low) / 2;
                // Check if x is present at mid
                if(copySoldVec[mid].getBrand() == x){
                    return mid;
                }
                // If x greater, ignore left half
                if(copySoldVec[mid].getBrand() < x){
                    low = mid + 1;
                }
                // If x is smaller, ignore right half
                else{
                    high = mid - 1;
                }
            }
                return -1;
        }

        void setPeriod(string p){
            period = p;
        }

        string getPeriod()const{
            return period;
        }

        string getTimer(){
            // Get the timestamp for the current date and time
            time_t timestamp;
            time(&timestamp);
            cout << ctime(&timestamp);
            return timer;
        }

        void printCars()const{
            system("CLS");
            for(const auto &c : copySoldVec){
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

class soldCar : public car{
    private:
        vector <allSoldCar> soldVec;
        vector <allSoldCar> copySoldVec;

    public:
        soldCar(){
            saveSoldCar();
        }

        void saveSoldCar(){
            string soldCarPath = "soldCar.txt";
            ifstream soldFile(soldCarPath);
            if(!soldFile){
                cout << "Error opening " << soldCarPath << endl;
            }
            else{
                string line;
                allSoldCar s;
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
                    soldVec.push_back(s);
                }
            }
            copySoldVec = soldVec;
        }

        void printBills()const{
            //system("CLS");
            for(const auto &s : copySoldVec){
                cout << "-----------------------------------------" << endl;
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
};

class carSystem{
    private:
        allClient clients;
        Allcar cars;
        allSoldCar vended;
        soldCar solds;
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
                                type = 1;
                                break;
                            }
                            continue;
                        case 2:
                            if(login(2)){
                                type = 2;
                                break;
                            }
                            continue;
                        case -1:
                            flag = 1;
                            break;
                        default:
                            continue;
                    }
                }
                cout << "Welcome to SHARK BEE" << endl;
                cout << currentUser.getName() << endl;
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
            //system("CLS");
            int choice;
            int flag;
            string line;
            while(1){
                cars.printCars();
                cout << "Sort by" << endl;
                cout << "1) ID" << endl;
                cout << "2) Price" << endl;
                cout << "3) Brand" << endl;
                cout << "4) Select Purchase" << endl;
                cout << "5) Check Bill" << endl;
                cout << "6) Checkout" << endl;
                cout << "> ";
                cin >> choice;
                switch (choice){
                case 1:
                    break;
                case 2:
                    break;
                case 3:
                    break;
                case 4:
                    selectPurchase();
                    confirmPurchase();
                    break;
                case 5:
                    //checkBill();
                    break;
                case 6:
                    flag = 1;                    
                default:
                    cout << "Invalid Input";
                    continue; 
                }
                if(flag == 1){
                    
                }

            }
        }
        void selectPurchase(){
            system("CLS");
            string line;
            int flag = 0;
            while(flag == 0){
                cout << "Enter Car ID> ";
                cin >> line;
                for(int i = 0; i < cars.getCar().size(); i++){
                    if(line == cars.getCar()[i].getID()){
                        chosenCar.push_back(cars.getCar()[i]);
                        flag = 1;
                    }
                }
                if(!flag)
                cout << "Incorrect Car ID" << endl;
            }
        }
        void confirmPurchase(){
            system("CLS");
            string flag;
            string period;
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
            if(flag ==  "Y"){
                //period = vended.getTimer();
            }
        }
        void checkBill(){
            // solds.printBills();
            // cout << "bello";
        }
        void adminPage(){
            system("CLS");
            int choice;
            string line;
            while(1){
                cout << "Edit page" << endl;
                cout << "1) Add new car" << endl;
                cout << "2) Modify car data" << endl;
                cout << "3) Remove car record" << endl;
                cout << "4) Number car sold" << endl;
                cout << "5) Exit" << endl;
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
                    return;
                default:
                    cout << "Invalid Input";
                    continue;
                }
            }
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
                cout << "Generated car ID" << endl;
                writeCar << endl << carcar.getID() << "," << carcar.getBrand() << "," << carcar.getColor() << "," << carcar.getCountry() << "," << carcar.getYear() << "," << carcar.getPrice() << endl;
            }
            cars.printCars();
            writeCar.close();
        }

        void editCar(){
            system("CLS");
            string carPath = "car.txt";
            string id, color;
            int sb, price, flag;
            bool carFound;
            ifstream file(carPath);
            cars.printCars();
            while(1){
                cout << "Enter the car ID you want to edit: ";
                cin >> id;
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
                        }
                        else if(sb == 2){
                            cout << "Before change: " << cars.getCar()[i].getPrice() << endl;
                            cout << "After change: ";
                            cin >> price;
                            cars.getCar()[i].setPrice(price);
                        }
                    }
                }
                cout << "Updated datasets" << endl;
                cars.printCars();          
                ofstream out(carPath);
                for(const auto& car : cars.getCar()){
                    out << car.getID() << "," << car.getBrand() << "," << car.getColor() << "," << car.getCountry() << "," << car.getYear() << "," << car.getPrice() << endl;
                }
                out.close();
                flag = 0;
                if(flag == 0){
                    break;
                }
                else{
                    continue;
                }
            }
        }

        void removeCar(){
            system("CLS");
            string carPath = "car.txt";
            string id;
            int flag;
            ifstream file(carPath);
            cars.printCars();
            while(1){
                cout << "Enter the car ID to delete: ";
                cin >> id;
                cars.getCar();
                for(int i = 0; i < cars.getCar().size(); i++){
                    if(cars.getCar()[i].getID() == id){
                        cars.getCar().erase(cars.getCar().begin()+i);
                    }
                }
                cout << "Updated datasets" << endl;
                cars.printCars();
                flag = 0;
                ofstream out(carPath);
                for(const auto& car : cars.getCar()){
                    out << car.getID() << "," << car.getBrand() << "," << car.getColor() << "," << car.getCountry() << "," << car.getYear() << "," << car.getPrice() << endl;
                }
                out.close();              
                if(flag == 0){
                    break;
                }
                else{
                    continue;
                }
            }
        }

        void soldCar(){
            system("CLS");
            vended.bubbleSort();
            vended.printCars();
            vended.countBrands();
        }
};
int main(){
    soldCar cr;
    cr.printBills();
    carSystem sys;
    sys.run();
}
