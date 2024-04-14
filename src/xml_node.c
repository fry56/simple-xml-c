/*
** EPITECH PROJECT, 2024
** simple-xml-c
** File description:
** xml_node
*/

#include <xml.h>

xml_node *xml_new_node(xml_node *parent)
{
    xml_node *node = calloc(1, sizeof(xml_node));

    node->parent = parent;
    node->tag = NULL;
    node->inner_text = NULL;
    node->list_attributes = list_new();
    node->list_children = list_new();
    if (parent)
        list_add(parent->list_children, node);
    return node;
}

void xml_node_free(xml_node *xml_node)
{
    if (xml_node->tag)
        free(xml_node->tag);
    if (xml_node->inner_text)
        free(xml_node->inner_text);
    list_foreach(xml_node->list_attributes, node) {
        free(((xml_attribute *)node->value)->value);
        free(((xml_attribute *)node->value)->key);
        free(node->value);
    }
    list_clear(xml_node->list_attributes);
    free(xml_node->list_attributes);
    list_foreach(xml_node->list_children, node)
    xml_node_free(node->value);
    list_clear(xml_node->list_children);
    free(xml_node->list_children);
    free(xml_node);
}
