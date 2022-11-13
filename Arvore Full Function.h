// Documento formatado com a codificação ISO 8859-1

#include <iostream>
#include <math.h>
#include <stdlib.h>
#include <vector>

#define d 10

using namespace std;

    //=====================//
    //  Funções Genéricas  //
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
    cout << "1° valor= " << n << endl;
}

void mostravalor (int& n, int& m) // 2 valores de entrada
{
    cout << "1° valor= " << n << "2° valor= " << m << endl;
}

void mostravalor (int& n, int& m, int& q) // 3 valores de entrada
{
    cout << "1° valor= " << n << "2° valor= " << m << "3° valor= " << q << endl;
}

#ifndef BINARY_SEARCH_TREE
#define BINARY_SEARCH_TREE

    //=====================//
    //  Definições da BST  //
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
        BSTNode (const BSTNode&)=default; // Cópia

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
    //  Funções Públicas da BST  //
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
        cout << "O fator de Balanceamento do Nó " << tmp->el << " é " << tmp->fb << endl;
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
        cout << "A árvore tem " << countNodes (root) << " Nós" << endl;
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
            cout << "\nO nó informado não existe, nenhuma deleção realizada!!" << endl;
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
    //  Protótipo das Funções da BST  //
    //================================//

    virtual void visit ( BSTNode<T>* p )                        // Monstra o valor do nó informado
    {
        cout << p->el << ' ';   
    }   
    void clear ( BSTNode<T>* ) {root=0;}                        // Limpa a árvore
    T* search ( BSTNode<T>*, const T& ) const;                  // Ve onde e se o elemento informado esta na arvore
    void preorder ( BSTNode<T>* );                              // Procedimento pré-ordem
    void inorder ( BSTNode<T>* );                               // Procedimento em ordem
    void postorder ( BSTNode<T>* );                             // Procedimento pós-ordem
    int height ( BSTNode<T>* );                                 // Retorna a altura de um nó
    int balanceFactorAtt ( BSTNode<T>* );                       // Calcula o fator de balanceamento do nó informado (considerando que não tem ele no membro public)
    void viewtree (BSTNode<T>*, int );                          // Visualizar árvore
    BSTNode<T>* searchNode ( BSTNode<T>*, const T& );           // Retorna o nó a partir de um nó base (normalmente a root) e o valor do nó a ser encontrado
    BSTNode<T>* prNode ( BSTNode<T>* );                         // Retorna o Ascendente do nó Informado
    void rotateLeft  ( BSTNode<T>*, BSTNode<T>*, BSTNode<T>* ); // Rotaciona à esquerda
    void rotateRight ( BSTNode<T>*, BSTNode<T>*, BSTNode<T>* ); // Rotaciona à direita
    void updateBalanceFactors ( BSTNode<T>* );                  // Atualiza o Fator de Balanceamento dos Nós inseridos
    int countNodesL ( BSTNode<T>* );                            // Conta quantos nós tem à Esquerda no nó informado
    int countNodesR ( BSTNode<T>* );                            // Conta quantos nós tem à Direita no nó informado
    int countNodes  ( BSTNode<T>* );                            // Conta quantos nós tem ào total
    void createBackboneL ();                                    // Com rotação à direita
    void createBackboneR ();                                    // Com rotação à esquerda
    void createPerfectTreeR ();                                 // Só pode ser aplicado em backbone pra direita
    void createPerfectTreeL ();                                 // Só pode ser aplicado em backbone pra direita
    int qtdNodesR ();                                           // Só pode ser aplicado em nós pra direita
    int qtdNodesL ();                                           // Só pode ser aplicado em nós pra esquerda
    void preorderheight ( BSTNode<T>* );                        // Visualiza os nós com suas respectivas alturas em no prercuso Pré-Ordem
    int balanceFactorDef ( BSTNode<T>* );                       // Define o fator de balancemanto de cada nó
    void fusionDelete ( BSTNode<T>*& );                         // Deleção por fusão
    void deleteNodeN ( BSTNode<T>*& );                          // Deleta o Nó informado
    void deleteLeafs ( BSTNode<T>* );                           // Deleta as folhas de uma árvore dadas as folhas em um vetor
    vector<T> identifyLeafsV ( BSTNode<T>*, vector<T> );        // Identifica as Folhas de uma árvore ou subarvore a partir de um no informado   
    bool isInVector (vector<T>, int );                          // Verifica se o valor inserido está no vetor
    int maxHeight ( BSTNode<T>* );                              // Identifica a altura máxima de descendentes de um Nó
    void balanceFactorAll ( BSTNode<T>* );                      // Redefine o Fator de Balanceamento de todos os Nós

};

    //=================================//
    //  Definições das Funções da BST  //
    //=================================//

