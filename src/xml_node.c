/*
** EPITECH PROJECT, 2024
** simple-xml-c
** File description:
** xml_node
*/

t_xml_node *t_xml_new_node(t_xml_node *parent)
{
    t_xml_node *node = tcalloc(1, sizeof(t_xml_node));

    tassert(node == NULL);
    node->parent = parent;
    node->tag = NULL;
    node->inner_text = NULL;
    node->list_attributes = tlist_new();
    node->list_children = tlist_new();
    if (parent)
        tlist_add(parent->list_children, node);
    return node;
}

void t_xml_node_free(t_xml_node *xml_node)
{
    if (xml_node->tag)
        free(xml_node->tag);
    if (xml_node->inner_text)
        free(xml_node->inner_text);
    list_foreach(xml_node->list_attributes, node) {
        free(((t_xml_attribute *)node->value)->value);
        free(((t_xml_attribute *)node->value)->key);
        free(node->value);
    }
    tlist_clear(xml_node->list_attributes);
    free(xml_node->list_attributes);
    list_foreach(xml_node->list_children, node)
    t_xml_node_free(node->value);
    tlist_clear(xml_node->list_children);
    free(xml_node->list_children);
    free(xml_node);
}
