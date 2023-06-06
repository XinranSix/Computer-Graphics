MACRO(SUBDIRLIST result curdir)
    FILE(GLOB children RELATIVE ${curdir} ${curdir}/*)
    SET(dirlist "")
    FOREACH (child ${children})
        IF (IS_DIRECTORY ${curdir}/${child})
            LIST(APPEND dirlist ${child})
        ENDIF ()
    ENDFOREACH ()
    SET(${result} ${dirlist})
ENDMACRO()

find_package(OpenGL REQUIRED)
find_package(glfw3 CONFIG REQUIRED)
find_package(glad CONFIG REQUIRED)
find_package(glm CONFIG REQUIRED)


SUBDIRLIST(SUBDIRS ${PROJECT_SOURCE_DIR}/src)

aux_source_directory(../lib/ OTHER_LIST)

FOREACH (subdir ${SUBDIRS})

    add_executable(${subdir} ${subdir}/main.cpp ${OTHER_LIST})

    target_link_libraries(${subdir} PRIVATE glfw)
    target_link_libraries(${subdir} PRIVATE OpenGL::GL)
    target_link_libraries(${subdir} PRIVATE glad::glad)
    target_link_libraries(${subdir} PRIVATE glm::glm)

    add_custom_command(
            TARGET ${subdir}
            POST_BUILD
            COMMAND ${CMAKE_COMMAND} -E copy_directory "${PROJECT_SOURCE_DIR}/assets"
            "$<TARGET_FILE_DIR:${subdir}>/assets")

    add_custom_command(
            TARGET ${subdir}
            POST_BUILD
            COMMAND ${CMAKE_COMMAND} -E copy_directory "${CMAKE_CURRENT_SOURCE_DIR}/${subdir}/shaders/"
            "$<TARGET_FILE_DIR:${subdir}>/shaders")
ENDFOREACH ()