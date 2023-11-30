void deleteDeep(Node* root,Node* delete_node){
    queue<Node*> q;
    q.push(root);
    Node* temp;
    while(!q.empty()){
        temp = q.front();
        q.pop();
        if(temp == delete_node){
            temp = NULL;
            delete(delete_node);
            return;
        }
        if(temp -> right){
            if(temp -> right == delete_node){
                temp -> right = NULL;
                delete (temp->right);
                return;
            }
            else{
                q.push(temp -> right);
            }
        }
        if(temp -> left){
            if(temp -> left == delete_node){
                temp -> left == NULL;
                delete(temp -> left);
                return;
            }
            else{
                q.push(temp -> left);
            }
        }

    }
}