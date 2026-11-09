#include <stdio.h>
 
#define MAXN 10000
 
 
int main(void)
{
    int n, count;
    char in, c;
 
    scanf("%d", &n);
    getchar();
    while(n--) {
        count = 0;
        c = '\0';
        for(;;) {
            in = getchar();
 
            if(in == '\n')
                break;
 
            if(in != c) {
                if(count != 0) {
                    if(count == 1)
                        putchar(c);
                    else
                        printf("%d%c", count, c);
                }
                c = in;
                count = 1;
            } else
                count++;
        }
        if(count > 0) {
            if(count == 1)
                putchar(c);
            else
                printf("%d%c", count, c);
        }
        printf("\n");
    }
 
    return 0;
}


