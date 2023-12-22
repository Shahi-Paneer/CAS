#include <iostream>
#include <bits/stdc++.h>
#include <sstream>
#include <string>
#include <cctype>

using namespace std;

void removeSpaces(string &s);

void splitEquation(string &s);

int sumSide(string side);

int main()
{

    string eq = "x + 2 = x -7 -1";
    removeSpaces(eq);

    cout << eq;

    string LHS = "";

    string RHS = "";

    bool x_location;

    bool middle = false;

    for (int i = 0; i < eq.length(); i++)
    {

        if (eq[i] == '=')
        {
            middle = true;
            continue;
        }

        if (middle == false)
        {
            LHS = LHS + eq[i];
            if (eq[i] == 'x')
                x_location = false;
        }
        else
        {
            RHS = RHS + eq[i];
            if (eq[i] == 'x')
                x_location = true;
        }
    }

    cout << endl
         << LHS << endl
         << RHS;

    int LeftSum = sumSide(LHS);
    int RightSum = sumSide(RHS);

    RightSum = RightSum - LeftSum;
    //(x_location ? RHS : LHS) += sum;

    cout << endl << "Solution: X = " << RightSum << endl;
}

int sumSide(string side)
{

    istringstream iss(side);

    char sign;

    char prevChar = '\0';
    int number, sum = 0;

    while (iss >> sign)
    {
        if (isdigit(sign))
        {
             
            iss.putback(sign);
            cout << endl << "lol " << sign << endl;
            if (iss >> number)
            {
                if (prevChar == '-') {
                  number *= -1;
                }
                sum += number;
            }
        }
        prevChar = sign;
    }

    return sum;
};

void removeSpaces(string &s)
{

    int l = s.length(); // storing the length of the string

    int c = count(s.begin(), s.end(),
                  ' '); // counting the number of whitespaces

    remove(s.begin(), s.end(),
           ' '); // removing all the whitespaces

    s.resize(l - c); // resizing the string to l-c
}

void splitEquation(string &s)
{

    int l = s.length();
};
