extern void __VERIFIER_error() __attribute__ ((__noreturn__));
void assert(int expression) { if (!expression) { ERROR: __VERIFIER_error();}; return; }
typedef unsigned long int pthread_t;

//error: svp_simple_006_001_global_var1<R#30>,<W#17>,<R#32>

//#define MAX_LENGTH 10000
//#define TRIGGER 9999

volatile int svp_simple_006_001_global_var1 = 0x01;
volatile int svp_simple_006_001_global_var2;
volatile unsigned char flag = 0x55;
int reader1, reader2;

void *svp_simple_006_001_isr_1(void *arg) {

  svp_simple_006_001_global_var1 = 10;
  reader2 = svp_simple_006_001_global_var2;
}


int main(){
  pthread_t t0;
  pthread_create(&t0, 0, svp_simple_006_001_isr_1, 0);

    for (int i = 0; i < 5; i++)
        for (int j = 0; j < 5; j++) {
            if (i == j) {
                if (i == 0)
                    reader1 = svp_simple_006_001_global_var1;
                else if (i == 4)
                    reader2 = svp_simple_006_001_global_var1;
                else if (i == 6)
                    reader2 = svp_simple_006_001_global_var1;
            }
        }
    for (int i = 0; i < 5; i++)
        for (int j = 0; j < 5; j++) {
            if (((i + j) == 6) && (i < j))
                svp_simple_006_001_global_var2 = 0x02;
        }

    pthread_join(t0, 0);
    assert(reader2 != 10);
    return 0;
}
