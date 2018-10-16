#include <stdio.h>
#include <stdlib.h>

typedef struct tree
{	
	int info;
	struct tree *left;
	struct tree *right;
	
}tree;

typedef struct Tree
{
	tree *root;
}Tree;

Tree *CreateTree()
{
	Tree *new = (Tree*)malloc(sizeof(Tree));
	if(new == NULL){
		puts("ERROR, CLOSING THE PROGRAM!");
		exit(1);
	}
	new->root = NULL;
	return new;
}

tree *Build_node_Tree( int son)
{
		tree *subTree1 = (tree*)malloc(sizeof(tree));
	
		if(subTree1 == NULL){
			puts("ERROR, CLOSING THE PROGRAM!");
			exit(1);
		}
		subTree1->info = son;
		subTree1->left = NULL;
		subTree1->right = NULL;
		return subTree1;
}

void Search_SubTree(tree *arv, int father, int son_l, int son_r)
{
	if(arv->root != NULL && arv->info == father){
		arv->left->info = 100;
		arv->root->right->info = 456;
	}else if(arv != NULL){
		Search_SubTree(arv->root->left,father, son_l, son_r);
		Search_SubTree(arv->root->right,father, son_l, son_r);
	}
	else{
		return;
	}
}

/*tree *Insert_Tree(Tree *Arv, int father, int son_left, int son_right)
{
	if(Arv->root == NULL){
		return Build_node_Tree(father);
	}else{
		Search_SubTree(Arv->root,father,son_left,son_right);
	}
	return Arv->root;
}*/

tree* InserirArvBin(tree *arvore, int valor)
{
  if(arvore == NULL){
 
 	 tree *subTree1 = (tree*)malloc(sizeof(tree));
	
		if(subTree1 == NULL){
			puts("ERROR, CLOSING THE PROGRAM!");
			exit(1);
		}
		subTree1->info = valor;
		subTree1->left = NULL;
		subTree1->right = NULL;
		return subTree1;
  }else{
      
      if(valor < arvore->info){
        arvore->left = InserirArvBin(arvore->left, valor);
      }else{
        arvore->right = InserirArvBin(arvore->right, valor);
      }
      return arvore;
  }
}
void Printtree(tree *arv)
{
    if(arv != NULL){
        Printtree(arv->left);
        printf("%d ", arv->info);
        Printtree(arv->right);
    }
}
int main()
{
	Tree *arv = CreateTree();

	int cases, i, *solution = NULL;
	scanf("%d", &cases);
	int father, son_l, son_r;
	solution = (int*)calloc(cases, sizeof(int));

	for(i=0;i<cases;i++)
	{
		scanf("%d", &father/*, &son_l, &son_r*/);
		//arv->root =  Insert_Tree(arv,father, son_l, son_r);
		arv->root = InserirArvBin(arv->root, father);
	}

	Printtree(arv->root);
	printf("\n");
	Search_SubTree(arv->root, 3, 4551, 4651);
	Printtree(arv->root);
	free(solution);

	return 0;
}