#include <iostream>
#include <string>
using namespace std;

const int MAX = 10; // max 10 cities for safety

void dfs(int matrix[MAX][MAX], int node, bool visited[], int num_nodes, string city[]) {
    visited[node] = true;
    cout << " -> " << city[node];

    for (int i = 0; i < num_nodes; i++) {
        if (matrix[node][i] > 0 && !visited[i]) {
            dfs(matrix, i, visited, num_nodes, city);
        }
    }
}

bool isConnected(int matrix[MAX][MAX], int num_nodes, string city[]) {
    bool visited[MAX] = {false};
    dfs(matrix, 0, visited, num_nodes, city);

    for (int i = 0; i < num_nodes; i++) {
        if (!visited[i]) return false;
    }
    return true;
}

int main() {
    int num_nodes;
    cout << "Enter number of cities (max 10): ";
    cin >> num_nodes;

    string city[MAX];
    int matrix[MAX][MAX] = {0};

    
    for (int i = 0; i < num_nodes; i++) {
        cout << "Enter name of city " << i + 1 << ": ";
        cin >> city[i];
    }

    for (int i = 0; i < num_nodes; i++) {
        for (int j = 0; j < num_nodes; j++) {
            if (i != j) {
                cout << "Enter cost of flight from " << city[i] << " to " << city[j] << " (0 if none): ";
                cin >> matrix[i][j];
            }
        }
    }

    cout << "\nFlight connectivity path:";
    if (isConnected(matrix, num_nodes, city)) {
        cout << "\nThe graph is connected.\n";
    } else {
        cout << "\nThe graph is not connected.\n";
    }

    return 0;
}
