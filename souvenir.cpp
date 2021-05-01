#include "souvenir.h"
souvenirs::souvenirs(){

}

souvenirs::~souvenirs(){

}

souvenirs::souvenirs(const souvenirs& other){

}

souvenirs& souvenirs::operator = (const souvenirs& other){

}

souvenir& souvenirs::operator [](int index){

}

int souvenirs::getSize(){
}

void souvenirs::addSouvenir(souvenir addMe){
    souvenirs temp(*this);
}
void souvenirs::removeSouvenir(int index){
    assert(this->_size >=1);

}

int souvenirs::getItemCount(string itemName){

}

bool souvenirs::operator == (const souvenirs& other){

}
