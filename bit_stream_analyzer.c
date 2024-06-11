#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <unistd.h>
#include <signal.h>

#define BUFFER_SIZE 16384  // 16KB
#define FRAME_SIZE 14 // ADS-B frame size is 14 bytes

// handle exit
volatile sig_atomic_t stop = 0;

void handle_sigint(int signum){
   stop = 1;
}

// right shift i to least significant bit mask using 1.
void print_bits(uint8_t byte) {
   for(int i = 7; i >= 0; i--){
      printf("%d", (byte >> i) & 1); 
   }
}

void analyze(uint8_t *buffer, int len){
  
   if(len <  FRAME_SIZE){
      return;
   }

   // extract downlink format (DF) from the first byte
   uint8_t df = (buffer[0] >> 3) & 0x1F; // first 5 bits
    
   if(df == 17){
   
      for(int i = 0; i < FRAME_SIZE; i++){
         printf("%02X", buffer[i]);
      }
      printf("\n");

      // print bits
      /*
      for(int i = 0; i < FRAME_SIZE; i++){
         print_bits(buffer[i]); // pass in each byte
         printf(" ");
      }
      printf("\n");
      */
   }
}

int main(){
   uint8_t buffer[BUFFER_SIZE];
   ssize_t len;
  
   while (!stop && (len = read(STDIN_FILENO, buffer, BUFFER_SIZE)) > 0){
     analyze(buffer, len);
   }
  // capture a single frame
  /* if((len = read(STDIN_FILENO, buffer, FRAME_SIZE)) > 0){
     analyze(buffer, len);
   }*/

   if(len < 0){
      perror("read");
      return EXIT_FAILURE;
   }
}
