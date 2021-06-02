#ifndef STADIUM_H
#define STADIUM_H

#include <iostream>
#include <sstream>

using namespace std;

class stadium
{
public:

    /******************
     ** CONSTRUCTURS **
     ******************/
    stadium();
    stadium(string,     // IN - stadium name to set
            string,     // IN - team name to set
            string,     // IN - address to set
            string,     // IN - address 2
            string,     // IN - phone to set
            string,     // IN - open date to set
            string,     // IN - capacity to set
            string,     // IN - league to set
            string,     // IN - field surface to set
            int x = 0,  // IN - x coordinate
            int y = 0); // IN - y coordinate

    /***************
     ** ACCESSORS **
     ***************/
    bool operator == (const stadium& other); // IN - stadium to copy
    bool operator == (const std::string& other); // IN - stadium to copy

    string getStadiumName() const {
        return _sName;
    }

    string getTeamName() const {
        return _teamName;
    }

    string getAddress() const {
        return _address;
    }

    string getAddress2() const {
        return _address2;
    }

    string getPhone() const {
        return _phone;
    }

    string getOpenDate() const {
        return _openDate;
    }

    string getCapacity() const {
        return _capacity;
    }

    string getType() const {
        return _type;
    }
    string getFieldSurface() const {
        return _surface;
    }


    int getXCoor() const
    {
        return xPixel;
    }

    int getYCoor() const
    {
        return yPixel;
    }

    string getAllInfo() const;

    friend ostream& operator << (ostream& outs,         // OUT -  output stream
                                 const stadium& s){     // IN -  stadium to out
        outs << s._sName;
        return outs;
    }

    /**************
     ** MUTATORS **
     **************/
    void setName(string name){          // IN - stadium name to set
        _sName = name;
    }

    void setTeamName(string tname){     // IN - team name to set
        _teamName = tname;
    }

    void setAddress(string address){    // IN -  address to set
        _address = address;
    }

    void setAddress2(string address2){
        _address2 = address2;
    }

    void setphone(string phone){        // IN -  phone to set
        _phone = phone;
    }

    void setOpenDate(string openDate){  // IN -  openDate to set
        _openDate = openDate;
    }

    void setCapacity(string capacity){  // IN -  capacity to set
        _capacity = capacity;
    }

    void setType(string type){          // IN -  type to set
        _type = type;
    }

    void setFieldSurface(string surface){   // IN -  surface to set
        _surface = surface;
    }

    void setXCoor(int xpos)             // IN -  x pos to set(for map)
    {
        xPixel = xpos;
    }

    void setYCoor(int ypos)             // IN -  y pos to set(for map)
    {
        yPixel = ypos;
    }


private:
    string _sName;      //ATT - stadium name
    string _teamName;   //ATT - team name
    string _address;    //ATT - stadium address
    string _address2;   //ATT - second line of address
    string _phone;      //ATT - stadium phone
    string _openDate;   //ATT - stadium open date
    string _capacity;   //ATT - stadium capacity
    string _type;       //ATT - stadium league type
    string _surface;    //ATT - stadium field surface

    int xPixel;         //ATT - x coor of stadium on map
    int yPixel;         //ATT - y coor of stadium on map
};

/****************************************************************
 * stadium Class
 *   This class represents a stadium object. It manages all
 *   information on the stadium as well as its coordinates.
 ***************************************************************/


/******************************
 ** CONSTRUCTOR & DESTRUCTOR **
 ******************************/

/****************************************************************
 * stadium(string,
           string,
           string,
           string,
           string,
           string,
           string,
           string,
           string,
           int x = 0,
           int y = 0);
 *   Constructor; Initialize a stadium object with parameters
 *   Parameters:
 *          string // IN - stadium name to set
 *          string // IN - team name to set
 *          string // IN - address to set
 *          string // IN - address 2
 *          string // IN - phone to set
 *          string // IN - open date to set
 *          string // IN - capacity to set
 *          string // IN - league to set
 *          string // IN - field surface to set
 *          int x   // IN - x coordinate
 *          int y   // IN - y coordinate
 *   Return: none
 ***************************************************************/


 /***************
  ** ACCESSORS **
  ***************/

