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
        string name, surname, book;
        cout << "Enter your name and surname, please\n";
        cin >> name >> surname;
        cout << "Enter your favourite book name, please\n";
        getline(cin, book);
        getline(cin, book);
        ofstream output;
        output.open("answers.txt", ofstream::app);
        output << name + " " + surname + ": " + book + ".\n";
        output.close();
    }
    else {
        print_results();
    }
}