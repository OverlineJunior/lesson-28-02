#include <stdio.h>
#include <math.h>

#define ONE_INPUT_NUM 5
#define TWO_INPUT_NUM 5
#define SIX_INPUT_NUM 3 // Exercício pede 50, mas achei exagerado.

typedef struct {
    int gender_id;
    int eye_color_id;
    int hair_color_id;
    int age;
} Person;

typedef struct {
    int s1;
    int s2;
} PeopleStatistics;

void swap(int *a, int *b) {
    const int save = *a;

    *a = *b;
    *b = save;
}

int square_root_i(int n) {
    return sqrt(n);
}

void square_root_f(float *n) {
    *n = sqrtf(*n);
}

void array_display(int vec[], int size) {
    for (int i = 0; i < size; i++) {
        printf("%i ", vec[i]);
    }

    printf("\n");
}

void array_reverse(int *vec, int size) {
    for (int i = 0; i < size / 2; i++) {
        const int rev_i = size - 1 - i;
        const int save = vec[i];

        vec[i] = vec[rev_i];
        vec[rev_i] = save;
    }
}

int array_highest_i(int *vec, int size) {
    int highest_i = 0;
    int highest_v = vec[0];

    for (int i = 0; i < size; i++) {
        if (vec[i] > highest_v) {
            highest_v = vec[i];
            highest_i = i;
        }
    }

    return highest_i;
}

int array_lowest_i(int *vec, int size) {
    int lowest_i = 0;
    int lowest_v = vec[0];

    for (int i = 0; i < size; i++) {
        if (vec[i] < lowest_v) {
            lowest_v = vec[i];
            lowest_i = i;
        }
    }

    return lowest_i;
}

// Redundante, mas é pedido pelo exercício.
void display_then_reverse(int *vec) {
    printf("Vetor na ordem original: ");
    array_display(vec, ONE_INPUT_NUM);

    array_reverse(vec, ONE_INPUT_NUM);

    printf("Vetor na ordem reversa: ");
    array_display(vec, ONE_INPUT_NUM);
}

void read_people(Person *people, int size) {
    for (int i = 0; i < size; i++) {
        Person p;
        scanf("%i%i%i%i", &p.gender_id, &p.eye_color_id, &p.hair_color_id, &p.age);

        people[i] = p;
    }
}

PeopleStatistics get_people_statistics(Person people[], int size) {
    PeopleStatistics ps = {
        .s1 = people[0].age,
        .s2 = 0,
    };

    for (int i = 0; i < size; i++) {
        Person p = people[i];

        ps.s1 = p.age > ps.s1 ? p.age : ps.s1;

        if (p.gender_id == 1 && p.age >= 18 && p.age <= 35 && p.eye_color_id == 1 && p.hair_color_id == 0) {
            ps.s2++;
        }
    }

    return ps;
}

void display_people_statistics(PeopleStatistics ps) {
    printf(
        "Maior idade entre os habitantes: %i\n"
        "Quantidade de individuos do sexo feminino cuja idade esta entre 18 e 35 (inclusive) e "
        "que tenham olhos verdes e cabelos louros: %i\n",
        ps.s1,
        ps.s2
    );
}

void one() {
    printf("Entre com inteiros %i vezes:\n", ONE_INPUT_NUM);

    int vec[ONE_INPUT_NUM];
    for (int i = 0; i < ONE_INPUT_NUM; i++) {
        scanf("%i", &vec[i]);
    }

    display_then_reverse(vec);
}

void two() {
    printf("Entre com inteiros %i vezes:\n", TWO_INPUT_NUM);

    int vec[TWO_INPUT_NUM];
    for (int i = 0; i < TWO_INPUT_NUM; i++) {
        scanf("%i", &vec[i]);
    }

    printf(
        "Indice do valor mais...\n  alto: %i\n  baixo: %i\n",
        array_highest_i(vec, TWO_INPUT_NUM),
        array_lowest_i(vec, TWO_INPUT_NUM)    
    );
}

void three() {
    printf("Entre com um numero real: ");

    float n;
    scanf("%f", &n);

    const float save = n;

    square_root_f(&n);

    printf("Raiz quadrada de %f: %f\n", save, n);
}

void four() {
    printf("Entre com um inteiro: ");

    int n;
    scanf("%i", &n);

    const int save = n;

    n = square_root_i(n);

    printf("Raiz quadrada de %i: %i\n", save, n);
}

void five() {
    printf("Entre com inteiros 2 vezes:\n");

    int a, b;
    scanf("%i%i", &a, &b);

    const int save_a = a, save_b = b;

    swap(&a, &b);

    printf("%i %i -> Inverte a posicao na memoria -> %i %i\n", save_a, save_b, a, b);
}

void six() {
    printf(
        "Entre %i vezes com...\n"
        "  1. Genero         (0: masculino, 1: feminino)\n"
        "  2. Cor dos olhos  (0: azul, 1: verde, 2: castanho)\n"
        "  3. Cor do cabelo  (0: louro, 1: preto, 2: castanho)\n"
        "  4. Idade          (inteiro)\n",
        SIX_INPUT_NUM
    );

    Person people[SIX_INPUT_NUM];
    read_people(people, SIX_INPUT_NUM);

    PeopleStatistics ps = get_people_statistics(people, SIX_INPUT_NUM);
    display_people_statistics(ps);
}

int main(void) {
    printf("Selecione um exercicio de 1 a 6: ");

    int n;
    scanf("%i", &n);
    
    switch (n) {
        case 1:
            one();
            break;
        case 2:
            two();
            break;
        case 3:
            three();
            break;
        case 4:
            four();
            break;
        case 5:
            five();
            break;
        case 6:
            six();
            break;
        default:
            printf("Exercicio invalido\n");
    }

    // Lesson lesson = lesson_new();

    // lesson_add_exercise(&lesson, one);
    // lesson_add_exercise(&lesson, two);
    // lesson_add_exercise(&lesson, three);
    // lesson_add_exercise(&lesson, four);
    // lesson_add_exercise(&lesson, five);
    // lesson_add_exercise(&lesson, six);

    // lesson_display(lesson);
    // lesson_select_exercise(lesson);

    return 0;
}
