#include "date.h"
using namespace std;

Date::Date()
{
    day = 1;
    month = 1;
    monthName = "January";
    year = 2000;
}

Date::Date(unsigned m, //month
           unsigned d, //day
           unsigned y) //year
{
    if(inRange(m, d))
    {
        if(d <= daysPerMonth(m,y))
        {
            month = m;
            day = d;
            year = y;
            monthName = name(m);
        }
        else
        {
            month = m;
            day = daysPerMonth(m,y);
            year = y;
            monthName = name(month);
        }
    }
    else
    {
        if(m>12 or m<1)
        {
            month = 1;
        }
        else
        {
            if(d>daysPerMonth(m,d) or d<1)
            {
                day = 1;
            }
        }
        year = y;
    }
}

Date::Date(const string &date) //string representation of date
{
    string upperMonth[12] = {"January", "February", "March", "April",
                            "May", "June", "July", "August", "September",
                            "October", "November", "December"};
    string lowerMonth[12] = {"january", "february", "march", "april",
                             "may", "june", "july", "august", "september",
                             "october", "november", "december"};    
    string mn;
    unsigned int d;
    unsigned int y;

    mn = date.substr(0, date.find(' '));
    d = std::stoi(date.substr(date.find(' ')+1, date.find(',') - 1));
    y = std::stoi(date.substr(date.find_last_of(' ')+1));

    bool isMonthMatch;
    isMonthMatch = false;

    for (int i = 0; i < 12; i++)
    {
        if ((mn == upperMonth[i]) or (mn == lowerMonth[i]))
        {
            monthName = mn;
            month = number(monthName);
            year = y;
            isMonthMatch = true;
            break;
        }
    }
    if (isMonthMatch == false)
    {
        month = 1;
        monthName = "January";
        day = 1;
        year = 2000;
    }
    else
    {
        if(d>daysPerMonth(month,y))
        {
            day=daysPerMonth(month,y);
        }
        else
        {
            day = d;
        }
        year = y;
    }
}

void Date::setDate(unsigned m, unsigned d, unsigned y)
{
    if(inRange(m, d))
    {
        if(d <= daysPerMonth(m,y))
        {
            month = m;
            day = d;
            year = y;
            monthName = name(m);
        }
        else
        {
            month = m;
            day = daysPerMonth(m,y);
            year = y;
            monthName = name(month);
        }
    }
    else
    {
        if(m>12 or m<1)
        {
            month = 1;
        }
        else
        {
            if(d>daysPerMonth(m,d) or d<1)
            {
                day = 1;
            }
        }
        year = y;
    }
}

void Date::setWhole(const string &info)
{
    char dt[3];
    char mn[3];
    char yr[5];

    int stringIncrement;
    stringIncrement = 0;
    int position;
    position = 0;

    while (info[stringIncrement] != '\0')
    {
        if(position ==0)
        {
            for(int i=0; info[stringIncrement] != '/'; i++)
            {
                mn[i] = info[stringIncrement];
                stringIncrement++;
            }
            position++;
        }
        else if(position == 1)
        {
            for(int i=0; info[stringIncrement] != '/'; i++)
            {
                dt[i] = info[stringIncrement];
                stringIncrement++;
            }
            position++;
        }
        else if(position == 2)
        {
            for(int i=0; info[stringIncrement] != '\0'; i++)
            {
                yr[i] = info[stringIncrement];
                stringIncrement++;
            }
            position++;
        }
        stringIncrement++;
    }

    unsigned m;
    unsigned d;
    unsigned y;

    m = atoi(mn);
    d = atoi(dt);
    y = atoi(yr);

    if(inRange(m, d))
    {
        if(d <= daysPerMonth(m,y))
        {
            month = m;
            day = d;
            year = y;
            monthName = name(m);
        }
        else
        {
            month = m;
            day = daysPerMonth(m,y);
            year = y;
            monthName = name(month);
        }
    }
    else
    {
        if(m>12 or m<1)
        {
            month = 1;
        }
        else
        {
            if(d>daysPerMonth(m,d) or d<1)
            {
                day = 1;
            }
        }
        year = y;
    }
}

void Date::setMonth(unsigned int m)
{
    month = m;
}

void Date::setDay(unsigned int d)
{
    day = d;
}

void Date::setYear(unsigned int y)
{
    year = y;
}

bool Date::isLeap(unsigned int year) const
{
    if(((year%4)==0) and ((year%100)!=0))
    {
        return true;
    }
    else if(((year%4)==0) and ((year%400)==0))
    {
        return true;
    }
    else
    {
        return false;
    }
}

unsigned Date::daysPerMonth(unsigned m,         //month
                            unsigned y) const   //year
{
    if (m==2)
    {
        if (isLeap(y))
        {
            return 29;
        }
        else
        {
            return 28;
        }
    }
    else if ((m==1)or(m==3)or
             (m==5)or(m==7)or
             (m==8)or(m==10)or
             (m==12))
    {
        return 31;
    }
    else if((m==3)or(m==4)or
            (m==6)or(m==9)or
            (m==11))
    {
        return 30;
    }

    return 31;
}

