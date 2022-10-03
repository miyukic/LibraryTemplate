# CMakeList.txt : LibraryTemplate の CMake プロジェクト。ソースを含めて、次を定義します:
# プロジェクト専用ロジックはこちらです。
#
cmake_minimum_required (VERSION 3.8)

# プロジェクト名の設定
set(PROJ_NAME "Main")


# ソースをこのプロジェクトの実行可能ファイルに追加します。
add_executable (${PROJ_NAME} "Main.cpp" "Main.h")

target_include_directories(${PROJ_NAME} 
	PUBLIC
	${PROJECT_SOURCE_DIR}/MykLibTemplate/include
)

#自作ライブラリのリンク
target_link_libraries(${PROJ_NAME} MykLibTemplate)

#dllを実行ファイルと同じフォルダへのコピー
#https://yuki-koyama.hatenablog.com/entry/2018/09/09/135057
if(MSVC)
	add_custom_command(
		TARGET ${PROJ_NAME} POST_BUILD
		COMMAND ${CMAKE_COMMAND} -E copy 
		"${PROJECT_SOURCE_DIR}/out/build/x64-debug/MykLibTemplate/MykLibTemplate.dll"
		$<TARGET_FILE_DIR:Main>
	)
endif()


if (CMAKE_VERSION VERSION_GREATER 3.12)
  set_property(TARGET ${PROJ_NAME} PROPERTY CXX_STANDARD 20)
endif()
# TODO: テストを追加し、必要な場合は、ターゲットをインストールします。
