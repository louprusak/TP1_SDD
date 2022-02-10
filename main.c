#include "diary.h"

int main(void){

    printf("Je rentre dans le main\n");

    Diary d = initDiary();

    initDiaryWithFile(&d,"diary.txt");

    
    // insertFirst(&d,"2022",1);
    // insertFirst(&d,"2021",2);
    // insertFirst(&d,"2020",3);
    // insertFirst(&d,"2019",4);
    // insertFirst(&d,"2018",5);
    // insertFirst(&d,"2017",6);

    //displayWeeksList(d);

    printf("Je sors du main\n");
    
}