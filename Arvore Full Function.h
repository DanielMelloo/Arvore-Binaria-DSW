// Documento formatado com a codifica��o ISO 8859-1

#include <iostream>
#include <math.h>
#include <stdlib.h>
#include <vector>

#define d 10

using namespace std;

    //=====================//
    //  Fun��es Gen�ricas  //
    //=====================//

void passagem2 (int& Gr, int& Pr, int& Ch)
{
    cout << "Gr= " << Gr << "\nPr= " << Pr << "Ch= " << Ch << endl;
}

void passagem ()
{
    cout << "Aqui Passou" << endl;
}

void mostravalor (int& n) // 1 valor de entrada
{
    cout << "1� valor= " << n << endl;
}

void mostravalor (int& n, int& m) // 2 valores de entrada
{
    cout << "1� valor= " << n << "2� valor= " << m << endl;
}

void mostravalor (int& n, int& m, int& q) // 3 valores de entrada
{
    cout << "1� valor= " << n << "2� valor= " << m << "3� valor= " << q << endl;
}

#ifndef BINARY_SEARCH_TREE
#define BINARY_SEARCH_TREE

    //=====================//
    //  Defini��es da BST  //
    //=====================//

template <class T>
class BSTNode 
{
    public:

    //=================================//
    // Construtores e Inicializadores  //
    //=================================//

        BSTNode ()
        {
            left = right = 0;
        } 
        BSTNode(const T& e, BSTNode<T> *l = 0, BSTNode<T> *r = 0) 
        {
            el = e; left = l; right = r;
        }
        BSTNode (const BSTNode&)=default; // C�pia

        int fb=0;
        T el;
        BSTNode<T> *left, *right;
};

template <class T>
class BST 
{
    public:
    
    //============================//
    //  Construtores e Destrutor  //
    //============================//

    BST() 
    {
        root = 0;
    }

    ~BST()
    {
        clear();
    }

    //===========================//
    //  Fun��es P�blicas da BST  //
    //===========================//

    void clear() 
    {
        clear(root); 
    }

    bool isEmpty() const 
    {
        return root == 0;
    }

    void preorder() 
    {
        preorder(root);
    }

    void inorder() 
    {
        inorder(root);
    }

    void postorder() 
    {
        postorder(root);
    }

    void preorderheight ()
    {
        preorderheight (root);
    }

    T* search(const T& el) const 
    {
        return search(root,el);
    }

    int countNodesL (const T& el)
    {
        BSTNode<T>* tmp=searchNode (root, el);
    
        return countNodesL (tmp->left);
    }

    int countNodesR (const T& el)
    {
        BSTNode<T>* tmp=searchNode (root, el);

        return countNodesR (tmp->right);
    }

    void viewtree ()
    {
        viewtree (root, 5);
    }
    
    void mostrarFB (int valorN)
    {
        BSTNode<T> *tmp=searchNode (root, valorN);
        cout << "O fator de Balanceamento do N� " << tmp->el << " � " << tmp->fb << endl;
        delete tmp;
    }

    void createBackboneRa ()
    {
        createBackboneR ();
    }

    void createBackboneLa ()
    {
        createBackboneL ();
    }

    void createPerfTR ()
    {
        createPerfectTreeR ();
    }

    void createPerfTL ()
    {
        createPerfectTreeL ();
    }
    
    void countNodes ()
    {
        cout << "A �rvore tem " << countNodes (root) << " N�s" << endl;
    }

    void deleteNodeV (int n)
    {
        BSTNode<T>* tmp=searchNode (root, n);

        if (tmp!=NULL)
        {
            deleteNodeN (tmp);
        }

        else
        {
            cout << "\nO n� informado n�o existe, nenhuma dele��o realizada!!" << endl;
        }

    }

    vector<T> identifyLeafsV (const T& n)
    {
        vector<T> vec;

        BSTNode<T>* tmp=searchNode (root, n);

        return identifyLeafsV (tmp, vec);  
    }  

    bool oneNode ()
        {
            if (!isEmpty () && root->left == NULL && root->right == NULL)
            {
                return true;
            }

            return false;
        }

    void deleteLeafsV (const T& el)
    {
        BSTNode<T>* tmp=searchNode (root, el);

        deleteLeafs (tmp); 
    }

    int balanceFactor (int n)
    {
        return balanceFactorDef (searchNode (root, n));
    }

    void insert (const T& el);

    void breadthFirst();

protected:

    BSTNode<T>* root;

