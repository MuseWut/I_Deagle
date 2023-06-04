extern void __VERIFIER_error() __attribute__ ((__noreturn__));
void assert(int expression) { if (!expression) { ERROR: __VERIFIER_error();}; return; }
typedef unsigned long int pthread_t;

// error: svp_simple_003_001_global_var1<R#53>,<W#22>,<R#58>

//#define MAX_LENGTH 10
//#define TRIGGER 9

volatile int svp_simple_003_001_global_var1 = 0;
volatile int svp_simple_003_001_global_var2 = 0;

volatile int svp_simple_003_001_global_flag = 1;
volatile int svp_simple_003_001_global_flag1 = 0;

int reader1, reader2;


void *svp_simple_003_001_isr_1(void *arg) {

  svp_simple_003_001_global_var2 = 999;

  if (svp_simple_003_001_global_flag == 1) {
    svp_simple_003_001_global_var1 = 999;
  } else if (svp_simple_003_001_global_flag1 == 2) {
    svp_simple_003_001_global_var1 = 888;
  }
}

void *svp_simple_003_001_isr_2(void *arg) {
  svp_simple_003_001_global_flag = 1;
}

int main(){
  pthread_t t1, t2;
  pthread_create(&t1, 0, svp_simple_003_001_isr_1, 0);
  pthread_create(&t2, 0, svp_simple_003_001_isr_2, 0);
  int reader3, reader4;

  for (int i = 0; i < 10; i++) {
      if (i == 9) {
          reader3 = svp_simple_003_001_global_var2;
      }
  }
  for (int j = 10; j > 0; j--) {
      if (j == 9) {
          reader4 = svp_simple_003_001_global_var2;
      }
  }

  for (int i = 0; i < 10; i++) {
      if (i == 9) {
          reader1 = svp_simple_003_001_global_var1;
      }
  }
  for (int j = 10; j > 0; j--) {
      if (j == 9) {
          reader2 = svp_simple_003_001_global_var1;
      }
  }
  pthread_join(t1, 0);
  pthread_join(t2, 0);

  assert(reader2 != 999);
  return 0;
}


