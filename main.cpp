//#include <iostream>
//#include <cmath>
//#include <iomanip>
//#include <vector>
//
//using namespace std;
//
//typedef long double ld;
//
//struct Point {
//    int x, y;
//};
//
//istream& operator >>(istream& input, Point& p) {
//    input >> p.x >> p.y;
//    return input;
//}
//
//struct Vector {
//    int x, y;
//    Vector() {}
//    Vector(Point a, Point b) {
//        x = b.x - a.x;
//        y = b.y - a.y;
//    }
//    Vector(Point a) {
//        x = a.x;
//        y = a.y;
//    }
//    Vector(int x_, int y_) : x(x_), y(y_) {}
//};
//
//int operator* (Vector& a, Vector& b) {
//    return a.x * b.x + a.y * b.y;
//}
//
//int operator% (Vector& a, Vector& b) {
//    return a.x * b.y - a.y * b.x;
//}
//
//Vector make_orto(Vector& a) {
//    Vector ans;
//    if (a.x == 0)
//        ans.x = a.y * -1;
//    else if (a.y == 0)
//        ans.y = a.x * -1;
//    else {
//        ans.x = a.y * -1;
//        ans.y = a.x;
//    }
//    return ans;
//}
//
//pair<ld, ld> line_intersec(int a1, int b1, int c1, int a2, int b2, int c2) {
//    ld x = (ld)(b1 * c2 - b2 * c1) / (ld)(a1 * b2 - a2 * b1),
//        y = (ld)(a2 * c1 - a1 * c2) / (ld)(a1 * b2 - a2 * b1);
//    return { x, y };
//}
//
//
//bool is_in_poly(Point a, vector<Point>& poly) {
//    int ans = 0;
//    for (int i = 0; i < poly.size() - 1; i++) {
//        Point b = poly[i], c = poly[i + 1];        
//        if (b.y < c.y)
//            swap(b, c);
//        Vector first(b, c), first_(c, a),
//            second(c, b), second_(b, a);
//        int ans1 = first % first_, ans2 = second % second_;
//        if (a.x == poly[i].x && a.y == poly[i].y)
//            return true;
//        if (first * first_ < 0 && second * second_ < 0 &&
//            ans1 == 0)
//            return true;
//        if (ans1 < 0 && ans2 > 0 &&
//            b.y >= a.y && c.y < a.y)
//            ans++;
//    }
//    Point b = poly.back(), c = poly[0];
//    if (a.x == poly.back().x && a.y == poly.back().y)
//        return true;
//    if (b.y < c.y)
//        swap(b, c);
//    Vector first(b, c), first_(c, a),
//        second(c, b), second_(b, a);
//    int ans1 = first % first_, ans2 = second % second_;
//    if (ans1 < 0 && ans2 > 0 &&
//        b.y >= a.y && c.y < a.y)
//        ans++;
//    if (ans & 1)
//        return true;
//    return false;
//}
//
//int main() {
//    int n;
//    Point a;
//    cin >> n >> a;
//    vector<Point> poly(n);
//    for (int i = 0; i < n; i++) 
//        cin >> poly[i];
//    if (is_in_poly(a, poly))
//        cout << "YES";
//    else
//        cout << "NO";
//}
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
    cout << "\n";
    question_counter++;
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
        if (shift_counter % questions.size() == 0)
            cout << "\n";
        getline(input, user_info, '~');
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
        input.close();
        output.close();
    }
    else {
        cout << "Enter the width of the table ans, please: \n";
        int width;
        cin >> width;
        print_results(width);
    }
}