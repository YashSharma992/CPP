#include <iostream>

// Node structure
struct Node {
    int data;
    Node* next;

    Node(int val) {
        data = val;
        next = nullptr;
    }
};

class Stack {
private:
    Node* top;

public:
    Stack() {
        top = nullptr;
    }

    // Push element onto stack (Insert at Head)
    void push(int x) {
        Node* newNode = new Node(x);
        newNode->next = top;
        top = newNode;
        std::cout << x << " pushed to stack\n";
    }

    // Remove top element (Delete from Head)
    void pop() {
        if (empty()) {
            std::cout << "Stack Underflow\n";
            return;
        }
        Node* temp = top;
        top = top->next;
        delete temp; // Free memory
    }

    // Return the top element
    int peek() {
        if (empty()) {
            std::cout << "Stack is empty\n";
            return -1;
        }
        return top->data;
    }

    // Check if empty
    bool empty() {
        return top == nullptr;
    }

    // Display stack contents from top to bottom
    void display() {
        if (empty()) {
            std::cout << "Stack is empty\n";
            return;
        }
        Node* temp = top;
        std::cout << "Stack (Top -> Bottom): ";
        while (temp != nullptr) {
            std::cout << temp->data << " ";
            temp = temp->next;
        }
        std::cout << "\n";
    }

    // Destructor to free remaining heap memory
    ~Stack() {
        while (!empty()) {
            pop();
        }
    }
};

int main() {
    Stack st;

    st.push(10);
    st.push(20);
    st.push(30);

    st.display();

    std::cout << "Top element: " << st.peek() <<"\n";

    st.pop();
    st.display();

    return 0;
}