    //================================//
    //  Prot�tipo das Fun��es da BST  //
    //================================//

    virtual void visit ( BSTNode<T>* p )                        // Monstra o valor do n� informado
    {
        cout << p->el << ' ';   
    }   
    void clear ( BSTNode<T>* ) {root=0;}                        // Limpa a �rvore
    T* search ( BSTNode<T>*, const T& ) const;                  // Ve onde e se o elemento informado esta na arvore
    void preorder ( BSTNode<T>* );                              // Procedimento pr�-ordem
    void inorder ( BSTNode<T>* );                               // Procedimento em ordem
    void postorder ( BSTNode<T>* );                             // Procedimento p�s-ordem
    int height ( BSTNode<T>* );                                 // Retorna a altura de um n�
    int balanceFactorAtt ( BSTNode<T>* );                       // Calcula o fator de balanceamento do n� informado (considerando que n�o tem ele no membro public)
    void viewtree (BSTNode<T>*, int );                          // Visualizar �rvore
    BSTNode<T>* searchNode ( BSTNode<T>*, const T& );           // Retorna o n� a partir de um n� base (normalmente a root) e o valor do n� a ser encontrado
    BSTNode<T>* prNode ( BSTNode<T>* );                         // Retorna o Ascendente do n� Informado
    void rotateLeft  ( BSTNode<T>*, BSTNode<T>*, BSTNode<T>* ); // Rotaciona � esquerda
    void rotateRight ( BSTNode<T>*, BSTNode<T>*, BSTNode<T>* ); // Rotaciona � direita
    void updateBalanceFactors ( BSTNode<T>* );                  // Atualiza o Fator de Balanceamento dos N�s inseridos
    int countNodesL ( BSTNode<T>* );                            // Conta quantos n�s tem � Esquerda no n� informado
    int countNodesR ( BSTNode<T>* );                            // Conta quantos n�s tem � Direita no n� informado
    int countNodes  ( BSTNode<T>* );                            // Conta quantos n�s tem �o total
    void createBackboneL ();                                    // Com rota��o � direita
    void createBackboneR ();                                    // Com rota��o � esquerda
    void createPerfectTreeR ();                                 // S� pode ser aplicado em backbone pra direita
    void createPerfectTreeL ();                                 // S� pode ser aplicado em backbone pra direita
    int qtdNodesR ();                                           // S� pode ser aplicado em n�s pra direita
    int qtdNodesL ();                                           // S� pode ser aplicado em n�s pra esquerda
    void preorderheight ( BSTNode<T>* );                        // Visualiza os n�s com suas respectivas alturas em no prercuso Pr�-Ordem
    int balanceFactorDef ( BSTNode<T>* );                       // Define o fator de balancemanto de cada n�
    void fusionDelete ( BSTNode<T>*& );                         // Dele��o por fus�o
    void deleteNodeN ( BSTNode<T>*& );                          // Deleta o N� informado
    void deleteLeafs ( BSTNode<T>* );                           // Deleta as folhas de uma �rvore dadas as folhas em um vetor
    vector<T> identifyLeafsV ( BSTNode<T>*, vector<T> );        // Identifica as Folhas de uma �rvore ou subarvore a partir de um no informado   
    bool isInVector (vector<T>, int );                          // Verifica se o valor inserido est� no vetor
    int maxHeight ( BSTNode<T>* );                              // Identifica a altura m�xima de descendentes de um N�
    void balanceFactorAll ( BSTNode<T>* );                      // Redefine o Fator de Balanceamento de todos os N�s

};

    //=================================//
    //  Defini��es das Fun��es da BST  //
    //=================================//

template <class T>
int BST<T>::maxHeight (BSTNode<T>* p)
{

    //=========================//
    //  Caso 0 -> O N� � Nulo  //
    //=========================//

    if ( p == NULL )
    {
        return 0;
    }

    //============================//
    //  Caso 1 -> O N� � a folha  //
    //============================//

    else if ( p->left == NULL && p->right == NULL )
    {
        return height (p);
    }

    //============================================================//
    //  Caso 2 -> Os decendentes � esquerda tem uma altura maior  //
    //============================================================//

    else if ( maxHeight ( p->left ) > maxHeight ( p->right ) || p->right == NULL)
    {
        return maxHeight ( p->left );
    }

    //===========================================================//
    //  Caso 3 -> Os decendentes � Direita tem uma altura maior  //
    //===========================================================//

    else if ( maxHeight ( p->right) > maxHeight ( p->left ) || p->left==NULL)
    {
        return maxHeight ( p->right);
    }

    //=====================================================//
    //  Caso 4 -> Ambos os decendentes tem a mesma altura  //
    //=====================================================//

    else if (maxHeight ( p->right) == maxHeight ( p->left ))
    {
        return maxHeight ( p->right);
    }

    //=====================================//
    //  Caso 5 -> Nenhumas das Anteriores  //
    //=====================================//

    else
    {
        return 0;
    }
}

