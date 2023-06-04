extern void __VERIFIER_error() __attribute__ ((__noreturn__));
void assert(int expression) { if (!expression) { ERROR: __VERIFIER_error();}; return; }
typedef unsigned long int pthread_t;

//bug点:
//1.svp_simple_017_001_global_var<W#33>,<W#22>,<R#33> 我们新找的
//2.svp_simple_017_001_global_var<R#33>,<W#22>,<R#36>
//3.svp_simple_017_001_global_var<R#36>,<W#22>,<W#34>

// 轩宇
// 5.svp_simple_017_001_global_var<R#34>,<W#39>,<W#34>

//#define MAX_LENGTH 10
//#define TRIGGER 5

volatile int svp_simple_017_001_global_var;
volatile int svp_simple_017_001_local_array[10];

void *svp_simple_017_001_isr_1(void *arg) {
  idlerun();

  svp_simple_017_001_global_var = 5;

  svp_simple_017_001_local_array[5] = 0;
}

int main(){
  pthread_t t1;
  pthread_create(&t1, 0, svp_simple_017_001_isr_1, 0);

  int i = 0;

  for (svp_simple_017_001_global_var = 0; svp_simple_017_001_global_var < 10;
       svp_simple_017_001_global_var++)
  {
      svp_simple_017_001_local_array[svp_simple_017_001_global_var] = i++;
  }

  pthread_join(t1, 0);
  for(i = 0; i < 10; i++){
      assert(svp_simple_017_001_local_array[i] == i);
  }
  return 0;
}

