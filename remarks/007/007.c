extern void __VERIFIER_error() __attribute__ ((__noreturn__));
void assert(int expression) { if (!expression) { ERROR: __VERIFIER_error();}; return; }
typedef unsigned long int pthread_t;

//error: svp_simple_007_001_global_array<W#35>,<W#18>,<R#39>

//#define MAX_LENGTH 10
//#define TRIGGER 9

volatile int svp_simple_007_001_global_var;

volatile int svp_simple_007_001_global_array[5];

int reader1, reader2;

void *svp_simple_007_001_isr_1(void *arg) {

  svp_simple_007_001_global_array[2] = 0x09;

  svp_simple_007_001_global_var += 1;
  svp_simple_007_001_global_array[svp_simple_007_001_global_var] = 0x09;
}


int main(){
  pthread_t t0;
  pthread_create(&t0, 0, svp_simple_007_001_isr_1, 0);

  svp_simple_007_001_global_array[svp_simple_007_001_global_var] = 0x01;

  reader2 = svp_simple_007_001_global_array[svp_simple_007_001_global_var];

  int i = rand();
  if (i == 2)
      svp_simple_007_001_global_array[i] = 0x02;
  else
      svp_simple_007_001_global_array[i] = 0x09;

  reader1 = svp_simple_007_001_global_array[2];

  pthread_join(t0, 0);

  assert(reader1 != 0x09);

  return 0;
}
