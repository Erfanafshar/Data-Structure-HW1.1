#include <iostream>
#include <stack>

using namespace std;

int main() {

    int pushed;
    int numberOfQuestion = 0;
    int peek;
    string question;
    string pushNumber;

    stack<int> stack1;
    stack<int> stack2;

    cin >> numberOfQuestion;

    for (int i = 0; i <= numberOfQuestion; i++) {

        getline(cin, question);

        if (question.compare(0, 4, "push") == 0) {
            pushNumber = question.substr(5, question.size() - 5);
            pushed = stoi(pushNumber);

            stack1.push(pushed);

            if (stack2.empty()) {
                stack2.push(pushed);
            } else {

                peek = stack2.top();

                if (pushed > peek) {
                    stack2.push(peek);
                } else {
                    stack2.push(pushed);
                }
            }

        }

        if (question.compare(0, 3, "pop") == 0) {

            if (!stack1.empty()) {
                stack1.pop();
                stack2.pop();
            }

        }

        if (question.compare(0, 5, "spell") == 0) {

            if (!stack2.empty()) {
                peek = stack2.top();
                cout << peek << endl;
            }

        }

    }

    return 0;
}