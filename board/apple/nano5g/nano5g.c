#include <common.h>
#include <asm/global_data.h>

DECLARE_GLOBAL_DATA_PTR;

int dram_init(void)
{
    // Just guessing for now.
    gd->ram_size = (32 << 10);
    return 0;
}

int board_init(void)
{
    return 0;
}

void reset_cpu(void)
{
}

ulong get_tbclk(void)
{
    // Just guessing for now.
    return 1000;
}