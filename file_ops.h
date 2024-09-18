#ifndef FILE_OPS_H
#define FILE_OPS_H

void save_item(const char *filename, const char *item);
void list_items(const char *filename);
void edit_item(const char *filename, const char *old_item, const char *new_item);
void delete_item(const char *filename, const char *item);

#endif // FILE_OPS_H