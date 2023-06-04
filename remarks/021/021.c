extern void __VERIFIER_error() __attribute__ ((__noreturn__));
void assert(int expression) { if (!expression) { ERROR: __VERIFIER_error();}; return; }
typedef unsigned long int pthread_t;

// bug点：
// 1.svp_simple_021_001_tc_block_rcvd_bytes_ch1 <R,#36>, <W,#48>, <W,#37>
// 2.svp_simple_021_001_tc_block_rcvd_bytes_ch1 <W,#37>, <W,#48>, <R,#68>
// 3.svp_simple_021_001_tc_block_rcvd_bytes_ch1 <R,#36>, <W,#48>, <R,#68>

//#define svp_simple_021_001_CNT (volatile unsigned int *)0x10000000

volatile unsigned16 svp_simple_021_001_tc_block_rcvd_bytes_ch1;
volatile unsigned16 svp_simple_021_001_tc_block_rcvd_bytes_ch2;
volatile unsigned16 svp_simple_021_001_tc_block_rcvd_bytes;
volatile unsigned8 svp_simple_021_001_tc_chan1_buff[256];
volatile unsigned8 svp_simple_021_001_tc_chan2_buff[256];
volatile unsigned8 *svp_simple_021_001_tc_buff_p;

struct svp_simple_021_001_tc_block_data {
  unsigned8 type;
  unsigned8 id;
  unsigned8 valid_len;
};

void svp_simple_021_001_init() {
  svp_simple_021_001_tc_block_rcvd_bytes_ch1 = rand();  
  svp_simple_021_001_tc_block_rcvd_bytes_ch2 = rand();

  init();
}

void svp_simple_021_001_RecvTcBlock() {
  unsigned svp_simple_021_001_flag_chan1;
  svp_simple_021_001_flag_chan1 = 0;

  if (svp_simple_021_001_tc_block_rcvd_bytes_ch1 >= 16) { 
    svp_simple_021_001_tc_block_rcvd_bytes_ch1 = 0;    
    int i;
    for (i = 0; i < 256; i++) {
      svp_simple_021_001_tc_chan1_buff[i] = 0;
    }
    svp_simple_021_001_flag_chan1 = 0xFF;
  }
}


void *svp_simple_021_001_isr_1(void *arg) {
  svp_simple_021_001_tc_block_rcvd_bytes_ch1 =
      (*(0x10000000) >> 3) & 0x1FFF;
}


int main(){
  pthread_t t0, t1, t2, t3;
  pthread_create(&t1, 0, svp_simple_021_001_isr_1, 0);

    struct svp_simple_021_001_tc_block_data tc_block;

    svp_simple_021_001_init();

    svp_simple_021_001_RecvTcBlock();

    int ichan;
    for (ichan = 0; ichan < 2; ichan++) {
        if (ichan == 0) {
            svp_simple_021_001_tc_buff_p = svp_simple_021_001_tc_chan1_buff;
            svp_simple_021_001_tc_block_rcvd_bytes =
                    svp_simple_021_001_tc_block_rcvd_bytes_ch1;
        } else {
            svp_simple_021_001_tc_buff_p = svp_simple_021_001_tc_chan2_buff;
            svp_simple_021_001_tc_block_rcvd_bytes =
                    svp_simple_021_001_tc_block_rcvd_bytes_ch2;
        }

        tc_block.type = *(svp_simple_021_001_tc_buff_p + 2);
        tc_block.id = *(svp_simple_021_001_tc_buff_p + 4);
        tc_block.valid_len = *(svp_simple_021_001_tc_buff_p + 5);
    }

    pthread_join(t1, 0);
    assert();
    return 0;
}
