#include <pthread.h>
#include <assert.h>
/*
 * racebench2.1_remarks
 * Filename:svp_simple_025_001
 * Template File:svp_simple_025
 * Created by Beijing Sunwise Information Technology Ltd. on 19/11/25.
 * Copyright © 2019年 Beijing Sunwise Information Technology Ltd. All rights reserved.
 * [说明]:
 * 主程序入口:svp_simple_025_001_main
 * 中断入口:svp_simple_025_001_isr_1
 * 中断间的优先级以中断号作为标准，中断号越高，中断优先级越高。
 *
 *
 *
 *
 */

#include "../common.h"

volatile int svp_simple_025_001_global_var;
volatile int *svp_simple_025_001_global_array[100];
void svp_simple_025_001_func_1(int *array);
void svp_simple_025_001_init();

void *main_task(void *arg) {
  svp_simple_025_001_init();
  svp_simple_025_001_func_1(&svp_simple_025_001_global_var);
}
void svp_simple_025_001_init() {
  svp_simple_025_001_global_var = rand();

  init();
}

void svp_simple_025_001_func_1(int *ptr_var) {
  *ptr_var = *ptr_var + 1;  
}
void *svp_simple_025_001_isr_1(void *arg) {
  svp_simple_025_001_global_var = 0;  
}

// bug点：
// 1.svp_simple_025_001_global_var <R,#35>, <W, #38>, <W, #35>
int main(){
  pthread_t t0, t1, t2, t3;
  pthread_create(&t0, 0, main_task, 0);
  pthread_create(&t1, 0, svp_simple_025_001_isr_1, 0);
  pthread_create(&t2, 0, svp_simple_025_001_isr_1, 0);
  pthread_create(&t3, 0, svp_simple_025_001_isr_1, 0);
}
