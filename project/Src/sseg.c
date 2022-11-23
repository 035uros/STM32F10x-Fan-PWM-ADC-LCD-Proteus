#include <stdio.h>
#include "stm32f103x6.h"

void delay(int num);
void resetcifre(void);
void jedinica(int zarez);
void dvojka(int zarez);
void trojka(int zarez);
void cetvorka(int zarez);
void petica(int zarez);
void sestica(int zarez);
void sedmica(int zarez);
void osmica(int zarez);
void devetka(int zarez);

void resetcifre(void){
	//искључујемо све сегменте
	GPIOC->BSRR |= GPIO_BSRR_BS6;
	GPIOC->BSRR |= GPIO_BSRR_BS7;
	GPIOC->BSRR |= GPIO_BSRR_BS8;
	GPIOC->BSRR |= GPIO_BSRR_BS9;
	GPIOC->BSRR |= GPIO_BSRR_BS10;
	GPIOC->BSRR |= GPIO_BSRR_BS11;
	GPIOC->BSRR |= GPIO_BSRR_BS12;
	GPIOC->BSRR |= GPIO_BSRR_BS13;
}
void jedinica(zarez){

	resetcifre();
	GPIOC->BSRR &= ~(GPIO_BSRR_BS7);// B
	GPIOC->BSRR |= (GPIO_BSRR_BR7); // reset

	GPIOC->BSRR &= ~(GPIO_BSRR_BS8); // C
	GPIOC->BSRR |= (GPIO_BSRR_BR8); // reset

	if(zarez == 1){
		GPIOC->BSRR &= ~(GPIO_BSRR_BS13); // ресетујемо пин PC13
		GPIOC->BSRR |= (GPIO_BSRR_BR13); //ресетујемо пин PC13
	}
}

void dvojka(zarez){

	resetcifre();
	GPIOC->BSRR &= ~GPIO_BSRR_BS6; // A
	GPIOC->BSRR |= (GPIO_BSRR_BR6); // reset

	GPIOC->BSRR &= ~GPIO_BSRR_BS7; // B
	GPIOC->BSRR |= (GPIO_BSRR_BR7); // reset

	GPIOC->BSRR &= ~GPIO_BSRR_BS12; // G
	GPIOC->BSRR |= (GPIO_BSRR_BR12); // reset

	GPIOC->BSRR &= ~GPIO_BSRR_BS10;  // E
	GPIOC->BSRR |= (GPIO_BSRR_BR10); // reset

	GPIOC->BSRR &= ~GPIO_BSRR_BS9; // D
	GPIOC->BSRR |= (GPIO_BSRR_BR9); // reset

	if(zarez == 1){
			GPIOC->BSRR &= ~(GPIO_BSRR_BS13); // ресетујемо пин PC13
			GPIOC->BSRR |= (GPIO_BSRR_BR13); // ресетујемо пин PC13
		}
}

void trojka(zarez){

	resetcifre();
	GPIOC->BSRR &= ~GPIO_BSRR_BS6; // A
	GPIOC->BSRR |= (GPIO_BSRR_BR6); // reset

	GPIOC->BSRR &= ~GPIO_BSRR_BS7; // B
	GPIOC->BSRR |= (GPIO_BSRR_BR7); // reset

	GPIOC->BSRR &= ~(GPIO_BSRR_BS8); // C
	GPIOC->BSRR |= (GPIO_BSRR_BR8); // reset

	GPIOC->BSRR &= ~GPIO_BSRR_BS9; // D
	GPIOC->BSRR |= (GPIO_BSRR_BR9); // reset

	GPIOC->BSRR &= ~GPIO_BSRR_BS12; // G
	GPIOC->BSRR |= (GPIO_BSRR_BR12); // reset

	if(zarez == 1){
			GPIOC->BSRR &= ~(GPIO_BSRR_BS13); // ресетујемо пин PC13
			GPIOC->BSRR |= (GPIO_BSRR_BR13); // ресетујемо пин PC13
		}
}

void cetvorka(zarez){

	resetcifre();
	GPIOC->BSRR &= ~GPIO_BSRR_BS11; // F
	GPIOC->BSRR |= (GPIO_BSRR_BR11); // reset

	GPIOC->BSRR &= ~GPIO_BSRR_BS7; // B
	GPIOC->BSRR |= (GPIO_BSRR_BR7); // reset

	GPIOC->BSRR &= ~(GPIO_BSRR_BS8); // C
	GPIOC->BSRR |= (GPIO_BSRR_BR8); // reset

	GPIOC->BSRR &= ~GPIO_BSRR_BS12; // G
	GPIOC->BSRR |= (GPIO_BSRR_BR12); // reset

	if(zarez == 1){
			GPIOC->BSRR &= ~(GPIO_BSRR_BS13); // ресетујемо пин PC13
			GPIOC->BSRR |= (GPIO_BSRR_BR13); // ресетујемо пин PC13
		}
}