template <class T>
int BST<T>::maxHeight (BSTNode<T>* p)
{

    //=========================//
    //  Caso 0 -> O Nó é Nulo  //
    //=========================//

    if ( p == NULL )
    {
        return 0;
    }

    //============================//
    //  Caso 1 -> O Nó é a folha  //
    //============================//

    else if ( p->left == NULL && p->right == NULL )
    {
        return height (p);
    }

    //============================================================//
    //  Caso 2 -> Os decendentes à esquerda tem uma altura maior  //
    //============================================================//

    else if ( maxHeight ( p->left ) > maxHeight ( p->right ) || p->right == NULL)
    {
        return maxHeight ( p->left );
    }

    //===========================================================//
    //  Caso 3 -> Os decendentes à Direita tem uma altura maior  //
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
        //  Caso 0 -> Só tem a root na árvore  //
        //=====================================//

        if (tmp==root && (tmp->left == NULL && tmp->right == NULL))
        {
            cout << "A árvore não possui folhas!!" << endl;
            return vec;
        }

        //======================================//
        //  Caso 1 -> só tem filhos à esquerda  //
        //======================================//

        if (tmp->left != NULL && tmp->right == NULL)
        {
            tmp=tmp->left;
        }


        //=====================================//
        //  Caso 2 -> só tem filhos à direita  //
        //=====================================//

        else if (tmp->left == NULL && tmp->right != NULL)
        {
            tmp=tmp->right;
        }

        //==============================================//
        //  Caso 3 -> Tem filhos à esqueda e à direita  //
        //==============================================//

        if (tmp->left != NULL && tmp->right != NULL)
        {
            vec=identifyLeafsV (tmp->left, vec);
            vec=identifyLeafsV (tmp->right, vec);
        }

        //==============================//
        //  Inserção da folha no vetor  //
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
    if ( vec.empty() ) // Se o vetor está vazio
    {
        return false; // automáticamente o elemento não está nele, pois nem elemnto tem
    }

    for ( int i=0 ; vec.back()!=vec[i] ; i++ ) // varre o vetor verificando se o elemento está nele
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

    if ( Pr == p) // Caso o nó a ser deletado seja raiz
    {
        Pr=NULL;
    }
    if ( Pr != NULL)
    {
        Pr=prNode (p);
    }

    }

    //===========================//
    //  Caso 0 -> O Nó é a raiz  //
    //===========================// // testar para arvores desbalanceadas pra cada lado

    if ( Pr == NULL ) 
    {
        // Escolha de Implementação -> deleta a root e transforma o nó à direita como root no default
        if ( p->right != NULL && p->left != NULL ) // Se tem filho à direita da root e à esquerda
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

        else if ( p->left == NULL && p->right != NULL) // Só tem filho à direita da root
        {
            root=p->right;

            cout << "root=" << root->el << endl;
            cout << "root left=" << root->left->el << endl;
            cout << "root right=" << root->right->el << endl;

            delete p;
        }

        else if ( p->left != NULL && p->right == NULL) // Só tem filho à esquerda da root
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
    //  Caso 1 -> O Nó não tem filhos  //
    //=================================//

    else if ( p->left == NULL && p->right == NULL )
    {
        if ( Pr->left == p ) // Verifica se p está à esquerda de Pr
        {
            Pr->left=NULL;
        }

        else if ( Pr->right == p ) // Verifica se p está à direita de Pr
        {
            Pr->right=NULL;
        }

        delete p;
    }
    
    //==============================//
    //  Caso 2 -> O Nó tem 1 filho  //
    //==============================//

    else if ( ( p->left != NULL && p->right == NULL ) ) // Se p tem um filho à esquerda   
    {
        Pr->left=p->left;

        delete p;
    }

    else if ( p->left == NULL && p->right != NULL ) // Se p tem um filho à direita   
    {
        Pr->right=p->right;

        delete p;
    }

    //==================================//
    //  Caso 3 -> O Nó tem dois filhos  //
    //==================================//

    else if ( ( p->left != NULL && p->right != NULL ) && Pr != NULL )
    {
        fusionDelete (p);
    }

    //=========================//
    //  Caso 4 -> O Nó é nulo  //
    //=========================//

    else if ( p == NULL )
    {
        cout << "O nó a solicitado ser removido não existe!!!" << endl;
    }
    
    //===============================================//
    //  Fase de Inserção do Fator de Baçlanceamento  //
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
    //  Altura à Esquerda  //
    //=====================//

    
    hl=maxHeight (p->left);


    //====================//
    //  Altura à Direita  //
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
        int n=countNodesR (root) ; // conta quantos nós à direita da root e soma com a própria root

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
        cout << "\n ** Árvore Balanceada! **\n\n";
    }

    else
    {
        cout << "\nÁrvore não nalanceada pois o backbone está para o lado errado!!\n\n";
    }


}

