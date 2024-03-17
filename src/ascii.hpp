#ifndef ASCII_HPP
#define ASCII_HPP

#include <SFML/Graphics.hpp>
#include <iostream>
#include <fstream>
#include <string>

namespace arc
{

	extern std::string greyscale;

	std::string imageToASCII(const sf::Image& image, int newWidth, int newHeight);


}
#endif // !ASCII_HPP

