/* 
 * CS:APP Data Lab 
 * 
 * <Please put your name and userid here>
 * 黄靖修 26303050101
 * bits.c - Source file with your solutions to the Lab.
 *          This is the file you will hand in to your instructor.
 *
 * WARNING: Do not include the <stdio.h> header; it confuses the dlc
 * compiler. You can still use printf for debugging without including
 * <stdio.h>, although you might get a compiler warning. In general,
 * it's not good practice to ignore compiler warnings, but in this
 * case it's OK.  
 */

#if 0
/*
 * Instructions to Students:
 *
 * STEP 1: Read the following instructions carefully.
 */

You will provide your solution to the Data Lab by
editing the collection of functions in this source file.

INTEGER CODING RULES:

  Replace the "return" statement in each function with one
  or more lines of C code that implements the function. Your code 
  must conform to the following style:
 
  int Funct(arg1, arg2, ...) {
      /* brief description of how your implementation works */
      int var1 = Expr1;
      ...
      int varM = ExprM;

      varJ = ExprJ;
      ...
      varN = ExprN;
      return ExprR;
  }

  Each "Expr" is an expression using ONLY the following:
  1. Integer constants 0 through 255 (0xFF), inclusive. You are
      not allowed to use big constants such as 0xffffffff.
  2. Function arguments and local variables (no global variables).
  3. Unary integer operations ! ~
  4. Binary integer operations & ^ | + << >>
    
  Some of the problems restrict the set of allowed operators even further.
  Each "Expr" may consist of multiple operators. You are not restricted to
  one operator per line.

  You are expressly forbidden to:
  1. Use any control constructs such as if, do, while, for, switch, etc.
  2. Define or use any macros.
  3. Define any additional functions in this file.
  4. Call any functions.
  5. Use any other operations, such as &&, ||, -, or ?:
  6. Use any form of casting.
  7. Use any data type other than int.  This implies that you
     cannot use arrays, structs, or unions.

 
  You may assume that your machine:
  1. Uses 2s complement, 32-bit representations of integers.
  2. Performs right shifts arithmetically.
  3. Has unpredictable behavior when shifting if the shift amount
     is less than 0 or greater than 31.
  4. Interprets integer expressions using the Data Lab 32-bit bit-vector
     model: results outside the signed range retain their low 32 bits.


EXAMPLES OF ACCEPTABLE CODING STYLE:
  /*
   * pow2plus1 - returns 2^x + 1, where 0 <= x <= 31
   */
  int pow2plus1(int x) {
     /* exploit ability of shifts to compute powers of 2 */
     return (1 << x) + 1;
  }

  /*
   * pow2plus4 - returns 2^x + 4, where 0 <= x <= 31
   */
  int pow2plus4(int x) {
     /* exploit ability of shifts to compute powers of 2 */
     int result = (1 << x);
     result += 4;
     return result;
  }

FLOATING POINT CODING RULES

For the problems that require you to implement floating-point operations,
the coding rules are less strict.  You are allowed to use looping and
conditional control.  You are allowed to use both ints and unsigneds.
You can use arbitrary integer and unsigned constants. You can use any arithmetic,
logical, or comparison operations on int or unsigned data.

You are expressly forbidden to:
  1. Define or use any macros.
  2. Define any additional functions in this file.
  3. Call any functions.
  4. Use any form of casting.
  5. Use any data type other than int or unsigned.  This means that you
     cannot use arrays, structs, or unions.
  6. Use any floating point data types, operations, or constants.


NOTES:
  1. Use the dlc (data lab checker) compiler (described in the handout) to 
     check the legality of your solutions.
  2. Each function has a maximum number of operations (integer, logical,
     or comparison) that you are allowed to use for your implementation
     of the function.  The max operator count is checked by dlc.
     Note that assignment ('=') is not counted; you may use as many of
     these as you want without penalty.
  3. Use the btest test harness to check your functions for correctness.
  4. Use the BDD checker to formally verify your functions
  5. The maximum number of ops for each function is given in the
     header comment for each function. If there are any inconsistencies 
     between the maximum ops in the writeup and in this file, consider
     this file the authoritative source.

