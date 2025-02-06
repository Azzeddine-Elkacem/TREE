#include <stdio.h>
#include <stdlib.h>

#define WIDTH 5
#define HEIGHT 5

typedef struct Tree{
    struct Tree *leftChild, *rightChild;
} Tree;
Tree *maze[WIDTH][HEIGHT];
   //create the Grid : 
void initializeMaze(){
  for (int x=0; x <WIDTH; x++)
     for (int y =0;y <HEIGHT; y++)
         maze[x][y] = (Tree *)malloc(sizeof(Tree)), maze[x][y]->leftChild = maze[x][y]->rightChild = NULL;
}

//generate the Maze : i used rand for random integer : rand() % 2 gives one or zero : one for right child (go right) and zero go for lift child (up)
//checking the value of y it should be above zero to connect to the node above or get NULL (there is no space), the same with x and width:
void generateMaze(){
    for (int x= 0; x <WIDTH; x++)
     for (int y= 0; y<HEIGHT; y++)
         (rand()% 2)?(maze[x][y]->leftChild =(y>0 ? maze[x][y -1] : NULL))
                         : (maze[x][y]->rightChild =(x< WIDTH -1 ? maze[x +1][y] : NULL));
}

//print external wall (top border) first , 
// space if maze[x][y]->rightChild is not NULL, else wall will be written,
//horizontal wall --- vertical wall | stars for the corners;
void printMaze(){
    for (int x= 0; x < WIDTH;x++) printf("+---");  printf("+\n");
   
    for (int y = HEIGHT-1; y>= 0; y--){
     printf("|");
      for (int x = 0; x <WIDTH; x++) printf("   %c",maze[x][y]->rightChild ? ' ':'|');
       printf("\n");
    for (int x =0; x< WIDTH;x++) printf("+%s",maze[x][y]->leftChild ? "  ": "---");
        printf("+\n");
  }
  }
int main(){
    initializeMaze();
    generateMaze();
    printMaze();
   
   
   


   
    return 0;
}
