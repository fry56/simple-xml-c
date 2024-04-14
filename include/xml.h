/*
** EPITECH PROJECT, 2024
** simple-xml-c
** File description:
** xml
*/

#pragma once

#include <list.h>
#include <stdbool.h>
#include <string.h>
#include <fcntl.h>
#include <unistd.h>
#include <sys/stat.h>

typedef struct xml_file {
    int fd;
    char *path;
    size_t size;
    char *buf;
    size_t lignes;
} xml_file;

typedef struct xml_attribute {
    char *key;
    char *value;
} xml_attribute;

typedef struct xml_node {
    char *tag;
    list *list_attributes;
    char *inner_text;
    struct xml_node *parent;
    list *list_children;
} xml_node;

typedef struct xml {
    char *path;
    xml_node *root;
} xml;

xml *xml_load(const char *path);
void xml_free(xml *doc);
xml_node *xml_new_node(xml_node *parent);
void xml_node_free(xml_node *node);
bool xml_parser(xml *doc, xml_file *file);
void xml_add_data(xml *doc, xml_node **current, size_t *index, char *buf);
size_t xml_get_node_inner_text(xml_node *node, char *buf);
size_t xml_get_node_tag(xml_node *node, char *buf);
xml *xml_new(void);

xml_file *xml_file_open(char *path, int flags, bool buff);
void xml_file_close(xml_file *file);