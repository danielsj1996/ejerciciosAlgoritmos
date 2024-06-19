#include <stdio.h>
int main(){



    int prim=10, seg=20,temp;
    int*punt_num;
    printf("Al Inicio - prim= %d,seg: %d\n",prim,seg);
    punt_num = &prim;
    temp= *punt_num;
    *punt_num=seg;
    seg=temp;

    printf("Despues - prim: %d, seg:%d", prim, seg);
    return 0;
}