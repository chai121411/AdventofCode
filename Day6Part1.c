    #include <stdio.h>
    #include <stdlib.h>
    #include <string.h>

    int main()
    {
        int **arr = (int **)malloc(1000*sizeof(int*));
        int i, j;
        char buffer[40];
        FILE *fp;
        int directive;
        int LitCount = 0;

        for(i = 0; i < 1000; i++){
            arr[i] = (int *)malloc(1000*sizeof(int));
            for(j = 0; j < 1000; j++){
                arr[i][j] = 0;
            }
        }

        fp = fopen("txt0.txt", "r");
        while(fgets(buffer,40,fp) != NULL){
            char *ptr = buffer;
            char *comma;
            char* tempbuffer;
            char* pastcomma;
            char* pastwhitespace;
            char* pastsecondcomma;
            int Firstindex, Secondindex, Thirdindex, Fourthindex;
            int index1, index2, index3, index4;

            if(strstr(buffer,"turn on ")){
                directive = 0;
                ptr+=8;
            }
            else if(strstr(buffer,"toggle ")){
                directive = 1;
                ptr+=7;
            }
            else{
                directive = 2;
                ptr+=9;
            }

            comma = ptr;
            while(comma[0] != ','){
                comma++;
            }
            Firstindex = (int)(comma - ptr);
            i = 0;
            tempbuffer = (char*)malloc(Firstindex*sizeof(char)+1);
            while(i < Firstindex){
                tempbuffer[i] = ptr[i];
                i++;
            }
            tempbuffer[Firstindex] = '\0';
            index1 = atoi(tempbuffer);
            free(tempbuffer);

            comma++; /*Skip Comma*/
            pastcomma = comma;
            while(pastcomma[0] != ' '){
                pastcomma++;
            }
            Secondindex = (int)(pastcomma - comma);
            i = 0;
            tempbuffer = (char*)malloc(Secondindex*sizeof(char)+1);
            while(i < Secondindex){
                tempbuffer[i] = comma[i];
                i++;
            }
            tempbuffer[Secondindex] = '\0';
            index2 = atoi(tempbuffer);
            free(tempbuffer);

            pastcomma++; /*Skip whitespace*/
            pastcomma+= 8; /*Skip through */
            pastwhitespace = pastcomma;
            while(pastwhitespace[0] != ','){
                pastwhitespace++;
            }
            Thirdindex = (int)(pastwhitespace - pastcomma);
            i = 0;
            tempbuffer = (char*)malloc(Thirdindex*sizeof(char)+1);
            while(i < Thirdindex){
                tempbuffer[i] = pastcomma[i];
                i++;
            }
            tempbuffer[Thirdindex] = '\0';
            index3 = atoi(tempbuffer);
            free(tempbuffer);

            pastwhitespace++; /*Skip Second comma*/
            pastsecondcomma = pastwhitespace;
            while(pastsecondcomma[0] != '\0'){
                pastsecondcomma++;
            }
            Fourthindex = (int)(pastsecondcomma - pastwhitespace);
            i = 0;
            tempbuffer = (char*)malloc(Fourthindex*sizeof(char)+1);
            while(i < Fourthindex){
                tempbuffer[i] = pastwhitespace[i];
                i++;
            }
            tempbuffer[Fourthindex] = '\0';
            index4 = atoi(tempbuffer);
            free(tempbuffer);

            switch(directive){
            case 0:
                for(i = index1; i <= index3; i++){
                    for(j = index2; j <= index4; j++){
                        arr[i][j] = 1;
                    }
                }
                break;
            case 1:
                for(i = index1; i <= index3; i++){
                    for(j = index2; j <= index4; j++){
                        if(arr[i][j] == 0){
                            arr[i][j] = 1;
                        }else arr[i][j] = 0;
                    }
                }
                break;
            case 2:
                for(i = index1; i <= index3; i++){
                    for(j = index2; j <= index4; j++){
                        arr[i][j] = 0;
                    }
                }
                break;
            default:
                break;
            }
        }

        for(i = 0; i < 1000; i++){
            for(j = 0; j < 1000; j++){
                if(arr[i][j] == 1){
                    LitCount++;
                }
            }
        }
        printf("%d\n", LitCount);

        for(i = 0; i < 1000; i++){
            free(arr[i]);
        }
        free(arr);
        fclose(fp);
        return 0;
    }
