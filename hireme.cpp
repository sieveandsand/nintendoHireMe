#include <string.h>
#include <cstdio>
#include <iostream>
#include <sstream>
#include <fstream>
#include <bitset>

#define DEBUG_PRINT
#define DEBUG_FILE
#define DEBUG_FILE_NAME             "debug.log"

template<typename... Args>
static void debug_print(Args... args) {
#ifdef DEBUG_PRINT
    std::stringstream ss;
    (ss << ... << args);
    std::cout << ss.str() << std::endl;
#endif // DEBUG_PRINT

#ifdef DEBUG_FILE
    std::ofstream file (DEBUG_FILE_NAME, std::ios::app);
    if (file.is_open()) {
        file << ss.str() << std::endl;
        file.close();
    } else {
        std::cerr << "Failed to open file" << std::endl;
    }
#endif // DEBUG_FILE
}



typedef unsigned char u8;
typedef unsigned int u32;

u8 confusion[512]={
0xac,0xd1,0x25,0x94,0x1f,0xb3,0x33,0x28,0x7c,0x2b,0x17,0xbc,0xf6,0xb0,0x55,0x5d,
0x8f,0xd2,0x48,0xd4,0xd3,0x78,0x62,0x1a,0x02,0xf2,0x01,0xc9,0xaa,0xf0,0x83,0x71,
0x72,0x4b,0x6a,0xe8,0xe9,0x42,0xc0,0x53,0x63,0x66,0x13,0x4a,0xc1,0x85,0xcf,0x0c,
0x24,0x76,0xa5,0x6e,0xd7,0xa1,0xec,0xc6,0x04,0xc2,0xa2,0x5c,0x81,0x92,0x6c,0xda,
0xc6,0x86,0xba,0x4d,0x39,0xa0,0x0e,0x8c,0x8a,0xd0,0xfe,0x59,0x96,0x49,0xe6,0xea,
0x69,0x30,0x52,0x1c,0xe0,0xb2,0x05,0x9b,0x10,0x03,0xa8,0x64,0x51,0x97,0x02,0x09,
0x8e,0xad,0xf7,0x36,0x47,0xab,0xce,0x7f,0x56,0xca,0x00,0xe3,0xed,0xf1,0x38,0xd8,
0x26,0x1c,0xdc,0x35,0x91,0x43,0x2c,0x74,0xb4,0x61,0x9d,0x5e,0xe9,0x4c,0xbf,0x77,
0x16,0x1e,0x21,0x1d,0x2d,0xa9,0x95,0xb8,0xc3,0x8d,0xf8,0xdb,0x34,0xe1,0x84,0xd6,
0x0b,0x23,0x4e,0xff,0x3c,0x54,0xa7,0x78,0xa4,0x89,0x33,0x6d,0xfb,0x79,0x27,0xc4,
0xf9,0x40,0x41,0xdf,0xc5,0x82,0x93,0xdd,0xa6,0xef,0xcd,0x8d,0xa3,0xae,0x7a,0xb6,
0x2f,0xfd,0xbd,0xe5,0x98,0x66,0xf3,0x4f,0x57,0x88,0x90,0x9c,0x0a,0x50,0xe7,0x15,
0x7b,0x58,0xbc,0x07,0x68,0x3a,0x5f,0xee,0x32,0x9f,0xeb,0xcc,0x18,0x8b,0xe2,0x57,
0xb7,0x49,0x37,0xde,0xf5,0x99,0x67,0x5b,0x3b,0xbb,0x3d,0xb5,0x2d,0x19,0x2e,0x0d,
0x93,0xfc,0x7e,0x06,0x08,0xbe,0x3f,0xd9,0x2a,0x70,0x9a,0xc8,0x7d,0xd8,0x46,0x65,
0x22,0xf4,0xb9,0xa2,0x6f,0x12,0x1b,0x14,0x45,0xc7,0x87,0x31,0x60,0x29,0xf7,0x73,
0x2c,0x97,0x72,0xcd,0x89,0xa6,0x88,0x4c,0xe8,0x83,0xeb,0x59,0xca,0x50,0x3f,0x27,
0x4e,0xae,0x43,0xd5,0x6e,0xd0,0x99,0x7b,0x7c,0x40,0x0c,0x52,0x86,0xc1,0x46,0x12,
0x5a,0x28,0xa8,0xbb,0xcb,0xf0,0x11,0x95,0x26,0x0d,0x34,0x66,0x22,0x18,0x6f,0x51,
0x9b,0x3b,0xda,0xec,0x5e,0x00,0x2a,0xf5,0x8f,0x61,0xba,0x96,0xb3,0xd1,0x30,0xdc,
0x33,0x75,0xe9,0x6d,0xc8,0xa1,0x3a,0x3e,0x5f,0x9d,0xfd,0xa9,0x31,0x9f,0xaa,0x85,
0x2f,0x92,0xaf,0x67,0x78,0xa5,0xab,0x03,0x21,0x4f,0xb9,0xad,0xfe,0xf3,0x42,0xfc,
0x17,0xd7,0xee,0xa3,0xd8,0x80,0x14,0x2e,0xa0,0x47,0x55,0xc4,0xff,0xe5,0x13,0x3f,
0x81,0xb6,0x7a,0x94,0xd0,0xb5,0x54,0xbf,0x91,0xa7,0x37,0xf1,0x6b,0xc9,0x1b,0xb1,
0x3c,0xb6,0xd9,0x32,0x24,0x8d,0xf2,0x82,0xb4,0xf9,0xdb,0x7d,0x44,0xfb,0x1e,0xd4,
0xea,0x5d,0x35,0x69,0x23,0x71,0x57,0x01,0x06,0xe4,0x55,0x9a,0xa4,0x58,0x56,0xc7,
0x4a,0x8c,0x8a,0xd6,0x6a,0x49,0x70,0xc5,0x8e,0x0a,0x62,0xdc,0x29,0x4b,0x42,0x41,
0xcb,0x2b,0xb7,0xce,0x08,0xa1,0x76,0x1d,0x1a,0xb8,0xe3,0xcc,0x7e,0x48,0x20,0xe6,
0xf8,0x45,0x93,0xde,0xc3,0x63,0x0f,0xb0,0xac,0x5c,0xba,0xdf,0x07,0x77,0xe7,0x4e,
0x1f,0x28,0x10,0x6c,0x59,0xd3,0xdd,0x2d,0x65,0x39,0xb2,0x74,0x84,0x3d,0xf4,0xbd,
0xc7,0x79,0x60,0x0b,0x4d,0x33,0x36,0x25,0xbc,0xe0,0x09,0xcf,0x5b,0xe2,0x38,0x9e,
0xc0,0xef,0xd2,0x16,0x05,0xbe,0x53,0xf7,0xc2,0xc6,0xa2,0x24,0x98,0x1c,0xad,0x04};

