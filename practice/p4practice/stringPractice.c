#include <string.h>
#include <stdbool.h>
#include <stdio.h>


void line(){
    printf("\n");
}

int strLength(char* s){
    int i = 0;
    if(s==NULL) return 0;
    while(s[i] != 0) i++;
    return i;
}

char* strCat(char* d, char* s){
    // goes to end of d
    char* ans = d + strLength(d);
    while(s != 0){
        // make the pointer in dest point to the same char as s:
        *ans = *s;
        s++;
        ans++;
    }
    *ans = 0;
    return d;
}

/* returns 0 iff a==b. else returns the distance between the first different char. */
int strComp(char* a, char* b){
    /* while both pointers aren't a null terminator, and equal;
    this brings us to the first index that's different: */
    while(*a && *b && *a==*b){
        a++;
        b++;
    }
    /* returns the difference between the ascii 
    values of the chars that the pointers point at: */
    return *a-*b;
}

/* checks if a ends with b */
bool checkSuffix(char* a, char* b){
    int lenA = strLength(a);
    int lenB = strLength(b);
    if(lenA < lenB) return false;
    /* compare the last "lentB" chars of a, and b: */
    return !strComp(a+(lenA-lenB), b);
}

char upCase(char c){
    if(c >= 'a' && c <= 'z'){
        return c - 'a' + 'A';
    }
    return c;
}

int strCompCaseInsensitiveN(char* a, char* b, int n){
    for(int i=0; i<n; i++){
        /* two ways to point to the char: */
        if(upCase(*a) != upCase(b[i])) return 0;
        a++;
    }
    return 1;
}

int countSubStrings(char* a, char* b){
    int lenA = strLength(a), lenB = strLength(b);
    int count = 0;
    for(int i=0; i<lenB-lenA; i++){
        if(strCompCaseInsensitiveN(a, b+i, lenA)){
            count++;
        }
    }
    return count;
}

int charToNum(char*c){
    int sign = 1;
    int num = 0;
    if(*c == '-'){
        sign = -1;
        c++;
    }
    while(*c != 0){
        num = num*10 + (*c-'0');
        c++;
    }
    return sign*num;
}

void reverse(char* a, int len){
    for(int i=0; i<len/2; i++){
        char t = a[i];
        a[i] = a[len-i-1];
        a[len-i-1] = t;
    }
}

void swapWords(char s[]){
    int lengths[3];
    int i=0, len=0, count, strLen=0;
    for(count=0; count<3; count++){
        while(s[i++]){
            strLen++;
        }
        lengths[count] = strLen+1;
        len += lengths[count];
        strLen = 0;
    }
    reverse(s, len);
    reverse(s, lengths[2]);
    reverse(s+lengths[2], lengths[1]);
    reverse(s+lengths[2]+lengths[1], lengths[0]);
}

int abu(char* num){
    bool go=true;
    int a = (int)*(num)-48, b = (int)*(num+1)-48, expected, next, i=2, j=0;
    printf("%c", *num);
    printf("%c", *(num+1));
    while (go){
        go = false;
        if(*(num+i)=='\0'){
            return 1;
        } 
        expected = a+b;
        next = (int)*(num+i)-48;
        j=0;
        while(*(num+i+j) != '\0'){
            if(next == expected){
                go = true;
                a = b;
                b = next;
                i += (j+1);
                printf("%d", next);
                break;
            } 
            next *= 10;
            next += (int)*(num+i+j+1)-48;
            j++;
        }
    }
    return 0;
}

void num2string(int num, char*str){
    int i=0;
    while(num>0){
        char c = num%10 + '0';
        str[i] = c;
        num /= 10;
        i++;
    }
    int len = i;
    for(int j = 0; j<len/2; j++){
        char t = str[j];
        str[j] = str[i-1];
        str[i-1] = t;
        i--;
    }
}

int beginWith2(char*A, char*B){
    int a = 0, b = 0;
    while(*(A+a)!=0 && *(B+b)!=0){
        if(*(A+a)!=*(B+b)) return 0;
        if(*(A+a+1)==0) return 1;
        if(*(B+b+1)==0) return 0;
        a++;
        b++;
    }
    return 1;
}

int beginWith(char*A, char*B){
    while(*A && *B){
        if(*A != *B) break;
        A++;
        B++;
    }
    return (*A == 0) ? 1 : 0;
}

