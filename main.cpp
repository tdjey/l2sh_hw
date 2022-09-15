#include <iostream>
#include <fstream>

using namespace std;

int main() {
    ifstream input;
    string question, answer;
    input.open("questions.txt");
    ofstream output;
    string name, surname;
    cout << "Enter your name and surname, please\n";
    cin >> name >> surname;
    output.open("answer.txt", fstream::app);
    output << name << " " << surname;
    getline(cin, answer);
    while (!input.eof()) {
        getline(input, question);
        if (question == "")
            cout << "No questions 4 u)\n";
        else {
            cout << question << "\n";
            getline(cin, answer);
            output << ", " << answer;
        }
    }
    output << "\n";
    input.close();
    output.close();
}