#Exemple 1
find_package(gf REQUIRED)

add_executable (main main.cpp)

target_link_libraries(main
  gf::gf0
)

install(PROGRAMS ${CMAKE_CURRENT_BINARY_DIR}/main
  DESTINATION bin
  RENAME ${CMAKE_PROJECT_NAME})
