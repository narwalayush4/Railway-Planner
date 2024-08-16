#include <iostream>
#include <vector>
#include <queue>
#include <climits>

using namespace std;

/**
 * Performs Dijkstra's algorithm to find the shortest path from a starting node.
 * 
 * @param graph An adjacency list where each entry contains pairs (neighbor, weight).
 * @param start The starting node for Dijkstra's algorithm.
 */
void dijkstra(const vector<vector<pair<int, int>>>& graph, int start) {
    int n = graph.size();              // Number of nodes in the graph
    vector<int> dist(n, INT_MAX);      // Distance from start to each node
    vector<bool> visited(n, false);   // Visited status of nodes
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<>> pq; // Min-heap for selecting the node with the minimum distance

    dist[start] = 0;                  // Distance to the start node is 0
    pq.push({0, start});              // Push the start node into the priority queue

    while (!pq.empty()) {
        int u = pq.top().second;      // Get the node with the minimum distance
        pq.pop();                    // Remove the node from the priority queue

        if (visited[u]) continue;    // Skip if the node has already been visited
        visited[u] = true;          // Mark the node as visited

        // Traverse all the adjacent nodes of the current node
        for (const auto& edge : graph[u]) {
            int v = edge.first;      // Neighbor node
            int weight = edge.second; // Weight of the edge

            // Relaxation step
            if (dist[u] + weight < dist[v]) {
                dist[v] = dist[u] + weight;
                pq.push({dist[v], v}); // Update the priority queue with the new distance
            }
        }
    }

    // Print distances from start node
    for (int i = 0; i < n; ++i) {
        cout << "Distance from node " << start << " to node " << i << " is " << dist[i] << endl;
    }
}

int main() {
    // Example usage
    int n = 6; // Number of nodes
    vector<vector<pair<int, int>>> graph(n);

    // Adding edges to the graph with weights
    graph[0].emplace_back(1, 4);
    graph[0].emplace_back(2, 2);
    graph[1].emplace_back(2, 5);
    graph[1].emplace_back(3, 10);
    graph[2].emplace_back(3, 3);
    graph[3].emplace_back(4, 1);
    graph[4].emplace_back(3, 6);

    cout << "Dijkstra's algorithm starting from node 0:" << endl;
    dijkstra(graph, 0); // Perform Dijkstra's algorithm starting from node 0

    return 0;
}
