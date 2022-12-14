#define _CRT_SECURE_NO_WARNINGS
#include <vector>
#include <iostream>
#include <fstream>
#include <map>
#include <string>


using namespace std;

void print_results(int width) {
    ifstream input;
    input.open("answers.txt");
    string user_info;
    ifstream questions_input;
    questions_input.open("questions.txt");
    string question, answer;
    int question_counter = 0;
    vector<string> questions;
    questions.push_back("username");
    while (!questions_input.eof()) {
        getline(questions_input, question);
        question_counter++;
        questions.push_back(question);
    }
    map<string, int> answers_map;
    question_counter++;
    cout << "\n";
    int column_width = width / question_counter;
    for (string s : questions) {
        if (s.size() <= column_width) {
            cout << s;
            for (int i = 0; i < column_width - (int)s.size(); i++)
                cout << " ";
        }
        else {
            for (int i = 0; i < column_width - 3; i++)
                cout << s[i];
            cout << "...";
        }
        cout << "//";
    }
    cout << "\n";
    int shift_counter = 0;
    while (!input.eof()) {
        getline(input, user_info, '~');
        if (shift_counter % questions.size() == 0)
            cout << "\n";
        if ((shift_counter + 1) % question_counter == 0)
            answers_map[user_info] += 1;
        if (user_info == "\n" || user_info == "")
            continue;
        if (user_info.size() <= column_width) {
            cout << user_info;
            for (int i = 0; i < column_width - (int)user_info.size(); i++)
                cout << " ";
        }
        else {
            for (int i = 0; i < column_width - 3; i++)
                cout << user_info[i];
            cout << "...";
        }
        cout << "//";
        shift_counter++;
    }
    cout << "\n";
    int max_ans = 0;
    string ans;
    for (auto cur : answers_map)
        if (cur.second > max_ans) {
            ans = cur.first;
            max_ans = cur.second;
        }

    cout << "------Final statistics:------\nAmount of respondents: " << shift_counter / question_counter <<
        "\nThe most popular answer on last question is: " << ans;
    input.close();
}

int main() {
    string type;
    cout << "Enter 1 to start the quiz, 2 to get the results, 3 to modify the questions\n";
    cin >> type;
    while (type != "1" && type != "2" && type != "3") {
        cout << "Enter 1 to start the quiz, 2 to get the results, 3 to modify the questions\n";
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
        input.close();
        output.close();
    }

    else if (type == "2") {
        cout << "Enter the width of the table ans, please: \n";
        int width;
        cin >> width;
        print_results(width);
    }

    else
    {
        fstream q;
        string _;
        int mode = 0;

        cout << "1 to delete a question, 2 to add\n";
        while (mode != 1 && mode != 2) { cin >> mode; }

        if (mode == 1) //delete
        {
            fstream newQustions;
            q.open("questions.txt");
            newQustions.open("newQustions.txt", ios_base::app);

            string questionLine, conf;
            bool isFirstLine = true;
            bool deletingAllQuestions = true;

            getline(cin, _);
            while (getline(q, questionLine))
            {
                cout << questionLine << "\n";
                cout << "Would you like to delete this question?('n' to pass, 'y' to delete)\n";
                while (conf != "n" && conf != "y") { cin >> conf; }
                if (conf == "n")
                {
                    if (isFirstLine) { newQustions << questionLine; isFirstLine = false; }
                    else { newQustions << "\n" << questionLine; }
                    deletingAllQuestions = false;
                }
                conf = "";
            }

            if (deletingAllQuestions)
            {
                newQustions << questionLine;
                isFirstLine = false;
                cout << "You cant have 0 questions! Add more first to delete this one\n";
            }

            newQustions.close();
            q.close();
            remove("questions.txt");
            rename("newQustions.txt", "questions.txt");
        }

        else //add
        {
            q.open("questions.txt", ios_base::app);
            string newQuestion;
            getline(cin, _);
            while (newQuestion != "/stop")
            {
                cout << "Input a new question or '/stop' to stop adding questions\n";
                getline(cin, newQuestion);
                if (newQuestion != "/stop") { q << "\n" << newQuestion; }
            }
            q.close();
        }

        ofstream ans;
        ans.open("answers.txt", ofstream::out | ofstream::trunc);
        ans.close();

        cout << "answers.txt was cleared\n";
    }
}