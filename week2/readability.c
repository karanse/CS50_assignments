#include <cs50.h>
#include <ctype.h>
#include <math.h>
#include <stdio.h>
#include <string.h>

int count_letters(string text);
int count_words(string text);
int count_sentences(string text);

int main(void)
{
    // Prompt the user for some text
    string user_text = get_string("Text: ");

    // Compute the Coleman-Liau index
    int letters = count_letters(user_text);
    int words = count_words(user_text);
    int sentences = count_sentences(user_text);

    int index = (int) round(0.0588 * ((float) letters / words * 100) -
                            0.296 * ((float) sentences / words * 100) - 15.8);

    // Print the grade level

    if (index < 1)
    {
        printf("Before Grade 1\n");
    }
    else if (index > 16)
    {
        printf("Grade 16+\n");
    }
    else
    {
        printf("Grade %i\n", index);
    }
}

int count_letters(string text)
{
    // Count the number of letters, in the text
    int letters = 0;

    for (int i = 0, n = strlen(text); i < n; i++)
    {
        if (isalpha(text[i]))
        {
            letters++;
        }
    }
    return letters;
}

int count_words(string text)
{
    // count the number of words in the text
    int words = 0;

    for (int i = 1, n = strlen(text); i < n; i++)
    {
        if (isblank(text[i - 1]) == false && isblank(text[i]))
        {
            words++;
        }
    }
    if (isblank(text[strlen(text) - 1]) == false)
    {
        words++;
    }

    return words;
}

int count_sentences(string text)
{
    // Count the number of sentences in the text
    int sentences = 0;
    for (int i = 0, n = strlen(text); i < n; i++)
    {
        if (text[i] == '.' || text[i] == '!' || text[i] == '?')
        {
            sentences++;
        }
    }
    return sentences;
}
