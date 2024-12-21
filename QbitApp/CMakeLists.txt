project(QbitApp)


set(GLEW_DIR "${CMAKE_SOURCE_DIR}/QbitLite/Engine/vendor/GLEW")
set(GLEW_WIN_DIR "${CMAKE_SOURCE_DIR}/QbitLite/Engine/vendor/glew_Win")
set(GLFW_DIR "${CMAKE_SOURCE_DIR}/QbitLite/Engine/vendor/glfw")
set(IMGUI_DIR "${CMAKE_SOURCE_DIR}/QbitLite/Engine/vendor/imgui")
set(GLM_DIR "${CMAKE_SOURCE_DIR}/QbitLite/Engine/vendor/glm")
set(SPDLOG_DIR "${CMAKE_SOURCE_DIR}/QbitLite/Engine/vendor/spdlog")


file(GLOB_RECURSE SRC
    "${CMAKE_SOURCE_DIR}/QbitApp/src/*.cpp"
    "${CMAKE_SOURCE_DIR}/QbitApp/src/*.h"
)

add_executable(QbitApp ${SRC})

# Include directories
target_include_directories(QbitApp PRIVATE 
    ${CMAKE_SOURCE_DIR}/QbitLite/Engine/vendor
    ${CMAKE_SOURCE_DIR}/QbitLite/Engine/src
    ${GLFW_DIR}/install/include 
    ${GLEW_DIR}/include
    ${IMGUI_DIR}
    ${IMGUI_DIR}/backends
    ${GLM_DIR}
    ${GLM_DIR}/glm
    ${SPDLOG_DIR}/include

)

if(WIN32)

    
    target_link_directories(QbitApp PRIVATE 
        ${GLFW_DIR}/install/lib
        ${GLEW_DIR}/Windows/lib/Release/x64
    )
    target_link_libraries(QbitApp PRIVATE 
        glew32s 
        glfw3 
        opengl32 
        gdi32 
        winmm
        Engine
    )
elseif(UNIX)
    target_link_directories(QbitApp PRIVATE 
        ${GLFW_DIR}/build/src
        ${GLEW_DIR}/lib
    )
    target_link_libraries(QbitApp PRIVATE 
        glfw3 
        GLEW 
        m 
        dl 
        pthread 
        GL
        Engine
    )
else()
    message(FATAL_ERROR "Unsupported operating system")
endif()

# Enable "Show All Files" option for Visual Studio projects
set_property(GLOBAL PROPERTY USE_FOLDERS ON)
set_property(TARGET QbitApp PROPERTY VS_SOLUTION_SHOW_ALL_FILES ON)
