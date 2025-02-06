#include<stdio.h>
#include<stdlib.h>

typedef struct Node{
  struct * tree leftChild;
  int data;
  struct * tree rightChild; 
}Tree;
*root = NULL;


void insert(Tree * t, int key){
  Tree * r,*p;
  if(root == NULL){
    p = (Tree*)malloc(sizeof(Tree));
    p->data = key;
    p->leftChild = NULL;
    p->rightChild = NULL;
    root = p;
    return;
  }

while(t!=NULL){
  r = t;
  if(t == key){
    return;
  }
  else if(key > t){
    t = t->rightChild;
  }
  else t = t->leftChild;

}

if(r->data > key) r-leftChild = p;
else r-rightChild = p;

}

void inOrder(Tree *t){
  if(t){
    inOrder(t->leftChild);
    printf("%d", t->data);
    inOrder(t->rightChild);
  }
}








int main(){
  insert(10);
  insert(5);
  insert(20);
  insert(8);

  

  return 0;
}