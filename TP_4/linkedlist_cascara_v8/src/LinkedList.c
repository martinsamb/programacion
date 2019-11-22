#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../inc/LinkedList.h"


static Node* getNode(LinkedList* this, int nodeIndex);
static int addNode(LinkedList* this, int nodeIndex,void* pElement);

/** \brief Crea un nuevo LinkedList en memoria de manera dinamica
 *
 *  \param void
 *  \return LinkedList* Retorna (NULL) en el caso de no conseguir espacio en memoria
 *                      o el puntero al espacio reservado
 */
LinkedList* ll_newLinkedList(void)
{
    LinkedList* this;//declaro una variable de tipo ll
    this = (LinkedList*)malloc(sizeof(LinkedList*));
    if(this!=NULL)//reservo ese espacio de memoria dinamica
    {
        this->pFirstNode=NULL;
        this->size=0;
    }
    return this;
}

/** \brief Retorna la cantidad de elementos de la lista
 *
 * \param this LinkedList* Puntero a la lista
 * \return int Retorna (-1) si el puntero es NULL o la cantidad de elementos de la lista
 *
 */
int ll_len(LinkedList* this)
{
    int returnAux = -1;

    if(this!=NULL)
    {
        returnAux = this->size;
    }
    return returnAux;
}


/** \brief  Obtiene un nodo de la lista
 *
 * \param this LinkedList* Puntero a la lista
 * \param index int Indice del nodo a obtener
 * \return Node* Retorna  (NULL) Error: si el puntero a la lista es NULL o (si el indice es menor a 0 o mayor al len de la lista)
                        (pNode) Si funciono correctamente
 *
 */
static Node* getNode(LinkedList* this, int nodeIndex)
{
    int i;
    Node* pNode;

    if(this!=NULL && nodeIndex < ll_len(this) && nodeIndex>=0)
    {
        pNode = this->pFirstNode;
        if(nodeIndex==0)
        {
            return pNode;
        }
        else
        {
            for(i=0;i<nodeIndex; i++)
            {
                pNode = pNode->pNextNode;
            }
            return pNode;
        }
    }
    return NULL;
}

/** \brief  Permite realizar el test de la funcion getNode la cual es privada
 *
 * \param this LinkedList* Puntero a la lista
 * \param index int Indice del nodo a obtener
 * \return Node* Retorna  (NULL) Error: si el puntero a la lista es NULL o (si el indice es menor a 0 o mayor al len de la lista)
                        (pElement) Si funciono correctamente
 *
 */
Node* test_getNode(LinkedList* this, int nodeIndex)
{
    return getNode(this, nodeIndex);
}


/** \brief Agrega y enlaza un nuevo nodo a la lista
 *
 * \param this LinkedList* Puntero a la lista
 * \param nodeIndex int Ubicacion donde se agregara el nuevo nodo
 * \param pElement void* Puntero al elemento a ser contenido por el nuevo nodo
 * \return int Retorna  (-1) Error: si el puntero a la lista es NULL o (si el indice es menor a 0 o mayor al len de la lista)
                        ( 0) Si funciono correctamente
 *
 */
static int addNode(LinkedList* this, int nodeIndex,void* pElement)
{
    int returnAux = -1;
    Node* pNodoAnterior=NULL;
    Node* pNodoNuevo=NULL;

    if(this != NULL && nodeIndex>=0 && nodeIndex<=ll_len(this))//no se valida el elemento
    {
        pNodoNuevo = (Node*)malloc(sizeof(Node));
        pNodoAnterior = getNode(this,nodeIndex-1);//ubicacion nodo anterior
        if(pNodoNuevo != NULL)
        {
            pNodoNuevo->pElement = pElement;
            pNodoNuevo->pNextNode=getNode(this,nodeIndex); //Si es el ultino elemento de Get va a dar a NULL , no apunta a nada
            if(nodeIndex == 0)//Previo almaceno la direccion del nuevo nodo
            {
                this->pFirstNode = pNodoNuevo;
            }
            else if(pNodoAnterior!= NULL)//el unico caso en que seria NUll es el index=0, asi que no es necesario checkear !=NULL
            {
                pNodoAnterior->pNextNode=pNodoNuevo;
            }
            this->size++;
            returnAux = 0;
        }
    }
    return returnAux;
}

