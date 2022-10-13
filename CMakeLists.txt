# CMakeList.txt : 最上位の CMake プロジェクト ファイル。グローバル構成を行います
# また、サブプロジェクトをここに含めます。
#
cmake_minimum_required (VERSION 3.8)

set(MAIN_PROJ_NAME "Main")
set(LIBTEMP_PROJ_NAME "MykLibTemplate")

project("LibraryTemplate")
if (MSVC)
else ()
endif ()

#dllを見つけられるようになるために必要な二行
#https://stackoverflow.com/questions/44909846/cmake-exe-cant-find-dll
if(MSVC)
	set(LIBRARY_OUTPUT_PATH "${CMAKE_BINARY_DIR}")
	set(EXECUTABLE_OUTPUT_PATH "${CMAKE_BINARY_DIR}")
endif()
# サブプロジェクトを含めます。
add_subdirectory("Main")
add_subdirectory("MykLibTemplate")
