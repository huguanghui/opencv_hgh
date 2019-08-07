set(TARGET_NAME Image05)
set(TARGET_LIST main.cpp)

add_executable(${TARGET_NAME} ${TARGET_LIST})
target_link_libraries(${TARGET_NAME} ${OpenCV_LIBS})
