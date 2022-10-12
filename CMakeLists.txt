# CMakeList.txt : 最上位の CMake プロジェクト ファイル。グローバル構成を行います
# また、サブプロジェクトをここに含めます。
#
cmake_minimum_required (VERSION 3.8)

project ("LibraryTemplate")
if(MSVC)
else()
endif()

#dllを見つけられるようになるために必要な二行
if (MSVC)
set(LIBRARY_OUTPUT_PATH "${CMAKE_BINARY_DIR}")
set(EXECUTABLE_OUTPUT_PATH "${CMAKE_BINARY_DIR}")
endif()
# サブプロジェクトを含めます。
add_subdirectory("Main")
add_subdirectory ("MykLibTemplate")
