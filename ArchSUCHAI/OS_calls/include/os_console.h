#ifndef OS_CONSOLE_H
#define OS_CONSOLE_H

#if(SCH_TARGET_ARCH == 0)
    #include"../Arch/posix/p_console.h"
#elif(SCH_TARGET_ARCH == 1)
    #include"Arch/freertos/console.h"
#endif

#endif