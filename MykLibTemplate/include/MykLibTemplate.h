// MykLibTemplate.h: ターゲットのヘッダー ファイル。
#pragma once

#ifdef MYKLIB_EXPORTS
#   define MYKLIB_API __declspec(dllexport)
#else
#   ifdef _WIN32
#       define MYKLIB_API __declspec(dllimport)
#   elif __linux__
#       define MYKLIB_API
#   endif
#endif

#include <iostream>

// TODO: プログラムに必要な追加ヘッダーをここで参照します。
extern "C" {
     int MYKLIB_API libmyfunc();
}
// int MYKLIB_API libmyfunc();
