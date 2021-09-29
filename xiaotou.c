#include<stdio.h>
int main(){
    for(int x = 1; x <= 4; x++){
        if ( (x!=1) + (x==3) + (x==4) + (x!=4)==3){
            printf("小偷是%c", x+96);
        }
    }
}