/*************************************************************************/
/*************************************************************************/
/************************** Name: Taher Mohamed   ************************/
/************************** File name: Terminal.c ************************/
/*************************************************************************/
/*************************************************************************/
/*includes*/
#include "terminal.h"
#include "card.h"

/*func to get TransactionDate */
TerminalError_t getTransactionDate(Terminal_t* ptrCopyTermData)
{
	u8 u8Local_date[6];
	printf("please enter Transaction Date MM/YY : \n==> ");

	/*get date*/
	scanf("%5s", &ptrCopyTermData->transactionDate);
	strcpy(u8Local_date,ptrCopyTermData->transactionDate);

	/*check month*/
	if (u8Local_date[0]=='0' || u8Local_date[0] == '1')
	{
        if ((u8Local_date[0] == '1' && (u8Local_date[1] >= '0' && u8Local_date[1] <= '2')) ||
            (u8Local_date[0] == '0' && (u8Local_date[1] >= '1' && u8Local_date[1] <= '9'))) 																  
		{
			printf(" OK\n");
            return OK;
		}
		else
		{
            printf(" WRONG_DATE\n");
            return WRONG_DATE;
		}
	}
	else
	{
		printf(" WRONG_DATE\n");
		return WRONG_DATE;
	}


	/*check year*/
	if((u8Local_date[3]>='2' && u8Local_date[4]>='2') && (u8Local_date[3]<='3'))
	{
        printf(" OK\n");
        return OK;
	}
	else
	{
		printf(" WRONG_DATE\n");
        return WRONG_DATE;
	}

}
/*func to check TransactionDate */
TerminalError_t isCardExpired(CARD_t* ptrCopyCardData,Terminal_t* ptrCopyTermData)
{		/*year check*/
	if (ptrCopyTermData->transactionDate[3]<ptrCopyCardData->CARD_Expiry_Date[3]) /*year check*/
	{
		/*true*/
		printf(" Ok, Card expiry Date  is Valid \n");
		return Ok;
	}
	else if (ptrCopyTermData->transactionDate[3]>ptrCopyCardData->CARD_Expiry_Date[3])
	{
		/*false*/
		printf(" EXPIRED_CARD\n");
		return EXPIRED_CARD;
	}
	else if (ptrCopyTermData->transactionDate[3]==ptrCopyCardData->CARD_Expiry_Date[3])
	{
		if (ptrCopyTermData->transactionDate[4]<ptrCopyCardData->CARD_Expiry_Date[4])
		{
			/*true*/
			printf(" Ok, Card expiry Date  is Valid \n");
			return Ok;
		}
		else if (ptrCopyTermData->transactionDate[4]>ptrCopyCardData->CARD_Expiry_Date[4])
		{
			/*false*/
			printf(" EXPIRED_CARD\n");
			return EXPIRED_CARD;
		}
		else if (ptrCopyTermData->transactionDate[4]==ptrCopyCardData->CARD_Expiry_Date[4])
		{
			/*check mounth*/
			if (ptrCopyTermData->transactionDate[0]<ptrCopyCardData->CARD_Expiry_Date[0])
			{
				/*true*/
				printf(" Ok, Card expiry Date  is Valid \n");
				return Ok;

			}
			else if(ptrCopyTermData->transactionDate[0]>ptrCopyCardData->CARD_Expiry_Date[0])
			{
				/*false*/
				printf(" EXPIRED_CARD\n");
				return EXPIRED_CARD;
			}
			else if (ptrCopyTermData->transactionDate[0]==ptrCopyCardData->CARD_Expiry_Date[0])
			{
				if(ptrCopyTermData->transactionDate[1]<ptrCopyCardData->CARD_Expiry_Date[1])
				{
					/*true*/
					printf(" Ok, Card expiry Date  is Valid \n");
					return Ok;
				}
				else if (ptrCopyTermData->transactionDate[1]>ptrCopyCardData->CARD_Expiry_Date[1])
				{
					/*false*/
					printf(" EXPIRED_CARD\n");
					return EXPIRED_CARD;
				}
				else if(ptrCopyTermData->transactionDate[1]==ptrCopyCardData->CARD_Expiry_Date[1])
				{
					/*true*/
					printf(" Ok, Card expiry Date  is Valid \n");
					return Ok;
				}
				else
				{
					/*false*/
					printf(" EXPIRED_CARD\n");
					return EXPIRED_CARD;
				}

			}
			else
			{
				/*false*/
				printf(" EXPIRED_CARD\n");
				return EXPIRED_CARD;
			}

		}
		else
		{
			/*false*/
			printf(" EXPIRED_CARD\n");
			return EXPIRED_CARD;
		}
	}
	else
	{
		/*false*/
		printf(" EXPIRED_CARD\n");
		return EXPIRED_CARD;

	}

}

/*Set max Amount to one transaction*/
TerminalError_t setMaxAmount(Terminal_t* ptrCopyTermData)
{
	    ptrCopyTermData->maxTransAmount = (f32)10000.00;

    if (ptrCopyTermData->maxTransAmount <= (f32)0) 
        return INVALID_MAX_AMOUNT;
    else {
        printf(" max tarnsaction amount is set to 10000.00$\n");
        return Ok;
    }
}
/*func to get Transaction Amount */
TerminalError_t getTransactionAmount(Terminal_t* ptrCopyTermData)
{
	 printf("please enter the transaction amount : \n==> ");
    scanf("%f", &(ptrCopyTermData->transAmount));

    if (ptrCopyTermData->transAmount <= (f32)0) {
        printf(" INVALID_AMOUNT\n");
        return INVALID_AMOUNT;
    }
    else 
    {
        return Ok;
    }
}

/*func to check Amount is valid      */
TerminalError_t isBelowMaxAmount(Terminal_t* ptrCopyTermData)
{
	 if (ptrCopyTermData->transAmount > ptrCopyTermData->maxTransAmount) {
        printf(" EXCEED MAX AMOUNT\n");
        return EXCEED_MAX_AMOUNT;
    }
    else
     {
        printf(" %0.2f is valid amount \n", ptrCopyTermData->transAmount);
        return Ok;
    }
}
