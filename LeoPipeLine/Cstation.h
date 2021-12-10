#pragma once
#include <iostream>
#include <fstream>
#include <unordered_map>
#include <string>
#include "StreamTable.h"

class Cstation
{
private:
    int id;
    static int max_id;
public:
    std::string n;
    int s;
    int w_s;
    int e;

    friend StreamTable& operator << (StreamTable& out, const Cstation& Cstation);
    friend std::ostream& operator << (std::ostream& out, const Cstation& Cstation);
    friend std::istream& operator >> (std::istream& out, Cstation& Cstation);
    friend std::ofstream& operator << (std::ofstream& out, const Cstation& Cstation);
    friend std::ifstream& operator >> (std::ifstream& out, Cstation& Cstation);

    static bool checkName(const Cstation& Cstation, std::string name);
    static bool checkPercent(const Cstation& Cstation, float percent);

    void create();
    void edit();

    int GetID();
    int GetMaxID();
};

