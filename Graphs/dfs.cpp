#include <iostream>
#include <vector>

using namespace std;

/**
 * Performs Depth-First Search (DFS) on a graph from a starting node.
 * 
 * @param graph An adjacency list representing the graph.
 * @param node The current node in DFS.
 * @param visited A vector to keep track of visited nodes.
 */
void dfsUtil(const vector<vector<int>>& graph, int node, vector<bool>& visited) {
    visited[node] = true;           // Mark the node as visited
    cout << node << " ";           // Print the current node

    // Traverse all the adjacent nodes of the current node
    for (int neighbor : graph[node]) {
        if (!visited[neighbor]) {
            dfsUtil(graph, neighbor, visited); // Recur for unvisited neighbors
        }
    }
}

/**
 * Initiates DFS from a given start node.
 * 
 * @param graph An adjacency list representing the graph.
 * @param start The starting node for DFS.
 */
void dfs(const vector<vector<int>>& graph, int start) {
    int n = graph.size();          // Number of nodes in the graph
    vector<bool> visited(n, false); // Visited status of nodes
    dfsUtil(graph, start, visited); // Call the utility function for DFS
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

    cout << "DFS starting from node 0:" << endl;
    dfs(graph, 0); // Perform DFS starting from node 0

    return 0;
}
