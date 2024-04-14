/*
** EPITECH PROJECT, 2024
** simple-xml-c
** File description:
** xml_get_node_tag
*/

#include <xml.h>
#include <utils.h>

static void get_node_tag_attribute(xml_node *node, char *buf)
{
    char *match = str_match(buf, " .*=\".*\"");
    size_t key_end;
    size_t attribute_end;
    xml_attribute *temp;

    if (match == NULL)
        return;
    while (match++) {
        temp = calloc(1, sizeof(xml_attribute));
        key_end = str_index_of(match, "=\"");
        temp->key = calloc(1, key_end);
        strncpy(temp->key, match, key_end);
        attribute_end = str_index_of(match + key_end + 2, "\"");
        temp->value = calloc(1, attribute_end);
        strncpy(temp->value, match + key_end + 2, attribute_end - 1);
        list_add(node->list_attributes, temp);
        if (*(match + key_end + 2 + attribute_end + 1) == '>')
            return;
        if ((match = str_match(match + key_end + attribute_end + 3, " .*=\".*\"")) == NULL)
            return;
    }
}

size_t xml_get_node_tag(xml_node *node, char *buf)
{
    char *match = str_match(buf, "<.*>");
    size_t i = 0;
    size_t tag_end;

    if (match == NULL)
        return 0;
    get_node_tag_attribute(node, match);
    tag_end = str_index_of(match, " ");
    for (; match[i] != '>'; ++i);
    if (tag_end < i && tag_end > 0) {
        node->tag = calloc(1, tag_end);
        strncpy(node->tag, match + 1, tag_end - 1);
    } else {
        node->tag = calloc(1, i);
        strncpy(node->tag, match + 1, i - 1);
    }
    return i + 1;
}