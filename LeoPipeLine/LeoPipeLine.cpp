#include <iostream>
#include <fstream>
#include <string>
#include "LeoPipeLine.h"

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

int GetInt(int min = 0, int max = INT_MAX) 
{
    while (1)
    {
        int number;
        cin >> number;

        if (cin.fail() || number < min || number > max || cin.peek() != '\n')
        {
            cin.clear();
            cin.ignore(32767, '\n');
            cout << "Incorrect. Try again: ";
        }
        else
        {
            return number;
        }
    }
}

float GetFloat(float min = 0, float max = FLT_MAX)
{
    while (1)
    {
        float number;
        cin >> number;

        if (cin.fail() || number < min || number > max || cin.peek() != '\n')
        {
            cin.clear();
            cin.ignore(32767, '\n');
            cout << "Incorrect. Try again: ";
        }
        else
        {
            return number;
        }
    }
}

string GetString() 
{
    while (1)
    {
        cin >> ws;
        string str;
        getline(cin, str);

        return str;
    }
}

bool GetBool() 
{
    while (1)
    {
        bool condition;
        cin >> condition;

        if (cin.fail() || cin.peek() != '\n')
        {
            cin.clear();
            cin.ignore(32767, '\n');
            cout << "Incorrect. Try again: ";
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
    cout << "Is Repair? : " << pipe.Repair << endl << endl;
}

void StationOutput(Station& s)
{
    cout << endl;
    cout << "Entered station properties: " << endl;

    cout << "ID: " << s.id << endl;
    cout << "Name: " << s.station_name << endl;
    cout << "Shops: " << s.shops << endl;
    cout << "Working shops: " << s.working_shops << endl;
    cout << "Effectiveness: " << s.effect << endl << endl;
}

Pipe Create_pipe()
{
    Pipe p = {};
    

    cout << "Ready to read pipeline properties." << endl;

    cout << "Diameter: ";
    p.d = GetInt(500, 3000);

    cout << "Lentgh: ";
    p.l = GetFloat();

    cout << "Is repair? ";
    p.Repair = GetBool();

    cout << endl << "Pipeline added." << endl << endl;

    return p;
}

Station Create_station()
{
    Station st = {};

    cout << endl << "Ready to read station properties." << endl;

    cout << "Name: ";
    st.station_name = GetString();

    cout << "Shops: ";
    st.shops = GetInt();

    cout << "Working shops: ";
    st.working_shops = GetInt(0, st.shops);

    cout << "Effectiveness: ";
    st.effect = GetInt(0,100);

    cout << endl << "Station added." << endl << endl;

    return st;
}

void PrintMenu()
{
    cout << "Choose the action:" << endl << endl;

    cout << "1. Add a pipeline" << endl;
    cout << "2. Add a station" << endl;
    cout << "3. See all" << endl;
    cout << "4. Modify the pipeline" << endl;
    cout << "5. Modify the station" << endl;
    cout << "6. Save to file" << endl;
    cout << "7. Load from file" << endl;
    cout << "0. Quit" << endl << endl;
}

void PrintPipeEdit()
{
    cout << "What to edit?" << endl << endl;

    cout << "1. Diameter" << endl;
    cout << "2. Length" << endl;
    cout << "3. Repair status" << endl;
    cout << "4. Back to Home" << endl;
}

void PrintStationEdit()
{
    cout << "What to edit?" << endl << endl;

    cout << "1. Station name" << endl;
    cout << "2. Shops" << endl;
    cout << "3. Working shops" << endl;
    cout << "4. Effectiveness" << endl;
    cout << "5. Back to Home" << endl;
}

void PipeEdit(int b, Pipe& pipe)
{
    switch (b)
    {
    case 1:
    {
        cout << "New diameter: ";
        pipe.d = GetInt(500, 3000);
        break;
    }
    case 2:
    {
        cout << "New lentgh: ";
        pipe.l = GetFloat();
        break;
    }
    case 3:
    {
        cout << "Is repair? ";
        pipe.Repair = GetBool();
        break;
    }
    case 4:
    {
        break;
    }
    }
}

void StationEdit(int c, Station& station)
{
    switch (c)
    {
    case 1:
    {
        cout << "New station name: ";
        station.station_name = GetInt();
        break;
    }
    case 2:
    {
        cout << "New number of shops: ";
        station.shops = GetInt();
        break;
    }
    case 3:
    {
        cout << "New number of working shops: ";
        station.working_shops = GetInt(0, station.shops);
        break;
    }
    case 4:
    {
        cout << "New effectiveness: ";
        station.effect = GetInt(0, 100);
        break;
    }
    case 5:
    {
        break;
    }
    }
}

void LoadFromFile(Pipe& pipe, Station& station)
{
    ifstream file;
    file.open("data.txt", ios::in);
    if (file.good())
    {
        while (!file.eof())
        {
            string str;
            getline(file, str);
            if (str == "PIPELINE")
            {
                string value;
                getline(file, value);
                pipe.id = stoi(value);
                getline(file, value);
                pipe.l = stof(value);
                getline(file, value);
                pipe.d = stoi(value);
                getline(file, value);
                pipe.Repair = (value == "1");
            }

            if (str == "STATION")
            {
                string value;
                getline(file, value);
                station.id = stoi(value);
                getline(file, value);
                station.station_name = value;
                getline(file, value);
                station.shops = stoi(value);
                getline(file, value);
                station.working_shops = stoi(value);
                getline(file, value);
                station.effect = stoi(value);
            }
        }
        cout << "Loaded." << endl << endl;
    }
    else
    {
        cout << "Can't load from file." << endl << endl;
    }
}

void OutputInFile(Pipe& pipe, Station& station)
{
    ofstream file;
    file.open("data.txt", ios_base::out);

    if (file.good())
    {
        if (pipe.d > 0)
        {
            file << "PIPELINE" << endl
                << pipe.id << endl
                << pipe.l << endl
                << pipe.d << endl
                << pipe.Repair << endl;
        }
        else
        {
            cout << "No pipelane in base.";
        }

        if (station.shops > 0)
        {
            file << "STATION" << endl
                << station.id << endl
                << station.station_name << endl
                << station.shops << endl
                << station.working_shops << endl
                << station.effect << endl;
        }
        else
        {
            cout << "No station in base." << endl << endl;
        }
        file.close();
        cout << "Saved." << endl << endl;
    }
    else
    {
        cout << "Can't save the file." << endl << endl;
    }
}

int main()
{
    Pipe pipe = {};
    Station station = {};

    while (1)
    {
        int a = 0;
        PrintMenu();
        a = GetInt();
        cout << endl;

        switch (a)
        {
        case 1:
        {
            pipe = Create_pipe();
            break;
        }
        case 2:
        {
            station = Create_station();
            break;
        }
        case 3:
        {
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
        }
        case 4: 
            {
            int b = 0;

            if (pipe.d > 0)
            {
                PrintPipeEdit();
                b = GetInt();
                cout << endl;
            
                PipeEdit(b, pipe);
            }
            else
            {
               cout << "No pipeline in base." << endl << endl; 
            }
            break;
            }
        case 5:
            {
            if (station.shops > 0)
            {
                PrintStationEdit();
                int c = GetInt();
                cout << endl;
            
                StationEdit(c, station);
            }
            else
            {
               cout << "No station in base." << endl << endl; 
            }
            break;
            }
        case 6:
           {
            OutputInFile(pipe, station);
            break;
           }
        case 7:
        {
            LoadFromFile(pipe, station);
            break;
        }
        case 0:
        {
            return 0;
            break;
        }
        default:
        {
            cout << "Incorrect. Try again." << endl << endl;
            break;
        }
        }

    } 
}
      