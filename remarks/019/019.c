extern void __VERIFIER_error() __attribute__ ((__noreturn__));
void assert(int expression) { if (!expression) { ERROR: __VERIFIER_error();}; return; }
typedef unsigned long int pthread_t;
//BUG: svp_simple_019_001_global_var1<R#43>,<W#25>,<R#46>

volatile int svp_simple_019_001_global_condition1 = 1;
volatile int svp_simple_019_001_global_condiiton2 = 1;
volatile int svp_simple_019_001_global_condition3 = 1;

volatile int svp_simple_019_001_global_para1;
volatile int svp_simple_019_001_global_para2;
volatile int svp_simple_019_001_global_para3;

volatile int svp_simple_019_001_global_var1;
volatile int svp_simple_019_001_global_var2;

int reader1, reader2, reader3, reader4, reader5;

void *svp_simple_019_001_isr_1(void *arg) {
  if ((svp_simple_019_001_global_para1 + svp_simple_019_001_global_para3) < svp_simple_019_001_global_para2)
    svp_simple_019_001_global_var2 = 0x55;

  svp_simple_019_001_global_condition3 = 0;

  svp_simple_019_001_global_var1 = 0x01;
}

int main(){
  pthread_t t0;
  pthread_create(&t0, 0, svp_simple_019_001_isr_1, 0);


    svp_simple_019_001_global_para1 = rand() % 10;
    svp_simple_019_001_global_para2 = rand() % 10;
    svp_simple_019_001_global_para3 = rand() % 10;

    if ((svp_simple_019_001_global_para1 + svp_simple_019_001_global_para3) > svp_simple_019_001_global_para2)
        reader1 = svp_simple_019_001_global_var2;

    reader2 = svp_simple_019_001_global_var2;

    if ((svp_simple_019_001_global_condition1 == 1) && (svp_simple_019_001_global_condiiton2 == 1))
        reader3 = svp_simple_019_001_global_var1;
    if ((svp_simple_019_001_global_condition1 == 1) && (svp_simple_019_001_global_condition3 == 1))
    {
        reader4 = svp_simple_019_001_global_var1;
    }

    if ((svp_simple_019_001_global_condiiton2 == 1) && (svp_simple_019_001_global_condition3 == 0))
    {
        reader5 = svp_simple_019_001_global_var1;
    }

    pthread_join(t0, 0);
    assert(reader3 != reader4);
    return 0;
}
