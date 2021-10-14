/**
 * This class serves to represent a list. It a child of the class element and serves as an element which is able to contain elements (and lists) within it.
 * Written by Dylan Hansen and Emily Roberts
 */

#ifndef LIST_H
#define LIST_H

#include <vector> 
#include "element.h"

namespace core
{
    class list : public element
    {

        private:
            std::unordered_map<std::string, element*> name_to_element; // Maps an element name to a pointer to the element with that name
            std::unordered_map<std::string, element*> sorted; // Maps a sorting type with a head element pointing towards the first element in said sorted list

        public:
            list(const std::string &name); // Creates a list with the given name
            //list(const std::string &name, const std::vector<element*> &init_elements); // Creates a list with the given name and elements already in it

            void insert(const element &e); // Inserts an element into the list
            void remove(const std::string &name); // Removes the element with the specified name from the list

            element get_element(const std::string &name); // Gets the elements with the specified name
            element get_first(const std::string &type); // Gets the sorted list of elements sorted with the specified type
    };
}

#endif