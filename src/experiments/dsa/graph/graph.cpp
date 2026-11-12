#include "graph.hpp"

namespace dsa::graph {
void addEdge(std::vector<std::vector<std::pair<int, double>>>* adjacencyListGraph,
             int from,
             int to,
             double weight)
{
    (*adjacencyListGraph)[from].push_back(std::make_pair(to, weight));
}

void addUndirectedBidirectionalEdge(std::vector<std::vector<size_t>>* adjacencyListGraph,
                                    const size_t from,
                                    const size_t to)
{
    (*adjacencyListGraph)[from - 1].push_back(to - 1);
    (*adjacencyListGraph)[to - 1].push_back(from - 1);
}

void addUndirectedEdge(std::vector<std::vector<size_t>>* adjacencyListGraph,
                       const size_t from,
                       const size_t to)
{
    (*adjacencyListGraph)[from - 1].push_back(to - 1);
}
} // namespace dsa::graph
