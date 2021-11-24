#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <vector>
#include <unordered_map>
#include "LeoPipeLine.h"
#include "StreamTable.h" // исключить!
#include "Ccheck.h"
#include "Cpipe.h"
#include "Cstation.h"

using namespace std;

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

void AfterTableMenu()
{
    cout << "What to do?" << endl
        << "1. Add new pipeline" << endl
        << "2. Modify" << endl
        << "3. Delete" << endl
        << "0. Back to home" << endl << endl;
}

void WhatStatusToSet()
{
    cout << "What repairing status you want to set?" << endl
        << "1. All in repair" << endl
        << "2. All in use" << endl
        << "0. Back to home" << endl << endl;
}

template <typename T, typename S>
using Filter = bool(*)(const S& pipe, T param);

template <typename T, typename S>
static vector <int> findByFilter(const unordered_map<int, S>& pipes, Filter<T, S> f, T param) {
    vector <int> keys;
    for (auto& i : pipes) {
        if (f(i.second, param))
            keys.push_back(i.first);
    }
    return keys;
}

void PipeTable(StreamTable& table, std::unordered_map<int, Cpipe>& Pipes, std::vector<int>& vec_picked_ids)
{
    table.Clear();
    table.SetCols(4, 12);

    table.MakeBorderExt(true);
    table.SetDelimRow(true, '-');
    table.SetDelimCol(true, '|');

    cout << "Pipelines:" << endl << endl;

    table << "ID" << "Diameter" << "Length" << "Repairing?";

    for (auto it = Pipes.begin(); it != Pipes.end(); ++it) {
        for (int i = 0; i < vec_picked_ids.size(); i++) {
            if (vec_picked_ids[i] == it->first) {
                table << it->second.GetID() << it->second.d << it->second.l << it->second.s;
            }
        }
    }
}

void StationTable(StreamTable& table, std::unordered_map<int, Cstation>& Stations, std::vector<int>& vec_picked_ids)
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

    table << "ID" << "Name" << "Shops" << "Working shops" << "Effectiveness";

    for (auto it = Stations.begin(); it != Stations.end(); ++it) {
        for (int i = 0; i < vec_picked_ids.size(); i++) {
            if (vec_picked_ids[i] == it->first) {
                table << it->second.GetID() << it->second.n << it->second.s << it->second.w_s << it->second.e;
            }
        }
    }
}

