## Exceptions
    
### W_EXCEPTION_STACK_DECLARE(size)
#### Arguments
```C
size                 the size of the exception stack, e.g. 64
```
#### Description
    Use W_EXCEPTION_STACK_DECLARE to declare an exception stack. Use it in the global scope (outside any function) in a C file. Use also in a header with extern prefix and with emphty size argument.
    
### W_EXCEPTION_RESET_LAST
#### Description
    Use W_EXCEPTION_RESET_LAST to clear all data related to last exception. with extern prefix and with emphty size argument.
    
### W_TRY
#### Description
    Use W_TRY to run code which may cause exceptions. Use W_THROW to throw an exception inside W_TRY block. Use W_CATCH or W_CATCH_ALL to catch exceptions after W_TRY block.
#### Notes
Exception stack must be declared using W_EXCEPTION_STACK_DECLARE.
    
### W_THROW(err[,...])
#### Arguments
```C
err                  an integer other than zero
```
#### Description
    Use W_THROW to throw an exception inside W_TRY block.
    
### W_CATCH(err)
#### Arguments
```C
err                  an integer other than zero
```
#### Description
    Use W_CATCH to catch exceptions of a given error class. It will clear the last exception from memory so another catch following will not trigger.
    
### W_CATCH_ALL
#### Description
    Use W_CATCH_ALL to catch exceptions of all kinds. It will clear the last exception from memory so another catch following will not trigger.
    
### W_EXCEPTION_FPRINTF(out)
#### Description
    Use W_EXCEPTION_FPRINTF to print an error message of latest exception into a file (e.g. stderr).
