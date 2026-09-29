#include <bits/stdc++.h>
using namespace std;

struct MyStack {
    int a[100];
    int top;

public:
    MyStack() {
        top = -1;
    }

    void push(int x) {
        if (top == 99)
            cout << "overflow" << endl;
        else {
            top++;
            a[top] = x;
        }
    }

    void pop() {
        if (top == -1)
            cout << "underflow" << endl;
        else {
            top--;
        }
    }

    int peek() {
        if (top == -1) {
            cout << "underflow" << endl;
            return -1; 
        } else {
            return a[top];
        }
    }

    bool empty() {
        return top == -1;
    }

    void display() {
        if (!empty()) {
            for (int i = top; i >= 0; i--) {
                cout << a[i] << " ";
            }
            cout << endl;
        }
    }
};

int main() {
    MyStack st;
    st.push(100);
    st.display();
    return 0;
}