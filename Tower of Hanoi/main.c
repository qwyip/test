#include <stdio.h>

void hanoi(int n,int from,int to,int aux){
    if(n==1){
        printf("%d %d %d\n",n,from,to);
    }
    else{
        hanoi(n-1,from,aux,to);
        printf("%d %d %d\n",n,from,to);
        hanoi(n-1,aux,to,from);
    }
}


int main() {
    int n;
    scanf("%d",&n);
    hanoi(n,1,3,2);
    return 0;
}
