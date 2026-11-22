#include "experiments/dsa/graph/topological_sort.hpp"
#include <gtest/gtest.h>

TEST(TopologicalSortTest, topsortWith2Paths)
{
    // given
    const int nodes = 6;
    dsa::graph::Graph<int> graph(nodes);
    //     0
    //    /  \
    //   4    5
    //   |    |
    //   1    2
    //    \  /
    //     3
    graph.addEdge(4, 0, false);
    graph.addEdge(5, 0, false);
    graph.addEdge(5, 2, false);
    graph.addEdge(2, 3, false);
    graph.addEdge(3, 1, false);
    graph.addEdge(4, 1, false);
    // when
    std::vector<int> topologicalOrder = dsa::graph::topologicalSort<int>(graph);
    // then
    std::vector expectedOrdering = {5, 4, 2, 3, 1, 0};
    EXPECT_EQ(expectedOrdering, topologicalOrder);
}

TEST(TopologicalSortTest, topsortWithRhombusAndSidePath)
{
    // given
    const int nodes = 5;
    dsa::graph::Graph<int> graph(nodes);
    //   0
    //  /  \
    // 1 -- 2 - 4
    //  \  /
    //   3
    graph.addEdge(0, 1, false);
    graph.addEdge(0, 2, false);
    graph.addEdge(1, 2, false);
    graph.addEdge(2, 3, false);
    graph.addEdge(1, 3, false);
    graph.addEdge(2, 4, false);
    // when
    const std::vector<int> topologicalOrder = dsa::graph::topologicalSort<int>(graph);
    // then
    const std::vector expectedOrdering = {0, 1, 2, 4, 3};
    EXPECT_EQ(expectedOrdering, topologicalOrder);
}
