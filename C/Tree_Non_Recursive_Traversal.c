#include<stdio.h>
#include<stdlib.h>

/*  tree node */
typedef struct tnode {
    char data ;
    struct tnode * left ;
    struct tnode * right ;
}Node ;

void leftside(Node** head , Node* tmp){
    (*head)->left = tmp ;
}

void rightside(Node** head , Node* tmp){
    (*head)->right = tmp ;
}

struct tnode* nd (char val){
    Node * newnd = (Node*)malloc(sizeof(Node)) ;
    newnd->data = val ;
    newnd->left = NULL ;
    newnd->right = NULL ;
    return newnd ;
}

/* stack node */
struct NODE{
    struct tnode * tnd ;
    struct NODE * next ;
};

struct NODE * push(struct NODE * head , struct tnode* treend ){
    struct NODE * tmp = (struct NODE *)malloc(sizeof(struct NODE)) ;
    tmp->tnd = treend ;
    tmp->next = head ;
    head=tmp ;
    return head ;
}


struct NODE* pop(struct NODE *head){
    struct NODE *tmp=head ;
    if (tmp==NULL) printf("    Cannot delete as NO nodes in the linked-list \n" ) ;
    else {
        head = head->next ;
        free(tmp) ;
    }
    return head ;
}

int isempty(struct NODE* head){
    return (head==NULL ? 1 : 0) ;
}

struct NODE * reverse_list(struct NODE * head){
    struct NODE * backptr ,*firstptr ;
    backptr=NULL ; firstptr=head ;
    while(head!=NULL){
        firstptr = firstptr->next ;
        head-> next = backptr ;
        backptr = head ;
        head = firstptr ;
    }
    head = backptr ;
    return head ;
}

void inorder_nonrursive(Node * ptr){
    Node * curr = ptr ;
    struct NODE * stack = NULL ;
    while(curr!=NULL || !isempty(stack)){
        while (curr!=NULL){
            stack=push(stack,curr) ;
            curr = curr->left ;
        }
        curr=stack->tnd ;
        printf("%c ",curr->data) ;
        stack = pop(stack) ;
        curr = curr->right ;
    }
    printf("\n") ;
}

void preorder_nonrursive(Node* ptr){
    Node* curr=ptr ;
    struct NODE * stack=(struct NODE * )malloc(sizeof(struct NODE)) ;
    stack->tnd = ptr ;
    stack->next = NULL ;
    while(!isempty(stack) && curr!=NULL){
        printf("%c ",curr->data) ;
        stack=pop(stack) ;
        if (curr->right) stack=push(stack,curr->right) ;
        if (curr->left) stack=push(stack,curr->left) ;
        if (!isempty(stack)) curr = stack->tnd ;
    }
    printf("\n") ;
}

void postorder_nonrursive(Node *ptr){
    Node *curr=ptr ;
    struct NODE* stack=(struct NODE * )malloc(sizeof(struct NODE)) , *stack1=NULL ;
    stack->tnd=curr ;
    stack->next=NULL ;
    while(!isempty(stack)){
        stack1=push(stack1,stack->tnd) ;
        stack=pop(stack) ;
        if (stack1->tnd->left) { stack=push(stack,stack1->tnd->left) ;} //printf("%c 2 ",stack1->tnd->left->data) ;}
        if (stack1->tnd->right) { stack=push(stack,stack1->tnd->right) ; } //printf("%c 1 ",stack1->tnd->right->data) ;}
    }
    while(stack1!=NULL){
        printf("%c ",stack1->tnd->data) ;
        stack1=stack1->next ;
    }
}

int main(){
    struct NODE * stack ;

    Node* root ;
    root=nd('A') ;
    leftside(&root,nd('B')) ;
    rightside(&root,nd('C')) ;
    leftside(&(root->left),nd('D')) ;
    rightside(&(root->left),nd('E')) ;
    leftside(&(root->right),nd('F')) ;
    rightside(&(root->right),nd('G')) ;
    printf("Inorder_nonrursive   : ")  ; inorder_nonrursive(root) ;
    printf("Preorder_nonrursive  : ") ; preorder_nonrursive(root) ;
    printf("Postorder_nonrursive : ") ; postorder_nonrursive(root) ;

}

//     => Inorder_nonrursive traversal  : D B E A F C G
//     => Preorder_nonrursive traversal : A B D E C F G
//     => Preorder_nonrursive traversal : D E B F G C A
