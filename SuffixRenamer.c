#include <stdio.h>
#include <stdlib.h>
#include <io.h>

int main(void)
{
    char newname[100];

    //the structure to store files information
    struct _finddata_t fileSearcher;
    //tick
    long fHandle;

    if((fHandle = _findfirst("*.*", &fileSearcher)) == -1L)
    {
        printf("There is no file!\n");
    }
    else
    {
        do
        {
            fHandle++;
            printf( "File found: %s,File size：%d\n", fileSearcher.name, fileSearcher.size);
            sprintf(newname, "%s.mp3", fileSearcher.name);
            if (rename(fileSearcher.name, newname) == 0)
            {
                printf("old: %s; new: %s.\n", fileSearcher.name, newname);
            }
            else
            {
                perror("rename");
            }
        }
        while( _findnext(fHandle, &fileSearcher) == 0);
    }
    //close
    _findclose(fHandle);
    printf("Number of files：%d\n", fHandle);
    system("pause");

    return 0;
}
