#pragma once
#include "Cnetwork.h"

using namespace std;

StreamTable table(cout);


void Cnetwork::AfterTableMenu()
{
    cout << "What to do?" << endl
        << "1. Add new pipeline" << endl
        << "2. Modify" << endl
        << "3. Delete" << endl
        << "0. Back to home" << endl << endl;
}
void Cnetwork::WhatStatusToSet()
{
    cout << "What repairing status you want to set?" << endl
        << "1. All in repair" << endl
        << "2. All in use" << endl
        << "0. Back to home" << endl << endl;
}

void Cnetwork::PipeTable(StreamTable& table, std::unordered_map<int, Cpipe>& Pipes, std::vector<int>& vec_picked_ids)
{
    table.Clear();
    table.SetCols(6, 12);

    table.MakeBorderExt(true);
    table.SetDelimRow(true, '-');
    table.SetDelimCol(true, '|');

    cout << "Pipelines:" << endl << endl;

    table << "ID" << "Diameter" << "Length" << "Repairing?" << "From station No." << "To station No.";

    for (auto it = Pipes.begin(); it != Pipes.end(); ++it) {
        for (int i = 0; i < vec_picked_ids.size(); i++) {
            if (vec_picked_ids[i] == it->first) {
                table << it->second;
            }
        }
    }
}
void Cnetwork::StationTable(StreamTable& table, std::unordered_map<int, Cstation>& Stations, std::vector<int>& vec_picked_ids)
{
    table.Clear();
    table.AddCol(5);
    table.AddCol(15);
    table.AddCol(10);
    table.AddCol(20);
    table.AddCol(20);
    table.AddCol(20);

    table.MakeBorderExt(true);
    table.SetDelimRow(true, '-');
    table.SetDelimCol(true, '|');

    table << "ID" << "Name" << "Shops" << "Working shops" << "Effectiveness" << "Using shops";

    for (auto it = Stations.begin(); it != Stations.end(); ++it) {
        for (int i = 0; i < vec_picked_ids.size(); i++) {
            if (vec_picked_ids[i] == it->first) {
                table << it->second;
            }
        }
    }
}

