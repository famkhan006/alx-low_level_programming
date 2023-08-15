#include <stdlib.h>
#include "dog.h"

/**
 * _strlen - returns the length of a string
 * @str: string to evaluate
 *
 * Return: the length of the string
 */
int _strlen(char *str)
{
    int length = 0;

    while (str[length] != '\0')
    {
        length++;
    }

    return (length);
}

/**
 * _strcpy - copies the string pointed to by src
 * including the terminating null byte (\0)
 * to the buffer pointed to by dest
 * @dest: pointer to the buffer in which we copy the string
 * @src: string to be copied
 *
 * Return: the pointer to dest
 */
char *_strcpy(char *dest, char *src)
{
    int length = 0;
    int i;

    while (src[length] != '\0')
    {
        length++;
    }

    for (i = 0; i < length; i++)
    {
        dest[i] = src[i];
    }
    dest[i] = '\0';

    return (dest);
}

/**
 * new_dog - creates a new dog
 * @name: name of the dog
 * @age: age of the dog
 * @owner: owner of the dog
 *
 * Return: pointer to the new dog (Success), NULL otherwise
 */
dog_t *new_dog(char *name, float age, char *owner)
{
    dog_t *newDog;
    int len1, len2;

    len1 = _strlen(name);
    len2 = _strlen(owner);

    newDog = malloc(sizeof(dog_t));
    if (newDog == NULL)
        return (NULL);

    newDog->name = malloc(sizeof(char) * (len1 + 1));
    if (newDog->name == NULL)
    {
        free(newDog);
        return (NULL);
    }
    newDog->owner = malloc(sizeof(char) * (len2 + 1));
    if (newDog->owner == NULL)
    {
        free(newDog);
        free(newDog->name);
        return (NULL);
    }
    _strcpy(newDog->name, name);
    _strcpy(newDog->owner, owner);
    newDog->age = age;

    return (newDog);
}
