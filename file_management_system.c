#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void create_file(char *filename)
{
    FILE *fp = fopen(filename, "w");
    if (fp == NULL)
    {
        printf("Unable to create file.\n");
        return;
    }
    printf("File created successfully.\n");
    fclose(fp);
}

void delete_file(char *filename)
{
    if (remove(filename) == 0)
    {
        printf("File deleted successfully.\n");
    }
    else
    {
        printf("Unable to delete file.\n");
    }
}

void modify_file(char *filename)
{
    int choice;
    printf("Choose :\n1.Overwrite the existing file to write new content\n2.Append new content to the existing file\n");
    scanf("%d", &choice);
    if (choice == 1)
    {
        FILE *fp = fopen(filename, "w");
        if (fp == NULL)
        {
            printf("Unable to open file.\n");
            return;
        }
        char new_content[100];
        printf("Enter new content: ");
        scanf(" %[^\n]", new_content);
        fprintf(fp, "%s", new_content);
        fclose(fp);
        printf("File modified successfully.\n");
    }
    else
    {
        FILE *fp = fopen(filename, "r+");
        if (fp == NULL)
        {
            printf("Unable to open file.\n");
            return;
        }
        fseek(fp, 0, SEEK_END);
        char new_content[100];
        printf("Enter new content: ");
        scanf(" %[^\n]", new_content);
        fprintf(fp, "%s", new_content);
        fclose(fp);
        printf("File modified successfully.\n");
    }
}

int main()
{
    int choice;
    char filename[100];

    printf("File Management System\n");
    printf("======================\n");

    while (1)
    {
        printf("\n1. Create file\n");
        printf("2. Delete file\n");
        printf("3. Modify file\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            printf("Enter filename: ");
            scanf("%s", filename);
            create_file(filename);
            break;
        case 2:
            printf("Enter filename: ");
            scanf("%s", filename);
            delete_file(filename);
            break;
        case 3:
            printf("Enter filename: ");
            scanf("%s", filename);
            modify_file(filename);
            break;
        case 4:
            printf("Exiting...\n");
            exit(0);
        default:
            printf("Invalid choice. Please try again.\n");
        }
    }
}