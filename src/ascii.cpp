#include "ascii.hpp"


namespace arc {

	std::string greyscale{ "@%#*+=-:. " }; // Default grayscale characters

	std::string imageToASCII(const sf::Image& image, int newWidth, int newHeight)
	{
		sf::Vector2u size = image.getSize();
		float scaleX = static_cast<float>(size.x) / newWidth;
		float scaleY = static_cast<float>(size.y) / newHeight;

		std::string asciiArt{};

		for (int y{ 0 }; y < newHeight; ++y)
		{
			for (int x{ 0 }; x < newWidth; ++x)
			{
				int startX = static_cast<int>(x * scaleX);
				int endX = static_cast<int>((x + 1) * scaleX);
				int startY = static_cast<int>(y * scaleY);
				int endY = static_cast<int>((y + 1) * scaleY);

				int averageColor{};//0

				for (int i = startX; i < endX; ++i)
				{
					for (int j = startY; j < endY; ++j)
					{
						sf::Color pixelColor = image.getPixel(i, j);
						averageColor += (pixelColor.r + pixelColor.g + pixelColor.b) / 3;
					}
				}
				averageColor /= (endX - startX) * (endY - startY);
				asciiArt += arc::greyscale[static_cast<int>(averageColor / 255.0 * (arc::greyscale.size() - 1))];
			}
			asciiArt += '\n';
		}

		return asciiArt;
	}



}

   
	




