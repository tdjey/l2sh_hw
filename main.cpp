#include <iostream>

using namespace std;

int main() {
    string name, surname, book;
    cout << "Enter your name and surname, please\n";
    cin >> name >> surname;
    cout << "Enter your favourite book name, please\n";
    getline(cin, book);
    getline(cin, book);
    freopen("ans.txt", "a", stdout);
    cout << name + " " + surname + ": " + book + ".\n";
}