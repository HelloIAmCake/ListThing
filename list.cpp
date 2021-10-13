// Written by Dylan Hansen and Emily Roberts

#include "list.h"
#include <iostream> //TODO REMOVE

core::list::list(const std::string &name) : element(name)
{
    // Creates an empty vector for every sorting type
    element* a = new element(true, false);
    a->set_next("alphabetical", new element(false, true));
    sorted["alphabetical"] = a;
}
/*core::list::list(const std::string &name, const std::vector<element*> &init_elements) : list(name) 
{    
    this->elements = init_elements;
}*/

void core::list::insert(const element &e)
{
    element* to_e = new element(e.get_name());

    name_to_element[to_e->get_name()] = to_e;

    // For every sorting type in the program
    for(std::unordered_map<std::string, element*>::iterator it = sorted.begin(); it != sorted.end(); it++) 
    {
        // Get the type
        std::string compare_type = it->first;

        element* cur = it->second;
        // Uses iterates through the list until it finds the greatest element that's not bigger than the current element
        while(cur->next(compare_type)->compare_to(e, compare_type) < 0)
        {
            cur = cur->next(compare_type);
        }
        cur->set_next(compare_type, to_e);
    }

}

void core::list::remove(const std::string &name)
{
    element* to_delete = name_to_element[name];
    name_to_element.erase(name);
    for(std::unordered_map<std::string, element*>::iterator it = sorted.begin(); it != sorted.end(); it++)
    {
        std::string sorting_type = it->first;
        to_delete->prev(sorting_type)->set_next(sorting_type, to_delete->next(sorting_type));
    }
    delete(to_delete);
    to_delete = NULL;
}

core::element core::list::get_element(const std::string &name)
{
    return *name_to_element[name];
}

core::element core::list::get_first(const std::string &type)
{
    return *sorted[type]->next(type);
}