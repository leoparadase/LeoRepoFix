#include <iostream>
using namespace std;

struct Pipe
{
    int id;
    int d;
    float l;
    bool Repair;
};

void PipeOutput(Pipe& pipe1)
{
    cout << endl;
    cout << "ID of Pipeline: " << pipe1.id << endl;
    cout << "Diameter: " << pipe1.d << endl;
    cout << "Length: " << pipe1.l << endl;
    cout << "Is Repair? : " << pipe1.Repair << endl;
}

Pipe Create_pipe()
{
    Pipe p = {};

    cout << "Diameter: ";
    cin >> p.d;

    cout << "Lentgh: ";
    cin >> p.l;

    cout << "Is repair? ";
    cin >> p.Repair;

    return p;
}

int main()
{
    Pipe pipe = Create_pipe();
    PipeOutput(pipe);
}
