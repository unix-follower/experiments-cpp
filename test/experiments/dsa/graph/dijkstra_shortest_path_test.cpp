#include <gtest/gtest.h>
#include "experiments/dsa/graph/dijkstra_shortest_path.hpp"

namespace {
    auto createGraph() {
        std::vector adjacencyListGraph(4, std::vector<std::pair<int, double>>());
        dsa::graph::addEdge(&adjacencyListGraph, 0, 1, 1);
        dsa::graph::addEdge(&adjacencyListGraph, 3, 0, 2);
        dsa::graph::addEdge(&adjacencyListGraph, 1, 2, 2);
        dsa::graph::addEdge(&adjacencyListGraph, 0, 2, 5);
        return adjacencyListGraph;
    }
}

TEST(DijkstraShortestPathTest, distanceToSingleNode)
{
    // given
    std::vector adjacencyListGraph(1, std::vector<std::pair<int, double>>());
    dsa::graph::addEdge(&adjacencyListGraph, 0, 0, 0);
    const int startVertex = 0;
    const int targetVertex = 0;
    // when
    const double distance = dsa::graph::dijkstra(&adjacencyListGraph, startVertex, targetVertex);
    // then
    EXPECT_EQ(0, distance);
}

TEST(DijkstraShortestPathTest, twoNodesDirectEdge)
{
    // given
    std::vector adjacencyListGraph(2, std::vector<std::pair<int, double>>()); 
    dsa::graph::addEdge(&adjacencyListGraph, 0, 0, 0);
    dsa::graph::addEdge(&adjacencyListGraph, 0, 1, 5);
    const int startVertex = 0;
    const int targetVertex = 1;
    // when
    const double distance = dsa::graph::dijkstra(&adjacencyListGraph, startVertex, targetVertex);
    // then
    EXPECT_EQ(5, distance);
}

TEST(DijkstraShortestPathTest, Test1)
{
    // given
    std::vector adjacencyListGraph{createGraph()};
    const int startVertex = 0;
    const int targetVertex = 2;
    // when
    const double distance = dsa::graph::dijkstra(&adjacencyListGraph, startVertex, targetVertex);
    // then
    EXPECT_EQ(3, distance);
}

TEST(DijkstraShortestPathTest, Test2)
{
    // given
    std::vector adjacencyListGraph{createGraph()};
    const int startVertex = 3;
    const int targetVertex = 2;
    // when
    const double distance = dsa::graph::dijkstra(&adjacencyListGraph, startVertex, targetVertex);
    // then
    EXPECT_EQ(5, distance);
}

TEST(DijkstraShortestPathTest, Test3)
{
    // given
    std::vector adjacencyListGraph(5, std::vector<std::pair<int, double>>());
    dsa::graph::addEdge(&adjacencyListGraph, 0, 1, 4);
    dsa::graph::addEdge(&adjacencyListGraph, 0, 2, 2);
    dsa::graph::addEdge(&adjacencyListGraph, 1, 2, 2);
    dsa::graph::addEdge(&adjacencyListGraph, 2, 1, 1);
    dsa::graph::addEdge(&adjacencyListGraph, 1, 3, 2);
    dsa::graph::addEdge(&adjacencyListGraph, 2, 4, 4);
    dsa::graph::addEdge(&adjacencyListGraph, 4, 3, 1);
    dsa::graph::addEdge(&adjacencyListGraph, 1, 4, 3);
    dsa::graph::addEdge(&adjacencyListGraph, 2, 3, 4);

    const int startVertex = 0;
    const int targetVertex = 4;
    // when
    const double distance = dsa::graph::dijkstra(&adjacencyListGraph, startVertex, targetVertex);
    // then
    EXPECT_EQ(6, distance);
}
