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
            std::string get_name();

            int compare_to(element e, std::string compare_type);
    };
}

#endif