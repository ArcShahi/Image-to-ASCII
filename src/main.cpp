#include "ascii.hpp"




int main(int argc, char* argv[])
{

	std::string imagePath{};
	int newWidth{};
	int newHeight{};
	std::string customChars{};

	if (argc >= 2)
	{
		imagePath = argv[1];
	}
	else
	{
		std::cout << "Enter the path to the image file: ";
		std::getline(std::cin, imagePath);
	}

	sf::Image image{};

	if (!image.loadFromFile(imagePath))
	{
		std::cerr << "Failed to load image!" << std::endl;
		return 1;
	}

	if (argc >= 5)
	{
		newWidth = std::stoi(argv[2]);
		newHeight = std::stoi(argv[3]);
	}
	else
	{
		std::cout << "Enter the width of the ASCII art: ";
		std::cin >> newWidth;
		std::cout << "Enter the height of the ASCII art: ";
		std::cin >> newHeight;
	}

	std::cout << "Wanna use default characters for ASCII art? (Y/N): ";
	char choice;
	std::cin >> choice;

	if (choice == 'N' || choice == 'n')
	{
		std::cout << "Enter custom characters for ASCII art: ";
		std::cin.ignore(); // Clear newline character
		std::getline(std::cin, customChars);
		arc::greyscale = customChars;
	}

	std::string asciiArt = arc::imageToASCII(image, newWidth, newHeight);

	std::string outputPath{};
	if (argc >= 6)
	{
		outputPath = argv[5];
	}
	else
	{
		std::cin.ignore(); // Ignore the newline character left in the buffer
		std::cout << "Enter the path for the output text file: ";
		std::getline(std::cin, outputPath);
	}

	std::ofstream outputFile(outputPath);
	if (outputFile.is_open())
	{
		outputFile << asciiArt;
		outputFile.close();
		std::cout << "ASCII art saved to " << outputPath << std::endl;
	}
	else
	{
		std::cerr << "Failed to open output file!" << std::endl;
		return 1;
	}

	return 0;
}
