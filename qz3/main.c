#include <stdlib.h>
#include <stdio.h>
int i = 0;
FILE* fp;

char rec_dec(char* str) {
    i != 0 ? printf(",%c", *str): printf("%c", *str);
    if(!(*str)) return 0;
    i++;
    rec_dec(str+1);
    return 0;
}

void towerOfHanoi (int n, char from_rod, char to_rod, char aux_rod) {
    if (n == 1) {
        fp = fopen("honai.txt", "a+");
        fprintf(fp, "\n Move disk 1 from  %c to  %c", from_rod, to_rod);
        fclose(fp);
        return ;
    }
    towerOfHanoi(n-1, from_rod, aux_rod, to_rod);
    fp = fopen("honai.txt", "a+");
    fprintf(fp, "\n Move disk %d from  %c to  %c", n, from_rod, to_rod);
    fclose(fp);
    towerOfHanoi(n-1, aux_rod, to_rod, from_rod);
}

int multiplication(int i, int j) {
    printf("%d * %d = %2d ", i, j, i*j);
    if(j == 9) {
        if(i == 9) return 0;
        printf("\n");
        i++;
        j = 0;
        return multiplication(i ,j+1);
    }
    multiplication(i ,j+1);
    return 0;
}
int main() {
    char s[] = "1234546915641789";
    rec_dec(s);
    printf("\n#Func 1.----------------\n");
    towerOfHanoi(16, 'A', 'B', 'C');
    printf("\n#Func 2.----------------\n");
    multiplication(1,1);
    printf("\n#Func 3.----------------\n");
    return 0;
}