/*
 * STEP 2: Modify the following functions according the coding rules.
 * 
 *   IMPORTANT. TO AVOID GRADING SURPRISES:
 *   1. Use the dlc compiler to check that your solutions conform
 *      to the coding rules.
 *   2. Use the BDD checker to formally verify that your solutions produce 
 *      the correct answers.
 */


#endif
#include "bits.h"

// P1
/* 
 * signMask - return a mask with only the most significant bit set (0x80000000)
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 2
 *   Rating: 1
 */
int signMask(void) {
  return 1<<31;
}
  
// P2
/* 
 * bitXor - x^y using only ~ and & 
 *   Example: bitXor(4, 5) = 1, bitXor(7, 7) = 0
 *   Legal ops: ~ &
 *   Max ops: 8
 *   Rating: 2
 */
int bitXor(int x, int y) {
	return ~(~x & ~y) & ~(x & y);
}

// P3
/*
 * negativePart - return -x if x < 0, otherwise return 0
 *   Examples: negativePart(-10) = 10, negativePart(5) = 0
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 6
 *   Rating: 3
 */
int negativePart(int x){
  return (x >>31) & (~x +1);
}


// P4
/*
 * copyByteWithin - copy byte src of x to byte dst, leaving all other bytes unchanged
 *   Bytes are numbered from 0 (least significant) to 3 (most significant).
 *   You can assume 0 <= src <= 3 and 0 <= dst <= 3.
 *   Example: copyByteWithin(0x11223344, 0, 2) = 0x11443344
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 12
 *   Rating: 4
 */
int copyByteWithin(int x, int src, int dst) {
  return (x & ~(0xFF <<(dst << 3))) | (((x >> (src << 3)) & 0xFF) << (dst << 3));
}

// P5
/* 
 * logicalShift - shift x to the right by n bits, using a logical shift
 *   Can assume that 0 <= n <= 31
 *   Examples: logicalShift(0x87654321,4) = 0x08765432
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 20
 *   Rating: 4
 */
int logicalShift(int x, int n) {
  return (x >> n) & ~(((1 << 31) >> n) << 1);
}

// P6
/*
 * swapNibblePairs - swap the low and high 4 bits within each byte of x
 *   Examples: swapNibblePairs(0xAB) = 0xBA
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 18
 *   Rating: 4
 */
int swapNibblePairs(int x) {
 int mask = 0x0F;
  mask = mask | (mask << 8);
  mask = mask | (mask << 16);
  return ((x >> 4) & mask) | ((x & mask) << 4);
}

// P7
/*
 * secondLowestZeroBit - return a mask that marks the position of the second least significant 0 bit
 *   Examples: secondLowestZeroBit(0xFFFFFFFA) = 0x4, secondLowestZeroBit(0x7FFFFFFF) = 0
 *             secondLowestZeroBit(-1) = 0
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 8
 *   Rating: 4
 */
int secondLowestZeroBit(int x) {
 int y = ~x;
  int lowest_1 = y & (~y + 1);
  int y2 = y ^ lowest_1;
  return y2 & (~y2 + 1);
}


// P8
/*
 * oddParity - return the odd parity bit of x, that is,
 *      when the number of 1s in the binary representation of x is even, then the return 1, otherwise return 0.
 *   Examples: oddParity(5) = 1, oddParity(7) = 0
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 56
 *   Rating: 5
 */
int oddParity(int x) {
  x = x ^ (x >> 16);
  x = x ^ (x >> 8);
  x = x ^ (x >> 4);
  x = x ^ (x >> 2);
  x = x ^ (x >> 1);
  return !(x & 1);
}

// P9
/* 
 * rotateRightBits - rotate x to right by n bits
 *   you can assume n >= 0
 *   Examples: rotateRightBits(0x12345678, 8) = 0x78123456
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 16
 *   Rating: 5
 */
int rotateRightBits(int x, int n) {
  int logical_shift = (x >> n) & ~(((1 << 31) >> n) << 1);
  int wrap_around = x << (32 + (~n + 1));
  return logical_shift | wrap_around;
}

