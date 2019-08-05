set(TARGET_NAME Image04)
set(TARGET_LIST main.cpp)

add_executable(${TARGET_NAME} ${TARGET_LIST})
target_link_libraries(${TARGET_NAME} ${OpenCV_LIBS})
