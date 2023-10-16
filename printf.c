#include <stdio.h>
#include <stdarg.h>
/**
 * print_number - Function to print number
 * @number: number to be printed
 */
void print_number(int number)
{
    if (number < 0){
        putchar('-');
        number = -number;
    }
    if (number == 0)
    {
        putchar('0');
        return;
    }
    if (number / 10 != 0)
    {
                print_number(number / 10);
    }
    putchar('0' + number % 10);
}

/**
 * _printf - Function to print to the stdout
 * @format: the type to be converted
 * Return: the number of characters printed
*/
int _printf(const char *format,...)
{
    va_list args;

    va_start(args, format);
    int i = 0;
    int num;

    while(*format)
    {
        if (*format == '%')
        {
            format++;
            switch (*format){
                case 's':
                {
                   const char *string = va_arg(args, const char *);
                    while(*string)
                    {
                        putchar(*string);
                        string++;
                        i++;
                    }
                }
                    break;
                case 'c':
                    putchar(va_arg(args,int));
                    i++;
                break;
                case '%':
                    putchar('%');
                    i++;
                    break;
                case 'i':
                case 'd':
                {
                    num = (va_arg(args, int));
                    print_number(num);
                    i++;
                }
                    break;
                default:
                    putchar('%');
                    i++;
                    break;
            }
        }
        else
        {
            putchar(*format);
            i++;
        }
        format++;
    }
    va_end(args);
    return i;
}
int main() {
    int count = _printf("Hello, %c world! This is a %s example.%% Integer: %d, Another: %i\n", 'C', "printf", 100, -123);
    printf("Total characters printed: %d\n", count);
    return 0;
}