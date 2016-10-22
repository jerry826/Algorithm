#include<iostream>  
using namespace std;


int num_visit=0;//记录输出元素个数  





struct tnode{     
    public: int data;  
    public: tnode *left,*right;  
      
    tnode(){}  
    tnode(int item,tnode *p,tnode *q):data(item),left(p),right(q){}  
 }; 


typedef tnode*  Tnode ;  


bool search(Tnode root, int search_num){
	if (root==NULL){
		return false;
	}else{
		if (root->data == search_num){
			return true ;
		}else{
		
			if (root->data>search_num){
				return search(root->left, search_num);
			}else{
				return search(root->right, search_num);
		}
	}
	}
}


Tnode insert(Tnode root, int insert_num)
{
	
	if (!search(root,insert_num)){
		
		
		
		if (root == NULL){
			root = new tnode(insert_num,NULL,NULL);
		}
		else {
			if (root->data > insert_num){
				root->left = insert(root->left, insert_num);
			}else{
				root->right = insert(root->right, insert_num);
			}
			
		}
	
	}
	return root;
}

Tnode buildtree(int pdata[], int k)
{
	Tnode root;
	root = NULL;
	
	for (int i=0;i<k;i++)
	{
		root = insert(root,pdata[i]);
	}
	
	return root;
	
}


void visit(int n){
	cout<<n<<" ,";
}



int inorder_showTree(Tnode root){  
    if(root){  
        inorder_showTree(root->left);  
        visit(root->data);  
        inorder_showTree(root->right);  
    }else  
        return 0;  
} 


int postorder_showTree(Tnode root){  
    if(root){  
        postorder_showTree(root->left);  
        postorder_showTree(root->right);  
        visit(root->data);  
    }else   
        return 0;  
} 

int level_showTree(Tnode root){  
    if(root){  
        visit(root->data);  
        level_showTree(root->left);  
        level_showTree(root->right);  
    }else  
        return 0;  
} 

void delete_node(Tnode root, int delete_num){
	if (root){
		if (root->left->data==delete_num){
			
		}else if(root->left->data==delete_num{
			delete_node()
		}
		
		
		
		
		
	}
	
}



Tnode insert(Tnode root,int insert_num);//插入  
Tnode buildtree(int pdata[], int k);
bool search(Tnode root, int search_num);




int main()
{
	Tnode root;
	bool v0, v1, v2, v3;
	int input[] = {5,4,2,1,7,6,9,0,3,8,11,11};
	root = buildtree(input,12);
	v0 = (root==NULL);
	v1 = search(root,5);
	v2 = search(root,8);
	v3 = search(root,15);
	cout << v0<<" "<<v1 <<" "<<v2 <<" "<< v3<<"\n"<<endl; 
	cout << "\n "<<"Inorder: ";
	inorder_showTree(root);
	cout << "\n "<< "levelorder: ";
	level_showTree(root);
	cout << "\n "<< "Post order: ";
	postorder_showTree(root);


//	cout<<root->left->data<<endl;




	return 0; 
}
