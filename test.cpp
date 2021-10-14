// Written by Dylan Hansen and Emily Roberts

#include "element.h"
#include "list.h"
#include <iostream> // For outputting to the console

// TESTING FOR NOW UNTIL A PROPER UNIT TESTING CLASS IS IMPLEMENETED
int main()
{
        core::list main_list("Jojo");
        core::element waa("13");
        core::element waa2("Joseph2");
        core::element waa3("Wow");
        core::element waa4("Joseph1");
        main_list.insert(waa);
        main_list.insert(waa2);
        main_list.insert(waa3);
        main_list.insert(waa4);
       core:: element* cur = main_list.get_first("alphabetical");
        while (cur->next("alphabetical") != NULL)
        {
            std::cout << cur->get_name() << std::endl;
            cur = cur->next("alphabetical");
        }

        std::cout << std::endl;
        main_list.remove("Wow");

        core::element* cur2 = main_list.get_first("alphabetical");
        while (cur2->next("alphabetical") != NULL)
        {
            std::cout << cur2->get_name() << std::endl;
            cur2 = cur2->next("alphabetical");
        }
        
        return 0;
}