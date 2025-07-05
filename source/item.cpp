#include "../header/item.hpp"

Item::Item(csvstream &csv) {
    csv >> *this;
}

std::ostream & operator<<(std::ostream &os, const Item & item) {
    
}
