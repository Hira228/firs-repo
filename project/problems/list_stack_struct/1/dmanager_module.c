// Создать структуру дверей в src/door_struct.h. Сама структура состоит из целочисленного 
// id двери и целочисленного status'а (0 - закрыто, 1 - открыто). Исправить программу src/dmanager_module.c так, 
// чтобы она отсортировала проинициализированный массив дверей по возрастанию id дверей любым алгоритмом и вывела его в 
// формате: "id двери, статус двери".


#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#include "door_struct.h"

#define DOORS_COUNT 15
#define MAX_ID_SEED 10000

void initialize_doors(struct door *doors);
void sotr_struct(struct door *doors);

int main() {
    struct door doors[DOORS_COUNT];
    initialize_doors(doors);
    sotr_struct(doors);
    for(int i = 0; i < DOORS_COUNT; i++)
    {
        printf("%d, %d\n", (doors + i) -> id, (doors + i) -> status);
    }
    
    return 0;
}

void initialize_doors(struct door* doors) {
    srand(time(0));

    int seed = rand() % MAX_ID_SEED;
    for (int i = 0; i < DOORS_COUNT; i++) {
        doors[i].id = (i + seed) % DOORS_COUNT;
        doors[i].status = rand() % 2;
    }
}

int tmp = 0;

void sotr_struct(struct door *doors)
{
    for(int i = 0; i < DOORS_COUNT; i++)
    {
        (doors + i) -> status = 0;
        for(int j = 0; j < DOORS_COUNT - 1; j++)
        {
            if((doors + j) -> id > (doors + i) -> id)
            {
                tmp = (doors + j) -> id;
                (doors + j) -> id = (doors + i) -> id;
                (doors + i) -> id = tmp;
            }
        }
    }
}
