#include "stadium.h"

stadium::stadium(){}

stadium::stadium(string name,       // IN - std name
                 string teamName,   // IN - team at std
                 string address,    // IN - std address
                 string address2,   // IN - address 2
                 string phone,      // IN - assoc. phone
                 string openDate,   // IN - day std opened
                 string capacity,   // IN - cap of std
                 string type,        // IN - std leage
                 string surface,
                 int x,
                 int y){  // IN - std surface

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

string stadium::getAllInfo(){
    stringstream ss;
    ss << getStadiumName() <<endl;
    ss << getTeamName()<<endl;
    ss << getAddress() <<endl;
    ss << "Phone: " << getPhone() <<endl;
    ss << "Founded: "<<getOpenDate() <<endl;
    ss << "Capacity: " << getCapacity() <<endl;
    ss << "League: " << getType() <<endl;
    ss << "Field surface: " << getFieldSurface() <<endl;

    return string(ss.str());
}

bool stadium::operator == (const stadium& other){
    if(_sName    == other._sName    ||
       _teamName == other._teamName ||
       _address  == other._address  ||
       _phone    == other._phone) {
       return true;
    }

    return false;
}

bool stadium::operator==(const std::string& other){
    return _sName == other;
}

