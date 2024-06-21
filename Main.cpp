#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include <sstream>

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
        int LinearSearch(int arr[], int n, int x){
            for(int i = 0; i < n; i++){
                if (arr[i] == x){
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
            id = id.substr(0,3);
            for(int i = 0; i < 13; i++){
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
        void addCar(const car &c){
            string brand, color, country, year;
            int price;
            string carPath = "car.txt";
            ofstream writeCar;
            writeCar.open(carPath, ios::app);
            if(!writeCar){
                cout << "Error opening " << carPath << endl;
            }
            else{
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
                writeCar << brand << "," << color << "," << country << "," << year << "," << price << endl;
                car cw(brand, color, country, year, price);
                cars.push_back(c);
            }
            copy_cars = cars;
        }

        void mergeSort(){
            copy_cars = cars;
            // Implement merge sort here
        }

        void radixSort(){
            copy_cars = cars;
            // Implement radix sort here
        }


        void bubbleSort(){
            copy_cars = cars;
            // Implement bubble sort here
        }

        void selectionSort(int arr[], int n){
            copy_cars = cars;
            int min_idx;

            // One by one move boundary of
            // unsorted subarray
            for(int i = 0; i < n - 1; i++){

                // Find the minimum element in
                // unsorted array
                min_idx = i;
                for(int j = i + 1; j < n; j++){
                    if(arr[j] < arr[min_idx]){
                        min_idx = j;
                    }
                }

                // Swap the found minimum element
                // with the first element
                if(min_idx != i){
                    swap(arr[min_idx], arr[i]);
                }
            }
        }

        int partition(int arr[], int start, int end){
            int pivot = arr[start];

            int count = 0;
            for(int i = start + 1; i <= end; i++){
                if(arr[i] <= pivot){
                    count++;
                }
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
    
        void quickSort(int arr[], int start, int end){
            copy_cars = cars;
            
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
        int binarySearch(int arr[], int low, int high, int x){
            while(low <= high){
                int mid = low + (high - low) / 2;

                // Check if x is present at mid
                if(arr[mid] == x){
                    return mid;
                }

                // If x greater, ignore left half
                if(arr[mid] < x){
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
        int LinearSearch(int arr[], int n, int x){
            for(int i = 0; i < n; i++){
                if (arr[i] == x){
                    return i;
                }
            }
            return -1;
        }

        void printCars()const{
            for(const auto &c : copy_cars){
                cout << c.getID() << ", " << c.getBrand() << ", " << c.getColor() << ", "
                    << c.getCountry() << ", " << c.getYear() << ", " << c.getPrice() << endl;
            }
        }
};
class carSystem{
    private:
        allClient clients;
        Allcar cars;
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
                cout << "5) Checkout" << endl;
                cout << "> ";
                cin >> choice;
                switch (choice)
                {
                case 1:
                    break;
                case 2:
                    break;
                case 3:
                    break;
                case 4:
                    selectPurchase();
                    break;
                case 5:
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
            string flag;
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

            }
        }
        void adminPage(){
            int choice;
            int flag;
            string line;
            while(1){
                cars.printCars();
                cout << "Edit page" << endl;
                cout << "1) Add new car" << endl;
                cout << "2) Modify car data" << endl;
                cout << "3) Remove car record" << endl;
                cout << "4) Number car sold" << endl;
                cout << "5) Exit" << endl;
                cout << "> ";
                cin >> choice;
                switch (choice)
                {
                case 1:
                    break;
                case 2:
                    break;
                case 3:
                    break;
                case 4:
                    break;
                case 5:
                    flag = 1;
                default:
                    cout << "Invalid Input";
                    continue; 
                }
                if(flag == 1){
                    return;
                }
            }
        }
};
int main(){
    carSystem sys;
    sys.run();

}
