#pragma once
#include "Ccheck.h"

int getInt(int min, int max)
{
    while (1)
    {
        int number;
        std::cin >> number;

        if (std::cin.fail() || number < min || number > max || std::cin.peek() != '\n')
        {
            std::cin.clear();
            std::cin.ignore(32767, '\n');
            std::cout << "Incorrect. Try again: ";
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
        std::cin >> number;

        if (std::cin.fail() || number < min || number > max || std::cin.peek() != '\n')
        {
            std::cin.clear();
            std::cin.ignore(32767, '\n');
            std::cout << "Incorrect. Try again: ";
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
        std::cin >> condition;

        if (std::cin.fail() || std::cin.peek() != '\n')
        {
            std::cin.clear();
            std::cin.ignore(32767, '\n');
            std::cout << "Incorrect. Try again: ";
        }
        else
        {
            return condition;
        }
    }
}

std::string getFileName()
{
    std::string fileName;
    std::string incorrectSymbols[16] = { " ","~","#","%","&","*","{","}","/",":","<",">","?","+","|","." };
    while (true) {
            std::cout << "Enter filename: ";
            std::cin >> fileName;
            // getline(cin, fileName);
            std::cout << std::endl << std::endl;
            std::cerr << fileName;
            for (std::string i : incorrectSymbols) {
                while (fileName.find(i) != std::string::npos) {
                    fileName.erase(fileName.find(i), 1);
                }
            }
            if (fileName == "") continue;
            std::cout << std::endl;
            return fileName;
    }
}

std::string getString()
{
    while (1)
    {
        std::cin >> std::ws;
        std::string str;
        std::getline(std::cin, str);

        return str;
    }
}