// P10
/*
 * roundEvenPow2 - round nonnegative x to the nearest multiple of 2^n.
 *   If x is exactly halfway between two multiples, choose the multiple whose
 *   quotient by 2^n is even.
 *   You can assume 0 <= x <= 0x3fffffff and 1 <= n <= 16.
 *   Examples: roundEvenPow2(10, 2) = 8, roundEvenPow2(14, 2) = 16
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 24
 *   Rating: 5
 */
int roundEvenPow2(int x, int n) {
  int shifted = x >> n;
  int mask = (1 << n) + ~0;
  int half_minus_one = mask >> 1;
  int round_bias = half_minus_one + (shifted & 1);
  return ((x + round_bias) >> n) << n;
}

// P11
/* 
 * midpointTowardFirst - return the exact mathematical midpoint (x+y)/2
 *   without overflow. If the exact midpoint lies halfway between two
 *   integers, choose the adjacent integer that is closer to the first
 *   argument x.
 *   Examples: midpointTowardFirst(4, 7) = 5,
 *             midpointTowardFirst(7, 4) = 6
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 32
 *   Rating: 5
 */
int midpointTowardFirst(int x, int y) {
  int average = (x & y) + ((x ^ y) >> 1);
  
  int sign_x = x >> 31;
  int sign_y = y >> 31;
  int diff = x + ~y + 1; 
  int sign_diff = diff >> 31;
  int signs_differ = sign_x ^ sign_y;
  
  int x_gt_y_true = ((~signs_differ) & (~sign_diff)) | (signs_differ & (~sign_x));
  
  int bias = ((x ^ y) & 1) & x_gt_y_true;
  
  return average + bias;
}


// P12
/* 
 * isBetweenEitherOrder - return 1 when x lies in the inclusive interval whose
 *   endpoints are a and b. The endpoints may be given in either order.
 *   Example: isBetweenEitherOrder(5, 8, 3) = 1.
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 48
 *   Rating: 7
 */
int isBetweenEitherOrder(int x, int a, int b) {
  int sa = a >> 31;
  int sb = b >> 31;
  int diff_ab = a + ~b + 1;
  int a_lt_b = (diff_ab ^ ((sa ^ sb) & (diff_ab ^ a))) >> 31;

  int min = (a & a_lt_b) | (b & ~a_lt_b);
  int max = a ^ b ^ min;

  int sx = x >> 31;
  
  int smin = min >> 31;
  int same_min = ~(smin ^ sx);
  int diff_min = min + ~x + 1;
  int sd_min = diff_min >> 31;
  int min_le_x = (same_min & (sd_min | !(min ^ x))) | (~same_min & smin);

  int smax = max >> 31;
  int same_max = ~(sx ^ smax);
  int diff_max = x + ~max + 1;
  int sd_max = diff_max >> 31;
  int x_le_max = (same_max & (sd_max | !(x ^ max))) | (~same_max & sx);

  return (min_le_x & x_le_max) & 1;
}
// P13
/* 
 * mul5Sat - return x*5, and if x*5 overflow, change the result to 
 * INT_MAX(0x7fffffff) or INT_MIN(0x80000000) correspondingly
 *   Examples: mul5Sat(1) = 0x5, mul5Sat(0x40000000) = 0x7fffffff
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 30
 *   Rating: 7
 */
 int mul5Sat(int x) {
  int xX = x >> 31;
  int a  = x << 1;
  int b  = x << 2;
  int ans = x + b;
  
  int aIf   = (a >> 31) ^ xX;
  int bIf   = (b >> 31) ^ xX;
  int ansIf = (ans >> 31) ^ xX;
  int keyIf = aIf | bIf | ansIf;
  
  int initmin = 1 << 31;
  int initmax = ~initmin; 
  return (ans & ~keyIf) + ((~xX) & keyIf & initmax) + (xX & keyIf & initmin);
}
// P14
/* 
 * classifyAdd3 - classify the exact mathematical sum x+y+z.
 *   Return 1 if the sum is greater than INT_MAX, -1 if it is less than
 *   INT_MIN, and 0 otherwise. You may not use a wider integer type.
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 52
 *   Rating: 7
 */
