#define _SVID_SOURCE
/* print files in current directory in reverse order */
#include <dirent.h>
#include <stdio.h>
#include <stdlib.h>



int
main(void)
{
    struct dirent **namelist;
    int n;

    n = scandir(".", &namelist, NULL, alphasort);
    if (n < 0)
        perror("scandir");
    else {
		int i=0;
        for(i=0; i<n; i++){
            printf("%s\n", namelist[i]->d_name);
            free(namelist[i]);
        }
        free(namelist);
    }
}
