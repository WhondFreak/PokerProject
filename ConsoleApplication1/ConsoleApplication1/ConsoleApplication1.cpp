// ConsoleApplication1.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "pch.h"
#include <iostream>
#include <vector>
#include <ctype.h>
#include <locale>
#include <string>
#include <algorithm>
#include <random>
#include <chrono>

/*
Values:
2 = 2
3 = 3
4 = 4
5 = 5
6 = 6
7 = 7
8 = 8
9 = 9
10 = 10
11 = J
12 = Q
13 = K
14 = A

2-14 = Hearts
15-27 = Diamonds
28-40 = Clubs
41-53 = Spades
*/

struct hand
{
	int first = 0;
	int second = 0;
	int viewed = 0;
};



int main()
{
	bool run = true;
	int choice = 0;
	int size = 0;
	int i = 0;
	int Fcard = 1;
	int Scard = 1;
	std::vector<hand> pair;
	struct hand Poker;
	
	//Skapar en random seed vi använder för att blanda leken
	unsigned seed = std::chrono::system_clock::now()
		.time_since_epoch()
		.count();

	// Lägger till alla möjliga händer i en vector
	while (Fcard <= 52)
		{
			while (Scard <= 52)
			{
				if (!(Fcard == Scard))
				{
					Poker.first = Fcard + 1;
					Poker.second = Scard + 1;
					pair.push_back(Poker);
					size++;
					Scard++;
				}
				else
				{
					Scard++;
				}
			}
			Fcard++;
			Scard = Fcard;
		}
	std::cout << "Poker game \n ------------------------------------- \n 1. Start Practice. \n 2. Set-up Your Range. \n 3. Shuffle the deck. \n 4. Quit. \n ------------------------------------- \n\n";
	

	//Kör programmet
	while (true == run)
	{
		
		//Ber användaren göra ett val och kollar om användaren skriver in nummer.
		while (!(std::cin >> choice))
		{
			std::cout << "Incorrect character entered. Please use a number" << std::endl;
			std::cin.clear();
			std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
			//std::cout << "Poker game \n ------------------------------------- \n 1. Start Practice. \n 2. Set-up Your Range. \n 3. Quit. \n ------------------------------------- \n\n";
		}

				// Main menyn
				switch (choice)
				{
				case 1:
				{
					while  (i <= size)
					{
						// Hjärter
						if (pair[i].first <= 10)
						{
							std::cout << pair[i].first << "h ";
						}
						else if (pair[i].first == 11)
						{
							std::cout << "Jh ";
						}
						else if (pair[i].first == 12)
						{
							std::cout << "Qh ";
						}
						else if (pair[i].first == 13)
						{
							std::cout << "Kh ";
						}
						else if (pair[i].first == 14)
						{
							std::cout << "Ah ";
						}
						
						// Ruter
						else if (pair[i].first >= 15 && pair[i].first <= 23)
						{
							std::cout << pair[i].first - 13 << "d ";
						}
						else if (pair[i].first == 24)
						{
							std::cout << "Jd ";
						}
						else if (pair[i].first == 25)
						{
							std::cout << "Qd ";
						}
						else if (pair[i].first == 26)
						{
							std::cout << "Kd ";
						}
						else if (pair[i].first == 27)
						{
							std::cout << "Ad ";
						}

						// Klöver
						else if (pair[i].first <= 10)
						{
							std::cout << pair[i].first << "h ";
						}
						else if (pair[i].first == 11)
						{
							std::cout << "Jh ";
						}
						else if (pair[i].first == 12)
						{
							std::cout << "Qh ";
						}
						else if (pair[i].first == 13)
						{
							std::cout << "Kh ";
						}
						else if (pair[i].first == 14)
						{
							std::cout << "Ah ";
						}

						// Spader
						else if (pair[i].first <= 10)
						{
							std::cout << pair[i].first << "h ";
						}
						else if (pair[i].first == 11)
						{
							std::cout << "Jh ";
						}
						else if (pair[i].first == 12)
						{
							std::cout << "Qh ";
						}
						else if (pair[i].first == 13)
						{
							std::cout << "Kh ";
						}
						else if (pair[i].first == 14)
						{
							std::cout << "Ah ";
						}
					}
					//std::cout << "1 \n\n";
					break;
				}

				case 2:
				{
					std::cout << "2 \n\n";
					break;
				}

				case 3:
				{
					//Blandar leken med våran random seed
					shuffle(std::begin(pair), std::end(pair), std::default_random_engine(seed));
					std::cout << "The deck has been shuffled! \n\n";
					break;
				}

				case 4:
				{
					std::cout << "3 \n\n";
					run = false;
					break;
				}

				default:
				{
					std::cout << "That is not a valid option, please try again \n\n";
					break;
				}

				}
		
		
	}


    std::cout << pair.size() << "\n"; 
	std::cout << pair[0].first << " " << pair[0].second << "\n";
	std::cout << pair[1].first << " " << pair[1].second << "\n";
	std::cout << pair[12].first << " " << pair[12].second << "\n";
	std::cin;
	return 0;
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
