#include <string>
#include "MykClassTemplate.hpp"

#ifdef _WIN32
#include <Windows.h>
#endif

void MykClassTemplate::printData() {
#ifdef _WIN32
    std::cout.imbue(std::locale("." + std::to_string(GetConsoleCP()), std::locale::ctype));
#endif
    std::cout << "printData\nHogeHoge" << std::endl;
    for (auto& str : this->data) {
        std::cout << str << "\n";
    }
}

MykClassTemplate::MykClassTemplate() noexcept
    : data{ "あ", "漢", "🍙" }
{ }
