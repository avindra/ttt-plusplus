file(GLOB_RECURSE UI_FILES *.ui)
file(GLOB_RECURSE CODE_FILES *.cpp)

qt5_wrap_ui(UI_HEADERS ${UI_FILES})

# Setup the exe
# resources.qrc might be needed here
add_executable(${CMAKE_PROJECT_NAME}
	${UI_HEADERS}
	${CODE_FILES}
)

#qt5_wrap_cpp(${CMAKE_PROJECT_NAME} winmain.h winmain.cpp)

# Link QT libs
target_link_libraries(${CMAKE_PROJECT_NAME} Qt5::Widgets)