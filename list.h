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
            std::vector<element> elements;
            std::map<std::string,std::vector<element>> sorted;

        public:
            list(const std::string &name);
            list(const std::string &name, const std::vector<element> &init_elements);
            void insert(const element &e);
            std::vector<element> get_elements();
            std::vector<element> get_sorted(const std::string &type);
    };
}

#endif