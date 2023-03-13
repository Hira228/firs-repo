Разработать программу src/list.c, в которой содержатся реализации функций по работе 
с односвязным списком дверей (`struct node* init(struct door* door)` - инициализация структуры
односвязного списка на базе переданной `struct door`,
`struct node* add_door(struct node* elem, struct door* door)` - вставка нового элемента `struct door` в односвязный список после переданного узла `elem`,
`struct node* find_door(int door_id, struct node* root)` - поиск двери в списке по её id,
`struct node* remove_door(struct node* elem, struct node* root)` - удаление элемента списка,
`void destroy(struct node* root)` - освобождение памяти, занимаемой структурой списка). 
Объявления этих функций и структуру односвязного списка вынести в файл src/list.h. 
Написать модульные тесты для проверки работы функций add_door и remove_door односвязного списка в src/list_test.c.