void zigzag (Node* root){
    if(root == NULL){
        return ;
    }
    Node* temp;
    int leftToRight = 1;
    stack<Node*> s1;
    stack<Node*> s2;
    s1.push(root);
    while(!s1.empty()){
        temp = s1.top();
        s1.pop();
        if(temp){
            cout<<temp->data<<" ";
            if(leftToRight){
                if(temp->left){
                    s2.push(temp->left);
                }
                if(temp->right){
                    s2.push(temp->right);
                }
            }
            else {
                if(temp->right){
                    s2.push(temp->right);
                }
                if(temp->left){
                    s2.push(temp->left);
                }
            }
        }
        if(s1.empty()){
            leftToRight = 1 - leftToRight;
            swap(s1,s2);
        }
    }

}