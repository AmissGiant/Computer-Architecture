#include <stdio.h>
#include <stdlib.h>
struct TreeNode{
    struct TreeNode* left;
    struct TreeNode* right;
    int data;
};
struct TreeNode* createNode(int val){
    struct TreeNode* newNode = (struct TreeNode*)malloc(sizeof(struct TreeNode));//allocate space since we don't know size
    newNode->left = newNode->right = NULL;
    newNode->data = val;
    return newNode;
}
void insert(struct TreeNode** root, int val, int* inserted){//inserts a node into the tree
    if(*root == NULL){
        *root = createNode(val);
        *inserted = 1;
    }else if(val < (*root)->data){
        insert(&((*root)->left), val, inserted);
    }else if(val > (*root)->data){
        insert(&((*root)->right), val, inserted);
    }else{
        *inserted = 0;
    }
}
void deleteNode(struct TreeNode** root, int val){//deletes a node from the tree
    if(*root == NULL){
        return;
    }
    if(val < (*root)->data){
        deleteNode(&((*root)->left), val);
    }else if(val > (*root)->data){
        deleteNode(&((*root)->right), val);
    }else{
        if((*root)->left == NULL){//reaches end on left
            struct TreeNode* temp = *root;
            *root = (*root)->right;
            free(temp);
        }else if((*root)->right == NULL){//reaches end on rigth
            struct TreeNode* temp = *root;
            *root = (*root)->left;
            free(temp);
        }else{
            struct TreeNode* minValueNode = (*root)->right;
            while(minValueNode->left != NULL){
                minValueNode = minValueNode->left;
            }
            (*root)->data = minValueNode->data;
            deleteNode(&((*root)->right), minValueNode->data);
        }
    }
}
int search(struct TreeNode* root, int val){//searched for and returns a specific value fromt he tree
    if(root == NULL){
        return 0;
    }else if(val == root->data){
        return 1;
    }else if(val < root->data){
        return search(root->left, val);
    }else{
        return search(root->right, val);
    }
}
void print(struct TreeNode* root){
    if(root == NULL){
        return;
    }
    printf("(");
    print(root->left);
    printf("%d", root->data);
    print(root->right);
    printf(")");
}
int main(int argc, char* argv[]){
    struct TreeNode* root = NULL;
    char command;
    int val, inserted, result;
    while(scanf(" %c", &command) != EOF){
        switch(command){
            case 'i'://inserts
                scanf("%d", &val);
                inserted = 0;
                insert(&root, val, &inserted);
                if(inserted){
                    printf("inserted\n");
                }else{
                    printf("not inserted\n");
                }
                break;
            case 's'://searches
                scanf("%d", &val);
                result = search(root, val);
                if(result){
                    printf("present\n");
                }else{
                    printf("absent\n");
                }
                break;
            case 'd'://deletes
                scanf("%d", &val);
                if(search(root, val)){
                    deleteNode(&root, val);
                    printf("deleted\n");
                }else{
                    printf("absent\n");
                }
                break;
            case 'p'://prints
                if(root == NULL){
                    printf("\n");
                }else{
                    print(root);
                    printf("\n");
                }
                break;
        }
    }
    return 0;
}