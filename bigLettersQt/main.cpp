#include <QCoreApplication>
#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

using std::cin;//instead of using namespace std; better to list only names that will be used
using std::cout;
using std::vector;
using std::string;
using std::endl;


int main(int argc, char* argv[])
{
    QCoreApplication a(argc, argv);

    int width{}, height{};
    string text;

    cin >> width; cin.ignore();
    cin >> height; cin.ignore();
    getline(cin, text);

    for_each(begin(text), end(text), [](char& letter) {letter = ::toupper(letter); }); //algorithm for_each is used with lambda to make entered text uppercase

    const int A = static_cast<int>('A'); //ASCII table allows to cast chars to ints
    const int Z = static_cast<int>('Z');

    vector<string> letters(height); //vector letters will keep entered strings

    for (size_t i = 0; i < letters.size(); i++)//for loop is used to fill the vector letters with the user input
    {
        string str;
        getline(cin, str); //getline() is used to read chars till the newline character '\n'
        letters.at(i) = str;
    }

    cout << endl << endl;

    for (size_t i = 0; i < letters.size(); i++) // for loop with one nested loop is used to iterate through entered text and to construct result string
    {
        string resultStr = "";
        for (size_t j = 0; j < text.size(); j++)
        {
            int intLetter = static_cast<int>(text[j]);
            if (intLetter < A || intLetter > Z)
            {
                resultStr += letters.at(i).substr(width * (Z - A + 1), width); //if entered other than A-Z letters, will output ? sign according to the entered template
            }
            else
            {
                resultStr += letters.at(i).substr(width * (intLetter - A), width); //for output of A-Z letters according to the entered template
            }
        }

        cout << resultStr << endl;
    }
    return 0;
}
