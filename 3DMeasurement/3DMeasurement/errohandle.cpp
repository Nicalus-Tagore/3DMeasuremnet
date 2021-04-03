#include "errohandle.h"
#include <QMessageBox>
#include "NIMCExample.h"
#include "MotnCnst.h"
#include "flexmotn.h"


ErroHandle::ErroHandle(QWidget *parent) : QWidget(parent)
{
}

void ErroHandle::nimcDisplayError(i32 errorCode, u16 commandID, u16 resourceID)
{
    i8 *errorDescription;//Pointer to i8's -  to get error description
    u32 sizeOfArray;//Size of error description
    u16 descriptionType;//The type of description to be printed
    i32 status;//Error returned by function

    if(commandID == 0){
        descriptionType = NIMC_ERROR_ONLY;
    }else{
        descriptionType = NIMC_COMBINED_DESCRIPTION;
    }

    sizeOfArray = 0;
    errorDescription = NULL;

    status = flex_get_error_description(descriptionType, errorCode, commandID, resourceID, errorDescription, &sizeOfArray );

    errorDescription = new i8[sizeOfArray + 1];
    sizeOfArray++;

    status = flex_get_error_description(descriptionType, errorCode, commandID, resourceID, errorDescription, &sizeOfArray );

    if (errorDescription != NULL){
        QMessageBox::warning(this,"Error",errorDescription);
        //printf(errorDescription);	//Print description to screen
        //free(errorDescription);		//Free allocated memory
        delete [] errorDescription;
    }else{
        printf("Memory Allocation Error");
    }
}


