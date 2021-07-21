/**
 * Name: Celeste Amengual
 * PID: 6115500
 * Assignment: 4
 * Class: COP 4338 Section U02
 */


#include <stdio.h>
#include <stdlib.h>

typedef enum
{
    NONE = 0,
    UP = 1,
    DOWN = 2,
    LEFT = 4,
    RIGHT = 8
}Direction;

typedef struct
{
    int x, y;
}Vertex;

typedef struct
{
    int numberOfVertices;
    Direction shiftDirection;
    Vertex* vertexList;
}Polygon;

Vertex newVertex(int x, int y)
{

    Vertex newV;
    newV.x = x;
    newV.y = y;
    return newV;
}

static Polygon polygons[1000];

void addPolygons(int numOfVertices){

    Polygon *polyPointer = (Polygon*)malloc(sizeof(Polygon));
    Vertex* vertices = (Vertex*)malloc(sizeof(Vertex)*100);

    for( int i = numOfVertices, j = 0; i > 0; i--,j++){
        int x,y;

        printf("\nWhat is the X coordinate of vertex #%d?\n", (j+1));
        scanf("%d", &x);
        printf("What is the Y coordinate of vertex #%d?\n", (j+1));
        scanf("%d",&y);

        Vertex v = newVertex(x,y);
        vertices[j] = v;
    }

    polyPointer->numberOfVertices = numOfVertices;
    polyPointer->shiftDirection = NONE;
    polyPointer->vertexList = vertices;

    for (int i = 0; i < 1000; i++)
    {
        if (polygons[i].numberOfVertices == 0)
        {
            polygons[i] = *polyPointer;
            break;
        }
    }

    printf("\nPolygon has been added to list!\n");

}

void displayPolygons(){

    int i;
    int j;
    int k;
    int x;
    int y;
    double xAverage;
    double yAverage;

    for(i = 0; i < 1000 && polygons[i].numberOfVertices != 0; i++){

        printf("\n\n");

        int xSum = 0;
        int ySum = 0;

        printf("Polygon #%d\n", (i+1));
        printf("Number of vertices: %d\n", polygons[i].numberOfVertices);
        printf("Direction: %d\n", polygons[i].shiftDirection);


        for(j = 0; j < polygons[i].numberOfVertices; j++){

            printf("Vertex #%d: ", (j+1));
            printf("(%d, %d)\n", polygons[i].vertexList[j].x, polygons[i].vertexList[j].y);


        }

        for(k = 0; k < polygons[i].numberOfVertices; k++){

             x = polygons[i].vertexList[k].x;
            xSum = xSum + x;

             y = polygons[i].vertexList[k].y;
            ySum = ySum + y;


        }

        xAverage = (double)(xSum)/(polygons[i].numberOfVertices);
        yAverage = (double)(ySum)/(polygons[i].numberOfVertices);

        printf("Centroid: (%f, %f)\n", xAverage,yAverage);

    }

}

void turnPolygon(int aPolygon){

    int turn;

    if(polygons[aPolygon - 1].numberOfVertices == 0){

        printf("Polygon does not exist!!!!\n");
        return;

    }

    printf("\nEnter...\n");
    printf("1 to turn left\n");
    printf("2 to turn right\n");
    printf("3 to turn up\n");
    printf("4 to turn down\n");
    printf("5 to turn up-right\n");
    printf("6 to turn up-left\n");
    printf("7 to turn down-right\n");
    printf("8 to turn down-left\n");
    scanf("%d", &turn);

    if(turn == 1){
        polygons[aPolygon-1].shiftDirection = LEFT;
    }
    if(turn == 2){
        polygons[aPolygon-1].shiftDirection = RIGHT;
    }
    if(turn == 3){
        polygons[aPolygon-1].shiftDirection = UP;
    }
    if(turn == 4){
        polygons[aPolygon-1].shiftDirection = DOWN;
    }
    if(turn == 5){
        polygons[aPolygon-1].shiftDirection = UP | RIGHT;
    }
    if(turn == 6){
        polygons[aPolygon-1].shiftDirection = UP | LEFT;
    }
    if(turn == 7){
        polygons[aPolygon-1].shiftDirection = DOWN | RIGHT;
    }
    if(turn == 8){
        polygons[aPolygon-1].shiftDirection = DOWN | LEFT;
    }

}

