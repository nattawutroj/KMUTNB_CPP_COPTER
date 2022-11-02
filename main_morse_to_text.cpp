#include <iostream>
using namespace std;
int main() // morse code convert text
{
    string morseCode[26] = {".-", "-...", "-.-.", "-..", ".", "..-.", "--.", "....", "..", ".---", "-.-", ".-..", "--", "-.", "---", ".--.", "--.-", ".-.", "...", "-", "..-", "...-", ".--", "-..-", "-.--", "--.."};
    char alphabet[26] = {'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l', 'm', 'n', 'o', 'p', 'q', 'r', 's', 't', 'u', 'v', 'w', 'x', 'y', 'z'};
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
    return 0;
}