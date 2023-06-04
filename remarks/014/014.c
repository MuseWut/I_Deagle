extern void __VERIFIER_error() __attribute__ ((__noreturn__));
void assert(int expression) { if (!expression) { ERROR: __VERIFIER_error();}; return; }
typedef unsigned long int pthread_t;

//BUG: svp_simple_014_001_global_var1<R#22>,<W#41>,<R#24>

//#define MAX_LENGTH 10
//#define TRIGGER 9

volatile int svp_simple_014_001_global_var1 = 0x01;
volatile int svp_simple_014_001_global_var2 = 0x02;

int svp_simple_014_001_global_flag1 = 0;
int svp_simple_014_001_global_flag2 = 1;
int reader1, reader2;
int reader3, reader4;

void *svp_simple_014_001_isr_1(void *arg) {
  disable_isr(3);

  for (int i = 0; i < 10; i++)
    if (i == 9) reader1 = svp_simple_014_001_global_var1;

  reader2 = svp_simple_014_001_global_var1;

  reader3 = svp_simple_014_001_global_var2;

  reader4 = svp_simple_014_001_global_var2;
}

void *svp_simple_014_001_isr_2(void *arg) {
  svp_simple_014_001_global_flag1 = 1;
  svp_simple_014_001_global_flag2 = 0;

  enable_isr(3);

  idlerun();
}

void *svp_simple_014_001_isr_3(void *arg) {
  if (svp_simple_014_001_global_flag1 == 1) svp_simple_014_001_global_var1 = 0x09;
  if (svp_simple_014_001_global_flag2 == 1) svp_simple_014_001_global_var2 = 0x09;
}



int main(){
  pthread_t t1, t2, t3;
  pthread_create(&t1, 0, svp_simple_014_001_isr_1, 0);
  pthread_create(&t2, 0, svp_simple_014_001_isr_2, 0);
  pthread_create(&t3, 0, svp_simple_014_001_isr_3, 0);

  idlerun();

  pthread_join(t1, 0);
  pthread_join(t2, 0);
  pthread_join(t3, 0);

  assert(reader1 != reader2);
  return 0;
}
