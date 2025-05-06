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

Node *createNode(string keyword, string meaning)
{
        Node *newNode = new Node();
        newNode->keyword = keyword;
        newNode->meaning = meaning;
        newNode->left = newNode->right = nullptr;
        return newNode;
}

Node *insert(Node *root, string keyword, string meaning)
{
        if (root == nullptr)
                return createNode(keyword, meaning);

        if (keyword < root->keyword)
                root->left = insert(root->left, keyword, meaning);
        else if (keyword > root->keyword)
                root->right = insert(root->right, keyword, meaning);

        return root;
}

Node *search(Node *root, string keyword)
{
        if (root == nullptr || root->keyword == keyword)
                return root;

        if (keyword < root->keyword)
                return search(root->left, keyword);
        else
                return search(root->right, keyword);
}

int findMaxComparisons(Node *root)
{
        if (root == nullptr)
                return 0;
        int leftDepth = findMaxComparisons(root->left);
        int rightDepth = findMaxComparisons(root->right);
        return max(leftDepth, rightDepth) + 1;
}

// Function to update meaning of a keyword
void updateMeaning(Node *root, string keyword, string newMeaning)
{
        Node *node = search(root, keyword);
        if (node != nullptr)
                node->meaning = newMeaning;
        else
                cout << "Keyword not found!" << endl;
}

// Function to find the minimum node (for deletion)
Node *findMin(Node *root)
{
        while (root && root->left != nullptr)
                root = root->left;
        return root;
}

Node *deleteNode(Node *root, string keyword)
{
        if (root == nullptr)
                return root;

        if (keyword < root->keyword)
                root->left = deleteNode(root->left, keyword);
        else if (keyword > root->keyword)
                root->right = deleteNode(root->right, keyword);
        else
        {
                if (root->left == nullptr)
                {
                        Node *temp = root->right;
                        delete root;
                        return temp;
                }
                else if (root->right == nullptr)
                {
                        Node *temp = root->left;
                        delete root;
                        return temp;
                }

                Node *temp = findMin(root->right);
                root->keyword = temp->keyword;
                root->meaning = temp->meaning;
                root->right = deleteNode(root->right, temp->keyword);
        }
        return root;
}

void inorder(Node *root)
{
        if (root != nullptr)
        {
                inorder(root->left);
                cout << root->keyword << ": " << root->meaning << endl;
                inorder(root->right);
        }
}

void reverseInorder(Node *root)
{
        if (root != nullptr)
        {
                reverseInorder(root->right);
                cout << root->keyword << ": " << root->meaning << endl;
                reverseInorder(root->left);
        }
}

int main()
{
        Node *root = nullptr;
        int choice;
        string keyword, meaning;

        while (true)
        {
                cout << "\nDictionary Menu: \n";
                cout << "1. Add a new keyword\n";
                cout << "2. Delete a keyword\n";
                cout << "3. Update meaning\n";
                cout << "4. Display dictionary in ascending order\n";
                cout << "5. Display dictionary in descending order\n";
                cout << "6. Find maximum comparisons for keyword search\n";
                cout << "7. Exit\n";
                cout << "Enter your choice: ";
                cin >> choice;

                switch (choice)
                {
                case 1:
                        cout << "Enter keyword: ";
                        cin >> keyword;
                        cout << "Enter meaning: ";
                        cin.ignore(); // To clear the buffer for getline
                        getline(cin, meaning);
                        root = insert(root, keyword, meaning);
                        break;

                case 2:
                        cout << "Enter keyword to delete: ";
                        cin >> keyword;
                        root = deleteNode(root, keyword);
                        cout << "Keyword deleted!" << endl;
                        break;

                case 3:
                        cout << "Enter keyword to update: ";
                        cin >> keyword;
                        cout << "Enter new meaning: ";
                        cin.ignore();
                        getline(cin, meaning);
                        updateMeaning(root, keyword, meaning);
                        break;

                case 4:
                        cout << "Dictionary in ascending order:\n";
                        inorder(root);
                        break;

                case 5:
                        cout << "Dictionary in descending order:\n";
                        reverseInorder(root);
                        break;

                case 6:
                        cout << "Maximum comparisons for searching any keyword: "
                             << findMaxComparisons(root) << endl;
                        break;

                case 7:
                        cout << "Exiting...\n";
                        return 0;

                default:
                        cout << "Invalid choice! Please try again.\n";
                }
        }
}