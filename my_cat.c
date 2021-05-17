#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int count_file_line(FILE *fp);
int n_h_t_option_print_file(FILE *fp, int n_option, int line_number, int h_option, int start_line, int t_option, int end_line, int count_line);

int main(int argc, char *argv[]) {
    FILE *fp;
    int i;
    int count_line[10000];
    int n_option, line_number = 0;
    int h_option, start_line = 0;
    int t_option, end_line = 0;
    int option_count = 0;

    for (i = 1; i < argc; i++) {
        if (argv[i][0] == '-') {
            if (argv[i][1] != 'n' && argv[i][1] != 'h' && argv[i][1] != 't') {
                fprintf(stderr, " %s: 無効なオプション -- '%c'\n 有効なオプションは n, h, t の３文字です\n", argv[0], argv[i][1]);
                exit(1);
            }
        }
    }

    for (i = 1; i < argc; i++) {
        if (argv[i][0] == '-') {
            option_count++;
        }
    }

    n_option = 0;
    for (i = 1; i < argc; i++) {
        if (strcmp(argv[i], "-n") == 0) {
            n_option = 1;
            break;
        }
    }

    h_option = 0;
    for (i = 1; i < argc; i++) {
        if (strncmp(argv[i], "-h", 2) == 0) {
            h_option = 1;
            start_line = atoi(argv[i] + 2);
            if (start_line == 0) {
                fprintf(stderr, " %s: %s: -h の後ろに出力開始行が指定されていない、または、出力開始行が 0 になっています\n", argv[0], argv[i]);
                exit(1);
            }
            break;
        }
    }

    t_option = 0;
    for (i = 1; i < argc; i++) {
        if (strncmp(argv[i], "-t", 2) == 0) {
            t_option = 1;
            end_line = atoi(argv[i] + 2);
            if (end_line == 0) {
                fprintf(stderr," %s: %s: -t の後ろに出力開始行が指定されていない、または、出力終了行が 0 になっています\n", argv[0], argv[i]);
                exit(1);
            }
            break;
        }
    }

    if (option_count == argc - 1) {
        if (h_option == 1 && t_option == 1) {
            if (start_line > end_line) {
                fprintf(stderr,
                        " %s: %s: 出力開始行の値に出力終了行より大きい値が指定されています。\n", argv[0], argv[i]);
                exit(1);
            }
        }
        line_number = n_h_t_option_print_file(stdin, n_option, line_number, h_option, start_line, t_option, end_line, 1);
    }

    for (i = 1; i < argc; i++) {
        if (argv[i][0] != '-') {
            fp = fopen(argv[i], "r");
            if (fp == NULL) {
                fprintf(stderr, " %s: %s: そのようなファイルやディレクトリはありません\n", argv[0], argv[i]);
                exit(1);
            }
            count_line[i] = count_file_line(fp);

            fclose(fp);
            fp = fopen(argv[i], "r");

            if (n_option == 1 && h_option == 1 && t_option == 1) {
                if (start_line > count_line[i]) {
                    fprintf(stderr, " %s: %s: %sは%d行未満であるため%d行目からの出力はできません\n", argv[0], argv[i], argv[i], start_line, start_line);
                    exit(1);
                } else if (end_line > count_line[i]) {
                    fprintf(stderr," %s: %s: %sは%d行未満であるため%d行目までの出力はできません\n",  argv[0], argv[i], argv[i], end_line, end_line);
                    exit(1);
                } else if (start_line > end_line) {
                    fprintf(stderr," %s: %s: 出力開始行の値に出力終了行より大きい値が指定されています。\n", argv[0], argv[i]);
                    exit(1);
                }
                line_number = n_h_t_option_print_file( fp, n_option, line_number, h_option, start_line, t_option, end_line, count_line[i]);
            }

            if (n_option == 1 && h_option == 1 && t_option == 0) {
                if (start_line > count_line[i]) {
                    fprintf(stderr, " %s: %s: %sは%d行未満であるため%d行目からの出力はできません\n", argv[0], argv[i], argv[i], start_line, start_line);
                    exit(1);
                }
                line_number = n_h_t_option_print_file(fp, n_option, line_number, h_option, start_line, t_option, end_line, count_line[i]);
            }

            if (n_option == 1 && h_option == 0 && t_option == 1) {
                if (end_line > count_line[i]) {
                    fprintf(stderr, " %s: %s: %sは%d行未満であるため%d行目までの出力はできません\n", argv[0], argv[i], argv[i], end_line, end_line);
                    exit(1);
                }
                line_number = n_h_t_option_print_file(fp, n_option, line_number, h_option, start_line, t_option, end_line, count_line[i]);
            }

            if (n_option == 0 && h_option == 1 && t_option == 1) {
                if (start_line > count_line[i]) {
                    fprintf(stderr," %s: %s: %sは%d行未満であるため%d行目からの出力はできません\n", argv[0], argv[i], argv[i], start_line, start_line);
                    exit(1);
                } else if (end_line > count_line[i]) {
                    fprintf(stderr," %s: %s: %sは%d行未満であるため%d行目までの出力はできません\n", argv[0], argv[i], argv[i], end_line, end_line);
                    exit(1);
                } else if (start_line > end_line) {
                    fprintf(stderr," %s: %s: 出力開始行の値に出力終了行より大きい値が指定されています。\n", argv[0], argv[i]);
                    exit(1);
                }
                line_number = n_h_t_option_print_file(fp, n_option, line_number, h_option, start_line, t_option, end_line, count_line[i]);
            }

            if (n_option == 0 && h_option == 1 && t_option == 0) {
                if (h_option == 1 && start_line > count_line[i]) {
                    fprintf(stderr, "%s: %s: %sは%d行未満であるため%d行目からの出力はできません\n", argv[0], argv[i], argv[i], start_line, start_line);
                    exit(1);
                }
                line_number = n_h_t_option_print_file(fp, n_option, line_number, h_option, start_line, t_option, end_line, count_line[i]);
            }

            if (n_option == 1 && h_option == 0 && t_option == 0) {
                line_number = n_h_t_option_print_file(fp, n_option, line_number, h_option, start_line, t_option, end_line, count_line[i]);
            }

            if (n_option == 0 && h_option == 0 && t_option == 1) {
                if (end_line > count_line[i]) {
                    fprintf(stderr," %s: %s: %sは%d行未満であるため%d行目までの出力はできません\n", argv[0], argv[i], argv[i], end_line, end_line);
                    exit(1);
                }
                line_number = n_h_t_option_print_file(fp, n_option, line_number, h_option, start_line, t_option, end_line, count_line[i]);
            }

            if (n_option == 0 && h_option == 0 && t_option == 0) {
                line_number = n_h_t_option_print_file(fp, n_option, line_number, h_option, start_line, t_option, end_line, count_line[i]);
            }

            fclose(fp);
        }
    }

    return 0;
}

