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
    LinkedList* this;
    this = (LinkedList *)malloc(sizeof(LinkedList));
    if(this != NULL)
    {
        this->size=0;
        this->pFirstNode = NULL;
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
    int retorno = -1;
    if(this != NULL)
    {
        retorno = this-> size;
    }
    return retorno;
}


/** \brief  Obtiene un nodo de la lista
 *
 * \param this LinkedList* Puntero a la lista
 * \param index int Indice del nodo a obtener
 * \return Node* Retorna  (NULL) Error: si el puntero a la lista es NULL o (si el indice es menor a 0 o mayor al len de la lista)
                        (pElement) Si funciono correctamente
 *
 */
static Node* getNode(LinkedList* this, int nodeIndex)
{
    Node* pNode = NULL;
    int indexNodoActual;
    if (this != NULL && nodeIndex >=0 && nodeIndex < ll_len(this))
    {
        pNode = this -> pFirstNode;
        for(indexNodoActual =0; indexNodoActual < nodeIndex ; indexNodoActual++)
        {
            pNode = pNode ->pNextNode;
        }
    }
    return pNode;
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
    int retorno = -1;
    Node* pNode = NULL;

    if (this != NULL && nodeIndex >= 0 && nodeIndex <= ll_len(this))
    {
        Node* pNewNode = malloc (sizeof(Node));
        pNewNode ->pElement = pElement;
        if(nodeIndex == 0)
        {
            pNewNode ->pNextNode = this-> pFirstNode;
            this->pFirstNode = pNewNode;
            this->size = this->size + 1;
        }
        else
        {
            pNode = getNode(this,(nodeIndex-1));
            pNewNode ->pNextNode = pNode ->pNextNode;
            pNode->pNextNode = pNewNode;
            this->size = this->size + 1;
        }
        retorno = 0;
    }
    return retorno;
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
    int retorno = -1;
    if(this != NULL)
    {
        if(addNode(this,ll_len(this),pElement) == 0)
        {
            retorno = 0;
        }

    }
    return retorno;
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
    void* retorno = NULL;
    Node* pNode;
    if(this != NULL && index >= 0 && index <= ll_len(this))
    {
        pNode = getNode(this,index);
        if(pNode != NULL)
        {
            retorno = pNode->pElement;
        }

    }
    return retorno;
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
    int retorno = -1;
    Node* pNode;
    if(this != NULL && index >= 0 && index < ll_len(this))
    {
        pNode = getNode(this,index);
        if( pNode != NULL)
        {
            pNode->pElement = pElement;
        }
        retorno = 0;
    }
    return retorno;
}


/** \brief Elimina un elemento de la lista
 *
 * \param this LinkedList* Puntero a la lista
 * \param index int Ubicacion del elemento a eliminar
 * \return int Retorna  (-1) Error: si el puntero a la lista es NULL o (si el indice es menor a 0 o mayor al len de la lista)
                        ( 0) Si funciono correctamente
 *
 */
