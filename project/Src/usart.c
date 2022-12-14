#include <stdio.h>
#include "stm32f103x6.h"
#include "util.h"

//иницијализација USART комуникације
void USART_Init (USART_TypeDef * USARTx) {

	USARTx->CR1 &= ~USART_CR1_UE;  					// На почетку онемогућавамо USART, пишемо 0 на бит 13 у контролном регистру 1, стр. 821

	USARTx->CR1 &= ~USART_CR1_M;   					// Одређујемо дужини речи, пишемо 0 у бит 12 у контролном регистру 1, што означава реч од 8 бита, стр. 821

	USARTx->CR2 &= ~USART_CR2_STOP; 				// Одређујемо број стоп битова, пишемо 0 у битове 13:12 у контролном регистру 2, што означава 1 стоп бит, стр. 823

	// Подешавање baud rate-а односно брзине преноса података, рачуна се по формули baud = f_CK / (16*USARTDIV) (стр. 798)
	// Подразумевни клок је 8MHz, па добијамо USARTDIV = 8.000.000/(16*9600) = 52,083
	// Након дељења USARTDIV-a на мантису тј. 52 и остатак тј. 0,083 и конвертовања у хекс систем након примењивања формуле добијамо BRR
	USARTx->BRR  = 0x341;

	USARTx->CR1  |= (USART_CR1_RE | USART_CR1_TE);  // Уписивањем 1 на битнове 2 и 3  контролонг регистра 1 (стр. 822) омогућавамо ресивер и трансмитер

	USARTx->CR1  |= USART_CR1_UE; 					// На крају омогућавамо USART, пишемо 1 на бит 13 у контролном регистру 1, стр. 821
}

//иницијализација пинова које ћемо користити за комуникацију
void UART1_GPIO_Init(void) {

	RCC->APB2ENR |=   RCC_APB2ENR_IOPAEN; 					// омогућавамо клок порта А уписивањем 1 на бит 2 APB2ENR регистра, стр. 114

	// са стране 181 установљавамо да је потребно мапирати пинове 9 и 10 за трансмитер и ресивер, респективно
	// са страна 166/167 видимо у ком режиму треба подесити пинове, односно у Alternate function push-pull/Input floating, излазни/улазни режим, користимо Full duplex (комуникација у оба смера)

	//подешавање пина USART1_TX
	GPIOA->CRH &= ~(GPIO_CRH_MODE9 | GPIO_CRH_CNF9); 		// најпре бришемо CNF и MODE поља пина 9, порта А, стр. 172

	GPIOA->CRH |= (GPIO_CRH_MODE9_1 | GPIO_CRH_MODE9_0); 	// уписујемо вреност 11 у битове 4:5, односно сетујемо макс. брзину 50MHz , стр. 172

	GPIOA->CRH |= GPIO_CRH_CNF9_1;							// уписујемо вреност 10 у битове 7:6, односно сетујемо режими у Alternate function push-pull

	//подешавање пина USART1_RX
	GPIOA->CRH &= ~(GPIO_CRH_MODE10 | GPIO_CRH_CNF10); 		// најпре бришемо CNF и MODE поља пина 10, порта А, стр. 172

	//MODE битове смо обрисали, тј. уписана вредност је 00 ондосно Input mode што нам одговара, стр. 172

	GPIOA->CRH |= GPIO_CRH_CNF10_0; 						// уписујемо вреност 01 у битова 11:10, што нам даје Floating input, стр. 167
}

//иницијализација USART1 комуникације
void UART1_Init(void) {

	RCC->APB2ENR |= RCC_APB2ENR_USART1EN;  		//омогућавамо клок USART1 уписивањем 1 на бит 14 APB2ENR регистра, стр. 113

	UART1_GPIO_Init();							//иницијализација пинова које ћемо користити за комуникацију
	USART_Init(USART1);							//иницијализација USART1 комуникације

	NVIC_EnableIRQ(USART1_IRQn);				//омугућавамо прекид USART1
}

static const uint8_t *sendbuf;					//декларишемо бафер

//функција која позива прекид и шаље податке за испис
void UART_Send (uint8_t *buffer){

	sendbuf = buffer;				 		//додељујемо поруку за слање
	USART1->CR1 |= USART_CR1_TXEIE;  		//сетовањем бита 7 у контролном регистру 1 омогућавамо TXE прекид, стр. 821
}

//фукнција за обраду прекида
void USART1_IRQHandler(void) {

    if(USART1->CR1 & USART1->SR & USART_SR_TXE) { //уколико је омогућен прекид и TXE бит сетован
        uint8_t c = *sendbuf++;					  //додељујемо вредност
        if (*sendbuf == 0)						  //уколико нема више података за слање
            USART1->CR1 &= ~USART_CR1_TXEIE;	  //онемогућујемо даље прекиде
    	USART1->DR = c;							  //шаљемо податак у дата регистар

    }
}