string Date::name(unsigned int m) const
{
    if(m == 1)
    {
        return "January";
    }
    if(m == 2)
    {
        return "February";
    }
    if(m == 3)
    {
        return "March";
    }
    if(m == 4)
    {
        return "April";
    }
    if(m == 5)
    {
        return "May";
    }
    if(m == 6)
    {
        return "June";
    }
    if(m == 7)
    {
        return "July";
    }
    if(m == 8)
    {
        return "August";
    }
    if(m == 9)
    {
        return "September";
    }
    if(m == 10)
    {
        return "October";
    }
    if(m == 11)
    {
        return "November";
    }
    if(m == 12)
    {
        return "December";
    }

    return "January";
}

unsigned Date::number(const string& mn) const
{
    if ((mn == "January") or (mn == "january"))
    {
        return 1;
    }
    else if ((mn == "February") or (mn == "february"))
    {
        return 2;
    }
    else if ((mn == "March") or (mn == "march"))
    {
        return 3;
    }
    else if ((mn == "April") or (mn == "april"))
    {
        return 4;
    }
    else if ((mn == "May") or (mn == "may"))
    {
        return 5;
    }
    else if ((mn == "June") or (mn == "june"))
    {
        return 6;
    }
    else if ((mn == "July") or (mn == "july"))
    {
        return 7;
    }
    else if ((mn == "August") or (mn == "august"))
    {
        return 8;
    }
    else if ((mn == "September") or (mn == "september"))
    {
        return 9;
    }
    else if ((mn == "October") or (mn == "october"))
    {
        return 10;
    }
    else if ((mn == "November") or (mn == "november"))
    {
        return 11;
    }
    else if ((mn == "December") or (mn == "december"))
    {
        return 12;
    }
    return 1;
}

string Date::getDate() const
{
    string dy;
    string mn;
    string yr;

    dy = to_string(day);
    mn = to_string(month);
    yr = to_string(year);

    return monthName + " " + dy + ", " + yr;
}

unsigned Date::getDay() const
{
    return day;
}
unsigned Date::getMonth() const
{
    return month;
}
unsigned Date::getYear() const
{
    return year;
}

bool Date::inRange(unsigned int m, unsigned int d)
{
    if((m<=12 and m>=1) and (d<=31 and d>=1))
    {
        return true;
    }

    return false;
}

ostream& operator<<(ostream& outs, Date& target)
{
    outs << target.month << "/" << target.day << "/" << target.year ;

    return outs;
}

bool Date::operator!=(const Date &other)
{
    if(year != other.year)
    {
        return true;
    }
    else if(month!=other.month)
    {
        return true;
    }
    else if (day != other.day)
    {
        return true;
    }
    else
    {
        return false;
    }
}

bool Date::operator==(const Date &other)
{
    if((month==other.month)and (day==other.day)
            and (year==other.year))
    {
        return true;
    }
    else
    {
        return false;
    }
}

bool Date::operator>=(const Date &other)
{
    if(year > other.year)
    {
        return true;
    }

    if(year == other.year)
    {
        if (month == other.month)
        {
            if (day >= other.day)
                return true;
            else
                return false;
        }
    }

    if(year == other.year)
    {
        if (month >= other.month)
        {
            return true;
        }
        else
        {
            return false;
        }
    }

    return false;
}

bool Date::operator<=(const Date &other)
{
    if(year < other.year)
    {
        return true;
    }

    if(year == other.year)
    {
        if (month == other.month)
        {
            if (day <= other.day)
                return true;
            else
                return false;
        }
    }

    if(year == other.year)
    {
        if (month <= other.month)
        {
            return true;
        }
        else
        {
            return false;
        }
    }

    return false;
}

bool Date::operator>(const Date &other)
{

    if(year > other.year)
    {
        return true;
    }
    else if(year < other.year)
    {
        return false;
    }

    if(year == other.year)
    {
        if(month > other.month)
        {
            return true;
        }
        else
        {
            return false;
        }
    }

    if(year == other.year)
    {
        if(month == other.month)
        {
            if (day > other.day)
            {
                return true;
            }
            else
            {
                return false;
            }
        }
    }
    return false;
}
bool Date::operator<(const Date &other)
{
    if(year < other.year)
    {
        return true;
    }
    else if(year < other.year)
    {
        return false;
    }

    if(year == other.year)
    {
        if(month < other.month)
        {
            return true;
        }
        else
        {
            return false;
        }
    }

    if(year == other.year)
    {
        if(month == other.month)
        {
            if (day < other.day)
            {
                return true;
            }
            else
            {
                return false;
            }
        }
    }
    return false;
}


bool Date::isCorrectDate(unsigned month, unsigned date, unsigned year)
{
    if(month <1 && month >12)
    {
        return false;
    }
    else
    {
        int correctTotalDate;
        correctTotalDate = daysPerMonth(month, year);
        if(date > correctTotalDate)
        {
            return false;
        }
    }
    return true;
}
