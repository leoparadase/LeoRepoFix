#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <vector>
#include <unordered_map>
#include "LeoPipeLine.h"
#include "StreamTable.h"

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

    cout << "Length: ";
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

    cout << "1. Show pipelines" << endl
        << "2. Show stations" << endl
        << "3. Search pipelines" << endl
        << "4. Search stations" << endl
        << "5. Save to file" << endl
        << "6. Load from file" << endl
        << "0. Quit" << endl << endl;
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

    //vector <Pipe> Pipes;
    //vector <Station> Stations;
    vector <Pipe> vec_picked_p;
    vector <Station> vec_picked_s;
    vector <int> vec_picked_ids;

    unordered_map <int, Pipe> Pipes = {};
    unordered_map <int, Station> Stations = {};

    unordered_map <int, Pipe> ::iterator it_pipe = Pipes.begin();
    unordered_map <int, Station> ::iterator it_station = Stations.begin();

    StreamTable table(cout);

    int id;
    int p_id_count = 0;
    int s_id_count = 0;
    string str;

    while (1)
    {
        int a = 0;

        PrintMenu();
        a = GetInt(0, 8);
        cout << endl;

        switch (a)
        {
        case 1: // show pipelines.
        {
            if (!Pipes.empty())
            {
                // !!! put in function with giving vector
                table.Clear();
                table.SetCols(4, 12);

                table.MakeBorderExt(true);
                table.SetDelimRow(true, '-');
                table.SetDelimCol(true, '|');

                cout << "Pipelines:" << endl << endl;

                table << "ID" << "Diameter" << "Length" << "Repairing?";

                it_pipe = Pipes.begin();

                for (int i = 0; it_pipe != Pipes.end(); it_pipe++) {
                    table << it_pipe->second.id << it_pipe->second.d << it_pipe->second.l << it_pipe->second.Repair;
                }

                cout << endl << endl;

                cout << "What to do?" << endl
                    << "1. Add exciting pipeline" << endl
                    << "2. Modify" << endl
                    << "3. Delete" << endl
                    << "0. Back to home" << endl << endl;

                a = GetInt(0, 3);
                cout << endl;

                switch (a)
                {
                case 1: // add
                {
                    pipe = Create_pipe();
                    p_id_count++;
                    pipe.id = p_id_count;
                    Pipes.insert({ p_id_count, pipe });
                    break;
                }
                case 2: // modify
                {

                    cout << "Enter IDs of pipelines. One by one, after each ID press ENTER:" << endl;
                    id = GetInt();
                    while (id != NULL)
                    {
                        vec_picked_ids.push_back(id);
                        cout << "Added. Enter one more or type 0 to modify" << endl; // check what the output when press ENTER
                        id = GetInt();
                    }
                    if (!vec_picked_ids.empty())
                    {
                        cout << "What repairing status you want to set?" << endl
                            << "1. All in repair" << endl
                            << "2. All in use" << endl
                            << "0. Back to home" << endl << endl;

                        a = GetInt(0, 2);
                        cout << endl;

                        switch (a)
                        {
                        case 1:
                        {
                            it_pipe = Pipes.begin();

                            for (int i = 0; i < vec_picked_ids.size(); i++) {
                                for (int j = 0; it_pipe != Pipes.end(); it_pipe++) {
                                    if (it_pipe->first == vec_picked_ids[i])
                                    {
                                        Pipes[it_pipe->first].Repair = 1;
                                    }
                                }
                            }
                            vec_picked_ids.clear();
                            break;
                        }
                        case 2:
                        {
                            it_pipe = Pipes.begin();

                            for (int i = 0; i < vec_picked_ids.size(); i++) {
                                for (int j = 0; it_pipe != Pipes.end(); it_pipe++) {
                                    if (it_pipe->first == vec_picked_ids[i])
                                    {
                                        Pipes[it_pipe->first].Repair = 0;
                                    }
                                }
                            }
                            vec_picked_ids.clear();
                            break;
                        }
                        case 0:
                        {
                            break;
                        }
                        }
                    }
                    else
                    {
                        cout << "Nothing entered. Return to home..." << endl << endl;
                    }
                    break;
                }
                case 3:
                {
                    cout << "Enter IDs of pipelines. One by one, after each ID press ENTER:" << endl;
                    id = GetInt();
                    while (id != NULL)
                    {
                        vec_picked_ids.push_back(id);
                        cout << "Added. Enter one more or type 0 to modify" << endl; // check what the output when press ENTER
                        id = GetInt();
                    }
                    if (!vec_picked_ids.empty())
                    {
                        cout << "Are you sure to delete?" << endl
                            << "1. Yes" << endl
                            << "2. No" << endl << endl;

                        a = GetInt(1, 2);
                        cout << endl;

                        switch (a)
                        {
                        case 1:
                        {
                            it_pipe = Pipes.begin();

                            for (int i = 0; i < vec_picked_ids.size(); i++) {
                                it_pipe = Pipes.find(vec_picked_ids[i]);
                                Pipes.erase(it_pipe);
                            }
                            vec_picked_ids.clear();
                            break;
                        }
                        case 2:
                        {
                            cout << "OK, returning to home..." << endl << endl;
                            break;
                        }
                        }
                    }
                    else
                    {
                        cout << "Nothing entered. Returning to home..." << endl << endl;
                    }
                }
                }
            }
            else
            {
                cout << "No pipelines. Want to add?" << endl
                    << "1. Yes" << endl
                    << "2. No" << endl << endl;

                a = GetInt(1, 2);
                cout << endl << endl;

                switch (a)
                {
                case 1:
                {
                    pipe = Create_pipe();
                    p_id_count++;
                    pipe.id = p_id_count;
                    Pipes.insert({ p_id_count, pipe });
                    break;
                }
                case 2:
                {
                    cout << "OK, returning to home..." << endl << endl;
                    break;
                }
                }
            }
            break;
        }
        case 2: // show stations. if no stations, then add only
        {
            if (!Stations.empty())
            {
                // !!! put in function with giving vector
                table.Clear();
                table.AddCol(5);
                table.AddCol(15);
                table.AddCol(10);
                table.AddCol(20);
                table.AddCol(20);

                table.MakeBorderExt(true);
                table.SetDelimRow(true, '-');
                table.SetDelimCol(true, '|');

                table << "ID" << "Name" << "Shops" << "Working shops" << "Effectiveness";

                it_station = Stations.begin();

                for (int i = 0; it_station != Stations.end(); it_station++) {
                    table << it_station->second.id << it_station->second.station_name << it_station->second.shops << it_station->second.working_shops << it_station->second.effect;
                }
                cout << endl << "What to do?" << endl
                    << "1. Add exciting station" << endl
                    << "2. Delete" << endl
                    << "0. Back to home" << endl << endl;

                a = GetInt(0, 2);
                cout << endl;

                switch (a)
                {
                case 1:
                {
                    station = Create_station();
                    s_id_count++;
                    station.id = s_id_count;
                    Stations.insert({ s_id_count, station });
                    break;
                }
                case 2:
                {
                    cout << "Enter IDs of pipelines. One by one, after each ID press ENTER:" << endl;
                    id = GetInt();
                    while (id != NULL)
                    {
                        vec_picked_ids.push_back(id);
                        cout << "Added. Enter one more or type 0 to modify" << endl; // check what the output when press ENTER
                        id = GetInt();
                    }
                    if (!vec_picked_ids.empty())
                    {
                        cout << "Are you sure to delete?" << endl
                            << "1. Yes" << endl
                            << "2. No" << endl << endl;


                        a = GetInt(0, 3);
                        cout << endl;

                        switch (a)
                        {
                        case 1:
                        {
                            it_station = Stations.begin();

                            for (int i = 0; i < vec_picked_ids.size(); i++) {
                                it_station = Stations.find(vec_picked_ids[i]);
                                Stations.erase(it_station);
                            }
                            vec_picked_ids.clear();
                            break;

                        }
                        case 2:
                        {
                            break;
                        }
                        }
                    }
                }
                }
            }
            else
            {
                cout << "No stations. Want to add?" << endl
                    << "1. Yes" << endl
                    << "2. No" << endl << endl;

                a = GetInt(1, 2);
                cout << endl << endl;

                switch (a)
                {
                case 1:
                {
                    station = Create_station();
                    s_id_count++;
                    station.id = s_id_count;
                    Stations.insert({ s_id_count, station });
                    break;
                }
                case 2:
                {
                    break;
                }
                }
            }
            break;
        }
        case 3: // search pipelines.
        {
            if (!Pipes.empty())
            {
                cout << "Search by..." << endl
                    << "1. By ID" << endl
                    << "2. By repairing status" << endl
                    << "0. Back to home" << endl << endl;
                a = GetInt(0, 2);
                cout << endl << endl;

                switch (a)
                {
                case 1:
                {
                    // by ID
                    cout << "Enter ID of pipeline: ";
                    a = GetInt();
                    cout << endl << endl;
                    it_pipe = Pipes.find(a);

                    if (it_pipe == Pipes.end())
                    {
                        cout << "No pipeline found." << endl << endl;
                    }
                    else
                    {
                        table.Clear();
                        table.SetCols(4, 12);

                        table.MakeBorderExt(true);
                        table.SetDelimRow(true, '-');
                        table.SetDelimCol(true, '|');

                        cout << "Pipeline:" << endl << endl;

                        table << "ID" << "Diameter" << "Length" << "Repairing?";
                        table << it_pipe->second.id << it_pipe->second.d << it_pipe->second.l << it_pipe->second.Repair;

                        cout << endl << endl;
                    }
                    break;
                }
                case 2:
                {
                    // by Repairing status

                    cout << "What status?" << endl
                        << "1. Repairing now" << endl
                        << "2. In use" << endl << endl;

                    a = GetInt();
                    cout << endl << endl;

                    switch (a)
                    {
                    case 1:
                    {
                        it_pipe = Pipes.begin();
                        for (int i = 0; it_pipe != Pipes.end(); it_pipe++) {
                            if (it_pipe->second.Repair == 1)
                            {
                                vec_picked_p.push_back(it_pipe->second);
                            }
                        }

                        if (!vec_picked_p.empty())
                        {
                            table.Clear();
                            table.SetCols(4, 12);

                            table.MakeBorderExt(true);
                            table.SetDelimRow(true, '-');
                            table.SetDelimCol(true, '|');

                            cout << "Pipelines:" << endl << endl;

                            table << "ID" << "Diameter" << "Length" << "Repairing?";

                            for (int i = 0; i < vec_picked_p.size(); i++) {
                                table << vec_picked_p[i].id << vec_picked_p[i].d << vec_picked_p[i].l << vec_picked_p[i].Repair;
                            }

                            vec_picked_p.clear();
                            cout << endl << endl;
                        }
                        else
                        {
                            cout << "No pipelines found." << endl << endl;
                        }


                        cout << endl << endl;
                        break;
                    }
                    case 2:
                    {
                        it_pipe = Pipes.begin();
                        for (int i = 0; it_pipe != Pipes.end(); it_pipe++) {
                            if (it_pipe->second.Repair == 0)
                            {
                                vec_picked_p.push_back(it_pipe->second);
                            }


                            if (!vec_picked_p.empty())
                            {
                                table.Clear();
                                table.SetCols(4, 12);

                                table.MakeBorderExt(true);
                                table.SetDelimRow(true, '-');
                                table.SetDelimCol(true, '|');

                                cout << "Pipelines:" << endl << endl;

                                table << "ID" << "Diameter" << "Length" << "Repairing?";

                                for (int i = 0; i < vec_picked_p.size(); i++) {
                                    table << vec_picked_p[i].id << vec_picked_p[i].d << vec_picked_p[i].l << vec_picked_p[i].Repair;
                                }

                                vec_picked_p.clear();
                                cout << endl << endl;
                            }
                            else
                            {
                                cout << "No pipelines found." << endl << endl;
                            }

                            cout << endl << endl;
                            break;
                        }
                    }
                    break;
                    }
                }
                }
            }
            else
            {
                cout << "No pipelines." << endl << endl;
            }
            break;
        }
        case 4: // search stations. 
        {
            if (!Stations.empty())
            {
                cout << "Search by..." << endl
                    << "1. By name" << endl
                    << "2. By ID" << endl
                    << "3. By % of working shops" << endl
                    << "0. Return to home" << endl << endl;

                a = GetInt(0, 3);

                switch (a)
                {
                case 1:
                {
                    // by name
                    cout << "Enter name: ";
                    str = GetString();
                    cout << endl << endl;

                    it_station = Stations.begin();
                    for (int i = 0; it_station != Stations.end(); it_station++)
                    {
                        if (it_station->second.station_name == str)
                        {
                            vec_picked_s.push_back(it_station->second);
                        }
                    }

                    if (!vec_picked_s.empty())
                    {
                        table.Clear();
                        table.AddCol(5);
                        table.AddCol(15);
                        table.AddCol(10);
                        table.AddCol(20);
                        table.AddCol(20);

                        table.MakeBorderExt(true);
                        table.SetDelimRow(true, '-');
                        table.SetDelimCol(true, '|');

                        cout << "Stations:" << endl << endl;

                        table << "ID" << "Name" << "Shops" << "Working shops" << "Effectiveness";

                        for (int i = 0; i < vec_picked_s.size(); i++) {
                            table << vec_picked_s[i].id << vec_picked_s[i].station_name << vec_picked_s[i].shops << vec_picked_s[i].working_shops << vec_picked_s[i].effect;
                        }

                        vec_picked_s.clear();
                        cout << endl << endl;
                    }
                    else
                    {
                        cout << "No stations found." << endl << endl;
                    }

                    break;
                }
                case 2:
                {
                    // by ID
                    cout << "Enter ID of station: ";
                    a = GetInt();
                    cout << endl << endl;

                    it_station = Stations.find(a);

                    if (it_station == Stations.end())
                    {
                        cout << "No station found." << endl << endl;
                    }
                    else
                    {
                        table.Clear();
                        table.AddCol(5);
                        table.AddCol(15);
                        table.AddCol(10);
                        table.AddCol(20);
                        table.AddCol(20);

                        table.MakeBorderExt(true);
                        table.SetDelimRow(true, '-');
                        table.SetDelimCol(true, '|');

                        cout << "Station:" << endl << endl;

                        table << "ID" << "Name" << "Shops" << "Working shops" << "Effectiveness";
                        table << it_station->second.id << it_station->second.station_name << it_station->second.shops << it_station->second.working_shops << it_station->second.effect;
                        cout << endl << endl;
                    }
                    break;
                }
                case 3:
                {
                    cout << "Enter percent that is not less than the one you are looking for: ";
                    float b = GetFloat(0.0, 100.0);
                    cout << endl << endl;

                    it_station = Stations.begin();
                    for (int i = 0; it_station != Stations.end(); it_station++)
                    {
                        float shop_check = (float)it_station->second.working_shops / (float)it_station->second.shops * 100;
                        if (shop_check >= b)
                        {
                            vec_picked_s.push_back(it_station->second);
                        }

                        if (!vec_picked_s.empty())
                        {
                            table.Clear();
                            table.AddCol(5);
                            table.AddCol(15);
                            table.AddCol(10);
                            table.AddCol(20);
                            table.AddCol(20);

                            table.MakeBorderExt(true);
                            table.SetDelimRow(true, '-');
                            table.SetDelimCol(true, '|');

                            cout << "Stations:" << endl << endl;

                            table << "ID" << "Name" << "Shops" << "Working shops" << "Effectiveness";

                            for (int i = 0; i < vec_picked_s.size(); i++) {
                                table << vec_picked_s[i].id << vec_picked_s[i].station_name << vec_picked_s[i].shops << vec_picked_s[i].working_shops << vec_picked_s[i].effect;
                            }

                            vec_picked_s.clear();
                            cout << endl << endl;
                        }
                        else
                        {
                            cout << "No stations found." << endl << endl;
                        }
                    }
                }
                }
            }
            else
            {
                cout << "No stations" << endl << endl;
            }
            break;
        }
        case 5:
        {
            if (Pipes.empty() && Stations.empty())
            {
                cout << "Nothing to save." << endl << endl;
            }
            else
            {
                ofstream file;

                cout << "Enter name of output file: ";
                str = GetString();
                cout << endl << endl;
                file.open(str, ios_base::out);

                if (file.good())
                {
                    file << "PIPELINES COUNT" << endl << p_id_count << endl << "STATIONS COUNT" << endl << s_id_count << endl;
                    if (p_id_count != 0)
                    {
                        it_pipe = Pipes.begin();
                        for (int i = 0; it_pipe != Pipes.end(); it_pipe++)
                        {
                            file << "PIPELINE" << endl
                                << it_pipe->second.id << endl
                                << it_pipe->second.l << endl
                                << it_pipe->second.d << endl
                                << it_pipe->second.Repair << endl;
                        }
                    }
                    else
                    {
                        cout << "No pipelane in base.";
                    }

                    if (s_id_count != 0)
                    {
                        it_station = Stations.begin();
                        for (int i = 0; it_station != Stations.end(); it_station++)
                        {
                            file << "STATION" << endl
                                << it_station->second.id << endl
                                << it_station->second.station_name << endl
                                << it_station->second.shops << endl
                                << it_station->second.working_shops << endl
                                << it_station->second.effect << endl;
                        }
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
            break;
        }
        case 6:
        {
            ifstream file;
            cout << "Enter name of file: ";
            str = GetString();
            cout << endl << endl;
            file.open(str, ios::in);

            if (file.good())
            {
                Pipes.clear();
                Stations.clear();

                while (!file.eof())
                {
                    getline(file, str);
                    if (str == "PIPELINE")
                    {
                        string value;
                        Pipe p_picked;
                        getline(file, value);
                        p_picked.id = stoi(value);
                        getline(file, value);
                        p_picked.l = stof(value);
                        getline(file, value);
                        p_picked.d = stoi(value);
                        getline(file, value);
                        p_picked.Repair = (value == "1");

                        Pipes.insert({ p_picked.id, p_picked });
                    }

                    if (str == "STATION")
                    {
                        string value;
                        Station s_picked;
                        getline(file, value);
                        s_picked.id = stoi(value);
                        getline(file, value);
                        s_picked.station_name = value;
                        getline(file, value);
                        s_picked.shops = stoi(value);
                        getline(file, value);
                        s_picked.working_shops = stoi(value);
                        getline(file, value);
                        s_picked.effect = stoi(value);

                        Stations.insert({ s_picked.id, s_picked });
                    }

                    if (str == "PIPELINES COUNT")
                    {
                        string value;
                        getline(file, value);
                        p_id_count = stoi(value);
                    }

                    if (str == "STATIONS COUNT")
                    {
                        string value;
                        getline(file, value);
                        s_id_count = stoi(value);
                    }
                }
                cout << "Loaded." << endl << endl;
            }
            else
            {
                cout << "Can't load from file." << endl << endl;
            }

            break;
        }
        case 0:
        {
            return 0;
        }
        }
    }
}