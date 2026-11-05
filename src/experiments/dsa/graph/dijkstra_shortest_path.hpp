#include <queue>

namespace dsa::graph {
// pair(distance, vertex)
using MinHeap = std::priority_queue<std::pair<double, int>,
                                    std::vector<std::pair<double, int>>,
                                    std::greater<std::pair<double, int>>>;

void addEdge(std::vector<std::vector<std::pair<int, double>>>* adjacencyListGraph,
             int from,
             int to,
             double weight);
/**
 * https://en.wikipedia.org/wiki/Dijkstra%27s_algorithm
 * @return shortest distance if target is reachable from source. Otherwise -1.
 */
double dijkstra(std::vector<std::vector<std::pair<int, double>>>* adjacencyListGraph,
                int startVertex,
                int targetVertex);
} // namespace dsa::graph
