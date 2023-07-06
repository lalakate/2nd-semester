#include "hash.h"

int main() {
    FILE *fp;
    hashmap *map;
    map = (hashmap *) malloc(sizeof(hashmap));
    map->capacity = 1;
    map->size = 0;
    map->buckets = (bucket **) calloc(1, sizeof(bucket *));
    fp = fopen("top-1m.txt", "r");
    while (1) {
        int n;
        printf("1 - download information from database\n"
               "2 - find IP address\n"
               "3 - input information\n"
               "4 - delete IP address\n"
               "5 - end the program\n");
        rewind(stdin);
        scanf("%i", &n);
        switch (n) {
            case 1:
                task1(fp, map);
                break;
            case 2:
                task2(map);
                break;
            case 3:
                task3(map);
                break;
            case 4:
                task4(map);
                break;
            case 5:
                free_map(map);
                printf("Bye-bye\n");
                fclose(fp);
                return 0;
            default:
                break;
        }
    }
}
