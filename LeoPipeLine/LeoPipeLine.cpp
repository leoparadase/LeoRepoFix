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

int isInt() // int? more than 0?
{
    while (1)
    {
        int number;
        cin >> number;

        if (cin.fail() || number < 0)
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

float isFloat() //float? more than 0?
{
    while (1)
    {
        float number;
        cin >> number;

        if (cin.fail() || number < 0)
        {
            cin.clear();
            cin.ignore(32767, '\n');
            cout << "Incorrect. Enter the float number more than 0: ";
        }
        else
        {
            return number;
        }
    }
}

int isEffect() // int? 0<=x<=100?
{
    while (1)
    {
        int number;
        cin >> number;

        if (cin.fail() || (number < 0 & number > 100))
        {
            cin.clear();
            cin.ignore(32767, '\n');
            cout << "Incorrect. Enter the integer number between 0 and 100: ";
        }
        else
        {
            return number;
        }
    }
}

string isString() //is string?
{
    while (1)
    {
        string str;
        cin >> str;

        if (cin.fail())
        {
            cin.clear();
            cin.ignore(32767, '\n');
            cout << "Incorrect. Enter the string: ";
        }
        else
        {
            return str;
        }
    }
}

bool isBool() // bool?
{
    while (1)
    {
        bool condition;
        cin >> condition;

        if (cin.fail())
        {
            cin.clear();
            cin.ignore(32767, '\n');
            cout << "Incorrect. Enter True or False";
        }
        else
        {
            return condition;
        }
    }
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
    p.d = isInt();

    cout << "Lentgh: ";
    p.l = isFloat();

    cout << "Is repair? ";
    p.Repair = isBool();

    cout << endl;

    return p;
}

Station Create_station()
{
    Station st = {};

    cout << endl << "Hey! Ready to read station properties." << endl;

    cout << "Name: ";
    st.station_name = isString();

    cout << "Shops: ";
    st.shops = isInt();

    cout << "Working shops: ";
    
        while (1)
        {
            st.working_shops = isInt();
            if (st.working_shops > st.shops)
            {
                cout << "Number of working shops can't be more than number of all shops. Enter again: ";
                st.working_shops = 0;
            }
            else
            {
                break;
            }
        }

    cout << "Effectiveness: ";
    st.effect = isEffect();

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
