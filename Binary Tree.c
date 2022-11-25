#include <stdio.h>
#include <stdlib.h>

   typedef struct node Node;

   struct node{
       int data;
       Node *left;
       Node *right;
   };
   
   Node *create_node(int data){
        Node *new_node = (Node *)malloc(sizeof(Node));
        if (new_node == NULL){
            printf("Error!Node is not created\n");
            exit(1);
        }
        new_node->data = data;
        new_node->left = NULL;
        new_node->right = NULL;
        return new_node;
   }
   
   void add_left_child(Node *node, Node *child){
       node->left = child;
   }
   
   void add_right_child(Node *node, Node *child){
       node->right = child;
   }
   
   void pre_order_traversal(Node *node){
       printf("%d\n", node->data);
       if(node->left != NULL){
           pre_order_traversal(node->left);
       }
       if (node->right != NULL){
           pre_order_traversal(node->right);
       }
   }
   
   void post_order_traversal(Node *node){
       if(node->left != NULL){
           post_order_traversal(node->left);
       }
       if (node->right != NULL){
           post_order_traversal(node->right);
       }
        printf("%d\n", node->data);
   }
   
   void in_order_traversal(Node *node){
       if(node->left != NULL){
           in_order_traversal(node->left);
       }
       printf("%d\n", node->data);
       if (node->right != NULL){
           in_order_traversal(node->right);
       }
   }
   
   Node *create_tree(){
       
      Node *two = create_node(2);
      Node *seven = create_node(7);
      Node *nine = create_node(9);
      
      add_left_child(two, seven);
      add_right_child(two, nine);
      
      Node *one = create_node(1);
      Node *six = create_node(6);
      
      Node *five = create_node(5);
      Node *ten = create_node(10);
      
      add_left_child(six, five);
      add_right_child(six, ten);
      
      add_left_child(seven, one);
      add_right_child(seven, six);
      
      Node *eight = create_node(8);
      Node *three = create_node(3);
      Node *four = create_node(4);
      
      add_right_child(nine, eight);
      
      add_left_child(eight, three);
      add_right_child(eight, four);
      
      return two;
       
   }
   
   int main(){
      
      Node  *root = create_tree();
      /*printf("%d\n", root->data);*/
     /*pre_order_traversal(root);*/
      /*post_order_traversal(root);*/
      in_order_traversal(root);
      return 0;
       
   }
