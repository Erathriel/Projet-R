#Exemple 1
find_package(gf REQUIRED)

add_executable (mainDemo main.cpp)

target_link_libraries(mainDemo
  gf::gf0
)

install(PROGRAMS ${CMAKE_CURRENT_BINARY_DIR}/mainDemo
  DESTINATION bin
  RENAME ${CMAKE_PROJECT_NAME})
