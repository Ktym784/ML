#include <iostream>
#include <vector>
#include <limits>


using namespace std;

const int WEIGHT = 100; 
const int INF = numeric_limits<int>::max(); 


void dijkstra(int graph[WEIGHT][WEIGHT], int V, int start, int end) {
    int dist[WEIGHT]; 
    int parent[WEIGHT]; 
    bool visited[WEIGHT] = { false }; 

    for (int i = 0; i < V; i++) {
        dist[i] = INF; 
        parent[i] = -1;
    }
    dist[start] = 0; 


    for (int i = 0; i < V - 1; i++) {
   
        int minDist = INF;
        int u = -1;
        for (int j = 0; j < V; j++) {
            if (!visited[j] && dist[j] < minDist) {
                minDist = dist[j];
                u = j;
            }
        }

      
        if (u == -1)
            break;

        visited[u] = true; 

       
        for (int v = 0; v < V; v++) {
            if (graph[u][v] != 0 && !visited[v]) { 
                if (dist[u] + graph[u][v] < dist[v]) {
                    dist[v] = dist[u] + graph[u][v];
                    parent[v] = u; 
                }
            }
        }
    }

 
    vector<int> path;
    for (int at = end; at != -1; at = parent[at]) {
        path.push_back(at);
    }
    reverse(path.begin(), path.end()); 

   
    if (dist[end] == INF) {
        cout << "Нет пути от вершины " << start + 1 << " до вершины " << end + 1 << endl;
    }
    else {
        cout << "Кратчайший путь от вершины " << start + 1 << " до вершины " << end + 1 << ":\n";
        for (int i : path) {
            cout << i + 1 << " ";
        }
        cout << "\nСуммарная стоимость пути: " << dist[end] << endl;
    }
}

int main() {
    setlocale(LC_ALL, "Russian");
    int V, E;
    cout << "Введите количество вершин: ";
    cin >> V;
    cout << "Введите количество рёбер: ";
    cin >> E;

    int graph[WEIGHT][WEIGHT] = { 0 }; 
    cout << "Введите рёбра (u, v, вес):\n";
    for (int i = 0; i < E; i++) {
        int u, v, weight;
        cin >> u >> v >> weight;
        graph[u - 1][v - 1] = weight; 
        graph[v - 1][u - 1] = weight; 
    }

    int start, end;
    cout << "Введите начальную и конечную вершины: ";
    cin >> start >> end;

  
    dijkstra(graph, V, start - 1, end - 1);

    return 0;
}