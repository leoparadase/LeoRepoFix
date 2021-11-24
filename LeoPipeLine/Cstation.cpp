#pragma once
#include "Cstation.h"
#include "Ccheck.h"

using namespace std;

int Cstation::max_id = 0;

Cstation::Cstation()
{
    
}

Cstation::~Cstation()
{
}

bool Cstation::checkName(const Cstation& Cstation, std::string name)
{
    return Cstation.n.find(name) != string::npos;
}

bool Cstation::checkPercent(const Cstation& Cstation, int percent)
{
    return round(((float)(Cstation.s - Cstation.w_s) / Cstation.s) * 100) >= percent;
}

void Cstation::create()
{
    SetMaxID();
    SetID();

    cout << endl << "Ready to read station properties." << endl;

    cout << "Name: ";
    this->n = getString();

    cout << "Shops: ";
    this->s = getInt();

    cout << "Working shops: ";
    this->w_s = getInt(0, this->s);

    cout << "Effectiveness: ";
    this->e = getInt(0, 100);

    cout << endl << "Station added." << endl << endl;
}

void Cstation::edit()
{
    cout << "Edit station No. " << GetID() << " (" << this->n << ") " << endl;
    do {
        cout << "Enter number of working shops: ";
        this -> w_s = getInt();
    } while (this -> w_s > this -> s);

    cout << "Enter efficienty: ";
    this -> e = getInt();
    cout << "Changed." << endl;
}

void Cstation::SetID()
{
    this -> id = GetMaxID();
}

int Cstation::GetID()
{
    return id;
}

void Cstation::SetMaxID()
{
    max_id++;
}

int Cstation::GetMaxID()
{
    return max_id;
}

ostream& operator<<(ostream& out, const Cstation& Cstation)
{
    out << Cstation.max_id << endl
        << Cstation.id << endl
        << Cstation.n << endl
        << Cstation.s << endl
        << Cstation.w_s << endl
        << Cstation.e << endl;
    return out;
}

istream& operator>>(istream& out, Cstation& Cstation)
{
    string value;
    getline(out, value);
    Cstation.max_id = stoi(value);
    getline(out, value);
    Cstation.id = stoi(value);
    getline(out, value);
    Cstation.n = value;
    getline(out, value);
    Cstation.s = stoi(value);
    getline(out, value);
    Cstation.w_s = stoi(value);
    getline(out, value);
    Cstation.e = stoi(value);
    return out;
}
