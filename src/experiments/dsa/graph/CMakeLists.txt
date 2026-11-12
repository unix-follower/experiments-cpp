file(GLOB APP_SOURCES RELATIVE ${CMAKE_CURRENT_SOURCE_DIR} CONFIGURE_DEPENDS *_demo.cpp)

foreach(source_file IN LISTS APP_SOURCES)
    get_filename_component(app_name ${source_file} NAME_WE)
    add_executable(${app_name} ${source_file})
    set_target_properties(${app_name} PROPERTIES OUTPUT_NAME ${app_name})
    install(TARGETS ${app_name} DESTINATION "bin/graph")
endforeach()

add_library(dsa_graph
    graph.hpp
    graph.cpp
    depth_first_search.hpp
    dfs.cpp
    dijkstra_algorithm.hpp
    dijkstra_shortest_path.cpp
)
target_include_directories(dsa_graph PUBLIC ${PROJECT_SOURCE_DIR}/src)
