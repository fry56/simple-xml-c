/*
** EPITECH PROJECT, 2024
** simple-xml-c
** File description:
** xml_get_node_tag
*/

static void get_node_tag_attribute(t_xml_node *node, char *buf)
{
    char *match = tstr_match(buf, " .*=\".*\"");;
    int key_end, attribute_end;
    t_xml_attribute *temp;

    if (match == NULL)
        return;
    while (match++) {
        tassert((temp = tcalloc(1, sizeof(t_xml_attribute))) == NULL);
        key_end = tstr_index_of(match, "=\"");
        temp->key = tstr_ncpy(NULL, match, key_end - 1);
        attribute_end = tstr_index_of(match + key_end + 2, "\"");
        temp->value = tstr_ncpy(NULL, match + key_end + 2, attribute_end - 1);
        tlist_add(node->list_attributes, temp);
        if (*(match + key_end + 2 + attribute_end + 1) == '>')
            return;
        if ((match = tstr_match(match + key_end + attribute_end + 3,
                                " .*=\".*\"")) == NULL)
            return;
    }
}

int xml_get_node_tag(t_xml_node *node, char *buf)
{
    char *match = tstr_match(buf, "<.*>");
    int i = 0;
    int tag_end;

    if (match == NULL)
        return 0;
    get_node_tag_attribute(node, match);
    tag_end = tstr_index_of(match, " ");
    for (; match[i] != '>'; ++i);
    if (tag_end < i && tag_end > 0)
        node->tag = tstr_ncpy(NULL, match + 1, tag_end - 2);
    else
        node->tag = tstr_ncpy(NULL, match + 1, i - 2);
    return i + 1;
}