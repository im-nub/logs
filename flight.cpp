#include <iostream>
#include <string>
using namespace std;

const int MAX = 10;

int matrix[MAX][MAX] = {0};
bool visited[MAX] = {false};
string city[MAX];
int num_nodes;

void dfs(int node)
{
    visited[node] = true;
    cout << " -> " << city[node];

    for (int i = 0; i < num_nodes; i++)
    {
        if (matrix[node][i] > 0 && !visited[i])
        {
            dfs(i);
        }
    }
}

bool isConnected()
{
    dfs(0);

    for (int i = 0; i < num_nodes; i++)
    {
        if (!visited[i])
            return false;
    }
    return true;
}

int main()
{
    cout << "Enter number of cities (max 10): ";
    cin >> num_nodes;

    for (int i = 0; i < num_nodes; i++)
    {
        cout << "Enter name of city " << i + 1 << ": ";
        cin >> city[i];
    }

    for (int i = 0; i < num_nodes; i++)
    {
        for (int j = 0; j < num_nodes; j++)
        {
            if (i != j)
            {
                cout << "Enter cost of flight from " << city[i] << " to " << city[j] << " (0 if none): ";
                cin >> matrix[i][j];
            }
        }
    }

    cout << "\nFlight connectivity path:";
    if (isConnected())
    {
        cout << "\nThe graph is connected.\n";
    }
    else
    {
        cout << "\nThe graph is not connected.\n";
    }

    return 0;
}
