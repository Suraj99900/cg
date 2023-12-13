
/* ----------------
Name :- suraj jaiswal

Roll no. :- 69

Lab_7
*/

#include <iostream>
#include <map>
#include <algorithm>
#include <sys/wait.h>
#include <stdlib.h>

using namespace std;

class Population
{
private:
    map<string, int> states;

public:
    Population();
    ~Population();

    // check state already present or not
    bool checkState(string sState);

    // add state population
    void addStatePopulation(string sState, int iPopulation);

    void updateStatePopultation(string sState, int iPopulation);

    auto fetchByStateName(string sState);
    void fetchAll();
};

bool Population::checkState(string sState)
{
    for (auto &&iEle : states)
    {
        if (iEle.first == sState)
        {
            return true;
        }
    }

    return false;
}

void Population::addStatePopulation(string sState, int iPopulation)
{
    if (checkState(sState))
    {
        updateStatePopultation(sState, iPopulation);
    }
    else
    {
        states.insert(pair<string, int>(sState, iPopulation));
    }
}

void Population::updateStatePopultation(string sState, int iPopulation)
{
    states[sState] = iPopulation;
}

auto Population::fetchByStateName(string sState)
{
    return states[sState];
}

void Population::fetchAll()
{
    for (auto &&iEle : states)
    {
        cout << iEle.first << " : " << iEle.second << endl;
    }
}

Population::Population()
{
    cout << "Program Initialization..." << endl;
    cout << "Wait Loading..." << endl;
    sleep(1);
}

Population::~Population()
{
    cout << "Program Destroy..." << endl;
    cout << "Wait Loading..." << endl;
    sleep(1);
}

int main()
{
    Population population;

    while (true)
    {
        int choice;
        string state;
        int iPopulation;

        cout << "\nEnter your choice:\n"
             << "1. Add/Update State Population\n"
             << "2. Fetch Population by State Name\n"
             << "3. Fetch All Populations\n"
             << "4. Exit\n";
        cin >> choice;

        switch (choice)
        {
        case 1:
            cout << "Enter state name: ";
            cin >> state;
            cout << "Enter population: ";
            cin >> iPopulation;
            population.addStatePopulation(state, iPopulation);
            break;

        case 2:
            cout << "Enter state name to fetch population: ";
            cin >> state;
            if (population.checkState(state))
            {
                cout << "Population of " << state << ": " << population.fetchByStateName(state) << endl;
            }
            else
            {
                cout << "State not found." << endl;
            }
            break;

        case 3:
            cout << "All Populations:\n";
            population.fetchAll();
            break;

        case 4:
            cout << "Exiting program.\n";
            return 0;

        default:
            cout << "Invalid choice. Please try again.\n";
        }
    }

    return 0;
}