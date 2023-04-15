aux_source_directory (. SRC_LIST)

add_executable(2.1.1.ibl_irradiance_conversion ${SRC_LIST})

find_package(glad CONFIG REQUIRED)
find_package(OpenGL REQUIRED)
find_package(glfw3 CONFIG REQUIRED)

target_link_libraries(2.1.1.ibl_irradiance_conversion PRIVATE glfw)
target_link_libraries(2.1.1.ibl_irradiance_conversion PRIVATE OpenGL::GL)
target_link_libraries(2.1.1.ibl_irradiance_conversion PRIVATE glad::glad)