int count_file_line(FILE *fp) {
    int c;
    int lineCount = 0;

    c = getc(fp);
    while (c != EOF) {
        if (c == 10) {
            c = getc(fp);
            lineCount++;
        }
        c = getc(fp);
    }
    return lineCount;
}

int n_h_t_option_print_file(FILE *fp, int n_option, int line_number, int h_option, int start_line, int t_option, int end_line, int count_line) {
    int h = 1, t = 0;
    int c = 0;

    if (h_option == 1) {
        c = getc(fp);
        while (h != start_line) {
            if (c == 10) {
                h++;
                t++;
            }
            c = getc(fp);
            if (c == EOF) {
                return line_number;
            }
        }
    }

    if (n_option == 1 && t_option == 0) {
        if (count_line == 0) {
            return line_number;
        }

        line_number++;
        printf("%6d  ", line_number);

        if (h_option == 1) {
            putc(c, stdout);
        }
        c = getc(fp);
        while (c != EOF) {
            putc(c, stdout);
            if (c == 10) {
                c = getc(fp);
                if (c != EOF) {
                    line_number++;
                    printf("%6d  ", line_number);
                    putc(c, stdout);
                }
            }
            c = getc(fp);
        }
        return line_number;
    }

    if (n_option == 0 && h_option == 1 && t_option == 0) {
        while (c != EOF) {
            putc(c, stdout);
            c = getc(fp);
        }
    }

    if (n_option == 1 && t_option == 1) {
        if (count_line == 0) {
            return line_number;
        }

        line_number++;
        printf("%6d  ", line_number);

        if (h_option == 1) {
            putc(c, stdout);
        }

        c = getc(fp);
        while (t != end_line) {
            if (t < end_line) {
                putc(c, stdout);
            }
            if (c == 10) {
                c = getc(fp);
                if (c != EOF) {
                    t++;
                    if (t < end_line) {
                        line_number++;
                        printf("%6d  ", line_number);
                        putc(c, stdout);
                    }
                }
            }
            c = getc(fp);
            if (c == EOF) {
                break;
            }
        }
    }

    if (n_option == 0 && t_option == 1) {
        while (t != end_line && c != EOF) {
            if (c == 10) {
                t++;
            }
            putc(c, stdout);
            c = getc(fp);
        }
    }

    if (n_option == 0 && h_option == 0 && t_option == 0) {
        c = getc(fp);
        while (c != EOF) {
            putc(c, stdout);
            c = getc(fp);
        }
    }
    return line_number;
}
