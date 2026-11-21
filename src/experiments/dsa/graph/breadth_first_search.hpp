#pragma once

#include "graph.hpp"

#include <algorithm>
#include <iostream>
#include <queue>

namespace dsa::graph {
template <typename T>
void exploreNeighbors(std::queue<T>& traversePath,
                      std::map<T, bool>& visited,
                      const std::list<T>& neighbourVertices)
{
    for (const T& neighbour : neighbourVertices) {
        if (!visited[neighbour]) {
            // The neighbour is unvisited
            traversePath.push(neighbour);
            // Mark as visited
            visited[neighbour] = true;
        }
    }
}

/**
 * \details
 * Time Complexity O(|V| + |E|)
 *
 *  @return a mapping which maps the nodes to a boolean value representing whether the
 *  node was traversed or not.
 */
template <typename T> std::map<T, bool> bfs(const Graph<T>& graph, T startVertex)
{
    std::map<T, bool> visited;
    // Mark all vertices as unvisited
    for (const auto& adjacencyListMap : graph.getGraph()) {
        visited[adjacencyListMap.first] = false;
        for (const auto& node : graph.getGraph().at(adjacencyListMap.first)) {
            visited[node] = false;
        }
    }

    std::queue<T> traversePath;

    traversePath.push(startVertex);
    // Mark the start vertex as visited
    visited[startVertex] = true;
    const std::map<T, std::list<T>>& adjacencyListMap = graph.getGraph();
    while (!traversePath.empty()) {
        const T node = traversePath.front();
        traversePath.pop();

        const auto it = adjacencyListMap.find(node);
        if (it != adjacencyListMap.end()) {
            exploreNeighbors(traversePath, visited, it->second);
        }
    }
    return visited;
}
} // namespace dsa::graph