void petica(zarez){

	resetcifre();
	GPIOC->BSRR &= ~GPIO_BSRR_BS6; // A
	GPIOC->BSRR |= (GPIO_BSRR_BR6); // reset

	GPIOC->BSRR &= ~GPIO_BSRR_BS11; // F
	GPIOC->BSRR |= (GPIO_BSRR_BR11); // reset

	GPIOC->BSRR &= ~GPIO_BSRR_BS12; // G
	GPIOC->BSRR |= (GPIO_BSRR_BR12); // reset

	GPIOC->BSRR &= ~(GPIO_BSRR_BS8); // C
	GPIOC->BSRR |= (GPIO_BSRR_BR8); // reset

	GPIOC->BSRR &= ~GPIO_BSRR_BS9; // D
	GPIOC->BSRR |= (GPIO_BSRR_BR9); // reset

	if(zarez == 1){
			GPIOC->BSRR &= ~(GPIO_BSRR_BS13); // ресетујемо пин PC13
			GPIOC->BSRR |= (GPIO_BSRR_BR13); // ресетујемо пин PC13
		}
}

void sestica(zarez){

	resetcifre();
	GPIOC->BSRR &= ~GPIO_BSRR_BS6; // A
	GPIOC->BSRR |= (GPIO_BSRR_BR6); // reset

	GPIOC->BSRR &= ~GPIO_BSRR_BS11; // F
	GPIOC->BSRR |= (GPIO_BSRR_BR11); // reset

	GPIOC->BSRR &= ~GPIO_BSRR_BS12; // G
	GPIOC->BSRR |= (GPIO_BSRR_BR12); // reset

	GPIOC->BSRR &= ~(GPIO_BSRR_BS8); // C
	GPIOC->BSRR |= (GPIO_BSRR_BR8); // reset

	GPIOC->BSRR &= ~GPIO_BSRR_BS9; // D
	GPIOC->BSRR |= (GPIO_BSRR_BR9); // reset

	GPIOC->BSRR &= ~GPIO_BSRR_BS10;  // E
	GPIOC->BSRR |= (GPIO_BSRR_BR10); // reset

	if(zarez == 1){
			GPIOC->BSRR &= ~(GPIO_BSRR_BS13); // ресетујемо пин PC13
			GPIOC->BSRR |= (GPIO_BSRR_BR13); // ресетујемо пин PC13
		}
}

void sedmica(zarez){

	resetcifre();
	GPIOC->BSRR &= ~GPIO_BSRR_BS11; // F
	GPIOC->BSRR |= (GPIO_BSRR_BR11); // reset

	GPIOC->BSRR &= ~GPIO_BSRR_BS7; // B
	GPIOC->BSRR |= (GPIO_BSRR_BR7); // reset

	GPIOC->BSRR &= ~(GPIO_BSRR_BS8); // C
	GPIOC->BSRR |= (GPIO_BSRR_BR8); // reset

	GPIOC->BSRR &= ~GPIO_BSRR_BS6; // A
	GPIOC->BSRR |= (GPIO_BSRR_BR6); // reset

	if(zarez == 1){
			GPIOC->BSRR &= ~(GPIO_BSRR_BS13); // ресетујемо пин PC13
			GPIOC->BSRR |= (GPIO_BSRR_BR13); // ресетујемо пин PC13
		}

}

