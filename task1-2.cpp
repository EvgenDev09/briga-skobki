#include <iostream>
#include <stack>
using namespace std;

// Скобки
const int BR = 3;
const string BR1 = "([{", BR2 = ")]}";

int main() {
	string s;
	cin >> s;
	
	// Стек
	stack<int> brackets;
	bool isCorrect = true, toAdd = true;
	for (char c : s) {
		// Перебираем все скобки в строке
		for (int i = 0; i < BR; i++) {
			if (c == BR1[i]) {
				// Скобка открывающаяся
				brackets.push(i);
				break;
			}
			if (c == BR2[i]) {
				// Скобка закрывающаяся
				if (!brackets.empty() && brackets.top() == i) {
					// Скобка правильная
					brackets.pop();
				} else {
					// Скобка неправильная
					isCorrect = false;
					toAdd = false;
				}
				break;
			}
		}
		if (!toAdd) break;
	}
	if (!brackets.empty()) {
		// Не все скобки закрылись
		isCorrect = false;
	}
	
	cout << "CORRECT: " << (isCorrect ? "YES" : "NO") << endl;
	cout << "TO ADD: " << (toAdd ? "YES" : "NO") << endl;
	return 0;
}
