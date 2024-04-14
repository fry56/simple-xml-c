/*
** EPITECH PROJECT, 2024
** bac-a-sable
** File description:
** xml_get_node_by_tag
*/

#include <xml.h>

xml_node *xml_get_node_by_tag(xml_node *node, char *tag)
{
    xml_node *res;

    if (node == NULL)
        return NULL;
    if (strcmp(node->tag, tag) == 0)
        return node;
    list_foreach(node->list_children, tmp)
    {
        res = xml_get_node_by_tag(tmp->value, tag);
        if (res != NULL)
            return res;
    }
    return NULL;
}
