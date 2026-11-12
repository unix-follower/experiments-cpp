#include <vector>

namespace dsa::graph {
void dfs(const std::vector<std::vector<size_t>>& adjacencyListGraph, size_t startVertex);

std::vector<size_t> dfsWithStack(const std::vector<std::vector<size_t>>& adjacencyListGraph,
                                 size_t startVertex);
} // namespace dsa::graph
