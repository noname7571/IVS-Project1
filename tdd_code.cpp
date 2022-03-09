//======== Copyright (c) 2021, FIT VUT Brno, All rights reserved. ============//
//
// Purpose:     Test Driven Development - priority queue code
//
// $NoKeywords: $ivs_project_1 $tdd_code.cpp
// $Author:     Matej Tomko <xtomko06@stud.fit.vutbr.cz>
// $Date:       $2021-01-04
//============================================================================//
/**
 * @file tdd_code.cpp
 * @author Matej Tomko
 * 
 * @brief Implementace metod tridy prioritni fronty.
 */

#include <stdlib.h>
#include <stdio.h>

#include "tdd_code.h"

//============================================================================//
// ** ZDE DOPLNTE IMPLEMENTACI **
//
// Zde doplnte implementaci verejneho rozhrani prioritni fronty (Priority Queue)
// 1. Verejne rozhrani fronty specifikovane v: tdd_code.h (sekce "public:")
//    - Konstruktor (PriorityQueue()), Destruktor (~PriorityQueue())
//    - Metody Insert/Remove/Find/GetHead ...
//    - Pripadne vase metody definovane v tdd_code.h (sekce "protected:")
//
// Cilem je dosahnout plne funkcni implementace prioritni fronty implementovane
// pomoci tzv. "singly linked list", ktera bude splnovat dodane testy
// (tdd_tests.cpp).
//============================================================================//

PriorityQueue::PriorityQueue()
{
    m_pHead = NULL;
}

PriorityQueue::~PriorityQueue()
{
    Element_t *element = GetHead();
    Element_t *tmp = NULL;

    // removes all elements of the list
    while (element != NULL) {
        tmp = element->pNext;
        delete (element);
        element = tmp;
    }
}

void PriorityQueue::Insert(int value)
{
    Element_t *newElement = new Element_t();
    newElement->pNext = NULL;
    newElement->value = value;

    // inserts a new element at start of the list if the list is empty
    if (m_pHead == NULL) {
        m_pHead = newElement;
        return;

    // inserts a new element at start of the list if the value is greater or the same as a value of the first element
    } else if (m_pHead->value <= value) {
        Element_t *tmp = GetHead();
        m_pHead = newElement;
        newElement->pNext = tmp;
        return;

    } else {
        Element_t *element = GetHead();
        while (element != NULL) {
            // inserts a new element at the end of the list
            if (element->pNext == NULL) {
                element->pNext = newElement;
                return;
            }
            // inserts a new element where it is supposed to be in a list
            if (element->pNext->value <= value) {
                newElement->pNext = element->pNext;
                element->pNext = newElement;
                return;
            }
            element = element->pNext;
        }
    }
}

bool PriorityQueue::Remove(int value)
{
    Element_t *tmp = NULL;
    
    // if the list is empty, return false
    if (m_pHead == NULL) {
        return false;
    
    } else {
        // if the first value of the list is the value we want to remove, it removes it and returns true
        if (m_pHead->value == value) {
            tmp = m_pHead->pNext;
            delete(m_pHead);
            m_pHead = tmp;
            return true;
        }

        Element_t *element = GetHead();
        while (element->pNext != NULL) {
            // finds and removes the value of the list that is supposed to be removed and if it does, returns true
            if (element->pNext->value == value) {
                tmp = element->pNext;
                element->pNext = element->pNext->pNext;
                delete(tmp);
                return true;
            }

            element = element->pNext;
        }

        return false;
    }
}

PriorityQueue::Element_t *PriorityQueue::Find(int value)
{
    Element_t *element = GetHead();

    while (element != NULL) {
        // finds an element with the searched value
        if (element->value == value) {
            return element; // if value is found, return the element with that value
        }

        element = element->pNext;
    }

    return NULL; // if value is not found anywhere in the list, return NULL
}

size_t PriorityQueue::Length()
{
	Element_t *element = GetHead();

    if (element == NULL) {
        return 0; // if the list is empty, return 0
    }

    int QLength = 0; // Length counter
    while (element != NULL) {
        element = element->pNext;
        QLength++; // adds 1 to counter for every element in the list
    }
    
    return QLength;
}

PriorityQueue::Element_t *PriorityQueue::GetHead()
{
    return m_pHead;
}

/*** Konec souboru tdd_code.cpp ***/
