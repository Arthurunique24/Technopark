#include <stdio.h>
#include <string.h>

void countLines(FILE *file){
    char s[256];
    unsigned int countLines = 0;
    while (fgets(s, 100, file)) {
        //printf("%s", s);
        countLines++;
    }
    printf("\nCount of lines: %d\n", countLines);
    fseek(file, 0, SEEK_SET);
}

void countWords(FILE *file){
    char str[256];
    unsigned int countWords = 0;
    while (fgets(str, 100, file)) {
        for(int i = 0; i<strlen(str) - 1; i++){
            if ((str[i]==' ') && (str[i+1]!=' ')){
                countWords=countWords+1;
            }
        }
        if (str[0]!=' ' && str[0] != '\n'){
            countWords=countWords+1;
        }
    }
    printf("\nCount of words: %d\n", countWords);
    fseek(file, 0, SEEK_SET);
}

void countSymbols(FILE *file){
    char str[256];
    unsigned int countSize = 0;
    while(fgets(str, 100, file)){
        for(int i = 0; i < strlen(str); i++){
            if(str[i] != ' ' && str[i] != '\n'){
                countSize++;
            }
        }
    }
    printf("\nCount of symbols: %d\n", countSize);
    fseek(file, 0, SEEK_SET);
}

int main(int argc, char *argv[]) {
    if (argc < 2) {
        return 0;
    }
    FILE* file = fopen(argv[1], "r");
    
    countLines(file);
    countWords(file);
    countSymbols(file);
    
    fclose(file);
    return 0;
}
