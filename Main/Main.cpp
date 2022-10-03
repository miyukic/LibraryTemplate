// Main.cpp: ターゲットのソース ファイル。
//

#include "Main.h"
#include "MykLibTemplate.h"
#include "MykClassTemplate.hpp"

int main()
{
	std::cout << "main" << std::endl;
	libmyfunc();
	MykClassTemplate mct{};
	mct.printData();
	char a[128];
	std::cin >> a;
	return 0;
}
