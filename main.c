#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <stdbool.h>
#include "unity.h"

struct Results {
  int * C;
  int L; // Length of the array
};

int _max(int A, int B)
{
    return A < B ? B : A;
}

struct Results solution(int N, int A[], int M)
{
    struct Results res;
    res.C = (int*)malloc(N*sizeof(int));
    for(int w=0;w<N;++w)
    {
        res.C[w]=0;
    }
    res.L = N;
    int max = 0;
    int curmax = 0;
    for(int i = 0; i<M; ++i)
    {
        if(A[i]>N)
        {
                max = curmax;
        }
        else
        {
            res.C[A[i]-1]=_max(res.C[A[i]-1],max)+1;
            curmax=_max(res.C[A[i]-1],curmax);
                
        }
        #ifdef PRINTING
        for(int j = 0;j<N;++j)
        {
            printf("\nC[%d]: %d\n",j,res.C[j]);
        }
        printf("\n-----------------------------------\n");
        #endif
    }
    if(max>0)
    {
        for(int j = 0; j<N; ++j)
        {
            if(res.C[j]<max)
            {
                res.C[j] = max;
            }
        }
    }
    #ifdef PRINTING
    for(int j = 0;j<N;++j)
    {
        printf("\nC[%d]: %d\n",j,res.C[j]);
    }
    printf("\n-----------------------------------\n");
    #endif

    return res;
}


void setUp(void) 
{
    printf("\nUnity Test started.\n");
}

void tearDown(void) 
{
    printf("\nUnity Test ended.\n");
}
void odd_occurrences_in_array(void) 
{
    int A7_1[] = {3,4,4,6,1,4,4};
    struct Results expres1;
    int res[] = {3,2,2,4,2}; 
    expres1.C=res;
    expres1.L=5;
    struct Results res1 =  solution(5, A7_1, 7);
    TEST_ASSERT_EQUAL_INT_ARRAY( expres1.C, res1.C,res1.L);

    int A7_2[] = {3,4,4,6,1,4,4,6};
    struct Results expres2;
    int _res2[] = {4,4,4,4,4}; 
    expres2.C=_res2;
    expres2.L=5;
    struct Results res2 =  solution(5, A7_2, 8);
    TEST_ASSERT_EQUAL_INT_ARRAY( expres2.C, res2.C,res2.L);


}

int main()
{

    UNITY_BEGIN();
    RUN_TEST(odd_occurrences_in_array);
    return UNITY_END();
}
