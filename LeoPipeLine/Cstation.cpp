#pragma once
#include "Cstation.h"
#include "Ccheck.h"

int Cstation::max_id = 0;

bool Cstation::checkName(const Cstation& Cstation, std::string name)
{
    return Cstation.n.find(name) != std::string::npos;
}

bool Cstation::checkPercent(const Cstation& Cstation, float percent)
{
    return round(((float)(Cstation.s - Cstation.w_s) / Cstation.s) * 100) >= percent;
}

void Cstation::create()
{
   
}

void Cstation::edit()
{
    std::cout << "Edit station No. " << GetID() << " (" << this->n << ") " << std::endl;
    do {
        std::cout << "Enter number of working shops: ";
        this -> w_s = getInt();
    } while (this -> w_s > this -> s);

    std::cout << "Enter efficienty: ";
    this -> e = getInt();
    std::cout << "Changed." << std::endl;
}

int Cstation::GetID()
{
    return id;
}

int Cstation::GetMaxID()
{
    return max_id;
}

StreamTable& operator << (StreamTable& out, const Cstation& Cstation)
{
    out 
        << Cstation.id
        << Cstation.n
        << Cstation.s
        << Cstation.w_s
        << Cstation.e;
    return out;
}

std::ostream& operator<<(std::ostream& out, const Cstation& Cstation)
{
    out << Cstation.max_id << std::endl
        << Cstation.id << std::endl
        << Cstation.n << std::endl
        << Cstation.s << std::endl
        << Cstation.w_s << std::endl
        << Cstation.e << std::endl;
    return out;
}

std::istream& operator>>(std::istream& out, Cstation& Cstation)
{
    Cstation.max_id++;
    Cstation.id = Cstation.max_id;

    std::cout << std::endl << "Ready to read station properties." << std::endl;

    std::cout << "Name: ";
    Cstation.n = getString();

    std::cout << "Shops: ";
    Cstation.s = getInt();

    std::cout << "Working shops: ";
    Cstation.w_s = getInt(0, Cstation.s);

    std::cout << "Effectiveness: ";
    Cstation.e = getInt(0, 100);

    std::cout << std::endl << "Station added." << std::endl << std::endl;

    return out;
}

std::ofstream& operator<<(std::ofstream& out, const Cstation& Cstation)
{
    out << Cstation.max_id << std::endl
        << Cstation.id << std::endl
        << Cstation.n << std::endl
        << Cstation.s << std::endl
        << Cstation.w_s << std::endl
        << Cstation.e << std::endl;
    return out;
}

std::ifstream& operator>>(std::ifstream& out, Cstation& Cstation)
{
    std::string value;
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
