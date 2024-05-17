#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

void count_characters(const char* filename) {
    FILE* file = fopen(filename, "r");
    if (file == NULL) {
        perror("Error opening file");
        return;
    }

    int character;
    int count = 0;
    while ((character = fgetc(file)) != EOF) {
        count++;
    }

    fclose(file);
    printf("字符数：%d\n", count);
}

void count_words(const char* filename) {
    FILE* file = fopen(filename, "r");
    if (file == NULL) {
        perror("Error opening file");
        return;
    }

    int character;
    int in_word = 0;
    int count = 0;
    while ((character = fgetc(file)) != EOF) {
        if (isspace(character) || character == ',') {
            if (in_word) {
                count++;
                in_word = 0;
            }
        }
        else {
            in_word = 1;
        }
    }
    if (in_word) {
        count++;
    }

    fclose(file);
    printf("单词数：%d\n", count);
}

int main(int argc, char* argv[]) {
    if (argc != 3) {
        fprintf(stderr, "Usage: %s [-c|-w] <input_file_name>\n", argv[0]);
        return 1;
    }

    if (strcmp(argv[1], "-c") == 0) {
        count_characters(argv[2]);
    }
    else if (strcmp(argv[1], "-w") == 0) {
        count_words(argv[2]);
    }
    else {
        fprintf(stderr, "Invalid parameter %s. Use -c for character count or -w for word count.\n", argv[1]);
        return 1;
    }

    return 0;
}
