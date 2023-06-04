extern void __VERIFIER_error() __attribute__ ((__noreturn__));
void assert(int expression) { if (!expression) { ERROR: __VERIFIER_error();}; return; }
typedef unsigned long int pthread_t;

//error: svp_simple_012_001_global_var<W#23>,<R#13>,<W#25>

int svp_simple_012_001_global_var;

int svp_simple_012_001_global_pointer;
int reader1;

void *svp_simple_012_001_isr_1(void *arg) {
  reader1 = svp_simple_012_001_global_var;
}


int main(){
  pthread_t t0, t1, t2, t3;
  pthread_create(&t1, 0, svp_simple_012_001_isr_1, 0);

    int *p = &svp_simple_012_001_global_var;

    svp_simple_012_001_global_var = 0x01;

    *p = 0x02;

    pthread_join(t1, 0);
    assert(reader1 != 0x01);
    return 0;
}
