/*
** EPITECH PROJECT, 2024
** bac-a-sable
** File description:
** xml_get_node_by_tag
*/

#include <xml.h>

xml_node_t *xml_get_node_by_tag(xml_node_t *node, char *tag)
{
    xml_node_t *res;

    if (node == NULL || tag == NULL || node->tag == NULL)
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
