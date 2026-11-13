#include <utility>
#include <vector>

namespace dsa::graph {
void addEdge(std::vector<std::vector<std::pair<int, double>>>* adjacencyListGraph,
             int from,
             int to,
             double weight);

/**
 * @param adjacencyListGraph an undirected graph
 */
void addUndirectedBidirectionalEdge(std::vector<std::vector<size_t>>* adjacencyListGraph,
                                    const size_t from,
                                    const size_t to);

void addUndirectedEdge(std::vector<std::vector<size_t>>* adjacencyListGraph,
                       const size_t from,
                       const size_t to);
} // namespace dsa::graph