void shiftPolygon(int aPolygon){

    int shift;

    if(polygons[aPolygon - 1].numberOfVertices == 0){

        printf("\nPolygon does not exist!!!!\n");
        return;

    }

    printf("\nBy how much would you like to shift the polygon?\n");
    scanf("%d",&shift);


    if(polygons[aPolygon-1].shiftDirection == NONE){
        printf("Shift direction of this polygon is set to none, no shifting will take place!\n");
        return;
    }

    for(int i = 0; i < polygons[aPolygon-1].numberOfVertices; i++){


        if(polygons[aPolygon-1].shiftDirection == LEFT){
            polygons[aPolygon-1].vertexList[i].x = polygons[aPolygon-1].vertexList[i].x - shift;
        }

        if(polygons[aPolygon-1].shiftDirection == RIGHT){
            polygons[aPolygon-1].vertexList[i].x = polygons[aPolygon-1].vertexList[i].x + shift;
        }
        if(polygons[aPolygon-1].shiftDirection == UP ){
            polygons[aPolygon-1].vertexList[i].y = polygons[aPolygon-1].vertexList[i].y + shift;

        }
        if(polygons[aPolygon-1].shiftDirection == DOWN){
            polygons[aPolygon-1].vertexList[i].y = polygons[aPolygon-1].vertexList[i].y - shift;

        }
        if(polygons[aPolygon-1].shiftDirection == 5){

            polygons[aPolygon-1].vertexList[i].x = polygons[aPolygon-1].vertexList[i].x - shift;
            polygons[aPolygon-1].vertexList[i].y = polygons[aPolygon-1].vertexList[i].y + shift;
        }
        if(polygons[aPolygon-1].shiftDirection == 6){

            polygons[aPolygon-1].vertexList[i].x = polygons[aPolygon-1].vertexList[i].x - shift;
            polygons[aPolygon-1].vertexList[i].y = polygons[aPolygon-1].vertexList[i].y - shift;
        }
        if(polygons[aPolygon-1].shiftDirection == 9){

            polygons[aPolygon-1].vertexList[i].x = polygons[aPolygon-1].vertexList[i].x + shift;
            polygons[aPolygon-1].vertexList[i].y = polygons[aPolygon-1].vertexList[i].y + shift;
        }
        if(polygons[aPolygon-1].shiftDirection == 10){

            polygons[aPolygon-1].vertexList[i].x = polygons[aPolygon-1].vertexList[i].x + shift;
            polygons[aPolygon-1].vertexList[i].y = polygons[aPolygon-1].vertexList[i].y - shift;
        }



    }

}

int main() {
    int command;
    int numOfVertices;
    int aPolygon;

    while (1) {
        printf("\n");
        printf("Enter 1 if you would like to add a polygon\n");
        printf("Enter 2 if you would like to see a summary of the polygon list\n");
        printf("Enter 3 if you would like to turn a polygon\n");
        printf("Enter 4 if you would like to shift a polygon\n");
        printf("Enter 5 if you would like to quit program\n");
        scanf("%d", &command);

        if (command == 1) {
            printf("How many vertices will the polygon have?\n");
            scanf("%d", &numOfVertices);

            addPolygons(numOfVertices);
        }
        if(command == 3){
            printf("Which polygon would you like turn?\n");
            scanf("%d",&aPolygon);

            turnPolygon(aPolygon);

        }
        if (command == 2) {
            displayPolygons();

        }
        if(command == 4){
            printf("Which polygon would you like to shift?\n");
            scanf("%d", &aPolygon);

            shiftPolygon(aPolygon);

        }
        if(command == 5){
            break;
        }

    }

}

