
#include <iostream>
#include <vector>
#include <queue>
using namespace std;

class Graph {
    int vertices;
    vector<vector<int>> adj;

    void dfsHelper(int node, vector<bool>& visited) {
        visited[node] = true;
        cout << node << " ";

        for (int neighbour : adj[node]) {
            if (!visited[neighbour])
                dfsHelper(neighbour, visited);
        }
    }

public:
    Graph(int v) {
        vertices = v;
        adj.resize(v);
    }

    void addEdge(int u, int v) {
        if (u < 0 || u >= vertices || v < 0 || v >= vertices) {
            cout << "Invalid vertex.\n";
            return;
        }

        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    void displayGraph() {
        cout << "\nAdjacency List:\n";

        for (int i = 0; i < vertices; i++) {
            cout << i << ": ";
            for (int neighbour : adj[i])
                cout << neighbour << " ";
            cout << "\n";
        }
    }

    void bfs(int start) {
        if (start < 0 || start >= vertices) {
            cout << "Invalid starting vertex.\n";
            return;
        }

        vector<bool> visited(vertices, false);
        queue<int> q;

        visited[start] = true;
        q.push(start);

        cout << "BFS: ";

        while (!q.empty()) {
            int node = q.front();
            q.pop();

            cout << node << " ";

            for (int neighbour : adj[node]) {
                if (!visited[neighbour]) {
                    visited[neighbour] = true;
                    q.push(neighbour);
                }
            }
        }

        cout << "\n";
    }

    void dfs(int start) {
        if (start < 0 || start >= vertices) {
            cout << "Invalid starting vertex.\n";
            return;
        }

        vector<bool> visited(vertices, false);
        cout << "DFS: ";
        dfsHelper(start, visited);
        cout << "\n";
    }
};

int main() {
    Graph g(6);

    g.addEdge(0, 1);
    g.addEdge(0, 2);
    g.addEdge(1, 3);
    g.addEdge(1, 4);
    g.addEdge(2, 5);

    int choice, start;

    do {
        cout << "\n--- Academic Resource Graph ---\n";
        cout << "1. Display Graph\n2. BFS Traversal\n";
        cout << "3. DFS Traversal\n0. Exit\nChoice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                g.displayGraph();
                break;
            case 2:
                cout << "Enter starting vertex (0-5): ";
                cin >> start;
                g.bfs(start);
                break;
            case 3:
                cout << "Enter starting vertex (0-5): ";
                cin >> start;
                g.dfs(start);
                break;
            case 0:
                cout << "Exiting.\n";
                break;
            default:
                cout << "Invalid choice.\n";
        }
    } while (choice != 0);

    return 0;
}