void osmica(zarez){

	resetcifre();
	GPIOC->BSRR &= ~GPIO_BSRR_BS11; // F
	GPIOC->BSRR |= (GPIO_BSRR_BR11); // reset

	GPIOC->BSRR &= ~GPIO_BSRR_BS7; // B
	GPIOC->BSRR |= (GPIO_BSRR_BR7); // reset

	GPIOC->BSRR &= ~(GPIO_BSRR_BS8); // C
	GPIOC->BSRR |= (GPIO_BSRR_BR8); // reset

	GPIOC->BSRR &= ~GPIO_BSRR_BS6; // A
	GPIOC->BSRR |= (GPIO_BSRR_BR6); // reset

	GPIOC->BSRR &= ~GPIO_BSRR_BS9; // D
	GPIOC->BSRR |= (GPIO_BSRR_BR9); // reset

	GPIOC->BSRR &= ~GPIO_BSRR_BS10;  // E
	GPIOC->BSRR |= (GPIO_BSRR_BR10); // reset

	GPIOC->BSRR &= ~GPIO_BSRR_BS12; // G
	GPIOC->BSRR |= (GPIO_BSRR_BR12); // reset

	if(zarez == 1){
			GPIOC->BSRR &= ~(GPIO_BSRR_BS13); // ресетујемо пин PC13
			GPIOC->BSRR |= (GPIO_BSRR_BR13); // ресетујемо пин PC13
		}

}

void devetka(zarez){

	resetcifre();
	GPIOC->BSRR &= ~GPIO_BSRR_BS11; // F
	GPIOC->BSRR |= (GPIO_BSRR_BR11); // reset

	GPIOC->BSRR &= ~GPIO_BSRR_BS7; // B
	GPIOC->BSRR |= (GPIO_BSRR_BR7); // reset

	GPIOC->BSRR &= ~(GPIO_BSRR_BS8); // C
	GPIOC->BSRR |= (GPIO_BSRR_BR8); // reset

	GPIOC->BSRR &= ~GPIO_BSRR_BS6; // A
	GPIOC->BSRR |= (GPIO_BSRR_BR6); // reset

	GPIOC->BSRR &= ~GPIO_BSRR_BS9; // D
	GPIOC->BSRR |= (GPIO_BSRR_BR9); // reset

	GPIOC->BSRR &= ~GPIO_BSRR_BS12; // G
	GPIOC->BSRR |= (GPIO_BSRR_BR12); // reset

	if(zarez == 1){
			GPIOC->BSRR &= ~(GPIO_BSRR_BS13); // ресетујемо пин PC13
			GPIOC->BSRR |= (GPIO_BSRR_BR13); // ресетујемо пин PC13
		}

}

void nula(zarez){

	resetcifre();
	GPIOC->BSRR &= ~GPIO_BSRR_BS11; // F
	GPIOC->BSRR |= (GPIO_BSRR_BR11); // reset

	GPIOC->BSRR &= ~GPIO_BSRR_BS7; // B
	GPIOC->BSRR |= (GPIO_BSRR_BR7); // reset

	GPIOC->BSRR &= ~(GPIO_BSRR_BS8); // C
	GPIOC->BSRR |= (GPIO_BSRR_BR8); // reset

	GPIOC->BSRR &= ~GPIO_BSRR_BS6; // A
	GPIOC->BSRR |= (GPIO_BSRR_BR6); // reset

	GPIOC->BSRR &= ~GPIO_BSRR_BS9; // D
	GPIOC->BSRR |= (GPIO_BSRR_BR9); // reset

	GPIOC->BSRR &= ~GPIO_BSRR_BS10;  // E
	GPIOC->BSRR |= (GPIO_BSRR_BR10); // reset

	if(zarez == 1){
			GPIOC->BSRR &= ~(GPIO_BSRR_BS13); // ресетујемо пин PC13
			GPIOC->BSRR |= (GPIO_BSRR_BR13); // ресетујемо пин PC13
		}


}


