extern void __VERIFIER_error() __attribute__ ((__noreturn__));
void assert(int expression) { if (!expression) { ERROR: __VERIFIER_error();}; return; }
typedef unsigned long int pthread_t;

//error: svp_simple_005_001_global_var<W#29>,<R#18>,<W#36>

//#define MAX_LENGTH 5
//#define TRIGGER 4
//#define TRIGGER1 1

volatile int svp_simple_005_001_global_condition = 0;

volatile int svp_simple_005_001_global_var;

int reader;

void *svp_simple_005_001_isr_1(void *arg) {
  reader = svp_simple_005_001_global_var;
}


int main(){
  pthread_t t1;
  pthread_create(&t1, 0, svp_simple_005_001_isr_1, 0);

  for (int i = 0; i < 5; i++) {
      for (int j = 0; j < 5; j++) {
          if ((i == 4) && (j == 1))
              svp_simple_005_001_global_var = 0x01;
      }
  }

  if (svp_simple_005_001_global_condition ==
      1)
      svp_simple_005_001_global_var = 0x09;
  svp_simple_005_001_global_var = 0x05;

  pthread_join(t1, 0);

  assert(reader != 0x01);

  return 0;
}
