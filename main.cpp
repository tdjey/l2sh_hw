#include <iostream>

using namespace std;

int main() {
    string name, surname, film;
    cout << "Enter your name and surname, please\n";
    cin >> name >> surname;
    cout << "Enter your favourite film name, please\n";
    getline(cin, film);
    getline(cin, film);
    freopen("ans.txt", "a", stdout);
    cout << name + " " + surname + ": " + film + ".\n";
}