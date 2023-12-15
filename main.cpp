#include <iostream>
#include <bits/stdc++.h>
#include <sstream>
#include <string>
#include <cctype>

using namespace std;

void removeSpaces(string &s);

void splitEquation(string &s);

int main()
{

    string eq = "x + 2 = 7";
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

    istringstream iss(LHS);

    char sign;
    int number, sum = 0;

    while (iss >> sign) {
        if (isdigit(sign)) {
            iss.putback(sign);
            if (iss >> number) {
                sum += number;
            }
        }
    }

    (x_location ? RHS : LHS) += sum;

    cout << "Sum of the numbers: " << sum << endl;
}

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
