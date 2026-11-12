#include "depth_first_search.hpp"
#include <algorithm>
#include <iostream>
#include <stack>

namespace dsa::graph {
constexpr int WHITE = 0; // indicates the node hasn't been explored
constexpr int GREY = 1;  // indicates node is in stack waiting to be explored
constexpr int BLACK = 2; // indicates node has already been explored

void exploreVertex(const std::vector<std::vector<size_t>>& adjacencyListGraph,
                   const size_t vertex,
                   std::vector<bool>* visitedVertices)
{
    std::cout << vertex + 1 << " ";
    (*visitedVertices)[vertex] = true;
    for (auto connectedVertex : adjacencyListGraph[vertex]) {
        if (!(*visitedVertices)[connectedVertex]) {
            exploreVertex(adjacencyListGraph, connectedVertex, visitedVertices);
        }
    }
}

void dfs(const std::vector<std::vector<size_t>>& adjacencyListGraph, size_t startVertex)
{
    size_t vertices = adjacencyListGraph.size();

    // Mark all vertices as unvisited
    std::vector<bool> visited(vertices, false);
    exploreVertex(adjacencyListGraph, startVertex, &visited);
}

void dfsExplore(const std::vector<std::vector<size_t>>& adjacencyListGraph,
                std::stack<size_t>& stack,
                std::vector<size_t>& visited,
                std::vector<size_t>& traversedPath,
                const size_t vertex)
{
    if (visited[vertex] == GREY) {
        // Push the node to the final result vector
        traversedPath.push_back(vertex + 1);

        // Exploring the neighbours of the current node
        for (auto connectedVertex : adjacencyListGraph[vertex]) {
            stack.push(connectedVertex);
            if (visited[connectedVertex] != BLACK) {
                visited[connectedVertex] = GREY;
            }
        }
        visited[vertex] = BLACK; // Node has been explored
    }
}

/**
 * @details
 * Time Complexity: O(|V| + |E|)
 *
 * @return vector with nodes stored in the order of DFS traversal
 */
std::vector<size_t> dfsWithStack(const std::vector<std::vector<size_t>>& adjacencyListGraph,
                                 size_t startVertex)
{
    // Mark all vertices as unvisited
    std::vector<size_t> visited(adjacencyListGraph.size(), WHITE);
    std::vector<size_t> traversedPath;

    visited[startVertex] = GREY;
    std::stack<size_t> stack;
    stack.push(startVertex);

    // While stack is not empty, keep exploring the node on top of the stack
    while (!stack.empty()) {
        const size_t vertex = stack.top();
        stack.pop();

        dfsExplore(adjacencyListGraph, stack, visited, traversedPath, vertex);
    }
    return traversedPath;
}
} // namespace dsa::graph
