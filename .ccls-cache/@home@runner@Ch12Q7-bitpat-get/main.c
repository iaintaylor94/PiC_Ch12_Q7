// Program to extract bits from a bit string

#include <stdio.h>

// Declare Functions
int int_size (void);
unsigned int mask_create (int, int);
unsigned int bitpat_get (unsigned int, int, int);

int main(void) {

  unsigned int src = 0; src = mask_create (16, 8);
  unsigned int result = bitpat_get (src, 4, 16);
  printf ("bitMaskSource:   %#.32b\n", src);
  printf ("bitMaskExtract:  %#.32b\n", mask_create(4, 16));
  printf ("bitMaskResult:   %#.32b\n", result);
  
  return 0;
}

// Define Functions
int int_size (void) {
  unsigned int test = ~0; // All ones

  int i = 0;
  while (test != 0) {
    test >>= 1;
    i++;
  }

  return i;
}

unsigned int mask_create (int index, int length) {
  unsigned int bitMask = 0;
  for (int i = 0; i < length; i++) {
    bitMask <<= 1;
    bitMask++;
  }
  bitMask <<= int_size() - length;
  bitMask >>= index;
  return bitMask;
}

// Leftmost bit is "0" -- Rightmost bit is "int_size() - 1"
unsigned int bitpat_get (unsigned int source, int maskIndex, int maskLength) {
  unsigned int mask = 0; mask = mask_create (maskIndex, maskLength);
  
  return source & mask;
}