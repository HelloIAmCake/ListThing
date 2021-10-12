// Written by Dylan Hansen and Emily Roberts

#include "element.h"

core::element::element(const std::string &name)
{
    this->name = name;
}

std::string core::element::get_name() const
{
    return name;
}

int core::element::compare_to(element e, std::string compare_type)
{
    //TODO: ADD MORE SORTING TYPE DEFINITIONS
    // Compares elements based on alphabetical order
    if(this->get_name() < e.get_name())
    {
        return -1;
    }
    else if(this->get_name() > e.get_name())
    {
        return 1;
    }
    else
    {
        return 0;
    }
}