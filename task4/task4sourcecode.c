#include <stdio.h>
#include <stdlib.h>
#include <time.h> 
 
/*
    compilation notes: 
    -O2: 6.969321
    -O3: 7.044864
    -O4: 6.965374
    -Ofast: 6.971263
    -Os: 7.458775   


    HW specs: 
    Cache L1d 528 KiB 11 instances
    Cache L1i 704 KiB 11 instances 
    Cache L2 22 MiB
    Cache L3 24 MiB 
    NUMA 0-21

    CPU: Interl Ultra 7 155H
    Cores/sockets : 11
    Sockets  1
    Threads/Cores: 2

    Memory: 15Gi - Swap 4Gi
*/ 

struct ab {
    int ***a;
    int ***b;
};
 
 
long long int p(struct ab s, int w, int x, int y, int z) {
    long long int t = 0;
    // w is 50 - number of steps 
    // xyz = 300*200*100
    // total cell-visit number = xyz * w = 300*200*100*50
    for (int h = 0; h < w; h++) {
        for (int k = 0; k < x; k++) {
            for (int j = 0; j < y; j++) {
                for (int i = 0; i < z; i++) {
                    s.a[i][j][k] += rand() % 3; // fully-independent operation
//                    printf("%d\n", s.a[i][j][k]);
                }
            }
        }
        for (int k = 0; k < x; k++) {
            for (int j = 1; j < y; j++) {
                for (int i = 0; i < z; i++) {
                    s.b[i][j][k] = s.a[i][j][k] + s.a[i][j - 1][k];
                    t += s.b[i][j][k];
                }
            }
        }
    }
    return t;
}
 
 
int main() {
    srand(1234);
    int w = 50;  
    int x = 100;
    int y = 200;
    int z = 300;
    struct ab s;
    // dimension 1 is 300 elements - z
    s.a = malloc(sizeof(int *) * z);
    s.b = malloc(sizeof(int *) * z);
    time_t start = clock();
    // as long as intialization and allocation is fully-independent, MPI with OpenMP can be used
    // to reduce runtime 
    for (int k = 0; k < z; k++) {
        s.a[k] = malloc(sizeof(int *) * y);
        s.b[k] = malloc(sizeof(int *) * y);
        // demension 2 is 200 elements - y
        for (int j = 0; j < y; j++) {
            s.a[k][j] = malloc(sizeof(int) * x);
            s.b[k][j] = malloc(sizeof(int) * x);
            // dimension 3 is 100 elements - x 

            // if a brute force traverse will visit 300*200*100 cells
            for (int i = 0; i < x; i++) {
                s.a[k][j][i] = 0;
                s.b[k][j][i] = 0;
            }
        }
    }
    long long int t = p(s, w, x, y, z);
    printf("time elapsed %f\n", ((double)(clock() - start)/CLOCKS_PER_SEC));
    printf("%lld\n", t);
    return 0;
}