template <class T>
void BST<T>::balanceFactorAll (BSTNode<T>* p)
{
    if ( p != 0 ) 
    {
        p->fb=balanceFactorDef (p);
        balanceFactorAll (p->left);
        balanceFactorAll (p->right);
    }
}

template <class T>
vector<T> BST<T>::identifyLeafsV (BSTNode<T>* p, vector<T> vec)
{
        BSTNode<T>* tmp=p;

            //=====================//
            //  Fase de Varredura  //
            //=====================//

        //=====================================//
        //  Caso 0 -> S� tem a root na �rvore  //
        //=====================================//

        if (tmp==root && (tmp->left == NULL && tmp->right == NULL))
        {
            cout << "A �rvore n�o possui folhas!!" << endl;
            return vec;
        }

        //======================================//
        //  Caso 1 -> s� tem filhos � esquerda  //
        //======================================//

        if (tmp->left != NULL && tmp->right == NULL)
        {
            tmp=tmp->left;
        }


        //=====================================//
        //  Caso 2 -> s� tem filhos � direita  //
        //=====================================//

        else if (tmp->left == NULL && tmp->right != NULL)
        {
            tmp=tmp->right;
        }

        //==============================================//
        //  Caso 3 -> Tem filhos � esqueda e � direita  //
        //==============================================//

        if (tmp->left != NULL && tmp->right != NULL)
        {
            vec=identifyLeafsV (tmp->left, vec);
            vec=identifyLeafsV (tmp->right, vec);
        }

        //==============================//
        //  Inser��o da folha no vetor  //
        //==============================//
    
        if ( !isInVector (vec, tmp->el) && ( tmp->left == NULL && tmp->right == NULL) )
        {                                                 
            vec.push_back ( tmp->el );
        } 

    return vec;
}

template <class T>
bool BST<T>::isInVector (vector<T> vec, int n )
{
    if ( vec.empty() ) // Se o vetor est� vazio
    {
        return false; // autom�ticamente o elemento n�o est� nele, pois nem elemnto tem
    }

    for ( int i=0 ; vec.back()!=vec[i] ; i++ ) // varre o vetor verificando se o elemento est� nele
    {
        if ( vec[i] == n )
        {
            return true;
        }
    }
    return false;
}

template <class T>
void BST<T>::deleteLeafs (BSTNode<T>* p)
{
    BSTNode<T>* tmp;
    vector<T> vec;
    vec=identifyLeafsV (p, vec);
    

    while ( !vec.empty() )
    {
        tmp = searchNode ( root, vec.back() );

        if ( tmp==root )
        {
            return;
        }

        vec.pop_back () ;
        deleteNodeN (tmp);
    }
}

