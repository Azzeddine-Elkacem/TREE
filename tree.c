#include<stdio.h>
#include<stdlib.h>

typedef struct Node{
  struct Node * leftChild;
  int data;
  struct Node* rightChild; 
}Tree;

 Tree *root = NULL;


void insert(int key){

  Tree *t = root;
  Tree *r  = NULL, *p;

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
  if(key < t->data){
    t =t->leftChild;
  }
  else if(key > t->data){
    t = t->rightChild;
  }else
  return;

}

p = (Tree*)malloc(sizeof(Tree));
  p->data = key;
  p->leftChild = NULL;
  p->rightChild = NULL;

if(r->data > key) r->leftChild = p;
else r->rightChild = p;

}

void inOrder(Tree *t){
  if(t){
    inOrder(t->leftChild);
    printf("%d ", t->data);
    inOrder(t->rightChild);
  }
}








int main(){
  insert(10);
  insert(5);
  insert(20);
  insert(8);
 printf("In-order Traversal: ");
inOrder(root);
printf("\n");
  return 0;
}