/****************************************************************
 * bool operator==(const stadium& other) const;
 *
 *   Accessor; This method will return true if the given stadium
 *             is identical to the calling stadium
 * --------------------------------------------------------------
 *   Parameters: other (const stadium) // IN - stadium to compare
 * --------------------------------------------------------------
 *   Return: bool - true if the two are identical false otherwise
 ***************************************************************/

/****************************************************************
 * bool operator==(const std::string& other) const;
 *
 *   Accessor; This method will return true if the given stadium
 *             name is identical to the calling stadium name
 * --------------------------------------------------------------
 *   Parameters: other (const std::string&) // IN - name to check
 * --------------------------------------------------------------
 *   Return: bool - true if the two are identical false otherwise
 ***************************************************************/

/****************************************************************
 * string getStadiumName() const;
 *
 *   Accessor; This method will return the stadium name
 * --------------------------------------------------------------
 *   Parameters: none
 * --------------------------------------------------------------
 *   Return: _sName (std::string) // stadium name
 ***************************************************************/

/****************************************************************
 * string getTeamName() const;
 *
 *   Accessor; This method will return the team name
 * --------------------------------------------------------------
 *   Parameters: none
 * --------------------------------------------------------------
 *   Return: _teamName (std::string) // team name
 ***************************************************************/

/****************************************************************
 * string getAddress() const;
 *
 *   Accessor; This method will return the stadium address
 * --------------------------------------------------------------
 *   Parameters: none
 * --------------------------------------------------------------
 *   Return: _address (std::string) // stadium address
 ***************************************************************/

/****************************************************************
 * string getAddress2() const;
 *
 *   Accessor; This method will return the stadium address 2
 * --------------------------------------------------------------
 *   Parameters: none
 * --------------------------------------------------------------
 *   Return: _address2 (std::string) // stadium address2
 ***************************************************************/

/****************************************************************
 * string getPhone() const;
 *
 *   Accessor; This method will return the stadium phone number
 * --------------------------------------------------------------
 *   Parameters: none
 * --------------------------------------------------------------
 *   Return: _phone (std::string) // stadium phone number
 ***************************************************************/

/****************************************************************
 * string getOpenDate() const;
 *
 *   Accessor; This method will return the stadium open date
 * --------------------------------------------------------------
 *   Parameters: none
 * --------------------------------------------------------------
 *   Return: _openDate (std::string) // stadium founding date
 ***************************************************************/

/****************************************************************
 * string getCapacity() const;
 *
 *   Accessor; This method will return the stadium capacity
 * --------------------------------------------------------------
 *   Parameters: none
 * --------------------------------------------------------------
 *   Return: _capacity (std::string) // stadium capacity
 ***************************************************************/

/****************************************************************
 * string getType() const;
 *
 *   Accessor; This method will return the stadium type
 * --------------------------------------------------------------
 *   Parameters: none
 * --------------------------------------------------------------
 *   Return: _type (std::string) // stadium type
 ***************************************************************/

/****************************************************************
 * string getFieldSurface() const;
 *
 *   Accessor; This method will return the stadium surface
 * --------------------------------------------------------------
 *   Parameters: none
 * --------------------------------------------------------------
 *   Return: _surface (std::string) // stadium surface
 ***************************************************************/

/****************************************************************
 * int getXCoor() const;
 *
 *   Accessor; This method will return the stadium x-coordinate
 * --------------------------------------------------------------
 *   Parameters: none
 * --------------------------------------------------------------
 *   Return: xPixel (int) // stadium x-coordinate
 ***************************************************************/

/****************************************************************
 * int getYCoor() const;
 *
 *   Accessor; This method will return the stadium y-coordinate
 * --------------------------------------------------------------
 *   Parameters: none
 * --------------------------------------------------------------
 *   Return: yPixel (int) // stadium y-coordinate
 ***************************************************************/

