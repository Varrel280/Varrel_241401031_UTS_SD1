#include <iostream>
#include <queue>
#include <vector>
#include <string>
using namespace std;

#define INF 9999

// Struktur Graph
class Graph {
public:
    int V;
    vector<vector<pair<int, int>>> adj;

    Graph(int V) {
        this->V = V;
        adj.resize(V);
    }

    void addEdge(int u, int v, int w) {
        adj[u].push_back({v, w});
        adj[v].push_back({u, w}); // graf tidak berarah
    }

    // DFS (rekursif)
    void DFSUtil(int v, vector<bool>& visited) {
        visited[v] = true;
        cout << char('A' + v);
        for (auto& it : adj[v]) {
            int next = it.first;
            if (!visited[next]) {
                cout << " → ";
                DFSUtil(next, visited);
            }
        }
    }

    void DFS(int start) {
        vector<bool> visited(V, false);
        cout << "PENJELAJAHAN PARUL (DFS dari A):\n";
        DFSUtil(start, visited);
        cout << endl << endl;
    }

    // BFS mencari jalur terpendek dari A ke E
    void BFSShortest(int start, int goal, vector<string> namaKota) {
        vector<int> dist(V, INF);
        vector<int> parent(V, -1);
        queue<int> q;

        dist[start] = 0;
        q.push(start);

        while (!q.empty()) {
            int u = q.front(); q.pop();
            for (auto& edge : adj[u]) {
                int v = edge.first;
                int w = edge.second;
                if (dist[v] == INF) {
                    dist[v] = dist[u] + w;
                    parent[v] = u;
                    q.push(v);
                }
            }
        }

        // Rekonstruksi jalur
        vector<int> path;
        for (int v = goal; v != -1; v = parent[v]) {
            path.insert(path.begin(), v);
        }

        cout << "JALUR TERCEPAT PARUL (BFS):\n";
        int totalJarak = 0;
        for (size_t i = 0; i < path.size(); i++) {
            cout << namaKota[path[i]] << " (" << char('A' + path[i]) << ")\n";
            if (i + 1 < path.size()) {
                for (auto& e : adj[path[i]]) {
                    if (e.first == path[i + 1]) {
                        cout << e.second << "m\n";
                        totalJarak += e.second;
                        break;
                    }
                }
            }
        }

        cout << "\nJalur terpendek: ";
        for (size_t i = 0; i < path.size(); i++) {
            cout << char('A' + path[i]);
            if (i + 1 < path.size()) cout << " → ";
        }

        cout << "\nTotal langkah: " << path.size() - 1 << " edge";
        cout << "\nTotal jarak: " << totalJarak << " meter" << endl;
    }
};

int main() {
    system("chcp 65001 > nul"); // Set console ke UTF-8 otomatis

    Graph g(5);
    vector<string> namaKota = {
        "Ikan Bakar Pak Harry",
        "Gudang Kaleng Bekas",
        "Sushi Kucing Alya",
        "Kedai IKLC",
        "Pasar Ikan Tengah Malam"
    };

    // Tambah edge (graf)
    g.addEdge(0, 1, 5); // A-B
    g.addEdge(0, 2, 2); // A-C
    g.addEdge(1, 3, 4); // B-D
    g.addEdge(2, 3, 1); // C-D
    g.addEdge(3, 4, 3); // D-E

    // Output
    g.DFS(0);         // DFS dari A
    g.BFSShortest(0, 4, namaKota);  // BFS dari A ke E

    return 0;
}
