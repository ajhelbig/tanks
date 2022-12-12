
add_executable(${PROJECT_NAME} 
	main.cpp
	terrain.cpp
	tank.cpp
)

target_link_libraries(${PROJECT_NAME} 
	raylib 
)
