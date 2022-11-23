#include "stm32f103x6.h"
#include "hd44780.h"

static char pos_x;										//хоризонтална координата, означава позицију на коју пишемо карактер

void LCD_WriteText(char* text);							//декларација функције и њених параметара
void LCD_WriteCommand(unsigned char command);			//декларација функције и њених параметара
void LCD_WriteChar(unsigned char command);				//декларација функције и њених параметара
void LCD_WriteDPort(unsigned char command);				//декларација функције и њених параметара
void LCD_SetCursor(unsigned char x);					//декларација функције и њених параметара

//функција за иницијализацију LCD
void LCD_Init(void) {

	unsigned int i;										//пременљива коју користимо у сврси delay функције

	RCC->APB2ENR |= RCC_APB2ENR_IOPBEN; 				//омогућавамо клок порта А уписивањем 1 на бит 2 APB2ENR регистра, стр. 114

	GPIOB->CRH &= ~(GPIO_CRH_MODE9 | GPIO_CRH_CNF9); 	//бришемо подешавања за PB9
	GPIOB->CRH |= (GPIO_CRH_MODE9_1 | GPIO_CRH_CNF9_0); //сетујемо решим у излазни push-pull мод

	GPIOB->CRH &= ~(GPIO_CRH_MODE10 | GPIO_CRH_CNF10); 	//бришемо подешавања за PB10
	GPIOB->CRH |= (GPIO_CRH_MODE10_1 | GPIO_CRH_CNF10_0); //сетујемо решим у излазни push-pull мод

	GPIOB->CRH &= ~(GPIO_CRH_MODE11 | GPIO_CRH_CNF11); 	//бришемо подешавања за PB11
	GPIOB->CRH |= (GPIO_CRH_MODE11_1 | GPIO_CRH_CNF11_0); //сетујемо решим у излазни push-pull мод

	GPIOB->CRH &= ~(GPIO_CRH_MODE12 | GPIO_CRH_CNF12); 	//бришемо подешавања за PB12
	GPIOB->CRH |= (GPIO_CRH_MODE12_1 | GPIO_CRH_CNF12_0); //сетујемо решим у излазни push-pull мод

	GPIOB->CRH &= ~(GPIO_CRH_MODE13 | GPIO_CRH_CNF13); 	//бришемо подешавања за PB13
	GPIOB->CRH |= (GPIO_CRH_MODE13_1 | GPIO_CRH_CNF13_0); //сетујемо решим у излазни push-pull мод

	GPIOB->CRH &= ~(GPIO_CRH_MODE14 | GPIO_CRH_CNF14); 	//бришемо подешавања за PB14
	GPIOB->CRH |= (GPIO_CRH_MODE14_1 | GPIO_CRH_CNF14_0); //сетујемо решим у излазни push-pull мод

	GPIOB->CRH &= ~(GPIO_CRH_MODE15 | GPIO_CRH_CNF15); 	//бришемо подешавања за PB15
	GPIOB->CRH |= (GPIO_CRH_MODE15_1 | GPIO_CRH_CNF15_0); //сетујемо решим у излазни push-pull мод

	PORT->ODR &= ~PIN_E & ~PIN_RS & ~PIN_RW;			//онемогућујемо екран, подешавамо мод на писање у командни регистар

	for (i = 0; i < 80000000 / 200; i++);				//осигуравамо да су пинови искључени

	LCD_WriteDPort(0x02); 								//користимо 4битни интерфејс, стр. 14 LM020L_ETC.pdf
	LCD_WriteCommand(0x20); 							//4bit interface, 1 ред, 5x7 резолуција карактера
	LCD_WriteCommand(0x0F); 							//Укључујемо дисплеј, трепкање и "курсор" стр. 27, LM020L_ETC.pdf
	LCD_WriteCommand(0x01);								//чистмо дисплеј
	LCD_SetCursor(0);								//постављамо курсор на почетну позицију
}

//функција за исписивање текста
void LCD_WriteText(char* text) {

	LCD_WriteCommand(0x01);								//чистмо дисплеј
	LCD_SetCursor(0);								//постављамо курсор на почетну позицију
	while (*text) {										//петља за пролазак кроз текст
			LCD_WriteChar(*text++);						//исписујемо карактер
	}
}

//функција за писање команди
void LCD_WriteCommand(unsigned char command) {

	PORT->BRR = PIN_RS;									//приступамо командном регистру
	PORT->BRR = PIN_RW;									//пишемо команду

	LCD_WriteDPort(command >> 4);						//шаљемо виших 4 бита
	LCD_WriteDPort(command);							//шаљемо нижих 4 бита

	delay(1000);										//осигравамо да се команда извршила
}

//фкункција за исписивање карактера
void LCD_WriteChar(unsigned char c) {

	PORT->BSRR = PIN_RS;								//приступамо регистру података
	PORT->BRR = PIN_RW;									//пишемо

	LCD_WriteDPort(c >> 4);								//шаљемо виших 4 бита
	LCD_WriteDPort(c);									//шаљемо нижих 4 бита

	delay(1000);										//осигравамо да се инструкција извршила

	pos_x++;											//инкрементујемо позицију у десно

	if (pos_x == WIDTH) {								//проверавамо да ли смо на граници опсега
		pos_x = 0;										//уколико јесмо, враћамо координату на почетну вредност
	}
}

//функција за писање команди
void LCD_WriteDPort(unsigned char command) {

	PORT->BSRR = PIN_E;									//најпре омогућујемо екран, стр. 3 LM020L_ETC.pdf

	if (command & 0x01)									//проверавамо да ли је потребно бит D4 подићи
		PORT->BSRR = PIN_D4;							//уколико јесте стављамо пин на high коришћењем BBSR регистра стр.173 Ref. Man.
	else
		PORT->BRR = PIN_D4;								//иначе га ресетујемо, стр. 174 Ref. Man.
	if (command & 0x02)									//проверавамо да ли је потребно бит D5 подићи
		PORT->BSRR = PIN_D5;							//уколико јесте стављамо пин на high коришћењем BBSR регистра стр.173 Ref. Man.
	else
		PORT->BRR = PIN_D5;								//иначе га ресетујемо, стр. 174 Ref. Man.
	if (command & 0x04)									//проверавамо да ли је потребно бит D6 подићи
		PORT->BSRR = PIN_D6;							//уколико јесте стављамо пин на high коришћењем BBSR регистра стр.173 Ref. Man.
	else
		PORT->BRR = PIN_D6;								//иначе га ресетујемо, стр. 174 Ref. Man.
	if (command & 0x08)									//проверавамо да ли је потребно бит D7 подићи
		PORT->BSRR = PIN_D7;							//уколико јесте стављамо пин на high коришћењем BBSR регистра стр.173 Ref. Man.
	else
		PORT->BRR = PIN_D7;								//иначе га ресетујемо, стр. 174 Ref. Man.

	PORT->BRR = PIN_E;									//онемогућимо екран како бисмо послали команду
}

//функција за позиционирање курсора
void LCD_SetCursor(unsigned char x) {

	int i;
	pos_x = x;											//Х кооридната
	LCD_WriteCommand(0x02);								//враћа курсор на почетну позицију, команде за ЛЦД.png

	for (i = 0; i < x; i++) {							//помера курсор за онолико поља колико нам је потребно
		LCD_WriteCommand(0x14);							//померање курсора за једно поље у десно, команде за ЛЦД.png
	}
}

