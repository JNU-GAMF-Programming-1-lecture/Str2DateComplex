#include <iostream>
#include <string>
#include <sstream>
#include <regex>

using namespace std;

// Function to check if a given year is a leap year
bool isLeapYear(int year) 
{
  if ((year % 4 == 0 && year % 100 != 0) || (year % 400 == 0)) {
    return true;
  }
  return false;
}

// Function to check if the given day, month, and year form a valid date
bool isValidDate(int day, int month, int year) 
{
  // Check if month is between 1 and 12
  if (month < 1 || month > 12) 
    return false;

  // Days in each month, accounting for February in leap years
  int daysInMonth[] = { 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };

  // Adjust February days in case of leap year
  if (isLeapYear(year)) 
    daysInMonth[1] = 29;

  // Check if the day is valid for the given month
  if (day < 1 || day > daysInMonth[month - 1]) 
    return false;

  return true;
}

// Function to convert string to date and validate it
bool str2date(const string& dateStr, int& day, int& month, int& year) 
{
  // Regular expression to match the date format dd-mm-yyyy
  regex datePattern(R"((\d{2})-(\d{2})-(\d{4}))");

  smatch match;
  if (regex_match(dateStr, match, datePattern)) {
    // Extract day, month, and year from the matched string
    day = stoi(match[1].str());
    month = stoi(match[2].str());
    year = stoi(match[3].str());

    // Validate the date
    if (isValidDate(day, month, year)) 
      return true;
  }

  // If no match or invalid date, return false
  return false;
}

int main() 
{
  string inputDate;
  int day, month, year;

  // Ask the user for a date input
  cout << "Enter a date in the format dd-mm-yyyy: ";
  getline(cin, inputDate);

  // Pass the input string to the str2date function
  if (str2date(inputDate, day, month, year)) 
    cout << "The date is valid: " << day << "-" << month << "-" << year << endl;
  else 
    cout << "Invalid date." << endl;

  return 0; 
}
