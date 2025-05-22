#ifndef COMPUTER_H
#define COMPUTER_H

#include <string>
#include <iostream>

    class Computer;
std::ostream &operator<<(std::ostream &os, const Computer &comp);

class Computer
{
protected:
    int m_id;
    std::string m_make;
    std::string m_model;
    double m_price;
    static int s_nextId;

public:
    // Constructors
    Computer();
    Computer(std::string make, std::string model, double price);

    // Accessors
    int getId() const;
    std::string getMake() const;
    std::string getModel() const;
    double getPrice() const;

    // Mutators
    void setMake(std::string make);
    void setModel(std::string model);
    void setPrice(double price);

    // Overloaded operators
    bool operator==(const Computer &other) const;
    friend std::ostream &operator<<(std::ostream &os, const Computer &comp);
};

#endif