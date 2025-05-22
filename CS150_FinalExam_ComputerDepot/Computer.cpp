/*****************************************************************************
 * AUTHOR: Mikayla Weber
 * COURSE: CS 150 : C++ Programming 1
 * SECTION: online
 * IC (PROJECT)#: Final Exam
 * LAST MODIFIED: 5/21/25
 *****************************************************************************/
/*****************************************************************************
 * Computer Class
 *****************************************************************************
 * PROGRAM DESCRIPTION:
 * Implements the methods for the Computer class, including constructors,
 * accessors, mutators, and overloaded operators.
 *****************************************************************************
 * ALGORITHM:
 * 1. Initialize static member s_nextId to 100.
 * 2. Implement default constructor: initializes members to default values (ID to 0).
 * 3. Implement parameterized constructor: assigns a unique ID using s_nextId
 *    and initializes other members with provided values.
 * 4. Implement accessor methods to return member variable values.
 * 5. Implement mutator methods to set member variable values (except ID).
 * 6. Implement overloaded equality operator to compare two Computer objects.
 * 7. Implement overloaded stream insertion operator to print Computer
 *    object details
 *****************************************************************************
 * ALL IMPORTED LIBRARIES NEEDED AND PURPOSE:
 * "Computer.h" - Contains the declaration of the Computer class.
 * <iostream>   - For std::ostream, std::fixed, std::left, std::right.
 * <string>     - For std::string.
 * <iomanip>    - For std::setw, std::setprecision.
 *****************************************************************************/

#include "Computer.h"
#include <iostream>
#include <string>
#include <iomanip> // For std::setw, std::setprecision

// Initialize static member variable
int Computer::s_nextId = 100;

// Default constructor
Computer::Computer() : m_id(0), m_make(""), m_model(""), m_price(0.0) {}

// Parameterized constructor
Computer::Computer(std::string make, std::string model, double price)
    : m_make(make), m_model(model), m_price(price)
{
    m_id = s_nextId++;
}

// Accessors
int Computer::getId() const
{
    return m_id;
}

std::string Computer::getMake() const
{
    return m_make;
}

std::string Computer::getModel() const
{
    return m_model;
}

double Computer::getPrice() const
{
    return m_price;
}

// Mutators
void Computer::setMake(std::string make)
{
    m_make = make;
}

void Computer::setModel(std::string model)
{
    m_model = model;
}

void Computer::setPrice(double price)
{
    m_price = price;
}

// Overloaded equality == operator
bool Computer::operator==(const Computer &other) const
{
    return (m_id == other.m_id &&
            m_make == other.m_make &&
            m_model == other.m_model &&
            m_price == other.m_price);
}

// Overloaded stream insertion << operator
std::ostream &operator<<(std::ostream &os, const Computer &comp)
{
    os << "| " << std::left << std::setw(6) << comp.m_id
       << "| " << std::setw(7) << comp.m_make
       << "| " << std::setw(15) << comp.m_model
       << "| " << std::right << std::setw(8) << std::fixed << std::setprecision(2) << comp.m_price
       << " |";
    return os;
}