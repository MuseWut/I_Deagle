extern void __VERIFIER_error() __attribute__ ((__noreturn__));
void assert(int expression) { if (!expression) { ERROR: __VERIFIER_error();}; return; }
typedef unsigned long int pthread_t;

//error: svp_simple_010_001_global_union.header<W#40>,<R#24>,<W#41>

typedef union pack1 {
   char header;
   int data;
} svp_simple_010_001_union;

typedef struct pack2 {
   char header;
   int data;
} svp_simple_010_001_struct;

volatile svp_simple_010_001_union svp_simple_010_001_global_union;
volatile svp_simple_010_001_struct svp_simple_010_001_global_struct;

int reader1, reader2;

void *svp_simple_010_001_isr_1(void *arg) {

  reader1 = svp_simple_010_001_global_union.header;

  reader2 = svp_simple_010_001_global_struct.header;
}


int main(){
  pthread_t t1;
  pthread_create(&t1, 0, svp_simple_010_001_isr_1, 0);

    int svp_simple_010_001_local_var1 = 0x01;
    int svp_simple_010_001_local_var2 = 0x02;

    int svp_simple_010_001_local_var3 = 0x03;
    int svp_simple_010_001_local_var4 = 0x04;

    svp_simple_010_001_global_union.header = svp_simple_010_001_local_var1;
    svp_simple_010_001_global_union.data = svp_simple_010_001_local_var2;

    svp_simple_010_001_global_struct.header = svp_simple_010_001_local_var3;
    svp_simple_010_001_global_struct.data = svp_simple_010_001_local_var4;

    pthread_join(t1, 0);
    assert(reader1 != 0x01 || svp_simple_010_001_global_union.data != 0x02);
    return 0;
}
