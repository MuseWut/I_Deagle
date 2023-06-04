extern void __VERIFIER_error() __attribute__ ((__noreturn__));
void assert(int expression) { if (!expression) { ERROR: __VERIFIER_error();}; return; }
typedef unsigned long int pthread_t;

// error: *svp_simple_009_001_p<W#32>,<R#15>,<W#33>

volatile int *svp_simple_009_001_p;
volatile int *svp_simple_009_001_q;

volatile int *svp_simple_009_001_m;
int reader1 = 0x00, reader2 = 0x00;

void *svp_simple_009_001_isr_1(void *arg) {

  reader1 = *svp_simple_009_001_p;
  int svp_simple_009_001_local_var3 = 0x08;
  svp_simple_009_001_m = &svp_simple_009_001_local_var3;
  reader2 = *svp_simple_009_001_m;
}


int main(){
  pthread_t t1;
  pthread_create(&t1, 0, svp_simple_009_001_isr_1, 0);

    int svp_simple_009_001_local_var1 = 0x01;
    int svp_simple_009_001_local_var2 = 0x09;

    svp_simple_009_001_p = &svp_simple_009_001_local_var1;
    svp_simple_009_001_q = &svp_simple_009_001_local_var1;

    *svp_simple_009_001_p = 0x02;
    *svp_simple_009_001_q = 0x03;

    svp_simple_009_001_m = &svp_simple_009_001_local_var2;

    *svp_simple_009_001_m = 0x06;
    *svp_simple_009_001_m = 0x06;

    pthread_join(t1, 0);
    assert(reader1 != 0x02);
    return 0;
}
