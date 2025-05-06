#include <iostream>
#include <string>
using namespace std;

struct Node
{
        string keyword;
        string meaning;
        Node *left;
        Node *right;
};

Node *root = nullptr; // Global root pointer

Node *createNode(string keyword, string meaning)
{
        Node *newNode = new Node();
        newNode->keyword = keyword;
        newNode->meaning = meaning;
        newNode->left = newNode->right = nullptr;
        return newNode;
}

// Insert node into BST
void insert(Node *&root, string keyword, string meaning)
{
        if (root == nullptr)
        {
                root = createNode(keyword, meaning);
                return;
        }

        if (keyword < root->keyword)
                insert(root->left, keyword, meaning);
        else if (keyword > root->keyword)
                insert(root->right, keyword, meaning);
        else
                cout << "Keyword already exists.\n";
}

// Search keyword
Node *search(Node *root, string keyword)
{
        if (root == nullptr || root->keyword == keyword)
                return root;

        if (keyword < root->keyword)
                return search(root->left, keyword);
        else
                return search(root->right, keyword);
}

// Update meaning
void updateMeaning(Node *root, string keyword, string newMeaning)
{
        Node *found = search(root, keyword);
        if (found)
                found->meaning = newMeaning;
        else
                cout << "Keyword not found!\n";
}

// Find min node (for deletion)
Node *findMin(Node *root)
{
        while (root && root->left)
                root = root->left;
        return root;
}

// Delete a node
void deleteNode(Node *&root, string keyword)
{
        if (root == nullptr)
                return;

        if (keyword < root->keyword)
        {
                deleteNode(root->left, keyword);
        }
        else if (keyword > root->keyword)
        {
                deleteNode(root->right, keyword);
        }
        else
        {
                // Case 1: Node has no left child
                if (root->left == nullptr)
                {
                        Node *temp = root;
                        root = root->right;
                        delete temp;
                }
                // Case 2: Node has no right child
                else if (root->right == nullptr)
                {
                        Node *temp = root;
                        root = root->left;
                        delete temp;
                }
                // Case 3: Node has no children
                else if (root->left == nullptr && root->right == nullptr)
                {
                        delete root;
                        root = nullptr;
                }
                // Case 4: Node has both children
                else
                {
                        Node *temp = findMin(root->right); // Find inorder successor
                        root->keyword = temp->keyword;
                        root->meaning = temp->meaning;
                        deleteNode(root->right, temp->keyword);
                }
        }
}

// In-order traversal (ascending)
void inorder(Node *root)
{
        if (root)
        {
                inorder(root->left);
                cout << root->keyword << " : " << root->meaning << "\n";
                inorder(root->right);
        }
}

// Reverse in-order (descending)
void reverseInorder(Node *root)
{
        if (root)
        {
                reverseInorder(root->right);
                cout << root->keyword << " : " << root->meaning << "\n";
                reverseInorder(root->left);
        }
}

// Maximum comparisons = height of BST
int findMaxComparisons(Node *root)
{
        if (!root)
                return 0;
        return 1 + max(findMaxComparisons(root->left), findMaxComparisons(root->right));
}

int main()
{
        int choice;
        string keyword, meaning;

        while (true)
        {
                cout << "\n1. Add  2. Delete  3. Update  4. Ascending  5. Descending  6. Max Comparisons  7. Exit\n";
                cout << "Enter choice: ";
                cin >> choice;

                switch (choice)
                {
                case 1:
                        cout << "Keyword: ";
                        cin >> keyword;
                        cin.ignore();
                        cout << "Meaning: ";
                        getline(cin, meaning);
                        insert(root, keyword, meaning);
                        break;
                case 2:
                        cout << "Keyword to delete: ";
                        cin >> keyword;
                        deleteNode(root, keyword);
                        break;
                case 3:
                        cout << "Keyword to update: ";
                        cin >> keyword;
                        cin.ignore();
                        cout << "New meaning: ";
                        getline(cin, meaning);
                        updateMeaning(root, keyword, meaning);
                        break;
                case 4:
                        cout << "Dictionary (A-Z):\n";
                        inorder(root);
                        break;
                case 5:
                        cout << "Dictionary (Z-A):\n";
                        reverseInorder(root);
                        break;
                case 6:
                        cout << "Max comparisons to find a keyword: " << findMaxComparisons(root) << "\n";
                        break;
                case 7:
                        return 0;
                default:
                        cout << "Invalid!\n";
                }
        }
}
