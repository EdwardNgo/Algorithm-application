#include <iostream>
using namespace std;
struct Node
{
    int data;
    Node *next;

    Node(int data)
    {
        this->data = data;
        next = NULL;
    }
};

// push a new element to the beginning of the list
Node *prepend(Node *head, int data)
{
    /*****************
    # YOUR CODE HERE #
    *****************/
    // Node *newnode;
    // newnode->data = data;
    // newnode->next = head;
    // head = newnode;
    // return head;
    struct Node *new_node = (struct Node *)malloc(sizeof(struct Node));
    new_node->data = data;
    new_node->next = head;
    head = new_node;
    return head;
}

// print the list content on a line
void print(Node *head)
{
    while (head != NULL)
    {
        cout << head->data << " ";
        head = head->next;
    }
}

// return the new head of the reversed list
Node *reverse(Node *head)
{
    /*****************
    # YOUR CODE HERE #
    *****************/
    Node *current = head;
    Node *prev = NULL, *next = NULL;

    while (current != NULL)
    {
        // Store next
        next = current->next;

        // Reverse current node's pointer
        current->next = prev;

        // Move pointers one position ahead.
        prev = current;
        current = next;
    }
    head = prev;
    return head;
}

int main()
{
    int n, u;
    cin >> n;
    Node *head = NULL;
    for (int i = 0; i < n; ++i)
    {
        cin >> u;
        head = prepend(head, u);
    }

    cout << "Original list: ";
    print(head);

    head = reverse(head);

    cout <<endl<< "Reversed list: ";
    print(head);

    return 0;
}