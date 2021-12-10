#pragma once
#include <iostream>
#include <fstream>
#include <unordered_map>
#include "StreamTable.h"

class Cpipe
{
private:
    int id;
    static int max_id;

public:
    int d;
    float l;
    bool s;
    int from_id;
    int to_id;

    friend StreamTable& operator << (StreamTable& out, const Cpipe& Cpipe);
    friend std::ostream& operator << (std::ostream& out, const Cpipe& Cpipe);
    friend std::istream& operator >> (std::istream& out, Cpipe& Cpipe);
    friend std::ofstream& operator << (std::ofstream& out, const Cpipe& Cpipe);
    friend std::ifstream& operator >> (std::ifstream& out, Cpipe& Cpipe);

    static bool checkCondition(const Cpipe& Cpipe, bool condition);
    static bool checkDiameter(const Cpipe& Cpipe, int diameter);

    void edit();

    int GetID();
    int GetMaxID();
};
