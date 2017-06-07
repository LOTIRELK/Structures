// Assignment1.cpp : Defines the entry point for the console application.
//
//a program that reads in data from a list and answers queries about the data. 

#include "stdafx.h"
#include <iostream>
#include<iomanip>
#include<fstream>
#include<string>
using namespace std;
//declaration of functions
void displayMeterologist(void);
void displayWetDays(void);
void displaySunnyDays(void);
void displayAverageRainfall(void);
void displayHottestDay(void);
void displayShortest(void);
void loadItemsFromList(void);
void displayMenu(void);
void doQuit(void);
//nested struct date in struct Report 
typedef struct
{
	int day;
	int month;
	int year;

} Date;
struct Report
{

	Date forecast;
	char name[12];
	double sunshine;
	double rainfall;
	double temperature;

};

//global collection and data
Report d[30];
int numDays = 0,
day1,
day2,
numItemsInList,
day3,
month3,
year3,
day4,
month4,
year4;

string name;

double shortest = 0,
hottest = 0,
averageTemp = 0;

bool quitFlag = false;

int _tmain(int argc, _TCHAR* argv[])
{
	//load items from list
	loadItemsFromList();
	
	int option;
	
	do 
	{

		displayMenu();
		cout << "\tPlease enter an option. ";
		cin >> option;
		cout << "------------------------------------------------"<<endl;

		switch (option)
		{
		case 1:
			displayMeterologist();
			break;
		case 2:
			displayWetDays();
			break;
		case 3:
			displaySunnyDays();
			break;
		case 4:
			displayAverageRainfall();
			break;
		case 5:
			displayHottestDay();
			break;
		case 6:
			displayShortest();
			break;
		case 7:
			doQuit();//exit program
			break;
		default:
			cout << "Please enter a number corresponding to a number on the menu. [1-7]" << endl;
		}
	} while (!quitFlag);//continue displaying menu until quitflag not true

    return 0;
}


void displayMeterologist(void)
{
	int newLine = 0;
	cout << setw(1) <<"Please enter the name of a meterologist." << endl;
	cout << "------------------------------------------------" << endl;
	cin >> name;
	cout << "------------------------------------------------" << endl;
		for (int i = 0; i < numItemsInList; i++)//scans through list
		{
			
			if (d[i].name == name)//if name entered equals name in list
			{
				cout << setw(4)<< d[i].forecast.day << "/" << d[i].forecast.month << "/" << d[i].forecast.year ;//output the day month and year
				newLine += 1;
				if (newLine == 5)
				{
					cout << endl;
					newLine = 0;
				}
			}
 
		}
		cout << endl;
		cout << "------------------------------------------------" << endl;
		cout << setw(1) << "If no results appear the name is incorrect." << endl;
		

}


void displayWetDays(void)
{
	int newLine = 0;
	cout << setw(1) <<"This is a list of the wet days." << endl;
	cout << "------------------------------------------------" << endl;
	for (int i = 0; i < numItemsInList; i++)//scans through list
	{
		if (d[i].rainfall >= 4)//if rainfall is greater or equal to 4
		{
			cout << setw(4) << d[i].forecast.day << "/" << d[i].forecast.month << "/" << d[i].forecast.year ;//output day month year
			newLine += 1;
			if (newLine == 5)
			{
				cout << endl;
				newLine = 0;
			}
		}
	}
	cout << endl;
}


void displaySunnyDays(void)
{
	int newLine = 0;
	cout << setw(1) <<"This is a list of the sunny days." << endl;
	cout << "------------------------------------------------" << endl;
	for (int i = 0; i < numItemsInList; i++)//scans through list
	{
		if (d[i].sunshine >= 5)//if sunshine greater than or equal to 5
		{
			cout << setw(4) << d[i].forecast.day << "/" << d[i].forecast.month << "/" << d[i].forecast.year ;//output day month year
			newLine += 1;
			if (newLine == 5)
			{
				cout << endl;
				newLine = 0;
			}
		}
	}
	cout << endl;
}


void displayAverageRainfall(void)
{

	cout << setw(1) <<"Please enter the first day: ";
	cin >> day1;
	cout << endl;
	cout << setw(1) <<"Please enter the second day: ";
	cin >> day2;
	cout << "------------------------------------------------" << endl;
	numDays = day2 - day1;
	for (int i = day1-1; i <day2; i++)//start position at first date -1 to get the location in the array. Terminate when i greater than day 2
	{
		averageTemp = averageTemp + d[i].temperature;//add current temperature to averageTemp
	}
	averageTemp = averageTemp / (numDays+1);//divide averageTemp by numDays +1 to divide by number of days between day 1 and 2
	cout << setw(1) << "The average temperature between the two days is: " << fixed << setprecision(1) << averageTemp << endl;

}


void displayHottestDay(void)
{

	hottest = d[30].temperature;//hottest equals last value of temperature in array
	
	for (int i = 0; i < numItemsInList; i++)//scan array
	{
		if (d[i].temperature > hottest)//if current value is greater than hottest
		{
			hottest = d[i].temperature;//assign to hottest
			//save its day month year
			day3 = d[i].forecast.day;
			month3 = d[i].forecast.month;
			year3 = d[i].forecast.year;

		}

	}
	cout << setw(1) <<"The hottest day is "<< day3 << "/" << month3 << "/" << year3 << endl;//output result

}


void displayShortest(void)
{

	shortest =d[0].sunshine;//hottest equals first value of sunshine in array
	for (int i = 0; i < numItemsInList; i++)//scan array
	{
		if (d[i].sunshine < shortest)//if current value is less than shortest
		{
			shortest = d[i].sunshine;//assign to sunshine
			//save its day month and year
			day4 = d[i].forecast.day;
			month4 = d[i].forecast.month;
			year4 = d[i].forecast.year;
		}
	}
	cout << setw(1) << "The shortest day is " << day4 << "/" << month4 << "/" << year4 << endl;//output result

}


void loadItemsFromList(void)
{

	//read in file
	ifstream infile("List.dat");
	
	infile >> numItemsInList;//read in number of items in list
	for (int i = 0; i < numItemsInList; i++)
	{
		//read in data and assign to variables within struct
		infile >> d[i].forecast.day >> d[i].forecast.month >> d[i].forecast.year >> d[i].name >> d[i].sunshine >> d[i].rainfall
			>> d[i].temperature;
	}

}


void displayMenu(void)
{

	cout << "----------------Weather Forecast----------------" << endl;
	cout << "\t1)List dates a meterologist was on duty." << endl;
	cout << "\t2)List the wet days" << endl;
	cout << "\t3)List sunny days." << endl;
	cout << "\t4)List the average rainfall between two dates." << endl;
	cout << "\t5)List the hottest day." << endl;
	cout << "\t6)List the day with shortest sunshine." << endl;
	cout << "\t7)Exit from application." << endl;
	cout << "------------------------------------------------" << endl;

}


void doQuit(void)
{

	quitFlag = true;
	cout << "Goodbye. Have a nice day!"<<endl;

}