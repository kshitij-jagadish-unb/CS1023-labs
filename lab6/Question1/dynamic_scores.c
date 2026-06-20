#include <stdio.h>
#include <stdlib.h>

double *createScores(size_t count){

    double *new_memory =  (double *)malloc(count * sizeof(double));
    return new_memory;
}

void readScores(double scores[], size_t count){

    size_t x = 0;

    while (x < count){

        printf("Enter score(s) %zu :", x + 1);
        scanf("%lf", &scores[x]);

        x = x + 1;
    }
}

void printScores(const double scores[], size_t count){

    size_t x = 0;

    printf("Score(s) entered are: ");
    
    while (x < count){

        printf("%.2f", scores[x]);

        x = x + 1;
    }
    printf("\n");
    
}

double findMinimum(const double scores[], size_t count) {
   
    double min = scores[0]; 
    size_t x = 1; 
    
    while (x < count) {

        if (scores[x] < min) {
            
            min = scores[x];
        } 
        else {
           
        }
        x = x + 1;
    }
    return min;
}

double findMaximum(const double scores[], size_t count) {
 
    double max = scores[0];
    size_t x = 1;
    
    while (x < count) {
        if (scores[x] > max) {
            
            max = scores[x];
        }
        else {
            
        }
        x = x + 1;
    }
    return max;
}

double calculateAverage(const double scores[], size_t count) {

    double sum = 0.0;
    size_t x = 0;
    
    while (x < count) {

        sum = sum + scores[x]; 
        x = x + 1;
    }
    
    return sum / count; 
}

int main(void){

int inputsize = 0;
int incheck = 0;

printf("How many scores you wanna enter?");
scanf("%d", &inputsize);
incheck = inputsize;

if (incheck != 1) {

        printf("Error: You did not enter a valid number.\n");
        return 1; 
    } 
    else if (inputsize <= 0) {
        printf("Error: Invalid size. You must enter a number greater than zero.\n");
        return 1;
    }
    else {
        
        size_t count = (size_t)inputsize;

 
        double *scores = createScores(count);
        
     
        if (scores == NULL) {
            printf("Error: Memory allocation failed.\n");
            return 1;
        }
        else {
            
            readScores(scores, count);

            printf("\n--- Results ---\n");
            
          
            printScores(scores, count);

           
            double min_score = findMinimum(scores, count);
            double max_score = findMaximum(scores, count);
            double avg_score = calculateAverage(scores, count);

            printf("Minimum score: %.2f\n", min_score);
            printf("Maximum score: %.2f\n", max_score);
            printf("Average score: %.2f\n", avg_score);

            
            free(scores);
        }
    }
    
    return 0; 

}
