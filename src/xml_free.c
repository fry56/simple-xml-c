/*
** EPITECH PROJECT, 2023
** xml_free.c
** File description:
** desc
*/

#include <t_xml_token.h>
#include <stdlib.h>

void t_xml_free(t_xml *doc)
{
    t_xml_node_free(doc->root);
    free(doc);
}