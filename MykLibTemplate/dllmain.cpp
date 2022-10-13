// dllmain.cpp : DLL アプリケーションのエントリ ポイントを定義します。
#include "pch.h"

#ifdef _WIN32

BOOL APIENTRY DllMain(HMODULE hModule,
    DWORD  ul_reason_for_call,
    LPVOID lpReserved
) {
    switch (ul_reason_for_call) {
    case DLL_PROCESS_ATTACH:
#ifdef _DEBUG
        std::cout << "__cplusplus = " << __cplusplus << std::endl;
#ifdef _WIN64
        std::cout << "Compiled for Windows x64." << std::endl;
#elif _WIN32
        std::cout << "Compiled for Windows x86";
#endif
#endif //_DEBUG
    case DLL_THREAD_ATTACH:
    case DLL_THREAD_DETACH:
    case DLL_PROCESS_DETACH:
        break;
    }
    return TRUE;
}
#endif

