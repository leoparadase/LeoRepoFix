#include <iostream>
#include <fstream>
#include <iomanip>
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

float isFloat() 
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

int isEffect() 
{
    while (1)
    {
        int number;
        cin >> number;

        if (cin.fail() || number < 0 || number > 100)
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

string isString() 
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

bool isBool() 
{
    while (1)
    {
        bool condition;
        cin >> condition;

        if (cin.fail())
        {
            cin.clear();
            cin.ignore(32767, '\n');
            cout << "Incorrect. Enter True or False: ";
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

        a = isInt();
        cout << endl;

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
            {
            int b = 0;

            if (pipe.d > 0)
            {
                cout << "What to edit?" << endl << endl;

                cout << "1. Diameter" << endl;
                cout << "2. Length" << endl;
                cout << "3. Repair status" << endl;
                cout << "4. Back to Home" << endl;
                
                b = isInt();
                cout << endl;
            
                switch(b)
                {
                case 1:
                    cout << "New diameter: ";
                    pipe.d = isInt();
                    break;
                case 2:
                    cout << "New lentgh: ";
                    pipe.l = isFloat();
                    break;
                case 3:
                    cout << "Is repair? ";
                    pipe.Repair = isBool();
                    break;
                case 4:
                    break;
                }
            }
            else
            {
               cout << "No pipeline in base." << endl << endl; 
            }
            break;
            }
        case 5:
            {
            int c = 0;

            if (station.shops > 0)
            {
                cout << "What to edit?" << endl << endl;

                cout << "1. Station name" << endl;
                cout << "2. Shops" << endl;
                cout << "3. Working shops" << endl;
                cout << "4. Effectiveness" << endl;
                cout << "5. Back to Home" << endl;
                
                c = isInt();
                cout << endl;
            
                switch(c)
                {
                case 1:
                    cout << "New station name: ";
                    station.station_name = isInt();
                    break;
                case 2:
                    cout << "New number of shops: ";
                    station.shops = isInt();
                    break;
                case 3:
                {
                    while(1)
                    {
                    int sh = station.working_shops;
                    cout << "New number of working shops: ";
                    station.working_shops = isInt();
                    if (station.working_shops > station.shops)
                        {
                            cout << "Number of working shops can't be more than number of all shops. Enter again: ";
                            station.working_shops = sh;
                            
                        }
                    else break;
                    }
                    break;
                }
                case 4:
                    cout << "New effectiveness: ";
                    station.effect = isEffect();
                    break;
                case 5:
                    break;
                }
            }
            else
            {
               cout << "No station in base." << endl << endl; 
            }
            break;
            }
        case 6:
           {
            ofstream fout("data.txt", ios_base::out);
            
            if (pipe.d > 0)
            {
                fout << "PIPELINE" << endl;
                fout << "ID" << setw(10) << "Diameter" << setw(10) << "Length" << setw(10) << "Repair?" << endl;
                fout << pipe.id << setw(5) << pipe.d << setw(15) << pipe.l << setw(10) << pipe.Repair << endl << endl;
            }

            else
            {
                fout << "No pipeline in base." << endl << endl;
            }   

            if (station.shops > 0)
            {
                fout << "STATION" << endl;
                fout << "ID" << setw(15) << "Name" << setw(20) << "Shops" << setw(20) << "Working shops" << setw(20) << "Effectiveness" << endl;
                fout << station.id << setw(15) << station.station_name << setw(20) << station.shops << setw(20) << station.working_shops << setw(20) << station.effect << endl << endl;
            }
            else
            {
                fout << "No station in base." << endl << endl;
            }
            
            fout.close();
            break;
           }
        case 7:
            //fstream
            break;
        case 8:
            return 0;
            break;
        }

    } 
}
