#include <stdio.h>
#include "String.h"
#include <errno.h>
static char *my_strtok_helper(char *str, const char *delim);


void *my_memchr(const void *str, int c, size_t n)
{
    unsigned char *ptr = (unsigned char*)str;
    unsigned int *result = NULL;
    while (NULL != str && 0 != n-- )
    {
        if ((unsigned char)c == *ptr)
        {
            result = ptr;
            break;
        }
        else
        {
            ptr++;
        }
    }
    return result;
}

int my_memcmp(const void *str1, const void *str2, size_t n)
{
    unsigned char *ptr1 = (unsigned char *)str1, *ptr2 = (unsigned char *)str2;
    signed int ret = 0;
    while (NULL != str1 && NULL != str2 && n--)
    {
        if ('\0' == *ptr1 && '\0' != *ptr2)
        {
            ret = -1;
            break;
        }
        else if ('\0' == *ptr2 && '\0' != *ptr1)
        {
            ret = 1;
            break;
        }
        else
        {
            ret = 0;
        }
        ptr1++;
        ptr2++;
    }
    return (ret);
}

void *my_memcpy(void *dest, const void * src, size_t n)
{
    unsigned char *ptr1 = (unsigned char *)dest;
    unsigned char *ptr2 = (unsigned char *)src;
    while (NULL != dest && NULL != src && n--)
    {
        *ptr1 = *ptr2;
        ptr1++;
        ptr2++;
    }
    return dest;
}

void *my_memmove(void *str1, const void *str2, size_t n)
{
    unsigned char *ptr1 = (unsigned char *)str1, *ptr2 = (unsigned char *)str2;
    while (NULL != str2 && n--)
    {
        *ptr1 = *ptr2;
        ptr1++;
        ptr2++;
    }
    return str1;
}

void *my_memset(void *str, int c, size_t n)
{
    unsigned char *ptr1 = (unsigned char *)str, *ptr2 = (unsigned char*)c;
    while (NULL != str && n--)
    {
        *ptr1 = *ptr2;
        ptr1++;
        ptr2++;
    }
    return str;
}

char *my_strcat(char *dest, const char *src)
{
    char *ptr = dest + strlen(dest);
    while('\0' != *src)
    {
        *ptr = *src;
        src++;
        ptr++;
    }
    *ptr ='\0';

    return dest;
}

char *my_strncat(char *dest, const char *src, size_t n)
{

    char *ptr = dest + strlen(dest);
    while(n--)
    {
        *ptr = *src;
        src++;
        ptr++;
    }
    *ptr ='\0';

    return dest;

}

char *my_strchr(const char *str, int c)
{
    while('\0' != *str)
    {
        if ((unsigned char)c != *str)
        {
            str++;
        }
        else
        {
            break;
        }
    }
    if ('\0' == *str)
    {
        return NULL;
    }
    return str;
}

int   my_strcmp(const char *str1, const char *str2)
{
    unsigned int temp_lenght = 0;
    if (strlen(str1) > strlen(str2))
    {
        temp_lenght = strlen(str1);
    }
    else
    {
        temp_lenght = strlen(str2);
    }
    return my_memcmp(str1, str2, temp_lenght);
}

int   my_strncmp(const char *str1, const char *str2, size_t n)
{
    return my_memcmp(str1, str2, n);
}

int   my_strcoll(const char *str1, const char *str2)
{
    unsigned int temp_lenght = 0;
    if (strlen(str1) > strlen(str2))
    {
        temp_lenght = strlen(str1);
    }
    else
    {
        temp_lenght = strlen(str2);
    }
    return my_memcmp(str1, str2, temp_lenght);
}

char  *my_strcpy(char *dest, const char *src)
{
    char *ptr1 = dest;
    char *ptr2 = src;
    unsigned int n = strlen(src);
    while (NULL != dest && NULL != src && n--)
    {
        *ptr1 = *ptr2;
        ptr1++;
        ptr2++;
    }
    *ptr1 = '\0';
    return dest;
}

char  *my_strncpy(char *dest, const char *src, size_t n)
{
    char *ptr1 = dest;
    char *ptr2 = src;
    while (NULL != dest && NULL != src && n--)
    {
        *ptr1 = *ptr2;
        ptr1++;
        ptr2++;
    }
    return dest;
}

