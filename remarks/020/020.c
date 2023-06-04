extern void __VERIFIER_error() __attribute__ ((__noreturn__));
void assert(int expression) { if (!expression) { ERROR: __VERIFIER_error();}; return; }
typedef unsigned long int pthread_t;
//bug点:
//1.svp_simple_020_001_global_var<R#43>,<W#27>,<R#46>
//2.svp_simple_020_001_global_para<R#42>,<W#26>,<R#45>

volatile int svp_simple_020_001_global_var;

volatile int svp_simple_020_001_global_para;

volatile int svp_simple_020_001_global_flag = 0;

int reader1, reader2;


void *svp_simple_020_001_isr_1(void *arg) {
  svp_simple_020_001_global_var = 0x01;
  
  svp_simple_020_001_global_flag = 1;
  enable_isr(2);
}

void *svp_simple_020_001_isr_2(void *arg) {
  if (svp_simple_020_001_global_flag == 1) {
    svp_simple_020_001_global_para = 11;
    svp_simple_020_001_global_var = 0x05;
  }
}


int main(){
  pthread_t t0, t1, t2, t3, t4, t5, t6;
  pthread_create(&t1, 0, svp_simple_020_001_isr_1, 0);
  pthread_create(&t2, 0, svp_simple_020_001_isr_2, 0);

    disable_isr(2);
    int svp_simple_020_001_local_var1, svp_simple_020_001_local_var2;
    svp_simple_020_001_local_var1 = rand();
    svp_simple_020_001_local_var2 = rand();

    if (svp_simple_020_001_local_var1 + svp_simple_020_001_local_var2 > svp_simple_020_001_global_para)
        reader1 = svp_simple_020_001_global_var;

    if (svp_simple_020_001_local_var1 + svp_simple_020_001_local_var2 < svp_simple_020_001_global_para)
        reader2 = svp_simple_020_001_global_var;

    pthread_join(t1, 0);
    pthread_join(t2, 0);
    assert(reader1 != reader2);
    return 0;
}
