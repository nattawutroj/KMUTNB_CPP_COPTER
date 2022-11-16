#include <iostream>
#include <iomanip>
#include <string>
#include <windows.h>
#include <fstream>
using namespace std;
string list[1000][3];
string dis[400][10];
string input_text;
string morse_done;
int position = 1;
void file_maker();
void file_writer();
void display(int control);
void dis_line();
void dis_hader();
void dis_main();
void dis_draw_list_manu();
void dis_draw_add_manu();
void dis_draw_main_manu();
void dis_draw_add_confirm(string input_text, string morse_done);
void dis_clear();
void dis_draw_select();
void dis_player_morse(string morse_done, int control_command);
void wirte_list_array(string input_text, string morse_done);
void cls_add_varible();
void input(int control_input);
int main()
{
    file_maker();
    display(1);
    return 0;
}
void dis_draw_select()
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
    dis[17][0] = "   Type \"b\" or \"B\" to Back to list Morse Code";
}
void dis_draw_list_manu()
{
    int count_list = 0;
    while (list[count_list][0] != "")
    {
        count_list++;
    }
    int com = 0;
    int end = position * 20;
    for (int start = (position * 20) - 20; start < end; start++)
    {
        if(list[start][0] != "")
        {
            dis[com][0] = to_string(start + 1) + "  " + list[start][0];
        }
        com++;
    }
    count_list = (count_list/20)+1;
    dis[1][1] = "  List of Morse Code Page " + to_string(position) + " of " + to_string(count_list);
    dis[8][1] = "  Type \"p\" or \"P\" and Number";
    dis[9][1] = "                            Move to Page (Ex. p2)";
    dis[11][1] = "  Type \"s\" or \"S\" and Number";
    dis[12][1] = "                       Select Morse Code (Ex. s2)";
    dis[14][1] = "  Type \"d\" or \"D\" and Number";
    dis[15][1] = "                             Delete List (Ex. d2)";
    dis[17][1] = "  Type \"b\" or \"B\"";
    dis[18][1] = "                               Back to Main Manu";
}
void wirte_list_array(string input_text, string morse_done)
{
    int i = 0;
    while (list[i][0] != "")
    {
        i++;
    }
    list[i][0] = input_text;
    list[i][1] = morse_done;
    file_writer();
}
void file_writer()
{
    ofstream file;
    file.open("list.txt");
    for (int i = 0; list[i][0] != ""; i++)
    {
        file << list[i][0] << endl;
        file << list[i][1] << endl;
    }
    file.close();
}
void file_maker()
{
    ifstream ifile;
    ifile.open("list.txt");
    if (ifile.fail())
    {
        ofstream ofile;
        ofile.open("list.txt");
        ofile.close();
    }
    else
    {
        for (int i = 0; !ifile.eof(); i++)
        {
            getline(ifile, list[i][0]);
            getline(ifile, list[i][1]);
        }
    }
    ifile.close();
}

