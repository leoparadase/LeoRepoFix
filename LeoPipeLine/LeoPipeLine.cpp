#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <vector>
#include <unordered_map>
//#include "LeoPipeLine.h"
#include "StreamTable.h"
#include "Ccheck.h"
#include "Cpipe.h"
#include "Cstation.h"
#include "Cnetwork.h"

using namespace std;

void PrintMenu()
{
    cout << "Choose the action:" << endl << endl;

    cout << "1. Show pipelines" << endl
        << "2. Show stations" << endl
        << "3. Connect pipes" << endl
        << "4. Disconnect pipes" << endl
        << "5. Show connections" << endl
        << "6. Search pipelines" << endl
        << "7. Search stations" << endl
        << "8. Save to file" << endl
        << "9. Load from file" << endl
        << "10. Sort network" << endl
        << "0. Quit" << endl << endl;
}


int main()
{
    Cnetwork Network;

    while (1)
    {
        PrintMenu();
        cout << endl;
        int a = getInt(0, 10);

        switch (a)
        {
        case 1:
        {
            Network.PipeMainMenu();
            break;
        }
        case 2:
        {
            Network.StationMainMenu();
            break;
        }
        case 3:
        {
            Network.PipeConnect();
            break;
        }
        case 4:
        {
            Network.PipeDisconnect();
            break;
        }
        case 5:
        {
            Network.ShowConnections();
            break;
        }
        case 6:
        {
            Network.SearchPipes();
            break;
        }
        case 7:
        {
            Network.SearchStations();
            break;
        }
        case 8:
        {
            Network.save();
            break;
        }
        case 9:
        {
            Network.load();
            break;
        }
        case 10:
        {
            Network.NetworkSort();
            break;
        }
        default:
        {
            return 0;
        }
        }
    }
 }


/*int main()
{
    vector <int> vec_picked_ids;

    unordered_map <int, Cpipe> Pipes = {};
    unordered_map <int, Cstation> Stations = {};

    StreamTable table(cout);

    while (1)
    {
        PrintMenu();
        cout << endl;

        switch (getInt(0, 8))
        {
        case 1:
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
                        int a = getInt(1,2);
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
                            Pipes.erase(id);
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
            }
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
            break;
        }
        case 2:
        {
            if (!Stations.empty())
            {
                vec_picked_ids.clear();
                for (auto& p: Stations)//.size(); i++) {
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
                            Stations.erase(id);
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
                    int a = getInt(1, 2);
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

                    break;
                }
                case 0:
                {
                    return 0;
                }
                }
            }
        
    } 
}*/