template <class T>
void BST<T>::deleteNodeN (BSTNode<T>*& p)
{
    BSTNode<T>* Pr=root; // Ascendente de p

    //===============================//
    //  Definindo o Ascendente de p  //
    //===============================//

    {

    if ( Pr == p) // Caso o n� a ser deletado seja raiz
    {
        Pr=NULL;
    }
    if ( Pr != NULL)
    {
        Pr=prNode (p);
    }

    }

    //===========================//
    //  Caso 0 -> O N� � a raiz  //
    //===========================// // testar para arvores desbalanceadas pra cada lado

    if ( Pr == NULL ) 
    {
        // Escolha de Implementa��o -> deleta a root e transforma o n� � direita como root no default
        if ( p->right != NULL && p->left != NULL ) // Se tem filho � direita da root e � esquerda
        {
            BSTNode<T>* tmp=p->right;

            while ( tmp->left != NULL )
            {
                tmp=tmp->left;
            }

            tmp->left=p->left;
            root=p->right;

            delete p;
        }

        else if ( p->left == NULL && p->right != NULL) // S� tem filho � direita da root
        {
            root=p->right;

            cout << "root=" << root->el << endl;
            cout << "root left=" << root->left->el << endl;
            cout << "root right=" << root->right->el << endl;

            delete p;
        }

        else if ( p->left != NULL && p->right == NULL) // S� tem filho � esquerda da root
        {
            root=p->left;
            delete p;
        }

        else // se nao tem filhos
        {
            delete p;
        }
    }

    //=================================//
    //  Caso 1 -> O N� n�o tem filhos  //
    //=================================//

    else if ( p->left == NULL && p->right == NULL )
    {
        if ( Pr->left == p ) // Verifica se p est� � esquerda de Pr
        {
            Pr->left=NULL;
        }

        else if ( Pr->right == p ) // Verifica se p est� � direita de Pr
        {
            Pr->right=NULL;
        }

        delete p;
    }
    
    //==============================//
    //  Caso 2 -> O N� tem 1 filho  //
    //==============================//

    else if ( ( p->left != NULL && p->right == NULL ) ) // Se p tem um filho � esquerda   
    {
        Pr->left=p->left;

        delete p;
    }

    else if ( p->left == NULL && p->right != NULL ) // Se p tem um filho � direita   
    {
        Pr->right=p->right;

        delete p;
    }

    //==================================//
    //  Caso 3 -> O N� tem dois filhos  //
    //==================================//

    else if ( ( p->left != NULL && p->right != NULL ) && Pr != NULL )
    {
        fusionDelete (p);
    }

    //=========================//
    //  Caso 4 -> O N� � nulo  //
    //=========================//

    else if ( p == NULL )
    {
        cout << "O n� a solicitado ser removido n�o existe!!!" << endl;
    }
    
    //===============================================//
    //  Fase de Inser��o do Fator de Ba�lanceamento  //
    //===============================================//

    balanceFactorAll (root);
}

template <class T>
int BST<T>::countNodes (BSTNode<T>* p)
{
    if(p==NULL)
    {
        return 0;
    }
    else
    {
        return 1 + countNodes(p->left) + countNodes(p->right);
    }

    return 0;
}

template <class T>
void BST<T>::fusionDelete (BSTNode<T>*& p)
{
    BSTNode<T>* Pr=prNode (p), *tmp=p->right;
            
    while ( tmp->left != NULL )
    {
        tmp=tmp->left;
    }

    if ( Pr->left == p )
    {
        Pr->left=p->right;
    }

    else if ( Pr->right == p )
    {
        Pr->right=p->right;
    }

    tmp->left=p->left;
    delete p;
}

template <class T>
int BST<T>::balanceFactorDef (BSTNode<T>* p)
{
    int hl=1, hr=1;

    //=====================//
    //  Altura � Esquerda  //
    //=====================//

    
    hl=maxHeight (p->left);


    //====================//
    //  Altura � Direita  //
    //====================//


    hr=maxHeight (p->right);


    return hr-hl;
}

template <class T>
int BST<T>::countNodesL (BSTNode<T>* p)
{
    if(p==NULL)
    {
        return 0;
    }
    else
    {
        return 1 + countNodesL (p->left);
    }

    return 0;
}

template <class T>
int BST<T>::countNodesR (BSTNode<T>* p)
{
    if(p==NULL)
    {
        return 0;
    }
    else
    {
        return 1 + countNodesR (p->right);
    }

    return 0;
}

template <class T>
void BST<T>::preorderheight (BSTNode<T>* p)
{
    int h;

    if ( p != 0 ) 
    {
        cout << "Node: ";   
        visit(p);
        h=height(p);
        cout << "\tHeight:\t" << h << endl;
        preorderheight (p->left);
        preorderheight (p->right);
    }
}

template <class T>
void BST<T>:: createPerfectTreeR ()
{
    if (countNodesR (root) == countNodes (root))
    {
        BSTNode<T> *Gr, *Pr=root, *Ch=Pr->right;
        int n=countNodesR (root) ; // conta quantos n�s � direita da root e soma com a pr�pria root

        float m=( pow ( 2, log2 ( n - 1 ) ) ) -1;
        
        for (int i=0;i<(n-m);i++)
        {
            rotateLeft (Gr, Pr, Ch);
            Gr=root;
            Pr=Gr->right;
            Ch=Pr->right;
        }

        Pr=root;
        Ch=Pr->right;
        
        while (m>1)
        {
            if(Pr==root)
            {
                rotateLeft (Gr, Pr, Ch);
                Gr=root;
                Pr=Gr->right;
                Ch=Pr->right;
                m=m/2;
            }

            rotateLeft (Gr, Pr, Ch);

            Gr=Gr->right;
            Pr=Gr->right;
            Ch=Pr->right;
            m=m/2;
        }
        cout << "\n ** �rvore Balanceada! **\n\n";
    }

    else
    {
        cout << "\n�rvore n�o nalanceada pois o backbone est� para o lado errado!!\n\n";
    }


}

