


#include<iostream>
#include<fstream>
#include<iomanip>  
#include<unistd.h>
using namespace std;

void menu();


// Encapsulation concept

class ManageMenu
{
protected :
    string userName;

public:
    ManageMenu()
    {
        cout << "\n\n\n\n\n\n\n\n\n\n\n\n\t Enter your name to continue as an admin : " << " " ;
        cin >> userName ;
        system("CLS");
        menu();
    }
    ~ManageMenu() {}
};

class Customers
{
public:
    string name, gender, address;
    int age, mobileNo;
    static int cusID;
    char all[999];

    // method to get details form user
    void detDetails()
    {
        ofstream out("old-customers.txt", ios::app);
        {
            cout << "Enter the Customer Id :";
            cin >> cusID;
            cout << "Enter the Name :";
            cin >> name;
            cout << "Enter the Age :";
            cin >> age;
            cout << "Enter the mobile number :";
            cin >> mobileNo;
            cout << "Enter Address :";
            cin >> address;
            cout << "Enter Gender :";
            cin >> gender;
        }
        out << "\n Customer Id: " << cusID << "\n Name"<<name << "\n Age" << age << "\n Mobile NUmber" << mobileNo << "\n Address" << address << "\n gender" << gender << endl;
        out.close();
        cout <<"\n Saved  \n Note: We save your details records for future purpose \n " << endl;

    }
    void showDetails()
    {
        ifstream in("old-customers.txt");
        {
            if (!in)
            {
                cout << "File error! " ;
            }
            while(!(in.eof()))
            {
                in.getline(all, 999);
                cout << all << endl;

            }
            in.close();
        }
    }

};

int Customers::cusID;

class Cabs
{
public:
    int cabChoice;
    int kilometers;
    float cabCost;
    static float lastCabCost;

    void cabDetails()
    {
        cout << "We collaborated with fastest, safest and smartest cas sevice around the country " << endl;
        cout << "-----------------Xilion Cabs--------------" << endl;
        cout << "1. Rent of a Standard cab - Rs.15 for 1KM " << endl;
        cout << "2. Rent of a Luxury cab - Rs.25 for 1KM " << endl;

        cout <<"\n\n To calcute the cost for your journey : "<< endl;
        cout << "\n Choose the cab for your need\n";
        cin >> cabChoice;
        cout << "\n Enter the destination distane for your travel in KM\n";
        cin >> kilometers;

        int hireCab;

        if (cabChoice == 1)
        {
            cabCost = kilometers * 15;
            cout << "\n Your tour cost is " << cabCost << "rupees for a standard cab \n" ;
            cout << "\n Press 1 to hire this cab " << endl;
            cout << "             Or             " << endl;
            cout << "\n Press 2 to hire another cab " << endl;
            cin >> hireCab;

            system("CLS");
            if (hireCab == 1)
            {
                lastCabCost = cabCost;
                cout <<"\n You have successfully hired a Standard cab "<< endl;
                cout << "Goto Menu and take the receipt" << endl;
            }
            else if (hireCab == 2)
            {
                cabDetails();
            }
            else
            {
                cout << "Invalid Input ! Redirecting to previous menu \n Please Wait " << endl;
                usleep(999);
                system("CLS");
                cabDetails();
            }
        }
        else if (cabChoice == 2)
        {
            cabCost = kilometers * 25;
            cout << "\n Your tour cost is " << cabCost << "rupees for a standard cab \n" ;
            cout << "\n Press 1 to hire this cab " << endl;
            cout << "             Or             " << endl;
            cout << "\n Press 2 to hire another cab " << endl;
            cin >> hireCab;

            system("CLS");
            if (hireCab == 1)
            {
                lastCabCost = cabCost;
                cout <<"\n You have successfully hired a Luxuary cab "<< endl;
                cout << "Goto Menu and take the receipt" << endl;
            }
            else if (hireCab == 2)
            {
                cabDetails();
            }
            else
            {
                cout << "Invalid Input ! Redirecting to previous menu \n Please Wait " << endl;
                usleep(1100);
                system("CLS");
                cabDetails();
            }
        }
        else
        {
            cout << "Invalid Input ! Redirecting to main menu \n Please Wait " << endl;
            usleep(1100);
            system("CLS");
            menu();
        }
        cout << "\n Press 1 to redirect Main menu : ";
        cin >> hireCab;
        system("CLS");
        if (hireCab == 1)
        {
            menu();
        }
        else
        {
            menu();
        }

    }

};

float Cabs::lastCabCost;

class Booking
{
public :
    int choiceHotel;
    int packageChoice;
    static float hotelCost;

