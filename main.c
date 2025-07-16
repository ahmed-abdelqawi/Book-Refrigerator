/*
    --- The Book Refrigerator. ---
    - This app is designed to help you mange your book collection by sorting, searching and finding any book you want in the list.

    Architected and Codded by: Fishy.
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

typedef struct
{
    char *title;
    char *writer;
    char *category;
    int year;
} Book;

bool books_input(Book set[], size_t bookNumber); // Take the "input.txt" file and store it in "set[]".
void store_books(Book set[], size_t bookNumber); // Store the final list in the "output.txt" file.
void display_books(Book set[]);                  // Display the first 10 books in the terminal "Just to make sure, lol".
void tFinder(Book set[]);                        // Finding books by title.

int main()
{
    const size_t maxNum = 1000;

    Book set[maxNum];

    books_input(set, maxNum);
    if (!books_input)
    {
        printf("Error! Books input failed.\n");
        return 1;
    }

    store_books(set, maxNum);
    display_books(set);

    // Memory cleaning up.
    for (size_t i = 0; i < 3; ++i)
    {
        free(set[i].title);
        free(set[i].writer);
        free(set[i].category);

        set[i].title = NULL;
        set[i].writer = NULL;
        set[i].category = NULL;
    }

    return 0;
}

bool books_input(Book set[], size_t bookNumber)
{
    FILE *file = fopen("input.txt", "r");
    if (file == NULL)
    {
        printf("Failed to locate the input file.\n");
        return false;
    }

    char lineBuffer[256];
    for (size_t i = 0; i < bookNumber; ++i)
    {
        set[i].title = malloc(100);
        set[i].writer = malloc(100);
        set[i].category = malloc(100);

        fgets(lineBuffer, sizeof(lineBuffer), file); // Title.
        sscanf(lineBuffer, "Title: %[^\n]", set[i].title);

        fgets(lineBuffer, sizeof(lineBuffer), file); // Writer.
        sscanf(lineBuffer, "Writer: %[^\n]", set[i].writer);

        fgets(lineBuffer, sizeof(lineBuffer), file); // Category.
        sscanf(lineBuffer, "Category: %[^\n]", set[i].category);

        fgets(lineBuffer, sizeof(lineBuffer), file); // Year.
        sscanf(lineBuffer, "Year: %d", &set[i].year);

        fgets(lineBuffer, sizeof(lineBuffer), file); // Skip possible blank line
    }

    fclose(file);
    return true;
}

void store_books(Book set[], size_t bookNumber)
{
    FILE *inFile = fopen("output.txt", "w");

    if (inFile == NULL)
    {
        printf("Failed to find the input file.");
        return;
    }

    for (size_t i = 0; i < bookNumber; ++i)
    {
        fprintf(inFile, "Title: %s\n", set[i].title);
        fprintf(inFile, "Writer: %s\n", set[i].writer);
        fprintf(inFile, "Category: %s\n", set[i].category);
        fprintf(inFile, "Year: %d\n", set[i].year);
        fprintf(inFile, "------------------------------------\n");
    }

    fclose(inFile);
}

void display_books(Book set[])
{
    for (size_t i = 0; i < 10; ++i)
    {
        printf("\n------------------------------------\n");
        printf("Title: %s\n", set[i].title);
        printf("Writer: %s\n", set[i].writer);
        printf("Category: %s\n", set[i].category);
        printf("Year: %d\n", set[i].year);
        printf("------------------------------------\n");
        printf("\n");
    }
}

void tFinder(Book set[])
{
}