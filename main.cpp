#include <iostream>
#include <fstream>

using namespace std;

void print_results() {
    ifstream input;
    input.open("answers.txt");
    string user_info;
    ifstream questions_input;
    questions_input.open("questions.txt");
    string question, answer;
    cout << "/ username /";
    while (!questions_input.eof()) {
        getline(questions_input, question);
        cout << "/ " + question + " /";
    }
    cout << "\n";
    while (!input.eof()) {
        getline(input, user_info);
        if (user_info == "")
            continue;
        cout << "/ ";
        for (char i : user_info) {
            if (i == '~')
                cout << " // ";
            else
                cout << i;
        }
        cout << " /\n";
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
        output.open("answers.txt", fstream::app);
        output << name << " " << surname;
        getline(cin, answer);
        while (!input.eof()) {
            getline(input, question);
            if (question == "")
                cout << "No questions 4 u)\n";
            else {
                cout << question << "\n";
                getline(cin, answer);
                output << "~ " << answer;
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