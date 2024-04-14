/*
** EPITECH PROJECT, 2024
** simple-xml-c
** File description:
** xml_load
*/

#include "xml.h"
#include <stdlib.h>

xml *xml_load(const char *path)
{
    xml *doc = calloc(1, sizeof(xml));
    xml_file *file = xml_file_open((char *)path, O_RDONLY, true);

    if (doc == NULL || file == NULL)
        return NULL;
    doc->root = xml_new_node(NULL, NULL, NULL);
    if (!xml_parser(doc, file->buf)) {
        xml_free(doc);
        return NULL;
    }
    xml_file_close(file);
    return doc;
}
