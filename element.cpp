// Written by Dylan Hansen and Emily Roberts

#include "element.h"

core::element::element(bool is_head, bool is_tail)
{
    this->is_head = is_head;
    this->is_tail = is_tail;
}

core::element::element(const std::string &name) : element(false, false)
{
    this->name = name;
}

std::string core::element::get_name() const
{
    return name;
}

void core::element::set_next(std::string sorting_type, element* e)
{
    if(e->is_tail)
    {
        next_map[sorting_type] = e;
        e->prev_map[sorting_type] = this;
        return;
    }
    element* old_next = next(sorting_type);
    next_map[sorting_type] = e;
    e->next_map[sorting_type] = old_next;

    old_next->prev_map[sorting_type] = e;
    e->prev_map[sorting_type] = this;
}

core::element* core::element::next(std::string sorting_type)
{
    return next_map[sorting_type];
}
core::element* core::element::prev(std::string sorting_type)
{
    return prev_map[sorting_type];
}

int core::element::compare_to(element e, std::string compare_type)
{
    if(this->is_head)
        return -1;
    if(this->is_tail)
        return 1;
    //TODO: ADD MORE SORTING TYPE DEFINITIONS
    // Compares elements based on alphabetical order
    if(this->get_name() < e.get_name())
    {
        return -1;
    }
    else if(this->get_name() > e.get_name())
    {
        return 1;
    }
    else
    {
        return 0;
    }
}