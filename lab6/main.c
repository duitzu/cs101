#include <stdio.h>

int _sum(int x, int y) {
    return x + y;
}
int _sub(int x, int y) {
    return x - y;
}
int _mult(int x, int y) {
    return x * y;
}
int _div(int x, int y) {
    return x / y;
}
int _pow(int x, int y) {
    if(y == 1) return x;
    int num = x;
    num = _pow(num, --y);
    num *= x;
    return num;
}

int main() {
    int x, y, choice;
    int (*ope[5])(int, int);
    ope[0] = _sum;
    ope[1] = _sub;
    ope[2] = _mult;
    ope[3] = _div;
    ope[4] = _pow;
    
    printf("Enter Two Integers: ");
    scanf("%d%d", &x, &y);
    
    printf("Enter 0:+, 1:-, 2:*, 3:, 4:^ :");
    scanf("%d", &choice);
    
    printf("%d", ope[choice](x, y));
    return 0;
}