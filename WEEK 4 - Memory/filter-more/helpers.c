#include "helpers.h"
#include "math.h"
void grayscale(int height, int width, RGBTRIPLE image[height][width])
{
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            float red = image[i][j].rgbtRed;
            float green = image[i][j].rgbtGreen;
            float blue = image[i][j].rgbtBlue;

            int average = round((red + green + blue) / 3);

            image[i][j].rgbtRed = image[i][j].rgbtGreen = image[i][j].rgbtBlue = average;
        }
    }
    return;
}

void reflect(int height, int width, RGBTRIPLE image[height][width])
{
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width / 2; j++)
        {
            RGBTRIPLE temp = image[i][j];
            image[i][j] = image[i][width - 1 - j];
            image[i][width - 1 - j] = temp;
        }
    }
    return;
}

void blur(int height, int width, RGBTRIPLE image[height][width])
{
    RGBTRIPLE temp[height][width];
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            temp[i][j] = image[i][j];
        }
    }

    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            int totalRed, totalGreen, totalBlue;
            totalRed = totalGreen = totalBlue = 0;
            float count = 0.00;

            for (int x = -1; x < 2; x++)
            {
                for (int y = -1; y < 2; y++)
                {
                    int targetX = i + x;
                    int targetY = j + y;

                    if (targetX < 0 || targetX > (height - 1) || targetY < 0 ||
                        targetY > (width - 1))
                    {
                        continue;
                    }

                    totalRed += image[targetX][targetY].rgbtRed;
                    totalGreen += image[targetX][targetY].rgbtGreen;
                    totalBlue += image[targetX][targetY].rgbtBlue;

                    count++;
                }

                temp[i][j].rgbtRed = round(totalRed / count);
                temp[i][j].rgbtGreen = round(totalGreen / count);
                temp[i][j].rgbtBlue = round(totalBlue / count);
            }
        }
    }
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
void edges(int height, int width, RGBTRIPLE image[height][width])
{
    RGBTRIPLE temp[height][width];
    int gx[3][3] = {{-1, 0, 1}, {-2, 0, 2}, {-1, 0, 1}};
    int gy[3][3] = {{-1, -2, -1}, {0, 0, 0}, {1, 2, 1}};

    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            int gxRed, gyRed, gxGreen, gyGreen, gxBlue, gyBlue;
            gxRed = gyRed = gxGreen = gyGreen = gxBlue = gyBlue = 0;
            for (int r = -1; r < 2; r++)
            {
                for (int c = -1; c < 2; c++)
                {
                    if (i + r < 0 || i + r > height - 1 || j + c < 0 || j + c > width - 1)
                        continue;

                    gxRed += image[i + r][j + c].rgbtRed * gx[r + 1][c + 1];
                    gyRed += image[i + r][j + c].rgbtRed * gy[r + 1][c + 1];
                    gxGreen += image[i + r][j + c].rgbtGreen * gx[r + 1][c + 1];
                    gyGreen += image[i + r][j + c].rgbtGreen * gy[r + 1][c + 1];
                    gxBlue += image[i + r][j + c].rgbtBlue * gx[r + 1][c + 1];
                    gyBlue += image[i + r][j + c].rgbtBlue * gy[r + 1][c + 1];
                }
            }
            int red = round(sqrt(gxRed * gxRed + gyRed * gyRed));
            int green = round(sqrt(gxGreen * gxGreen + gyGreen * gyGreen));
            int blue = round(sqrt(gxBlue * gxBlue + gyBlue * gyBlue));

            temp[i][j].rgbtRed = (red > 255) ? 255 : red;
            temp[i][j].rgbtGreen = (green > 255) ? 255 : green;
            temp[i][j].rgbtBlue = (blue > 255) ? 255 : blue;
        }
    }

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
