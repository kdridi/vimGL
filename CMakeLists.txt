CMAKE_MINIMUM_REQUIRED (VERSION 3.9)

PROJECT (vimGL)

################################################################################
# C++ SUPPORT
################################################################################
SET (CMAKE_CXX_STANDARD 14)

################################################################################
# EXECUTABLE
################################################################################
SET (EXECUTABLE_NAME "vimGL")

################################################################################
# SOURCES
################################################################################
SOURCE_GROUP("src" FILES
	src/main/main.cpp
)

SOURCE_GROUP("src\\assets" FILES
	src/main/assets.cpp
	src/main/assets.hpp
)

SOURCE_GROUP("src\\keyboard" FILES
	src/main/keyboard/handler.cpp
	src/main/keyboard/handler.hpp
)

SOURCE_GROUP("src\\game" FILES
	src/main/game/context.cpp
	src/main/game/context.hpp
)

ADD_EXECUTABLE (${EXECUTABLE_NAME}
	src/main/assets.cpp
	src/main/assets.hpp
	src/main/game/context.cpp
	src/main/game/context.hpp
	src/main/keyboard/handler.cpp
	src/main/keyboard/handler.hpp
	src/main/main.cpp
)

################################################################################
# SFML
################################################################################
SET (CMAKE_MODULE_PATH "${CMAKE_SOURCE_DIR}/vendor/SFML/cmake/Modules" ${CMAKE_MODULE_PATH})

FIND_PACKAGE (SFML 2.4 COMPONENTS window graphics network audio system REQUIRED)

IF (SFML_FOUND)
	INCLUDE_DIRECTORIES (${SFML_INCLUDE_DIR})
	TARGET_LINK_LIBRARIES (${EXECUTABLE_NAME} ${SFML_LIBRARIES} ${SFML_DEPENDENCIES})
ENDIF ()
