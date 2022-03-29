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
void DrawMan(int wrong_attempts, string origin_word)
{
    switch (wrong_attempts)
    {
    case 0:
        gotoXY(20, 10);
        cout << "   -------------    \n";
        gotoXY(20, 11);
        cout << "   |                \n";
        gotoXY(20, 12);
        cout << "   |                \n";
        gotoXY(20, 13);
        cout << "   |                \n";
        gotoXY(20, 14);
        cout << "   |                \n";
        gotoXY(20, 15);
        cout << "   |     \n";
        gotoXY(20, 16);
        cout << " -----   \n";
        break;
    case 1:
        gotoXY(20, 10);
        cout << "   -------------    \n";
        gotoXY(20, 11);
        cout << "   |           |    \n";
        gotoXY(20, 12);
        cout << "   |                \n";
        gotoXY(20, 13);
        cout << "   |                \n";
        gotoXY(20, 14);
        cout << "   |                \n";
        gotoXY(20, 15);
        cout << "   |     \n";
        gotoXY(20, 16);
        cout << " -----   \n";
        break;
    case 2:
        gotoXY(20, 10);
        cout << "   -------------    \n";
        gotoXY(20, 11);
        cout << "   |           |    \n";
        gotoXY(20, 12);
        cout << "   |           O    \n";
        gotoXY(20, 13);
        cout << "   |                \n";
        gotoXY(20, 14);
        cout << "   |                \n";
        gotoXY(20, 15);
        cout << "   |     \n";
        gotoXY(20, 16);
        cout << " -----   \n";
        break;
    case 3:
        gotoXY(20, 10);
        cout << "   -------------    \n";
        gotoXY(20, 11);
        cout << "   |           |    \n";
        gotoXY(20, 12);
        cout << "   |           0    \n";
        gotoXY(20, 13);
        cout << "   |           |    \n";
        gotoXY(20, 14);
        cout << "   |                \n";
        gotoXY(20, 15);
        cout << "   |     \n";
        gotoXY(20, 16);
        cout << " -----   \n";
        break;
    case 4:
        gotoXY(20, 10);
        cout << "   -------------    \n";
        gotoXY(20, 11);
        cout << "   |           |    \n";
        gotoXY(20, 12);
        cout << "   |           0    \n";
        gotoXY(20, 13);
        cout << "   |           |\\  \n";
        gotoXY(20, 14);
        cout << "   |                \n";
        gotoXY(20, 15);
        cout << "   |     \n";
        gotoXY(20, 16);
        cout << " -----   \n";
        break;
    case 5:
        gotoXY(20, 10);
        cout << "   -------------    \n";
        gotoXY(20, 11);
        cout << "   |           |    \n";
        gotoXY(20, 12);
        cout << "   |           0    \n";
        gotoXY(20, 13);
        cout << "   |          /|\\  \n";
        gotoXY(20, 14);
        cout << "   |                \n";
        gotoXY(20, 15);
        cout << "   |     \n";
        gotoXY(20, 16);
        cout << " -----   \n";
        break;
    case 6:
        gotoXY(20, 10);
        cout << "   -------------    \n";
        gotoXY(20, 11);
        cout << "   |           |    \n";
        gotoXY(20, 12);
        cout << "   |           0    \n";
        gotoXY(20, 13);
        cout << "   |          /|\\  \n";
        gotoXY(20, 14);
        cout << "   |            \\  \n";
        gotoXY(20, 15);
        cout << "   |     \n";
        gotoXY(20, 16);
        cout << " -----   \n";
        break;
    case 8:
        gotoXY(20, 10);
        cout << "   -------------   \n";
        gotoXY(20, 11);
        cout << "   |               \n";
        gotoXY(20, 12);
        cout << "   |          yay...\n";
        gotoXY(20, 13);
        cout << "   |           0   \n";
        gotoXY(20, 14);
        cout << "   |          /|\\ \n";
        gotoXY(20, 15);
        cout << "   |          / \\ \n";
        gotoXY(20, 16);
        cout << " -----\n";
        gotoXY(20, 17);
        cout << "You did it, the word is ";
        TextColor(12);
        gotoXY(20, 18);
        cout << origin_word << endl;
        TextColor(7);

        break;
    case 9:
        while (true)
        {
            gotoXY(20, 10);
            cout << "   -------------    \n";
            gotoXY(20, 11);
            cout << "   |           |    \n";
            gotoXY(20, 12);
            cout << "   |           0 ~~ \n";
            gotoXY(20, 13);
            cout << "   |          /|\\  \n";
            gotoXY(20, 14);
            cout << "   |          / \\  \n";
            gotoXY(20, 15);
            cout << "   |     \n";
            gotoXY(20, 16);
            cout << " -----   \n";
            gotoXY(20, 17);
            cout << "Out of attempts, the word is ";
            TextColor(12);
            gotoXY(20, 18);
            cout << origin_word << endl;
            TextColor(7);
            Sleep(250);
            clrscr();
            gotoXY(20, 10);
            cout << "   -------------    \n";
            gotoXY(20, 11);
            cout << "   |           /    \n";
            gotoXY(20, 12);
            cout << "   |          0 ~~ \n";
            gotoXY(20, 13);
            cout << "   |         /|\\  \n";
            gotoXY(20, 14);
            cout << "   |         / \\  \n";
            gotoXY(20, 15);
            cout << "   |     \n";
            gotoXY(20, 16);
            cout << " -----   \n";
            gotoXY(20, 17);
            cout << "Out of attempts, the word is ";
            TextColor(12);
            gotoXY(20, 18);
            cout << origin_word << endl;
            TextColor(7);
            Sleep(250);
            clrscr();
            gotoXY(20, 10);
            cout << "   -------------    \n";
            gotoXY(20, 11);
            cout << "   |           |    \n";
            gotoXY(20, 12);
            cout << "   |           0 ~~ \n";
            gotoXY(20, 13);
            cout << "   |          /|\\  \n";
            gotoXY(20, 14);
            cout << "   |          / \\  \n";
            gotoXY(20, 15);
            cout << "   |     \n";
            gotoXY(20, 16);
            cout << " -----   \n";
            gotoXY(20, 17);
            cout << "Out of attempts, the word is ";
            TextColor(12);
            gotoXY(20, 18);
            cout << origin_word << endl;
            TextColor(7);
            Sleep(250);
            clrscr();
            gotoXY(20, 10);
            cout << "   -------------    \n";
            gotoXY(20, 11);
            cout << "   |           \\    \n";
            gotoXY(20, 12);
            cout << "   |            0 ~~ \n";
            gotoXY(20, 13);
            cout << "   |           /|\\  \n";
            gotoXY(20, 14);
            cout << "   |           / \\  \n";
            gotoXY(20, 15);
            cout << "   |     \n";
            gotoXY(20, 16);
            cout << " -----   \n";
            gotoXY(20, 17);
            cout << "Out of attempts, the word is ";
            TextColor(12);
            gotoXY(20, 18);
            cout << origin_word << endl;
            TextColor(7);
            Sleep(250);
            clrscr();
        }
        break;
    default:
        break;
    }
}
void DrawHDWord(string hidden_word)
{
    gotoXY(20, 19);
    cout << hidden_word << endl;
    gotoXY(20, 20);
    cout << "Enter your character: ";
}
vector<string> readWordListFromFile(const string &filePath)
{
    vector<string> list;
    ifstream f_in(filePath);
    string word;
    while (f_in >> word)
    {
        list.push_back(word);
    }
    return list;
}
void normalize(char &guess)
{
    if (65 <= guess && guess <= 90)
    {
        guess += 32;
    }
}
void Welcome(string origin_word, int max_attempts)
{
    gotoXY(20, 6);
    cout << "Welcome to hangman game!" << endl;
    gotoXY(20, 7);
    cout << "The words do not contain any special character or numbers, guess wisely." << endl;
    gotoXY(20, 8);
    cout << "Now let's start, the word has " << origin_word.length() << " character(s) and you have "
         << max_attempts << " attempts.";
    gotoXY(20, 9);
    cout << "Good luck!" << endl;
}
void DrawGuessedWords(vector<char> guessed_words)
{
    gotoXY(40, 9);
    cout << "Guessed words: ";
    for (int i = 0; i < guessed_words.size(); i++)
    {
        gotoXY(40 + i, 10);
        cout << guessed_words[i];
    }
}
int main()
{
	srand((int)time(0));
    while (true)
    {
        int retry = 0;
        srand((int)time(0));
        vector<string> list;
        ifstream f_in("Words_list.txt");
        string word;
        while (f_in >> word)
        {
            list.push_back(word);
        }
        int random = rand() % (list.size() - 1) + 1;

        string origin_word = list[random];
        string hidden_word = string(origin_word.length(), '-');
        vector<char> guessed_words;
        int wrong_attempts = 0;
        int max_attempts = 7; // max attempts
        int count = 0;
        Welcome(origin_word, max_attempts);

        while (wrong_attempts < max_attempts)
        {
            DrawMan(wrong_attempts, origin_word);
            DrawHDWord(hidden_word);
            DrawGuessedWords(guessed_words);

            char guess;
            int pass = 0, continue_check = 0;
            gotoXY(42, 20);
            cin >> guess;
            normalize(guess);
            for (int k = 0; k < guessed_words.size(); k++)
            {
                if (guess == guessed_words[k])
                {
                    gotoXY(40 + k, 10);
                    TextColor(12);
                    cout << guessed_words[k];
                    TextColor(7);
                    gotoXY(20, 21);
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
                gotoXY(20, 21);
                cout << "Wrong character, you have ";
                TextColor(12);
                cout << max_attempts - wrong_attempts;
                TextColor(7);
                cout << " attempt(s) left" << endl;
                Sleep(600);
            }
            if (count == origin_word.size()) // Correctly guessed all the char
            {
                wrong_attempts = 8;
                clrscr();
                DrawMan(wrong_attempts, origin_word);
                DrawGuessedWords(guessed_words);
                break;
            }
            clrscr();
        }
        if (count != origin_word.size()) // Failed
        {
            wrong_attempts = 9;
            DrawMan(wrong_attempts, origin_word);
            DrawGuessedWords(guessed_words);
        }
        Sleep(2600);
        gotoXY(20, 21);
        cout << "Enter 0 to quit, enter 1 to retry: " << endl;
        char choice;
        while (true)
        {
            cin >> choice;
            if (choice == '1')
            {
                retry++;
                break;
            }
            if (choice == '0')
            {
                retry--;
                break;
            }
        }
        if (retry == -1)
            break;
        clrscr();
    }
}
