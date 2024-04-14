/*
** EPITECH PROJECT, 2024
** bac-a-sable
** File description:
** xml_new
*/

#include <xml.h>

xml *xml_new(void)
{
    xml *doc = calloc(1, sizeof(xml));

    if (doc == NULL)
        return NULL;
    doc->root = xml_new_node(NULL);
    return doc;
}
