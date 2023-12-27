/*************************************************************************/
/*************************************************************************/
/************************** Name: Taher Mohamed **************************/
/************************** File name: CARD.h   **************************/
/*************************************************************************/
/*************************************************************************/

/* file guard */
#ifndef _CARD_H
#define _CARD_H

/* includes */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "STD_TYPE.h"

/*structure data type to store CARD information */
typedef struct 
{
	u8 CARD_Holder_Name[25];
	u8 CARD_Expiry_Date[6];
	u8 CARD_PAN_Number[17];
} CARD_t;

/* Card errors*/
typedef enum Card_Errors
{
	OK,
	CARD_Name_error,
	CARD_ExpiryDate_error,
	CARD_PAN_error
}Card_Errors;

/*function to get NAME */
Card_Errors getCardHolderName(CARD_t* ptrCopyCARD_t);
/*function to get ExpiryDate */
Card_Errors getCardExpiryDate(CARD_t* ptrCopyCARD_t);
/*function to get CardPAN */
Card_Errors getCardPAN(CARD_t* ptrCopyCARD_t);

#endif