/** \brief Permite realizar el test de la funcion addNode la cual es privada
 *
 * \param this LinkedList* Puntero a la lista
 * \param nodeIndex int Ubicacion donde se agregara el nuevo nodo
 * \param pElement void* Puntero al elemento a ser contenido por el nuevo nodo
  * \return int Retorna  (-1) Error: si el puntero a la lista es NULL o (si el indice es menor a 0 o mayor al len de la lista)
                        ( 0) Si funciono correctamente
 *
 */
int test_addNode(LinkedList* this, int nodeIndex,void* pElement)
{
    return addNode(this,nodeIndex,pElement);
}


/** \brief  Agrega un elemento a la lista
 * \param pList LinkedList* Puntero a la lista
 * \param pElement void* Puntero al elemento a ser agregado
 * \return int Retorna  (-1) Error: si el puntero a la lista es NULL
                        ( 0) Si funciono correctamente
 *
 */
int ll_add(LinkedList* this, void* pElement)
{
    int returnAux = -1;

    if(this!=NULL)
    {
        if(addNode(this,ll_len(this),pElement)==0)
        {
            returnAux=0;//lo agrego correctamente
        }
    }

    return returnAux;//error
}

/** \brief Permite realizar el test de la funcion addNode la cual es privada
 *
 * \param this LinkedList* Puntero a la lista
 * \param nodeIndex int Ubicacion del elemento a obtener
 * \return void* Retorna    (NULL) Error: si el puntero a la lista es NULL o (si el indice es menor a 0 o mayor al len de la lista)
                            (pElement) Si funciono correctamente
 *
 */
void* ll_get(LinkedList* this, int index)
{
    void* returnAux = NULL;
    Node* pAuxiliar= NULL;

    if(this!=NULL && index>= 0 && index<ll_len(this))
    {
        pAuxiliar=getNode(this,index); //puntero a nodo
        if(pAuxiliar!=NULL)
        {
            returnAux = pAuxiliar->pElement; //devuelve el puntero almacenado en el campo pElement
        }
    }

    return returnAux;
}


/** \brief Modifica un elemento de la lista
 *
 * \param this LinkedList* Puntero a la lista
 * \param nodeIndex int Ubicacion del elemento a modificar
 * \param pElement void* Puntero al nuevo elemento
 * \return int Retorna  (-1) Error: si el puntero a la lista es NULL o (si el indice es menor a 0 o mayor al len de la lista)
                        ( 0) Si funciono correctamente
 *
 */
int ll_set(LinkedList* this, int index,void* pElement)
{
    int returnAux = -1;
    Node* pAuxiliar = NULL;

    if(this!=NULL && index>=0 && index<ll_len(this))
    {
        pAuxiliar=getNode(this,index); // puntero a nodo
        if(pAuxiliar!=NULL)
        {
            pAuxiliar->pElement=pElement; // almaceno el nuevo elemento
            returnAux = 0; //funciono
        }
    }

    return returnAux;
}


/** \brief Elimina un elemento de la lista
 *
 * \param this LinkedList* Puntero a la lista
 * \param nodeIndex int Ubicacion del elemento a eliminar
 * \return int Retorna  (-1) Error: si el puntero a la lista es NULL o (si el indice es menor a 0 o mayor al len de la lista)
                        ( 0) Si funciono correctamente
 *
 */
int ll_remove(LinkedList* this,int index)
{
    int returnAux = -1;

    Node* pAuxiliarActual=NULL;
    Node* pAuxiliarPrevia=NULL;

    if(this!=NULL && index>=0 && index<ll_len(this) && ll_len(this)>0)
    {
        pAuxiliarActual=getNode(this,index);
        pAuxiliarPrevia=getNode(this,index-1); //anterior posición del nodo

        if(pAuxiliarActual!=NULL)
        {
            if(index == 0)  //Previo: Donde alamaceno la posicion del nodo siguientre
            {
                this->pFirstNode=pAuxiliarActual->pNextNode;
            }
            else if(pAuxiliarPrevia!=NULL)
            {
                pAuxiliarPrevia->pNextNode=pAuxiliarActual->pNextNode;
            }
            free(pAuxiliarActual);
            this->size--;
            returnAux = 0;
        }
    }
    return returnAux;
}


/** \brief Elimina todos los elementos de la lista
 *
 * \param this LinkedList* Puntero a la lista
 * \return int Retorna  (-1) Error: si el puntero a la lista es NULL
                        ( 0) Si funciono correctamente
 *
 */
