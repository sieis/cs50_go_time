#include <stdio.h>
#include <cs50.h>
#include <string.h>
#include <math.h>

int num_letters(string s);
int num_words(string s);
int num_sentences(string s);

int main(void)
{
    // Get the text
    string read = get_string("Text: ");

    // put text into counter functions
    float l = num_letters(read);
    float w = num_words(read);
    float s  = num_sentences(read);
    // average letter per 100 words
    float L = l * 100 / w;
    printf("L: %f\n", L);
    // average sentences per 100 words
    float S = s * 100 / w;
    printf("S: %f\n", S);

    // Coleman-Liau index
    float i = 0.0588 * L - 0.296 * S - 15.8;
    int index = (int) round(i);
    printf("i: %f\n", i);
    printf("index : %i\n", index);


    printf("Number of letters: %f\n", l);
    printf("Number of words: %f\n", w);
    printf("Number of sentences: %f\n", s);

    if (index <1)
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

// string letter counter function
int num_letters(string s)
{
    int count = 0;
    for(int i = 0, n = strlen(s); i < n; i++)
    {
        // iterate over every char and test if it's a letter
        if((int) s[i] >64 && (int) s[i] < 123)
        count++;
    }
    return count;
}

int num_words(string s)
{
    int count = 1;
    for (int i = 0, n = strlen(s); i < n; i++)
    {
        if ((int) s[i] == 32)
        {
            count++;
        }
    }
    return count;
}

int num_sentences(string s)
{
    int count = 0;
    for (int i = 0, n = strlen(s); i < n; i++)
    {
        // checking array value without explicitly casting numeric value...i think
        if (s[i] == 33 || s[i] == 46 || s[i] == 63)
        {
            count++;
        }
    }
    return count;
}