void SSGPIO_Init(void){

	RCC->APB2ENR |= RCC_APB2ENR_IOPCEN;  //омогућавамо клок порта А уписивањем 1 на бит 2 APB2ENR регистра, стр. 114

	//цифре
	GPIOC->CRL &= ~(GPIO_CRL_MODE0 | GPIO_CRL_CNF0); // бришемо подешавања PC0
	GPIOC->CRL |= (GPIO_CRL_MODE0_1 | GPIO_CRL_CNF0_0);  //GPO Push-pull

	GPIOC->CRL &= ~(GPIO_CRL_MODE1 | GPIO_CRL_CNF1); // бришемо подешавања PC1
	GPIOC->CRL |= (GPIO_CRL_MODE1_1 | GPIO_CRL_CNF1_0);  //GPO Push-pull

	GPIOC->CRL &= ~(GPIO_CRL_MODE2 | GPIO_CRL_CNF2); //бришемо подешавања PC2
	GPIOC->CRL |= (GPIO_CRL_MODE2_1 | GPIO_CRL_CNF2_0);  //GPO Push-pull

	GPIOC->CRL &= ~(GPIO_CRL_MODE3 | GPIO_CRL_CNF3); // бришемо подешавања PC3
	GPIOC->CRL |= (GPIO_CRL_MODE3_1 | GPIO_CRL_CNF3_0);  //GPO Push-pull

	GPIOC->CRL &= ~(GPIO_CRL_MODE4 | GPIO_CRL_CNF4); // бришемо подешавања PC4
	GPIOC->CRL |= (GPIO_CRL_MODE4_1 | GPIO_CRL_CNF4_0);  //GPO Push-pull

	GPIOC->CRL &= ~(GPIO_CRL_MODE5 | GPIO_CRL_CNF5); // бришемо подешавања PC5
	GPIOC->CRL |= (GPIO_CRL_MODE5_1 | GPIO_CRL_CNF5_0);  //GPO Push-pull

	//сегменти
	GPIOC->CRL &= ~(GPIO_CRL_MODE7 | GPIO_CRL_CNF7); // бришемо подешавања PC7
	GPIOC->CRL |= (GPIO_CRL_MODE7_1 | GPIO_CRL_CNF7_0);  //GPO Push-pull

	GPIOC->CRL &= ~(GPIO_CRL_MODE6 | GPIO_CRL_CNF6); //бришемо подешавања PC6
	GPIOC->CRL |= (GPIO_CRL_MODE6_1 | GPIO_CRL_CNF6_0);  //GPO Push-pull

	GPIOC->CRH &= ~(GPIO_CRH_MODE8 | GPIO_CRH_CNF8); // бришемо подешавања PC8
	GPIOC->CRH |= (GPIO_CRH_MODE8_1 | GPIO_CRH_CNF8_0);  //GPO Push-pull

	GPIOC->CRH &= ~(GPIO_CRH_MODE9 | GPIO_CRH_CNF9); // бришемо подешавања PC9
	GPIOC->CRH |= (GPIO_CRH_MODE9_1 | GPIO_CRH_CNF9_0);  //GPO Push-pull

	GPIOC->CRH &= ~(GPIO_CRH_MODE10 | GPIO_CRH_CNF10); // бришемо подешавања PC10
	GPIOC->CRH |= (GPIO_CRH_MODE10_1 | GPIO_CRH_CNF10_0);  //GPO Push-pull

	GPIOC->CRH &= ~(GPIO_CRH_MODE11 | GPIO_CRH_CNF11); // бришемо подешавања PC11
	GPIOC->CRH |= (GPIO_CRH_MODE11_1 | GPIO_CRH_CNF11_0);  //GPO Push-pull

	GPIOC->CRH &= ~(GPIO_CRH_MODE12 | GPIO_CRH_CNF12); //бришемо подешавања PC12
	GPIOC->CRH |= (GPIO_CRH_MODE12_1 | GPIO_CRH_CNF12_0);  //GPO Push-pull

	GPIOC->CRH &= ~(GPIO_CRH_MODE13 | GPIO_CRH_CNF13); // бришемо подешавања PC13
	GPIOC->CRH |= (GPIO_CRH_MODE13_1 | GPIO_CRH_CNF13_0);  //GPO Push-pull



	GPIOC->BSRR |= (GPIO_BSRR_BS0); // setujemo pin PC0
	GPIOC->BSRR |= (GPIO_BSRR_BS1); // setujemo pin PC0

	GPIOC->BSRR |= (GPIO_BSRR_BS2); // setujemo pin PC1

	GPIOC->BSRR &= ~(GPIO_BSRR_BS1); // resetujemo pin PC0
	GPIOC->BSRR |= (GPIO_BSRR_BR1); // resetujemo pin PC0
	GPIOC->BSRR &= ~(GPIO_BSRR_BS2); // resetujemo pin PC0
	GPIOC->BSRR |= (GPIO_BSRR_BR2); // resetujemo pin PC0



}

