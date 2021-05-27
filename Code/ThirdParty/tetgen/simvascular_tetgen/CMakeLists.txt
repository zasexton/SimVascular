# Set  the minimum  required version  of cmake  for a  project.
cmake_minimum_required(VERSION 2.6)
project(TETGEN)
### SIMVASCULAR_CHANGE
set (lib ${SV_LIB_THIRDPARTY_TETGEN_NAME})
if(SV_USE_THIRDPARTY_SHARED_TETGEN_NAME)
  add_library(${lib} SHARED tetgen.cxx predicates.cxx)
else()
  add_library(${lib} SHARED tetgen.cxx predicates.cxx)
endif()

# Add an executable to the project using the specified source files.
#add_executable(tetgen tetgen.cxx predicates.cxx)

#Add a library to the project using the specified source files. 
# In Linux/Unix, it will creates the libtet.a
#add_library(tet STATIC tetgen.cxx predicates.cxx)

#Set properties on a target. 
#We use this here to set -DTETLIBRARY for when compiling the
#library
set_target_properties(${lib} PROPERTIES "COMPILE_DEFINITIONS" TETLIBRARY)

if(SV_INSTALL_LIBS)
	install(TARGET ${lib}
		RUNTIME DESTINATION ${SV_INSTALL_RUNTIME_DIR} COMPONENT ThirdPartyExecutables
		LIBRARY DESTINATION ${SV_INSTALL_LIBRARY_DIR} COMPONENT ThirdPartyLibraries
		ARCHIVE DESTINATION ${SV_INSTALL_LIBRARY_DIR} COMPONENT ThirdPartyLibraries
		)
endif()
if(SV_INSTALL_HEADERS)
	install(FILES tetgen.h
		DESTINATION ${SV_INSTALL_INCLUDE_DIR}/thirdparty/tetgen COMPONENT ThirdPartyHeaders
		)
endif()
