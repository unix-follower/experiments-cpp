#include "dijkstra_algorithm.hpp"
#include <cmath>
#include <memory>

namespace dsa::graph {
double dijkstra(std::vector<std::vector<std::pair<int, double>>>* adjacencyListGraph,
                int startVertex,
                int targetVertex)
{
    const size_t numberOfVertices = adjacencyListGraph->size();

    // Assume that all nodes are unreachable from the source vertex, set all to ∞ by default
    std::vector<double> distances(numberOfVertices, INFINITY);

    MinHeap minHeap;

    // Set distance to the source vertex to 0
    minHeap.push(std::make_pair(0, startVertex));
    distances[startVertex] = 0;

    while (!minHeap.empty()) {
        auto [currentDistance, currentNode] = minHeap.top();

        minHeap.pop();

        for (const auto& [nextVertex, weight] : (*adjacencyListGraph)[currentNode]) {
            // Minimizing distances
            const double distanceToNextVertex = currentDistance + weight;
            if (distanceToNextVertex < distances[nextVertex]) {
                distances[nextVertex] = distanceToNextVertex;
                minHeap.push({distanceToNextVertex, nextVertex});
            }
        }
    }
    if (distances[targetVertex] != INFINITY) {
        return distances[targetVertex];
    }
    return -1;
}
} // namespace dsa::graph
