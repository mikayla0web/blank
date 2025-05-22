/*****************************************************************************
 * AUTHOR: Mikayla Weber
 * COURSE: CS 150 : C++ Programming 1
 * SECTION: online
 * IC (PROJECT)#: Final Exam
 * LAST MODIFIED: 5/21/25
 *****************************************************************************/
/*****************************************************************************
 * Laptop Class
 *****************************************************************************
 * PROGRAM DESCRIPTION:
 * Implements the methods for the Laptop class, including constructors,
 * accessors, mutators, and overloaded operators.
 *****************************************************************************
 * ALGORITHM:
 * 1. Implement default constructor: calls Computer default constructor and
 *    initializes Laptop-specific members to 0.0.
 * 2. Implement parameterized constructor: calls Computer parameterized constructor
 *     to initialize base class members (which also assigns unique ID) and then
 *    initializes Laptop-specific members (battery life, weight).
 * 3. Implement accessor methods for battery life and weight.
 * 4. Implement mutator methods for battery life and weight.
 * 5. Implement overloaded equality (==) operator to compare two Laptop objects,
 *    including base class parts.
 * 6. Implement overloaded stream insertion (<<) operator to print Laptop
 *    object details (including inherited Computer fields) in a formatted way.
 *****************************************************************************
 * ALL IMPORTED LIBRARIES NEEDED AND PURPOSE:
 * "Laptop.h"   - Contains the declaration of the Laptop class.
 * <iostream>   - For std::ostream, std::fixed, std::left, std::right.
 * <string>     - For std::string.
 * <iomanip>    - For std::setw, std::setprecision.
 *****************************************************************************/

#include "Laptop.h"
#include <iostream>
#include <string>
#include <iomanip>

// Default constructor
Laptop::Laptop() : Computer(), m_batteryLife(0.0), m_weight(0.0)
{

}

// Parameterized constructor
Laptop::Laptop(std::string make, std::string model, double price, double batteryLife, double weight)
    : Computer(make, model, price), m_batteryLife(batteryLife), m_weight(weight)
{

}

// Accessors
double Laptop::getBatteryLife() const
{
    return m_batteryLife;
}

double Laptop::getWeight() const
{
    return m_weight;
}

// Mutators
void Laptop::setBatteryLife(double batteryLife)
{
    m_batteryLife = batteryLife;
}

void Laptop::setWeight(double weight)
{
    m_weight = weight;
}

// Overloaded equality == operator (as per class diagram)
bool Laptop::operator==(const Laptop &other) const
{
    return (static_cast<const Computer &>(*this) == static_cast<const Computer &>(other) &&
            m_batteryLife == other.m_batteryLife &&
            m_weight == other.m_weight);
}

// Overloaded stream insertion << operator
std::ostream &operator<<(std::ostream &os, const Laptop &lap)
{
    os << "| " << std::left << std::setw(6) << lap.getId()
       << "| " << std::setw(7) << lap.getMake()
       << "| " << std::setw(15) << lap.getModel()
       << "| " << std::right << std::setw(8) << std::fixed << std::setprecision(2) << lap.getPrice()
       << " | " << std::setw(13) << std::fixed << std::setprecision(1) << lap.m_batteryLife
       << " | " << std::setw(13) << std::fixed << std::setprecision(1) << lap.m_weight
       << " |";
    return os;
}