int main()
{
    vector <int> vec_picked_ids;

    unordered_map <int, Cpipe> Pipes = {};
    unordered_map <int, Cstation> Stations = {};

    StreamTable table(cout);

    int id;

    string str;

    while (1)
    {
        int a = 0;
        PrintMenu();
        a = getInt(0, 8);
        cout << endl;

        switch (a)
        {
        case 1:
        {
            if (!Pipes.empty())
            {
                vec_picked_ids.clear();
                for (int i = 0; i <= Pipes.size(); i++) {
                    vec_picked_ids.push_back(i);
                }

                PipeTable(table, Pipes, vec_picked_ids);

                cout << endl << endl;

                AfterTableMenu();

                a = getInt(0, 3);
                cout << endl;

                switch (a)
                {
                case 1: // add
                {
                    Cpipe pipe;
                    pipe.create();
                    Pipes.insert({ pipe.GetID(), pipe });
                    break;
                }
                case 2: // modify
                {
                    vec_picked_ids.clear();

                    while (1) 
                    {
                        cout << "Enter ID of pipeline (press 0 to exit): ";
                        id = getInt();
                        cout << endl << endl;
                        if (id == 0) break;
                        if (Pipes.find(id) != Pipes.end()) {
                            Pipes[id].edit();
                        }
                        cout << "Modify one more?" <<
                            endl << "1. Yes" <<
                            endl << "2. No" << endl << endl;
                        a = getInt(1,2);
                        cout << endl << endl;
                        if (a == 2) break;
                    }
                    break;
                }
                case 3:
                {
                    while (1)
                    {
                        cout << "Enter ID of pipeline (press 0 to exit): ";
                        id = getInt();
                        cout << endl << endl;
                        if (id == 0) break;
                        if (Pipes.find(id) != Pipes.end()) {
                            Pipes.erase(id);
                        }
                        cout << "Delete one more?" <<
                            endl << "1. Yes" <<
                            endl << "2. No" << endl << endl;
                        a = getInt(1, 2);
                        cout << endl << endl;
                        if (a == 2) break;
                    }
                    break;
                }
                }
            }
            else
            {
                cout << "No pipelines. Want to add?" << endl
                    << "1. Yes" << endl
                    << "2. No" << endl << endl;

                a = getInt(1, 2);
                cout << endl << endl;

                switch (a)
                {
                case 1:
                {
                    Cpipe pipe;
                    pipe.create();
                    Pipes.insert({ pipe.GetID(), pipe });
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
        case 2:
        {
            if (!Stations.empty())
            {
                vec_picked_ids.clear();
                for (int i = 0; i <= Stations.size(); i++) {
                    vec_picked_ids.push_back(i);
                }

                StationTable(table, Stations, vec_picked_ids);

                cout << endl << "What to do?" << endl
                    << "1. Add new station" << endl
                    << "2. Modify one" << endl
                    << "3. Delete" << endl
                    << "0. Back to home" << endl << endl;

                a = getInt(0, 3);
                cout << endl;

                switch (a)
                {
                case 1:
                {
                    Cstation station;
                    station.create();
                    Stations.insert({ station.GetID(), station });
                    break;
                }
                case 2:
                {
                    while (1)
                    {

                        cout << "Enter ID of station (press 0 to exit): ";
                        id = getInt();
                        cout << endl << endl;
                        if (id == 0) break;
                        if (Stations.find(id) != Stations.end()) {
                            Stations[id].edit();
                        }
                        cout << "Modify one more?" <<
                            endl << "1. Yes" <<
                            endl << "2. No" << endl << endl;
                        a = getInt(1, 2);
                        cout << endl << endl;
                        if (a == 2) break;
                    }
                    break;
                }
                case 3:
                {
                    while (1)
                    {
                        cout << "Enter ID of station (press 0 to exit): ";
                        id = getInt();
                        cout << endl << endl;
                        if (id == 0) break;
                        if (Stations.find(id) != Stations.end()) {
                            Stations.erase(id);
                        }
                        cout << "Delete one more?" <<
                            endl << "1. Yes" <<
                            endl << "2. No" << endl << endl;
                        a = getInt(1, 2);
                        cout << endl << endl;
                        if (a == 2) break;
                    }
                    break;
                }
                }
            }
            else
            {
                cout << "No stations. Want to add?" << endl
                    << "1. Yes" << endl
                    << "2. No" << endl << endl;

                a = getInt(1, 2);
                cout << endl << endl;

                switch (a)
                {
                case 1:
                {
                    Cstation station;
                    station.create();
                    Stations.insert({ station.GetID(), station });
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
        case 3: // FILTER by status
        {
            if (!Pipes.empty())
            {
                vec_picked_ids.clear();
                cout << "What status?" << endl
                    << "0. Repairing now" << endl
                    << "1. In use" << endl << endl;

                vec_picked_ids = findByFilter(Pipes, Cpipe::checkCondition, getBool());

                if (vec_picked_ids.empty())
                {
                    cout << "Not found" << endl << endl;
                }
                else
                {
                    PipeTable(table, Pipes, vec_picked_ids);
                    cout << "Want to change status?" << endl
                        << "1. Yes" << endl
                        << "2. No" << endl << endl;
                    a = getInt(1, 2);
                    cout << endl << endl;
                    if (a == 2) break;

                    for (int i = 0; i < vec_picked_ids.size(); i++) {
                        if (Pipes.find(vec_picked_ids[i]) != Pipes.end()) {
                            Pipes[vec_picked_ids[i]].edit();
                        }
                    }
                    
                    cout << "Done." << endl << endl;
                }


                break;
            }
        case 4: // FILTER
        {
            if (!Stations.empty())
            {
                cout << "Search by..." << endl
                    << "1. By name" << endl
                    << "2. By % of working shops" << endl
                    << "0. Return to home" << endl << endl;

                a = getInt(0, 2);

                switch (a)
                {
                case 1:
                {
                    // by name
                    vec_picked_ids.clear();
                    cout << "Enter name: ";
                    str = getString();
                    cout << endl << endl;

                    vec_picked_ids = findByFilter(Stations, Cstation::checkName, str);

                    if (vec_picked_ids.empty())
                    {
                        cout << "Not found" << endl << endl;
                    }
                    else
                    {
                        StationTable(table, Stations, vec_picked_ids);
                        cout << "Want to modify?" << endl
                            << "1. Yes" << endl
                            << "2. No" << endl << endl;
                        a = getInt(1, 2);
                        cout << endl << endl;
                        if (a == 2) break;

                        for (int i = 0; i < vec_picked_ids.size(); i++) {
                            if (Stations.find(vec_picked_ids[i]) != Stations.end()) {
                                Stations[vec_picked_ids[i]].edit();
                            }
                        }
                    }

                    break;
                }

                case 2:
                {
                    cout << "Sorry, don't working." << endl << endl;
                    /*cout << "Enter percent that is not less than the one you are looking for: ";
                    float b = getFloat(0.0, 100.0);
                    cout << endl << endl;

                    vec_picked_ids.clear();
                    vec_picked_ids = findByFilter(Stations, Cstation::checkPercent, getFloat(0.0, 100.0));

                    if (vec_picked_ids.empty())
                    {
                        cout << "Not found" << endl << endl;
                    }
                    else
                    {
                        StationTable(table, Stations, vec_picked_ids);
                        cout << "Want to modify?" << endl
                            << "1. Yes" << endl
                            << "2. No" << endl;
                        a = getInt(1, 2);
                        if (a == 2) { break; };

                        for (int i = 0; i < vec_picked_ids.size(); i++) {
                            if (Stations.find(vec_picked_ids[i]) != Stations.end()) {
                                Stations[vec_picked_ids[i]].edit();
                            }
                        }
                    }*/
                    break;
                }
                }
            } break;  }
                case 5:
                {
                    if (Pipes.empty() && Stations.empty())
                    {
                        cout << "Nothing to save." << endl << endl;
                    }
                    else
                    {
                        ofstream file;
                        file.open(getFileName());
                        if (file.good()) {
                            for (auto it = Pipes.begin(); it != Pipes.end(); ++it)
                                file << "PIPELINE" << endl << it->second;

                            for (auto it = Stations.begin(); it != Stations.end(); ++it)
                                file << "STATION" << endl << it->second;

                            file.close();
                            cout << "Saved" << endl;
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
                    str = getFileName();
                    cout << endl << endl;
                    file.open(str, ios::in);

                    if (file.good())
                    {
                        Pipes.clear();
                        Stations.clear();

                        while (!file.eof())
                        {
                            getline(file, str);
                            if (str == "PIPELINE") {
                                Cpipe p = {};
                                file >> p;
                                Pipes.insert({ p.GetID(), p });
                            }

                            if (str == "STATION") {
                                Cstation s = {};
                                file >> s;
                                Stations.insert({ s.GetID(), s });
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
}