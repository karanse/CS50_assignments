#include <cs50.h>
#include <ctype.h> // Include for isdigit function
#include <stdio.h>
#include <stdlib.h> // Include for atoi function

int main(void)
{
    int height; // Declare height outside the loop

    do
    {
        printf("Give an integer between 1 and 8 inclusive for the height\n");
        string input = get_string("Height: "); // Get input as string

        // Check if input is a valid integer
        bool validInput = true;

        if (input[0] == '\0')
        {
            validInput = false; // If the first character is the null terminator, input is empty
        }
        else
        {
            for (int i = 0; input[i] != '\0'; i++)
            {
                if (!isdigit(input[i]))
                {
                    validInput = false; // If any character is not a digit, input is invalid
                }
            }
        }

        if (validInput)
        {
            height = atoi(input); // Convert string to integer

            // Check if height is within range
            if (height < 1 || height > 8)
            {
                printf("Height must be between 1 and 8 inclusive.\n");
                height = 0; // Set height to 0 to continue loop
            }
        }
        else
        {
            // If input is not a valid integer, check if it's a negative number
            if (input[0] == '-')
            {
                printf("Height must be a positive integer.\n");
            }
            else
            {
                printf("Invalid input. Please enter a valid integer.\n");
            }
            height = 0; // Set height to 0 to continue loop
        }
    }
    while (height < 1 || height > 8);

    // Print an n-by-n grid of bricks
    for (int i = 0; i < height; i++)
    {
        // Print spaces before the first hash
        for (int j = 0; j < height - i - 1; j++)
        {
            printf(" ");
        }

        // Print the left side of the pyramid
        for (int j = 0; j <= i; j++)
        {
            printf("#");
        }

        // Print spaces between the two halves
        printf("  ");

        // Print the right side of the pyramid
        for (int j = 0; j <= i; j++)
        {
            printf("#");
        }

        // Move to the next line
        printf("\n");
    }

    return 0; // Indicate successful completion
}