void Cnetwork::PipeMainMenu()
{
    if (!Pipes.empty())
    {
        vec_picked_ids.clear();
        for (auto& p : Pipes)
            vec_picked_ids.push_back(p.first);

        PipeTable(table, Pipes, vec_picked_ids);

        cout << endl << endl;

        AfterTableMenu();

        cout << endl;

        switch (getInt(0, 3))
        {
        case 1: // add
        {
            Cpipe pipe;
            cin >> pipe;
            Pipes.insert({ pipe.GetID(), pipe });
            break;
        }
        case 2: // modify
        {
            vec_picked_ids.clear();

            while (1)
            {
                cout << "Enter ID of pipeline (press 0 to exit): ";
                int id = getInt();
                cout << endl << endl;
                if (id == 0) break;
                if (Pipes.find(id) != Pipes.end()) {
                    Pipes[id].edit();
                }
                cout << "Modify one more?" <<
                    endl << "1. Yes" <<
                    endl << "2. No" << endl << endl;
                int a = getInt(1, 2);
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
                int id = getInt();
                cout << endl << endl;
                if (id == 0) break;
                if (Pipes.find(id) != Pipes.end()) {
                    if ((Pipes[id].from_id == -1) && (Pipes[id].to_id == -1)) {
                        Pipes.erase(id);
                    }
                    else cout << "Disconnect this pipe!" << endl << endl;
                }
                else cout << "No pipe in base" << endl << endl;
                }
                cout << "Delete one more?" <<
                    endl << "1. Yes" <<
                    endl << "2. No" << endl << endl;
                int a = getInt(1, 2);
                cout << endl << endl;
                if (a == 2) break;
            }
            break;
        }
        }
    // } deleted!
    else
    {
        cout << "No pipelines. Want to add?" << endl
            << "1. Yes" << endl
            << "2. No" << endl << endl;

        cout << endl << endl;

        switch (getInt(1, 2))
        {
        case 1:
        {
            Cpipe pipe;
            cin >> pipe;
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
}

void Cnetwork::StationMainMenu()
{
    if (!Stations.empty())
    {
        vec_picked_ids.clear();
        for (auto& p : Stations)//.size(); i++) {
            vec_picked_ids.push_back(p.first);


        StationTable(table, Stations, vec_picked_ids);

        cout << endl << "What to do?" << endl
            << "1. Add new station" << endl
            << "2. Modify one" << endl
            << "3. Delete" << endl
            << "0. Back to home" << endl << endl;

        cout << endl;

        switch (getInt(0, 3))
        {
        case 1:
        {
            Cstation station;
            cin >> station;
            Stations.insert({ station.GetID(), station });
            break;
        }
        case 2:
        {
            while (1)
            {

                cout << "Enter ID of station (press 0 to exit): ";
                int id = getInt();
                cout << endl << endl;
                if (id == 0) break;
                if (Stations.find(id) != Stations.end()) {
                    Stations[id].edit();
                }
                cout << "Modify one more?" <<
                    endl << "1. Yes" <<
                    endl << "2. No" << endl << endl;
                int a = getInt(1, 2);
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
                int id = getInt();
                cout << endl << endl;
                if (id == 0) break;
                if (Stations.find(id) != Stations.end()) {
                    if (Stations[id].u_s == 0) {
                        Stations.erase(id);
                    }
                    else cout << "Some shops are using now" << endl << endl;
                }
                else cout << "No station in base" << endl << endl;
                cout << "Delete one more?" <<
                    endl << "1. Yes" <<
                    endl << "2. No" << endl << endl;
                int a = getInt(1, 2);
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

        cout << endl << endl;

        switch (getInt(1, 2))
        {
        case 1:
        {
            Cstation station;
            cin >> station;
            Stations.insert({ station.GetID(), station });
            break;
        }
        case 2:
        {
            break;
        }
        }
    }
}

// add search by ID
void Cnetwork::SearchPipes()
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
            int a = getInt(1, 2);
            cout << endl << endl;
            if (a == 2) return;

            for (int i = 0; i < vec_picked_ids.size(); i++) {
                if (Pipes.find(vec_picked_ids[i]) != Pipes.end()) {
                    Pipes[vec_picked_ids[i]].edit();
                }
            }

            cout << "Done." << endl << endl;
        }

    }
}
void Cnetwork::SearchStations()
{
    if (!Stations.empty())
    {
        cout << "Search by..." << endl
            << "1. By name" << endl
            << "2. By % of working shops" << endl
            << "0. Return to home" << endl << endl;

        switch (getInt(0, 2))
        {
        case 1:
        {
            // by name
            vec_picked_ids.clear();
            cout << "Enter name: ";
            string str = getString();
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
                int a = getInt(1, 2);
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
            cout << "Enter percent that is not less than the one you are looking for: ";
            cout << endl << endl;

            vec_picked_ids.clear();
            vec_picked_ids = findByFilter(Stations, Cstation::checkPercent, getFloat(0, 100));

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
                int a = getInt(1, 2);
                if (a == 2) break;
                cout << endl << endl;

                for (int i = 0; i < vec_picked_ids.size(); i++) {
                    if (Stations.find(vec_picked_ids[i]) != Stations.end()) {
                        Stations[vec_picked_ids[i]].edit();
                    }
                }
            }
            break;
        }
        }
    }
}

void Cnetwork::save()
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
}
void Cnetwork::load()
{
    ifstream file;
    string str = getFileName();
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
}

void Cnetwork::PipeConnect() 
{
    cout << "Enter ID of pipeline (press 0 to exit): ";
    int id = getInt();
    if (id == 0) return;
    cout << endl;

    cout << "Enter ID of initial station (press 0 to exit): ";
    int from_id = getInt();
    if (from_id == 0) return;
    cout << endl;

    cout << "Enter ID of terminal station (press 0 to exit): ";
    int to_id = getInt();
    if (to_id == 0) return;

    cout << endl << endl;
    if (Pipes.find(id) != Pipes.end()) {
        if (Stations.find(from_id) != Stations.end()) {
            if (Stations.find(to_id) != Stations.end()) {
                if (Pipes[id].from_id == -1 && Pipes[id].to_id == -1) {
                    if (Stations[from_id].u_s < Stations[from_id].w_s) {
                        if (Stations[from_id].u_s < Stations[from_id].w_s) {
                            Pipes[id].from_id = from_id;
                            Pipes[id].to_id = to_id;
                            Stations[id].u_s++;

                            cout << "Connected" << endl << endl;
                        }
                        else cout << "No vacant shop in initial station" << endl << endl;
                    }
                    else cout << "No vacant shop in initial station" << endl << endl;
                }
                else cout << "Pipe is already connected" << endl << endl;
            }
            else cout << "No such terminal station in base" << endl << endl;
        }
        else cout << "No such initial station in base" << endl << endl;
    }
    else cout << "No pipe in base" << endl << endl;
}



void Cnetwork::PipeDisconnect() // try to add it in delete menu
{   
    cout << "Enter ID of pipeline (press 0 to exit): ";
    int id = getInt();
    if (id == 0) return;
    cout << endl << endl;

    if (Pipes.find(id) != Pipes.end()) {
        if (Pipes[id].from_id != -1 && Pipes[id].to_id != -1) {
            Pipes[id].from_id = -1;
            Pipes[id].to_id = -1;
            Stations[id].u_s--;

            cout << "Disconnected" << endl << endl;
        }
        else cout << "Pipe is disconnected" << endl << endl;
    }
    else cout << "No pipe in base" << endl << endl;
}

//void Cnetwork::NetworkMap();
    // in unordered map:: struct/class: connection id, pipe id, station from id, station to id
    // add struct when connecting, delete when disconnecting
    // table output
//void Cnetwork::NetworkSort();
    // ask about sort
    // init dot = station, in which connections contains: pipe->to.id = station_id AND NO FROM ID!!!

