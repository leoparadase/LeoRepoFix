#pragma once
#include "Cpipe.h"
#include "Ccheck.h"

using namespace std;

int Cpipe::max_id = 0;

Cpipe::Cpipe()
{
   
}

Cpipe::~Cpipe()
{
}

bool Cpipe::checkCondition(const Cpipe& Cpipe, bool condition)
{
    return Cpipe.s == condition;
}

bool Cpipe::checkDiameter(const Cpipe& Cpipe, int diameter)
{
    return diameter == Cpipe.d;
}

void Cpipe::create()
{
    SetMaxID();
    SetID();

    cout << "Ready to read pipeline properties." << endl;

    cout << "Diameter: ";
    this->d = getInt(500, 3000);

    cout << "Length: ";
    this->l = getFloat();

    cout << "Is repairing? ";
    this->s = getBool();

    cout << endl << "Pipeline added." << endl << endl;
}

void Cpipe::edit()
{
    cout << "Enter status for pipe " << GetID() << ": 0 - in use, 1 - repairing" << endl;
    this -> s = getBool();
    cout << "Changed." << endl << endl;
}

void Cpipe::SetID()
{
    this -> id = GetMaxID();
}

void Cpipe::SetMaxID()
{
    max_id++;
}

int Cpipe::GetMaxID()
{
    return max_id;
}

void Cpipe::UpdateMaxID(int num)
{
    this->max_id = num;
}

int Cpipe::GetID()
{
    return id;
}

void Cpipe::UpdateID(int num)
{
    this->id = num;
}

std::ostream& operator<<(std::ostream& out, const Cpipe& Cpipe)
{
    out << Cpipe.max_id << endl
        << Cpipe.id << endl
        << Cpipe.l << endl
        << Cpipe.d << endl
        << Cpipe.s << endl;
    return out;
}

std::istream& operator>>(std::istream& out, Cpipe& Cpipe)
{
    string value;
    getline(out, value);
    Cpipe.max_id = stoi(value);
    getline(out, value);
    Cpipe.id = stoi(value);
    getline(out, value);
    Cpipe.l = stof(value);
    getline(out, value);
    Cpipe.d = stoi(value);
    getline(out, value);
    Cpipe.s = stoi(value);
    return out;
}
