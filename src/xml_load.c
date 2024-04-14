/*
** EPITECH PROJECT, 2024
** simple-xml-c
** File description:
** xml_load
*/

xml *xml_load(const char *path)
{
    xml *doc = calloc(1, sizeof(t_xml));
    //tfile_s *file = tpath_open_file((char *)path, O_RDONLY, true);

    if (doc == NULL || file == NULL)
        return NULL;
    doc->root = xml_new_node(NULL);
    if (!xml_parser(doc, file)) {
        t_xml_free(doc);
        return NULL;
    }
    //tpath_close_file(file);
    return doc;
}
