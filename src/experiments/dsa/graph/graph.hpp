#pragma once

#include <list>
#include <map>
#include <utility>
#include <vector>

namespace dsa::graph {
template <typename T> class Graph {
    int totalVerticies;
    std::map<T, std::list<T>> adjacencyListGraph;

  public:
    Graph() = default;

    explicit Graph(int totalNodes) : totalVerticies(totalNodes) {}

    int getTotalVerticies() const
    {
        return totalVerticies;
    }

    void addEdge(T from, T to, bool bidirectional = true)
    {
        adjacencyListGraph[from].push_back(to);
        if (bidirectional) {
            adjacencyListGraph[to].push_back(from);
        }
    }

    const std::map<T, std::list<T>>& getGraph() const
    {
        return adjacencyListGraph;
    }
};

void addEdge(std::vector<std::vector<std::pair<int, double>>>* adjacencyListGraph,
             int from,
             int to,
             double weight);

/**
 * @param adjacencyListGraph an undirected graph
 */
void addUndirectedBidirectionalEdge(std::vector<std::vector<size_t>>* adjacencyListGraph, size_t from, size_t to);

void addUndirectedEdge(std::vector<std::vector<size_t>>* adjacencyListGraph, size_t from, size_t to);
} // namespace dsa::graph
