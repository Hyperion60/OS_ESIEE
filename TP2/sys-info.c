#include <stdio.h>
#include <sys/sysinfo.h>


int main(void) {
    struct sysinfo my_sys;

    if (sysinfo(&my_sys) < 0)
        return 1;
    
    printf("Uptime : %ld secondes\n", my_sys.uptime);
    printf("Load average (last 1 min) : %.3f\n", (my_sys.loads[0] / 65536.0));
    printf("Load average (last 5 min) : %.3f\n", (my_sys.loads[1] / 65536.0));
    printf("Load average (last 15 min) : %.3f\n", (my_sys.loads[2] / 65536.0));
    printf("Total RAM : %ld bytes\n", my_sys.totalram);
    printf("Total free RAM : %ld bytes\n", my_sys.freeram);
    printf("Total shared RAM : %ld bytes\n", my_sys.sharedram);
    printf("Memory user by buffers : %ld bytes\n", my_sys.bufferram);
    printf("Total swap space size : %ld bytes\n", my_sys.totalswap);
    printf("Swap space still available : %ld bytes\n", my_sys.freeswap);
    printf("Number of current processes : %d\n", my_sys.procs);
    printf("Pads structure to 64 bytes :");
    for (int i = 0; i < 22; ++i)
        printf(" %02X", my_sys._f[i]);
    printf("\n");
}
