#include "stadium.h"

/**********************************************************
 *
 * CONSTRUCTOR stadium
 *_________________________________________________________
 * This constructor receives nothing and creates an empty
 * stadium object.
 *_________________________________________________________
 * PRE-CONDITIONS
 *   none
 *
 * POST-CONDITIONS
 *   An empty stadium object is created.
 ***********************************************************/
stadium::stadium(){}

/**********************************************************
 *
 * CONSTRUCTOR stadium
 *_________________________________________________________
 * This function receives all needed stadium information
 * and creates a new stadium with the information.
 *_________________________________________________________
 * PRE-CONDITIONS
 *   The following need previously defined values:
 *     string name,     // IN - std name
 *     string teamName, // IN - team at std
 *     string address,  // IN - std address
 *     string address2, // IN - address 2
 *     string phone,    // IN - assoc. phone
 *     string openDate, // IN - day std opened
 *     string capacity, // IN - cap of std
 *     string type,     // IN - std leage
 *     string surface,  // IN - std surface
 *     int x,           // IN - x-coordinate
 *     int y            // IN - y-coordinate
 *
 * POST-CONDITIONS
 *   This function will create a new stadium with the
 *   given information.
 ***********************************************************/
stadium::stadium(string name,     // IN - std name
                 string teamName, // IN - team at std
                 string address,  // IN - std address
                 string address2, // IN - address 2
                 string phone,    // IN - assoc. phone
                 string openDate, // IN - day std opened
                 string capacity, // IN - cap of std
                 string type,     // IN - std leage
                 string surface,  // IN - std surface
                 int x,           // IN - x-coordinate
                 int y)           // IN - y-coordinate
{
    _sName = name;
    _teamName = teamName;
    _address = address;
    _address2 = address2;
    _phone = phone;
    _openDate = openDate;
    _capacity = capacity;
    _type = type;
    _surface = surface;
    xPixel = x;
    yPixel = y;
}

/**********************************************************
 *
 * FUNCTION getAllInfo
 *_________________________________________________________
 * This function receives nothing and returns all stadium
 * info as a string.
 *_________________________________________________________
 * PRE-CONDITIONS
 *   none
 *
 * POST-CONDITIONS
 *   This function will output all stadium info.
 ***********************************************************/
string stadium::getAllInfo() const {
    stringstream ss;
    ss << getStadiumName() << endl;
    ss << getTeamName()<< endl;
    ss << getAddress() << endl;
    ss << getAddress2() << endl;
    ss << "Phone: " << getPhone() << endl;
    ss << "Founded: "<<getOpenDate() << endl;
    ss << "Capacity: " << getCapacity() << endl;
    ss << "League: " << getType() << endl;
    ss << "Field surface: " << getFieldSurface() << endl;

    return string(ss.str());
}

/**********************************************************
 *
 * FUNCTION operator==
 *_________________________________________________________
 * This function receives a stadium and checks if the
 * calling stadium is equal to the parameter.
 *_________________________________________________________
 * PRE-CONDITIONS
 *   The following need previously defined values:
 *     other: const stadium& // IN - stadium to compare
 *
 * POST-CONDITIONS
 *     This function will return true if the two stadiums
 *     are the same, false otherwise
 ***********************************************************/
bool stadium::operator == (const stadium& other){
    if(_sName    == other._sName    ||
       _teamName == other._teamName ||
       _address  == other._address  ||
       _phone    == other._phone) {
       return true;
    }

    return false;
}

/**********************************************************
 *
 * FUNCTION operator==
 *_________________________________________________________
 * This function receives a std::string and checks if the
 * calling stadium name is equal to the parameter.
 *_________________________________________________________
 * PRE-CONDITIONS
 *   The following need previously defined values:
 *     other: const std::string& // IN - name to compare
 *
 * POST-CONDITIONS
 *     This function will return true if the two stadium
 *     names are the same, false otherwise
 ***********************************************************/
bool stadium::operator==(const std::string& other){
    return _sName == other;
}

