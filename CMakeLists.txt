cmake_minimum_required(VERSION 3.5)

project(04_03_Max_Counters LANGUAGES C)

add_executable(04_03_Max_Counters main.c)

include(GNUInstallDirs)
target_link_libraries(${PROJECT_NAME} -lunity)
install(TARGETS 04_03_Max_Counters
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
    RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR}
)
