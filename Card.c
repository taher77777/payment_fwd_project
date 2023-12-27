/*************************************************************************/
/*************************************************************************/
/************************** Name: Taher Mohamed **************************/
/************************** File name: CARD.c   **************************/
/*************************************************************************/
/*************************************************************************/

/*includes*/
#include "Card.h"


/*function to get NAME */
Card_Errors getCardHolderName(CARD_t* ptrCopyCARD_t)
{
	u8 u8Local_length;
	printf(" enter your name   : \n use *_* not use space \n ===> ");
	/*get the name*/
	scanf("%s", &(ptrCopyCARD_t->CARD_Holder_Name));
	/*get name`s length*/

	u8Local_length=strlen(ptrCopyCARD_t->CARD_Holder_Name);

	/*check length*/
	
	if (u8Local_length >= 18 && u8Local_length <= 23) 
	{
        printf(" valid name \n");
        return OK;
    }
    else 
    {
        printf(" the name is wrong\n");
        return CARD_Name_error;
    }
}

/*function to get ExpiryDate */
Card_Errors getCardExpiryDate(CARD_t* ptrCopyCARD_t)
{
	printf(" enter card expiry date \n --> ");
	/*get date*/
	scanf("%s", &ptrCopyCARD_t->CARD_Expiry_Date);

	/*check month*/
	if ((ptrCopyCARD_t->CARD_Expiry_Date[0]=='1') || ( ptrCopyCARD_t->CARD_Expiry_Date[0] == '0'))
	{
        if (((ptrCopyCARD_t->CARD_Expiry_Date[0] == '0') && ((ptrCopyCARD_t->CARD_Expiry_Date[1] >= '1') && (ptrCopyCARD_t->CARD_Expiry_Date[1] <= '9'))) || ((ptrCopyCARD_t->CARD_Expiry_Date[0] == '1') && ((ptrCopyCARD_t->CARD_Expiry_Date[1] >= '0') && (ptrCopyCARD_t->CARD_Expiry_Date[1] <= '2')))) 																  
		{
			printf(" valid data \n");
            return OK;
		}
		else
		{
            printf(" wrong date\n");
            return CARD_ExpiryDate_error;
		}
	}
	else
	{
		printf(" wrong date\n");
		return CARD_ExpiryDate_error;
	}

	/*check year*/
	if((ptrCopyCARD_t->CARD_Expiry_Date[3]>='2' && ptrCopyCARD_t->CARD_Expiry_Date[4]>='0') && (ptrCopyCARD_t->CARD_Expiry_Date[3]<='3'))
	{
        printf(" valid data\n");
        return OK;
	}
	else
	{
		printf(" wrong date\n");
        return CARD_ExpiryDate_error;
	}

}
/*function to get CardPAN */
Card_Errors getCardPAN(CARD_t* ptrCopyCARD_t)
{
	u8 u8locallength=0;
	printf("please enter Card PAN : \n===> ");
	scanf("%s", &(ptrCopyCARD_t->CARD_PAN_Number));
	u8locallength=strlen(ptrCopyCARD_t->CARD_PAN_Number);
	if (u8locallength >= 16) 
	{
        printf(" valid PAN\n");
        return OK;
    }
    else {
        printf(" wrong PAN\n");
        return CARD_PAN_error;
    }
}
