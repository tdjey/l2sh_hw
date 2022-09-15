#include <iostream>
#include <fstream>

using namespace std;

void print_results() {
    ifstream input;
    input.open("answers.txt");
    string user_info;
    while (!input.eof()) {
        getline(input, user_info);
        cout << user_info << "\n";
    }
    input.close();
}

int main() {
    string type;
    cout << "Enter 1 to start the quiz, 2 to get the results\n";
    cin >> type;
    while (type != "1" && type != "2") {
        cout << "Enter 1 to start the quiz, 2 to get the results\n";
        cin >> type;
    }
    if (type == "1") {
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
    else {
        print_results();
    }
}