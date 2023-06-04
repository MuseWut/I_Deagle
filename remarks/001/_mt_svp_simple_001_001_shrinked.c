typedef unsigned long int pthread_t;

int svp_simple_001_001_global_var;          // var#1
int svp_simple_001_001_global_array[10];    // array#1
int svp_simple_001_001_global_flag = 0;     // flag#1
int reader1;                                // reader1#1
int reader3;                                // reader3#1

int a = 0;


void *svp_simple_001_001_isr_1(void *arg) {

  svp_simple_001_001_global_flag = 1;   // flag#3

  svp_simple_001_001_global_var = 0;    //var#3
  svp_simple_001_001_global_var = 1;    //var#4

}

void *svp_simple_001_001_isr_2(void *arg) {
    if (svp_simple_001_001_global_flag == 1){
      reader1 = svp_simple_001_001_global_array[9]; // reader1#3
      a = 1;
  }
  else
    reader1 = svp_simple_001_001_global_array[0];   // reader1#4

  reader3 = svp_simple_001_001_global_array[5];     // reader3#2

  int reader2;
  reader2 = svp_simple_001_001_global_var;
}


int main(){
  pthread_t t0, t1;
  pthread_create(&t0, 0, svp_simple_001_001_isr_1, 0);
  pthread_create(&t1, 0, svp_simple_001_001_isr_2, 0);

  for (int i = 0; i < 10; i++){
      svp_simple_001_001_global_array[i] = 0;   // array#3#5#7#9#11#13#15#17#19#21
      if(i == 9){
          assert(a == 0);
          a = 0;
      }
  }

  for (int i = 0; i < 10; i++)
      if (i == 9){
          svp_simple_001_001_global_array[i] = 1;   // array#23
          assert(a == 0);
          a = 0;
      }

  return 0;
}

// errror: W#39 R#21 W#43
