#include <iostream>
using namespace std;
struct Node {
    int data;
    Node* next;
};
 Node* removeDuplicates(Node* head) {


    if (head == NULL) {
        return NULL; // Just return the empty list
    }
 // We start at the beginning (the head).
    Node* current = head;
 // If current->next is NULL, we are at the end, so we stop.
    while (current->next != NULL) {
 // Is the data in my current node (e.g., 3)
        if (current->data == current->next->data) {


            current->next = current->next->next;
 } else {


            current = current->next;
        }
    }


    return head;
}



Node* createNode(int data) {
    Node* newNode = new Node();
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}


void push(Node** head_ref, int new_data) {
    Node* new_node = createNode(new_data);
    Node* last = *head_ref;

    if (*head_ref == NULL) {
        *head_ref = new_node;
        return; // And we're done
    }

    // Otherwise, loop until we find the *very last* node
    while (last->next != NULL) {
        last = last->next; // Keep moving to the next node
    }

    // We're at the end. Make the last node's 'next' pointer point to our new node.
    last->next = new_node;
}
 // A helper function to print all the data in the list
void printList(Node* node) {
    // Loop while our node pointer isn't NULL (which is at the end)
    while (node != NULL) {
        cout << node->data << " -> ";
        node = node->next;
    }
    cout << "NULL" << endl;
}
 int main() {
    // We always start with an empty list (head is NULL)
    Node* head = NULL;

    int n; // This variable will hold how many numbers the user wants
    int data; // This variable will hold each number as the user types it

    // Ask the user how many numbers they want to type
    cout << "How many numbers do you want to add to the list? ";
    cin >> n;

    // Remind the user of the problem's rule
    cout << "Great. Please enter the " << n << " numbers in sorted order, pressing Enter after each one:" << endl;

    // This loop will run 'n' times
    for (int i = 0; i < n; i++) {
        cout << "Enter number " << (i + 1) << ": ";
        cin >> data; // Get the number from the keyboard
        // Add the number they typed to the end of our list
        push(&head, data);
    }

    // Now, we show them the list they just built
    cout << "\nOriginal List you entered: " << endl;
    printList(head); // Print the list before any changes

    // this is where we call your function
    head = removeDuplicates(head);
    cout << "\nList after removing duplicates: " << endl;
    printList(head);
    return 0;
}