    void hotels()
    {
        string hotelNo[] = {"Alendra","ReckonCity","FrostBay"};
        for (int a = 0; a < 3; a++)
        {
            cout << (a+1) << ".Hotel" << hotelNo[a] << endl;
        }
        cout << "\n Currently we collaborated with above hotels !" << endl;
        cout << "\n Press any ley to back or \n Enter number of the hotel you want to book : " ;
        cin >> choiceHotel;

        system("CLS");

        if (choiceHotel == 1)
        {
            cout <<"\n--------Welcome to Hotel Alendra--------\n";
            cout <<"The Graden, food, beverage. Enjoy all you can drinks, stay cool and get chilled in the summer \n ";
            cout <<"\nPackage offered by Alendra: \n" <<endl;
            cout <<"1. Standard Package" << endl;
            cout <<"\t All basic facilities you need just for: Rs 5000.00" << endl;
            cout <<"2. Premium Package " << endl;
            cout << "\t Enjoy premium at Rs: 10000.00 "<< endl;
            cout <<"3. Luxury Package " << endl;
            cout << "\t Live a Luxury at Avendra : Rs.15000 " << endl;

            cout <<"\n Press any key to key back or \n Enter package number you want to book: " << " ";
            cin >> packageChoice;

            if (packageChoice == 1)
            {
                hotelCost = 5000.00;
                cout <<"\n You have successfully booked Standard pack at Avendra " << endl;
                cout << "Goto menu and take the receipt "<< endl;
            }
            else if (packageChoice == 2)
            {
                hotelCost = 10000.00;
                cout <<"\n You have successfully booked Premium pack at Avendra " << endl;
                cout << "Goto menu and take the receipt "<< endl;
            }
            else if (packageChoice == 3)
            {
                hotelCost = 15000.00;
                cout <<"\n You have successfully booked Luxury pack at Avendra " << endl;
                cout << "Goto menu and take the receipt "<< endl;
            }
            else
            {
                cout << "Invalid Input ! Recirecting to Previous Menu  \n Please Wait !" <<endl;
                usleep(1100);
                system("CLS");
                hotels();
            }
            int gotomenu;

            cout <<"\n Press 1 to redirect main menu : " ;
            cin >> gotomenu;

            if (gotomenu == 1)
            {
                menu();
            }
            else
            {
                menu();
            }
        }
        else if (choiceHotel == 2)
        {
            cout <<"\n--------Welcome to Hotel ReckonCity--------\n";
            cout <<"The Graden, food, beverage. Enjoy all you can drinks, stay cool and get chilled in the summer \n ";
            cout <<"\nPackage offered by ReckonCity: \n" <<endl;
            cout <<"1. Standard Package" << endl;
            cout <<"\t All basic facilities you need just for: Rs 5000.00" << endl;
            cout <<"2. Premium Package " << endl;
            cout << "\t Enjoy premium at Rs: 10000.00 "<< endl;
            cout <<"3. Luxury Package " << endl;
            cout << "\t Live a Luxury at Avendra : Rs.15000 " << endl;

            cout <<"\n Press any key to key back or \n Enter package number you want to book: " << " ";
            cin >> packageChoice;

            if (packageChoice == 1)
            {
                hotelCost = 5000.00;
                cout <<"\n You have successfully booked Standard pack at ReckonCity " << endl;
                cout << "Goto menu and take the receipt "<< endl;
            }
            else if (packageChoice == 2)
            {
                hotelCost = 10000.00;
                cout <<"\n You have successfully booked Premium pack at ReckonCity " << endl;
                cout << "Goto menu and take the receipt "<< endl;
            }
            else if (packageChoice == 3)
            {
                hotelCost = 15000.00;
                cout <<"\n You have successfully booked Luxury pack at ReckonCity " << endl;
                cout << "Goto menu and take the receipt "<< endl;
            }
            else
            {
                cout << "Invalid Input ! Recirecting to Previous Menu  \n Please Wait !" <<endl;
                usleep(1100);
                system("CLS");
                hotels();
            }
            int gotomenu;

            cout <<"\n Press 1 to redirect main menu : " ;
            cin >> gotomenu;

            if (gotomenu == 1)
            {
                menu();
            }
            else
            {
                menu();
            }
        }
        else if (choiceHotel == 3)
        {
            cout <<"\n--------Welcome to Hotel FrostBay--------\n";
            cout <<"The Graden, food, beverage. Enjoy all you can drinks, stay cool and get chilled in the summer \n ";
            cout <<"\nPackage offered by FrostBay: \n" <<endl;
            cout <<"1. Standard Package" << endl;
            cout <<"\t All basic facilities you need just for: Rs 5000.00" << endl;
            cout <<"2. Premium Package " << endl;
            cout << "\t Enjoy premium at Rs: 10000.00 "<< endl;
            cout <<"3. Luxury Package " << endl;
            cout << "\t Live a Luxury at Avendra : Rs.15000 " << endl;

            cout <<"\n Press any key to key back or \n Enter package number you want to book: " << " ";
            cin >> packageChoice;

            if (packageChoice == 1)
            {
                hotelCost = 5000.00;
                cout <<"\n You have successfully booked Standard pack at FrostBay " << endl;
                cout << "Goto menu and take the receipt "<< endl;
            }
            else if (packageChoice == 2)
            {
                hotelCost = 10000.00;
                cout <<"\n You have successfully booked Premium pack at FrostBay " << endl;
                cout << "Goto menu and take the receipt "<< endl;
            }
            else if (packageChoice == 3)
            {
                hotelCost = 15000.00;
                cout <<"\n You have successfully booked Luxury pack at FrostBay " << endl;
                cout << "Goto menu and take the receipt "<< endl;
            }
            else
            {
                cout << "Invalid Input ! Recirecting to Previous Menu  \n Please Wait !" <<endl;
                usleep(1100);
                system("CLS");
                hotels();
            }
            int gotomenu;

            cout <<"\n Press 1 to redirect main menu : " ;
            cin >> gotomenu;

            if (gotomenu == 1)
            {
                menu();
            }
            else
            {
                menu();
            }
        }
    }
};
float Booking:: hotelCost;

