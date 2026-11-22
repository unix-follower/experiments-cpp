#pragma once

#include "graph.hpp"

#include <stack>
#include <vector>

namespace dsa::graph {
namespace detail {
/**
 * @param path Contains the vertices for topological sorting
 */
template <typename T>
void dfs(int startVertex, std::vector<int>& visited,
         const Graph<T>& adjacencyListGraph, std::stack<int>& path) {
    visited[startVertex] = 1;
    const auto& adjacencyListMap = adjacencyListGraph.getGraph();
    if (const auto it = adjacencyListMap.find(startVertex); it != adjacencyListMap.end()) {
        for (int neighbour : adjacencyListMap.at(startVertex)) {
            if (!visited[neighbour]) {
                dfs(neighbour, visited, adjacencyListGraph, path);
            }
        }
    }
    path.push(startVertex);
}
}

template <typename T>
std::vector<int> topologicalSort(const Graph<T>& adjacencyListGraph) {
    const int totalVerticies = adjacencyListGraph.getTotalVerticies();
    std::vector visited(totalVerticies, 0);
    std::stack<int> path;

    for (int vertex = 0; vertex < totalVerticies; vertex++) {
        if (!visited[vertex]) {
            detail::dfs(vertex, visited, adjacencyListGraph, path);
        }
    }

    std::vector<int> topologicalOrder;
    while (!path.empty()) {
        const int vertex = path.top();
        path.pop();
        topologicalOrder.push_back(vertex);
    }

    return topologicalOrder;
}
}  // namespace dsa::graph
