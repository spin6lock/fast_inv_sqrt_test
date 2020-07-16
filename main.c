#include <stdio.h>
#include <math.h>
#include <time.h>

float extra_fast_inv_sqrt(float x) {
    return 1.0f / sqrtf(x);
}

double my_fast_inv_sqrt(double x) {
    return 1.0 / sqrt(x);
}

double ori_fast_inv_sqrt(double x) {
    double y = x;
    double xhalf = (double)0.5 * y;
    long long i = *(long long*)(&y);
    i = 0x5fe6ec85e7de30daLL - (i >> 1);
    y = *(double*)(&i);
    y = y * ((double)1.5 - xhalf * y * y);
    return y;
}

void test(double x) {
    double my_result = my_fast_inv_sqrt(x);
    struct timespec start, end1, end2;
    clock_gettime(CLOCK_MONOTONIC, &start);
    double sum1=0;
    double sum2=0;
    for (int i=0;i<10000000;i++) {
        sum1 += my_fast_inv_sqrt(x);
    } 
    clock_gettime(CLOCK_MONOTONIC, &end1);
    double ori_result = ori_fast_inv_sqrt(x);
    for (int i=0;i<10000000;i++) {
        sum2 += ori_fast_inv_sqrt(x);
    }
    clock_gettime(CLOCK_MONOTONIC, &end2);
    double time_cost1, time_cost2;
    time_cost1 = (end1.tv_sec - start.tv_sec) * 1e9;
    time_cost1 = (time_cost1 + (end1.tv_nsec - start.tv_nsec)) * 1e-9;
    time_cost2 = (end2.tv_sec - start.tv_sec) * 1e9;
    time_cost2 = (time_cost2 + (end2.tv_nsec - start.tv_nsec)) * 1e-9;
    printf("my:%f, origin:%f, mine cost:%f, origin cost:%f, mine faster:%s\n", my_result, ori_result, time_cost1, time_cost2, time_cost1<time_cost2?"true":"false");
}

int main() {
    for (int i=100;i<110;i++) {
        test((double)i);
    }
    return 0;
}
