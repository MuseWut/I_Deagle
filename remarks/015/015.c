extern void __VERIFIER_error() __attribute__ ((__noreturn__));
void assert(int expression) { if (!expression) { ERROR: __VERIFIER_error();}; return; }
typedef unsigned long int pthread_t;

//BUG: svp_simple_015_001_global_var1<R#29>,<W#14>,<R#30>

volatile int svp_simple_015_001_global_var1 = 0;
volatile int svp_simple_015_001_global_var2;
int reader1;


void *svp_simple_015_001_isr_1(void *arg) {
  idlerun();
  svp_simple_015_001_global_var1 = 5;
  svp_simple_015_001_global_var2 = 5;
  reader1 = 1;
}

int main(){
  pthread_t t0;
  pthread_create(&t0, 0, svp_simple_015_001_isr_1, 0);

    reader1 = 0;
    int x = rand();
    int y = rand();
    int z;
    int p = rand();

    if ((svp_simple_015_001_global_var1 < y) &&
        (svp_simple_015_001_global_var1 > x)){
        z = x + y;
        assert(reader1 == 0);
    }


    p == 1 ? svp_simple_015_001_global_var2 : svp_simple_015_001_global_var2;

    pthread_join(t0, 0);

    return 0;
}
