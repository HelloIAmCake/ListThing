// Written by Dylan Hansen and Emily Roberts

#include "element.h"
#include "list.h"
#include <iostream> // For outputting to the console

// TESTING FOR NOW UNTIL A PROPER UNIT TESTING CLASS IS IMPLEMENETED
int main()
{
        core::list main_list("Jojo");
        core::element waa("13");
        core::element waa2("6");
        core::element waa3("Joseph2");
        core::element waa4("Joseph1");
        main_list.insert(waa);
        main_list.insert(waa2);
        main_list.insert(waa3);
        main_list.insert(waa4);
        std::vector<core::element> elements = main_list.get_elements();
        for (int i = 0; i < elements.size(); i++)
            std::cout << elements.at(i).get_name() << std::endl;
        std::vector<core::element> sorted = main_list.get_sorted("alphabetical");
        for (int i = 0; i < sorted.size(); i++)
            std::cout << sorted.at(i).get_name() << std::endl;
        return 0;
}