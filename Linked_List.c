#include <stdio.h>
#include <stdlib.h>

   typedef struct node Node;

   struct node{
       int data;
       Node *next;
   };

   Node *create_node(int data, Node *next){

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

   Node *prepend(Node *head, int data){

        Node *new_node = create_node(data, NULL);

        if (head == NULL){

            return new_node;
       }

       new_node->next = head->next;

       head->next = new_node;

       return head;
   }


    Node *append(Node *head, int data){

        Node *new_node = create_node(data, NULL);

        Node *current_node = head;


        if (head == NULL){

            return new_node;
        }


        while (current_node->next != NULL){

            current_node = current_node->next;
       }

        current_node->next = new_node;

        return head;

   }

    void insert(int data, Node *node){

        Node *new_node = create_node(data, node->next);

        node->next = new_node;
    }


    Node *linked_list_from_array(Node *head, int num[]){

       Node *current_node = head;

        for (int i = 0; i < 5; i++){

            Node *new_node = create_node(num[i],NULL);

            if (head == NULL){

                head = new_node;

                current_node = head;

            }
           while (current_node->next != NULL){

                    current_node = current_node->next;

                };

              current_node->next = new_node;

           }
        return head;
        }


    void traverse_list(Node *head){

        Node *current_node = head;

        while(current_node != NULL){

            printf("data = %d\n", current_node->data);

            current_node = current_node->next;
    }

    }

int main(){

    //remove_node(head, second);

    //Node *head = NULL;

    Node *head = create_node(0,NULL);

    head = prepend(head,500);

    int num_array[5] = {4,5,3,2,8};

    head = linked_list_from_array(head, num_array);

    head = append(head, 100);

    head = prepend(head,1000);

    Node *current_node = head;

    while (current_node->data != 2){

        current_node = current_node->next;

    }

    head = remove_node(head, current_node);


    traverse_list(head);

}






