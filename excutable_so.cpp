#include <stdio.h>
#include <unistd.h> // needed for the _exit() function
 
// Must define the interpretor to be the dynamic linker
#ifdef __LP64__
const char service_interp[] __attribute__((section(".interp"))) = "/lib/x86_64-linux-gnu/ld-linux-x86-64.so.2";
#else
const char service_interp[] __attribute__((section(".interp"))) = "/lib/ld-linux.so.2";
#endif
 
extern "C" {
     
void __lib_main(void)
{
    __asm__ __volatile__("andq $-16, %rsp");
    printf("Entry point of excutable_so.so \n");
 
    _exit(0);
}
 
}
