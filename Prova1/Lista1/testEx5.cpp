#include <iostream>
#include <stack>
#include <queue>

using namespace std;

int main() {
	queue<int> q;
	stack<int> s;

	q.push(1);
	q.push(2);
	q.push(3);

	while(!q.empty()) {
		cout << q.front() << endl;
		q.pop();
	}

	q.push(1);
	q.push(2);
	q.push(3);

	cout << "Invertendo fila..." << endl;

	while(!q.empty()) {
		s.push(q.front());
		q.pop();
	}

	while(!s.empty()) {
		q.push(s.top());
		s.pop();
	}

	while(!q.empty()) {
		cout << q.front() << endl;
		q.pop();
}


	return 0;
}
