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
    string station_name;
    int shops;
    int working_shops;
    int effect;
};

void PipeOutput(Pipe& pipe)
{
    cout << endl;
    cout << "Entered pipeline properties: " << endl;

    cout << "ID of Pipeline: " << pipe.id << endl;
    cout << "Diameter: " << pipe.d << endl;
    cout << "Length: " << pipe.l << endl;
    cout << "Is Repair? : " << pipe.Repair << endl;
}

void StationOutput(Station& s)
{
    cout << endl;
    cout << "Entered station properties: " << endl;

    cout << "ID: " << s.id << endl;
    cout << "Name: " << s.station_name << endl;
    cout << "Shops: " << s.shops << endl;
    cout << "Working shops: " << s.working_shops << endl;
    cout << "Effectiveness: " << s.effect << endl;
}

Pipe Create_pipe()
{
    Pipe p = {};

    cout << "Hey! Ready to read pipeline properties." << endl;

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
    Station st = {};

    cout << endl << "Hey! Ready to read station properties." << endl;

    cout << "Name: ";
    cin >> st.station_name;

    cout << "Shops: ";
    cin >> st.shops;

    cout << "Working shops: ";
    cin >> st.working_shops;

    cout << "Effectiveness: ";
    cin >> st.effect;

    return st;
}

int main()
{
    while (1)
    {
        int a = 0;
        
        cout << "Hi! Choose the action:" << endl << endl;

        cout << "1. Add a pipeline" << endl;
        cout << "2. Add a station" << endl;
        cout << "3. See all" << endl;
        cout << "4. Modify the pipeline" << endl;
        cout << "5. Modify the station" << endl;
        cout << "6. Save to file" << endl;
        cout << "7. Load from file" << endl;
        cout << "8. Quit" << endl;

        cin >> a;

        switch (a)
        {
        case 1:

            break;
        case 2:

            break;
        case 3:

            break;
        case 4:

            break;
        case 5:

            break;
        case 6:

            break;
        case 7:

            break;
        case 8:

            break;
        }

    }
    
    Pipe pipe = Create_pipe();
    PipeOutput(pipe);

    Station station = Create_station();
    StationOutput(station);
}
