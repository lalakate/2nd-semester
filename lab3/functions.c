#include "functions.h"

int sort_condition(Paintball tmp, Paintball pj, char choose) {
    if (choose == '1') return (pj.id > tmp.id);
    else if (choose == '2') return (strcmp(pj.name, tmp.name) > 0);
    else if (choose == '3') return (strcmp(pj.type, tmp.type) > 0);
    else if (choose == '4') return (pj.quantity > tmp.quantity);
    else if (choose == '5') {
        if (pj.year > tmp.year) return 1;
        else if (pj.month > tmp.month) return 1;
        else if (pj.day > tmp.day) return 1;
    }
}

void insertion_sort(Paintball *paintball, int size, char choose) {
    for (int m = 0; m < size; m++) {
        int j;
        Paintball tmp = paintball[m];
        for (j = m - 1; j >= 0 && sort_condition(tmp, paintball[j], choose); j--)
            paintball[j + 1] = paintball[j];
        paintball[j + 1] = tmp;
    }
}

void save(Paintball *paintball, int size) {
    FILE *fp = fopen("bd_data.bin", "wb");
    if (size != 0) {
        fwrite(&size, sizeof(int), 1, fp);
        fwrite(paintball, sizeof(Paintball), size, fp);
    }
    fclose(fp);
}

void load(Paintball **paintball, int *size) {
    FILE *fp = fopen("bd_data.bin", "rb");
    fread(&(*size), sizeof(int), 1, fp);
    (*paintball) = realloc((*paintball), (*size) * sizeof(Paintball));
    fread((*paintball), sizeof(Paintball), (*size), fp);
    fclose(fp);
}

void load_previously_entered_data(Paintball **paintball, int *size) {
    printf("\nDo you wanna load previously entered data?\n"
           "1. yes\n"
           "2. no\n");

    char load_choose;
    while (!scanf("%c", &load_choose) || load_choose > '2' || load_choose < '1' || getchar() != '\n') {
        printf("Wrong input. Try again.\n");
        rewind(stdin);
    }

    if (load_choose == '1') {
        FILE *fp = fopen("bd_data.bin", "rb");
        fseek(fp, 0, SEEK_END);
        if (ftell(fp) == 0) {
            printf("There is no previously entered data\n");
            fclose(fp);
        } else {
            fclose(fp);
            load(&(*paintball), &(*size));
        }
    }
}

void append(char **s, char c, int *len, int *capacity) {
    (*len)++;
    if (*capacity < *len) {
        *capacity *= 2;
        *s = realloc(*s, sizeof(char) * (*capacity));
    }
    (*s)[(*len) - 1] = c;
}

char *read_string_safe() {
    char c;
    int len = 0;
    int capacity = 1;
    char *s = malloc(sizeof(char) * capacity);
    _Bool read_first = 1;
    while ((c = getchar()) != '\n' || read_first) {
        if (c == '\n')
            continue;
        read_first = 0;
        append(&s, c, &len, &capacity);
    }
    append(&s, '\0', &len, &capacity);
    return s;
}

int stock_availability(char *name, Paintball paintball) {
    int flg = 0;
    if (strlen(name) > strlen(paintball.name)) flg = 0;
    for (int i = 0; i < strlen(name); i++) {
        if (name[i] != paintball.name[i]) {
            flg = 0;
            break;
        } else flg = 1;
    }
    return flg;
}

//int stock_availability(char* name, Paintball paintball){
//    if(strlen(name) > strlen(paintball.name)){ return 0;}
//    for(int i = 0; i < strlen(name) - 1; i++){
//        if(name[i] != paintball.name[i]){ return 0;
//            }
//
//    }return 1;
//
//}
//
void task1(Paintball *paintball, int size) {
    char *name; //= giveMemory(300);
    int flg = 0;
    printf("Enter the name for searching:\n");
    name = read_string_safe();
    //rewind(stdin);
    //name = enterStr(name);

    for (int i = 0; i < size; i++) {
        if (stock_availability(name, paintball[i]) == 0) {
            flg = 0;
        } else {
            flg = 1;
            break;
        }
    }
    if (flg) printf("Equipment is in warehouse\n");
    else printf("Equipment is not found\n");
}

char *enterStr(char *string) {
    if (!string) return NULL;
    int i = 0;

    while ((*(string + i++) = (char) getchar()) != '\n');
    string[--i] = '\0';
    return string;
}

char *giveMemory(int n) {
    char *array = (char *) calloc(n + 1, sizeof(char));
    return array;
}