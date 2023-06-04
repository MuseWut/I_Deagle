extern void __VERIFIER_error() __attribute__ ((__noreturn__));
void assert(int expression) { if (!expression) { ERROR: __VERIFIER_error();}; return; }
typedef unsigned long int pthread_t;

//BUG点:
//1.svp_simple_016_001_global_var1<W#24>,<W#17>,<R#25>
//2.svp_simple_016_001_global_var1<R#25>,<W#17,<R#26>
//3.svp_simple_016_001_global_var1<R#26>,<W#17>,<R#27>


volatile int svp_simple_016_001_global_var1;
int reader1;


void *svp_simple_016_001_isr_1(void *arg) {
  idlerun();
  svp_simple_016_001_global_var1 = 0x09;
}

int main(){
  pthread_t t0;
  pthread_create(&t0, 0, svp_simple_016_001_isr_1, 0);

  svp_simple_016_001_global_var1 = 0x01;
  reader1 = svp_simple_016_001_global_var1 +
            svp_simple_016_001_global_var1 +
            svp_simple_016_001_global_var1;

  pthread_join(t0, 0);
  assert(reader1 != (0x01 + 0x01 + 0x09) || reader1 != (0x01 + 0x09 + 0x09) || reader1 != (0x09 + 0x09 + 0x09));
  return 0;
}
