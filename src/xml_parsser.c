/*
** EPITECH PROJECT, 2024
** simple-xml-c
** File description:
** xml_parsser
*/

#include "xml.h"
#include "utils.h"
#include <stdio.h>

static int xml_is_valid_end_tag(char *buf, xml_node_t *current, size_t *index)
{
    unsigned long temp_len;

    if (buf[*index + 1] == '/') {
        temp_len = strlen(current->tag);
        if (strncmp(current->tag, buf + (*index + 2), temp_len - 1) != 0 ||
            *(buf + (*index + 2 + temp_len)) != '>')
            return 0;
        *index += temp_len;
        return 1;
    }
    return 2;
}

static bool skip_start_tag(char **buf, size_t *index)
{
    while ((*buf)[*index] != '<' && (*buf)[*index] != '\0') {
        (*index)++;
    }
    return (*buf)[*index] != '\0';
}

static bool handle_end_tag(char *buf, xml_node_t **current, size_t *index)
{
    int valid_end = xml_is_valid_end_tag(buf, *current, index);

    if (valid_end == 1) {
        *current = (*current)->parent;
        return true;
    }
    return valid_end == 0 ? false : true;
}

bool xml_parser(xml_t *doc, char *content)
{
    size_t index = 0;
    char *buf = str_match(content, "<.*>");
    xml_node_t *current = NULL;

    if (buf == NULL)
        return false;
    while (buf[index] != '\0') {
        if (!skip_start_tag(&buf, &index))
            break;
        if (!handle_end_tag(buf, &current, &index))
            return false;
        xml_add_data(doc, &current, &index, buf);
    }
    return true;
}
