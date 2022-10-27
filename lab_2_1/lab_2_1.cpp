#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <windows.h>

struct glasses {
    int glasses_price;
    char *glasses_name;
    char *glasses_color;
};

struct cap {
    int cap_price;
    char *cap_name;
    char *cap_color;
};

struct shorts {
    int shorts_price;
    char *shorts_name;
    char *shorts_color;
};

struct slippers {
    int slippers_price;
    int slippers_size;
    char *slippers_name;
};

struct swim {
    struct glasses your_glasses;
    struct cap your_cap;
    struct shorts your_shorts;
    struct slippers your_slippers;
};

void init(struct swim *a){
    a->your_glasses.glasses_price = 0;
    a->your_glasses.glasses_name = (char*)calloc(30, (sizeof(char)));
    a->your_glasses.glasses_color = (char*)calloc(30, (sizeof(char)));

    a->your_cap.cap_price = 0;
    a->your_cap.cap_name = (char*)calloc(30, (sizeof(char)));
    a->your_cap.cap_color = (char*)calloc(30, (sizeof(char)));

    a->your_shorts.shorts_price = 0;
    a->your_shorts.shorts_name = (char*)calloc(30, (sizeof(char)));
    a->your_shorts.shorts_color = (char*)calloc(30, (sizeof(char)));

    a->your_slippers.slippers_price = 0;
    a->your_slippers.slippers_size = 0;
    a->your_slippers.slippers_name = (char*)calloc(30, (sizeof(char)));
}

void input(struct swim *a){
    printf("\nВведите название очков: ");
    scanf("%s", a->your_glasses.glasses_name);
    do {
        printf("\nВведите цвет очков: ");
        scanf("%s", a->your_glasses.glasses_color);
    } while ((strcmp(a->your_glasses.glasses_color, "red") != 0) && (strcmp(a->your_glasses.glasses_color, "yellow") != 0) && (strcmp(a->your_glasses.glasses_color, "green") != 0) && (strcmp(a->your_glasses.glasses_color, "blue") != 0) && (strcmp(a->your_glasses.glasses_color, "purple") != 0) && (strcmp(a->your_glasses.glasses_color, "black") != 0) && (strcmp(a->your_glasses.glasses_color, "white") != 0));
    do {
        printf("\nВведите стоимость очков: ");
        scanf("%d", &a->your_glasses.glasses_price);
    } while (a->your_glasses.glasses_price <= 0);

    printf("\nВведите название шапочки: ");
    scanf("%s", a->your_cap.cap_name);
    do {
        printf("\nВведите цвет шапочки: ");
        scanf("%s", a->your_cap.cap_color);
    } while ((strcmp(a->your_cap.cap_color, "red") != 0) && (strcmp(a->your_cap.cap_color, "yellow") != 0) && (strcmp(a->your_cap.cap_color, "green") != 0) && (strcmp(a->your_cap.cap_color, "blue") != 0) && (strcmp(a->your_cap.cap_color, "purple") != 0) && (strcmp(a->your_cap.cap_color, "black") != 0) && (strcmp(a->your_cap.cap_color, "white") != 0));
    do {
        printf("\nВведите стоимость шапочки: ");
        scanf("%d", &a->your_cap.cap_price);
    } while (a->your_cap.cap_price <= 0);

    printf("\nВведите название шорт: ");
    scanf("%s", a->your_shorts.shorts_name);
    do {
        printf("\nВведите цвет шорт: ");
        scanf("%s", a->your_shorts.shorts_color);
    } while ((strcmp(a->your_shorts.shorts_color, "red") != 0) && (strcmp(a->your_shorts.shorts_color, "yellow") != 0) && (strcmp(a->your_shorts.shorts_color, "green") != 0) && (strcmp(a->your_shorts.shorts_color, "blue") != 0) && (strcmp(a->your_shorts.shorts_color, "purple") != 0) && (strcmp(a->your_shorts.shorts_color, "black") != 0) && (strcmp(a->your_shorts.shorts_color, "white") != 0));
    do {
        printf("\nВведите стоимость шорт: ");
        scanf("%d", &a->your_shorts.shorts_price);
    } while (a->your_shorts.shorts_price <= 0);

    printf("\nВведите название сланцев: ");
    scanf("%s", a->your_slippers.slippers_name);
    do {
        printf("\nВведите размер сланцев: ");
        scanf("%d", &a->your_slippers.slippers_size);
    } while (a->your_slippers.slippers_size < 16 || a->your_slippers.slippers_size > 50);
    do {
        printf("\nВведите стоимость сланцев: ");
        scanf("%d", &a->your_slippers.slippers_price);
    } while (a->your_slippers.slippers_price <= 0);
}

void output(struct swim *a) {
    puts("Ваш комплект:");
    printf("\nОчки: %s\nЦвет: %s\nЦена: %d\n", a->your_glasses.glasses_name, a->your_glasses.glasses_color, a->your_glasses.glasses_price);
    printf("\nШапочка: %s\nЦвет: %s\nЦена: %d\n", a->your_cap.cap_name, a->your_cap.cap_color, a->your_cap.cap_price);
    printf("\nШорты: %s\nЦвет: %s\nЦена: %d\n", a->your_shorts.shorts_name, a->your_shorts.shorts_color, a->your_shorts.shorts_price);
    printf("\nСланцы: %s\nРазмер: %d\nЦена: %d\n", a->your_slippers.slippers_name, a->your_slippers.slippers_size, a->your_slippers.slippers_price);
}

int res(struct swim *a){
    int sum;
    sum = a->your_glasses.glasses_price + a->your_cap.cap_price + a->your_shorts.shorts_price + a->your_slippers.slippers_price;
    printf("Итог: %d\n", sum);
    return sum;
}

void color(struct swim* a) {
    if ((strcmp(a->your_glasses.glasses_color, a->your_cap.cap_color) == 0) && (strcmp(a->your_glasses.glasses_color, a->your_shorts.shorts_color) == 0))
        printf("У вас стильный total look\n");
    else
        printf("У вас разноцветный комплект\n");
}

int main() {
    int sum, k;
    setlocale(LC_ALL, "Rus");
    struct swim s;
    init(&s);
    input(&s);
    do{
        printf("\nВведите:\n1 - Для вывода вашего комплекта\n2 - Для вывода итоговой стоимости\n3 - Для анализа цветовой гаммы\n4 - Завершить работу программы\n");
        scanf("%d", &k);
        switch (k) {
            case 1:
                output(&s);
                break;
            case 2:
                sum = res(&s);
                break;
            case 3:
                color(&s);
        }
        } while (k != 4);
}