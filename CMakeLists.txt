cmake_minimum_required(VERSION 3.10)
project(TaskTrueConf VERSION 0.0.1)

include_directories(src)

add_executable(TaskTrueConf src/main.cpp
			    src/random_number_generator.h)

set_target_properties(TaskTrueConf PROPERTIES
	CXX_STANDARD 17
	CXX_STANDARD_REQUIRED ON
    RUNTIME_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}/bin"
)

#installation rules for the project
install(TARGETS TaskTrueConf DESTINATION bin)