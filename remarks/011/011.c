extern void __VERIFIER_error() __attribute__ ((__noreturn__));
void assert(int expression) { if (!expression) { ERROR: __VERIFIER_error();}; return; }
typedef unsigned long int pthread_t;

//error: *p<W#27>,<R#17>,<W#28>

int svp_simple_011_001_global_var1;
int svp_simple_011_001_global_var2;
int svp_simple_011_001_global_var3;

volatile int *svp_simple_011_001_u;
int reader1, reader2;


void *svp_simple_011_001_isr_1(void *arg) {
  int *m = &svp_simple_011_001_global_var1;
  reader1 = *m;
  reader2 = *svp_simple_011_001_u;
}

int main(){
  pthread_t t0, t1, t2, t3;
  pthread_create(&t1, 0, svp_simple_011_001_isr_1, 0);
    int *p = &svp_simple_011_001_global_var1;
    int *q = &svp_simple_011_001_global_var1;

    *p = 0x01;
    *q = 0x02;

    svp_simple_011_001_u = &svp_simple_011_001_global_var2;
    *svp_simple_011_001_u = 0x01;
    svp_simple_011_001_u = &svp_simple_011_001_global_var3;
    *svp_simple_011_001_u = 0x02;

    pthread_join(t1, 0);
    assert(reader1 != 0x01);
    return 0;
}
