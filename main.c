/**
 * Filename: main.c
 * Date: 03.04.2024
 * Author: Jakob Mierl and Andreas Mairhofer
 * Description:
 *   This program should implement the following bash command, via the c programming language.
 *   The command prints the lines between M>N from a certain .txt file, in this example it's fhs51232_a70charts.txt.
 *   head -n M fhs51232_a70charts.txt | tail +N
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

/* Flag set by ‘--verbose’. */
static int verbose_flag;

// --help for informations
void printHelpInfo();

// --version
void printVersion();


int main(int argc, char **argv) {
    int c;

    while (1) {
        static struct option long_options[] = {
                /* These options set a flag. */
                {"verbose", no_argument,       &verbose_flag, 1},
                {"brief",   no_argument,       &verbose_flag, 0},
                /* These options don’t set a flag.
                   We distinguish them by their indices. */
                {"add",     no_argument,       0,             'a'},
                {"append",  no_argument,       0,             'b'},
                {"delete",  required_argument, 0,             'd'},
                {"create",  required_argument, 0,             'c'},
                {"file",    required_argument, 0,             'f'},
                {0, 0,                         0,             0}
        };
        /* getopt_long stores the option index here. */
        int option_index = 0;

        c = getopt_long(argc, argv, "abc:d:f:", long_options, &option_index);

        /* Detect the end of the options. */
        if (c == -1) {
            break;
        }

        switch (c) {
            case 0:
                /* If this option set a flag, do nothing else now. */
                if (long_options[option_index].flag != 0) {
                    break;
                }
                printf("option %s", long_options[option_index].name);
                if (optarg) {
                    printf(" with arg %s", optarg);
                }
                printf("\n");
                break;

            case 'a':
                puts("option -a\n");
                break;

            case 'b':
                puts("option -b\n");
                break;

            case 'c':
                printf("option -c with value `%s'\n", optarg);
                break;

            case 'd':
                printf("option -d with value `%s'\n", optarg);
                break;

            case 'f':
                printf("option -f with value `%s'\n", optarg);
                break;

            case '?':
                /* getopt_long already printed an error message. */
                break;

            default:
                abort();
        }
    }

    /* Instead of reporting ‘--verbose’
       and ‘--brief’ as they are encountered,
       we report the final status resulting from them. */
    if (verbose_flag) {
        puts("verbose flag is set");
    }

    /* Print any remaining command line arguments (not options). */
    if (optind < argc) {
        printf("non-option ARGV-elements: ");
        while (optind < argc) {
            printf("%s ", argv[optind++]);
        }
        putchar('\n');
    }

    exit(0);
}

void printHelpInfo()
{
    printf("Help information");
    printf("\n-s n\t\tAngabe der ersten auszugebenen (n-te) Zeile\n\t\twenn keine Angabe, dann wird ab erster Zeile gelesen");
    printf("\n\n-e n\t\tAngabe der letzte auszugebenen (n-te) Zeile\n\t\twenn keine Angabe, dann wird bis zur letzten Zeile gelesen");
    printf("\n\n-n[format]\tAusgabe mit fuehrenden Zeilennummern\n\t\tuint\tBreite des Zeilennummernfelds\n\t\tR\trechtsbuendig\n\t\t0\trechtsbuendig mit fuehrenden Nullen\n\t\tL\tlinksbuendig\n\t\tN\tZeilennummer beginnt mit Null");
    printf("\n\n-v\t\tProgramm gibt waehrend Prozessierung zustaetzliche Status- und Dateininformationen aus");
    printf("\n\n-q\t\tProgramm gibt waehrend Prozessierung zustaetzliche Status- und Dateininformationen aus, ohne den\n\t\tInhalt der Datei auszugeben");
    printf("\n\n--version\tVersionsinformation des Programms wird ausgegeben\n");
}

void printVersion()
{
    printf("\ncvb Version 1.0");
}