int classifyAdd3(int x, int y, int z) {
  int s1 = x + y;
  int s2 = s1 + z;
  
  int pos1 = (~(x >> 31)) & (~(y >> 31)) & (s1 >> 31);
  int neg1 = (x >> 31) & (y >> 31) & ~(s1 >> 31);
  
  int pos2 = (~(s1 >> 31)) & (~(z >> 31)) & (s2 >> 31);
  int neg2 = (s1 >> 31) & (z >> 31) & ~(s2 >> 31);
  
  int pos = pos1 | pos2;
  int neg = neg1 | neg2;
  
  int cancel = (pos1 & neg2) | (neg1 & pos2);
  int pos_final = pos & ~cancel;
  int neg_final = neg & ~cancel;
  
  return (pos_final & 1) | neg_final;
}
// P15
/*
 * floatScaleThreeHalves - Return bit-level equivalent of expression f*3/2 for
 *   floating point argument f.
 *   Both the argument and result are passed as unsigned int's, but
 *   they are to be interpreted as the bit-level representation of
 *   single-precision floating point values.
 *   Use round-to-nearest-even. Preserve the sign of both +0 and -0.
 *   When argument is NaN, return argument.
 *   Legal ops: Any integer / unsigned operations incl. ||, &&. also if, while
 *   Max ops: 60
 *   Rating: 7
 */
unsigned floatScaleThreeHalves(unsigned uf) {
  unsigned sign = uf & 0x80000000;
  unsigned exp = (uf >> 23) & 0xFF;
  unsigned frac = uf & 0x007FFFFF;

  if (exp == 0xFF) return uf;
  if (exp == 0 && frac == 0) return uf;

  unsigned new_e;
  unsigned m_norm;

  if (exp == 0) {
    unsigned m3 = frac + (frac << 1);
    unsigned rem = m3 & 1;           
    m_norm = m3 >> 1;
    if (rem && (m_norm & 1)) m_norm++;
    
    if (m_norm & (1 << 23)) {
      new_e = 1;
      m_norm &= ~(1 << 23);
    } else {
      new_e = 0;
    }
  } else {
    unsigned m = (1 << 23) | frac;
    unsigned m3 = m + (m << 1);
    
    int shift = 0;
    if (m3 & (1 << 24)) shift = 1;
    if (m3 & (1 << 25)) shift = 2;
    
    unsigned rem = m3 & ((1 << shift) - 1);
    m_norm = m3 >> shift;
    
    if (shift > 0) {
      unsigned half = 1 << (shift - 1);
      if (rem > half || (rem == half && (m_norm & 1))) {
        m_norm++;
      }
    }
    
    if (m_norm & (1 << 24)) {
      m_norm >>= 1;
      shift++;
    }
    
    new_e = exp + shift - 1;
  }

  if (new_e >= 255) return sign | 0x7F800000;
  return sign | (new_e << 23) | (m_norm & 0x007FFFFF);
}
// P16
/* 
 * floatRoundEven - round the floating-point value represented by uf to the
 *   nearest integer, with halfway cases rounded to the even integer. Return
 *   the bit-level representation of that integer as a single-precision float.
 *   If rounding produces zero, preserve the input sign; thus a negative
 *   value that rounds to zero returns -0. When uf is NaN or infinity,
 *   return uf unchanged.
 *   Legal ops: Any integer / unsigned operations incl. ||, &&. also if, while
 *   Max ops: 65
 *   Rating: 10
 */
