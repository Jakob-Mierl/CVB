/**
 * Filename: main.c
 * Date: 03.04.2024
 * Author: Jakob Mierl and Andreas Mairhofer
 * Description:
 *   This program should implement the following bash command, via the c programming language.
 *   The command prints the lines between M>N from a certain .txt file, in this example it's fhs51232_a70charts.txt.
 *   head -n M a70charts.txt | tail +N
 *   - M --> Last line to be printed
 *   - N --> first line to be printed
*/

/**
 * Import documentation:
 *   <stdio.h>      --> Used for printing to stdout and stderr
 *   <stdlib.h>     --> Used for exit() functions and certain flags
 *   <getopt.h>     --> Used for handling flags set in argv
 */
#include <stdio.h>
#include <stdlib.h>
#include <getopt.h>
#include <string.h>



void printHelpInfo();
void printVersion();
int getFileLineCount(FILE *fp);
void printFormat(char *format, int line_num, char *line, int lineZero);




int main(int argc, char **argv) 
{
    FILE *fp;
    int startLine = 1, endLine = EOF, current_line = 1;
    int opt;
    char line[256];
    char *line_format = "R";

    static struct option long_options[] = {
        {"help", no_argument, 0, 'h'},
        {"version", no_argument, 0, 'v'},
        {0, 0, 0, 0}
    };
  
    while ((opt = getopt_long(argc, argv, "s:e:n:iq", long_options, NULL)) != -1) {
        switch (opt) {
            case 's':
                startLine = atoi(optarg);
                break;
            case 'e':
                endLine = atoi(optarg);
                break;
            case 'n':
                line_format = optarg;
                break;
            case 'i':
                printf("i");
                break;
            case 'q':
                printf("q");
                break;
            case 'h':
                printHelpInfo();
                return(0);
            case 'v':
                printVersion();
                return(0);
            default:
                fprintf(stderr, "Unknown option!\n");
                exit(EXIT_FAILURE);
        }
    }

    // The following lines handle the printing, they will likely have to be transfered to it's own function
    fp = fopen(argv[argc - 1], "r");

    if(fp == NULL)
    {
        fprintf(stderr, "No filename specified! Reading from command line\n");
        exit(EXIT_FAILURE);
    }

    if(endLine == EOF)
    {
        endLine = getFileLineCount(fp);
    }

    while (fgets(line, sizeof(line), fp) != NULL) 
    {
        if (current_line >= startLine && current_line <= endLine) 
        {
            if (line_format != NULL)
            {
                printFormat(line_format, current_line, line, startLine);
            }
            else
            {
                fprintf(stdout, "%s", line);
            }
        }
        
        current_line++;
        if (current_line > endLine)
            break;
    }

    fclose(fp);
    return 0;
}

int getFileLineCount(FILE *fp)
{
    char ch;
    int lines = 1;
    while(!feof(fp))
    {
        ch = fgetc(fp);
        if(ch == '\n')
        {
            lines++;
        }
    }
    rewind(fp);
    return lines;
}

void printFormat(char *format, int line_num, char *line, int lineZero)
{
    // temp array buffer to store format
    char formatted_line[20];

    if (strcmp(format, "R") == 0)
    {
        // snprintf formates and stores characters in the formatted_line array buffer
        snprintf(formatted_line, sizeof(formatted_line), "%10d ", line_num);
    }
    else if (strcmp(format, "0") == 0)
    {
        snprintf(formatted_line, sizeof(formatted_line), "%010d ", line_num);
    }
    else if (strcmp(format, "L") == 0)
    {
        snprintf(formatted_line, sizeof(formatted_line), "%d ", line_num);
    }
    else if (strcmp(format, "N") == 0)
    {
        snprintf(formatted_line, sizeof(formatted_line), "%d ", line_num - lineZero);
    }
    else
    {
        fprintf(stderr, "\nInvalid format!\n");
        exit(EXIT_FAILURE);
    }

    // print format and line
    fprintf(stdout, "%s%s", formatted_line, line);    
}

void printHelpInfo()
{
    fprintf(stdout, "Help information");
    fprintf(stdout, "\n-s n\t\tAngabe der ersten auszugebenen (n-te) Zeile\n\t\twenn keine Angabe, dann wird ab erster Zeile gelesen");
    fprintf(stdout, "\n\n-e n\t\tAngabe der letzte auszugebenen (n-te) Zeile\n\t\twenn keine Angabe, dann wird bis zur letzten Zeile gelesen");
    fprintf(stdout, "\n\n-n[format]\tAusgabe mit fuehrenden Zeilennummern\n\t\tuint\tBreite des Zeilennummernfelds\n\t\tR\trechtsbuendig\n\t\t0\trechtsbuendig mit fuehrenden Nullen\n\t\tL\tlinksbuendig\n\t\tN\tZeilennummer beginnt mit Null");
    fprintf(stdout, "\n\n-v\t\tProgramm gibt waehrend Prozessierung zustaetzliche Status- und Dateininformationen aus");
    fprintf(stdout, "\n\n-q\t\tProgramm gibt waehrend Prozessierung zustaetzliche Status- und Dateininformationen aus, ohne den\n\t\tInhalt der Datei auszugeben");
    fprintf(stdout, "\n\n--version\tVersionsinformation des Programms wird ausgegeben\n");
}

void printVersion()
{
    fprintf(stdout, "cvb Version 1.0\n");
}
