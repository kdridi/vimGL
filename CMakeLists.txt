CMAKE_MINIMUM_REQUIRED (VERSION 3.10)

PROJECT (vimGL)

################################################################################
# EXECUTABLE
################################################################################
SET (EXECUTABLE_NAME "vimGL")

################################################################################
# SOURCES
################################################################################
ADD_EXECUTABLE (${EXECUTABLE_NAME}
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
