#include "init.h"
#include <stdint.h>

uint8_t but1 = 0;
uint8_t but2 = 0;
uint32_t led_pin = 1;
uint32_t led_mode = 1;

int main(void) {

  BIT_SET(RCC_GPIOx, RCC_GPIOB_EN);           // включение бита, отвечающего за включение тактирования на шине APB2 (Reset and clock control RCC)

  BIT_SET(GPIOB_CRL, GPIOB_MODE_PIN5_OUT1);   // режим порта MODE (Output mode, max speed 10 MHz) для PB5
  BIT_RESET(GPIOB_CRL, GPIOB_CNF_PIN5_PP);    // CNF в режим push-pull для PB5

  BIT_SET(GPIOB_CRL, GPIOB_MODE_PIN7_OUT1);   // режим порта MODE (Output mode, max speed 10 MHz) для PB7
  BIT_RESET(GPIOB_CRL, GPIOB_CNF_PIN7_PP);    // CNF в режим push-pull для PB7

  BIT_SET(GPIOB_CRH, GPIOB_MODE_PIN9_OUT1);   // режим порта MODE (Output mode, max speed 10 MHz) для PB9
  BIT_RESET(GPIOB_CRH, GPIOB_CNF_PIN9_PP);    // CNF в режим push-pull для PB9

  BIT_RESET(GPIOB_CRH, GPIOB_CNF_PIN10_PUPD); // Сброс битов CNF
  BIT_RESET(GPIOB_CRH, GPIOB_CNF_PIN11_PUPD);
  BIT_SET(GPIOB_CRH, GPIOB_CNF_PIN10_IN);     // Установка CNF 10
  BIT_SET(GPIOB_CRH, GPIOB_CNF_PIN11_IN);
  BIT_SET(GPIOB_ODR, GPIOB_ODR_PIN10_PU);     // Установка ODR регистра в 1 для pull up
  BIT_SET(GPIOB_ODR, GPIOB_ODR_PIN11_PU);

  while(1) {
    if(BIT_READ(GPIOB_IDR, GPIOB_IDR_PIN10) == 0) {         // button 1
      but1 = 1;
      for(int i = 0; i < 300000; i++) {}
      led_pin++;
      if(led_pin >= 4 || (led_mode == 3 && led_pin >=3)) {
        led_pin = 1;
      }
    }
    else {
      but1 = 0;
    }

    if(BIT_READ(GPIOB_IDR, GPIOB_IDR_PIN11) == 0) {         // button 2
      but2 = 1;
      for(int i = 0; i < 300000; i++) {}
      led_mode++;
      if(led_mode >= 4) {
        led_mode = 1;
      }
    }
    else {
      but2 = 0;
    }

    if(led_mode == 1) {
      if(led_pin == 1) {
        BIT_SET(GPIOB_BSRR, GPIOB_BSRR_PIN5);
        BIT_SET(GPIOB_BSRR, GPIOB_BRR_PIN7);
        BIT_SET(GPIOB_BSRR, GPIOB_BRR_PIN9);
      }
      else if(led_pin == 2) {
        BIT_SET(GPIOB_BSRR, GPIOB_BRR_PIN5);
        BIT_SET(GPIOB_BSRR, GPIOB_BSRR_PIN7);
        BIT_SET(GPIOB_BSRR, GPIOB_BRR_PIN9);
      }
      else if(led_pin == 3) {
        BIT_SET(GPIOB_BSRR, GPIOB_BRR_PIN5);
        BIT_SET(GPIOB_BSRR, GPIOB_BRR_PIN7);
        BIT_SET(GPIOB_BSRR, GPIOB_BSRR_PIN9);
      }
    }

    if(led_mode == 2) {
      if(led_pin == 1) {
        BIT_SET(GPIOB_BSRR, GPIOB_BSRR_PIN5);
        BIT_SET(GPIOB_BSRR, GPIOB_BSRR_PIN7);
        BIT_SET(GPIOB_BSRR, GPIOB_BRR_PIN9);
      }
      else if(led_pin == 2) {
        BIT_SET(GPIOB_BSRR, GPIOB_BRR_PIN5);
        BIT_SET(GPIOB_BSRR, GPIOB_BSRR_PIN7);
        BIT_SET(GPIOB_BSRR, GPIOB_BSRR_PIN9);
      }
      else if(led_pin == 3) {
        BIT_SET(GPIOB_BSRR, GPIOB_BSRR_PIN5);
        BIT_SET(GPIOB_BSRR, GPIOB_BRR_PIN7);
        BIT_SET(GPIOB_BSRR, GPIOB_BSRR_PIN9);
      }
    }

    if(led_mode == 3) {
      if(led_pin == 1) {
        BIT_SET(GPIOB_BSRR, GPIOB_BSRR_PIN5);
        BIT_SET(GPIOB_BSRR, GPIOB_BSRR_PIN7);
        BIT_SET(GPIOB_BSRR, GPIOB_BSRR_PIN9);
      }
      else if(led_pin == 2) {
        BIT_SET(GPIOB_BSRR, GPIOB_BRR_PIN5);
        BIT_SET(GPIOB_BSRR, GPIOB_BRR_PIN7);
        BIT_SET(GPIOB_BSRR, GPIOB_BRR_PIN9);
      }
      // else if(led_pin == 3) {
      //   led_pin = 1;
      // }
    }
  }
}




























// int main(void){
//   // *(uint32_t*)(0x40021000UL + 0x18UL) |= 0x10UL;
//   // *(uint32_t*)(0x40011000UL + 0x04UL) |= 0x600000;
//   // *(uint32_t*)(0x40011000UL + 0x10UL) |= 0x2000;
//   // SET_BIT(RCC->APB2ENR, RCC_APB2ENR_IOPCEN);
//   // SET_BIT(GPIOC->CRH, GPIO_CRH_MODE13_1);
//   // CLEAR_BIT(GPIOC->CRH, GPIO_CRH_CNF13);

//   RCC->APB2ENR |= RCC_APB2ENR_IOPBEN; // включение тактирования

//   GPIOB->CRH |= GPIO_CRH_MODE9_1; // режим и скорость работы порта
//   GPIOB->CRH &= ~GPIO_CRH_CNF9; // // занулить два пина CNF

//   GPIOB->CRL |= 0x20000000; // режим порта MODE
//   GPIOB->CRL &= ~0xC0000000; // занулить два пина CNF 

//   GPIOB->CRL |= 0x100000;
//   GPIOB->CRL &= ~0xC00000;

//   GPIOB->CRH |= 0x1000;
//   GPIOB->CRH &= ~0xC000;
 
//   while(1){
//     // SET_BIT(GPIOC->BSRR, GPIO_BSRR_BR13);
    
//     GPIOB->BSRR = 0x800;

//     GPIOB->BSRR = 0x200;
//     for(int i = 0; i < 500000; i++) {}
//     GPIOB->BRR = 0x200;

//     GPIOB->BSRR = 0x80;
//     for(int i = 0; i < 500000; i++) {}
//     GPIOB->BRR = 0x80;

//     GPIOB->BSRR = 0x20;
//     for(int i = 0; i < 500000; i++) {}
//     GPIOB->BRR = 0x20;
//     GPIOB->BRR = 0x800;

//     for(int i = 0; i < 500000; i++) {}
//   }
// }