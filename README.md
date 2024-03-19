# Imgage to ASCII 
   Windows Command line Program to Convert Imgage into ASCII Art.

   
Downlaod Executable Here : https://github.com/ArcShahi/Image-to-ASCII/releases


## How to Use ?

1. Just type the path of image : `directory\folder\image.png` or Just drop an image on `SandBox.exe`. ( Before Opening it).
2. Prove `width` and `Height` of ASCII art. The more the Width and Heigh the more detailed the ASCII Art Will be.
3. You can customize the ASCII chars or use the Default One.
4. Give a output File name ( prefer `.txt` File ) : `test.txt`
5. Ouput file will be thrown in the same Directory as the Original Image.


## Example 

### Before

![image](https://github.com/ArcShahi/Image-to-ASCII/assets/90377780/359953e5-0423-4ced-acac-1d5ac0166108)


### After

![image](https://github.com/ArcShahi/Image-to-ASCII/assets/90377780/53a7281e-53cf-4792-a39b-c0ecfdfa2e2b)


>[!note]
>📕
>** Open the Output file via Notepad ( Recommended ) in Fullscreen and Dont' Forget to Zoom out : `ctrl and - (minus)`**


----
----
----



# Documentation 

Image to ASCII

First of all we need to Select a set of ASCII chars which will be mapped to the Pixels of the image.

It’s a density / greyscale string

`std::string greyscale{ "@%#*+=-:. " };`

It’s a set of chars from darkest to Lightest.



Image:

![image](https://github.com/ArcShahi/Image-to-ASCII/assets/90377780/661e7628-388b-4a3d-9cac-eba31b41a417)



Every Pixel of an Image has an RGB value : they are stored as Numbers uint ranging from ( 0-255).

If we wanna get a brightness value of a pixel , the higher the RGB value the higher the brightness.    Brightness of individual pixel : R + G + B / 3

It will give the greyscale value of the pixel. If the brightness is 255 we will choose the darker / Denser character from the ASCII string.  

An image of Dimension 50 x 50 in Pixels  has 2500 pixels ( 0-2499 ). 

How does the program work  ?

Load the Image
The function takes in an Image and new  Width and new Height .

`std::string imageToASCII(const sf::Image& image, int newWidth, int newHeight) 
{ // ------ }`





It scales it down for Further processing.
It calculates the Scale of the Image.

```cpp
float scaleX = static_cast<float>(size.x) / newWidth;
float scaleY = static_cast<float>(size.y) / newHeight;
```




Now we write an Algorithm to Walk through and look at the grayscale brightness of every single pixel

```cpp


   for (int y{ 0 }; y < newHeight; ++y)
        {
            for (int x{ 0 }; x < newWidth; ++x)
            {
                int startX = static_cast<int>(x * scaleX);
                int endX = static_cast<int>((x + 1) * scaleX);
                int startY = static_cast<int>(y * scaleY);
                int endY = static_cast<int>((y + 1) * scaleY);
```
.

The Above snippet is a Part of Algorithm , which will process block of pixels, 



The pixels of the New  scaled version of the image, will be divided into various blocks then it will be grayscale.   





```cpp
    int averageColor{};//0


for (int i = startX; i < endX; ++i)
{
    for (int j = startY; j < endY; ++j)
    {
        sf::Color pixelColor = image.getPixel(i, j);
        averageColor += (pixelColor.r + pixelColor.g + pixelColor.b) / 3;
    }
}
```



The above loop is for iterating every pixel of the image within the Block of Pixels, The iteration will happen from Top to Bottom and right to Left. Something like this

 `sf::Color pixelColor = image.getPixel(i, j);`



0  5

1  6

2  7

3  8

4  9


The entire block of pixels will be greyscale and the average color will be accumulated :

 `averageColor += (pixelColor.r + pixelColor.g + pixelColor.b) / 3`;

and average brightness intensity of the block will be calculated: 

 `averageColor /= (endX - startX) * (endY - startY);`



![image](https://github.com/ArcShahi/Image-to-ASCII/assets/90377780/90c2ee1a-8a4d-4a52-8937-0acaa4eb4d03)






Then finally , The average brightness intensity will be mapped to the ASCII density string and will be appended to the string .

`asciiArt += arc::greyscale[static_cast<int>(averageColor / 255.0 * (arc::greyscale.size() - 1))];`



The process continues until all rows and columns of the output ASCII art have been processed, generating the complete ASCII art representation of the image.