int ll_clear(LinkedList* this)
{
    int returnAux = -1;
    int i;

    if(this!=NULL)
    {
        for(i=0;i<ll_len(this);i++)
            ll_remove(this,i);//elemina todos los elementos de la lista

            if(ll_len(this)==0)
                returnAux=0;
    }
    return returnAux;
}


/** \brief Elimina todos los elementos de la lista y la lista
 *
 * \param this LinkedList* Puntero a la lista
 * \return int Retorna  (-1) Error: si el puntero a la lista es NULL
                        ( 0) Si funciono correctamente
 *
 */
int ll_deleteLinkedList(LinkedList* this)
{
    int returnAux = -1;

    if(this!=NULL)
    {
        ll_clear(this);
        free(this);
        returnAux=0;
    }
    return returnAux;
}

/** \brief Busca el indice de la primer ocurrencia del elemento pasado como parametro
 *
 * \param this LinkedList* Puntero a la lista
 * \param pElement void* Puntero al elemento
 * \return int Retorna  (-1) Error: si el puntero a la lista es NULL
                        (indice del elemento) Si funciono correctamente
 *
 */
int ll_indexOf(LinkedList* this, void* pElement)
{
    int returnAux = -1;
    int i;

    if(this!=NULL)
    {
        for(i=0;i<ll_len(this);i++)
        {
            if(ll_get(this,i) == pElement)//ll_get devuelve un pElement
            {
                returnAux = i;//devuelve el indice
            }
        }
    }

    return returnAux;
}

/** \brief Indica si la lista esta o no vacia
 *
 * \param this LinkedList* Puntero a la lista
 * \return int Retorna  (-1) Error: si el puntero a la lista es NULL
                        ( 0) Si la lista NO esta vacia
                        ( 1) Si la lista esta vacia
 *
 */
int ll_isEmpty(LinkedList* this)
{
    int returnAux = -1;

    if(this!=NULL)
    {
        returnAux = 1;
        if(ll_len(this)>0)
        {
            returnAux=0;
        }
    }
    return returnAux;
}

/** \brief Inserta un nuevo elemento en la lista en la posicion indicada
 *
 * \param this LinkedList* Puntero a la lista
 * \param nodeIndex int Ubicacion donde se agregara el nuevo elemento
 * \param pElement void* Puntero al nuevo elemento
 * \return int Retorna  (-1) Error: si el puntero a la lista es NULL o (si el indice es menor a 0 o mayor al len de la lista)
                        ( 0) Si funciono correctamente
 *
 */
int ll_push(LinkedList* this, int index, void* pElement)
{
    int returnAux = -1;
    if(this!=NULL && index>=0 && index<=ll_len(this))//ll_len se agrega al final
    {
        if(addNode(this,index,pElement)== 0)
        {
            returnAux = 0; //funciono
        }
    }
    return returnAux;
}


/** \brief Elimina el elemento de la posicion indicada y retorna su puntero
 *
 * \param this LinkedList* Puntero a la lista
 * \param nodeIndex int Ubicacion del elemento eliminar
 * \return void* Retorna    (NULL) Error: si el puntero a la lista es NULL o (si el indice es menor a 0 o mayor al len de la lista)
                            (pElement) Si funciono correctamente
 *
 */
void* ll_pop(LinkedList* this,int index)
{
    void* returnAux = NULL;

    if(this!=NULL && index>=0 && index<ll_len(this))
    {
        returnAux=ll_get(this,index); //devuelve pElement
        ll_remove(this,index);//elimina el elemento de la lista.
    }
    return returnAux; //conserva el puntero del elemento (get+remove)
}


/** \brief  Determina si la lista contiene o no el elemento pasado como parametro
 *
 * \param this LinkedList* Puntero a la lista
 * \param pElement void* Puntero del elemento a verificar
 * \return int Retorna  (-1) Error: si el puntero a la lista es NULL
                        ( 1) Si contiene el elemento
                        ( 0) si No contiene el elemento
*/
int ll_contains(LinkedList* this, void* pElement)
{
    int returnAux = -1;

    if(this!=NULL)
    {
        returnAux=0;//no contiene
        if(ll_indexOf(this,pElement)!=-1)//busca indide de ocurrencia pasado como parametro (-1)Null
            returnAux=1;//comntiene parametro
    }
    return returnAux;
}

