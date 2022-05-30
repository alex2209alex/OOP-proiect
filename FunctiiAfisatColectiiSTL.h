//
// Created by alex on 5/30/2022.
//

#ifndef OOP_FUNCTIIAFISATCOLECTIISTL_H
#define OOP_FUNCTIIAFISATCOLECTIISTL_H

#include <iostream>
#include <vector>

template <typename T>
std::enable_if_t<!std::is_convertible_v<T, std::string>, std::ostream&>
operator<<(std::ostream& os, const T& obj);

#endif //OOP_FUNCTIIAFISATCOLECTIISTL_H

#include <iostream>
#include <vector>


