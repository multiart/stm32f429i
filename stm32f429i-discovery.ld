/* Linker script for Nucleo F411RE  (STM32F411RE, 512K flash, 96K RAM). */

/* Define memory regions. */
MEMORY
{
    rom (rx) : ORIGIN = 0x08000000, LENGTH = 2048K
    ram (rwx) : ORIGIN = 0x20000000, LENGTH = 192K
}

/* Include the common ld script. */
INCLUDE libopencm3_stm32f4.ld
