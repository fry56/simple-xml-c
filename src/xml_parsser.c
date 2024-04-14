/*
** EPITECH PROJECT, 2024
** simple-xml-c
** File description:
** xml_parsser
*/

#include <string.h>

int xml_is_valid_end_tag(char *buf, xml_node *current, size_t *index)
{
    int temp_len;

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

bool xml_parser(xml *doc, tfile_s *file)
{
    size_t index = 0;
    char *buf = tstr_match(file->buf, "<.*>");
    xml_node *current = NULL;
    int valide_end;

    while (buf[index] != '\0') {
        if (buf[index] != '<') {
            index++;
            continue;
        }
        valide_end = xml_is_valid_end_tag(buf, current, &index);
        if (valide_end == 1) {
            current = current->parent;
            continue;
        }
        if (valide_end == 0)
            return false;
        xml_add_datas(doc, &current, &index, buf);
    }
    return true;
}