template <class T>
void BST<T>:: createPerfectTreeL () // Nada Foi alterado
{
    if (countNodesR (root) == countNodes (root))
    {
        BSTNode<T> *Gr, *Pr=root, *Ch=Pr->right;
        int n=countNodesR (root) ; // conta quantos nós à direita da root e soma com a própria root

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
        cout << "\n ** Árvore Balanceada! **\n\n";
    }

    else
    {
        cout << "\nÁrvore não nalanceada pois o backbone está para o lado errado!!\n\n";
    }


}

template <class T>
void BST<T>::createBackboneL ()
{
    BSTNode<T> *tmp, *Gr;

    tmp=root;

    while (tmp!=0)
    {
        while (tmp==root) // Quando o pai é a raiz
        {
            if (tmp->right!=0) // Se a raiz tem filho à esquerda
            {
                rotateLeft (Gr, tmp, tmp->right);
                tmp=root;
            }

            if (tmp->right==0 && tmp==root) // Se a raiz só tem filho à direita
            {
                Gr=root;
                tmp=Gr->left;
            }
        }
            
        if (tmp!=root)// Quando o não é raiz
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
        while (tmp==root) // Quando o pai é a raiz
        {
            if (tmp->left!=0) // Se a raiz tem filho à esquerda
            {
                rotateRight (Gr, tmp, tmp->left);
                tmp=root;
            }

            if (tmp->left==0 && tmp==root) // Se a raiz só tem filho à direita
            {
                Gr=root;
                tmp=Gr->right;
            }
        
        }    

        if (tmp!=root)// Quando o não é raiz
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
        // certo até aqui //
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
void BST<T>::updateBalanceFactors (BSTNode<T>* q /*Nó que foi inserido*/)
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

    if ( Pr == p) // Caso o nó não tenha ascendente
    {
        Pr=NULL;
    }

    else
    {
        while ( Pr->left!=p && Pr->right!=p )
        {
            if ( Pr->el < p->el ) // Se p está à direita de Pr então mover para direto
            {
                Pr=Pr->right;
            }
        
            else if ( Pr->el > p->el ) // Se p está à esquerda de Pr então mover para esquerda
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
    { // encontrar um lugar para inserir um nó
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

    if (root == 0) // verifica se a árvore esta vazia
    {
        root = new BSTNode<T>(el); //insere o nó na raiz
        tmp=root;
    }

    else if (el < prev->el) // compara el com o filho à esquerda
    {
        prev->left = new BSTNode<T>(el); //insere o nó no filho à esquerda
        
    }

    else 
    {
        prev->right = new BSTNode<T>(el); //insere o nó no filho à direita.
    }

    //===============================================//
    //  Fase de Inserção do Fator de Baçlanceamento  //
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
