#pragma once
#include <iostream>
#include <unordered_map>

using namespace std;

class Cpipe
{
private:
    int id;
    static int max_id;

public:
    int d;
    float l;
    bool s;

    Cpipe();
    ~Cpipe();

    friend std::ostream& operator << (std::ostream& out, const Cpipe& Cpipe);
    friend std::istream& operator >> (std::istream& out, Cpipe& Cpipe);

    static bool checkCondition(const Cpipe& Cpipe, bool condition);
    static bool checkDiameter(const Cpipe& Cpipe, int diameter);

    void edit();

    void SetID();
    int GetID();
    void UpdateID(int num);
    void SetMaxID();
    int GetMaxID();
    void UpdateMaxID(int num);
};
