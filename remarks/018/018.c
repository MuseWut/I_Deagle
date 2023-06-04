extern void __VERIFIER_error() __attribute__ ((__noreturn__));
void assert(int expression) { if (!expression) { ERROR: __VERIFIER_error();}; return; }
typedef unsigned long int pthread_t;

//bug点:
//1.svp_simple_018_001_para1<R#21>,<W#40>,<R#28>
//2.svp_simple_018_001_para2<R#22>,<W#35>,<R#29> ok
//3.svp_simple_018_001_para2<R#29>,<W#35>,<R#30> error

float svp_simple_018_001_func1();

float svp_simple_018_001_func2();

void svp_simple_018_001_isr_func1();

volatile float svp_simple_018_001_para1 = 1.0;
volatile float svp_simple_018_001_para2 = 1.0;

float svp_simple_018_001_func1() {
  float perimete = 0.0;
  perimete = 2 * svp_simple_018_001_para1 *
             svp_simple_018_001_para2;
  return perimete;
}

float svp_simple_018_001_func2() {
  float area = 0.0;
  area = svp_simple_018_001_para1 *
         svp_simple_018_001_para2 *
         svp_simple_018_001_para2;
  return area;
}

void svp_simple_018_001_isr_func1() {
  svp_simple_018_001_para2 = 1.5;
}

void *svp_simple_018_001_isr_1(void *arg) {
  idlerun();
  svp_simple_018_001_para1 = 2.0;
}

void *svp_simple_018_001_isr_2(void *arg) {
  idlerun();
  svp_simple_018_001_isr_func1();
}

int main(){
  pthread_t t1, t2;
  pthread_create(&t1, 0, svp_simple_018_001_isr_1, 0);
  pthread_create(&t2, 0, svp_simple_018_001_isr_2, 0);

  float svp_simple_018_001_perimete = 0;
  float svp_simple_018_001_area = 0;
  svp_simple_018_001_perimete = svp_simple_018_001_func1();
  svp_simple_018_001_area = svp_simple_018_001_func2();

  pthread_join(t1, 0);
  pthread_join(t2, 0);

  assert(svp_simple_018_001_perimete != (2*2.0*1.0) || svp_simple_018_001_area !=(2.0*1.5*1.5));
  return 0;
}
