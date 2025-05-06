#include <iostream>
using namespace std;

const int SIZE = 10;

struct Node
{
    string key;
    string value;
    Node(string k, string v) : key(k), value(v) {}
};

Node *table[SIZE] = {nullptr};

int hashFunc(string key)
{
    int sum = 0;
    for (char c : key)
        sum += c;
    return sum % SIZE;
}

void insert(string key, string value)
{
    int index = hashFunc(key);
    for (int i = 0; i < SIZE; i++)
    {
        int pos = (index + i) % SIZE;
        if (table[pos] == nullptr || table[pos]->key == key)
        {
            table[pos] = new Node(key, value);
            cout << "Inserted.\n";
            return;
        }
    }
    cout << "Hash table full!\n";
}

void find(string key)
{
    int index = hashFunc(key);
    for (int i = 0; i < SIZE; i++)
    {
        int pos = (index + i) % SIZE;
        if (table[pos] == nullptr)
            break;
        if (table[pos]->key == key)
        {
            cout << "Found: " << table[pos]->value << "\n";
            return;
        }
    }
    cout << "Not found.\n";
}

void remove(string key)
{
    int index = hashFunc(key);
    for (int i = 0; i < SIZE; i++)
    {
        int pos = (index + i) % SIZE;
        if (table[pos] == nullptr)
            break;
        if (table[pos]->key == key)
        {
            delete table[pos];
            table[pos] = nullptr;
            cout << "Deleted.\n";
            return;
        }
    }
    cout << "Not found.\n";
}

void display()
{
    cout << "\nDictionary:\n";
    for (int i = 0; i < SIZE; i++)
    {
        if (table[i] != nullptr)
            cout << table[i]->key << ": " << table[i]->value << "\n";
    }
}

int main()
{
    int choice;
    string key, value;

    while (true)
    {
        cout << "\n1.Insert 2.Find 3.Delete 4.Display 5.Exit\nChoice: ";
        cin >> choice;
        switch (choice)
        {
        case 1:
            cout << "Key: ";
            cin >> key;
            cout << "Value: ";
            cin >> value;
            insert(key, value);
            break;
        case 2:
            cout << "Key: ";
            cin >> key;
            find(key);
            break;
        case 3:
            cout << "Key: ";
            cin >> key;
            remove(key);
            break;
        case 4:
            display();
            break;
        case 5:
            return 0;
        default:
            cout << "Invalid!\n";
        }
    }
}
