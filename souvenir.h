
#ifndef SOUVENIR_H
#define SOUVENIR_H
#include <string>


struct souvenir{


    souvenir(){}

    souvenir(std::string name,       // IN -  name of souvenir
             std::string price){     // IN - price of souvenir
        _name = name;
        _price = price;
    }

    bool operator==(const souvenir& s){ return _name == s._name && _price == s._price; }
    bool operator!=(const souvenir& s){ return !(*this == s); };

    std::string getName(){
        return _name;
    }


    std::string getPrice(){
        return _price;
    }


    void setName(std::string name){  // IN -  name of souvenir
        _name = name;
    }


    void setPrice(std::string price){    // IN -  price of souvenir
        _price = price;
    }

private:
    std::string _name;       //ATT- name of souvenir
    std::string _price;      //ATT- price of souvenir
};


class souvenirs
{
public:

    souvenirs();

    ~souvenirs();


    souvenirs(const souvenirs& other); // IN -  souvenir arr to copy

    souvenirs& operator = (const souvenirs& other); //IN -  souvenir arr to copy

    souvenir& operator [](int index) const ;        // IN -  index to access

    bool operator == (const souvenirs& other);
    



    int getSize(){ return _size; };
    int getItemCount(souvenir itemName);
    std::string totalPrice();


    void addSouvenir(souvenir);     // IN -  souvenir to add to arr

    void removeSouvenir(int index); // IN -  index of souv to rem
    void resize();

private:
    souvenir* _s;   //ATT - souvenir array
    int _size;      //ATT - number of souvenirs
    int _capacity;
};

#endif // SOUVENIR_H
