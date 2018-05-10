#include <math.h>
#include <stdio.h>
#include <stdlib.h>




#define MAXN 32
#define R(i,j)  result[n*(i)+(j)]

int NullSpace(const FLOAT *a, FLOAT *result, FLOAT eps, int n);

int NullSpace(const FLOAT *a, FLOAT *result, FLOAT eps, int n)
{
    int r[MAXN], c[MAXN];
    register int i, j, k;
    int jj, kk, t;
    double max, temp;
    int ec;

    for (i = 0; i < n; i++)
        r[i] = c[i] = -1;           

    if (result != a) 
        for (i = 0; i < n*n; i++)  
            result[i] = a[i];

    for (i = 0; i < n; i++) {
        max = 0.0;
        for (k = 0; k < n; k++) {
            if (r[k] < 0) {
                for (j = 0; j < n; j++) {
                    if ((c[j] < 0) && ((temp = fabs(R(k, j))) > max)) {
                        kk = k;
                        jj = j;
                        max = temp;
                    }
                }
            }
        }
        if (max < eps)
            break;

        c[jj] = kk;                 
        r[kk] = jj;                 

        temp = 1.0 / R(kk, jj);
        R(kk, jj) = 1.0;
        for (j = 0; j < n; j++)     
            R(kk, j) *= temp;       

        for (k = 0; k < n; k++) {   
            if (k == kk)
                continue;           
            temp = R(k, jj);
            R(k, jj) = 0.0;
            for (j = 0; j < n; j++) {
                R(k, j) -= temp * R(kk, j); 
                if (fabs(R(k, j)) < eps)
                    R(k, j) = 0.0;  
            }
        }
    }
	
    for (j = 0; j < n; j++) {       
        while ((c[j] >= 0) && (j != c[j])) {
            for (k = 0; k < n; k++) {
                if (r[k] < 0) {
                    
                    temp = R(k, j);
                    R(k, j) = R(k, c[j]);
                    R(k, c[j]) = temp;
                }
            }
            t = c[j];               
            c[j] = c[t];
            c[t] = t;
        }
    }
	
    ec = 0;
    for (k = 0; k < n; k++) {
        if (r[k] < 0) {
            R(k, k) = 1.0;          
            if (ec != k) {
                for (j = 0; j < n; j++) {
                    R(ec, j) = R(k, j);
                }
            }
            ec++;
        }
    }
	
    return (ec);
}


