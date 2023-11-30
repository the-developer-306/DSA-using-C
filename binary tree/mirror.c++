void mirror(Node* root){
    if(root == NULL){
        return ;
    }
    else{
        Node* temp;
        mirror(root -> left);
        mirror(root -> right);

        temp = root -> left;
        root -> left = root -> right;
        root -> right = temp;
    }
}