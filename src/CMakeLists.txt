#Exemple 1
find_package(gf REQUIRED)

if(GF_SINGLE_COMPILATION_UNIT)
	add_executable(main
    	main.cc
    	XUnityBuild.cc
	)
else()
	add_executable (main
	 Square.cpp
	 main.cpp)
endif()

target_link_libraries(main
  gf::gf0
)

install(PROGRAMS ${CMAKE_CURRENT_BINARY_DIR}/main
  DESTINATION bin
  RENAME ${CMAKE_PROJECT_NAME})
