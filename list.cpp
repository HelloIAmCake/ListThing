// Written by Dylan Hansen and Emily Roberts

#include "list.h"
#include <iostream> //TODO REMOVE

core::list::list(const std::string &name) : element(name)
{
    // Creates an empty vector for every sorting type
    std::vector<element*> a;
    sorted["alphabetical"] = a;
}
core::list::list(const std::string &name, const std::vector<element*> &init_elements) : element(name) 
{    
    this->elements = init_elements;
}

void core::list::insert(const element &e)
{
    element* to_e = new element(e.get_name());

    elements.push_back(to_e);
    
    std::cout << elements.back() << std::endl;

    // For every sorting type in the program
    for(std::map<std::string, std::vector<element*>>::iterator it = sorted.begin(); it != sorted.end(); it++) 
    {
        // Get the type
        std::string compare_type = it->first;

        int start = 0;
        int end = it->second.size();
        // Uses a binary search algorithm to find the position of the smallest element which is bigger than e
        while(start != end)
        {
            int mid = (start + end) / 2;
            element* cur = it->second[mid];
            if(cur->compare_to(e, compare_type) < 0)
            {
                start = mid + 1;
            }
            else if(cur->compare_to(e, compare_type) > 0)
            {
                end = mid;
            }
        }
        // Inserts e into the position we found; maintaining the vector's sorted ordering
        it->second.insert(it->second.begin() + end, to_e);

        std::cout << it->second[end] << std::endl;
    }

}

void core::list::remove(const element &e)
{
    
}

std::vector<core::element*> core::list::get_elements() const
{
    return elements;
}

std::vector<core::element*> core::list::get_sorted(const std::string &type) const
{
    return sorted.at(type);
}