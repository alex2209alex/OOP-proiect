//
// Created by alex on 5/30/2022.
//

#include "FunctiiAfisatColectiiSTL.h"
#include <iostream>

template <typename T>
std::enable_if_t<!std::is_convertible_v<T, std::string>, std::ostream&>
operator<<(std::ostream& os, const T& obj) {
    os << "[";
    for(auto iter = obj.begin(); iter != obj.end(); ++iter) {
        os << *(*iter);
        if(iter == obj.end())
            break;
        os << "\n";
    }
    os << "]";
    return os;
}
