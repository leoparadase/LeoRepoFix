#pragma once
#include "Ccheck.h"

using namespace std;

int getInt(int min, int max)
{
    while (1)
    {
        int number;
        cin >> number;

        if (cin.fail() || number < min || number > max || cin.peek() != '\n')
        {
            cin.clear();
            cin.ignore(32767, '\n');
            cout << "Incorrect. Try again: ";
        }
        else
        {
            return number;
        }
    }
}

float getFloat(float min, float max)
{
    while (1)
    {
        float number;
        cin >> number;

        if (cin.fail() || number < min || number > max || cin.peek() != '\n')
        {
            cin.clear();
            cin.ignore(32767, '\n');
            cout << "Incorrect. Try again: ";
        }
        else
        {
            return number;
        }
    }
}

bool getBool()
{
    while (1)
    {
        bool condition;
        cin >> condition;

        if (cin.fail() || cin.peek() != '\n')
        {
            cin.clear();
            cin.ignore(32767, '\n');
            cout << "Incorrect. Try again: ";
        }
        else
        {
            return condition;
        }
    }
}

string getFileName()
{
    string fileName;
    string incorrectSymbols[16] = { " ","~","#","%","&","*","{","}","/",":","<",">","?","+","|","." };
    while (true) {
            cout << "Enter filename: ";
            cin >> fileName;
            // getline(cin, fileName);
            cout << endl << endl;
            cerr << fileName;
            for (string i : incorrectSymbols) {
                while (fileName.find(i) != string::npos) {
                    fileName.erase(fileName.find(i), 1);
                }
            }
            if (fileName == "") continue;
            cout << endl;
            return fileName;
    }
}

string getString()
{
    while (1)
    {
        cin >> ws;
        string str;
        getline(cin, str);

        return str;
    }
}

