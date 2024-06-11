#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <unistd.h>

#define BUFFER_SIZE 16 * 163834

void process_adsb_data(uint8_t *buffer, int length){
  // Implement ADS-B decoding logic
  printf("Recieved data chunk of size %d\n", length);
  for(int i = 0; i < length; i++){
     printf("%02X ", buffer[i]);
  }
  printf("\n");
}

int main(){
 uint8_t buffer[BUFFER_SIZE];
 ssize_t len;

  while((len = read(STDIN_FILENO, buffer, BUFFER_SIZE)) > 0) {
    process_adsb_data(buffer, len);
  }

  if(len < 0) {
    perror("read");
    return EXIT_FAILURE;
  }

  return EXIT_SUCCESS;
}
