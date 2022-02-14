#include<stdio.h>
#include<errno.h>
#include<stdlib.h>
#include<unistd.h>
#include<string.h>
#include<ctype.h>
#include<sys/utsname.h>
#include<libgen.h>
#include<sys/sysinfo.h>

//Run the program with a parameter as a custom message

void printSomething(FILE *arg)
{
}

void distro();

void model();

void packages();

int main (int argc, char *argv[])
{
    system("clear");
    printf("\n\t\033[1;32m    \n");
    char *user = getenv("USER");
    char *stringg = getenv("SHELL");
    char *shell = basename(stringg);
    printf("\t\033[1;31musr\t\033[0m%s\n", user);
    printf("\t\033[1;32mhost\t\033[0m");
    model();
    printf("\t\033[1;37mpkgs\t\033[0m");
    packages();
    printf("\t\033[1;33mshell\033[0m\t%s\n", shell);
    printf("\t\033[1;34mdistro\033[0m\t");
    distro();
    getchar();
    return 0;
}

void packages()
{
    FILE* packages = popen("xbps-query -l | wc -l", "r");


    int c;
    while (1)
    {
        c = fgetc(packages);
        if (feof(packages)) break;
        printf("%c", c);
    }

    fclose(packages);
}

void model()
{
    FILE* model = fopen("/sys/devices/virtual/dmi/id/product_name", "r");

    int c;
    while (1)
    {
        c = fgetc(model);
        if (feof(model)) break;
        printf("%c", c);
    }

    fclose(model);

}

void distro()
{
    int ch;
    char *distribution[70];
    int lol;
    FILE* distro = popen("lsb_release -sd", "r");
    while( (ch = fgetc(distro)) != EOF )
    {
        if ( isalpha(ch) )
        {
            lol = 1;
            putchar(ch);
        } else
        {
            if(lol)
            {
                putchar(' ');
                lol = 0;
            }
        }
    }
    pclose(distro);
    printf("\n");
}
/*
  color = {
    'white':    "\033[1;37m",
    'yellow':   "\033[1;33m",
    'green':    "\033[1;32m",
    'blue':     "\033[1;34m",
    'cyan':     "\033[1;36m",
    'red':      "\033[1;31m",
    'magenta':  "\033[1;35m",
    'black':    "\033[1;30m",
    'darkwhite':  "\033[0;37m",
    'darkyellow': "\033[0;33m",
    'darkgreen':  "\033[0;32m",
    'darkblue':   "\033[0;34m",
    'darkcyan':   "\033[0;36m",
    'darkred':    "\033[0;31m",
    'darkmagenta':"\033[0;35m",
    'darkblack':  "\033[0;30m",
    'off':        "\033[0;0m"
}
*/
