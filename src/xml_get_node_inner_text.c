/*
** EPITECH PROJECT, 2024
** simple-xml-c
** File description:
** xml_get_inner_text
*/

int xml_get_node_inner_text(t_xml_node *node, char *buf)
{
    int index = 0;

    for (; buf[index] != '\0'; ++index) {
        if (buf[index] == '<')
            break;
    }
    if (index > 0)
        node->inner_text = tstr_ncpy(NULL, buf, index - 1);
    return index;
}

