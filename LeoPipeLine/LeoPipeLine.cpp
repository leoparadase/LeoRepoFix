#include <iostream>
using namespace std;

struct Pipe
{
    int id;
    int d;
    float l;
    bool Repair;
};

struct Station
{
    int id;
    string station_name
    int deps;
    int workiing_deps;
    int effect;
};

void PipeOutput(Pipe& pipe)
{
    cout << endl;
    cout << "ID of Pipeline: " << pipe.id << endl;
    cout << "Diameter: " << pipe.d << endl;
    cout << "Length: " << pipe.l << endl;
    cout << "Is Repair? : " << pipe.Repair << endl;
}

void StationOutput(Station& s)
{
    cout << endl;
    cout << "ID of Station: " << pipe1.id << endl;
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

Station Create_station()
{

}

int main()
{
    Pipe pipe = Create_pipe();
    PipeOutput(pipe);


}
