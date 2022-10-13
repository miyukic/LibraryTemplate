set(PROJ_NAME ${LIBTEMP_PROJ_NAME})
set(SOURCE_LIST
	"dllmain.cpp" "pch.cpp"
	"MykLibTemplate.cpp" "include/MykLibTemplate.h"
	"MykClassTemplate.cpp"
)

#動的/静的ライブラリを切り替えるオプションを定義
option(BUILD_STATIC_LIBS "build static lib" OFF)

if(BUILD_STATIC_LIBS)
	add_library(${LIBTEMP_PROJ_NAME} STATIC 
		${SOURCE_LIST}
	)
else()
	add_library(${LIBTEMP_PROJ_NAME} SHARED
		${SOURCE_LIST}
	)
	if(MSVC)
		#プリプロセスマクロ定義
		add_compile_definitions(MYKLIB_EXPORTS)
	endif()
endif()

if (MSVC)
	#target_compile_options(${LIBTEMP_PROJ_NAME} PUBLIC "/utf-8")
	#target_compile_options(${LIBTEMP_PROJ_NAME} PUBLIC "/source-charset:utf-8")
	target_compile_options(${LIBTEMP_PROJ_NAME} PUBLIC "/execution-charset:utf-8")
endif()

target_include_directories(${LIBTEMP_PROJ_NAME} 
	PUBLIC
	${PROJECT_SOURCE_DIR}/${LIBTEMP_PROJ_NAME}/include
)

if(CMAKE_VERSION VERSION_GREATER 3.12)
	set_property(TARGET ${LIBTEMP_PROJ_NAME} PROPERTY CXX_STANDARD 20)
endif()
