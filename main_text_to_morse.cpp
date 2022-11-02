#include <iostream>
using namespace std;
int main() // start morse code converter
{
    string morseCode[26] = {".-", "-...", "-.-.", "-..", ".", "..-.", "--.", "....", "..", ".---", "-.-", ".-..", "--", "-.", "---", ".--.", "--.-", ".-.", "...", "-", "..-", "...-", ".--", "-..-", "-.--", "--.."};
    char alphabet[26] = {'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l', 'm', 'n', 'o', 'p', 'q', 'r', 's', 't', 'u', 'v', 'w', 'x', 'y', 'z'};
    string input;
    string output;
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
    return 0;
}