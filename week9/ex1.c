#include <stdio.h>
#include <math.h>

#define NUMBER_BITS 16

struct page {
    int ref;
	unsigned int counter;
};

int hit(int p_ref, int f_num, struct page *ps) {
    for (int i = 0; i < f_num; i++) {
        if ((ps + i)->ref == p_ref) {
            return i; // if page is in pages, return index
        }
    }
    return -1; // if page is not in pages
}

void shift_counter(int p_ref, int f_num, struct page *ps, int idx) {
    for (int i = 0; i < f_num; i++) {
        (ps + i)->counter >>= 1; 
        if (i == idx) {
            (ps + i)->ref = p_ref;
            (ps + i)->counter |= 1 << (NUMBER_BITS - 1);
        }
    }
}

int find_youngest_page(int p_ref, int f_num, struct page *ps) {
    int min_counter = pow(2, NUMBER_BITS + 1);
    int idx_min = 0;
    for (int i = 0; i < f_num; i++) {
        if ((ps + i)->counter < min_counter) {
            min_counter = (ps + i)->counter;
            idx_min = i;
        }
    }
    return idx_min;
}

void print_info(int p_ref, int f_num, struct page *ps) {
    printf("Inserting %d page reference:\n", p_ref);
    printf("idx\tref\tcounter\n");
    for(int i = 0; i < f_num; i++) {
        printf("%d\t%d\t%d\n", i, (ps + i)->ref, (ps + i)->counter);
    }
    printf("\n");
}

void print_performance_info(int hits, int misses) {
    printf("Hits: %d\nMisses: %d\n", hits, misses);
    printf("Hit ratio: %.7f\n", (double)hits/misses);
}

int main(int argc, char *argv[]) {
    int FRAMES_NUMBER;
    sscanf(argv[1], "%d", &FRAMES_NUMBER);

    struct page pages[FRAMES_NUMBER];
    for (int i = 0; i < FRAMES_NUMBER; i++) {
        pages[i].ref = -1;
        pages[i].counter = 0;
    }

    int page_ref = 0;
    int hits = 0;
    int misses = 0;
    FILE *f = fopen("input copy.txt", "r"); 
    while(!feof(f)) {
        fscanf(f, "%d", &page_ref);
        int index = hit(page_ref, FRAMES_NUMBER, pages);
        if (index != -1) {
            hits++;
        }
        else {
            index = find_youngest_page(page_ref, FRAMES_NUMBER, pages);
            misses++;
        }
        shift_counter(page_ref, FRAMES_NUMBER, pages, index);
        print_info(page_ref, FRAMES_NUMBER, pages);
    }
    fclose(f);
    print_performance_info(hits, misses);
}