u32 diffusion[32]={
0xf26cb481,0x16a5dc92,0x3c5ba924,0x79b65248,0x2fc64b18,0x615acd29,0xc3b59a42,0x976b2584,
0x6cf281b4,0xa51692dc,0x5b3c24a9,0xb6794852,0xc62f184b,0x5a6129cd,0xb5c3429a,0x6b978425,
0xb481f26c,0xdc9216a5,0xa9243c5b,0x524879b6,0x4b182fc6,0xcd29615a,0x9a42c3b5,0x2584976b,
0x81b46cf2,0x92dca516,0x24a95b3c,0x4852b679,0x184bc62f,0x29cd5a61,0x429ab5c3,0x84256b97};

u8 input[32]={
//change only this :
0x66,0xd5,0x4e,0x28,0x5f,0xff,0x6b,0x53,0xac,0x3b,0x34,0x14,0xb5,0x3c,0xb2,0xc6,
0xa4,0x85,0x1e,0x0d,0x86,0xc7,0x4f,0xba,0x75,0x5e,0xcb,0xc3,0x6e,0x48,0x79,0x8f
//
};

unsigned char hire_me_text[32] = {0x48, 0x69, 0x72, 0x65, 0x20, 0x6d, 0x65, 0x48, 0x69, 0x72, 0x65, 0x20, 0x6d, 0x65, 0x48, 0x69, 0x72, 0x65, 0x20, 0x6d, 0x65, 0x48, 0x69, 0x72, 0x65, 0x20, 0x6d, 0x65, 0x48, 0x69, 0x72, 0x65};

// self xor self == 0
// self xor 0 == self
// a xor b = c, c xor b = a, c xor a = b