void ispisbroja(int broj){

	int c4 = (broj%1000000)/100000;
	int c3 = (broj%100000)/10000;
	int c2=(broj%10000)/1000;
	int c1=(broj%1000)/100;
	int c0=(broj%100)/10;
	int cm1=(broj%10);

	int i=0;

	while(i<10){
		i++;
		GPIOC->BSRR |= (GPIO_BSRR_BS0); //сетујемо PC0
	switch(c4){
	case 9:
		devetka(0);
		break;
	case 8:
		osmica(0);
		break;
	case 7:
		sedmica(0);
		break;
	case 6:
		sestica(0);
		break;
	case 5:
		petica(0);
		break;
	case 4:
		cetvorka(0);
		break;
	case 3:
		trojka(0);
		break;
	case 2:
		dvojka(0);
		break;
	case 1:
		jedinica(0);
		break;
	default:
		nula(0);
	}
	delay(100);
	GPIOC->BSRR &= ~(GPIO_BSRR_BS0); // resetujemo pin PC0
	GPIOC->BSRR |= (GPIO_BSRR_BR0); // resetujemo pin PC0

	GPIOC->BSRR |= (GPIO_BSRR_BS1); // setujemo pin PC1
	switch(c3){
		case 9:
			devetka(0);
			break;
		case 8:
			osmica(0);
			break;
		case 7:
			sedmica(0);
			break;
		case 6:
			sestica(0);
			break;
		case 5:
			petica(0);
			break;
		case 4:
			cetvorka(0);
			break;
		case 3:
			trojka(0);
			break;
		case 2:
			dvojka(0);
			break;
		case 1:
			jedinica(0);
			break;
		default:
			nula(0);
		}
	delay(80);
	GPIOC->BSRR &= ~(GPIO_BSRR_BS1); // resetujemo pin PC1
	GPIOC->BSRR |= (GPIO_BSRR_BR1); // resetujemo pin PC1

	GPIOC->BSRR |= (GPIO_BSRR_BS2); // setujemo pin PC2
	switch (c2){
		case 9:
			devetka(0);
			break;
		case 8:
			osmica(0);
			break;
		case 7:
			sedmica(0);
			break;
		case 6:
			sestica(0);
			break;
		case 5:
			petica(0);
			break;
		case 4:
			cetvorka(0);
			break;
		case 3:
			trojka(0);
			break;
		case 2:
			dvojka(0);
			break;
		case 1:
			jedinica(0);
			break;
		default:
			nula(0);
		}
	delay(80);
	GPIOC->BSRR &= ~(GPIO_BSRR_BS2); // resetujemo pin PC2
	GPIOC->BSRR |= (GPIO_BSRR_BR2); // resetujemo pin PC2

	GPIOC->BSRR |= (GPIO_BSRR_BS3); // setujemo pin PC3
	switch(c1){
		case 9:
			devetka(1);
			break;
		case 8:
			osmica(1);
			break;
		case 7:
			sedmica(1);
			break;
		case 6:
			sestica(1);
			break;
		case 5:
			petica(1);
			break;
		case 4:
			cetvorka(1);
			break;
		case 3:
			trojka(1);
			break;
		case 2:
			dvojka(1);
			break;
		case 1:
			jedinica(1);
			break;
		default:
			nula(1);
		}
	delay(80);
	GPIOC->BSRR &= ~(GPIO_BSRR_BS3); // resetujemo pin PC3
	GPIOC->BSRR |= (GPIO_BSRR_BR3); // resetujemo pin PC3


	GPIOC->BSRR |= (GPIO_BSRR_BS4); // setujemo pin PC4
	switch(c0){
		case 9:
			devetka(0);
			break;
		case 8:
			osmica(0);
			break;
		case 7:
			sedmica(0);
			break;
		case 6:
			sestica(0);
			break;
		case 5:
			petica(0);
			break;
		case 4:
			cetvorka(0);
			break;
		case 3:
			trojka(0);
			break;
		case 2:
			dvojka(0);
			break;
		case 1:
			jedinica(0);
			break;
		default:
			nula(0);
		}
	delay(80);
	GPIOC->BSRR &= ~(GPIO_BSRR_BS4); // resetujemo pin PC4
	GPIOC->BSRR |= (GPIO_BSRR_BR4); // resetujemo pin PC4

	GPIOC->BSRR |= (GPIO_BSRR_BS5); // setujemo pin PC5
	switch(cm1){
		case 9:
			devetka(0);
			break;
		case 8:
			osmica(0);
			break;
		case 7:
			sedmica(0);
			break;
		case 6:
			sestica(0);
			break;
		case 5:
			petica(0);
			break;
		case 4:
			cetvorka(0);
			break;
		case 3:
			trojka(0);
			break;
		case 2:
			dvojka(0);
			break;
		case 1:
			jedinica(0);
			break;
		default:
			nula(0);
		}
	delay(80);
	GPIOC->BSRR &= ~(GPIO_BSRR_BS5); // resetujemo pin PC5
	GPIOC->BSRR |= (GPIO_BSRR_BR5); // resetujemo pin PC5
	}

}
