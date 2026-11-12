add_executable(dsa_graph_tests
    dijkstra_shortest_path_test.cpp
    depth_first_search_test.cpp
)
target_link_libraries(dsa_graph_tests PRIVATE dsa_graph GTest::gtest GTest::gtest_main)
gtest_discover_tests(dsa_graph_tests DISCOVERY_TIMEOUT 30)
