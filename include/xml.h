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

typedef struct xml_attribute {
    char *key;
    char *value;
} t_xml_attribute;

typedef struct xml_node {
    char *tag;
    list *list_attributes;
    char *inner_text;
    struct xml_node *parent;
    list *list_children;
} t_xml_node;

typedef struct xml {
    char *source;
    t_xml_node *root;
} t_xml;

t_xml *xml_load(const char *path);
void xml_free(t_xml *doc);
t_xml_node *xml_new_node(t_xml_node *parent);
void xml_node_free(t_xml_node *node);
bool xml_parser(t_xml *doc, tfile_s *file);
void xml_add_data(t_xml *doc, t_xml_node **current, size_t *index, char *buf);
int xml_is_valid_end_tag(char *buf, t_xml_node *current, size_t *index);