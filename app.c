#include <libopencm3/stm32/rcc.h>
#include <libopencm3/stm32/gpio.h>

/* Set STM32 to 168 MHz. */
static void clock_setup(void)
{
    rcc_clock_setup_hse_3v3(&rcc_hse_8mhz_3v3[RCC_CLOCK_3V3_168MHZ]);

    /* Enable GPIOG clock. */
    rcc_periph_clock_enable(RCC_GPIOG);
}

static void gpio_setup(void)
{
    /* Set GPIO13-14 (in GPIO port G) to 'output push-pull'. */
    gpio_mode_setup(GPIOG, GPIO_MODE_OUTPUT,
            GPIO_PUPD_NONE, GPIO13 | GPIO14);
}

int main(void)
{
    int i;

    clock_setup();
    gpio_setup();

    /* Set two LEDs for wigwag effect when toggling. */
    gpio_set(GPIOG, GPIO13);

    /* Blink the LEDs (PG13 and PG14) on the board. */
    while (1) {
        /* Toggle LEDs. */
        gpio_toggle(GPIOG, GPIO13 | GPIO14);
        for (i = 0; i < 8000000; i++) { /* Wait a bit. */
            __asm__("nop");
        }
    }

    return 0;
}
