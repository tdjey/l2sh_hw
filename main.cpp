#include <iostream>
#include <fstream>
#include <map>

using namespace std;

void print_results() {
    ifstream input;
    input.open("answers.txt");
    string user_info;
    ifstream questions_input;
    questions_input.open("questions.txt");
    string question, answer;
    cout << "/ username /";
    map<string, int> answers_map;
    int question_counter = 0;
    while (!questions_input.eof()) {
        getline(questions_input, question);
        cout << "/ " + question + " /";
        question_counter++;
    }
    question_counter++;
    cout << "\n";
    int counter = 0;
    while (!input.eof()) {
        getline(input, user_info, '~');
        if (user_info == "\n" || user_info == "")
            continue;
        cout << "/ ";
        cout << user_info;
        cout << " /";
        counter++;
        if (counter % question_counter == 0) 
            answers_map[user_info] += 1;
    }
    cout << "\n";
    int max_ans = 0;
    string ans;
    for (auto cur : answers_map) 
        if (cur.second > max_ans) {
            ans = cur.first;
            max_ans = cur.second;
        }

    cout << "------Final statistics:------\nAmount of respondents: " << counter / question_counter <<
        "\nThe most popular answer on last question is: " << ans;
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
        output << name << " " << surname << "~";
        getline(cin, answer);
        while (!input.eof()) {
            getline(input, question);
            if (question == "")
                cout << "No questions 4 u)\n";
            else {
                cout << question << "\n";
                getline(cin, answer);
                output << answer << "~";
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