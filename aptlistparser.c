//APT List Parser
//TXT to SH converter
//by Pedro Adelino
//Nara Logic 2020
//www.bypedro.eu

#include <stdio.h>
#include <string.h>
#include "naralogic.h"

#define MAXCHAR 1000

//const
char *app_version = "0.2";

int main()
{
    colorprint("APT List Parser v", "blue");
    colorprint(app_version, "blue");
    colorprint("\n", "blue");
    colorprint("TXT to SH converter.\n", "blue");
	colorprint("By Pedro Adelino.\n", "blue");
    colorprint("www.bypedro.eu\n", "blue");
    FILE *file;
    FILE *file2;
    int nrapps = 0;
    //char nrappsc[1000];
    char c;  // To store a character read from file
    char *found; 
    char line;
    char str[MAXCHAR];
    if((file = fopen("aptlist.txt","r"))!=NULL)
            {
                // file exists
                // Get number of apps
                for (c = getc(file); c != EOF; c = getc(file)){ 
                    if (c == '\n') // Increment count if this character is newline 
                        nrapps = nrapps + 1; 
                }
                colorprint("Number of apps : ", "yellow");
                //nrappsc = '0' + nrapps;
                //nrappsc[] = {'0' + nrapps, '\0'};
                //nrappsc = nrapps
                colorprinti(nrapps, "yellow");
                colorprint("\n", "yellow");
                fclose(file);
                // Read lines
                colorprint("Saving Restore Script...\n", "yellow");
                file = fopen("aptlist.txt","r");
                file2 = fopen("aptrestore.sh","w");
                fprintf(file2, "#!/bin/bash\n");
                fprintf(file2, "echo %cAPT Restore Script v0.2%c\n", 34, 34);
                fprintf(file2, "echo %cwww.bypedro.eu%c\n", 34, 34);
                fprintf(file2, "apt update\n");
                fprintf(file2, "apt upgrade\n");
                fprintf(file2, "apt clean\n");
                fprintf(file2, "echo %cInstalling packages with APT...%c\n", 34, 34);
                while (fgets(str, sizeof str, file) != NULL){
                    found = strtok(str,"/");
                    if( found==NULL)
                    {
                        printf("\t'%s'\n",str);
                        puts("\tNo separators found");
                        return(1);
                    }
                    while(found)
                    {
                    //printf("\t'%s'\n",found);
                    found = strtok(NULL,"/");
                    }
                    //printf("%s", str);
                    fprintf(file2, "apt install %s\n", str);
                }
                fprintf(file2, "echo %cAll done. Have fun!%c\n", 34, 34);
                fclose(file);
                fclose(file2);
                colorprint("Please run : ./aptrestore.sh\n", "green");
                colorprint("All done. Have fun!\n", "green");
            }
            else
            {
                colorprint("File 'aptlist.txt' not found.\n", "red");
            }
    return(0);
}