int main(int argc, char const *argv[])
{

    printf("%d\n", beginWith("abc", "abcdef"));
    printf("%d\n", beginWith("abc", "avbcdef"));
    printf("%d\n", beginWith("abcdef", "abc"));
    // char num[6];
    // char num2[] = {'2', '4', '6', '0', '1'};
    // printf("num2: %s\n", num2);
    // num2string(24601, num);
    // printf("num: %s\n", num);

    // printf("\nabu: %d\n", abu("12358132134"));
    // printf("\nabu: %d\n", abu("12"));
    // printf("\nabu: %d\n", abu("12358132134999"));

    // char* a[] = {"abc", "def", "ghi"};
    // for(int i=0; i<3; i++){
    //     printf("%s\n", *(a+i));
    // }
    // char b[] = {'h','e','l','l','o',0,'m','y',0,'w','o','r','l','d',0};
    // printf("b size: %d\n", (int)sizeof(b));
    // printf("%s\n", b);
    // printf("%d\n", strLength(b));
    // printf("%s\n", b);
    // printf("%d\n", strLength(b+6));
    // printf("%s\n", b+6);
    // printf("%d\n", strLength(b+9));
    // printf("%s\n", b+9);
    // for(int i=0; i<(int)sizeof(b); i++){
    //     char c = *(b+i);
    //     printf("%c", (c==0 ? 32 : c));
    // }
    // line();
    // swapWords(b);
    // for(int i=0; i<(int)sizeof(b); i++){
    //     char c = *(b+i);
    //     printf("%c", (c==0 ? 32 : c));
    // }
    
    // char *e = "a regular string";
    // char f[] = "also a string";
    // char*g[4] = {e, f, 0, "a string"};
    // char a[] = "aba", b[] = "aba 2 abababaBA";
    // printf("%d\n", sizeof(g));
    // printf("%d\n", sizeof(g)/sizeof(g[0]));
    // for(int i=0; i<sizeof(g)/sizeof(g[0]); i++){
    //     printf("\nsize: %d , ", sizeof(g[0]));
    //     if(g[i]==NULL) continue;
    //     printf("%s", g[i]);
    // }
    // if(argc>=2){
    //     printf("cmd line input:\n");
    //     const char *c = argv[1], *d = argv[2];
    //     printf("%s", c);
    //     printf("\n");
    //     printf("%s", d);
    //     printf("\n");
    //     printf("%d\n", countSubStrings(c, d));
    //     printf("%d\n", strCompCaseInsensitiveN(c, d, 3));
    // }
    // printf("\n%d\n", countSubStrings("aba","kaba 2 abababaBA"));
    // printf("%d\n", strCompCaseInsensitiveN("hello", "hella", 4));
    // printf("%d\n", countSubStrings("hello", "hella"));
    // printf("%d\n", strCompCaseInsensitiveN("hello", "hella", 4));
    // printf("%d\n", charToNum("2345"));
    // printf("%d\n", charToNum("-454345"));

    // char*beatles[5] = { "John Lennon","Paul McCartney",
    // "George Harrison","Ringo Starr" };
    // for(int i=0; i<sizeof(beatles)/sizeof(beatles[0]); i++){
    //     printf("\nbeatle ID: %d; name: %s, %s", i,
    //      beatles[i], (i==2)?"drums":"guitar");
    //     line();
    //     for(int j=strLength(beatles[i])-1; i==0 && j>=0; j--){
    //         /* beatles is a spot in memory (the first spot in an array). go to that spot plus i steps - 
    //         each step is a pointer to a string. go to the string that that place is pointing at.
    //         that's what the '*' is. in the string, (which is an array), go to spot j. */
    //         putchar((*(beatles+i))[j]);
    //     }
    //     for(int j=strLength(beatles[i])-1; i==1 && j>=0; j--){
    //         /* go to the ith place in 'beatles'. +j steps in that array. go to the char that it's pointing at. */
    //         putchar(*(beatles[i]+j));
    //     }
    //     for(int j=strLength(beatles[i])-1; i==2 && j>=0; j--){
    //         /* go to beatles+i. +j. go to whatever that points at. */
    //         putchar(*(*(beatles+i)+j));
    //     }
    //     for(int j=strLength(beatles[i])-1; i==3 && j>=0; j--){
    //         /* the jth spot in the ith spot in beatles. */
    //         putchar(beatles[i][j]);
    //     }
    //     line();
    // }
    // line();
    // beatles[2] = "new beatle";
    // for(int i=0; i<sizeof(beatles)/sizeof(beatles[0]); i++){
    //     printf("\nbeatle ID: %d; name: %s", i, *(beatles+i));
    // }
    // printf("\nk good");
    // swapWords("abc\0def\0ghi\0");
    printf("\n\n---END PROGRAM---\n\n");
    return 0;
}
