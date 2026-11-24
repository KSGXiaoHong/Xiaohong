cmake_minimum_required(VERSION 3.10)
#指定编译器
set(CMAKE_SYSTEM_NAME Linux)
set(CMAKE_SYSTEM_PROCESSOR arm)

set(CMAKE_C_COMPILER /usr/arm-linux/bin/arm-gcc)
set(CMAKE_CXX_COMPILER /usr/arm-linux/bin/arm-g++)

project(lvgl)

set(CMAKE_C_STANDARD 99)#C99 # lvgl officially support C99 and above
set(CMAKE_CXX_STANDARD 17)#C17
set(CMAKE_CXX_STANDARD_REQUIRED ON)

set(EXECUTABLE_OUTPUT_PATH ${PROJECT_SOURCE_DIR}/bin)

add_subdirectory(lvgl)
target_include_directories(lvgl PUBLIC ${PROJECT_SOURCE_DIR})

add_executable(main main.c mouse_cursor_icon.c bmp.c game.c lcdpjt.c play.c touch.c lv.c car.c mp4.c mokuai.c everyday.c photo.c map.c user.c help.c)

target_link_libraries(main lvgl lvgl::examples lvgl::demos lvgl::thorvg ${SDL2_LIBRARIES} m pthread)
add_custom_target (run COMMAND ${EXECUTABLE_OUTPUT_PATH}/main DEPENDS main)

