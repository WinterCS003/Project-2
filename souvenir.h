
#ifndef SOUVENIR_H
#define SOUVENIR_H
#include <string>


struct souvenir{


    souvenir(){}

    souvenir(std::string name,       // IN -  name of souvenir
             std::string price,
             std::string description){     // IN - price of souvenir
        _name = name;
        _price = price;
        _description = description;
        _quantity = 0;
    }

    bool operator==(const souvenir& s){ return _name == s._name && _price == s._price; }
    bool operator!=(const souvenir& s){ return !(*this == s); };

    std::string getName(){
        return _name;
    }

    std::string getPrice(){
        return _price;
    }

    std::string getDescription(){
        return _description;
    }

    int getQuantity(){
        return _quantity;
    }

    void setName(std::string name){  // IN -  name of souvenir
        _name = name;
    }

    void setPrice(std::string price){    // IN -  price of souvenir
        _price = price;
    }

    void setDescription(std::string description){    // IN -  description of souvenir
        _description = description;
    }

    void setQuantity(int quantity){
        _quantity = quantity;
    }

    void addQuantity(){
        _quantity++;
    }

private:
    std::string _name;       //ATT- name of souvenir
    std::string _price;      //ATT- price of souvenir
    std::string _description;      //ATT- description of souvenir
    int _quantity = 0; // number of souvenirs bought
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
    int getIndex(std::string name);


    void addSouvenir(souvenir);     // IN -  souvenir to add to arr

    void removeSouvenir(int index); // IN -  index of souv to rem
    void resize();

    std::string printReport();

private:
    souvenir* _s;   //ATT - souvenir array
    int _size;      //ATT - number of souvenirs
    int _capacity;
};

#endif // SOUVENIR_H
