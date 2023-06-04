extern void __VERIFIER_error() __attribute__ ((__noreturn__));
void assert(int expression) { if (!expression) { ERROR: __VERIFIER_error();}; return; }
typedef unsigned long int pthread_t;

//BUG: svp_simple_013_001_global_var1<R#45>,<W#29>,<R#47>

//#define MAX_LENGTH 100
//#define TRIGGER 99

volatile int svp_simple_013_001_global_var1;
volatile int svp_simple_013_001_global_var2;

int svp_simple_013_001_global_flag1 = 0;
int svp_simple_013_001_global_flag2 = 1;
int reader1, reader2;
int reader3, reader4;

void *svp_simple_013_001_isr_1(void *arg) {
  enable_isr(2);
}

void *svp_simple_013_001_isr_2(void *arg) {
  svp_simple_013_001_global_flag1 = 1;

  svp_simple_013_001_global_flag2 = 0;

  enable_isr(3);
}

void *svp_simple_013_001_isr_3(void *arg) {
  if (svp_simple_013_001_global_flag1 == 1) svp_simple_013_001_global_var1 = 0x01;
  if (svp_simple_013_001_global_flag2 == 1) svp_simple_013_001_global_var2 = 0x01;
}

int main(){
  pthread_t t0, t1, t2, t3;
  pthread_create(&t1, 0, svp_simple_013_001_isr_1, 0);
  pthread_create(&t2, 0, svp_simple_013_001_isr_2, 0);
  pthread_create(&t3, 0, svp_simple_013_001_isr_3, 0);
  disable_isr(2);
  disable_isr(3);
  for (int i = 0; i < 100; i++)
      if (i == 99) reader1 = svp_simple_013_001_global_var1;

  reader2 = svp_simple_013_001_global_var1;

  reader3 = svp_simple_013_001_global_var2;

  reader4 = svp_simple_013_001_global_var2;

  pthread_join(t1, 0);
  pthread_join(t2, 0);
  pthread_join(t3, 0);
  assert(reader1 != reader2);
  return 0;
}
