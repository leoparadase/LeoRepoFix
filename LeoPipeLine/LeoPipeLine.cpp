#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <vector>
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

    cout << "1. Show pipelines" << endl
        << "2. Show stations" << endl
        << "3. Search pipelines" << endl
        << "4. Search stations" << endl
        << "5. Multiple pipeline editing" << endl
        << "6. Multiple station editing" << endl
        << "7. Save to file" << endl
        << "8. Load from file" << endl
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

    vector <Pipe> Pipes;
    vector <Station> Stations;
    vector <int> picked_ids;

    StreamTable table(cout);

    int id;
    int p_id_count = 0;
    int s_id_count = 0;

    while (1)
    {
        int a = 0;
        PrintMenu();
        a = GetInt();
        cout << endl;

        switch (a)
        {
        case 1: // show pipelines. if no pipelines, then add only
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

                for (int i = 0; i < Pipes.size(); i++) {
                    table << Pipes[i].id << Pipes[i].d << Pipes[i].l << Pipes[i].Repair;
                }

                cout << endl << endl;

                cout << "What to do?" << endl
                    << "1. Add exciting pipeline" << endl
                    << "2. Modify" << endl
                    << "3. Delete" << endl
                    << "0. Back to home" << endl << endl;
                
                a = GetInt();
                cout << endl;

                switch(a)
                {
                    case 1:
                    {
                        pipe = Create_pipe();
                        pipe.id = p_id_count++;
                        Pipes.push_back(pipe);
                        break;
                    }
                    case 2:
                    {
                        cout << "Enter IDs of pipelines. One by one, after each ID press ENTER:" << endl;
                        id = GetInt();
                        while (id != NULL)
                        {
                            picked_ids.push_back(id);
                            cout << "Added. Enter one more or press ENTER to modify" << endl; // check what the output when press ENTER
                            id = GetInt();
                        }
                        if (!picked_ids.empty())
                        {
                            cout << "What repairing status you want to set?" << endl
                                << "1. All in repair" << endl
                                << "2. All in use" << endl
                                << "0. Back to home" << endl << endl;

                            a = GetInt(-1,3);
                            cout << endl;

                            switch (a)
                            {
                            case 1:
                            {
                                for (int i = 0; i < picked_ids.size(); i++) {
                                    for (int j = 0; j < Pipes.size(); j++) {
                                        if (Pipes[j].id == picked_ids[i])
                                        {
                                            Pipes[j].Repair = 1;
                                        }
                                    }
                                }
                                picked_ids.clear();
                                break;
                            }
                            case 2:
                            {
                                for (int i = 0; i < picked_ids.size(); i++) {
                                    for (int j = 0; j < Pipes.size(); j++) {
                                        if (Pipes[j].id == picked_ids[i])
                                        {
                                            Pipes[j].Repair = 0;
                                        }
                                    }
                                }
                                picked_ids.clear();
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
                            picked_ids.push_back(id);
                            cout << "Added. Enter one more or press ENTER to modify" << endl; // check what the output when press ENTER
                            id = GetInt();
                        }
                        if (!picked_ids.empty())
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
                                for (int i = 0; i < picked_ids.size(); i++) {
                                    for (int j = 0; j < Pipes.size(); j++) {
                                        if (Pipes[j].id == picked_ids[i])
                                        {
                                            Pipes.erase(Pipes.begin() + j);
                                        }
                                    }
                                }
                                picked_ids.clear();
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
                // done. check input
            }
            else
            {
            cout << "No pipelines. Want to add?" << endl 
                << "1. Yes" << endl
                << "2. No" << endl << endl;


            a = GetInt(0, 3);
            cout << endl;

            switch (a)
            {
            case 1:
            {
                pipe = Create_pipe();
                pipe.id = p_id_count++;
                Pipes.push_back(pipe);
                break;
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
        case 2: // show stations. if no stations, then add only
        {
            if (!Stations.empty())
            {
                // !!! put in function with giving vector
                table.Clear();
                table.AddCol(5);
                table.AddCol(15);
                table.AddCol(10);
                table.AddCol(10);
                table.AddCol(15);

                table.MakeBorderExt(true);
                table.SetDelimRow(true, '-');
                table.SetDelimCol(true, '|');

                table << "ID" << "Name" << "Shops" << "Working shops" << "Effectiveness";

                for (int i = 0; i < Stations.size(); i++) {
                    table << Stations[i].id << Stations[i].station_name << Stations[i].shops << Stations[i].working_shops << Stations[i].effect;
            }
                cout << "What to do?" << endl
                    << "1. Add exciting station" << endl
                    << "2. Modify" << endl
                    << "3. Delete" << endl
                    << "0. Back to home" << endl << endl;

                a = GetInt();
                cout << endl;

                switch (a)
                {
                case 1:
                {
                    station = Create_station();
                    station.id = s_id_count++;
                    Stations.push_back(station);
                    break;
                }
                case 2:
                {
                    cout << "Enter IDs of stations. One by one, after each ID press ENTER:" << endl; // single id!!!
                    id = GetInt();
                    while (id != NULL)
                    {
                        picked_ids.push_back(id);
                        cout << "Added. Enter one more or press ENTER to modify" << endl; // check what the output when press ENTER
                        id = GetInt();
                    }
                    if (!picked_ids.empty())
                    {
                        cout << "What repairing status you want to set?" << endl // change number of wsh only
                            << "1. All in repair" << endl
                            << "2. All in use" << endl
                            << "0. Back to home" << endl << endl;

                        a = GetInt(-1, 3);
                        cout << endl;

                        switch (a)
                        {
                        case 1:
                        {
                            for (int i = 0; i < picked_ids.size(); i++) {
                                for (int j = 0; j < Stations.size(); j++) {
                                    if (Stations[j].id == picked_ids[i])
                                    {
                                        Stations[j].working_shops = 1; // do check on working shops
                                    }
                                }
                            }
                            picked_ids.clear();
                            break;
                        }
                        case 2:
                        {
                            for (int i = 0; i < picked_ids.size(); i++) {
                                for (int j = 0; j < Stations.size(); j++) {
                                    if (Stations[j].id == picked_ids[i])
                                    {
                                        Stations[j].working_shops = 0;
                                    }
                                }
                            }
                            picked_ids.clear();
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
                        picked_ids.push_back(id);
                        cout << "Added. Enter one more or press ENTER to modify" << endl; // check what the output when press ENTER
                        id = GetInt();
                    }
                    if (!picked_ids.empty())
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
                            for (int i = 0; i < picked_ids.size(); i++) {
                                for (int j = 0; j < Stations.size(); j++) {
                                    if (Stations[j].id == picked_ids[i])
                                    {
                                        Stations.erase(Stations.begin() + j);
                                    }
                                }
                            }
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
            //what to do?
            //1. add exciting
            //2. modify one
            //3. delete one
            }
            else
            {
            cout << "No stations. Want to add?" << endl
                << "1. Yes" << endl
                << "2. No" << endl << endl;


            a = GetInt(0, 3);
            cout << endl;

            switch (a)
            {
            case 1:
            {
                station = Create_station();
                station.id = s_id_count++;
                Stations.push_back(station);
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
        case 3: // search pipelines. if no pipelines, then unavailible
        {
            // by ID
            // by Repairing status
            break;
        }
        case 4: // search stations. if no stations, then unavailible
        {
            // by Name
            // by % of working shops
            break;
        }
        case 5: // multiple pipeline editing. if no pipelines, then unavailible
        {
            // by entered IDs
            // by search results 
            break;
        }
        case 6: // multiple station editing. if no stations, then unavailible
        {
            // by entered IDs
            // by search results
            break;
        }
        case 7: // save to file w/custom name
        {
            break;
        }
        case 8: // load from file w/custom name
        {
            break;
        }
        case 0:
        {
            return 0;
        }
        default: // big ass cunt
        {
            break;
        }
        }

        /*switch (a)
        {
        case 1:
        {
            pipe = Create_pipe();
            pipe.id = Pipes.size() + 1;
            Pipes.push_back(pipe);
            break;
        }
        case 2:
        {
            station = Create_station();
            station.id = Stations.size() + 1;
            Stations.push_back(station);
            break;
        }
        case 3: // show all in table
        {
            if (!Pipes.empty())
            {
                //PipeOutput(pipe);

                table.Clear();
                table.SetCols(4, 12);

                table.MakeBorderExt(true);
                table.SetDelimRow(true, '-');
                table.SetDelimCol(true, '|');

                cout << "Pipelines:" << endl << endl;

                table << "ID" << "Diameter" << "Length" << "Repairing?";

                for (int i = 0; i < Pipes.size(); i++) {
                    table << Pipes[i].id << Pipes[i].d << Pipes[i].l << Pipes[i].Repair;
                }

                cout << endl << endl;
            }
            else
            {
                cout << "No pipelines in base." << endl << endl;
            };

            if (station.shops > 0)
            {
                //StationOutput(station);

                table.Clear();
                table.AddCol(5);
                table.AddCol(15);
                table.AddCol(10);
                table.AddCol(10);
                table.AddCol(15);

                table.MakeBorderExt(true);
                table.SetDelimRow(true, '-');
                table.SetDelimCol(true, '|');

                table << "ID" << "Name" << "Shops" << "Working shops" << "Effectiveness";

                for (int i = 0; i < Stations.size(); i++) {
                    table << Stations[i].id << Stations[i].station_name << Stations[i].shops << Stations[i].working_shops << Stations[i].effect;
                }
            }
            else
            {
                cout << "No stations in base." << endl << endl;
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
        }*/

    } 
}
      