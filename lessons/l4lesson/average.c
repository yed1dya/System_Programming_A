# include <stdio.h>
# include <stdlib.h>

int main(int argc, char* argv[]){
    float sum = 0;
    int i, num;
    num = argc-1;
    for(i=1; i<=num; i++){
        sum += atof(argv[i]);   
    }
    printf("average: %f\n", sum/(float) num);
    return 0;
}