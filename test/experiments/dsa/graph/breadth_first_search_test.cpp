#include "experiments/dsa/graph/breadth_first_search.hpp"
#include "experiments/dsa/graph/graph.hpp"
#include <gtest/gtest.h>

TEST(BreadthFirstSearchTest, simpleStraightPathTraversal)
{
    // given
    dsa::graph::Graph<int> graph;
    // 0 -- 1 -- 2 -- 3
    graph.addEdge(0, 1);
    graph.addEdge(1, 2);
    graph.addEdge(2, 3);

    // when
    const std::map<int, bool> traversedNodes = dsa::graph::bfs(graph, 0);
    const std::map<int, bool> traversedNodesFrom2 = dsa::graph::bfs(graph, 2);
    // then
    std::map<int, bool> expectedPath;
    expectedPath[0] = true;
    expectedPath[1] = true;
    expectedPath[2] = true;
    expectedPath[3] = true;
    EXPECT_EQ(expectedPath, traversedNodes);
    EXPECT_EQ(expectedPath, traversedNodesFrom2);
}

TEST(BreadthFirstSearchTest, stringNodesTraversal)
{
    // given
    dsa::graph::Graph<std::string> graph;
    //  Vitebsk
    //    |    \
    //  Minsk - Mogilev
    //  /     \   |
    // Brest -  Gomel
    graph.addEdge("Minsk", "Gomel", false);
    graph.addEdge("Gomel", "Mogilev", false);
    graph.addEdge("Minsk", "Vitebsk", false);
    graph.addEdge("Mogilev", "Vitebsk", false);
    graph.addEdge("Gomel", "Brest", false);
    graph.addEdge("Minsk", "Brest", false);
    const std::string startVertex = "Minsk";

    // when
    const std::map traversedNodes = dsa::graph::bfs(graph, startVertex);
    // then
    std::map<std::string, bool> expectedPath;
    expectedPath["Minsk"] = true;
    expectedPath["Gomel"] = true;
    expectedPath["Mogilev"] = true;
    expectedPath["Vitebsk"] = true;
    expectedPath["Brest"] = true;
    EXPECT_EQ(expectedPath, traversedNodes);
}