template <class T>
void BST<T>:: createPerfectTreeL () // Nada Foi alterado
{
    if (countNodesR (root) == countNodes (root))
    {
        BSTNode<T> *Gr, *Pr=root, *Ch=Pr->right;
        int n=countNodesR (root) ; // conta quantos n�s � direita da root e soma com a pr�pria root

        float m=( pow ( 2, log2 ( n - 1 ) ) ) -1;
        
        for (int i=0;i<(n-m);i++)
        {
            rotateLeft (Gr, Pr, Ch);
            Gr=root;
            Pr=Gr->right;
            Ch=Pr->right;
        }

        Pr=root;
        Ch=Pr->right;
        
        while (m>1)
        {
            if(Pr==root)
            {
                rotateLeft (Gr, Pr, Ch);
                Gr=root;
                Pr=Gr->right;
                Ch=Pr->right;
                m=m/2;
            }

            rotateLeft (Gr, Pr, Ch);

            Gr=Gr->right;
            Pr=Gr->right;
            Ch=Pr->right;
            m=m/2;
        }
        cout << "\n ** �rvore Balanceada! **\n\n";
    }

    else
    {
        cout << "\n�rvore n�o nalanceada pois o backbone est� para o lado errado!!\n\n";
    }


}

template <class T>
void BST<T>::createBackboneL ()
{
    BSTNode<T> *tmp, *Gr;

    tmp=root;

    while (tmp!=0)
    {
        while (tmp==root) // Quando o pai � a raiz
        {
            if (tmp->right!=0) // Se a raiz tem filho � esquerda
            {
                rotateLeft (Gr, tmp, tmp->right);
                tmp=root;
            }

            if (tmp->right==0 && tmp==root) // Se a raiz s� tem filho � direita
            {
                Gr=root;
                tmp=Gr->left;
            }
        }
            
        if (tmp!=root)// Quando o n�o � raiz
        {
            while (tmp->right!=0) 
            {
                rotateLeft (Gr, tmp, tmp->right);
                tmp=Gr->left;
            }
        }

        Gr=Gr->left;
        tmp=Gr->left;
    }
}

template <class T>
void BST<T>::createBackboneR ()
{
    BSTNode<T> *tmp, *Gr;

    tmp=root;

    while (tmp!=0)
    {
        while (tmp==root) // Quando o pai � a raiz
        {
            if (tmp->left!=0) // Se a raiz tem filho � esquerda
            {
                rotateRight (Gr, tmp, tmp->left);
                tmp=root;
            }

            if (tmp->left==0 && tmp==root) // Se a raiz s� tem filho � direita
            {
                Gr=root;
                tmp=Gr->right;
            }
        
        }    

        if (tmp!=root)// Quando o n�o � raiz
        {
            while (tmp->left!=0) 
            {
                rotateRight (Gr, tmp, tmp->left);
                tmp=Gr->right;
            }
        }

        Gr=Gr->right;
        tmp=Gr->right;
        
        //================//
        // certo at� aqui //
        //================//

    }
}

template <class T>
void BST<T>::rotateRight (BSTNode<T>* Gr, BSTNode<T>* Pr, BSTNode<T>* Ch)
{
    // Gr = pai de Par
    // Par = pai de Ch

    if ( Pr == root )
    {
        Pr->left=Ch->right;
        Ch->right=Pr;
        root=Ch;
    }

    else if ( Pr == Gr->right )
    {
        Pr->left=Ch->right;
        Ch->right=Pr;
        Gr->right=Ch;
    }

    else if ( Pr == Gr->left )
    {
        Pr->left=Ch->right;
        Ch->right=Pr;
        Gr->left=Ch;
    }
}

template <class T>
void BST<T>::rotateLeft (BSTNode<T>* Gr, BSTNode<T>* Pr, BSTNode<T>* Ch)
{
    // Gr = pai de Par
    // Par = pai de Ch

    if ( Pr == root )
    {
        Pr->right=Ch->left;
        Ch->left=Pr;
        root=Ch;
    }

    else if ( Pr == Gr->left )
    {
        Pr->right=Ch->left;
        Ch->left=Pr;
        Gr->left=Ch;
    }

    else if ( Pr == Gr->right )
    {
        Pr->right=Ch->left;
        Ch->left=Pr;
        Gr->right=Ch;
    }
}

