#include <stdio.h>
#include <stdlib.h>

   typedef struct node Node;

   struct node{

       int data;
       Node *next;

   };

   Node *create_node(int data, Node *next)

   {
        Node *n = (Node *)malloc(sizeof(Node));

        if (n == NULL){

            printf("Error!Node is not created\n");

            exit(1);
        }

        n->data = data;

        n->next = next;

        return n;

   }


   Node *remove_node(Node *head, Node *node){


        if(head == node){

            head = head->next;

            free(head);

            return head;

        }

        Node *current_node = head;

       while(current_node != NULL){

            if(current_node->next == node){

                    break;

            }

            current_node = current_node->next;

       }

    current_node->next = node->next;

    free(node);

    return head;

   }


int main()
{

    Node *head, *second, *third;

    head = create_node(100, NULL);

    second = create_node(200, NULL);

    third = create_node(300, NULL);

    head->next = second;

    second->next = third;

    third->next = NULL;


    remove_node(head, second);


    Node *current_node = head;


    while(current_node != NULL){

        printf("data = %d\n", current_node->data);

        current_node = current_node->next;

    }

    }


