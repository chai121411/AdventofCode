#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    int niceCount = 0;
    char buffer[40];
    char *twice;
    char *ptr;
    FILE* fp = fopen("file1.txt","r");

    while(fgets(buffer, 40, fp) != NULL){
        char *temp = buffer;
        int flag = 0;
        int flag2 = 0;
        char pair[3];
        char triplet[4];
        twice = buffer;
        twice += 2;
        pair[2] = '\0';
        while((temp - buffer) != (int)strlen(buffer)){
            pair[0] = temp[0];
            pair[1] = temp[1];
            if(strstr(twice,pair)){
                flag++;
            }
            twice += 1;
            temp++;
        }

        if(flag == 0){
            continue;
        }

        temp = buffer;
        triplet[3] = '\0';
        while((temp - buffer) != (int)strlen(buffer)){

            ptr = buffer;
            triplet[0] = temp[0];
            triplet[2] = temp[2];
            if(triplet[0] == triplet[2]){
                flag2++;
            }
            temp++;
        }

        if(flag2 == 0){
            continue;
        }

        niceCount++;
    }

    printf("%d\n", niceCount);

    fclose(fp);
    return 0;
}
