//Student Name:		Rasul Iskandarov
//Date:				23/12/2021

#ifdef _DEBUG 
#pragma comment(lib,"sfml-graphics-d.lib") 
#pragma comment(lib,"sfml-audio-d.lib") 
#pragma comment(lib,"sfml-system-d.lib") 
#pragma comment(lib,"sfml-window-d.lib") 
#pragma comment(lib,"sfml-network-d.lib") 
#else 
#pragma comment(lib,"sfml-graphics.lib") 
#pragma comment(lib,"sfml-audio.lib") 
#pragma comment(lib,"sfml-system.lib") 
#pragma comment(lib,"sfml-window.lib") 
#pragma comment(lib,"sfml-network.lib") 
#endif 

#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <SFML/System.hpp>
#include <iostream>
#include <stdlib.h> 
#include <time.h> 
#include <string>
#include <fstream>

std::string Read(std::string path) {
	std::string data = "";
	std::string line;
	std::ifstream file;

	file.open(path);

	while (file)
	{
		if (getline(file, line))
		{
			data += " ";
			data += line;
		}
	}

	file.close();

	return data;
}

void Part_1(std::string data)
{
	int indexData = 0;
	int indexArr = 0;
	int sizeArr = 0;
	int result = 0;

	while (indexData < data.size() && data.at(indexData) != '\0')
	{
		int digit = data.at(indexData) - '0';

		if (digit >= 0 && digit <= 9)
		{
			sizeArr = digit;
			indexData++;
			break;
		}

		indexData++;
	}

	int* arr = new int[sizeArr] {};

	while (indexData < data.size() && data.at(indexData) != '\0')
	{
		int digit = data.at(indexData) - '0';

		if (digit >= 0 && digit <= 9 && indexArr < sizeArr)
		{
			result = digit;

			indexData++;

			while (indexData < data.size() && data.at(indexData) != '\0')
			{
				digit = data.at(indexData) - '0';

				if (digit >= 0 && digit <= 9 && indexArr < sizeArr)
				{
					result *= 10;
					result += digit;
					indexData++;
				}
				else
				{
					break;
				}
			}

			arr[indexArr] = result;
			indexArr++;
		}

		indexData++;
	}

	std::cout << "Part 1:" << std::endl << std::endl;

	for (int raw = 0; raw < sizeArr; raw++)
	{
		for (int column = 0; column < arr[raw]; column++)
		{
			std::cout << "0";
		}
		std::cout << std::endl;
	}

	std::cout << std::endl;

	delete[] arr;
}

void Part_2(std::string data)
{
	int indexData = 0;
	int indexArr = 0;
	int result = 0;
	int sizeArr = 0;

	int maxHeight = 0;

	while (indexData < data.size() && data.at(indexData) != '\0')
	{
		int digit = data.at(indexData) - '0';

		if (digit >= 0 && digit <= 9)
		{
			sizeArr = digit;
			indexData++;
			break;
		}

		indexData++;
	}

	int* arr = new int[sizeArr] {};

	while (indexData < data.size() && data.at(indexData) != '\0')
	{
		int digit = data.at(indexData) - '0';

		if (digit >= 0 && digit <= 9 && indexArr < sizeArr)
		{
			result = digit;

			indexData++;

			while (indexData < data.size() && data.at(indexData) != '\0')
			{
				digit = data.at(indexData) - '0';

				if (digit >= 0 && digit <= 9 && indexArr < sizeArr)
				{
					result *= 10;
					result += digit;
					indexData++;
				}
				else
				{
					break;
				}
			}

			arr[indexArr] = result;
			indexArr++;
			
			if (result > maxHeight)
			{
				maxHeight = result;
			}
		}

		indexData++;
	}

	std::cout << "Part 2:" << std::endl << std::endl;

	for (int raw = 0; raw < maxHeight; raw++)
	{
		for (int column = 0; column < sizeArr; column++)
		{
			if (arr[column] >= maxHeight - raw)
			{
				std::cout << "0 ";
			}
			else 
			{
				std::cout << "  ";
			}
		}
		std::cout << std::endl;
	}

	std::cout << std::endl;

	delete[] arr;
}

