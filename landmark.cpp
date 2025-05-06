#include <iostream>
#include <cstring>
using namespace std;

const int SIZE = 5;
string nodes[SIZE] = {"College", "Library", "Canteen", "Hostel", "Playground"};
int adj[SIZE][SIZE] = {0};
int visited[SIZE];

// Function to get index from node name
int getIndex(string name) {
    for (int i = 0; i < SIZE; i++) {
        if (nodes[i] == name)
            return i;
    }
    return -1;
}

// DFS using recursion
void DFS(int start) {
    cout << nodes[start] << " ";
    visited[start] = 1;

    for (int i = 0; i < SIZE; i++) {
        if (adj[start][i] == 1 && visited[i] == 0) {
            DFS(i);
        }
    }
}

// BFS using simple arrays
void BFS(int start) {
    int queue[SIZE], front = 0, rear = 0;
    int visitedBFS[SIZE] = {0};

    queue[rear++] = start;
    visitedBFS[start] = 1;

    while (front < rear) {
        int curr = queue[front++];
        cout << nodes[curr] << " ";

        for (int i = 0; i < SIZE; i++) {
            if (adj[curr][i] == 1 && visitedBFS[i] == 0) {
                queue[rear++] = i;
                visitedBFS[i] = 1;
            }
        }
    }
}

int main() {
    // Create graph (undirected)
    adj[0][1] = adj[1][0] = 1; // College - Library
    adj[0][2] = adj[2][0] = 1; // College - Canteen
    adj[1][3] = adj[3][1] = 1; // Library - Hostel
    adj[2][4] = adj[4][2] = 1; // Canteen - Playground

    cout << "DFS Traversal: ";
    // memset(visited, 0, sizeof(visited));
    DFS(0);  // Start from College
    cout << endl;

    cout << "BFS Traversal: ";
    BFS(0);  // Start from College
    cout << endl;

    return 0;
}