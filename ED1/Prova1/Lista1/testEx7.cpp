#include <iostream>
#include <stack>

using namespace std;

int main() {
    stack<int> aux;
    stack<int> s;

    s.push(8);
    s.push(3);
    s.push(5);
    s.push(2);
    s.push(1);
    s.push(4);

    while (!s.empty()) {
        if (s.top() % 2 == 0)
            aux.push(s.top());
        s.pop();
    }

    while (!aux.empty()) {
        s.push(aux.top());
        aux.pop();
    }

    while (!s.empty()) {
        cout << s.top() << endl;
        s.pop();
    }

    return 0;
}
