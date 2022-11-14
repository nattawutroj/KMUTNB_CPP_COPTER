#include <vector>
#include <string>
#include <fstream>
#include <time.h>
#include <iostream>
std::string line = "";
std::string temp_input;
std::string Bufferen, Bufferde;
std::string history[1001][3];
typedef unsigned char BYTE;
std::string base64_encode(BYTE const *buf, unsigned int bufLen);
std::vector<BYTE> base64_decode(std::string const &);
static const std::string base64_chars =
    "ABCDEFGHIJKLMNOPQRSTUVWXYZ"
    "abcdefghijklmnopqrstuvwxyz"
    "0123456789+/";
static inline bool is_base64(BYTE c)
{
  return (isalnum(c) || (c == '+') || (c == '/'));
}
std::string base64_encode(BYTE const *buf, unsigned int bufLen)
{
  std::string ret;
  int i = 0;
  int j = 0;
  BYTE char_array_3[3];
  BYTE char_array_4[4];

  while (bufLen--)
  {
    char_array_3[i++] = *(buf++);
    if (i == 3)
    {
      char_array_4[0] = (char_array_3[0] & 0xfc) >> 2;
      char_array_4[1] = ((char_array_3[0] & 0x03) << 4) + ((char_array_3[1] & 0xf0) >> 4);
      char_array_4[2] = ((char_array_3[1] & 0x0f) << 2) + ((char_array_3[2] & 0xc0) >> 6);
      char_array_4[3] = char_array_3[2] & 0x3f;

      for (i = 0; (i < 4); i++)
        ret += base64_chars[char_array_4[i]];
      i = 0;
    }
  }

  if (i)
  {
    for (j = i; j < 3; j++)
      char_array_3[j] = '\0';

    char_array_4[0] = (char_array_3[0] & 0xfc) >> 2;
    char_array_4[1] = ((char_array_3[0] & 0x03) << 4) + ((char_array_3[1] & 0xf0) >> 4);
    char_array_4[2] = ((char_array_3[1] & 0x0f) << 2) + ((char_array_3[2] & 0xc0) >> 6);
    char_array_4[3] = char_array_3[2] & 0x3f;

    for (j = 0; (j < i + 1); j++)
      ret += base64_chars[char_array_4[j]];

    while ((i++ < 3))
      ret += '=';
  }

  return ret;
}
std::vector<BYTE> base64_decode(std::string const &encoded_string)
{
  int in_len = encoded_string.size();
  int i = 0;
  int j = 0;
  int in_ = 0;
  BYTE char_array_4[4], char_array_3[3];
  std::vector<BYTE> ret;

  while (in_len-- && (encoded_string[in_] != '=') && is_base64(encoded_string[in_]))
  {
    char_array_4[i++] = encoded_string[in_];
    in_++;
    if (i == 4)
    {
      for (i = 0; i < 4; i++)
        char_array_4[i] = base64_chars.find(char_array_4[i]);

      char_array_3[0] = (char_array_4[0] << 2) + ((char_array_4[1] & 0x30) >> 4);
      char_array_3[1] = ((char_array_4[1] & 0xf) << 4) + ((char_array_4[2] & 0x3c) >> 2);
      char_array_3[2] = ((char_array_4[2] & 0x3) << 6) + char_array_4[3];

      for (i = 0; (i < 3); i++)
        ret.push_back(char_array_3[i]);
      i = 0;
    }
  }

  if (i)
  {
    for (j = i; j < 4; j++)
      char_array_4[j] = 0;

    for (j = 0; j < 4; j++)
      char_array_4[j] = base64_chars.find(char_array_4[j]);

    char_array_3[0] = (char_array_4[0] << 2) + ((char_array_4[1] & 0x30) >> 4);
    char_array_3[1] = ((char_array_4[1] & 0xf) << 4) + ((char_array_4[2] & 0x3c) >> 2);
    char_array_3[2] = ((char_array_4[2] & 0x3) << 6) + char_array_4[3];

    for (j = 0; (j < i - 1); j++)
      ret.push_back(char_array_3[j]);
  }

  return ret;
}
void encode(std::string sstr, int con);
void draw();
void history_remove();
void openfile();
void dis_history();
void openfile_list();
void wirtefile();
void openfile()
{
  std::ifstream file;
  file.open("code.txt");
  if (file.is_open())
  {
    while (!file.eof())
    {
      std::getline(file, Bufferde);
    }
  }
  file.close();
}
void wirtefile_list();
void list();
void draw()
{
  for (int l = 0; l < 50; l++)
  {
    line += "*";
  }
}
void wirtefile()
{
  std::ofstream file;
  file.open("code.txt");
  if (file.is_open())
  {
    file << Bufferen;
  }
  file.close();
}
void encode(std::string sstr, int con)
{
  std::string str = "";
  str = sstr;
  std::string enreal = sstr;
  std::string encoded = base64_encode((const unsigned char *)str.c_str(), str.length());
  std::vector<BYTE> decoded = base64_decode(enreal);
  if (con == 1)
  {
    std::cout << "Encoded: " << encoded << std::endl;
    Bufferen = encoded;
    int l = 0;
    while (history[l][0] != history[1000][0])
    {
      l++;
    }
    history[l][0] = temp_input;
    history[l][1] = str;
    history[l][2] = encoded;
  }
  else if (con == 2)
  {
    std::cout << "Decoded: " << std::string(decoded.begin(), decoded.end()) << std::endl;
    Bufferde = std::string(decoded.begin(), decoded.end());
  }
}
void openfile_list()
{
  std::ifstream file;
  file.open("history.txt");
  int loop = 0;
  while (!file.eof())
  {
    std::getline(file, history[loop][0]);
    std::getline(file, history[loop][1]);
    std::getline(file, history[loop][2]);
    loop++;
  }
  file.close();
}
void wirtefile_list()
{
  std::ofstream file;
  file.open("history.txt");
  for (int l = 0; history[l][0] != ""; l++)
  {
    file << history[l][0] << std::endl
         << history[l][1] << std::endl
         << history[l][2] << std::endl;
  }
  file.close();
}
void history_remove()
{
  int his = 1;
  int start_page = 1;
  while (his == 1)
  {
#ifdef _WIN32
    system("cls");
#else
    system("clear");
#endif
    std::cout << "History: " << std::endl
              << std::endl;
    int i = 0;
    while (history[i][0] != "")
    {
      i++;
    }
    int end_page = i / 5;
    if (end_page == 0)
      end_page = 1;
    std::cout << "page " << start_page << " of " << end_page << std::endl;
    int le = start_page * 5;
    for (int l = (start_page * 5) - 5; l <= le; l++)
    {
      std::cout << line << " . " << l + 1 << " . " << line << std::endl;
      std::cout << "Raw String : " << history[l][0] << std::endl;
      std::cout << "Morse code : " << history[l][1] << std::endl;
      std::cout << "Base64 encode : " << history[l][2] << std::endl;
      std::cout << line << "*******" << line << std::endl
                << std::endl;
    }
    std::string rm_input;
    std::cout << "Typeing Number for select page \" Ex. 3 \" "<<std::endl<<"Typeing character 'd' before number for remove list \" Ex. d2 \" " << std::endl;
    std::cout << "Typeing 'q' for exit" << std::endl;
    std::cout << "Enter Command : ";
    std::cin >> rm_input;
    if(rm_input[0] == 'q')
    {
      his = 0;
    }
    else if (rm_input[0] == 'd')
    {
      int rm_position = std::stoi(rm_input.substr(1, rm_input.length()));
      for (int l = rm_position - 1; l < 1000; l++)
      {
        history[l][0] = history[l + 1][0];
        history[l][1] = history[l + 1][1];
        history[l][2] = history[l + 1][2];
      }
      wirtefile_list();
      //wait
    }
    else if (rm_input[0] == '1' || rm_input[0] == '2' || rm_input[0] == '3' || rm_input[0] == '4' || rm_input[0] == '5' || rm_input[0] == '6' || rm_input[0] == '7' || rm_input[0] == '8' || rm_input[0] == '9' || rm_input[0] == '0')
    {
      start_page = std::stoi(rm_input);
    }
  }
}
void dis_history()
{
  int his = 1;
  int start_page = 1;
  while (his == 1)
  {
#ifdef _WIN32
    system("cls");
#else
    system("clear");
#endif
    std::cout << "History: " << std::endl
              << std::endl;
    int i = 0;
    while (history[i][0] != "")
    {
      i++;
    }
    int end_page = i / 5;
    if (end_page == 0)
      end_page = 1;
    std::cout << "page " << start_page << " of " << end_page << std::endl;
    int le = start_page * 5;
    for (int l = (start_page * 5) - 5; l <= le; l++)
    {
      std::cout << line << " . " << l + 1 << " . " << line << std::endl;
      std::cout << "Raw String : " << history[l][0] << std::endl;
      std::cout << "Morse code : " << history[l][1] << std::endl;
      std::cout << "Base64 encode : " << history[l][2] << std::endl;
      std::cout << line << "*******" << line << std::endl
                << std::endl;
    }
    std::cout << "Enter page number to go to page Enter 0 to exit" << std::endl;
    std::cin >> start_page;
    if (start_page == 0)
    {
      //edit charactor exit
      his = 0;
    }
  }
}
int main()
{
  openfile_list();
  draw();
  std::string morseCode[27] = {"_", ".-", "-...", "-.-.", "-..", ".", "..-.", "--.", "....", "..", ".---", "-.-", ".-..", "--", "-.", "---", ".--.", "--.-", ".-.", "...", "-", "..-", "...-", ".--", "-..-", "-.--", "--.."};
  char alphabet[27] = {' ', 'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l', 'm', 'n', 'o', 'p', 'q', 'r', 's', 't', 'u', 'v', 'w', 'x', 'y', 'z'};
  int dw = 1;
  while (dw == 1)
  {
#ifdef _WIN32
    system("cls");
#else
    system("clear");
#endif
    std::string input;
    std::string output;
    int choice;
    std::cout << line << std::endl;
    std::cout << "1. Text to morse code" << std::endl;
    std::cout << "2. Morse code to text" << std::endl;
    std::cout << "3. History Encode" << std::endl;
    std::cout << "4. History Remove" << std::endl;
    std::cout << "5. Exit" << std::endl;
    std::cout << line << std::endl;
    std::cout << "Enter your choice: ";
    std::cin >> choice;
    if (choice == 1)
    {
      std::cout << "Enter a word to convert to morse code: ";
      std::getline(std::cin >> std::ws, input);
      temp_input = input;
      for (int i = 0; i < input.length(); i++)
      {
        for (int j = 0; j < 27; j++)
        {
          if (input[i] == alphabet[j])
          {
            output += morseCode[j];
            output += " ";
          }
        }
      }
      output += "";
      std::cout << output << std::endl;
      encode(output, 1);
      wirtefile();
      wirtefile_list();
      std::cout << "Press enter to continue...";
      std::cin.ignore();
      std::cin.ignore();
    }
    else if (choice == 2)
    {
      openfile();
      encode(Bufferde, 2);
      std::string input[1000];
      std::string output;
      std::cout << "input morse code: ";
      int loop = 0, loopin = 0;
      while (loop <= Bufferde.length())
      {
        if (Bufferde[loop] == ' ')
        {
          loopin++;
          loop++;
        }
        input[loopin] += Bufferde[loop];
        if (input[loopin] == input[999])
        {
          break;
        }
        loop++;
      }
      for (int i = 0; i < 100; i++)
      {
        for (int j = 0; j < 27; j++)
        {
          if (input[i] == morseCode[j])
          {
            std::cout << alphabet[j];
          }
        }
      }
      std::cout << std::endl;
      std::cout << "Press enter to continue...";
      std::cin.ignore();
      std::cin.ignore();
    }
    else if (choice == 3)
    {
      dis_history();
      std::cout << "Press enter to continue...";
      std::cin.ignore();
      std::cin.ignore();
    }
    else if (choice == 4)
    {
      history_remove();
    }
    else if (choice == 5)
    {
      dw = 0;
    }
    else
    {
      std::cout << "Invalid choice" << std::endl;
    }
  }
  return 0;
}