
/* ----------------
Name :- suraj jaiswal

Roll no. :- 69

Lab_6
*/

#include <iostream>
#include <vector>
#include <algorithm> // Include this header for using std::sort
#include <unistd.h>

using namespace std;

struct Item
{
    string sItemCode;
    string sName;
    float fCost;
    float fQuantity;
};

class RecordsData
{
private:
    vector<Item> aRecords;

public:
    // Initialization of values by using constructor...
    RecordsData(string sItemCode, string sName, float fCost, float fQuantity);

    //! Add Data in vector...
    void addRecord(string sItemCode, string sName, float fCost, float fQuantity)
    {
        aRecords.push_back({sItemCode, sName, fCost, fQuantity});
    }

    // Compare items based on cost
    void CompareByCost()
    {
        // Sort the vector based on the cost
        sort(aRecords.begin(), aRecords.end(), [](const Item &a, const Item &b)
             { return a.fCost < b.fCost; });
    }

    Item searchByIDItemCode(string Item_code)
    {
        for (auto &&iEle : aRecords)
        {
            if (iEle.sItemCode == Item_code)
            {
                return iEle;
            }
        }
        return {"", "", 0, 0};
    }

    // Display the data in the vector
    void showData()
    {
        for (const auto &record : aRecords)
        {
            cout << "Item Code: " << record.sItemCode << ", Name: " << record.sName
                 << ", Cost: " << record.fCost << ", Quantity: " << record.fQuantity << endl;
        }
    }

    ~RecordsData();
};

RecordsData::RecordsData(string sItemCode, string sName, float fCost, float fQuantity)
{
    // aRecords.push_back({sItemCode, sName, fCost, fQuantity});
}

RecordsData::~RecordsData()
{
}

int main()
{
    int iChioce;
    Item aData;
    string sItemCode = "";
    string sName = "";
    float fCost = 0.0;
    float fQuantity = 0.0;
    RecordsData oRecordData = RecordsData("", "", 0, 0);
    while (true)
    {

        cout << "Enter your choice \n"
             << "1) Add Record\n"
             << "2) Show Records\n"
             << "3)search Item\n"
             << "4)Sort by Cost\n"
             << "5)exit()\n"
             << endl;
        cin >> iChioce;
        switch (iChioce)
        {
        case 1:
            cout << "Item Code: ";
            cin >> sItemCode;
            cout << "Name : ";
            cin >> sName;
            cout << "Cost: ";
            cin >> fCost;
            cout << "Quantity : ";
            cin >> fQuantity;
            oRecordData.addRecord(sItemCode, sName, fCost, fQuantity);
            break;

        case 2:
            oRecordData.showData();
            break;
        case 3:
            cout << "Enter Item code you want to search: ";
            cin >> sItemCode;
            aData = oRecordData.searchByIDItemCode(sItemCode);
            if (aData.sItemCode == sItemCode)
            {
                cout << "Item Present In Record..." << endl;
                cout << "Item: " << aData.sItemCode << "\nName: " << aData.sName << "\nCost: " << aData.fCost << "\n Quantity: " << aData.fQuantity << endl;
            }
            else
            {
                cout << "Item not found..." << endl;
            }

            break;
        case 4:
            oRecordData.CompareByCost();
            break;

        case 5:
            return 1;
            break;

        default:
            break;
        }
    }

    return 0;
}