int ll_remove(LinkedList* this,int index)
{
    int retorno = -1;
    Node* pNodeA;
    Node* pNodeB;
    if(this != NULL && index >= 0 && index < ll_len(this))
    {
        if(ll_len(this) == 1)
        {
            this->pFirstNode=NULL;
            pNodeA = getNode(this,index);
            free(pNodeA);
            this->size--;
        }else
        {
            if(index == 0)
            {
                pNodeA=getNode(this,index);
                this->pFirstNode = pNodeA->pNextNode;
                free(pNodeA);
                this->size--;
            }else
            {
                pNodeA = getNode(this,index);
                if(pNodeA != NULL)
                {
                    pNodeB = getNode(this,index-1);
                    pNodeB->pNextNode = pNodeA->pNextNode;
                    free(pNodeA);
                    this->size--;
                }
            }
        }
        retorno = 0;
    }
    return retorno;
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
    int retorno = -1;
    int i;
    Node* pNode;
    if(this!= NULL)
    {
        if(ll_len(this) == 0)
        {
            retorno = 0;
        }
        else
        {
            for(i=0 ;i < ll_len(this); i++)
            {
                pNode = getNode(this,i);
                if(pNode != NULL)
                {
                    free(pNode);
                }
            }
            this->size = 0;
            this->pFirstNode = NULL;
            retorno = 0;
        }
    }
    return retorno;
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
    int retorno = -1;
    if(this != NULL)
    {
        ll_clear(this);
        free(this);
        retorno = 0;
    }
    return retorno;
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
    int retorno = -1;
    int i;
    Node* pNode;
    if(this!=NULL)
    {
        pNode = this->pFirstNode;
        for(i=0; i < this->size; i++)
        {
            if(pNode!= NULL && pNode->pElement == pElement)
            {
                retorno = i;
                break;
            }
            pNode = pNode->pNextNode;
        }
    }
    return retorno;
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
    int retorno = -1;
    if(this!=NULL)
    {
       if(ll_len(this) == 0)
            retorno = 1;
       else
            retorno = 0;
    }
    return retorno;
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
    int retorno = -1;
    if(this != NULL && index >=0 && index <= ll_len(this))
    {
        if(addNode(this, index,pElement) == 0)
            retorno = 0;
    }
    return retorno;
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
    void* retorno = NULL;
    if(this != NULL && index >= 0 && index < ll_len(this))
    {
        retorno = ll_get(this,index);
        ll_remove(this,index);
    }

    return retorno;
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
    int retorno = -1;
    if(this != NULL)
    {
        if(ll_indexOf(this,pElement) == -1)
            retorno = 0;
        else
            retorno = 1;
    }
    return retorno;
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
    int retorno = -1;
    int i;
    void* pElement2;

    if(this != NULL && this2 != NULL)
    {
        if(ll_len(this) < ll_len(this2))
        {
            retorno = 0;
        }
        else
        {
            for(i=0;i < ll_len(this2); i++)
            {
                pElement2 = ll_get(this2,i);
                if(ll_contains(this,pElement2) == 0)
                {
                    retorno = 0;
                    break;
                }
            }

            if(retorno == -1)//contiene todos los elementos
                retorno = 1;
            else
                retorno = 0;
        }
    }
    return retorno;
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
    LinkedList* nuevaLista = NULL;
    Node* pNode;
    int i;
    int j = 0;
    if(this != NULL && from >= 0 && from < ll_len(this) && to > from && to <= ll_len(this))
    {
        nuevaLista = ll_newLinkedList();
        if(nuevaLista != NULL)
        {
            for(i=from; i<to; i++)
            {
                pNode = getNode(this,i);
                addNode(nuevaLista,j, pNode->pElement);
                j++;
            }
        }
    }
    return nuevaLista;
}


/** \brief Crea y retorna una nueva lista con los elementos de la lista pasada como parametro
 *
 * \param pList LinkedList* Puntero a la lista
 * \return LinkedList* Retorna  (NULL) Error: si el puntero a la listas es NULL
                                (puntero a la nueva lista) Si ok
*/
LinkedList* ll_clone(LinkedList* this)
{
    LinkedList* nuevaLista = NULL;
    Node* pNode;
    int i;
    if(this != NULL && ll_len(this) > 0)
    {
        nuevaLista = ll_newLinkedList();
        if(nuevaLista !=NULL)
        {
            for(i=0;i < ll_len(this); i++)
            {
                pNode = getNode(this,i);
                addNode(nuevaLista ,i,pNode->pElement);
            }
        }
    }
    return nuevaLista;
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
    int retorno = -1;
    int i;
    int flag = 0;
    Node* pNode;
    Node* pNextNode;
    void* pElementAux;
    if(this != NULL && pFunc != NULL && ll_len(this) > 0)
    {
        do
        {
            pNode = this->pFirstNode;
            if(pNode!=NULL)
            {
                pNextNode = pNode->pNextNode;
                for(i=0; i < (ll_len(this)-1); i++)
                {
                    if(pFunc(pNode->pElement, pNextNode->pElement) == 1 && order == 1)
                        {
                            pElementAux = pNode->pElement;
                            pNode->pElement = pNextNode->pElement;
                            pNextNode->pElement = pElementAux;
                            flag = 1;
                        }
                    if(pNextNode->pNextNode != NULL)
                    {
                        pNode = pNextNode;
                    }
                    else
                        break;
                    pNextNode = pNode->pNextNode;
                }
            }
        }while(flag);
        retorno = 0;
    }

    return retorno;

}

