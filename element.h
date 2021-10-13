/**
 * Class which represents an element inside of a list. Stores all of the metadata you would want out of an element of said list
 * Written by Dylan Hansen and Emily Roberts
 */

#ifndef EL_H
#define EL_H

#include <string>
#include <unordered_map> 

namespace core
{
    class element
    {
        private:
            std::string name;
            std::unordered_map<std::string, element*> prev_map;
            std::unordered_map<std::string, element*> next_map;
            bool is_head;
            bool is_tail;
            
        public:
            element(bool is_head, bool is_tail);
            element(const std::string &name);
            std::string get_name() const;

            void set_next(std::string sorting_type, element* e);
            element* next(std::string sorting_type);
            element* prev(std::string sorting_type);

            int compare_to(element e, std::string compare_type); // Compares 2 elements based on the specified compare type.
            // If the returned val < 0, then this < e. If returned val > 0, then this > e. If returned 0, this = e.
    };
}

#endif