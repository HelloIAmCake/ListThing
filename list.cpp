#include "list.h"
#include <iostream> //TODO REMOVE

core::list::list(const std::string &name) : element(name)
{
    //std::string type = "alphabetical";
    std::vector<element> a;
    //sorted.insert(std::pair<std::string, std::vector<element>>(type, a));
    sorted["alphabetical"] = a;
}
core::list::list(const std::string &name, const std::vector<element> &init_elements) : element(name) 
{    
    this->elements = init_elements;
}

void core::list::insert(const element &e)
{
    elements.push_back(e);
    for(std::map<std::string, std::vector<element>>::iterator it = sorted.begin(); it != sorted.end(); it++) 
    {
        std::string compare_type = it->first;

        int start = 0;
        int end = it->second.size();
        while(start != end)
        {
            int mid = (start + end) / 2;
            element cur = it->second.at(mid);
            if(cur.compare_to(e, compare_type) < 0)
            {
                start = mid + 1;
            }
            else if(cur.compare_to(e, compare_type) > 0)
            {
                end = mid;
            }
        }
        it->second.insert(it->second.begin() + end, e);
    }

}

std::vector<core::element> core::list::get_elements()
{
    return elements;
}

std::vector<core::element> core::list::get_sorted(const std::string &type)
{
    return sorted.at(type);
}