void Part_3_1(std::string data)
{
	//Covid-19 Cases Worldwide:	 https://www.ecdc.europa.eu/en/geographical-distribution-2019-ncov-cases

	const int numOfElem = 6;
	int witdhOfBar = 20;
	float height[numOfElem] = {};

	sf::Font Font;
	sf::Text Header;
	sf::Text verticalNumbers[6];
	sf::Text Names[numOfElem];

	if (!Font.loadFromFile("res/Fonts/arialRasulC00246498.ttf"))
	{
		std::cout << "Couldn't open ttf sf::Font File!" << std::endl;
	}
	
	for (int index = 0, indexData = 0; index < numOfElem; index++)
	{
		while (indexData < data.size() && data.at(indexData) == ' ') { indexData++; }

		if (indexData < data.size())
		{
			if((data.at(indexData) >= 'a' && data.at(indexData) <= 'z') || (data.at(indexData) >= 'A' && data.at(indexData) <= 'Z'))
			{
				std::string name = "";

				while (indexData < data.size() && data.at(indexData) != ':')
				{
					name += data.at(indexData);
					indexData++;
				}
				Names[index].setString(name);
			}
		}

		while (indexData < data.size() && data.at(indexData) == ' ' || data.at(indexData) == ':') { indexData++; }

		if (indexData < data.size())
		{
			if (data.at(indexData) >= '0' && data.at(indexData) <= '9')
			{
				std::string num = "";
				float numberConverted;
				while (indexData < data.size() && (data.at(indexData) != ':' && data.at(indexData) != ' '))
				{
					num += data.at(indexData);
					indexData++;
				}
				numberConverted = stoi(num);
				numberConverted /= 300000;
				height[index] = numberConverted;
			}
		}
	}

	verticalNumbers[0].setString("0 M");
	verticalNumbers[1].setString("20 M");
	verticalNumbers[2].setString("40 M");
	verticalNumbers[3].setString("60 M");
	verticalNumbers[4].setString("80 M");
	verticalNumbers[5].setString("100 M");
	Header.setString("Covid-19 Cases Worldwide");


	sf::RenderWindow window(sf::VideoMode(850, 700), "Bar Chart with SFML in C++");
	sf::RectangleShape bar1(sf::Vector2f(witdhOfBar, height[0]));
	sf::RectangleShape bar2(sf::Vector2f(witdhOfBar, height[1]));
	sf::RectangleShape bar3(sf::Vector2f(witdhOfBar, height[2]));
	sf::RectangleShape bar4(sf::Vector2f(witdhOfBar, height[3]));
	sf::RectangleShape bar5(sf::Vector2f(witdhOfBar, height[4]));
	sf::RectangleShape bar6(sf::Vector2f(witdhOfBar, height[5]));
	sf::RectangleShape xLine(sf::Vector2f(1, 600));
	sf::RectangleShape yLine(sf::Vector2f(1, 334));


	Header.setPosition(250, 25);
	bar1.setPosition(200, (500 - height[0])); 
	bar2.setPosition(300, (500 - height[1])); 
	bar3.setPosition(400, (500 - height[2])); 
	bar4.setPosition(500, (500 - height[3])); 
	bar5.setPosition(600, (500 - height[4])); 
	bar6.setPosition(700, (500 - height[5]));
	Names[0].setPosition(200 - 5, (550 - height[0]));
	Names[1].setPosition(300 - 5, (550 - height[0]));
	Names[2].setPosition(400 - 5, (550 - height[0]));
	Names[3].setPosition(500 - 5, (550 - height[0]));
	Names[4].setPosition(600 - 5, (550 - height[0]));
	Names[5].setPosition(700 - 5, (550 - height[0]));
	xLine.setPosition(150, 501);
	xLine.rotate(270);
	yLine.setPosition(150, 501);
	yLine.rotate(180);
	for (int index = 0; index < numOfElem; index++)
	{
		verticalNumbers[index].setPosition(100, 501-67*index-10); 
	}


	Header.setFont(Font);
	Header.setFillColor(sf::Color::White);
	Header.setCharacterSize(28);
	bar1.setFillColor(sf::Color(100, 250, 50));
	bar2.setFillColor(sf::Color(10, 20, 100));
	bar3.setFillColor(sf::Color(500, 600, 700));
	bar4.setFillColor(sf::Color(200, 300, 50));
	bar5.setFillColor(sf::Color(10, 100, 45));
	bar6.setFillColor(sf::Color(100, 150, 45));
	xLine.setFillColor(sf::Color::White);
	yLine.setFillColor(sf::Color::White);
	for (int index = 0; index < numOfElem; index++)
	{
		Names[index].setFont(Font);
		Names[index].setFillColor(sf::Color::White);
		Names[index].setCharacterSize(16);

        verticalNumbers[index].setFont(Font);
		verticalNumbers[index].setFillColor(sf::Color::White);
		verticalNumbers[index].setCharacterSize(16);
	}


	window.draw(Header);
	window.draw(bar1);
	window.draw(bar2);
	window.draw(bar3);
	window.draw(bar4);
	window.draw(bar5);
	window.draw(bar6);
	window.draw(xLine);
	window.draw(yLine);
	for (int index = 0; index < numOfElem; index++)
	{
		window.draw(Names[index]);
		window.draw(verticalNumbers[index]);
	}


	std::cout << "Part 3 section 1:" << std::endl << std::endl;


	window.display();


	sf::Time timePerFrame = sf::seconds(1.0f / 60.0f);
	sf::Time timeSinceLastUpdate = sf::Time::Zero;

	while (window.isOpen())
	{
		sf::Event event;
		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
			{
				window.close();
				std::cout << "Closed!" << std::endl << std::endl;
			}
		}
	}
}

