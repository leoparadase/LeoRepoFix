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

int isInt()
{
    while (1)
    {
        int number;
        cin >> number;

        if (cin.fail() || number > 0)
        {
            cin.clear();
            cin.ignore(32767, '\n');
            cout << "Incorrect. Enter the integer number more than 0: ";
        }
        else
        {
            return number;
        }

    }
}

float isFloat()
{

}

int isEffect()
{

}

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

    cout << endl;

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

    cout << endl;

    return st;
}

int main()
{
    Pipe pipe = {};
    Station station = {};

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
        cout << "8. Quit" << endl << endl;

        cin >> a;
        cout << endl << endl;

        switch (a)
        {
        case 1:
            pipe = Create_pipe();
            cout << "Pipeline added." << endl << endl;
            break;
        case 2:
            station = Create_station();
            cout << "Station added." << endl << endl;
            break;
        case 3:
            if (pipe.d > 0)
            {
                PipeOutput(pipe);
            }
            else
            {
                cout << "No pipeline in base." << endl << endl;
            };
            
            if (station.shops > 0)
            {
                StationOutput(station);
            }
            else
            {
                cout << "No station in base." << endl << endl;
            };
            break;
        case 4:
            //more switch with prop select
            break;
        case 5:
            //more switch with prop select
            break;
        case 6:
            //fstream
            break;
        case 7:
            //fstream
            break;
        case 8:
            //quit
            break;
        }

    } 
}
