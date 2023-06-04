extern void __VERIFIER_error() __attribute__ ((__noreturn__));
void assert(int expression) { if (!expression) { ERROR: __VERIFIER_error();}; return; }
typedef unsigned long int pthread_t;

//error: svp_simple_004_001_global_var1<R#51>,<W#28>,<R#56>


//#define MAX_LENGTH 10000
//#define TRIGGER 9999

volatile int svp_simple_004_001_condition1 = 1;
volatile int svp_simple_004_001_condition2 = 1;
volatile int svp_simple_004_001_condition3 = 1;
volatile int svp_simple_004_001_condition4 = 1;
volatile int svp_simple_004_001_condition5 = 1;
volatile int svp_simple_004_001_condition6 = 1;

volatile int svp_simple_004_001_global_var1 = 0x11;
volatile int svp_simple_004_001_global_var2 = 0x22;
volatile int svp_simple_004_001_global_var3 = 0x33;

int reader1, reader2;


void *svp_simple_004_001_isr_1(void *arg) {
  svp_simple_004_001_condition6 = 0;
  if (svp_simple_004_001_condition3 == 1)
    svp_simple_004_001_global_var1 = 0xaa;
  else
    svp_simple_004_001_global_var3 = 0xcc;

  enable_isr(2);
}

void *svp_simple_004_001_isr_2(void *arg) {
  if (svp_simple_004_001_condition6 == 1)
    svp_simple_004_001_global_var2 = 0x22;
}

int main(){
  pthread_t t0, t1;
  pthread_create(&t0, 0, svp_simple_004_001_isr_1, 0);
  pthread_create(&t1, 0, svp_simple_004_001_isr_2, 0);

  int reader3, reader4;
  int reader5, reader6;

  disable_isr(2);

  if (svp_simple_004_001_condition1 == 1) {
      reader1 = svp_simple_004_001_global_var1;
      reader5 = svp_simple_004_001_global_var3;
  }

  if (svp_simple_004_001_condition2 == 1) {
      reader2 = svp_simple_004_001_global_var1;
      reader6 = svp_simple_004_001_global_var3;
  }

  if (svp_simple_004_001_condition4 == 1) reader3 = svp_simple_004_001_global_var2;

  if (svp_simple_004_001_condition5 == 1) reader4 = svp_simple_004_001_global_var2;

  pthread_join(t0, 0);
  pthread_join(t1, 0);

  assert(reader2 != 0xaa);

  return 0;
}
