#include "../../CMSIS/Devices/stm32f4xx.h"
#include "../../CMSIS/Devices/stm32f429xx.h"
// #include "../../CMSIS/Device/system_stm32f1xx.h"

#define RCC_GPIOx                      (*(uint32_t*) (0x40021000UL + 0x18UL))           // Reset and clock control RCC
#define RCC_GPIOB_EN                   (0x08UL)                                         // Port B eneble

#define GPIOB_MODE_L                   (*(uint32_t*) (0x40010C00UL + 0x00UL))           // Port configuration register type
#define GPIOB_MODE_H                   (*(uint32_t*) (0x40010C00UL + 0x04UL))           // Port configuration register type
#define GPIOB_CRL                      (*(uint32_t*) (0x40010C00UL + 0x00UL))           // Port configuration register low
#define GPIOB_CRH                      (*(uint32_t*) (0x40010C00UL + 0x04UL))           // Port configuration register high
#define GPIOB_BSRR                     (*(uint32_t*) (0x40010C00UL + 0x10UL))           // Port bit set/reset register
#define GPIOB_IDR                      (*(uint32_t*) (0x40010C00UL + 0x08UL))           // Port input data register
#define GPIOB_ODR                      (*(uint32_t*) (0x40010C00UL + 0x0CUL))           // Port output data register

//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

#define GPIOB_MODE_PIN5_OUT1           (0x100000)                                       // Output mode, max speed 10 MHz
#define GPIOB_MODE_PIN7_OUT1           (0x10000000)                                     // Output mode, max speed 10 MHz
#define GPIOB_MODE_PIN9_OUT1           (0x10)                                           // Output mode, max speed 10 MHz
#define GPIOB_ODR_PIN10_PU             (0x400)                                           // Pull-up
#define GPIOB_ODR_PIN11_PU             (0x800)                                           // Pull-up
 
#define GPIOB_CNF_PIN5_PP              (0xC00000)                                       // General purpose output push-pull
#define GPIOB_CNF_PIN7_PP              (0xC0000000)                                     // General purpose output push-pull
#define GPIOB_CNF_PIN9_PP              (0xC0)                                           // General purpose output push-pull
#define GPIOB_CNF_PIN10_PUPD           (0xC00)                                          // Analog mode
#define GPIOB_CNF_PIN11_PUPD           (0xC000)                                         // Analog mode
#define GPIOB_CNF_PIN10_IN             (0x800)                                          // Input with pull-up / pull-down
#define GPIOB_CNF_PIN11_IN             (0x8000)                                         // Input with pull-up / pull-down

//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

#define GPIOB_IDR_PIN10                (0x400)                                          // Port B Read bit 0
#define GPIOB_IDR_PIN11                (0x800)                                          // Port B Read bit 1
 
#define GPIOB_BSRR_PIN5                (0x20)                                           // Port B Set bit 5
#define GPIOB_BSRR_PIN7                (0x80)                                           // Port B Set bit 7
#define GPIOB_BSRR_PIN9                (0x200)                                          // Port B Set bit 9

#define GPIOB_BRR_PIN5                 (GPIOB_BSRR_PIN5 << 16U)                         // Port B Reset bit 5
#define GPIOB_BRR_PIN7                 (GPIOB_BSRR_PIN7 << 16U)                         // Port B Reset bit 7
#define GPIOB_BRR_PIN9                 (GPIOB_BSRR_PIN9 << 16U)                         // Port B Reset bit 9


#define BIT_SET(REG, BIT)              (REG |= BIT)                                     // Set bit function
#define BIT_RESET(REG, BIT)            (REG &= ~BIT)                                    // Reset bit function
#define BIT_READ(REG, BIT)             (REG & BIT)                                      // Read bit function