void Forward(u8 input[32],u8 output[32],u8 confusion[512],u32 diffusion[32])
{
    for(u32 i=0; i<256; i++)    // looks like 256 rounds of some kind of chained encryption
    {
        debug_print("Starting round ", std::to_string(i));

        for(u8 j=0; j<32; j++) // doing something for each of the 32 bytes
        {
            output[j]=confusion[input[j]]; // confusion step
            input[j]=0; // by the time we finish the first round input would be cleared to 0
        }

        u8 test = 0;

        for(u8 j=0; j<32; j++) { // go through the 32 bytes again 
            debug_print("Diffusion round ", std::to_string(j));

            u8 cons_xor_value = 0;
            u8 input_before_start = output[j];


            for(u8 k=0; k<32; k++) {
                debug_print("Current diffusion hex value: ", std::hex, diffusion[j], " using bit ", std::to_string((diffusion[j] >> k) & 1 ));
                debug_print("Value XORed is ", std::to_string(output[k] * ((diffusion[j] >> k) & 1 )));
                debug_print("input value into diffusion is ", std::hex, std::to_string(output[k]));
                cons_xor_value ^= output[k] * ((diffusion[j] >> k) & 1 );
                //result of entire confusion output * either 0 or one ... for every byte
                input[j] ^= output[k] * ((diffusion[j] >> k) & 1 ); // diffusion step we can keep track and pre-calculate

                // let's turn the scale down to just 5
                // result_byte = (output_0 * 0) ^ (output_1 * 1) ^ (output_2 * 1) ^ (output_3 * 0) ^ (output_4 * 1)
                // result_byte = output_1 ^ output_2 ^ output_4

                // to reverse we just XOR output_1 ^ output_2 ^ output_4 back!

                // pattern = 0, 1, 1, 0, 1 (we can pre calculate this)


                // here we can know all the values xored together

            }

            test ^= input[j];

            debug_print("Consecutive XOR value is ", std::to_string(cons_xor_value));
            debug_print("Value at input[j] is ", std::to_string(input[j]));
            debug_print("Value before start is ", std::to_string(input_before_start));
        }
        debug_print(std::hex, std::to_string(test));
        debug_print("End of round");
    }

    for(u8 i=0; i<16; i++)
        output[i]=confusion[input[i*2]] ^ confusion[input[i*2+1]+256]; // two bytes are xored together... kinda like a final hash to reduce the size?
}

void reverse(uint8_t target_string[16], uint8_t input[32]) {
    // reverse the process given
    // step 1. Reverse the last for loop
    //      all the possible pairs are confusion_index and confusion_index + 256
    //      go through all combinations

    // use dynamic programming to speed things up
    uint8_t final_confusion_dp[512/2];

    // fill up the dp
    for (int j = 0; j < 512/2; ++j) {
        uint8_t confusion_value = confusion[j] ^ confusion[j+256];
        final_confusion_dp[j] = confusion_value;
    }

    // reverse the last for loop
    for (int i = 0; i < 16; ++i) {
        for (int j = 0; j < 256; ++j) {
            if (target_string[i] == final_confusion_dp[j]) {
                input[i * 2] = confusion[j];
                input[i * 2 + 1] = confusion[j+256];
                break;
            }
        }
    }

    // break down the diffusion array

    // step 2. Reverse the diffusion step
    for (int i = 0; i < 256; ++i) {
        for (int j = 0; j < 32; ++j) {          // diffusion loop
            for (int k = 0; k < 32; ++k) {      // retrieving each of the diffusion element

            }
        }
    }

}

void print_xored_diffusion_array() {
    for (int i = 0; i < 32; ++i) {
        std::cout << "Diffusion element " << (i>9?"":" ") << i << ": ";
        for (int j = 0; j < 32; ++j) {
            if ((diffusion[i]>>j & 1) == 1) {
                std::cout << (j>9?"":" ") << j << ",";
            } else {
                std::cout << "  ,";
            }
        }
        std::cout << std::endl;
    }
}




/*
The solutions to this challenge belong to different levels :

Level 1 : an iterative algorithm which typically takes more than a second to
find a solution (for any given output). 

Most people stop here, which is fine, but if you want to go further, there is :

Level 2 : a non-iterative algorithm which typically takes less than a
millisecond to find a solution (for any given output).

Few people have reached this level. But if you want to beat it completely,
there's yet another castle...

Level 3 : an algorithm which can provide any of the 2^128 solutions (for any
given output).

Even fewer people have reached this final level. Congratulations to them!

*/

int main(int argc, char* argv[])
{
    u8 target[]="Hire me!!!!!!!!"; // 16 bytes
    u8 output[32];

    Forward(input,output,confusion,diffusion);
    for (int i = 0; i < 32; ++i) printf("%02x", output[i]);
    printf("\n");
    for (int i = 0; i < 16; ++i) printf("%c", output[i]);

    // uint8_t input[32];
    // reverse(target, input);
    // std::cout << std::endl;

    print_xored_diffusion_array();

    return memcmp(output,target,16); // => contact apply(at)nerd.nintendo.com
}