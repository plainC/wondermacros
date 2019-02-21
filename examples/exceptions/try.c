#include <wondermacros/exceptions/exceptions.h>

#include <stdio.h>

W_EXCEPTION_STACK_DECLARE(64);

void foo()
{
    W_THROW(2, "Error occured in foo\n");
}

int main()
{
#define FILE_ERROR 2

    W_TRY {
        char* filename = "not_found";
        FILE* file = fopen(filename,"r");
        if (!file)
            W_THROW(FILE_ERROR,"%s was not there", filename);
        printf("Does not print\n");
    }
    W_CATCH(4) {
        printf("Should not print\n");
    }
    W_CATCH(FILE_ERROR) {
        W_EXCEPTION_FPRINTF(stdout);
    }
    W_CATCH(FILE_ERROR) {
        printf("Should not print since catched already\n");
    }


    W_TRY {
        foo();
        printf("Should not print\n");
    }
    W_CATCH_ALL {
        W_EXCEPTION_FPRINTF(stdout);
    }
}