unsigned floatRoundEven(unsigned uf) {
  unsigned sign = uf & 0x80000000;
  unsigned exp = (uf >> 23) & 0xFF;
  unsigned frac = uf & 0x007FFFFF;

  if (exp == 0xFF) return uf;

  if (exp < 126) return sign;

  if (exp == 126) { 
    if (frac == 0) return sign;
    return sign | 0x3f800000;
  }

  if (exp >= 150) return uf;

  int E = exp - 127;
  int n = 23 - E;

  unsigned int_part = (1 << E) | (frac >> n);
  unsigned frac_part = frac & ((1 << n) - 1);
  unsigned half = 1 << (n - 1);
  if (frac_part > half || (frac_part == half && (int_part & 1))) {
    int_part++;
  }

  int p = 0;
  unsigned temp = int_part;
  if (temp >= (1 << 16)) { p += 16; temp >>= 16; }
  if (temp >= (1 << 8)) { p += 8; temp >>= 8; }
  if (temp >= (1 << 4)) { p += 4; temp >>= 4; }
  if (temp >= (1 << 2)) { p += 2; temp >>= 2; }
  if (temp >= (1 << 1)) { p += 1; }

  unsigned exp_new = 127 + p;
  unsigned frac_new = (int_part << (23 - p)) & 0x007FFFFF;

  return sign | (exp_new << 23) | frac_new;
}

// P17
/*
 * float_i2f - Return bit-level equivalent of expression (float) x.
 *   Result is returned as unsigned int, but
 *   it is to be interpreted as the bit-level representation of a
 *   single-precision floating point values.
 *   Legal ops: Any integer / unsigned operations incl. ||, &&. also if, while
 *   Max ops: 40
 *   Rating: 10
 */
unsigned float_i2f(int x) {
  if (x == 0) return 0;

  unsigned sign = 0;
  unsigned ux = x;
  if (x < 0) {
    sign = 0x80000000;
    ux = -x;
  }

  int E = 31;
  while (!(ux & (1 << E))) E--;

  unsigned exp = E + 127;
  unsigned frac = 0;

  if (E <= 23) {
    frac = (ux << (23 - E)) & 0x7FFFFF;
  } else {
    int shift = E - 23;
    frac = (ux >> shift) & 0x7FFFFF;
    
    int drop = ux & ((1 << shift) - 1);
    int half = 1 << (shift - 1);
    
    if (drop > half || (drop == half && (frac & 1))) {
      frac++;
      if (frac & (1 << 23)) {
        frac = 0;
        exp++;
      }
    }
  }

  return sign | (exp << 23) | frac;
}



// P18
/*
 * bitCount - return count of number of 1's in the binary representation of x
 *   Examples: bitCount(5) = 2, bitCount(7) = 3
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 40
 *   Rating: 10
 */
int bitCount(int x) {
  int m1 = 0x55; m1 = m1 | (m1 << 8); m1 = m1 | (m1 << 16);
  int m2 = 0x33; m2 = m2 | (m2 << 8); m2 = m2 | (m2 << 16);
  int m4 = 0x0F; m4 = m4 | (m4 << 8); m4 = m4 | (m4 << 16);
  int m8 = 0xFF; m8 = m8 | (m8 << 16);
  int m16 = 0xFF; m16 = m16 | (m16 << 8);

  x = (x & m1) + ((x >> 1) & m1);
  x = (x & m2) + ((x >> 2) & m2);
  x = (x & m4) + ((x >> 4) & m4);
  x = (x & m8) + ((x >> 8) & m8);
  x = (x & m16) + ((x >> 16) & m16);
  return x;
}

// P19
/*
 * bitReverse - Reverse bits in an 32-bit integer
 *   Examples: bitReverse(0x80000004) = 0x20000001
 *             bitReverse(0x7FFFFFFF) = 0xFFFFFFFE
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 34
 *   Rating: 10
 */
  int bitReverse(int x) {
  int m8 = 0xFF; m8 = m8 | (m8 << 16); // 0x00FF00FF
  int m4 = m8 ^ (m8 << 4); // 0x0F0F0F0F
  int m2 = m4 ^ (m4 << 2); // 0x33333333
  int m1 = m2 ^ (m2 << 1); // 0x55555555
  int m16 = 0xFF; m16 = m16 | (m16 << 8); // 0xFFFF

  x = ((x & m1) << 1) | ((x >> 1) & m1);
  x = ((x & m2) << 2) | ((x >> 2) & m2);
  x = ((x & m4) << 4) | ((x >> 4) & m4);
  x = ((x & m8) << 8) | ((x >> 8) & m8);
  x = (x << 16) | ((x >> 16) & m16);
  return x;
}