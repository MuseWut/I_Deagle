extern void __VERIFIER_error() __attribute__ ((__noreturn__));
void assert(int expression) { if (!expression) { ERROR: __VERIFIER_error();}; return; }
typedef unsigned long int pthread_t;

//error: svp_simple_008_001_global_array<W#41>,<W#29>,<R#23>

void svp_simple_008_001_func_1();

//#define MAX_LENGTH 10000
//#define TRIGGER 9999

volatile int svp_simple_008_001_global_var;

volatile int svp_simple_008_001_global_array[100];

int reader1, reader2;

void svp_simple_008_001_func_1() {
  int i = 1;
  int j = 2;
  int p = 1;
  int q = 3;
  reader1 = svp_simple_008_001_global_array[i * 20 + j * 10];

  reader2 = svp_simple_008_001_global_array[p + q];
}

void *svp_simple_008_001_isr_1(void *arg) {
  for (int k = 0; k < 100; k++) svp_simple_008_001_global_array[k] = 0x05;
}

int main(){
  pthread_t t1;
  pthread_create(&t1, 0, svp_simple_008_001_isr_1, 0);

  int p = 1;
  int q = 2;

  svp_simple_008_001_global_array[p + q] = 0x09;

  svp_simple_008_001_global_array[40] = 0x01;

  svp_simple_008_001_func_1();

  pthread_join(t1, 0);

  assert(reader1 != 0x05);
  return 0;
}
