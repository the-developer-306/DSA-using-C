Node* deletion(Node* root,int key){
    if(root == NULL){
        return NULL;
    }
    if(root -> left == NULL && root -> right == NULL){
        if(root -> data == key){
            return NULL;
        }
        else {
            return root;
        }
    }
    queue<Node*> q;
    q.push(root);
    Node* key_node = NULL;
    Node* temp ;
    while(!q.empty()){
        temp = q.front();
        q.pop();
        if(temp -> data == key){
            key_node = temp;
        }
        if(temp -> left){
            q.push(temp -> left);
        }
        if(temp -> right){
            q.push(temp -> right);
        }
    }
    if(key_node != NULL){
        int deep_node = temp -> data;
        deleteDeep(root , temp);
        key_node -> data = deep_node;
    }
    return root;

}