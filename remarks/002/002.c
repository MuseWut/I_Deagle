extern void __VERIFIER_error() __attribute__ ((__noreturn__));
void assert(int expression) { if (!expression) { ERROR: __VERIFIER_error();}; return; }
typedef unsigned long int pthread_t;

//#define MAX_LENGTH 10
//#define TRIGGER 9

volatile int svp_simple_002_001_global_array[10];
volatile int casee2_global_var;
int mininum, maxnum;


void *svp_simple_002_001_isr_1(void *arg) {
  svp_simple_002_001_global_array[9] = 999;
}

int main(){
  pthread_t t0;
  pthread_create(&t0, 0, svp_simple_002_001_isr_1, 0);

  for (int i = 0; i < 10; i++) {
      if (i == 9) svp_simple_002_001_global_array[i] = 1;
      if (i == 10 + 1)
          svp_simple_002_001_global_array[i] = 1;
  }
  mininum = svp_simple_002_001_global_array[9] - 10;

  maxnum = svp_simple_002_001_global_array[0] + 10;

  pthread_join(t0, 0);

    assert(mininum != 989);

}
//error: w20 w11 r24