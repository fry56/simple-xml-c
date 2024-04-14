/*
** EPITECH PROJECT, 2024
** bac-a-sable
** File description:
** xml_str
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <xml.h>

char *append_str(char *orig, const char *append) {
    size_t orig_len = orig ? strlen(orig) : 0;
    size_t append_len;
    char *new_str;

    if (!append)
        return orig;
    append_len = strlen(append);
    new_str = realloc(orig, orig_len + append_len + 1);
    if (!new_str) {
        free(orig);
        return NULL;
    }
    memcpy(new_str + orig_len, append, append_len + 1);
    return new_str;
}

char *serialize_attributes(list *attrs)
{
    char *result = strdup("");
    char buffer[256];
    char *temp;
    xml_attribute *attr;

    if (!attrs) return result;
    for (list_node *node = attrs->head; node; node = node->next) {
        attr = (xml_attribute *)node->value;
        buffer[0] = '\0';
        sprintf(buffer, " %s=\"%s\"", attr->key, attr->value);
        temp = append_str(result, buffer);
        if (!temp) {
            free(result);
            return NULL;
        }
        result = temp;
    }
    return result;
}

void serialize_node_elem(xml_node *node, char **result)
{
    char *temp;

    for (list_node *child = node->list_children->head; child; child = child->next) {
        char *child_str = serialize_node((xml_node *) child->value);

        if (!child_str)
            continue;
        temp = append_str(*result, child_str);
        free(child_str);
        if (!temp) {
            free(*result);
            return;
        }
        *result = temp;
    }
}

char *serialize_node_content(xml_node *node)
{
    char *result = strdup("");
    char *temp;

    if (node->inner_text) {
        temp = append_str(result, node->inner_text);
        if (!temp) {
            free(result);
            return NULL;
        }
        result = temp;
    }
    serialize_node_elem(node, &result);
    return result;
}

char *serialize_node(xml_node *node)
{
    char *attrs = serialize_attributes(node->list_attributes);
    char *content = serialize_node_content(node);
    char *tag_start = malloc(strlen(node->tag) + strlen(attrs) + 3);
    char *tag_end = malloc(strlen(node->tag) + 4);
    char *result;

    sprintf(tag_start, "<%s%s>", node->tag, attrs ? attrs : "");
    sprintf(tag_end, "</%s>", node->tag);
    result = append_str(tag_start, content);
    result = append_str(result, tag_end);
    free(attrs);
    free(content);
    free(tag_end);
    return result;
}

char *xml_str(xml *doc)
{
    if (!doc || !doc->root) return NULL;
    char *result = serialize_node(doc->root);
    return result;
}
