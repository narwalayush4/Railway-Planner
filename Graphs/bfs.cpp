#include <iostream>
#include <vector>
#include <queue>

using namespace std;

/**
 * Performs Breadth-First Search (BFS) on a graph from a starting node.
 * 
 * @param graph An adjacency list representing the graph.
 * @param start The starting node for BFS.
 */
void bfs(const vector<vector<int>>& graph, int start) {
    int n = graph.size();          // Number of nodes in the graph
    vector<bool> visited(n, false); // Visited status of nodes
    queue<int> q;                  // Queue for BFS

    visited[start] = true;        // Mark the start node as visited
    q.push(start);                // Enqueue the start node

    while (!q.empty()) {
        int node = q.front();      // Get the front node from the queue
        q.pop();                  // Remove the node from the queue

        cout << node << " ";      // Print the current node

        // Traverse all the adjacent nodes of the current node
        for (int neighbor : graph[node]) {
            if (!visited[neighbor]) {
                visited[neighbor] = true; // Mark neighbor as visited
                q.push(neighbor);         // Enqueue the neighbor
            }
        }
    }
}

int main() {
    // Example usage
    int n = 6; // Number of nodes
    vector<vector<int>> graph(n);

    // Adding edges to the graph
    graph[0].push_back(1);
    graph[0].push_back(2);
    graph[1].push_back(2);
    graph[1].push_back(3);
    graph[2].push_back(4);
    graph[3].push_back(4);

    cout << "BFS starting from node 0:" << endl;
    bfs(graph, 0); // Perform BFS starting from node 0

    return 0;
}
