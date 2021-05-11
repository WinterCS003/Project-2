#include "souvenir.h"

souvenirs::souvenirs(){
    _s = new souvenir[50];
    _capacity = 50;
}

souvenirs::~souvenirs(){
    delete [] _s;
}

souvenirs::souvenirs(const souvenirs& other){
    _capacity = other._capacity;
    _s = new souvenir[_capacity];
    for(int i = 0; i < other._size; i++){
        _s[i] = other[i];
    }
}

souvenirs& souvenirs::operator = (const souvenirs& other){
    if(_capacity < other._capacity){
        resize();
    }

    for(int i = 0; i < other._size; i++){
        _s[i] = other[i];
    }
}

souvenir& souvenirs::operator[](int index) const {
    return _s[index];
}

void souvenirs::addSouvenir(souvenir addMe){
    if(_size == _capacity){
        resize();
    }
    _s[_size++] = addMe;
}

void souvenirs::removeSouvenir(int index){
    if(index < 0 || index >= _size){
        return; // error
    }

    _s[index] = _s[_size--];
}

int souvenirs::getItemCount(souvenir itemName){
    int count = 0;
    for(int i = 0; i < _size; i++){
        if(_s[i] == itemName){
            count++;
        }
    }

    return count;
}

bool souvenirs::operator == (const souvenirs& other){
    for(int i = 0; i < _size; i++){
        if(_s[i] != other[i]){
            return false;
        }
    }

    return true;
}

void souvenirs::resize(){
    souvenir* temp = new souvenir[2*_capacity];
    for(int i = 0; i < _capacity; i++){
        temp[i] = _s[i];
    }

    delete [] _s;
    _s = temp;
}

std::string souvenirs::totalPrice(){
    double total = 0.0;
    for(int i = 0; i < _size; i++){
        total += std::stod(_s[i].getPrice())*_s[i].getQuantity();
    }

    std::string stotal = "$" + std::to_string(total);
    stotal = stotal.substr(0, stotal.find('.')+3);

    return stotal;
}

std::string souvenirs::printReport(){
    std::string output = "----------Begin Report---------\n\n";
    if(_size == 0){
        output += "No Purchases Made";
    } else{
        for(int i = 0; i < _size; i++){
            output += "Name: ";
            output += _s[i].getName();
            output += "\nPrice: $";
            output += _s[i].getPrice();
            output += "\nQuantity Purchased: ";
            output += std::to_string(_s[i].getQuantity());
            output += "\n\n";
        }
    }
    output += "\n\n---------End Report---------";

    return output;
}

int souvenirs::getIndex(std::string name){
    for(int i = 0; i < _size; i++){
        if(_s[i].getName() == name){
            return i;
        }
    }

    return -1;
}
