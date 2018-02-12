// CaeserCipher.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <string>

using namespace std;


std::string cipher(int key, std::string word)
{
	char letter[26]{ 'a','b','c','d','e','f','g','h','i','j','k','l','m','n','o','p','q','r','s','t','u','v','w','x','y','z' };
	char letterNew[26];
	std::string wordNew;


	for (int i = 0; i < 26; i++)
	{
		letterNew[i] = letter[((i + key) % 26)];
	}

	for (int i = 0; i < word.size(); i++)
	{
		bool letterFound = false;
		for (int j = 0; j < 26; j++)
		{
			if ((word[i] == letter[j]) && (letterFound == false))
			{
				word[i] = letterNew[j];
				letterFound = true;
			}
		}
	}

	return word;

}

int main()
{
	std::string word;
	std::string wordNew;
	int key;
	int menu=-1;

	while (menu != 0)
	{
		std::cout << "for caeser cipher coder, input 1" << std::endl;
		std::cout << "for caeser cipher decoder, input 2" << std::endl;
		std::cout << "to quit, input 0" << std::endl;
		std::cin >> menu;

		if (menu == 1)													//cipher coder
		{
			std::cout << "please insert cipher key:" << std::endl;
			std::cin >> key;
			std::cout << "please insert word to cipher:" << std::endl;
			std::cin >> word;
			wordNew = cipher(key, word);

			cout << "the coded word is:   " << wordNew << "\n" << endl;

		}
		else if (menu == 2)												//cipher decoder
		{
			std::cout << "please insert cipher key:" << std::endl;
			std::cin >> key;
			std::cout << "please insert word to decipher:" << std::endl;
			std::cin >> word;
			wordNew = cipher((-key), word);

			cout << "the decoded word is:   "<< wordNew << "\n" << endl;
		}
		else if (menu == 0)												//exit
		{
			break;
		}
		else															//invalid input
		{
			std::cout << "invalid number enetered\n" << std::endl;
		}

	}
    return 0;
}


