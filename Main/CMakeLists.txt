# CMakeList.txt : LibraryTemplate の CMake プロジェクト。ソースを含めて、次を定義します:
# プロジェクト専用ロジックはこちらです。
#
cmake_minimum_required (VERSION 3.8)

# プロジェクト名の設定
set(PROJ_NAME "Main")
# ソースファイル
set(PROJ_SOURCE "Main.cpp" "Main.h")


# ソースをこのプロジェクトの実行可能ファイルに追加します。
add_executable (${PROJ_NAME} ${PROJ_SOURCE})

target_include_directories(${PROJ_NAME} 
	PUBLIC
	#ライブラリ側のヘッダーファイルフォルダをincludeディレクトリに追加
	${PROJECT_SOURCE_DIR}/MykLibTemplate/include
)

#自作ライブラリをリンクする(インポートライブラリなども自動でリンク処理をする)
#第二引数目以降にプロジェクト名(gcc に -lfoo と指定していた場合は、 foo とだけ書く)を指定する
#https://gist.github.com/miyukic/246f3977372c440ccff37747a7b6a73a
target_link_libraries(${PROJ_NAME} PRIVATE MykLibTemplate)

#dllを実行ファイルと同じフォルダへのコピー -> ルートのCMakeListsに追加した二行で必要なくなった
#https://yuki-koyama.hatenablog.com/entry/2018/09/09/135057
if(MSVC)
#find_library(MykLibTemplate "${PROJECT_SOURCE_DIR}/out/build/x64-debug/MykLibTemplate/MykLibTemplate.dll")
#	if(CMAKE_BUILD_TYPE STREQUAL "Debug") # Debugビルド
#		if(CMAKE_SIZEOF_VOID_P EQUAL 8) # x64
#			add_custom_command(
#				TARGET ${PROJ_NAME} POST_BUILD
#				COMMAND ${CMAKE_COMMAND} -E copy 
#				"${PROJECT_SOURCE_DIR}/out/build/x64-debug/MykLibTemplate/MykLibTemplate.*"
#				$<TARGET_FILE_DIR:Main>
#			)
#		elseif(CMAKE_SIZEOF_VOID_P EQUAL 4) # x86
#			add_custom_command(
#				TARGET ${PROJ_NAME} POST_BUILD
#				COMMAND ${CMAKE_COMMAND} -E copy 
#				"${PROJECT_SOURCE_DIR}/out/build/x86-debug/MykLibTemplate/MykLibTemplate.*"
#				$<TARGET_FILE_DIR:Main>
#			)
#		endif()
#	elseif(CMAKE_BUILD_TYPE STREQUAL "Release") #Releaseビルド
#		if(CMAKE_SIZEOF_VOID_P EQUAL 8) # x64
#			add_custom_command(
#				TARGET ${PROJ_NAME} POST_BUILD
#				COMMAND ${CMAKE_COMMAND} -E copy 
#				"${PROJECT_SOURCE_DIR}/out/build/x64-release/MykLibTemplate/MykLibTemplate.*"
#				$<TARGET_FILE_DIR:Main>
#			)
#		elseif(CMAKE_SIZEOF_VOID_P EQUAL 4) # x86
#			add_custom_command(
#				TARGET ${PROJ_NAME} POST_BUILD
#				COMMAND ${CMAKE_COMMAND} -E copy 
#				"${PROJECT_SOURCE_DIR}/out/build/x86-release/MykLibTemplate/MykLibTemplate.*"
#				$<TARGET_FILE_DIR:Main>
#			)
#		endif()
#	endif()
endif()


if(CMAKE_VERSION VERSION_GREATER 3.12)
  set_property(TARGET ${PROJ_NAME} PROPERTY CXX_STANDARD 20)
endif()
# TODO: テストを追加し、必要な場合は、ターゲットをインストールします。
