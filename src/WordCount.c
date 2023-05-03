#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

#define MAX_FILE_NAME 512   // 最大文件名长度
#define MAX_WORD_LEN 512    // 最大单词长度

int main(int argc, char *argv[]) {
    int char_count = 0;     // 字符数统计变量
    int word_count = 0;     // 单词数统计变量
    char *filename;         // 文件名变量
    char *mode;             // 统计模式，-c表示字符数，-w表示单词数
    FILE *fp;               // 文件指针
    char c;                 // 当前字符
    int is_word = 0;        // 是否为单词的标志
    int word_len = 0;       // 当前单词的长度
    char word[MAX_WORD_LEN];// 当前单词的字符串

    // 处理命令行参数
    if (argc == 2) {
        mode = argv[1];
        filename = "input.txt";
    } else if (argc == 3) {
        mode = argv[1];
        filename = argv[2];
    } else {
        printf("Usage: WordCount [-c | -w] [input_file_name]\n");
        return 0;
    }

    // 打开文件
    fp = fopen("D:/Git/repository/WordCount/src/test.txt", "r");
    if (fp == NULL) {
        printf("Error: cannot open file '%s'\n", filename);
        return 0;
    }

    // 统计字符数或单词数
    while ((c = fgetc(fp)) != EOF) {
        char_count++;

        // 判断当前字符是否为单词分隔符
        if (c == ' ' || c == '\t' || c == '\n' || c == ',' || c == '.') {
            if (is_word) {
                is_word = 0;
                word[word_len] = '\0';
                word_len = 0;
                word_count++;
            }
        } else {
            is_word = 1;
            if (word_len < MAX_WORD_LEN) {
                word[word_len++] = c;
            }
        }
    }

    // 判断统计模式并输出结果
    if (strcmp(mode, "-c") == 0) {
        printf("字符数：%d\n", char_count);
    } else if (strcmp(mode, "-w") == 0) {
        printf("单词数：%d\n", word_count);
    } else {
        printf("Error: unknown mode '%s'\n", mode);
        return 0;
    }

    // 关闭文件
    fclose(fp);

    return 0;
}