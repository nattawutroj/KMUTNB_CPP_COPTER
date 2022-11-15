#include <iostream>
#include <iomanip>
#include <string>
using namespace std;
string dis[400][10];
string input_text;
string morse_done;
void display(int control);
void dis_line();
void dis_hader();
void dis_main();
void dis_draw_add_manu();
void dis_draw_main_manu();
void dis_draw_add_confirm(string input_text, string morse_done);
void dis_clear();
void dis_player_morse(string morse_done);
void cls_add_varible();
void input(int control_input);
int main()
{
    display(1);
    return 0;
}
void cls_add_varible()
{
    input_text = "";
    morse_done = "";
}
void dis_player_morse(string morse_done)
{
    for(int l = 7; l < 22 ; l++)
    {
    dis[l][1] = "   @@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@   ";
    }
}
void dis_draw_add_confirm(string input_text, string morse_done)
{
    dis[1][1] = "     " + input_text;
    dis[2][1] = "                    ^ Text ^";
    dis[10][0] = "                                          ^ Morse Code ^";
    if (morse_done.length() > 80 && morse_done.length() <= 160)
    {
        dis[2][0] = "        " + morse_done.substr(0, 80) + ">";
        dis[3][0] = "        " + morse_done.substr(80, morse_done.length());
    }
    else if (morse_done.length() > 160 && morse_done.length() <= 240)
    {
        dis[2][0] = "        " + morse_done.substr(0, 80) + ">";
        dis[3][0] = "        " + morse_done.substr(80, 80) + ">";
        dis[4][0] = "        " + morse_done.substr(160, morse_done.length());
    }
    else if (morse_done.length() > 240 && morse_done.length() <= 320)
    {
        dis[2][0] = "        " + morse_done.substr(0, 80) + ">";
        dis[3][0] = "        " + morse_done.substr(80, 80) + ">";
        dis[4][0] = "        " + morse_done.substr(160, 80) + ">";
        dis[5][0] = "        " + morse_done.substr(240, morse_done.length());
    }
    else if (morse_done.length() > 320)
    {
        dis[2][0] = "        " + morse_done.substr(0, 80) + ">";
        dis[3][0] = "        " + morse_done.substr(80, 80) + ">";
        dis[4][0] = "        " + morse_done.substr(160, 80) + ">";
        dis[5][0] = "        " + morse_done.substr(240, 80) + ">";
        dis[6][0] = "        " + morse_done.substr(320, morse_done.length());
    }
    else
    {
        dis[2][0] = "  " + morse_done;
    }
    dis[15][0] = "   Type \"p\" or \"P\" to play the morse code";
    dis[17][0] = "   Type \"y\" or \"Y\" to add code to list                  Type \"n\" or \"N\" to cancel";
}
void dis_clear()
{
    for (int i = 0; i < 400; i++)
    {
        for (int j = 0; j < 10; j++)
        {
            dis[i][j] = "";
        }
    }
}
void dis_draw_main_manu()
{
    dis[0][0] = "1. add Text Convert to Morse Code";
    dis[1][0] = "2. list all Text Convert to Morse Code";
    dis[2][0] = "3. Exit";
}
void display(int control)
{
    if (control == 1)
        dis_draw_main_manu();
    else if (control == 2)
        dis_draw_add_manu();
    else if (control == 3)
        ;
#ifdef _WIN32
    system("cls");
#else
    system("clear");
#endif
    dis_line();
    dis_hader();
    dis_line();
    dis_main();
    dis_line();
    input(control);
}
void dis_hader()
{
    cout << "|" << setw(1) << setw(75) << "Morse Code Playing" << setw(2) << setw(76) << "|" << endl;
}
void dis_line()
{
    for (int l = 0; l < 152; l++)
    {
        cout << "-";
    };
    cout << endl;
}
void dis_main()
{
    for (size_t i = 0; i < 50; i++)
    {
        dis[3][1] += "_";
    }

    for (int l = 0; l < 24; l++)
    {
        cout << left << setw(2) << "| " << setw(98) << dis[l][0] << setw(1) << "|" << setw(50) << dis[l][1] << setw(1) << "|" << endl
             << right;
    }
}
void dis_draw_add_manu()
{
    dis[0][0] = "";
    dis[1][0] = "      Add Text Convert to Morse Code";
    dis[2][0] = "";
}
void input(int control_input)
{
    if (control_input == 1)
    {
        bool input_main_manu = true;
        while (input_main_manu)
        {
            int choice;
            cout << "Enter your choice : ";
            cin >> choice;
            if (choice > 0 && choice < 4)
            {
                input_main_manu = false;
                dis_clear();
                display(2);
            }
            else
            {
                cout << "Please enter number 1-3" << endl;
                cin.ignore();
                cout << "Press Enter to continue...";
                cin.get();
                dis_clear();
                display(1);
            }
        }
    }
    if (control_input == 2)
    {
        cout << "Enter Text (NOT OVER 40 CHARACTER) : ";
        getline(std::cin >> std::ws, input_text);
        if (input_text.length() > 40)
        {
            cout << "Please enter text not over 40 character" << endl;
            cout << "Press Enter to continue...";
            cin.get();
            dis_clear();
            display(2);
        }
        else
        {
            string morsecode[37] = {"/", ".-", "-...", "-.-.", "-..", ".", "..-.", "--.", "....", "..", ".---", "-.-", ".-..", "--", "-.", "---", ".--.", "--.-", ".-.", "...", "-", "..-", "...-", ".--", "-..-", "-.--", "--..", ".----", "..---", "...--", "....-", ".....", "-....", "--...", "---..", "----.", "-----"};
            string alphabet[37] = {" ", "A", "B", "C", "D", "E", "F", "G", "H", "I", "J", "K", "L", "M", "N", "O", "P", "Q", "R", "S", "T", "U", "V", "W", "X", "Y", "Z", "1", "2", "3", "4", "5", "6", "7", "8", "9", "0"};
            for (int l = 0; l < input_text.length(); l++)
            {
                if (input_text[l] >= 97 && input_text[l] <= 122)
                {
                    input_text[l] -= 32;
                }
            }
            for (int i = 0; i < input_text.length(); i++)
            {
                for (int j = 0; j < 37; j++)
                {
                    if (input_text[i] == alphabet[j][0])
                    {
                        morse_done += morsecode[j] + " ";
                    }
                }
            }
            cout << endl;
            dis_clear();
            dis_draw_add_confirm(input_text, morse_done);
            display(3);
            input(100);
        }
    }
    if (control_input == 100)
    {
        bool input_add_manu = true;
        while (input_add_manu)
        {
            char command_add_manu;
            cout << "Command : ";
            cin >> command_add_manu;
            if (command_add_manu == 'p' || command_add_manu == 'P' || command_add_manu == 'y' || command_add_manu == 'Y' || command_add_manu == 'n' || command_add_manu == 'N')
            {
                input_add_manu = false;
                if (command_add_manu == 'p' || command_add_manu == 'P')
                {
                    dis_player_morse(morse_done);
                    display(3);
                }
                else if (command_add_manu == 'y' || command_add_manu == 'Y')
                {
                    dis_clear();
                    display(1);
                    cls_add_varible();
                }
                else if (command_add_manu == 'n' || command_add_manu == 'N')
                {
                    dis_clear();
                    display(1);
                    cls_add_varible();
                }
                // here
            }
            else
            {
                cout << "Please enter command \"p\" or \"P\" or \"y\" or \"Y\" or \"n\" or \"N\"" << endl;
                cin.ignore();
                cout << "Press Enter to continue...";
                cin.get();
                dis_clear();
                dis_draw_add_confirm(input_text, morse_done);
                display(3);
            }
        }
    }
}