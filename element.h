/**
 * Class which represents an element inside of a list. Stores all of the metadata you would want out of an element of said list
 * Written by Dylan Hansen and Emily Roberts
 */

#ifndef EL_H
#define EL_H

#include <string>

namespace core
{
    class element
    {
        private:
            std::string name;
        public:
            element(const std::string &name);
            std::string get_name() const;

            int compare_to(element e, std::string compare_type); // Compares 2 elements based on the specified compare type.
            // If the returned val < 0, then this < e. If returned val > 0, then this > e. If returned 0, this = e.
    };
}

#endif