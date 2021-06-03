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

public:
    Date();
    Date(unsigned m, unsigned d, unsigned y);
    Date(const string &mn);

    string getDate() const;                              //access date
    unsigned getDay() const;                             //access day
    unsigned getMonth() const;                           //access month
    unsigned getYear() const;                            //access year
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

    friend std::ostream& operator<<(std::ostream& os, const Date& d){
        os << d.getDate();
        return os;
    }

    unsigned daysPerMonth(unsigned m, unsigned y) const; //returns number of days for that month
    unsigned number(const string &mn) const;             //returns that month
    bool inRange(unsigned m, unsigned d);                //checks if in range

};

/****************************************************************
 * Date(unsigned m, unsigned d, unsigned y);
 *
 *   constructor: Set date
 * --------------------------------------------------------------
 *   Parameters: unsigned m unsigned d unsigned y
 * --------------------------------------------------------------
 *   Return: None
 ***************************************************************/


/****************************************************************
 * void setWhole(const string)
 *
 *   Mutator: share string, construct date
 * --------------------------------------------------------------
 *   Parameters: const string
 * --------------------------------------------------------------
 *   Return: none
 ***************************************************************/
/****************************************************************
 * void setDay(unsigned d);
 *
 *   Mutator: set day
 * --------------------------------------------------------------
 *   Parameters: unsigned d
 * --------------------------------------------------------------
 *   Return: none
 ***************************************************************/

/****************************************************************
 * void setMonth(unsigned m);
 *
 *   Mutator: set month
 * --------------------------------------------------------------
 *   Parameters: unsigned m
 * --------------------------------------------------------------
 *   Return: none
 ***************************************************************/

/****************************************************************
 * void setYear(unsigned y);
 *
 *   Mutator: set year
 * --------------------------------------------------------------
 *   Parameters: unsigned y
 * --------------------------------------------------------------
 *   Return: none
 ***************************************************************/

/****************************************************************
 * unsigned daysPerMonth(unsigned m, unsigned y) const;
 *
 *   Accessor: return days permonth
 * --------------------------------------------------------------
 *   Parameters: unsigned m, unsigned y
 * --------------------------------------------------------------
 *   Return: unsigned
 ***************************************************************/

/****************************************************************
 * unsigned number(const string &mn) const;
 *
 *   Accessor: return number of that month
 * --------------------------------------------------------------
 *   Parameters: const string &mn
 * --------------------------------------------------------------
 *   Return:unsigned
 ***************************************************************/

/****************************************************************
 * string name(unsigned m) const;
 *
 *   Accessor: return month in string
 * --------------------------------------------------------------
 *   Parameters: unsigned m
 * --------------------------------------------------------------
 *   Return: string
 ***************************************************************/

/****************************************************************
 * bool isLeap(unsigned y) const;
 *
 *   Accessor: check if its leap year
 * --------------------------------------------------------------
 *   Parameters: unsigned y
 * --------------------------------------------------------------
 *   Return: unsigned
 ***************************************************************/

/****************************************************************
 * bool isCorrectDate(unsigned, unsigned, unsigned);
 *
 *   Accessor: check whether the date is correct
 * --------------------------------------------------------------
 *   Parameters: unsigned, unsigned, unsigned
 * --------------------------------------------------------------
 *   Return: unsigned
 ***************************************************************/

#endif // DATE_H
