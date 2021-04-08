# 
CMAKE_MINIMUM_REQUIRED(VERSION 3.18)

#option(ENABLE_PICO_DOWLOAD						"LET CMAKE DOWLOAD PICO SDK" ON)
#IF(ENABLE_PICO_DOWLOAD)
	# initialize pico-sdk from GIT
	# (note this can come from environment, CMake cache etc)
#	set(PICO_SDK_FETCH_FROM_GIT on)
#ENDIF(ENABLE_PICO_DOWLOAD)

# initialize the SDK based on PICO_SDK_PATH
# note: this must happen before project()
INCLUDE(${CMAKE_CURRENT_SOURCE_DIR}/CMake/pico_sdk_import.cmake)

#Pico Temperature control system project setup
#haspberry pi pico thermic controler
PROJECT(HPP-PicoThermicControler) #HPPTC
SET( EXECUTABLE_NAME HPPTCfirmware )

# initialize the Raspberry Pi Pico SDK
pico_sdk_init()

# Project Source
#################################

SET( HPPTC_SOURCES 
		${CMAKE_CURRENT_SOURCE_DIR}/src/main.cpp
		${CMAKE_CURRENT_SOURCE_DIR}/src/controls.cpp
		${CMAKE_CURRENT_SOURCE_DIR}/src/sensors.cpp
	)

SET( HPPTC_HEADERS
		${CMAKE_CURRENT_SOURCE_DIR}/src/controls.hpp
		${CMAKE_CURRENT_SOURCE_DIR}/src/sensors.hpp
	)

# Project Libraries
#################################
set( RPPTC_LIBRARIES 
	pico_stdlib
	)

# Project Executable
####################################

# software main executable
ADD_EXECUTABLE( ${EXECUTABLE_NAME} ${RPPTC_SOURCES} ${RPPTC_HEADERS})

# Define the precompiled header
#target_precompile_headers( ${EXECUTABLE_NAME} PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/precompiled.h ) #can cause compiling error, try compile "C++" code as "C" 
target_precompile_headers( ${EXECUTABLE_NAME} PUBLIC "$<$<COMPILE_LANGUAGE:CXX>:${CMAKE_CURRENT_SOURCE_DIR}/src/precompiled.h>")

# Add pico_stdlib library which aggregates commonly used features
TARGET_LINK_LIBRARIES(${EXECUTABLE_NAME} ${RPPTC_LIBRARIES})

# create map/bin/hex/uf2 file in addition to ELF.
PICO_ADD_EXTRA_OUTPUTS(${EXECUTABLE_NAME})