/****************************************************************
 * string getAllInfo() const;
 *
 *   Accessor; This method will return all stadium info as a
 *             string
 * --------------------------------------------------------------
 *   Parameters: none
 * --------------------------------------------------------------
 *   Return: std::string // all stadium info
 ***************************************************************/

/*******************************************************************
 * ostream& operator<<(ostream& outs,
 *                     const stadium& s);
 *
 *   Accessor; This method will output stadium name to the
 *             stream output.
 *------------------------------------------------------------------
 *   Parameter: outs (ostream&)    // IN – output stream to write to
 *              s (const stadium&) // IN - stadium to output
 *------------------------------------------------------------------
 *   Return: none
 *******************************************************************/


/**************
 ** MUTATORS **
 **************/

/*******************************************************************
 * void setName(string name);
 *
 *   Mutator; This method will update the _sName attribute to the
 *            parameter
 *------------------------------------------------------------------
 *   Parameter: name (string) // IN – new name
 *------------------------------------------------------------------
 *   Return: none
 *******************************************************************/

/*******************************************************************
 * void setTeamName(string tname);
 *
 *   Mutator; This method will update the _teamName attribute to the
 *            parameter
 *------------------------------------------------------------------
 *   Parameter: tname (string) // IN – new team name
 *------------------------------------------------------------------
 *   Return: none
 *******************************************************************/

/*******************************************************************
 * void setAddress(string address);
 *
 *   Mutator; This method will update the _address attribute to the
 *            parameter
 *------------------------------------------------------------------
 *   Parameter: address (string) // IN – new address
 *------------------------------------------------------------------
 *   Return: none
 *******************************************************************/

/*******************************************************************
 * void setAddress2(string address2);
 *
 *   Mutator; This method will update the _address2 attribute to the
 *            parameter
 *------------------------------------------------------------------
 *   Parameter: address2 (string) // IN – new address2
 *------------------------------------------------------------------
 *   Return: none
 *******************************************************************/

/*******************************************************************
 * void setPhone(string phone);
 *
 *   Mutator; This method will update the _phone attribute to the
 *            parameter
 *------------------------------------------------------------------
 *   Parameter: phone (string) // IN – new phone number
 *------------------------------------------------------------------
 *   Return: none
 *******************************************************************/

/*******************************************************************
 * void setOpenDate(string openDate);
 *
 *   Mutator; This method will update the _openDate attribute to the
 *            parameter
 *------------------------------------------------------------------
 *   Parameter: openDate (string) // IN – new founding date
 *------------------------------------------------------------------
 *   Return: none
 *******************************************************************/

/*******************************************************************
 * void setCapacity(string capacity);
 *
 *   Mutator; This method will update the _capacity attribute to the
 *            parameter
 *------------------------------------------------------------------
 *   Parameter: capacity (string) // IN – new capacity
 *------------------------------------------------------------------
 *   Return: none
 *******************************************************************/

/*******************************************************************
 * void setType(string type);
 *
 *   Mutator; This method will update the _type attribute to the
 *            parameter
 *------------------------------------------------------------------
 *   Parameter: type (string) // IN – new type
 *------------------------------------------------------------------
 *   Return: none
 *******************************************************************/

/*******************************************************************
 * void setFieldSurface(string surface);
 *
 *   Mutator; This method will update the _surface attribute to the
 *            parameter
 *------------------------------------------------------------------
 *   Parameter: surface (string) // IN – new surface
 *------------------------------------------------------------------
 *   Return: none
 *******************************************************************/

/*******************************************************************
 * void setXCoor(int xpos);
 *
 *   Mutator; This method will update the xPixel attribute to the
 *            parameter
 *------------------------------------------------------------------
 *   Parameter: xpos (int) // IN – new x-coordinate
 *------------------------------------------------------------------
 *   Return: none
 *******************************************************************/

/*******************************************************************
 * void setYCoor(int ypos);
 *
 *   Mutator; This method will update the yPixel attribute to the
 *            parameter
 *------------------------------------------------------------------
 *   Parameter: ypos (int) // IN – new y-coordinate
 *------------------------------------------------------------------
 *   Return: none
 *******************************************************************/

#endif // STADIUM_H