class Charges : public Booking, Cabs, Customers
{
public:
    void printBill()
    {
        ofstream outf("receipt.txt");
        {
            outf << "----------XYZ Travel Agency----------" << endl;
            outf << "----------------Receipt--------------" << endl;
            outf << "_____________________________________" << endl;
            outf << "\n";
            outf << "CustomerID : " << Customers::cusID << endl;
            outf << "Description \t\t Totals" << endl;
            outf << "Hotel Cost \t\t " << fixed << setprecision(2) << Booking::hotelCost << endl;
            outf << "Travel [cab] cost : \t " << fixed << setprecision(2) << Cabs::lastCabCost << endl;
            outf << "_____________________________________" << endl;
            outf << "Total Charge : \t\t " << fixed << setprecision(2) << Booking::hotelCost + Cabs::lastCabCost << endl;
            outf << "_____________________________________" << endl;
            outf << "-------------Thank You---------------" << endl;

        }

        outf.close();

    }
    void showBill()
    {
        ifstream inf("receipt.txt");
        {
            if (!inf)
            {
                cout << "File Opening error !" << endl;
            }
            while (!(inf.eof()))
            {
                inf.getline(all, 999);
                cout << all << endl;
            }
        }
        inf.close();
    }


};


// Inheritance concept

void menu()
{
    int mainChoice;
    int inchoice;
    int gotoMenu;


    cout << "\t\t           XYZ travels         \n" << endl;
    cout << "\t _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ " << endl;
    cout << "\t|\t\t\t\t\t|" << endl;
    cout << "\t|\tCustomer Management -> 1\t|" << endl;
    cout << "\t|\tCabs Management     -> 2\t|" << endl;
    cout << "\t|\tBookings Management -> 3\t|" << endl;
    cout << "\t|\tCharges & Bill      -> 4\t|" << endl;
    cout << "\t|\tExit                -> 5\t|" << endl;
    cout << "\t|\t\t\t\t\t|" << endl;
    cout << "\t|_ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _|" << endl;

    cout << "\n\t Enter your Choice: ";
    cin >> mainChoice;

    system("CLS");

    Customers a2;
    Cabs a3;
    Booking a4;
    Charges a5;

    if (mainChoice == 1)
    {
        cout << "-----------Customers-----------" << endl;
        cout << "1). Enter the New Customers " << endl;
        cout << "2). See old customers " << endl;

        cout << "\n Enter Choice" << " ";
        cin >> inchoice;

        system("CLS");
        if (inchoice == 1)
        {
            a2.detDetails();
        }
        else if (inchoice == 2)
        {
            a2.showDetails();
        }
        else
        {
            cout << "\n Invalid Input ! Redirecting to previous Menu \n Please wait ! " << endl;
            usleep(1100);
            system("CLS");
            menu();
        }
        cout<< "\n Press 1 to redirect to main menu: " ;
        cin >> gotoMenu;
        system("CLS");

        if (gotoMenu == 1)
        {
            menu();
        }
        else
        {
            menu();
        }

    }
    else if (mainChoice == 2)
    {
        a3.cabDetails();
    }
    else if (mainChoice == 3)
    {
        cout << "-----> Book a luxury hotel using the system <-----" <<endl;
        a4.hotels();
    }
    else if (mainChoice == 4)
    {
        cout << "-----> Get Your receipt <-----" << endl;
        a5.printBill();
        cout << "Your recepit is already printed you can get it from file path \n " << endl;
        cout << "to display your receipt in the screen, \n Press 1 of press any other key to go back the main menu : " << endl;

        cin >> gotoMenu;

        if (gotoMenu == 1)
        {
            system("CLS");
            a5.showBill();
            cout << "\n Press 1 to redirect main menu ";
            cin >> gotoMenu;
            system("CLS");

            if (gotoMenu == 1)
            {
                menu();
            }
            else
            {
                menu();
            }
        }
        else
        {
            system("CLS");
            menu();
        }
    }
    else if (mainChoice == 5)
    {
        cout << "---> Good Bye <---" << endl;
        usleep(999);
        system("CLS");
        menu();
    }
    else
    {
        cout <<"Invlaid Input ! Redirecting to previous Menu \n Please wait " << endl;
        usleep(999);
        system("CLS");
        menu();
    }
}



int main()
{
    ManageMenu startobj;

    return 0;
}
