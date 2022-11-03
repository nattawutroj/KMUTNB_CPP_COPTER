#include<iostream>
using namespace std;
int main() // manu morse code to text && manu text to morse code
{
    string morseCode[26] = {".-", "-...", "-.-.", "-..", ".", "..-.", "--.", "....", "..", ".---", "-.-", ".-..", "--", "-.", "---", ".--.", "--.-", ".-.", "...", "-", "..-", "...-", ".--", "-..-", "-.--", "--.."};
    char alphabet[26] = {'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l', 'm', 'n', 'o', 'p', 'q', 'r', 's', 't', 'u', 'v', 'w', 'x', 'y', 'z'};
    string input;
    string output;
    int choice;
    cout << "1. Text to morse code" << endl;
    cout << "2. Morse code to text" << endl;
    cout << "Enter your choice: ";
    cin >> choice;
    if (choice == 1)
    {
        cout << "Enter a word to convert to morse code: ";
        cin >> input;
        for (int i = 0; i < input.length(); i++)
        {
            for (int j = 0; j < 26; j++)
            {
                if (input[i] == alphabet[j])
                {
                    output += morseCode[j];
                    output += " ";
                }
            }
        }
        cout << output << endl;
    }
    else if (choice == 2)
    {
        string input[100];
        string output;
        cout << "input morse code: ";
        for (int i = 0; cin >> input[i]; i++)
        {
            if (input[i] == "0")
            {
                break;
            }
        }
        for(int i = 0; i < 100; i++)
        {
            for (int j = 0; j < 26; j++)
            {
                if (input[i] == morseCode[j])
                {
                    cout<<alphabet[j];
                }
            }
        }
    }
    else
    {
        cout << "Invalid choice" << endl;
    }
}