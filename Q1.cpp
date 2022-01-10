// Fauzan Lodhi
// October 5, 2020
// TD Bank Transaction Log Program

//---------------------

// This program is designed for the user to manage their chequing account and log each transaction for the month
// This program penalizes the user for irresponsibly managing their account, such as letting their account balance fall below $50

//---------------------

#include "Q1.h"
#include <bits/stdc++.h>
using namespace std;

//-------------------
double welcome();       //declare two functions
double thanks();        // one for a welcome message, one for an exist message
//-------------------

Q1::Q1()
{
    system("color A7");     // change background colour to white with black text to make it easier to read
    char y='y', t;          // two char variables; y for the do while loop; t for the transaction (d or w)
    double bal, transaction, newbal;    // three double variables; one for current balance, one for the transaction amount, one for the new balance
    welcome();                      // call upon welcome function
    cout << "\nEnter your current balance: $";      // prompts user to input their current balance
    cin >> bal;     // double variable bal for current balance
    newbal=bal+transaction;  // give newbal a value of balance+transaction;

//-----------------------------------

    do
    {
        cout << "--------------------------------------------" << endl;
        cout << "\nWould you like to deposit or withdraw? (d/w): ";
        cin >> t;                   // prompt user to enter whether they would like to make a deposit or withdrawal

        if (t=='d')     // if transaction is deposit
        {
            system("color FA");     // change text colour to green if depositing
            cout << "How much money would you like to desposit?: $";
            cin >> transaction;         // enter amount to deposit
            newbal = newbal+transaction;        // new balance = new balance + deposit
            cout << "\nTransaction accepted." << endl;
        }

        //----

        else if (t=='w')        // if transaction is withdrawal
        {
            system("color F4");     // change text colour to red if withdrawing
            cout << "How much money would you like to withdraw?: $";
            cin >> transaction;     // enter amount to withdraw
            newbal = newbal-transaction;        // new balance = new balance - deposit
            cout << "\nTransaction accepted." << endl;
        }

        //----

        else        // if transaction input is neither d or w
        {
            cout << "\nError! Invalid. Please enter d for deposit OR w for withdraw" << endl;
        }


    //------------------------------------------------------------------------------------

        if (newbal>=1000)       // if the balance after transaction is greater than or equal to $1000
        {
            cout << "\nNot bad! Let's keep it above $1000" << endl;     // tell the user that they are doing a good job if the balance is above 1000
            cout << "\nYour balance is: $" << fixed << showpoint << setprecision(2) << newbal << endl;  // display new balance after transaction
        }

        //----

        else if (newbal<1000 && newbal>50)     // if the balance after the transaction is in between $50 and $1000
        {
            cout << "\nOops! You will now be charged a single $20 fee!" << endl;
            newbal = newbal-20;         // charge user $20 if their new balance is in between $50 and $2000
            cout << "\nYour balance is: $" << fixed << showpoint << setprecision(2) << newbal << endl; // display new balance after transaction
        }

        //----

        else if (newbal>=0 && newbal<=50)        // if the balance after the transaction is in between $0 and $50
        {
            cout << "\n*****WARNING!***** \nYour balance is dangerously low!" << endl;      // alert user if balance is in between $0 and $50
            cout << "\nYour balance is: $" << fixed << showpoint << setprecision(2) << newbal << endl;  // display new balance after transaction
        }

        //----

        else if (newbal<0 && t=='w')        // if the balance after the transaction is negative and the user makes a withdrawal
        {
            newbal=newbal-25;    // penalize user if they make withdrawal despite already having a negative balance
            cout << "\n*****URGENT WARNING!***** \nA negative balance! You will be charged a $25 fee for each withdrawal until the balance is no longer negative." << endl;        // warn user of negative balance
            cout << "\nYour balance is: $" << fixed << showpoint << setprecision(2) << newbal << endl;  // display new balance after transaction
        }

        //----

        else if (newbal<0 && t=='d')        // if the balance after the transaction is negative and the user makes a deposit
        {
            cout << "\n*****WARNING!***** \nA negative balance!" << endl;
            cout << "\nYour balance is: $" << fixed << showpoint << setprecision(2) << newbal << endl;  // display new balance after transaction
        }

        //------------------------------------------------------------------------------------

        cout << "\nTo continue, press y. To quit, enter any other key: ";   // prompt user to enter if they would like to continue or not
        cin >> y;       // character variable y
        system("color F0");     // reset text colour to black

    }while(y=='y');     // do while loop using character variable y

    thanks();       // call on "thanks" function
    cout << "Your final balance is: $" << fixed << showpoint << setprecision(2) << newbal << endl;  // display the final balance after completing the program
    cout << "Current session has expired." << endl;
    cout << "TD BANK Transaction Log Program complete." << endl;
}

//------------------------------------------------------------------------------------

double welcome()        // welcome message function
{
    string name;
    cout << "Welcome to the TD BANK Transaction Log Program to help you manage your chequing account!" << endl;  // introduce program to user
    cout << "Enter your name: "; // prompt user to enter name
    getline(cin, name);     // use getline function to accept spaces to allow for full name
    cout << "-----------------" << endl;        // dash line to make it easier to read
    cout << name << ", here are some things to keep in mind:" << endl;
    cout << "-----------------" << endl;
    cout << "\n1. If your balance falls below $1000 you will be charged a $20 fee!" << endl;        // rule 1
    cout << "\n2. If your balance falls below $50 you will recieve a warning!" << endl;     // rule 2
    cout << "\n3. If your balance falls below $0 you will be chargeed a $25 fee for every withdrawal made until balance is above $0!" << endl;  // rule 3
    cout << "\nReady to begin?" << endl;
    system("PAUSE");        // wait for user to enter any key before proceeding, to make sure the user has enough time to read the rules before beginning
    system("CLS");      // clear screen so that the welcome message and rules are no longer visible
    cout << "|TD TRANSACTION LOG\tCurrent session for: " << name << "'s chequing account|" << endl;    // display the program name and the user name at the top of the screen
}

//------------------------------------------------------------------------------------

double thanks()     // thank you message function
{
    cout << "\n-----------------" << endl;
    cout << "Thank you for using this program! Be responsible with your chequing account!" << endl;     // thank user for using program
    system ("PAUSE");       // wait for user to enter any key
    system ("CLS");     // clear screen
}



