#include <iostream>
#include <Windows.h>
#include <conio.h>
#include <stdlib.h>
#include <vector>
#include <time.h>
#include <fstream>
using namespace std;
void clrscr()
{
    CONSOLE_SCREEN_BUFFER_INFO csbiInfo;
    HANDLE hConsoleOut;
    COORD Home = {0, 0};
    DWORD dummy;

    hConsoleOut = GetStdHandle(STD_OUTPUT_HANDLE);
    GetConsoleScreenBufferInfo(hConsoleOut, &csbiInfo);

    FillConsoleOutputCharacter(hConsoleOut, ' ', csbiInfo.dwSize.X * csbiInfo.dwSize.Y, Home, &dummy);
    csbiInfo.dwCursorPosition.X = 0;
    csbiInfo.dwCursorPosition.Y = 0;
    SetConsoleCursorPosition(hConsoleOut, csbiInfo.dwCursorPosition);
}
void gotoXY(int column, int line)
{
    COORD coord;
    coord.X = column;
    coord.Y = line;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
}
void TextColor(int color)
{
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), color);
}
void DrawMan(int wrong_attempts, string origin_word){
    switch (wrong_attempts)
        {
        case 0:
            cout << "   -------------    \n";
            cout << "   |                \n";
            cout << "   |                \n";
            cout << "   |                \n";
            cout << "   |                \n";
            cout << "   |     \n";
            cout << " -----   \n";
            break;
        case 1:
            cout << "   -------------    \n";
            cout << "   |           |    \n";
            cout << "   |                \n";
            cout << "   |                \n";
            cout << "   |                \n";
            cout << "   |     \n";
            cout << " -----   \n";
            break;
        case 2:
            cout << "   -------------    \n";
            cout << "   |           |    \n";
            cout << "   |           O    \n";
            cout << "   |                \n";
            cout << "   |                \n";
            cout << "   |     \n";
            cout << " -----   \n";
            break;
        case 3:
            cout << "   -------------    \n";
            cout << "   |           |    \n";
            cout << "   |           0    \n";
            cout << "   |           |    \n";
            cout << "   |                \n";
            cout << "   |     \n";
            cout << " -----   \n";
            break;
        case 4:
            cout << "   -------------    \n";
            cout << "   |           |    \n";
            cout << "   |           0    \n";
            cout << "   |           |\\  \n";
            cout << "   |                \n";
            cout << "   |     \n";
            cout << " -----   \n";
            break;
        case 5:
            cout << "   -------------    \n";
            cout << "   |           |    \n";
            cout << "   |           0    \n";
            cout << "   |          /|\\  \n";
            cout << "   |                \n";
            cout << "   |     \n";
            cout << " -----   \n";
            break;
        case 6:
            cout << "   -------------    \n";
            cout << "   |           |    \n";
            cout << "   |           0    \n";
            cout << "   |          /|\\  \n";
            cout << "   |            \\  \n";
            cout << "   |     \n";
            cout << " -----   \n";
            break;
        case 8:
            cout << "   -------------   \n";
            cout << "   |               \n";
            cout << "   |          yay...\n";
            cout << "   |           0   \n";
            cout << "   |          /|\\ \n";
            cout << "   |          / \\ \n";
            cout << " -----\n";
            cout << "You did it, the word is ";
			TextColor(12);
			cout<< origin_word << endl;
			TextColor(7);
            break;
        case 9:
        	cout << "   -------------    \n";
            cout << "   |           |    \n";
            cout << "   |           0 ~~ \n";
            cout << "   |          /|\\  \n";
            cout << "   |          / \\  \n";
            cout << "   |     \n";
            cout << " -----   \n";
    	    cout << "Out of attempts, the word is ";
    	    TextColor(12);
			cout<< origin_word << endl;
			TextColor(7);
            break;
        default:
            break;
        }
}
vector<string> readWordListFromFile(const string& filePath)
{
    vector<string> list;
    ifstream f_in(filePath);
    string word;
    while (f_in>>word)
    {
        list.push_back(word);
    }
    return list; 
}
void normalize(char &guess){
    if(65<=guess && guess<=90){
        guess+=32;
    }
}
int main()
{
    srand((int)time(0));
    vector<string> list;
    ifstream f_in("hang.txt");
    string word;
    while (f_in>>word)
    {
        list.push_back(word);
    }
    int random = rand() %(list.size()-1) +1;
    
    string origin_word = list[random]; 
    string hidden_word = string(origin_word.length(), '-');
    vector<char> guessed_words;
    int wrong_attempts = 0;
    int max_attempts = 7; // max attempts
    int count = 0;
    cout << "Welcome to hangman game!" << endl;
    cout << "The words do not contain any special character or numbers, guess wisely." << endl;
    cout << "Now let's start, the word has " << origin_word.length() << " character(s) and you have "
         << max_attempts << " attempts.\nGood luck!" << endl;
    while (wrong_attempts < max_attempts)
    {
        DrawMan(wrong_attempts,origin_word);
        cout << hidden_word << endl;
        char guess;
        int pass = 0, continue_check = 0;
        cout << "Enter your character: ";
        cin >> guess;
        normalize(guess);
        for (int k = 0; k < guessed_words.size(); k++)
        {
            if (guess == guessed_words[k])
            {
                cout << "You guessed that one, try another character!" << endl;
                continue_check = 1;
            }
        }

        if (continue_check == 1)
        {
        	Sleep(600);
        	clrscr();
            continue;
        }
        guessed_words.push_back(guess);
        for (int i = 0; i < origin_word.size(); i++)
        {
            if (origin_word[i] == guess)
            {
                hidden_word[i] = guess;
                count++;
                pass = 1;
            }
        }
        if (pass == 0)
        {
            wrong_attempts++;
            cout << "Wrong character, you have " << max_attempts - wrong_attempts << " attempt(s) left" << endl;
            Sleep(600);
        }
        if (count == origin_word.size()) //Correctly guessed all the char
        {
            wrong_attempts = 8;
        	clrscr();
        	DrawMan(wrong_attempts,origin_word);
            break;
        }
        clrscr();
    }
    if (count != origin_word.size())    //Failed
    {
    	wrong_attempts = 9;
    	DrawMan(wrong_attempts,origin_word);
            
    }
}
