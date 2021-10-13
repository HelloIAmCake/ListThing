/**
 * This class serves to represent a list. It a child of the class element and serves as an element which is able to contain elements (and lists) within it.
 * Written by Dylan Hansen and Emily Roberts
 */

#ifndef LIST_H
#define LIST_H

#include <vector> 
#include <map> 
#include "element.h"

namespace core
{
    class list : public element
    {

        private:
            std::vector<element*> elements; // Data structure used to store the list's elements
            std::map<std::string,std::vector<element*>> sorted; // Data structure used to map a "sorting type" to a list of elements sorted with that type

        public:
            list(const std::string &name); // Creates a list with the given name
            list(const std::string &name, const std::vector<element*> &init_elements); // Creates a list with the given name and elements already in it

            void insert(const element &e); // Inserts an element into the list
            void remove(const element &e); // Removes the specified element from the list

            std::vector<element*> get_elements() const; // Gets the list of elements in the default ordering
            std::vector<element*> get_sorted(const std::string &type) const; // Gets the sorted list of elements sorted with the specified type
    };
}

#endif