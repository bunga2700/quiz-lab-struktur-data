#include <iostream>
#include <vector>
#include <queue>
#include <climits>
using namespace std;

class Graph {
private:
    int numberVertex;
    vector<vector<int>> adjMatrix;

    void dfsUntil(int currentVertex, vector<bool>& visited) {
        visited[currentVertex] = true;
        cout << "Visited " << (char)('A' + currentVertex) << endl;
        for (int i = 0; i < numberVertex; i++) {
            if (adjMatrix[currentVertex][i] != 0 && !visited[i]) {
                dfsUntil(i, visited);
            }
        }
    }

    void printPath(const vector<int>& parent, int target) {
        if (parent[target] == -1) {
            cout << (char)('A' + target);
            return;
        }
        printPath(parent, parent[target]);
        cout << " -> " << (char)('A' + target);
    }

public:
    Graph(int banyakTitik) {
        numberVertex = banyakTitik;
        adjMatrix.resize(numberVertex, vector<int>(numberVertex, 0));
    }
   void addEdge(int i, int j, int weight) {
        if (i >= 0 && i < numberVertex && j >= 0 && j < numberVertex) {
            adjMatrix[i][j] = weight;
            adjMatrix[j][i] = weight;
        } else {
            cout << "Index nonvalid" << endl;
        }
    }
    void printAdjMatrix() {
        cout << "  A B C D E F" << endl; 
        
        for (int i = 0; i < numberVertex; i++) {
            cout << (char)('A' + i) << " ";
            for (int j = 0; j < numberVertex; j++) {
                if (adjMatrix[i][j] == 0) {
                    cout << "0 ";
                } else {
                    cout << adjMatrix[i][j] << " ";
                }
            }
            cout << endl;
        }
    }

    // fungsi BFS
    void bfs(int startVertex) {
        vector<bool> visited(numberVertex, false);
        queue<int> titikVisit;
        
        visited[startVertex] = true;
        titikVisit.push(startVertex);
        
        cout << "Hasil BFS:" << endl;
        while (!titikVisit.empty()) {
            int currentVertex = titikVisit.front();
            titikVisit.pop();
            cout << "Visited " << (char)('A' + currentVertex) << endl;
            
            for (int i = 0; i < numberVertex; i++) {
                if (adjMatrix[currentVertex][i] != 0 && !visited[i]) {
                    visited[i] = true;
                    titikVisit.push(i);
                }
            }
        }
    }

    // fungsi DFS
    void dfs(int startVertex) {
        vector<bool> visited(numberVertex, false);
        cout << "Hasil DFS:" << endl;
        dfsUntil(startVertex, visited);
    }

    // fungsi Dijkstra dengan pelacakan rute
    void dijkstra(int source, int target) {
        vector<int> distance(numberVertex, INT_MAX);
        vector<bool> visited(numberVertex, false);
        vector<int> parent(numberVertex, -1);

        distance[source] = 0;

        for (int i = 0; i < numberVertex; i++) {
            int u = -1;
            for (int j = 0; j < numberVertex; j++) {
                if (!visited[j] && (u == -1 || distance[j] < distance[u])) {
                    u = j;
                }
            }
            
            if (u == -1 || distance[u] == INT_MAX) break;
            
            visited[u] = true;

            for (int v = 0; v < numberVertex; v++) {
                if (adjMatrix[u][v] != 0 && !visited[v]) {
                    int newDistance = distance[u] + adjMatrix[u][v];
                    if (newDistance < distance[v]) {
                        distance[v] = newDistance;
                        parent[v] = u;
                    }
                }
            }
        }

        cout << "Jarak terpendek dari vertex " << (char)('A' + source) << " ke " << (char)('A' + target) << ":" << endl;
        if (distance[target] == INT_MAX) {
            cout << "Tidak terjangkau" << endl;
        } else {
            cout << "Jarak: " << distance[target] << endl;
            cout << "Rute: ";
            printPath(parent, target);
            cout << endl;
        }
    }
};

int main() {
    Graph graphh(6);
    
    graphh.addEdge(0, 1, 4);
    graphh.addEdge(0, 2, 2);
    graphh.addEdge(1, 2, 1);
    graphh.addEdge(1, 3, 5);
    graphh.addEdge(1, 4, 3);
    graphh.addEdge(2, 3, 8);
    graphh.addEdge(2, 4, 6);
    graphh.addEdge(3, 4, 2);
    graphh.addEdge(3, 5, 4);
    graphh.addEdge(4, 5, 3);

    int pilihan;
    do {
        cout << endl;
        cout << "===== SISTEM PENCARIAN RUTE KAMPUS =====" << endl;
        cout << "1. Tampilkan Adjacency Matrix" << endl;
        cout << "2. BFS (Breadth-First Search)" << endl;
        cout << "3. DFS (Depth-First Search)" << endl;
        cout << "4. Cari Rute Terpendek (Dijkstra)" << endl;
        cout << "0. Keluar" << endl;
        cout << "Pilih menu: ";
        cin >> pilihan;
        cout << endl;

        switch (pilihan) {
            case 1:
                graphh.printAdjMatrix();
                break;
            case 2: {
                char start;
                cout << "Masukkan vertex awal (A-F): ";
                cin >> start;
                int idx = start - 'A';
                if (idx >= 0 && idx < 6) graphh.bfs(idx);
                else cout << "Index nonvalid" << endl;
                break;
            }
            case 3: {
                char start;
                cout << "Masukkan vertex awal (A-F): ";
                cin >> start;
                int idx = start - 'A';
                if (idx >= 0 && idx < 6) graphh.dfs(idx);
                else cout << "Index nonvalid" << endl;
                break;
            }
            case 4: {
                char start, target;
                cout << "Masukkan vertex awal (A-F): ";
                cin >> start;
                cout << "Masukkan vertex tujuan (A-F): ";
                cin >> target;
                int idxStart = start - 'A';
                int idxTarget = target - 'A';
                
                if (idxStart >= 0 && idxStart < 6 && idxTarget >= 0 && idxTarget < 6) {
                    graphh.dijkstra(idxStart, idxTarget);
                } else {
                    cout << "Index nonvalid" << endl;
                }
                break;
            }
            case 0:
                cout << "Program selesai." << endl;
                break;
            default:
                cout << "Pilihan tidak valid." << endl;
        }
    } while (pilihan != 0);

    return 0;
}