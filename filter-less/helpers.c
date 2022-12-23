#include "helpers.h"
#include <math.h>

// Convert image to grayscale
void grayscale(int height, int width, RGBTRIPLE image[height][width])
{
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            int red = image[i][j].rgbtRed;
            int green = image[i][j].rgbtGreen;
            int blue = image[i][j].rgbtBlue;

            //Rounding Off The Average
            int avg = round(((float)red + (float)blue + (float)green) / 3);

            //Storing The New Value
            image[i][j].rgbtRed = avg;
            image[i][j].rgbtBlue = avg;
            image[i][j].rgbtGreen = avg;
        }
    }
    return;
}

// Convert image to sepia
void sepia(int height, int width, RGBTRIPLE image[height][width])
{
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            int red = image[i][j].rgbtRed;
            int blue = image[i][j].rgbtBlue;
            int green = image[i][j].rgbtGreen;

            // New sapia values
            int sepiaRed = round(0.393 * red + 0.769 * green + 0.189 * blue);

            if (sepiaRed > 255)
            {
                image[i][j].rgbtRed = 255;
            }
            else
            {
                image[i][j].rgbtRed = sepiaRed;
            }

            int sepiaBlue = round(0.272 * red + 0.534 * green + 0.131 * blue);

            if (sepiaBlue > 255)
            {
                image[i][j].rgbtBlue = 255;
            }
            else
            {
                image[i][j].rgbtBlue = sepiaBlue;
            }

            int sepiaGreen = round(0.349 * red + 0.686 * green + 0.168 * blue);

            if (sepiaGreen > 255)
            {
                image[i][j].rgbtGreen = 255;
            }
            else
            {
                image[i][j].rgbtGreen = sepiaGreen;
            }
        }
    }
}

// Reflect image horizontally
void reflect(int height, int width, RGBTRIPLE image[height][width])
{
    for (int i = 0; i < height; i++)
    {
        // Loop all columns
        for (int j = 0; j < width / 2; j++)
        {
            // Reflect each pixel
            RGBTRIPLE new = image[i][j];
            image[i][j] = image[i][width - (j + 1)];
            image[i][width - (j + 1)] = new;
        }
    }
    return;
}

// Blur image
void blur(int height, int width, RGBTRIPLE image[height][width])
{
    //create a temporary image to implement blurred algorithm on it.
    RGBTRIPLE temp[height][width];

    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            int sumRed, sumBlue, sumGreen;
            sumRed = sumBlue = sumGreen = 0;
            float counter = 0.00;

            //Get the neighbouring pexels
            for (int c = -1; c < 2; c++)
            {
                for (int r = -1; r < 2; r++)
                {
                    int currentX = i + c;
                    int currentY = j + r;
                    //check for valid neighbouring pexels
                    if (currentX < 0 || currentX > (height - 1) || currentY < 0 || currentY > (width - 1))
                    {
                        continue;
                    }
                    //Get the image value
                    sumRed += image[currentX][currentY].rgbtRed;
                    sumGreen += image[currentX][currentY].rgbtGreen;
                    sumBlue += image[currentX][currentY].rgbtBlue;
                    counter++;
                }
                //do the average of neigbhouring pexels
                temp[i][j].rgbtRed = round(sumRed / counter);
                temp[i][j].rgbtGreen = round(sumGreen / counter);
                temp[i][j].rgbtBlue = round(sumBlue / counter);
            }
        }
    }
    //copy the blur image to the original image
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            image[i][j].rgbtRed = temp[i][j].rgbtRed;
            image[i][j].rgbtGreen = temp[i][j].rgbtGreen;
            image[i][j].rgbtBlue = temp[i][j].rgbtBlue;
        }
    }
    return;
}
