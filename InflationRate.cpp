// InflationRate.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>

using namespace std;

//Precondition: Null.
//Postcondition : return 3 prices to main. (shared location will be addressed in main.)
void getInput(double& NowYear, double& LastYear, double& TwoYearsAgo)
{
    cout << "Enter the current price of the item, the price last year, and the price of the item two years ago: ";
    cin >> NowYear >> LastYear >> TwoYearsAgo;
}

//Precondition: gather 3 prices from main 
//Postcondition : returns 2 inflation rates and trend
void calcRate(double NowYear, double LastYear, double TwoYearsAgo, double& NowRate, double& ThenRate, string& trend)
{
    NowRate = (NowYear - LastYear) / LastYear;
    ThenRate = (LastYear - TwoYearsAgo) / TwoYearsAgo;

    if (NowRate > ThenRate) {
        trend = "Increasing";
    }
    else if (NowRate < ThenRate) {
        trend = "Decreasing";
    }
    else {
        trend = "Stable";
    }
}

//Precondition: Gather 2 rates and trend from the main which it got from calcRate
//Postcondition : display the rates between this and last year, and the rate of last year and the year before. States the trend
void displayRate(double NowRate, double ThenRate, string trend)
{
    cout << "Inflation rate for the first year: " << NowRate << endl;
    cout << "Inflation rate for the second year: " << ThenRate << endl;
    cout << "Inflation trend: " << trend << endl;
}


int main() 
{
    double NowYear, LastYear, TwoYearsAgo;
    double NowRate, ThenRate;
    string trend;

    getInput(NowYear, LastYear, TwoYearsAgo);

    calcRate(NowYear, LastYear, TwoYearsAgo, NowRate, ThenRate, trend);

    displayRate(NowRate, ThenRate, trend);

    return 0;
}
