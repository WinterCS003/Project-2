#ifndef DATE_H
#define DATE_H
#include <string>
#include <cstdlib>
#include <iostream>
#include <cstring>
#include <vector>
using namespace std;

class Date
{
private:
    unsigned day;
    unsigned month;
    unsigned year;
    string monthName;

    unsigned daysPerMonth(unsigned m, unsigned y) const; //returns number of days for that month
    unsigned number(const string &mn) const;             //returns that month
    bool inRange(unsigned m, unsigned d);                //checks if in range

public:
    Date();
    Date(unsigned m, unsigned d, unsigned y);
    Date(const string &mn, unsigned d, unsigned y);

    string getDate();                                    //access date
    unsigned getDay();                                   //access day
    unsigned getMonth();                                 //access month
    unsigned getYear();                                  //access year
    string name(unsigned m) const;                       //return the name of month in string
    void setWhole(const string&);                        //share string to date
    void setDay(unsigned d);                             //sets date
    void setMonth(unsigned m);                           //sets month
    void setYear(unsigned y);                            //sets year
    bool isLeap(unsigned y) const;                       //check leap year

    void setDate(unsigned, unsigned, unsigned);
    bool isCorrectDate(unsigned, unsigned, unsigned);

    friend ostream& operator<<(ostream& outs, Date& target);

    bool operator==(const Date& other);
    bool operator!=(const Date& other);
    bool operator>=(const Date& other);
    bool operator<=(const Date& other);
    bool operator> (const Date& other);
    bool operator< (const Date& other);
};

#endif // DATE_H