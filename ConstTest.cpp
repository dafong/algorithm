//
// Created by 范鑫磊 on 17/3/9.
//

int main(){
    int i = 1;
    const int *p = &i;
    const int * const p1 = &i;
    int j = 2;
    p = &j;
}