// CaeserCipher.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <string>

using namespace std;

int main()
{
	char letter[26]{'a','b','c','d','e','f','g','h','i','j','k','l','m','n','o','p','q','r','s','t','u','v','w','x','y','z'};
	char letterNew[26];
	std::string word;
	std::string wordNew;
	int key;

	std::cout << "please insert cipher key:" <<std::endl;
	std::cin >> key;
	std::cout << "please insert word to cipher:" << std::endl;
	std::cin >> word;

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

	
	cout << word;

    return 0;
}

