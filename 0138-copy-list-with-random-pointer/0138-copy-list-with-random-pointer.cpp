/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
public:
    Node* copyRandomList(Node* head) {

        // Step 1: Handle an empty linked list.
        if (head == nullptr) {
            return nullptr;
        }

        // Step 2: Create a copy of each node and insert it
        // immediately after its original node.
        // Original: A -> B -> C
        // Updated:  A -> A' -> B -> B' -> C -> C'
        Node* current = head;

        while (current != nullptr) {
            Node* copy = new Node(current->val);

            copy->next = current->next;
            current->next = copy;

            current = copy->next;
        }

        // Step 3: Assign random pointers to copied nodes.
        // If original node's random points to X,
        // its copied node's random points to X's copy.
        current = head;

        while (current != nullptr) {

            Node* copy = current->next;

            if (current->random != nullptr) {
                copy->random = current->random->next;
            }

            current = copy->next;
        }

        // Step 4: Separate the original list and copied list.
        Node* dummy = new Node(0);
        Node* copyTail = dummy;

        current = head;

        while (current != nullptr) {

            // Get the copied node.
            Node* copy = current->next;

            // Restore the original list.
            current->next = copy->next;

            // Attach the copied node to the copied list.
            copyTail->next = copy;
            copyTail = copy;

            // Move to the next original node.
            current = current->next;
        }

        // Step 5: Store the copied list's head.
        Node* copiedHead = dummy->next;

        // Delete the temporary dummy node.
        delete dummy;

        return copiedHead;
    }
};