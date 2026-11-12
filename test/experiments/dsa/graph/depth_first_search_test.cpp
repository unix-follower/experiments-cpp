#include "experiments/dsa/graph/depth_first_search.hpp"
#include "experiments/dsa/graph/graph.hpp"
#include <gtest/gtest.h>

TEST(DepthFirstSearchWithStackTest, undirectedGraphOfTriangularShape)
{
    // given
    const size_t startVertex = 1;

    std::vector adjacencyListGraph(3, std::vector<size_t>());

    // 1 --- 2
    //   \   |
    //    \  |
    //      3
    dsa::graph::addUndirectedEdge(&adjacencyListGraph, 1, 2);
    dsa::graph::addUndirectedEdge(&adjacencyListGraph, 2, 3);
    dsa::graph::addUndirectedEdge(&adjacencyListGraph, 3, 1);

    // when
    const std::vector<size_t> traversedNodes =
        dsa::graph::dfsWithStack(adjacencyListGraph, startVertex - 1);
    // then
    const std::vector<size_t> expectedVertices{1, 2, 3};
    EXPECT_EQ(expectedVertices, traversedNodes);
}

TEST(DepthFirstSearchWithStackTest, undirectedGraphWithDiffStartingNodes)
{
    // given
    size_t startVertex = 1;

    // 1 -- 2
    // | \  |
    // 3    4
    std::vector adjacencyListGraph(4, std::vector<size_t>());

    dsa::graph::addUndirectedEdge(&adjacencyListGraph, 1, 2);
    dsa::graph::addUndirectedEdge(&adjacencyListGraph, 1, 3);
    dsa::graph::addUndirectedEdge(&adjacencyListGraph, 2, 4);
    dsa::graph::addUndirectedEdge(&adjacencyListGraph, 4, 1);

    // when
    const std::vector<size_t> traversedNodes =
        dsa::graph::dfsWithStack(adjacencyListGraph, startVertex - 1);
    startVertex = 2;
    const std::vector<size_t> traversedNodesFrom2 =
        dsa::graph::dfsWithStack(adjacencyListGraph, startVertex - 1);
    // then
    const std::vector<size_t> expectedVertices{1, 3, 2, 4};
    const std::vector<size_t> expectedVerticesFrom2{2, 4, 1, 3};
    EXPECT_EQ(expectedVertices, traversedNodes);
    EXPECT_EQ(expectedVerticesFrom2, traversedNodesFrom2);
}
