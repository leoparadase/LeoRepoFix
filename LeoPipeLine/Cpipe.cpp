#pragma once
#include "Cpipe.h"
#include "Ccheck.h"

int Cpipe::max_id = 0;
 
bool Cpipe::checkCondition(const Cpipe& Cpipe, bool condition)
{
    return Cpipe.s == condition;
}

bool Cpipe::checkDiameter(const Cpipe& Cpipe, int diameter)
{
    return diameter == Cpipe.d;
}

void Cpipe::edit()
{
    std::cout << "Enter status for pipe " << GetID() << ": 0 - in use, 1 - repairing" << std::endl;
    this -> s = getBool();
    std::cout << "Changed." << std::endl << std::endl;
}

int Cpipe::GetMaxID()
{
    return max_id;
}

int Cpipe::GetID()
{
    return id;
}

StreamTable& operator << (StreamTable& out, const Cpipe& Cpipe)
{
    out
        << Cpipe.id
        << Cpipe.l
        << Cpipe.d
        << Cpipe.s
        << Cpipe.from_id
        << Cpipe.to_id;
    return out;

}
std::ostream& operator<<(std::ostream& out, const Cpipe& Cpipe)
{
    out << Cpipe.max_id << std::endl
        << Cpipe.id << std::endl
        << Cpipe.l << std::endl
        << Cpipe.d << std::endl
        << Cpipe.s << std::endl
        << Cpipe.from_id << std::endl
        << Cpipe.to_id << std::endl;
    return out;
}

std::istream& operator>>(std::istream& out, Cpipe& Cpipe)
{
    Cpipe.max_id++;
    Cpipe.id = Cpipe.max_id;
    Cpipe.from_id = -1;
    Cpipe.to_id = -1;

    std::cout << "Ready to read pipeline properties." << std::endl;

    std::cout << "Diameter: ";
    Cpipe.d = getInt(500, 3000);

    std::cout << "Length: ";
    Cpipe.l = getFloat();

    std::cout << "Is repairing? ";
    Cpipe.s = getBool();

    std::cout << std::endl << "Pipeline added." << std::endl << std::endl;

    return out;
}


std::ofstream& operator<<(std::ofstream& out, const Cpipe& Cpipe)
{
    out << Cpipe.max_id << std::endl
        << Cpipe.id << std::endl
        << Cpipe.l << std::endl
        << Cpipe.d << std::endl
        << Cpipe.s << std::endl
        << Cpipe.from_id << std::endl
        << Cpipe.to_id << std::endl;
    return out;
}

std::ifstream& operator>>(std::ifstream& out, Cpipe& Cpipe)
{
    std::string value;
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
    getline(out, value);
    Cpipe.from_id = stoi(value);
    getline(out, value);
    Cpipe.to_id = stoi(value);
    return out;
}