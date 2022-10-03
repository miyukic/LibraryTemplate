#pragma once
#include "MykLibTemplate.h"
#include <string>
#include <vector>

//namespace myk::lib {
class MYKLIB_API MykClassTemplate {
    std::vector<std::string> data;
public:
    MykClassTemplate() noexcept;
    MykClassTemplate(const MykClassTemplate& other) = default;
    MykClassTemplate(MykClassTemplate&& other) = default;

    void printData();
};
//} //namespace end myk::lib 