void cls_add_varible()
{
    input_text = "";
    morse_done = "";
}
void dis_player_morse(string morse_done, int control_command)
{
    for (int l = 0; l <= morse_done.length(); l++)
    {
        dis[5][1] = "  " + morse_done.substr(l, 1);
        Sleep(100);
        if (morse_done[l] == '.')
        {
            dis[3][1] = "";
            for (int l = 7; l < 22; l++)
            {
                dis[l][1] = "   @@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@   ";
            }
            display(3);
            Sleep(100);
            Beep(641, 100);
            dis[3][1] = "";
            for (int l = 7; l < 22; l++)
            {
                dis[l][1] = "";
            }
            display(3);
            Sleep(10);
        }
        else if (morse_done[l] == '-')
        {
            dis[3][1] = "";
            for (int l = 7; l < 22; l++)
            {
                dis[l][1] = "   @@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@   ";
            }
            display(3);
            Sleep(240);
            Beep(651, 250);
            dis[3][1] = "";
            for (int l = 7; l < 22; l++)
            {
                dis[l][1] = "";
            }
            display(3);
            Sleep(10);
        }
        else
        {
            Sleep(10);
        }
        dis[3][1] = "";
        for (int l = 7; l < 22; l++)
        {
            dis[l][1] = "";
        }
    }
    display(control_command);
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
    dis[0][0] = "1. Add Text Convert to Morse Code";
    dis[1][0] = "2. List all Text Convert to Morse Code";
    dis[2][0] = "3. Exit";
}
void display(int control)
{
    if (control == 1)
        dis_draw_main_manu();
    else if (control == 2)
        dis_draw_add_manu();
    else if (control == 4)
        dis_draw_list_manu();
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
                if (choice == 1)
                {
                    dis_clear();
                    display(2);
                }
                else if (choice == 2)
                {
                    dis_clear();
                    display(4);
                }
                else if (choice == 3)
                {
                    exit(0);
                }
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
    if (control_input == 4)
    {
        bool input_list_manu = true;
        while (input_list_manu)
        {
            string choice;
            cout << "Command : ";
            cin >> choice;
            if (choice[0] == 'd' || choice[0] == 'D')
            {
                input_list_manu = false;
                int rm_position = std::stoi(choice.substr(1, choice.length()));
                for (int l = rm_position - 1; l < 1000; l++)
                {
                    list[l][0] = list[l + 1][0];
                    list[l][1] = list[l + 1][1];
                    list[l][2] = list[l + 1][2];
                }
                file_writer();
                dis_clear();
                display(4);
            }
            else if (choice[0] == 'p' || choice[0] == 'P')
            {
                input_list_manu = false;
                position = std::stoi(choice.substr(1, choice.length()));
                dis_clear();
                display(4);
            }
            else if (choice[0] == 's' || choice[0] == 'S')
            {
                input_list_manu = false;
                int select_position = std::stoi(choice.substr(1, choice.length()));
                morse_done = list[select_position - 1][1];
                input_text = list[select_position - 1][0];
                dis_clear();
                dis_draw_select();
                display(110);
            }
            else if (choice[0] == 'b' || choice[0] == 'B')
            {
                input_list_manu = false;
                dis_clear();
                display(1);
            }
            else
            {
                cout << "Please enter command again is Worng" << endl;
                cout << "Press Enter to continue...";
                cin.get();
                dis_clear();
                display(4);
            }
        }
    }
    if (control_input == 110)
    {
        bool input_select_manu = true;
        while (input_select_manu)
        {
            char command_select_manu;
            cout << "Command : ";
            cin >> command_select_manu;
            if (command_select_manu == 'p' || command_select_manu == 'P' ||  command_select_manu == 'b' || command_select_manu == 'B')
            {
                input_select_manu = false;
                if (command_select_manu == 'p' || command_select_manu == 'P')
                {
                    dis_player_morse(morse_done, 110);
                    display(3);
                }
                else if (command_select_manu == 'b' || command_select_manu == 'B')
                {
                    cout << "Back Manu" << endl;
                    cin.ignore();
                    cout << "Press Enter to continue...";
                    cin.get();
                    dis_clear();
                    cls_add_varible();
                    display(4);
                }
            }
            else
            {
                cout << "Please enter command \"p\" or \"P\" or \"b\" or \"B\"" << endl;
                cin.ignore();
                cout << "Press Enter to continue...";
                cin.get();
                dis_clear();
                dis_draw_select();
                display(110);
            }
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
                    dis_player_morse(morse_done, 100);
                    display(3);
                }
                else if (command_add_manu == 'y' || command_add_manu == 'Y')
                {
                    wirte_list_array(input_text, morse_done);
                    cout << "Add Complete" << endl;
                    cin.ignore();
                    cout << "Press Enter to continue...";
                    cin.get();
                    dis_clear();
                    cls_add_varible();
                    display(1);
                }
                else if (command_add_manu == 'n' || command_add_manu == 'N')
                {
                    cout << "Add Cancel" << endl;
                    cin.ignore();
                    cout << "Press Enter to continue...";
                    cin.get();
                    dis_clear();
                    cls_add_varible();
                    display(1);
                }
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