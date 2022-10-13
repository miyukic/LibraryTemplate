set(PROJ_NAME ${LIBTEMP_PROJ_NAME})
set(SOURCE_LIST
	"dllmain.cpp" "pch.cpp"
	"MykLibTemplate.cpp" "include/MykLibTemplate.h"
	"MykClassTemplate.cpp"
)

set(PRE_COMP_HEADERS
	"pch.h"
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

target_precompile_headers(${LIBTEMP_PROJ_NAME} PUBLIC ${PRE_COMP_HEADERS})

#target_compile_options(${LIBTEMP_PROJ_NAME} PUBLIC
#"/utf-8")
target_compile_options(${LIBTEMP_PROJ_NAME} PUBLIC
	$<$<CXX_COMPILER_ID:MSVC>:/utf-8>
	#$<$<CXX_COMPILER_ID:MSVC>:/source-charset:utf-8>
	#$<$<CXX_COMPILER_ID:MSVC>:/execution-charset:utf-8>
)

target_compile_options(${LIBTEMP_PROJ_NAME} PUBLIC
	$<$<CXX_COMPILER_ID:MSVC>: /W4>				#MSVC
	$<$<PLATFORM_ID:Linux>: -Wall -Wextra>		#Linux
)

target_include_directories(${LIBTEMP_PROJ_NAME} 
	PUBLIC
	${PROJECT_SOURCE_DIR}/${LIBTEMP_PROJ_NAME}/include
)

if(CMAKE_VERSION VERSION_GREATER 3.12)
	set_property(TARGET ${LIBTEMP_PROJ_NAME} PROPERTY CXX_STANDARD 20)
endif()
