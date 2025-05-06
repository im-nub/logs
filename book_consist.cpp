#include <iostream>
#include <string>
using namespace std;

struct node // Node Declaration
{
    string label;
    int ch_count;
    struct node *child[10];
} *root;

class GT // Class Declaration
{
public:
    void create_tree();
    void display(node *r1);
    GT()
    {
        root = NULL;
    }
};

void GT::create_tree()
{
    int tchapters;
    root = new node;

    cin.ignore(); // To clear newline before getline

    cout << "Enter name of book: ";
    getline(cin, root->label);

    cout << "Enter number of chapters in book: ";
    cin >> tchapters;
    root->ch_count = tchapters;

    for (int i = 0; i < tchapters; i++)
    {
        root->child[i] = new node;

        cin.ignore(); // Clear newline
        
        cout << "Enter name of Chapter " << i + 1 << ": ";
        getline(cin, root->child[i]->label);

        cout << "Enter number of sections in Chapter '" << root->child[i]->label << "': ";
        cin >> root->child[i]->ch_count;

        for (int j = 0; j < root->child[i]->ch_count; j++)
        {
            root->child[i]->child[j] = new node;
            cin.ignore(); // Clear newline
            
            cout << "Enter name of Section " << j + 1 << ": ";
            getline(cin, root->child[i]->child[j]->label);
        }
    }
}

void GT::display(node *r1)
{
    if (r1 != NULL)
    {
        cout << "\n----- Book Hierarchy -----";
        cout << "\nBook Title: " << r1->label;
        for (int i = 0; i < r1->ch_count; i++)
        {
            cout << "\n  Chapter " << i + 1 << ": " << r1->child[i]->label;
            cout << "\n    Sections:";
            for (int j = 0; j < r1->child[i]->ch_count; j++)
            {
                cout << "\n      - " << r1->child[i]->child[j]->label;
            }
        }
        cout << endl;
    }
    else
    {
        cout << "Book tree is empty.\n";
    }
}

int main()
{
    int choice;
    GT gt;

    while (true)
    {
        cout << "\n-----------------\n";
        cout << "Book Tree Creation\n";
        cout << "-----------------\n";
        cout << "1. Create\n";
        cout << "2. Display\n";
        cout << "3. Quit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice)
        {
        case 1:
            gt.create_tree();
            break; // <- important!
        case 2:
            gt.display(root);
            break;
        case 3:
            cout << "Thanks for using this program!\n";
            return 0;
        default:
            cout << "Invalid choice. Try again.\n";
        }
    }

    return 0;
}