/** \brief  Determina si todos los elementos de la lista (this2)
            estan contenidos en la lista (this)
 *
 * \param this LinkedList* Puntero a la lista
 * \param this2 LinkedList* Puntero a la lista
 * \return int Retorna  (-1) Error: si alguno de los punteros a las listas son NULL
                        ( 1) Si los elementos de (this2) estan contenidos en la lista (this)
                        ( 0) si los elementos de (this2) NO estan contenidos en la lista (this)
*/
int ll_containsAll(LinkedList* this,LinkedList* this2)
{
    int returnAux = -1;
    int i;
    void* pElement=NULL;

    if(this!=NULL && this2!=NULL)
    {
        returnAux=1;
        for(i=0;i<ll_len(this2);i++)
        {
            pElement=ll_get(this2,i);//devuelve un puntero element this2
            if(ll_contains(this,pElement)!=1)//determina si this 2 esta contenido en this
            {
                returnAux=0;
                break;
            }
        }
    }
    return returnAux;
}

/** \brief Crea y retorna una nueva lista con los elementos indicados
 *
 * \param pList LinkedList* Puntero a la lista
 * \param from int Indice desde el cual se copian los elementos en la nueva lista
 * \param to int Indice hasta el cual se copian los elementos en la nueva lista (no incluido)
 * \return LinkedList* Retorna  (NULL) Error: si el puntero a la listas es NULL
                                o (si el indice from es menor a 0 o mayor al len de la lista)
                                o (si el indice to es menor o igual a from o mayor al len de la lista)
                         (puntero a la nueva lista) Si ok
*/
LinkedList* ll_subList(LinkedList* this,int from,int to)
{
    LinkedList* cloneArray = NULL;
    int i;

    if(this!=NULL && from<to && from>=0 && to<=ll_len(this))//to==len porque recorre hasta <to, si tiene 1 elemento va a ser from 0 to 1
    {
        cloneArray=ll_newLinkedList();//creo un ll_new
        for(i=from;i<to;i++)
        {
            addNode(cloneArray,i,ll_get(this,i));//agrega un nuevo nodo a la lista
                                            //ll_get devuelve un pElement
        }

    }

    return cloneArray;
}



/** \brief Crea y retorna una nueva lista con los elementos de la lista pasada como parametro
 *
 * \param pList LinkedList* Puntero a la lista
 * \return LinkedList* Retorna  (NULL) Error: si el puntero a la listas es NULL
                                (puntero a la nueva lista) Si ok
*/
LinkedList* ll_clone(LinkedList* this)
{
    LinkedList* cloneArray = NULL;
    int i;

    if(this!=NULL)
    {
        cloneArray=ll_newLinkedList();
        for(i=0;i<ll_len(this);i++)
        {
            addNode(cloneArray,i,ll_get(this,i));
        }
    }
    return cloneArray;
}


/** \brief Ordena los elementos de la lista utilizando la funcion criterio recibida como parametro
 * \param pList LinkedList* Puntero a la lista
 * \param pFunc (*pFunc) Puntero a la funcion criterio
 * \param order int  [1] Indica orden ascendente - [0] Indica orden descendente
 * \return int Retorna  (-1) Error: si el puntero a la listas es NULL
                                ( 0) Si ok
 */
int ll_sort(LinkedList* this, int (*pFunc)(void* ,void*), int order)
{
    int returnAux =-1;
    int i,j;
    Node* auxiliarNodo=NULL;

    if(this!=NULL && pFunc!=NULL && (order==0||order==1))
    {
        if(order==0)//descendente
            order=-1;

            for(i=0;i<ll_len(this);i++)
            {
                auxiliarNodo=getNode(this,i);//obtengo un nodo de la lista
                j=i-1;
                while((j>=0) && pFunc(auxiliarNodo->pElement,(getNode(this,j)->pElement))!=order)
                    //j>0 - puntero de la funcion - obtengo el puntero del nodo
                {
                    j--;
                }
                if(j!=i-1)
                {
                    addNode(this,j+1,auxiliarNodo->pElement);//agrego un nuevo nodo
                    ll_remove(this,i+1); //elimino eleemnto de la lista
                }
            }
            returnAux=0;
    }
    return returnAux;
}

