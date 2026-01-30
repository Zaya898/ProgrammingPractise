#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <math.h>
#define MAX_PASSENGERS 100
typedef struct {
    int item_count;
    double total_weight;
} Luggage;
void read_luggage_data(FILE *file, Luggage *luggage, int *count);
double calculate_average_weight(Luggage *luggage, int count);
void task_a(Luggage *luggage, int count, double avg_weight);
void task_b(Luggage *luggage, int count);
void task_c(Luggage *luggage, int count);
void task_d(Luggage *luggage, int count);
void task_e(Luggage *luggage, int count);

int main() {
    FILE *file = fopen("luggage.txt", "r");
    if (file == NULL) {
        printf("File neeh bolomjgui!\n");
        return 1;
    }

    Luggage luggage[MAX_PASSENGERS];
    int passenger_count = 0;
    read_luggage_data(file, luggage, &passenger_count);
    fclose(file);

    if (passenger_count == 0) {
        printf("Filed ugugdul baihgui!\n");
        return 1;
    }
    double overall_avg_weight = calculate_average_weight(luggage, passenger_count);
    printf("Yronhuu dundaj jin: %.2f kg\n", overall_avg_weight);

    printf("\na) Dundaj jin yronhii dundajaas 0.3kg-aas iluu zuruuntei achianuud:\n");
    task_a(luggage, passenger_count, overall_avg_weight);

    printf("\nb) Hoyroos iluu zuiltei achaanuudiin dun shinjilgee:\n");
    task_b(luggage, passenger_count);

    printf("\nc) Ijil toonii zuiltei, 0.5kg-aas iluugui jingiin zuruutei hos zorchigch:\n");
    task_c(luggage, passenger_count);

    printf("\nd) Zuiliin too bolon jingiin busdaasaa iluu zorchigch:\n");
    task_d(luggage, passenger_count);

    printf("\ne) 30kg-aas baga jintei gants zuiltei zorchigch:\n");
    task_e(luggage, passenger_count);

    return 0;
}

void read_luggage_data(FILE *file, Luggage *luggage, int *count) {
    *count = 0;
    while (fscanf(file, "%d %lf", &luggage[*count].item_count, &luggage[*count].total_weight) == 2) {
        (*count)++;
        if (*count >= MAX_PASSENGERS) break;
    }
}

double calculate_average_weight(Luggage *luggage, int count) {
    double total_items = 0;
    double total_weight = 0;

    for (int i = 0; i < count; i++) {
        total_items += luggage[i].item_count;
        total_weight += luggage[i].total_weight;
    }

    return total_weight / total_items;
}

void task_a(Luggage *luggage, int count, double avg_weight) {
    for (int i = 0; i < count; i++) {
        double item_avg = luggage[i].total_weight / luggage[i].item_count;
        if (fabs(item_avg - avg_weight) <= 0.3) {
            printf("Zorchigch %d: %d zuil, %.2f kg (dundaj %.2f kg)\n", 
                   i+1, luggage[i].item_count, luggage[i].total_weight, item_avg);
        }
    }
}

void task_b(Luggage *luggage, int count) {
    int more_than_two = 0;
    double avg_items = 0;
    int above_avg_count = 0;

    for (int i = 0; i < count; i++) {
        avg_items += luggage[i].item_count;
    }
    avg_items /= count;

    for (int i = 0; i < count; i++) {
        if (luggage[i].item_count > 2) {
            more_than_two++;
        }
        if (luggage[i].item_count > avg_items) {
            above_avg_count++;
        }
    }

    printf("- 2-oos iluu zuiltei zorchigch: %d\n", more_than_two);
    printf("- dundjaas iluu zuiltei zorchigch: %d\n", above_avg_count);
}

void task_c(Luggage *luggage, int count) {
    bool found = false;
    
    for (int i = 0; i < count; i++) {
        for (int j = i+1; j < count; j++) {
            if (luggage[i].item_count == luggage[j].item_count && 
                fabs(luggage[i].total_weight - luggage[j].total_weight) <= 0.5) {
                printf("Zorchigch %d (%d zuil, %.2f kg) ba %d (%d zuil, %.2f kg)\n",
                       i+1, luggage[i].item_count, luggage[i].total_weight,
                       j+1, luggage[j].item_count, luggage[j].total_weight);
                found = true;
            }
        }
    }
    
    if (!found) {
        printf("Iim hos zorchigch oldsongui\n");
    }
}

void task_d(Luggage *luggage, int count) {
    bool found = false;
    
    for (int i = 0; i < count; i++) {
        bool items_greater = true;
        bool weight_greater = true;
        
        for (int j = 0; j < count; j++) {
            if (i != j) {
                if (luggage[i].item_count <= luggage[j].item_count) {
                    items_greater = false;
                }
                if (luggage[i].total_weight <= luggage[j].total_weight) {
                    weight_greater = false;
                }
            }
        }
        
        if (items_greater && weight_greater) {
            printf("Zorchigch %d: %d zuil, %.2f kg\n", 
                   i+1, luggage[i].item_count, luggage[i].total_weight);
            found = true;
            break;
        }
    }
    
    if (!found) {
        printf("Iim zorchigch oldsongui\n");
    }
}

void task_e(Luggage *luggage, int count) {
    bool found = false;
    
    for (int i = 0; i < count; i++) {
        if (luggage[i].item_count == 1 && luggage[i].total_weight < 30.0) {
            printf("Zorchigch %d: 1 zuil, %.2f kg\n", i+1, luggage[i].total_weight);
            found = true;
        }
    }
    
    if (!found) {
        printf("Iim zorchigch oldsongui\n");
    }
}
