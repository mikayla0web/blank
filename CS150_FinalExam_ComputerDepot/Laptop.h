#ifndef LAPTOP_H
#define LAPTOP_H

#include "Computer.h"
#include <string>
#include <iostream>

class Laptop;
std::ostream &operator<<(std::ostream &os, const Laptop &lap);

class Laptop : public Computer
{
private:
    double m_batteryLife; // hours
    double m_weight;      // pounds

public:
    // Constructors
    Laptop();
    Laptop(std::string make, std::string model, double price, double batteryLife, double weight);

    // Accessors
    double getBatteryLife() const;
    double getWeight() const;

    // Mutators
    void setBatteryLife(double batteryLife);
    void setWeight(double weight);

    // Overloaded operators
    bool operator==(const Laptop &other) const;
    friend std::ostream &operator<<(std::ostream &os, const Laptop &lap);
};

#endif