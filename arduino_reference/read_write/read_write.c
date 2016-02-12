#include <stdio.h>
#include <string.h>

int main(){
    const char str_to_write[] = "My dog is named Mose!";
    const char filename[] = "/dev/tty/ACM0"; //const char filename[] = "dogs.txt"; int len = strlen(str_to_write); FILE *file;
    file = fopen(filename, "w");

    if(file != NULL){
        for(int i = 0; i < len; i++){
            fputc(str_to_write[i], file);    
        }
        fclose(file);
    }
    else{
        printf("Couldn't open file\n");
        return 1;
    }
    return 0;
}