void Part_3_2(std::string data)
{
	//Covid-19 Cases Worldwide by years:	 https://ourworldindata.org/coronavirus-data

	const int numOfElem = 6;
	int witdhOfBar = 20;
	float height[numOfElem] = {};

	sf::Font Font;
	sf::Text Header;
	sf::Text verticalNumbers[6];
	sf::Text Dates[numOfElem];

	if (!Font.loadFromFile("res/Fonts/arialRasulC00246498.ttf"))
	{
		std::cout << "Couldn't open ttf sf::Font File!" << std::endl;
	}

	for (int index = 0, indexData = 0; index < numOfElem; index++)
	{
		while (indexData < data.size() && data.at(indexData) == ' ') { indexData++; }

		if (indexData < data.size())
		{
			if (data.at(indexData) != ':')
			{
				std::string name = "";

				while (indexData < data.size() && data.at(indexData) != ':')
				{
					if (data.at(indexData) != ',')
					{
						name += data.at(indexData);
						indexData++;
					}
					else
					{
						indexData++;
						break;
					}
				}

				name += ",\n";

				while (indexData < data.size() && data.at(indexData) != ':')
				{
					name += data.at(indexData);
					indexData++;
				}

				Dates[index].setString(name);
			}
		}

		while (indexData < data.size() && data.at(indexData) == ' ' || data.at(indexData) == ':') { indexData++; }

		if (indexData < data.size())
		{
			if (data.at(indexData) >= '0' && data.at(indexData) <= '9')
			{
				std::string num = "";
				float numberConverted;
				while (indexData < data.size() && (data.at(indexData) != ':' && data.at(indexData) != ' '))
				{
					num += data.at(indexData);
					indexData++;
				}
				numberConverted = stoi(num);
				numberConverted /= 900000;
				height[index] = numberConverted;
			}
		}
	}

	verticalNumbers[0].setString("0 M");
	verticalNumbers[1].setString("60 M");
	verticalNumbers[2].setString("120 M");
	verticalNumbers[3].setString("180 M");
	verticalNumbers[4].setString("240 M");
	verticalNumbers[5].setString("300 M");
	Header.setString("Increase of Covid-19 Cases");


	sf::RenderWindow window(sf::VideoMode(850, 700), "Line Chart with SFML in C++");

	sf::CircleShape bar1(3);
	sf::CircleShape bar2(3);
	sf::CircleShape bar3(3);
	sf::CircleShape bar4(3);
	sf::CircleShape bar5(3);
	sf::CircleShape bar6(3);
	sf::RectangleShape xLine(sf::Vector2f(1, 600));
	sf::RectangleShape yLine(sf::Vector2f(1, 334));
	sf::Vertex line1[] = { sf::Vertex(sf::Vector2f(148, 498)), sf::Vertex(sf::Vector2f(200 + 2, (490 + 2 - height[0]))) };
	sf::Vertex line2[] = { sf::Vertex(sf::Vector2f(200 + 3, (490 + 2 - height[0]))), sf::Vertex(sf::Vector2f(300 + 3, (490 + 2 - height[1]))) };
	sf::Vertex line3[] = { sf::Vertex(sf::Vector2f(300 + 3, (490 + 2 - height[1]))), sf::Vertex(sf::Vector2f(400 + 3, (490 + 2 - height[2]))) };
	sf::Vertex line4[] = { sf::Vertex(sf::Vector2f(400 + 3, (490 + 2 - height[2]))), sf::Vertex(sf::Vector2f(500 + 3, (490 + 2 - height[3]))) };
	sf::Vertex line5[] = { sf::Vertex(sf::Vector2f(500 + 3, (490 + 2 - height[3]))), sf::Vertex(sf::Vector2f(600 + 3, (490 + 2 - height[4]))) };
	sf::Vertex line6[] = { sf::Vertex(sf::Vector2f(600 + 3, (490 + 2 - height[4]))), sf::Vertex(sf::Vector2f(700 + 3, (490 + 2 - height[5]))) };


	Header.setPosition(250, 25);
	bar1.setPosition(200, (490 - height[0]));
	bar2.setPosition(300, (490 - height[1]));
	bar3.setPosition(400, (490 - height[2]));
	bar4.setPosition(500, (490 - height[3]));
	bar5.setPosition(600, (490 - height[4]));
	bar6.setPosition(700, (490 - height[5]));
	xLine.setPosition(150, 501);
	xLine.rotate(270);
	yLine.setPosition(150, 501);
	yLine.rotate(180);
	for (int index = 0; index < numOfElem; index++)
	{
		verticalNumbers[index].setPosition(100, 501 - 67 * index - 10); 
		Dates[index].setPosition((185 + index*100), (510 - height[0]));
	}


	Header.setFont(Font);
	Header.setFillColor(sf::Color::White);
	Header.setCharacterSize(28);
	bar1.setFillColor(sf::Color(100, 250, 50));
	bar2.setFillColor(sf::Color(100, 250, 50));
	bar3.setFillColor(sf::Color(100, 250, 50));
	bar4.setFillColor(sf::Color(100, 250, 50));
	bar5.setFillColor(sf::Color(100, 250, 50));
	bar6.setFillColor(sf::Color(100, 250, 50));
	xLine.setFillColor(sf::Color::White);
	yLine.setFillColor(sf::Color::White);
	for (int index = 0; index < numOfElem; index++)
	{
		Dates[index].setFont(Font);
		Dates[index].setFillColor(sf::Color::White);
		Dates[index].setCharacterSize(16);

		verticalNumbers[index].setFont(Font);
		verticalNumbers[index].setFillColor(sf::Color::White);
		verticalNumbers[index].setCharacterSize(16);
	}


	window.draw(line1, 3, sf::Lines);
	window.draw(line2, 3, sf::Lines);
	window.draw(line3, 3, sf::Lines);
	window.draw(line4, 3, sf::Lines);
	window.draw(line5, 3, sf::Lines);
	window.draw(line6, 3, sf::Lines);
	window.draw(Header);
	window.draw(bar1);
	window.draw(bar2);
	window.draw(bar3);
	window.draw(bar4);
	window.draw(bar5);
	window.draw(bar6);
	window.draw(xLine);
	window.draw(yLine);
	for (int index = 0; index < numOfElem; index++)
	{
		window.draw(Dates[index]);
		window.draw(verticalNumbers[index]);
	}


	std::cout << "Part 3 section 2:" << std::endl << std::endl;

	window.display();

	sf::Time timePerFrame = sf::seconds(1.0f / 60.0f);
	sf::Time timeSinceLastUpdate = sf::Time::Zero;

	while (window.isOpen())
	{
		sf::Event event;
		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
			{
				window.close();
				std::cout << "Closed!" << std::endl << std::endl;
			}
		}
	}
}

int main()
{
	std::string data;

	data = Read("res/Files/part1.txt");
	Part_1(data);

	data = Read("res/Files/part2.txt");
	Part_2(data);

	data = Read("res/Files/part3-1.txt");
	Part_3_1(data);

	data = Read("res/Files/part3-2.txt");
	Part_3_2(data);
}