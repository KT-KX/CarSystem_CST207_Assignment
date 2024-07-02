# CarSystem_CST207_Assignment
You are a software developer at a software development company. One of the largest car dealerships has approached your company, requesting a program to manage their business operations. The purpose of this system is to streamline tasks related to car brands, customers, billing, and more.

C++ version C++17

Instruction manual:
User logins
Clients:
    Username: SWT
    Password: SWT999

    Username: TYX
    Password: TYX999

Admins:
    Username: EKT
    Password: EKT99

    Username: NHM
    Password: NHM999

    Username: KMK
    Password: KMK999

Discount:
    Code: BUBBLE10
    Discount: 10%

    Code: QUICK20
    Discount: 20%

Main manu
Once the programme is executed the terminal will allow the user to choose the login mode (admin or client) user may choose any mode and login to their account. usernames and password is provided above.

Client manu:
(1)Once login the user is able to choose to view history of purchase from the company(i), buy new car(ii) or to logout(iii). (client main manu)

(i)The system will prompt all the history purchase then return back to the client main manu

(ii)Purchase Manu:
The system will display all the available vehicles to purchase in a unsorted manner (only once) the user is allow to sort the list by (1)carID(alphabetical), (2)price(low to high) or (3)brand(alphabetical).

(4)To make purchase, (5)to checkout and (6)to return back to the client main manu

(a)The user the able to keep puchasing until the users checkout.
(b)After the user checkout, the system is prompt an invoice for confirmation on purchase. 

if Y the system will procede to asking the user for discount code(discount code and discount percentage are above) after applying the code the purchase is made

else N cart will be empty and user is required to select the car again.

(iii)Logout the user and return to the main manu.

Admin menu:
The admin has the ability to (1)add new car(s), (2)modify car record(s), (3)remove car record(S), (4)check number of car sold, (5)check bills on specific year (6)logout(works the same as client logout)

(1)The user has to input the number of car(s) he/she want to add then, 
The user is required to key in the details one by one:
    Brand(string)
    color(string)
    country(string)
    year(string)
    price(int)
    (CarID will be generated randomly by the system)

(2)The user may modify the price and color on a specific car by keying in the car ID

(3)The user may remove the car record by keying in the car ID

(4)The system prompt all the sold vehicle using below format:
    PROTON : 6
    BMW : 5
    TOYOTA : 4

(5)The user has to key in a specific year, then the system will display all the vehicle sold on that year
