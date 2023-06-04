#include <pthread.h>
#include <assert.h>
/*
 * racebench2.1_remarks
 * Filename:svp_simple_026_001
 * Template File:svp_simple_026
 * Created by Beijing Sunwise Information Technology Ltd. on 19/11/25.
 * Copyright © 2019年 Beijing Sunwise Information Technology Ltd. All rights reserved.
 * [说明]:
 * 主程序入口:svp_simple_026_001_main
 * 中断入口:svp_simple_026_001_isr_1，svp_simple_026_001_isr_2
 * 中断间的优先级以中断号作为标准，中断号越高，中断优先级越高。
 *
 *
 *
 *
 */

#include "../common.h"

void svp_simple_026_001_init();

volatile int svp_simple_026_001_gloable_var;
void *main_task(void *arg) {
  svp_simple_026_001_init();

  disable_isr(1);
  if (svp_simple_026_001_gloable_var > 12) {  
    svp_simple_026_001_gloable_var = 0;       
  }
  enable_isr(1);

  return 0;
}
void svp_simple_026_001_init() {
  svp_simple_026_001_gloable_var = rand();

  init();
}

void *svp_simple_026_001_isr_1(void *arg) {
  svp_simple_026_001_gloable_var++;  
}
void *svp_simple_026_001_isr_2(void *arg) {
  svp_simple_026_001_gloable_var--;  
}

// bug点：
// 1.svp_simple_026_001_gloable_var <R, #26>, <W, #43>, <W,#27>

// 误报点：
// 1.svp_simple_026_001_gloable_var <R, #26>, <W, #40>, <W,#27>
int main(){
  pthread_t t0, t1, t2, t3, t4, t5, t6;
  pthread_create(&t0, 0, main_task, 0);
  pthread_create(&t1, 0, svp_simple_026_001_isr_1, 0);
  pthread_create(&t2, 0, svp_simple_026_001_isr_1, 0);
  pthread_create(&t3, 0, svp_simple_026_001_isr_1, 0);
  pthread_create(&t4, 0, svp_simple_026_001_isr_2, 0);
  pthread_create(&t5, 0, svp_simple_026_001_isr_2, 0);
  pthread_create(&t6, 0, svp_simple_026_001_isr_2, 0);
}