size_t my_strcspn(const char *str1, const char *str2) //problem
{
    unsigned int Number = 0;
    unsigned int length1 = strlen(str1) , length2 = strlen(str2);
    unsigned int ret = length1-1;
    for (int counter1 = 0 ; counter1 < length1 ; counter1++)
    {
        for(int counter2 = 0 ; counter2 < length2 ; counter2++)
        {
            if (str1[counter1] == str2[counter2])
            {
                ret--;
                break;
            }
        }
    }
    return ret;
}

char *my_strerror(int errnum)
{
    char *ptr = "No such file or directory";
    if (errno == errnum)
    {
        return ptr;
    }
    return NULL;
}

size_t my_strlen(const char *str)
{
    char *ptr = str;
    unsigned int length = 0;
    if (NULL != str)
    {
        while('\0' != *ptr)
        {
            length++;
            ptr++;
        }
    }
    else
    {
        printf("NULL Pointer!!");
    }
    return length;
}

char *my_strpbrk(const char *str1, const char *str2)
{
    char *ptr1 = str1, *ptr2 = str2;
    while ('\0' != *ptr1)
    {
        for (int counter = 0 ; counter < strlen(str1) ; counter++)
        {
            if (*ptr1 == *ptr2)
            {
                return ptr1;
            }
            else
            {
                ptr1++;
            }
        }
        ptr2++;
        ptr1 = str1;
    }
    return NULL;
}

char *my_strrchr(const char *str, int c)
{
    char *ptr = str + my_strlen(str);
    unsigned int length = strlen(str);
    while (length--)
    {
        if (*ptr == (unsigned char)c)
        {
            return ptr;

        }
        else
        {
            ptr--;
        }
    }
    return NULL;
}

size_t my_strspn(const char *str1, const char *str2)
{
    char *ptr1 = str1, *ptr2 = str2;
    unsigned int length = strlen(str1), Number = 0;
    while (length--)
    {
        if (*ptr1 == *ptr2)
        {
            Number++;
        }
        ptr1++;
        ptr2++;
    }
    return Number;
}

size_t my_strxfrm(char *dest, const char *src, size_t n)
{
    char *ptr1 = dest, *ptr2 = src;
    unsigned int Number = strlen(src);
    if (0 == n)
    {
        *dest = NULL;
        return Number;
    }
    while(n--)
    {
        *ptr1 = *ptr2;
        ptr1++;
        ptr2++;
    }
    return Number;
}

char *my_strstr(const char *haystack, const char *needle)
{
    char *ptr1 = haystack, *ptr2 = needle;
    unsigned int length = strlen(ptr1);
    while(length--)
    {
        if (*ptr1 == *ptr2)
        {
            return ptr1;
        }
        else
        {
            ptr1++;
        }
    }
    return NULL;
}

char *my_strtok(char *str, const char *delim)
{
    static char *repeat = NULL , *p = NULL;
    unsigned int i = 0;
    char *Result = NULL;
    if (NULL == str)
    {
        str = repeat;
        *p= my_strtok_helper(str, delim);
        goto NULL_condition;
    }
    char *ptr1 = str, *ptr2 = delim;
    unsigned int length = strlen(str);
    Result = malloc(sizeof (char) * length);
    while('\0' != *ptr1)
    {
        while('\0' != *ptr2)
        {
            if (*ptr1 != *ptr2)
            {
                *(Result+i) = *ptr1;

            }
            else
            {
                break;
            }
            ptr2++;
        }
        if (*ptr1 != *ptr2)
        {
            i++;
            ptr1++;
            ptr2 = delim;
        }
        else
        {
            break;
        }
    }
    {
        if (p !=NULL)
        {
          NULL_condition:
            repeat = ++p;
            return p;
        }
    }
    *(Result+i) = '\0';
    repeat = (++ptr1);
    return Result;
}
static char *my_strtok_helper(char *str, const char *delim)
{
    static char *repeat = NULL;
    unsigned int i = 0;
    char *Result = NULL;
    char *ptr1 = str, *ptr2 = delim;
    unsigned int length = strlen(str);
    Result = malloc(sizeof (char) * length);
    while('\0' != *ptr1)
    {
        while('\0' != *ptr2)
        {
            if (*ptr1 != *ptr2)
            {
                *(Result+i) = *ptr1;

            }
            else
            {
                break;
            }
            ptr2++;
        }
        if (*ptr1 != *ptr2)
        {
            i++;
            ptr1++;
            ptr2 = delim;
        }
        else
        {
            break;
        }
    }
    *(Result+i) = '\0';
    repeat = (++ptr1);
    return Result;
}



