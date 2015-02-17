/* 
 * Text Calandar
 *
 * Makes a text calandar for a ceratin month or year. 
 *
 * @author		Daniel	Windsor 
 * @version 1.0
 */
#include <stdio.h>
#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <cmath>

using namespace std;
unsigned parseMonth(string&); 
unsigned gaussFormula(int);   

bool isLeapYear(int); 

void printYear(int);
void printMonth(string, int);
void printMonth(int, int);
void clears();


int main()
{
	string monthInput, yearInput, menuInput;

	clears();

	cout << "Calandar Displayer" << endl << endl;
	cout << "1. Display a Month" << endl;
	cout << "2. Display a Year" << endl << endl;
	cout << "Enter your Choice:";
	cin >> menuInput;

	if (menuInput == "1"){
		cout << "Enter year:";
		cin >> yearInput;
		cout << "Enter month:";
		cin >> monthInput;
		clears();
		printMonth(monthInput, stoi(yearInput));
	}

	if (menuInput == "2"){
		cout << "Enter year:";
		cin >> yearInput;
		clears();
		printYear(stoi(yearInput));
	}	

	return 0;
}
/*
 * Displays a given year by printing out all 12 months
 *
 * @param year	The year to print out
 */
void printYear(int year){
	for (unsigned i = 1; i <= 12; i++){
		printMonth(i, year);
		cout << endl << endl;
	}
}
/*
 * Displays a month
 * The month argument must be either the month number, a shortened 3 letter version
 * (e.g. JAN, FEB, MAR), or the month's full name. Not case sensitive.
 *
 * @param month	the month to display
 * @param year	the year in which you want the month from
 */
void printMonth(string month, int year){

	unsigned monthNum = parseMonth(month);
	
	unsigned daysInMonth[13] = { 0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };
	
	vector<int> monthString; // Holds what's being displayed
	unsigned daysSoFar = 0;

	if (isLeapYear(year)) daysInMonth[2]++; // Adds a day to febuary on leap years

	// Figures out how many days there's been so far in that year

	for (unsigned i = 0; i < monthNum; i++){
		daysSoFar += daysInMonth[i];
	}

	// Gets the first day of the month

	unsigned firstDay = (gaussFormula(year) + daysSoFar)%7;

	// Print the header of the calandar
	cout << month << " " << abs(year);
	if (year < 0) cout << " BCE";
	cout << endl << endl;
	cout << "  S  M Tu  W Th  F  S" << endl << " ";

	// Pads the begining of the month with 0s
	for (unsigned i = 0; i < firstDay; i++) 
		monthString.push_back(0); 

	//Fills the month with the numbered days
	for (unsigned i = 0; i < daysInMonth[monthNum] + 1; i++)
		monthString.push_back(i); 

	for (unsigned i = 1; i < monthString.size(); i++){
		if (monthString[i] < 10) cout << " "; // Adds a space to single digits
		if (monthString[i] == 0) cout << " "; // Converts padding to spaces
		else cout << monthString[i];

		if (i % 7 == 0) cout << endl; // Wraps the calandar back around
		cout << " ";
	}
	cout << endl;


}

void printMonth(int month, int year) {
	printMonth(to_string(month), year);
}
/*
 * This uses Gauss' formula to determine which day is the first day of the year
 * 0 = sunday, 1 = monday, 2 = tuesday etc..
 *
 * @param year	the year you want to know about
 *
 * @return		an unsigned int based on the first calandar day of the year. 
 */

unsigned gaussFormula(int year){
	year--; // This simplifies the next line;
	return (1 + 5 * (year % 4) + 4 * (year % 100) + 6 * (year % 400)) % 7;
}
/*
 * This determines if a year is a leap year.
 *
 * @param year	The year you want to know about
 * 
 * @return		True if leap year, false if not
 */
bool isLeapYear(int year){

	// Years divisible by 400 are leap years.
	if (year % 400 == 0) return true; 

	// Years divisible by 100, but not 400 aren't NOT leap years.
	if (year % 100 == 0) return false; 

	// If you've dealt with the cases above, years divisible by 4 are leap years.
	if (year % 4 == 0) return true;

	// But most years aren't leap years.
	return false; 
}

/*
 * This will return the month value, and change the string containing the month
 * value into full caps.
 *
 * @param &month	Call by reference the string to be parsed. 
 *
 * @return			Month represented as a number. (Jan = 1, Feb = 2 ....)
  */
// Converts the user input into a more useful thing to code with

unsigned parseMonth(string &month){

	// Convert the input to upper case 
	// This makes it look like it should on the calandar, as well as 
	// making parsing easier. 

	transform(month.begin(), month.end(), month.begin(), ::toupper); 
	
	if (month == "1" || month == "JAN" || month == "JANUARY"){ 
		month = "JANUARY";
		return 1;
	}

	if (month == "2" || month == "FEB" || month == "FEBUARY"){
		month = "FEBUARY";
		return 2;
	}

	if (month == "3" || month == "MAR" || month == "MARCH"){
		month = "MARCH";
		return 3;
	}
	if (month == "4" || month == "APR" || month == "APRIL"){
		month = "APRIL";
		return 4;
	}

	if (month == "5" || month == "MAY"){
		month = "MAY";
		return 5;
	}
	if (month == "6" || month == "JUN" || month == "JUNE"){
		month = "JUNE";
		return 6;
	}

	if (month == "7" || month == "JUL" || month == "JULY"){
		month = "JULY";
		return 7;
	}
	if (month == "8" || month == "AUG" || month == "AUGUST"){
		month = "AUGUST";
		return 8;
	}

	if (month == "9" || month == "SEP" || month == "SEPTEMBER"){
		month = "SEPTEMBER";
		return 9;
	}
	if (month == "10" || month == "OCT" || month == "OCTOBER"){
		month = "OCTOBER";
		return 10;
	}

	if (month == "11" || month == "NOV" || month == "NOVEMBER"){
		month = "NOVEMBER";
		return 11;
	}
	if (month == "12" || month == "DEC" || month == "DECEMBER"){
		month = "DECEMBER";
		return 12;
	}
	cout << "Input Proper Month!";
	exit(0);
	return 0; 
}

/*
 * Makes a bunch of blank lines to "Clear" the screen
 */
void clears(){
	for (unsigned i = 0; i < 80; i++) cout << endl;
}
