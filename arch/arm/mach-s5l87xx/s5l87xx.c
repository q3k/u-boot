#include <init.h>
#include <asm/io.h>

struct s5l87xx_clkgates {
    uint32_t gates0;
    uint32_t gates4;
    uint32_t gates8;
    uint32_t gates12;
    uint32_t gates16;
    uint32_t gates20;
    uint32_t gates24;
    uint32_t gates28;
    uint32_t gates32;
    uint32_t gates36;
};

struct s5l87xx_uart {
    uint32_t ulcon;    // 0x00
    uint32_t ucon;     // 0x04
    uint32_t ufcon;    // 0x08
    uint32_t pad1;     // 0x0c
    uint32_t utrstat;  // 0x10
    uint32_t pad2[3];  // 0x14
    uint32_t utxh;     // 0x20
    uint32_t pad3;     // 0x24
    uint32_t ubrdiv;   // 0x28
    uint32_t pad4[2];  // 0x2c
    uint32_t ubrconrx; // 0x34
    uint32_t ubrcontx; // 0x38
};

#ifdef CONFIG_DEBUG_UART_BOARD_INIT
void board_debug_uart_init(void)
{
    // Enable GPIO pins on N5G.
    static volatile uint32_t *gpio = (uint32_t *)0x3cf00000;
    *gpio &= 0xff00ffff;
    *gpio |= 0x00220000;

}

// TODO(q3k): move this to serial driver

//#include <debug_uart.h>
//static inline void _debug_uart_init(void)
//{
//    // TODO(q3k): only enable needed gates
//    static volatile struct s5l87xx_clkgates * const gates = (void *)0x3C500048;
//    gates->gates0 = 0;
//    gates->gates4 = 0;
//    gates->gates16 = 0;
//    gates->gates32 = 0;
//    gates->gates36 = 0;
//
//    static volatile struct s5l87xx_uart * const uart = (void *)0x3CC00000;
//    uart->ulcon = 0;
//    uart->utrstat = 0xffffffff;
//    uart->ufcon = 0x1 | 0x4 | 0x2;
//    uart->ucon = 0x400;
//    uart->ulcon = 3;
//    uart->ubrdiv = 76;
//    uart->ubrconrx = 0xffffff;
//    uart->ubrcontx = 0xffffff;
//    uart->ucon = (1 << 2);
//}
//
//static inline void _debug_uart_putc(int ch)
//{
//    static volatile struct s5l87xx_uart * const uart = (void *)0x3CC00000;
//    while ((uart->utrstat & 2) == 0) {}
//    uart->utxh = ch & 0xff;
//}
//
//DEBUG_UART_FUNCS
#endif
