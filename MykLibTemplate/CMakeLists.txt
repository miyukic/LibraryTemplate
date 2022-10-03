set(PROJ_NAME "MykLibTemplate")
set(SOURCE_LIST
	"MykLibTemplate.cpp" "include/MykLibTemplate.h"
	"MykClassTemplate.cpp"
)

#動的/静的ライブラリを切り替えるオプションを定義
option(BUILD_STATIC_LIBS "build static lib" OFF)

if(BUILD_STATIC_LIBS)
	add_library(${PROJ_NAME} STATIC 
		${SOURCE_LIST}
	)
else()
	add_library(${PROJ_NAME} SHARED
		${SOURCE_LIST}
	)
	if(MSVC)
		#target_compile_options(${PROJ_NAME} PUBLIC "/utf-8")
		#プリプロセスマクロ定義
		add_compile_definitions(MYKLIB_EXPORTS)
	endif()
endif()

target_include_directories(${PROJ_NAME} 
	PUBLIC
	${PROJECT_SOURCE_DIR}/MykLibTemplate/include
)

