#include "stm32f103x6.h"

#define PORT GPIOB						//декларишемо порт B

#define PIN_RS	GPIO_ODR_ODR9			//дефинишемо Register Select пин, пиноут ЛЦД.png
#define PIN_RW	GPIO_ODR_ODR10			//дефинишемо Read/Write пин, пиноут ЛЦД.png
#define PIN_E	GPIO_ODR_ODR11			//дефинишемо Enable пин, пиноут ЛЦД.png
#define PIN_D4	GPIO_ODR_ODR12			//дефинишемо D4 пин, пиноут ЛЦД.png
#define PIN_D5	GPIO_ODR_ODR13			//дефинишемо D5 пин, пиноут ЛЦД.png
#define PIN_D6	GPIO_ODR_ODR14			//дефинишемо D6 пин, пиноут ЛЦД.png
#define PIN_D7	GPIO_ODR_ODR15			//дефинишемо D7 пин, пиноут ЛЦД.png

#define WIDTH 16						//дефинишемо дужину, односно 16 карактера је макс. могуће сместити на ЛЦД

void LCD_Init(void);					//декларација функције и њених параметара
