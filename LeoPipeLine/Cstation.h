#pragma once
#include <iostream>
#include <unordered_map>
#include <string>

using namespace std;

class Cstation
{
private:
    int id;
    static int max_id;
public:
    string n;
    int s;
    int w_s;
    int e;

    Cstation();
    ~Cstation();

    friend ostream& operator << (ostream& out, const Cstation& Cstation);
    friend istream& operator >> (istream& out, Cstation& Cstation);

    static bool checkName(const Cstation& Cstation, std::string name);
    static bool checkPercent(const Cstation& Cstation, int percent);

    void create();
    void edit();

    void SetID();
    int GetID();
    void SetMaxID();
    int GetMaxID();
};