template <class T>
void BST<T>::updateBalanceFactors (BSTNode<T>* q /*N� que foi inserido*/)
{
    BSTNode<T>* p=prNode (q);

    if ( p!=NULL )
    {
        if (p->left==q)
        {
            p->fb--;
        }

        else
        {
            p->fb++;
        }

        while (  p!=root && (p->fb!=2 || p->fb!=-2))
        {
            q=p;
            p=prNode ( p );

            if ( q->fb == 0 )
            {
                return;
            }

            if ( q==p->left )
            {
                p->fb--;
            }

            else
            {
                p->fb++;
            }

            if ( p->fb == 2 )
            {
                rotateLeft ( prNode (p), p, q );
            }

            else if ( p->fb == -2 )
            {
                rotateRight ( prNode (p), p, q );
            }
        }    
    }    
}

template <class T>
BSTNode<T>* BST<T>::prNode (BSTNode<T>* p)
{
    BSTNode<T>* Pr=root;

    if ( Pr == p) // Caso o n� n�o tenha ascendente
    {
        Pr=NULL;
    }

    else
    {
        while ( Pr->left!=p && Pr->right!=p )
        {
            if ( Pr->el < p->el ) // Se p est� � direita de Pr ent�o mover para direto
            {
                Pr=Pr->right;
            }
        
            else if ( Pr->el > p->el ) // Se p est� � esquerda de Pr ent�o mover para esquerda
            {
                Pr=Pr->left;
            }
        }
    }
    
    return Pr;
}

template <class T>
void BST<T>::viewtree (BSTNode<T>* p, int n) 
{
    if(p == NULL)
    {
        return;
    }

    n += d;
    viewtree (p->right, n);
    cout << "\n";

    for(int i = d; i < n; i++)
    {
        cout << " " ;
    }

    cout << p->el << endl;

    viewtree (p->left, n);
}

template <class T>
BSTNode<T>* BST<T>::searchNode (BSTNode<T>* p, const T& el)
{
    while (p != 0)
    {
        if (el == p->el)
        {
            return p;
        }
        else if (el < p->el)
        {
            p = p->left;
        }
        else 
        {
            p = p->right;
        }
    }
    return NULL;
}

template <class T>
int BST<T>::height (BSTNode<T>* p)
{
    int i=0;

    BSTNode<T>* tmp=root;

    while (tmp != 0)
    {
        i++;

        if (p->el == tmp->el)
            return i;

        else if (p->el < tmp->el)

        tmp = tmp->left;

        else tmp = tmp->right;

        
    }
    return i;
}

template <class T>
void BST<T>::insert (const T& el) 
{
    BSTNode<T> *p = root, *prev = 0, *tmp;
    
    while (p != 0) 
    { // encontrar um lugar para inserir um n�
        prev = p;

        if (el < p->el)
        {
            p = p->left;
        }

        else
        {
            p = p->right;
        }    
    }

    if (root == 0) // verifica se a �rvore esta vazia
    {
        root = new BSTNode<T>(el); //insere o n� na raiz
        tmp=root;
    }

    else if (el < prev->el) // compara el com o filho � esquerda
    {
        prev->left = new BSTNode<T>(el); //insere o n� no filho � esquerda
        
    }

    else 
    {
        prev->right = new BSTNode<T>(el); //insere o n� no filho � direita.
    }

    //===============================================//
    //  Fase de Inser��o do Fator de Ba�lanceamento  //
    //===============================================//

    tmp=searchNode (root, el);
    updateBalanceFactors ( tmp );

    balanceFactorAll (root);
}

template<class T>
T* BST<T>::search(BSTNode<T>* p, const T& el) const 
{
    while (p != 0)
        if (el == p->el)
            return &p->el;
    else if (el < p->el)
        p = p->left;
    else p = p->right;
        return 0;
}

template <class T>
void BST<T>::inorder (BSTNode<T> *p) 
{
    if ( p != 0 ) 
    {
        inorder (p->left);
        visit(p);
        inorder (p->right);
    }
}

template <class T>
void BST<T>::preorder (BSTNode<T> *p) 
{
    if ( p != 0 ) 
    {
        visit(p);
        preorder (p->left);
        preorder (p->right);
    }
}

template <class T>
void BST<T>::postorder (BSTNode<T> *p) 
{
    if ( p != 0 )
    {
        postorder (p->left);
        postorder (p->right);
        visit(p);
    }
}

#endif
