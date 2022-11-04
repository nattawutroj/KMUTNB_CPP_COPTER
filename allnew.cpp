#ifndef _BASE64_H_
#define _BASE64_H_
#include <vector>
#include <string>
#include <fstream>
std::string Bufferen, Bufferde;
typedef unsigned char BYTE;
std::string base64_encode(BYTE const *buf, unsigned int bufLen);
std::vector<BYTE> base64_decode(std::string const &);
#endif
#include <iostream>
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
void encode();
void openfile();
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
void wirtefile();
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
void encode(std::string sstr)
{
  std::string str = "";
  str = sstr;
  std::string enreal = sstr;
  std::string encoded = base64_encode((const unsigned char *)str.c_str(), str.length());
  std::vector<BYTE> decoded = base64_decode(enreal);
  std::cout << "Encoded: " << encoded << std::endl;
  Bufferen = encoded;
  std::cout << "Decoded: " << std::string(decoded.begin(), decoded.end()) << std::endl;
  Bufferde = std::string(decoded.begin(), decoded.end());
}

int main()
{
  std::string morseCode[26] = {".-", "-...", "-.-.", "-..", ".", "..-.", "--.", "....", "..", ".---", "-.-", ".-..", "--", "-.", "---", ".--.", "--.-", ".-.", "...", "-", "..-", "...-", ".--", "-..-", "-.--", "--.."};
  char alphabet[26] = {'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l', 'm', 'n', 'o', 'p', 'q', 'r', 's', 't', 'u', 'v', 'w', 'x', 'y', 'z'};
  std::string input;
  std::string output;
  int choice;
  std::cout << "1. Text to morse code" << std::endl;
  std::cout << "2. Morse code to text" << std::endl;
  std::cout << "Enter your choice: ";
  std::cin >> choice;
  if (choice == 1)
  {
    std::cout << "Enter a word to convert to morse code: ";
    std::cin >> input;
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
    output += "";
    std::cout << output << std::endl;
    encode(output);
    wirtefile();
  }
  else if (choice == 2)
  {
    openfile();
    encode(Bufferde);
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
      for (int j = 0; j < 26; j++)
      {
        if (input[i] == morseCode[j])
        {
          std::cout << alphabet[j];
        }
      }
    }
  }
  else
  {
    std::cout << "Invalid choice" << std::endl;
  }
  return 0;
}